#include "gfx/legato/generated/screen/le_gen_screen_SlideShow_Screen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* SlideShow_Screen_SS_PanelWidget;
leImageWidget* SlideShow_Screen_Images;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SlideShow_Screen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SlideShow_Screen(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    SlideShow_Screen_SS_PanelWidget = leWidget_New();
    SlideShow_Screen_SS_PanelWidget->fn->setPosition(SlideShow_Screen_SS_PanelWidget, 0, 0);
    SlideShow_Screen_SS_PanelWidget->fn->setSize(SlideShow_Screen_SS_PanelWidget, 480, 272);
    SlideShow_Screen_SS_PanelWidget->fn->setScheme(SlideShow_Screen_SS_PanelWidget, &WhiteScheme);
    SlideShow_Screen_SS_PanelWidget->fn->setMargins(SlideShow_Screen_SS_PanelWidget, 0, 0, 0, 0);
    root0->fn->addChild(root0, (leWidget*)SlideShow_Screen_SS_PanelWidget);

    SlideShow_Screen_Images = leImageWidget_New();
    SlideShow_Screen_Images->fn->setPosition(SlideShow_Screen_Images, 0, 0);
    SlideShow_Screen_Images->fn->setSize(SlideShow_Screen_Images, 480, 272);
    SlideShow_Screen_Images->fn->setScheme(SlideShow_Screen_Images, &WhiteScheme);
    SlideShow_Screen_Images->fn->setBorderType(SlideShow_Screen_Images, LE_WIDGET_BORDER_NONE);
    SlideShow_Screen_Images->fn->setMargins(SlideShow_Screen_Images, 0, 0, 0, 0);
    root0->fn->addChild(root0, (leWidget*)SlideShow_Screen_Images);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SlideShow_Screen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_SlideShow_Screen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SlideShow_Screen_SS_PanelWidget = NULL;
    SlideShow_Screen_Images = NULL;


    showing = LE_FALSE;
}

void screenDestroy_SlideShow_Screen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_SlideShow_Screen(uint32_t lyrIdx)
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

