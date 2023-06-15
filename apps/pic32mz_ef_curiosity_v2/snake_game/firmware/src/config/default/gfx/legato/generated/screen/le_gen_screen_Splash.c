#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Splash_Panel_splash_screen;
leImageWidget* Splash_PIC32_logo;
leImageWidget* Splash_Splash_bar;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Splash_Panel_splash_screen = leWidget_New();
    Splash_Panel_splash_screen->fn->setPosition(Splash_Panel_splash_screen, 0, 0);
    Splash_Panel_splash_screen->fn->setSize(Splash_Panel_splash_screen, 800, 480);
    Splash_Panel_splash_screen->fn->setScheme(Splash_Panel_splash_screen, &Splash_Panel);
    root0->fn->addChild(root0, (leWidget*)Splash_Panel_splash_screen);

    Splash_PIC32_logo = leImageWidget_New();
    Splash_PIC32_logo->fn->setPosition(Splash_PIC32_logo, 264, 192);
    Splash_PIC32_logo->fn->setSize(Splash_PIC32_logo, 240, 62);
    Splash_PIC32_logo->fn->setAlphaAmount(Splash_PIC32_logo, 0);
    Splash_PIC32_logo->fn->setBackgroundType(Splash_PIC32_logo, LE_WIDGET_BACKGROUND_NONE);
    Splash_PIC32_logo->fn->setBorderType(Splash_PIC32_logo, LE_WIDGET_BORDER_NONE);
    Splash_PIC32_logo->fn->setImage(Splash_PIC32_logo, (leImage*)&PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)Splash_PIC32_logo);

    Splash_Splash_bar = leImageWidget_New();
    Splash_Splash_bar->fn->setPosition(Splash_Splash_bar, 0, 389);
    Splash_Splash_bar->fn->setSize(Splash_Splash_bar, 800, 91);
    Splash_Splash_bar->fn->setAlphaAmount(Splash_Splash_bar, 0);
    Splash_Splash_bar->fn->setBorderType(Splash_Splash_bar, LE_WIDGET_BORDER_NONE);
    Splash_Splash_bar->fn->setImage(Splash_Splash_bar, (leImage*)&Bar_1);
    root0->fn->addChild(root0, (leWidget*)Splash_Splash_bar);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Splash(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_Panel_splash_screen = NULL;
    Splash_PIC32_logo = NULL;
    Splash_Splash_bar = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
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

