#include "gfx/legato/generated/screen/le_gen_screen_Screen2.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen2_Panel_0;
leCircleWidget* Screen2_CircleWidget_0;
leButtonWidget* Screen2_BTNscr2Ret;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen2(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen2(void)
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

    Screen2_Panel_0 = leWidget_New();
    Screen2_Panel_0->fn->setPosition(Screen2_Panel_0, 0, 0);
    Screen2_Panel_0->fn->setSize(Screen2_Panel_0, 432, 432);
    Screen2_Panel_0->fn->setScheme(Screen2_Panel_0, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen2_Panel_0);

    Screen2_CircleWidget_0 = leCircleWidget_New();
    Screen2_CircleWidget_0->fn->setPosition(Screen2_CircleWidget_0, 165, 146);
    Screen2_CircleWidget_0->fn->setSize(Screen2_CircleWidget_0, 105, 105);
    Screen2_CircleWidget_0->fn->setScheme(Screen2_CircleWidget_0, &GreenScheme);
    Screen2_CircleWidget_0->fn->setRadius(Screen2_CircleWidget_0, 50);
    Screen2_CircleWidget_0->fn->setThickness(Screen2_CircleWidget_0, 5);
    root0->fn->addChild(root0, (leWidget*)Screen2_CircleWidget_0);

    Screen2_BTNscr2Ret = leButtonWidget_New();
    Screen2_BTNscr2Ret->fn->setPosition(Screen2_BTNscr2Ret, 169, 325);
    Screen2_BTNscr2Ret->fn->setPressedEventCallback(Screen2_BTNscr2Ret, event_Screen2_BTNscr2Ret_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Screen2_BTNscr2Ret);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen2(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen2(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen2_Panel_0 = NULL;
    Screen2_CircleWidget_0 = NULL;
    Screen2_BTNscr2Ret = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen2(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen2(uint32_t lyrIdx)
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

