#include "gfx/legato/generated/screen/le_gen_screen_Start_screen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Start_screen_PanelWidget0;
leImageWidget* Start_screen_ImageWidget0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Start_screen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Start_screen(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 96, 96);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Start_screen_PanelWidget0 = leWidget_New();
    Start_screen_PanelWidget0->fn->setPosition(Start_screen_PanelWidget0, 0, 0);
    Start_screen_PanelWidget0->fn->setSize(Start_screen_PanelWidget0, 96, 96);
    Start_screen_PanelWidget0->fn->setScheme(Start_screen_PanelWidget0, &WhileScheme);
    root0->fn->addChild(root0, (leWidget*)Start_screen_PanelWidget0);

    Start_screen_ImageWidget0 = leImageWidget_New();
    Start_screen_ImageWidget0->fn->setPosition(Start_screen_ImageWidget0, 18, 27);
    Start_screen_ImageWidget0->fn->setSize(Start_screen_ImageWidget0, 64, 44);
    Start_screen_ImageWidget0->fn->setAlphaEnabled(Start_screen_ImageWidget0, LE_TRUE);
    Start_screen_ImageWidget0->fn->setAlphaAmount(Start_screen_ImageWidget0, 0);
    Start_screen_ImageWidget0->fn->setScheme(Start_screen_ImageWidget0, &WhileScheme);
    Start_screen_ImageWidget0->fn->setBorderType(Start_screen_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Start_screen_ImageWidget0->fn->setImage(Start_screen_ImageWidget0, (leImage*)&Harmony_logo);
    root0->fn->addChild(root0, (leWidget*)Start_screen_ImageWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Start_screen(void)
{
}

void screenHide_Start_screen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Start_screen_PanelWidget0 = NULL;
    Start_screen_ImageWidget0 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Start_screen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Start_screen(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

