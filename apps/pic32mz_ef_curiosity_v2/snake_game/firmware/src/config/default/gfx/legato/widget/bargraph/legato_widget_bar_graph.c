// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END


#include "gfx/legato/widget/bargraph/legato_widget_bar_graph.h"

#if LE_BARGRAPH_WIDGET_ENABLED

#define MAX_TICK_LABEL_DIGITS 10
#define MAX_TICK_LABEL_VALUE 999999999
#define LABEL_OFFSET_MIN_PIX 5

#include <stdio.h>
#include <string.h>
#include <gfx/legato/legato.h>

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_stringutils.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           101
#define DEFAULT_HEIGHT          101

#define DEFAULT_TICK_LENGTH        5
#define DEFAULT_TICK_INTERVAL      10
#define DEFAULT_SUBTICK_INTERVAL   5
#define DEFAULT_MAX_VALUE          100
#define DEFAULT_MIN_VALUE          0


static
#if LE_DYNAMIC_VTABLES == 0
const
#endif
leBarGraphWidgetVTable barGraphWidgetVTable;

void _leBarGraphWidget_Constructor(leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    /* call base class constructor */
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&barGraphWidgetVTable;
    _this->fn = &barGraphWidgetVTable;

    _this->widget.type = LE_WIDGET_BAR_GRAPH;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;
    
    _this->tickLength = DEFAULT_TICK_LENGTH;
    _this->fillGraphArea = LE_TRUE;
    _this->stacked = LE_FALSE;
    _this->maxValue = DEFAULT_MAX_VALUE;
    _this->minValue = DEFAULT_MIN_VALUE;
    _this->tickInterval = DEFAULT_TICK_INTERVAL;
    _this->subtickInterval = DEFAULT_SUBTICK_INTERVAL;
    
    _this->valueGridLinesVisible = LE_TRUE;
    _this->valueAxisLabelsVisible = LE_TRUE;
    _this->valueAxisTicksVisible = LE_TRUE;
    _this->valueAxisSubticksVisible = LE_TRUE;
    _this->valueAxisTicksPosition = BAR_GRAPH_TICK_CENTER;
    _this->valueAxisSubticksPosition = BAR_GRAPH_TICK_CENTER;
    
    _this->categAxisLabelsVisible = LE_TRUE;
    _this->categAxisTicksVisible = LE_TRUE;
    _this->categAxisTicksPosition = BAR_GRAPH_TICK_CENTER;
    
    leArray_Create(&_this->dataSeriesArray);
    leArray_Create(&_this->categories);

    _this->ticksLabelFont = NULL;
}

void _leWidget_Destructor(leWidget* wgt);

void _leBarGraphWidget_Destructor(leBarGraphWidget* _this)
{
    _this->fn->clearData(_this);

    _this->ticksLabelFont = NULL;

    _leWidget_Destructor((leWidget*)_this);
}

leBarGraphWidget* leBarGraphWidget_New()
{
    leBarGraphWidget* wgt = NULL;

    wgt = LE_MALLOC(sizeof(leBarGraphWidget));

    if(wgt == NULL)
        return NULL;
    
    _leBarGraphWidget_Constructor(wgt);

    return wgt;
}

//Gets the maximum draw rectangle for the category labels
static void getCategoryLabelMaxDrawRect(const leBarGraphWidget* _this,
                                        leRect* rect)
{
    uint32_t categoryIndex;
    leRect textRect;
    leString* category;
    
    *rect = leRect_Zero;
    
    for (categoryIndex = 0; 
        (categoryIndex < _this->categories.size); 
         categoryIndex++)
    {
        category = leArray_Get(&_this->categories, categoryIndex);
        
        if(category == NULL)
            return;
        
        category->fn->getRect(category, &textRect);
        
        if(textRect.height > rect->height)
        {
            rect->height = textRect.height;
        }
                    
        if(textRect.width > rect->width)
        {
            rect->width = textRect.width;
        }
    }
}

//Gets the superset (largest) draw rectangle for the labels. 
static void getValueLabelMaxDrawRect(const leBarGraphWidget* _this,
                                     leRect * rect)
{
    leRect minLabelRect;
    leRect maxLabelRect;
    char strbuff[MAX_TICK_LABEL_DIGITS];

    *rect = leRect_Zero;
    
    if(_this->ticksLabelFont == NULL)
        return;
    
    //Calculate the offset for the value labels
    if(_this->valueAxisLabelsVisible)
    {
        minLabelRect = leRect_Zero;
        maxLabelRect = leRect_Zero;

        if(_this->minValue < 0)
        {
            //Protect from overflow
            if(_this->minValue > -MAX_TICK_LABEL_VALUE)
            {
                sprintf(strbuff, "%d", (int)_this->minValue);
            }
            else
            {
                sprintf(strbuff, "---");
            }

            leStringUtils_GetRectCStr(strbuff,
                                      _this->ticksLabelFont,
                                      &minLabelRect);
        }

        //Protect from overflow
        if(_this->maxValue < MAX_TICK_LABEL_VALUE) 
        {
            sprintf(strbuff, "%d", (int)_this->maxValue);
        }
        else 
        {
            sprintf(strbuff, "---");
        }

        leStringUtils_GetRectCStr(strbuff,
                                  _this->ticksLabelFont,
                                  &maxLabelRect);

        rect->width = (maxLabelRect.width > minLabelRect.width) ?
                      (maxLabelRect.width) :
                      (minLabelRect.width);

        rect->height = (maxLabelRect.height > minLabelRect.height) ? 
                       (maxLabelRect.height) :
                       (minLabelRect.height);
    }
}

//Gets the rectangle of the graph area (without labels or ticks)
void _leBarGraphWidget_GetGraphRect(const leBarGraphWidget* _this,
                                    leRect* graphRect)
{
    lePoint p;
    leMargin margin;
    leRect widgetRect, valueLabelMaxRect, categoryLabelMaxRect;
 
    LE_ASSERT_THIS();
       
    widgetRect = _this->fn->localRect(_this);
    leUtils_RectToScreenSpace((leWidget*)_this, &widgetRect);

    p.x = widgetRect.x;
    p.y = widgetRect.y;
    
    valueLabelMaxRect = leRect_Zero;
    *graphRect = leRect_Zero;
    categoryLabelMaxRect = leRect_Zero;
    
    margin = _this->widget.margin;
    graphRect->x = p.x + margin.left;
    graphRect->width = widgetRect.width - margin.left - margin.right;

    if(_this->valueAxisTicksVisible)
    {
        switch (_this->valueAxisTicksPosition)
        {
            case BAR_GRAPH_TICK_OUT:
            {
                graphRect->x += _this->tickLength;
                graphRect->width -= _this->tickLength;
                break;
            }
            case BAR_GRAPH_TICK_CENTER:
            {
                graphRect->x += _this->tickLength/2;
                graphRect->width -= _this->tickLength/2;
                break;
            }
            default:
                break;
        }
    }

    graphRect->y = p.y + margin.top;
    graphRect->height = widgetRect.height - margin.top - margin.bottom;

    if(_this->valueAxisLabelsVisible)
    {
        getValueLabelMaxDrawRect(_this, &valueLabelMaxRect);

        if(valueLabelMaxRect.width != 0)
        {
            graphRect->x += (valueLabelMaxRect.width + LABEL_OFFSET_MIN_PIX * 2);
            graphRect->width -= (valueLabelMaxRect.width + LABEL_OFFSET_MIN_PIX * 2);
        }

        if(valueLabelMaxRect.height != 0)
        {
            graphRect->y += valueLabelMaxRect.height / 2 + LABEL_OFFSET_MIN_PIX;
            graphRect->height -= valueLabelMaxRect.height / 2 + LABEL_OFFSET_MIN_PIX;
        }
    }

    if(_this->categAxisTicksVisible)
    {
        switch (_this->categAxisTicksPosition)
        {
            case BAR_GRAPH_TICK_OUT:
            {
                graphRect->height -= _this->tickLength;
                break;
            }
            case BAR_GRAPH_TICK_CENTER:
            {
                graphRect->height -= _this->tickLength/2;
                break;
            }
            default:
                break;
        }
    }

    if(_this->categAxisLabelsVisible)
    {
        getCategoryLabelMaxDrawRect(_this, &categoryLabelMaxRect);
    }

    if(categoryLabelMaxRect.height > (valueLabelMaxRect.height / 2))
    {
        graphRect->height -= (categoryLabelMaxRect.height +  LABEL_OFFSET_MIN_PIX);
    }
    else if(valueLabelMaxRect.height != 0)
    {
        graphRect->height -= (valueLabelMaxRect.height / 2 +  LABEL_OFFSET_MIN_PIX);
    }
}

leResult _leBarGraphWidget_GetBarRect(const leBarGraphWidget* _this,
                                      uint32_t seriesID,
                                      uint32_t categoryID,
                                      leRect * rect)
{
    leRect graphRect;
    
    LE_ASSERT_THIS();
    
    if(rect == NULL)
        return LE_FAILURE;
    
    _leBarGraphWidget_GetGraphRect(_this, &graphRect);
    
    rect->height = graphRect.height;
    rect->y = graphRect.y;

    if(_this->stacked == LE_TRUE)
    {
        rect->width = (graphRect.width / _this->categories.size) / 3;
        
        rect->x = graphRect.x + 
              ((categoryID * graphRect.width) / _this->categories.size) + 
              (graphRect.width / (_this->categories.size * 2)) - 
              (rect->width/2);
    }
    else
    {
        rect->width = (graphRect.width / 
                          (_this->categories.size * (_this->dataSeriesArray.size + 2)));
        
        rect->x = graphRect.x + 
              (categoryID * graphRect.width / _this->categories.size) + 
              seriesID * rect->width + rect->width;

    }
    
    return LE_SUCCESS;
}

static uint32_t getTickLength(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->tickLength;
}

static leResult setTickLength(leBarGraphWidget* _this,
                              uint32_t length)
{
    LE_ASSERT_THIS();
    
    if(_this->tickLength == length)
        return LE_SUCCESS;
        
    _this->tickLength = length;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getFillGraphArea(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->fillGraphArea;
}

static leResult setFillGraphArea(leBarGraphWidget* _this,
                                 leBool fill)
{
    LE_ASSERT_THIS();
    
    if(_this->fillGraphArea == fill)
        return LE_SUCCESS;
        
    _this->fillGraphArea = fill;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getGridLinesVisible(const leBarGraphWidget* _this,
                                  leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueGridLinesVisible;
}

static leResult setGridLinesVisible(leBarGraphWidget* _this,
                                    leBarGraphValueAxis axis,
                                    leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->valueGridLinesVisible == vis)
        return LE_SUCCESS;
        
    _this->valueGridLinesVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getStacked(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->stacked;
}

static leResult setStacked(leBarGraphWidget* _this,
                           leBool stacked)
{   
    LE_ASSERT_THIS();
    
    if(_this->stacked == stacked)
        return LE_SUCCESS;
        
    _this->stacked = stacked;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getMaxValue(const leBarGraphWidget* _this,
                            leBarGraphValueAxis axis)
{   
    LE_ASSERT_THIS();
    
    return _this->maxValue;
}

static leResult setMaxValue(leBarGraphWidget* _this,
                            leBarGraphValueAxis axis,
                            int32_t value)
{   
    LE_ASSERT_THIS();
    
    if(value <= _this->minValue)
        return LE_FAILURE;
    
    if(_this->maxValue == value)
        return LE_SUCCESS;
        
    _this->maxValue = value;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getMinValue(const leBarGraphWidget* _this,
                            leBarGraphValueAxis axis)
{   
    LE_ASSERT_THIS();
    
    return _this->minValue;
}

static leResult setMinValue(leBarGraphWidget* _this,
                            leBarGraphValueAxis axis,
                            int32_t value)
{   
    LE_ASSERT_THIS();
    
    if(value >= _this->maxValue)
        return LE_FAILURE;

    if(_this->minValue == value)
        return LE_SUCCESS;
        
    _this->minValue = value;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getValueAxisLabelsVisible(const leBarGraphWidget* _this,
                                        leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueAxisLabelsVisible;
}

static leResult setValueAxisLabelsVisible(leBarGraphWidget* _this,
                                          leBarGraphValueAxis axis,
                                          leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->valueAxisLabelsVisible == vis)
        return LE_SUCCESS;
        
    _this->valueAxisLabelsVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getValueAxisTicksVisible(const leBarGraphWidget* _this,
                                       leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueAxisTicksVisible;
}

static leResult setValueAxisTicksVisible(leBarGraphWidget* _this,
                                         leBarGraphValueAxis axis,
                                         leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->valueAxisTicksVisible == vis)
        return LE_SUCCESS;
        
    _this->valueAxisTicksVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getValueAxisTicksInterval(const leBarGraphWidget* _this,
                                          leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->tickInterval;
}

static leResult setValueAxisTicksInterval(leBarGraphWidget* _this,
                                          leBarGraphValueAxis axis,
                                          uint32_t itv)
{
    LE_ASSERT_THIS();
    
    if(_this->tickInterval == itv)
        return LE_SUCCESS;
        
    _this->tickInterval = itv;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}


static leBarGraphTickPosition getValueAxisTicksPosition(const leBarGraphWidget* _this,
                                                        leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueAxisTicksPosition;
}

static leResult setValueAxisTicksPosition(leBarGraphWidget* _this,
                                          leBarGraphValueAxis axis,
                                          leBarGraphTickPosition pos)
{
    LE_ASSERT_THIS();
    
    if(_this->valueAxisTicksPosition == pos)
        return LE_SUCCESS;
        
    _this->valueAxisTicksPosition = pos;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS; 
}

static leBool getValueAxisSubticksVisible(const leBarGraphWidget* _this,
                                          leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueAxisSubticksVisible;
}

static leResult setValueAxisSubticksVisible(leBarGraphWidget* _this,
                                            leBarGraphValueAxis axis,
                                            leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->valueAxisSubticksVisible == vis)
        return LE_SUCCESS;
        
    _this->valueAxisSubticksVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getValueAxisSubticksInterval(const leBarGraphWidget* _this,
                                             leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->subtickInterval;
}

static leResult setValueAxisSubticksInterval(leBarGraphWidget* _this,
                                             leBarGraphValueAxis axis,
                                             uint32_t itv)
{
    LE_ASSERT_THIS();
    
    if(_this->subtickInterval == itv)
        return LE_SUCCESS;
        
    _this->subtickInterval = itv;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBarGraphTickPosition getValueAxisSubticksPosition(const leBarGraphWidget* _this,
                                                           leBarGraphValueAxis axis)
{
    LE_ASSERT_THIS();
    
    return _this->valueAxisSubticksPosition;
}

static leResult setValueAxisSubticksPosition(leBarGraphWidget* _this,
                                             leBarGraphValueAxis axis,
                                             leBarGraphTickPosition pos)
{
    LE_ASSERT_THIS();
    
    if(_this->valueAxisSubticksPosition == pos)
        return LE_SUCCESS;
        
    _this->valueAxisSubticksPosition = pos;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;     
}

static leBool getCategoryAxisTicksVisible(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->categAxisTicksVisible;
}

static leResult setCategoryAxisTicksVisible(leBarGraphWidget* _this,
                                            leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->categAxisTicksVisible == vis)
        return LE_SUCCESS;
        
    _this->categAxisTicksVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBarGraphTickPosition getCategoryAxisTicksPosition(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->categAxisTicksPosition;
}

static leResult setCategoryAxisTicksPosition(leBarGraphWidget* _this,
                                             leBarGraphTickPosition pos)
{
    LE_ASSERT_THIS();
    
    if(_this->categAxisTicksPosition == pos)
        return LE_SUCCESS;
        
    _this->categAxisTicksPosition = pos;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;      
}

static leBool getCategoryAxisLabelsVisible(const leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->categAxisLabelsVisible;
}

static leResult setCategoryAxisLabelsVisible(leBarGraphWidget* _this,
                                             leBool vis)
{
    LE_ASSERT_THIS();
    
    if(_this->categAxisLabelsVisible == vis)
        return LE_SUCCESS;
        
    _this->categAxisLabelsVisible = vis;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leFont* getTicksLabelFont(leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leFont*)_this->ticksLabelFont;
}

static leResult setTicksLabelFont(leBarGraphWidget* _this, 
                                  const leFont* font)
{
    LE_ASSERT_THIS();

    _this->ticksLabelFont = font;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leResult addSeries(leBarGraphWidget* _this,
                          uint32_t* seriesID)
{
    leBarGraphDataSeries * series;
    
    LE_ASSERT_THIS();
    
    series = LE_MALLOC(sizeof(leBarGraphDataSeries));
    
    if(series == NULL)
        return LE_FAILURE;

    leArray_Create(&series->data);
    
    series->axis = BAR_GRAPH_AXIS_0;
    series->scheme = leGetDefaultScheme();
    
    leArray_PushBack(&_this->dataSeriesArray, series);
    
    if(seriesID != NULL)
    {
        *seriesID = _this->dataSeriesArray.size;
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leResult addDataToSeries(leBarGraphWidget* _this,
                                uint32_t seriesID,
                                int32_t value,
                                uint32_t* index)
{
    leBarGraphDataSeries* series;
    int32_t* data;
    
    LE_ASSERT_THIS();
    
    if(seriesID >= _this->dataSeriesArray.size)
        return LE_FAILURE;
    
    series = leArray_Get(&_this->dataSeriesArray, seriesID);
    
    if(series == NULL)
        return LE_FAILURE;
    
    data = LE_MALLOC(sizeof(data));
    
    if(data == NULL)
        return LE_FAILURE;
    
    *data = value;
    
    leArray_PushBack(&series->data, (void*)data);

    if(index != NULL)
    {
       *index = series->data.size - 1;
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leResult setDataInSeries(leBarGraphWidget* _this, 
                                uint32_t seriesID,
                                uint32_t index,
                                int32_t value)
{
    leBarGraphDataSeries* series;
    int32_t* data;
    leRect damagedRect;
    
    LE_ASSERT_THIS();
    
    if(seriesID >= _this->dataSeriesArray.size)
        return LE_FAILURE;
    
    series = leArray_Get(&_this->dataSeriesArray, seriesID);
    
    if(series == NULL)
        return LE_FAILURE;

    if(index >= series->data.size)
        return LE_FAILURE;

    data = leArray_Get(&series->data, index);
    
    if(data == NULL)
        return LE_FAILURE;
    
    if(value == *data)
        return LE_SUCCESS;
    
    *data = value;

    _leBarGraphWidget_GetBarRect(_this,
                                 seriesID,
                                 index,
                                 &damagedRect);


    leRenderer_DamageArea(&damagedRect);
    
    return LE_SUCCESS;
}

static leScheme* getSeriesScheme(const leBarGraphWidget* _this,
                                 uint32_t seriesID)
{
    leBarGraphDataSeries* series;
    
    LE_ASSERT_THIS();
    
    if(seriesID >= _this->dataSeriesArray.size)
        return NULL;
    
    series = leArray_Get(&_this->dataSeriesArray, seriesID);
    
    if(series == NULL)
        return NULL;
    
    return (leScheme*)series->scheme;
}

static leResult setSeriesScheme(leBarGraphWidget* _this,
                                uint32_t seriesID,
                                const leScheme* scheme)
{
    leBarGraphDataSeries* series;
    
    LE_ASSERT_THIS();
    
    if(scheme == NULL)
        return LE_FAILURE;
    
    if(seriesID >= (int32_t) _this->dataSeriesArray.size)
        return LE_FAILURE;
    
    if(seriesID < 0)
        seriesID = _this->dataSeriesArray.size - 1;
    
    series = leArray_Get(&_this->dataSeriesArray, seriesID);
    
    if(series == NULL)
        return LE_FAILURE;
    
    series->scheme = scheme;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leResult addCategory(leBarGraphWidget* _this,
                            uint32_t* id)
{
    LE_ASSERT_THIS();

    leArray_PushBack(&_this->categories, NULL);

    if(id != NULL)
    {
        *id = _this->categories.size;
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leString* getCategoryString(const leBarGraphWidget* _this,
                                   uint32_t categoryID)
{
    leString* category;
    
    LE_ASSERT_THIS();
    
    if(categoryID >= _this->categories.size)
        return NULL;
    
    category = leArray_Get(&_this->categories, categoryID);
    
    if(category == NULL)
        return NULL;
        
    return category;
}

static leResult setCategoryString(leBarGraphWidget* _this,
                                  uint32_t categoryID,
                                  const leString* str)
{
    if(categoryID >= (int32_t)_this->categories.size)
        return LE_FAILURE;
    
    LE_ASSERT_THIS();
    
    if(categoryID < 0)
    {
        categoryID = _this->categories.size - 1;
    }
    
    if(leArray_Set(&_this->categories, categoryID, (void*)str) == LE_FAILURE)
        return LE_FAILURE;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leResult clearData(leBarGraphWidget* _this)
{
    leBarGraphDataSeries* seriesArray;
    uint32_t i;
    
    LE_ASSERT_THIS();
    
    // free the category array
    leArray_Clear(&_this->categories);
    
    // free category string data
    for (i = 0; i < _this->dataSeriesArray.size; i++)
    {
        seriesArray = leArray_Get(&_this->dataSeriesArray, i);
        
        if(seriesArray != NULL)
        {
            // destroy the data list
            leArray_Clear(&seriesArray->data);
        }    
        
        // destroy the pointer list
        LE_FREE(seriesArray);
    }
    
    leArray_Clear(&_this->dataSeriesArray);
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static void handleLanguageChangeEvent(leBarGraphWidget* _this)
{
    LE_ASSERT_THIS();

    _this->fn->invalidate(_this);
}

void _leBarGraphWidget_Paint(leBarGraphWidget* _this);

#if LE_DYNAMIC_VTABLES == 1
void _leWidget_FillVTable(leWidgetVTable* tbl);

void _leBarGraphWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&barGraphWidgetVTable);
    
    /* overrides from base class */
    barGraphWidgetVTable._destructor = _leBarGraphWidget_Destructor;
    barGraphWidgetVTable._paint = _leBarGraphWidget_Paint;
    barGraphWidgetVTable.languageChangeEvent = handleLanguageChangeEvent;
    
    /* member functions */
    barGraphWidgetVTable.getTickLength = getTickLength;
    barGraphWidgetVTable.setTickLength = setTickLength;
    barGraphWidgetVTable.getMinValue = getMinValue;
    barGraphWidgetVTable.setMinValue = setMinValue;
    barGraphWidgetVTable.getMaxValue = getMaxValue;
    barGraphWidgetVTable.setMaxValue = setMaxValue;
    barGraphWidgetVTable.getValueAxisLabelsVisible = getValueAxisLabelsVisible;
    barGraphWidgetVTable.setValueAxisLabelsVisible = setValueAxisLabelsVisible;
    barGraphWidgetVTable.getValueAxisTicksVisible = getValueAxisTicksVisible;
    barGraphWidgetVTable.setValueAxisTicksVisible = setValueAxisTicksVisible;
    barGraphWidgetVTable.getValueAxisTicksInterval = getValueAxisTicksInterval;
    barGraphWidgetVTable.setValueAxisTicksInterval = setValueAxisTicksInterval;
    barGraphWidgetVTable.getValueAxisTicksPosition = getValueAxisTicksPosition;
    barGraphWidgetVTable.setValueAxisTicksPosition = setValueAxisTicksPosition;
    barGraphWidgetVTable.getValueAxisSubticksVisible = getValueAxisSubticksVisible;
    barGraphWidgetVTable.setValueAxisSubticksVisible = setValueAxisSubticksVisible;
    barGraphWidgetVTable.getValueAxisSubticksInterval = getValueAxisSubticksInterval;
    barGraphWidgetVTable.setValueAxisSubticksInterval = setValueAxisSubticksInterval;
    barGraphWidgetVTable.getValueAxisSubticksPosition = getValueAxisSubticksPosition;
    barGraphWidgetVTable.setValueAxisSubticksPosition = setValueAxisSubticksPosition;
    barGraphWidgetVTable.getCategoryAxisTicksVisible = getCategoryAxisTicksVisible;
    barGraphWidgetVTable.setCategoryAxisTicksVisible = setCategoryAxisTicksVisible;
    barGraphWidgetVTable.getCategoryAxisTicksPosition = getCategoryAxisTicksPosition;
    barGraphWidgetVTable.setCategoryAxisTicksPosition = setCategoryAxisTicksPosition;
    barGraphWidgetVTable.getCategoryAxisLabelsVisible = getCategoryAxisLabelsVisible;
    barGraphWidgetVTable.setCategoryAxisLabelsVisible = setCategoryAxisLabelsVisible;
    barGraphWidgetVTable.addSeries = addSeries;
    barGraphWidgetVTable.getSeriesScheme = getSeriesScheme;
    barGraphWidgetVTable.setSeriesScheme = setSeriesScheme;
    barGraphWidgetVTable.addDataToSeries = addDataToSeries;
    barGraphWidgetVTable.setDataInSeries = setDataInSeries;
    barGraphWidgetVTable.clearData = clearData;
    barGraphWidgetVTable.getTicksLabelFont = getTicksLabelFont;
    barGraphWidgetVTable.setTicksLabelFont = setTicksLabelFont;
    barGraphWidgetVTable.getGridLinesVisible = getGridLinesVisible;
    barGraphWidgetVTable.setGridLinesVisible = setGridLinesVisible;
    barGraphWidgetVTable.addCategory = addCategory;
    barGraphWidgetVTable.getCategoryString = getCategoryString;
    barGraphWidgetVTable.setCategoryString = setCategoryString;
    barGraphWidgetVTable.getStacked = getStacked;
    barGraphWidgetVTable.setStacked = setStacked;
    barGraphWidgetVTable.getFillGraphArea = getFillGraphArea;
    barGraphWidgetVTable.setFillGraphArea = setFillGraphArea;
}

void _leBarGraphWidget_FillVTable(leBarGraphWidgetVTable* tbl)
{
    *tbl = barGraphWidgetVTable;
}
#else
static const leBarGraphWidgetVTable barGraphWidgetVTable =
{
    // base class
    .getType = (void*)_leWidget_GetType,
    .getX = (void*)_leWidget_GetX,
    .setX = (void*)_leWidget_SetX,
    .getY = (void*)_leWidget_GetY,
    .setY = (void*)_leWidget_SetY,
    .setPosition = (void*)_leWidget_SetPosition,
    .translate = (void*)_leWidget_Translate,
    .getWidth = (void*)_leWidget_GetWidth,
    .setWidth = (void*)_leWidget_SetWidth,
    .getHeight = (void*)_leWidget_GetHeight,
    .setHeight = (void*)_leWidget_SetHeight,
    .setSize = (void*)_leWidget_SetSize,
    .resize = (void*)_leWidget_Resize,
    .getAlphaEnabled = (void*)_leWidget_GetAlphaEnabled,
    .getCumulativeAlphaEnabled = (void*)_leWidget_GetCumulativeAlphaEnabled,
    .setAlphaEnabled = (void*)_leWidget_SetAlphaEnabled,
    .getAlphaAmount = (void*)_leWidget_GetAlphaAmount,
    .getCumulativeAlphaAmount = (void*)_leWidget_GetCumulativeAlphaAmount,
    .setAlphaAmount = (void*)_leWidget_SetAlphaAmount,
    .isOpaque = (void*)_leWidget_IsOpaque,
    .getEnabled = (void*)_leWidget_GetEnabled,
    .setEnabled = (void*)_leWidget_SetEnabled,
    .getVisible = (void*)_leWidget_GetVisible,
    .setVisible = (void*)_leWidget_SetVisible,
    .localRect = (void*)_leWidget_LocalRect,
    .rectToParent = (void*)_leWidget_RectToParentSpace,
    .rectToScreen = (void*)_leWidget_RectToScreenSpace,
    .addChild = (void*)_leWidget_AddChild,
    .removeChild = (void*)_leWidget_RemoveChild,
    .removeAllChildren = (void*)_leWidget_RemoveAllChildren,
    .getRootWidget = (void*)_leWidget_GetRootWidget,
    .setParent = (void*)_leWidget_SetParent,
    .getChildCount = (void*)_leWidget_GetChildCount,
    .getChildAtIndex = (void*)_leWidget_GetChildAtIndex,
    .getIndexOfChild = (void*)_leWidget_GetIndexOfChild,
    .containsDescendent = (void*)_leWidget_ContainsDescendent,
    .getScheme = (void*)_leWidget_GetScheme,
    .setScheme = (void*)_leWidget_SetScheme,
    .getBorderType = (void*)_leWidget_GetBorderType,
    .setBorderType = (void*)_leWidget_SetBorderType,
    .getBackgroundType = (void*)_leWidget_GetBackgroundType,
    .setBackgroundType = (void*)_leWidget_SetBackgroundType,
    .getHAlignment = (void*)_leWidget_GetHAlignment,
    .setHAlignment = (void*)_leWidget_SetHAlignment,
    .getVAlignment = (void*)_leWidget_GetVAlignment,
    .setVAlignment = (void*)_leWidget_SetVAlignment,
    .getMargins = (void*)_leWidget_GetMargins,
    .setMargins = (void*)_leWidget_SetMargins,
    .getCornerRadius = (void*)_leWidget_GetCornerRadius,
    .setCornerRadius = (void*)_leWidget_SetCornerRadius,
    .hasFocus = (void*)_leWidget_HasFocus,
    .setFocus = (void*)_leWidget_SetFocus,
    .invalidate = (void*)_leWidget_Invalidate,
    .invalidateContents = (void*)_leWidget_InvalidateContents,
    .installEventFilter = (void*)_leWidget_InstallEventFilter,
    .removeEventFilter = (void*)_leWidget_RemoveEventFilter,

    .update = (void*)_leWidget_Update,

    .touchDownEvent = (void*)_leWidget_TouchDownEvent,
    .touchUpEvent = (void*)_leWidget_TouchUpEvent,
    .touchMoveEvent = (void*)_leWidget_TouchMoveEvent,
    .moveEvent = (void*)_leWidget_MoveEvent,
    .resizeEvent = (void*)_leWidget_ResizeEvent,
    .focusLostEvent = (void*)_leWidget_FocusLostEvent,
    .focusGainedEvent = (void*)_leWidget_FocusGainedEvent,
    .languageChangeEvent = (void*)_leWidget_LanguageChangeEvent,

    ._handleEvent = (void*)_leWidget_HandleEvent,
    ._validateChildren = (void*)_leWidget_ValidateChildren,
    ._increaseDirtyState = (void*)_leWidget_IncreaseDirtyState,
    ._setDirtyState = (void*)_leWidget_SetDirtyState,
    ._clearDirtyState = (void*)_leWidget_ClearDirtyState,
    ._invalidateBorderAreas = (void*)_leWidget_InvalidateBorderAreas,
    ._damageArea = (void*)_leWidget_DamageArea,

    /* overrides from base class */
    ._destructor = _leBarGraphWidget_Destructor,
    ._paint = _leBarGraphWidget_Paint,
    .languageChangeEvent = handleLanguageChangeEvent,

    /* member functions */
    .getTickLength = getTickLength,
    .setTickLength = setTickLength,
    .getMinValue = getMinValue,
    .setMinValue = setMinValue,
    .getMaxValue = getMaxValue,
    .setMaxValue = setMaxValue,
    .getValueAxisLabelsVisible = getValueAxisLabelsVisible,
    .setValueAxisLabelsVisible = setValueAxisLabelsVisible,
    .getValueAxisTicksVisible = getValueAxisTicksVisible,
    .setValueAxisTicksVisible = setValueAxisTicksVisible,
    .getValueAxisTicksInterval = getValueAxisTicksInterval,
    .setValueAxisTicksInterval = setValueAxisTicksInterval,
    .getValueAxisTicksPosition = getValueAxisTicksPosition,
    .setValueAxisTicksPosition = setValueAxisTicksPosition,
    .getValueAxisSubticksVisible = getValueAxisSubticksVisible,
    .setValueAxisSubticksVisible = setValueAxisSubticksVisible,
    .getValueAxisSubticksInterval = getValueAxisSubticksInterval,
    .setValueAxisSubticksInterval = setValueAxisSubticksInterval,
    .getValueAxisSubticksPosition = getValueAxisSubticksPosition,
    .setValueAxisSubticksPosition = setValueAxisSubticksPosition,
    .getCategoryAxisTicksVisible = getCategoryAxisTicksVisible,
    .setCategoryAxisTicksVisible = setCategoryAxisTicksVisible,
    .getCategoryAxisTicksPosition = getCategoryAxisTicksPosition,
    .setCategoryAxisTicksPosition = setCategoryAxisTicksPosition,
    .getCategoryAxisLabelsVisible = getCategoryAxisLabelsVisible,
    .setCategoryAxisLabelsVisible = setCategoryAxisLabelsVisible,
    .addSeries = addSeries,
    .getSeriesScheme = getSeriesScheme,
    .setSeriesScheme = setSeriesScheme,
    .addDataToSeries = addDataToSeries,
    .setDataInSeries = setDataInSeries,
    .clearData = clearData,
    .getTicksLabelFont = getTicksLabelFont,
    .setTicksLabelFont = setTicksLabelFont,
    .getGridLinesVisible = getGridLinesVisible,
    .setGridLinesVisible = setGridLinesVisible,
    .addCategory = addCategory,
    .getCategoryString = getCategoryString,
    .setCategoryString = setCategoryString,
    .getStacked = getStacked,
    .setStacked = setStacked,
    .getFillGraphArea = getFillGraphArea,
    .setFillGraphArea = setFillGraphArea,
};
#endif

#endif // LE_BARGRAPH_WIDGET_ENABLED
