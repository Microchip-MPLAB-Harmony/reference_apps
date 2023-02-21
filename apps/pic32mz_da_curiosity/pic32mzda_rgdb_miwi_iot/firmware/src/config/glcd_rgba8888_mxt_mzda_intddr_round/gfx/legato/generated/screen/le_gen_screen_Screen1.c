#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen1_PanelBG;
leWidget* Screen1_PanelWidget_0;
leWidget* Screen1_PanelWidget_1;
leListWheelWidget* Screen1_ListWheelWidget_0;
leButtonWidget* Screen1_btnChoose;
leLabelWidget* Screen1_LabelWidget_0;
leLabelWidget* Screen1_lbonline;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen1(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 432, 432);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen1_PanelBG = leWidget_New();
    Screen1_PanelBG->fn->setPosition(Screen1_PanelBG, 0, 0);
    Screen1_PanelBG->fn->setSize(Screen1_PanelBG, 432, 432);
    Screen1_PanelBG->fn->setScheme(Screen1_PanelBG, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_PanelBG);

    Screen1_ListWheelWidget_0 = leListWheelWidget_New();
    Screen1_ListWheelWidget_0->fn->setPosition(Screen1_ListWheelWidget_0, 136, 0);
    Screen1_ListWheelWidget_0->fn->setSize(Screen1_ListWheelWidget_0, 160, 432);
    Screen1_ListWheelWidget_0->fn->setBackgroundType(Screen1_ListWheelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ListWheelWidget_0->fn->setBorderType(Screen1_ListWheelWidget_0, LE_WIDGET_BORDER_NONE);
    Screen1_ListWheelWidget_0->fn->setVisibleItemCount(Screen1_ListWheelWidget_0, 3);
    Screen1_ListWheelWidget_0->fn->setIconMargin(Screen1_ListWheelWidget_0, 0);
    Screen1_ListWheelWidget_0->fn->setShowIndicators(Screen1_ListWheelWidget_0, LE_FALSE);
    Screen1_ListWheelWidget_0->fn->setIndicatorArea(Screen1_ListWheelWidget_0, 80);
    Screen1_ListWheelWidget_0->fn->setIndicatorFill(Screen1_ListWheelWidget_0, LE_LISTWHEEL_INDICATOR_FILL_NONE);
    Screen1_ListWheelWidget_0->fn->setShaded(Screen1_ListWheelWidget_0, LE_FALSE);
    Screen1_ListWheelWidget_0->fn->setAutoHideWheel(Screen1_ListWheelWidget_0, LE_TRUE);
    Screen1_ListWheelWidget_0->fn->appendItem(Screen1_ListWheelWidget_0);
    Screen1_ListWheelWidget_0->fn->setItemIcon(Screen1_ListWheelWidget_0, 0, &n1);
    Screen1_ListWheelWidget_0->fn->appendItem(Screen1_ListWheelWidget_0);
    Screen1_ListWheelWidget_0->fn->setItemIcon(Screen1_ListWheelWidget_0, 1, &n2);
    Screen1_ListWheelWidget_0->fn->appendItem(Screen1_ListWheelWidget_0);
    Screen1_ListWheelWidget_0->fn->setItemIcon(Screen1_ListWheelWidget_0, 2, &n3);
    Screen1_ListWheelWidget_0->fn->setSelectedItemChangedEventCallback(Screen1_ListWheelWidget_0, event_Screen1_ListWheelWidget_0_OnSelectionChanged);
    Screen1_PanelBG->fn->addChild(Screen1_PanelBG, (leWidget*)Screen1_ListWheelWidget_0);

    Screen1_btnChoose = leButtonWidget_New();
    Screen1_btnChoose->fn->setPosition(Screen1_btnChoose, 47, 184);
    Screen1_btnChoose->fn->setSize(Screen1_btnChoose, 65, 62);
    Screen1_btnChoose->fn->setBackgroundType(Screen1_btnChoose, LE_WIDGET_BACKGROUND_NONE);
    Screen1_btnChoose->fn->setBorderType(Screen1_btnChoose, LE_WIDGET_BORDER_NONE);
    Screen1_btnChoose->fn->setPressedEventCallback(Screen1_btnChoose, event_Screen1_btnChoose_OnPressed);
    Screen1_btnChoose->fn->setReleasedEventCallback(Screen1_btnChoose, event_Screen1_btnChoose_OnReleased);
    Screen1_ListWheelWidget_0->fn->addChild(Screen1_ListWheelWidget_0, (leWidget*)Screen1_btnChoose);

    Screen1_PanelWidget_0 = leWidget_New();
    Screen1_PanelWidget_0->fn->setPosition(Screen1_PanelWidget_0, 103, 0);
    Screen1_PanelWidget_0->fn->setSize(Screen1_PanelWidget_0, 240, 51);
    Screen1_PanelWidget_0->fn->setScheme(Screen1_PanelWidget_0, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_PanelWidget_0);

    Screen1_LabelWidget_0 = leLabelWidget_New();
    Screen1_LabelWidget_0->fn->setPosition(Screen1_LabelWidget_0, 18, 26);
    Screen1_LabelWidget_0->fn->setSize(Screen1_LabelWidget_0, 198, 25);
    Screen1_LabelWidget_0->fn->setScheme(Screen1_LabelWidget_0, &RedScheme);
    Screen1_LabelWidget_0->fn->setBackgroundType(Screen1_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen1_LabelWidget_0->fn->setString(Screen1_LabelWidget_0, (leString*)&string_title);
    Screen1_PanelWidget_0->fn->addChild(Screen1_PanelWidget_0, (leWidget*)Screen1_LabelWidget_0);

    Screen1_PanelWidget_1 = leWidget_New();
    Screen1_PanelWidget_1->fn->setPosition(Screen1_PanelWidget_1, 124, 387);
    Screen1_PanelWidget_1->fn->setSize(Screen1_PanelWidget_1, 176, 45);
    Screen1_PanelWidget_1->fn->setScheme(Screen1_PanelWidget_1, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_PanelWidget_1);

    Screen1_lbonline = leLabelWidget_New();
    Screen1_lbonline->fn->setPosition(Screen1_lbonline, 49, 1);
    Screen1_lbonline->fn->setSize(Screen1_lbonline, 91, 25);
    Screen1_lbonline->fn->setScheme(Screen1_lbonline, &Alarm);
    Screen1_lbonline->fn->setBackgroundType(Screen1_lbonline, LE_WIDGET_BACKGROUND_NONE);
    Screen1_lbonline->fn->setString(Screen1_lbonline, (leString*)&string_Offline);
    Screen1_PanelWidget_1->fn->addChild(Screen1_PanelWidget_1, (leWidget*)Screen1_lbonline);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    Screen1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen1(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen1(void)
{
    Screen1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen1_PanelBG = NULL;
    Screen1_PanelWidget_0 = NULL;
    Screen1_PanelWidget_1 = NULL;
    Screen1_ListWheelWidget_0 = NULL;
    Screen1_btnChoose = NULL;
    Screen1_LabelWidget_0 = NULL;
    Screen1_lbonline = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx)
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

