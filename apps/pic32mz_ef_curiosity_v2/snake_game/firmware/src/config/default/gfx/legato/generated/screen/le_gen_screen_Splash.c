#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// widget list for layer 0
static leWidget* root0;

leWidget* Panel_splash_screen;
leImageWidget* PIC32_logo;
leImageWidget* Splash_bar;


static leBool showing = LE_FALSE;

leResult screenInit_Splash()
{
    return LE_SUCCESS;
}

leResult screenShow_Splash()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    Panel_splash_screen = leWidget_New();
    Panel_splash_screen->fn->setPosition(Panel_splash_screen, 0, 0);
    Panel_splash_screen->fn->setSize(Panel_splash_screen, 800, 480);
    Panel_splash_screen->fn->setScheme(Panel_splash_screen, &Splash_Panel);
    root0->fn->addChild(root0, Panel_splash_screen);

    PIC32_logo = leImageWidget_New();
    PIC32_logo->fn->setPosition(PIC32_logo, 264, 192);
    PIC32_logo->fn->setSize(PIC32_logo, 240, 62);
    PIC32_logo->fn->setAlphaAmount(PIC32_logo, 0);
    PIC32_logo->fn->setBackgroundType(PIC32_logo, LE_WIDGET_BACKGROUND_NONE);
    PIC32_logo->fn->setImage(PIC32_logo, &PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)PIC32_logo);

    Splash_bar = leImageWidget_New();
    Splash_bar->fn->setPosition(Splash_bar, 0, 389);
    Splash_bar->fn->setSize(Splash_bar, 800, 91);
    Splash_bar->fn->setAlphaAmount(Splash_bar, 0);
    Splash_bar->fn->setImage(Splash_bar, &Bar_1);
    root0->fn->addChild(root0, (leWidget*)Splash_bar);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash()
{
}

void screenHide_Splash()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    Panel_splash_screen = NULL;
    PIC32_logo = NULL;
    Splash_bar = NULL;
    showing = LE_FALSE;
}

void screenDestroy_Splash()
{

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

