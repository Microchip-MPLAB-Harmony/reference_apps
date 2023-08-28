#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_BackgroundPanel;
leImageWidget* Screen0_mchplogo;
leTextFieldWidget* Screen0_temp_val;
leTextFieldWidget* Screen0_temp;
leTextFieldWidget* Screen0_light;
leTextFieldWidget* Screen0_light_val;
leImageWidget* Screen0_nonsecure;
leImageWidget* Screen0_secure;

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

    Screen0_mchplogo = leImageWidget_New();
    Screen0_mchplogo->fn->setPosition(Screen0_mchplogo, 37, 9);
    Screen0_mchplogo->fn->setSize(Screen0_mchplogo, 20, 20);
    Screen0_mchplogo->fn->setBackgroundType(Screen0_mchplogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mchplogo->fn->setBorderType(Screen0_mchplogo, LE_WIDGET_BORDER_NONE);
    Screen0_mchplogo->fn->setImage(Screen0_mchplogo, (leImage*)&MCHP);
    root0->fn->addChild(root0, (leWidget*)Screen0_mchplogo);

    Screen0_temp_val = leTextFieldWidget_New();
    Screen0_temp_val->fn->setPosition(Screen0_temp_val, 53, 51);
    Screen0_temp_val->fn->setSize(Screen0_temp_val, 39, 19);
    Screen0_temp_val->fn->setBorderType(Screen0_temp_val, LE_WIDGET_BORDER_NONE);
    Screen0_temp_val->fn->setHAlignment(Screen0_temp_val, LE_HALIGN_LEFT);
    Screen0_temp_val->fn->setString(Screen0_temp_val, (leString*)&string_String);
    Screen0_temp_val->fn->setHintString(Screen0_temp_val, (leString*)&string_String);
    Screen0_temp_val->fn->setFont(Screen0_temp_val, (leFont*)&NotoMono_Regular);
    root0->fn->addChild(root0, (leWidget*)Screen0_temp_val);

    Screen0_temp = leTextFieldWidget_New();
    Screen0_temp->fn->setPosition(Screen0_temp, 0, 44);
    Screen0_temp->fn->setSize(Screen0_temp, 40, 35);
    Screen0_temp->fn->setBorderType(Screen0_temp, LE_WIDGET_BORDER_NONE);
    Screen0_temp->fn->setHAlignment(Screen0_temp, LE_HALIGN_LEFT);
    Screen0_temp->fn->setString(Screen0_temp, (leString*)&string_Temp);
    Screen0_temp->fn->setHintString(Screen0_temp, (leString*)&string_Temp);
    Screen0_temp->fn->setFont(Screen0_temp, (leFont*)&NotoMono_Regular);
    root0->fn->addChild(root0, (leWidget*)Screen0_temp);

    Screen0_light = leTextFieldWidget_New();
    Screen0_light->fn->setPosition(Screen0_light, 1, 70);
    Screen0_light->fn->setSize(Screen0_light, 45, 25);
    Screen0_light->fn->setBorderType(Screen0_light, LE_WIDGET_BORDER_NONE);
    Screen0_light->fn->setHAlignment(Screen0_light, LE_HALIGN_LEFT);
    Screen0_light->fn->setString(Screen0_light, (leString*)&string_Light);
    Screen0_light->fn->setHintString(Screen0_light, (leString*)&string_Light);
    Screen0_light->fn->setFont(Screen0_light, (leFont*)&NotoMono_Regular);
    root0->fn->addChild(root0, (leWidget*)Screen0_light);

    Screen0_light_val = leTextFieldWidget_New();
    Screen0_light_val->fn->setPosition(Screen0_light_val, 55, 69);
    Screen0_light_val->fn->setSize(Screen0_light_val, 40, 25);
    Screen0_light_val->fn->setBorderType(Screen0_light_val, LE_WIDGET_BORDER_NONE);
    Screen0_light_val->fn->setHAlignment(Screen0_light_val, LE_HALIGN_LEFT);
    Screen0_light_val->fn->setString(Screen0_light_val, (leString*)&string_String);
    Screen0_light_val->fn->setHintString(Screen0_light_val, (leString*)&string_String);
    Screen0_light_val->fn->setFont(Screen0_light_val, (leFont*)&NotoMono_Regular);
    root0->fn->addChild(root0, (leWidget*)Screen0_light_val);

    Screen0_nonsecure = leImageWidget_New();
    Screen0_nonsecure->fn->setPosition(Screen0_nonsecure, 0, 0);
    Screen0_nonsecure->fn->setSize(Screen0_nonsecure, 33, 41);
    Screen0_nonsecure->fn->setVisible(Screen0_nonsecure, LE_FALSE);
    Screen0_nonsecure->fn->setBackgroundType(Screen0_nonsecure, LE_WIDGET_BACKGROUND_NONE);
    Screen0_nonsecure->fn->setBorderType(Screen0_nonsecure, LE_WIDGET_BORDER_NONE);
    Screen0_nonsecure->fn->setImage(Screen0_nonsecure, (leImage*)&Orginal_NonSecure);
    root0->fn->addChild(root0, (leWidget*)Screen0_nonsecure);

    Screen0_secure = leImageWidget_New();
    Screen0_secure->fn->setPosition(Screen0_secure, 63, 0);
    Screen0_secure->fn->setSize(Screen0_secure, 33, 41);
    Screen0_secure->fn->setVisible(Screen0_secure, LE_FALSE);
    Screen0_secure->fn->setBackgroundType(Screen0_secure, LE_WIDGET_BACKGROUND_NONE);
    Screen0_secure->fn->setBorderType(Screen0_secure, LE_WIDGET_BORDER_NONE);
    Screen0_secure->fn->setImage(Screen0_secure, (leImage*)&Orginal_Secure);
    root0->fn->addChild(root0, (leWidget*)Screen0_secure);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BackgroundPanel = NULL;
    Screen0_mchplogo = NULL;
    Screen0_temp_val = NULL;
    Screen0_temp = NULL;
    Screen0_light = NULL;
    Screen0_light_val = NULL;
    Screen0_nonsecure = NULL;
    Screen0_secure = NULL;


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

