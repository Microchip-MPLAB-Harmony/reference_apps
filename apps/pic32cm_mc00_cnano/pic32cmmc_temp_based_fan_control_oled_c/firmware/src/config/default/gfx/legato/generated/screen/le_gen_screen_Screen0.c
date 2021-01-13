#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen0_BackgroundPanel;
leTextFieldWidget* Screen0_TextFieldWidget0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
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

    Screen0_BackgroundPanel = leWidget_New();
    Screen0_BackgroundPanel->fn->setPosition(Screen0_BackgroundPanel, 0, 0);
    Screen0_BackgroundPanel->fn->setSize(Screen0_BackgroundPanel, 96, 96);
    Screen0_BackgroundPanel->fn->setScheme(Screen0_BackgroundPanel, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackgroundPanel);

    Screen0_TextFieldWidget0 = leTextFieldWidget_New();
    Screen0_TextFieldWidget0->fn->setPosition(Screen0_TextFieldWidget0, -1, 35);
    Screen0_TextFieldWidget0->fn->setSize(Screen0_TextFieldWidget0, 91, 25);
    Screen0_TextFieldWidget0->fn->setBackgroundType(Screen0_TextFieldWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TextFieldWidget0->fn->setBorderType(Screen0_TextFieldWidget0, LE_WIDGET_BORDER_NONE);
    Screen0_TextFieldWidget0->fn->setHAlignment(Screen0_TextFieldWidget0, LE_HALIGN_LEFT);
    Screen0_TextFieldWidget0->fn->setString(Screen0_TextFieldWidget0, (leString*)&string_String);
    Screen0_TextFieldWidget0->fn->setHintString(Screen0_TextFieldWidget0, (leString*)&string_String);
    Screen0_TextFieldWidget0->fn->setFont(Screen0_TextFieldWidget0, (leFont*)&NotoMono_Regular);
    root0->fn->addChild(root0, (leWidget*)Screen0_TextFieldWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BackgroundPanel = NULL;
    Screen0_TextFieldWidget0 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
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

