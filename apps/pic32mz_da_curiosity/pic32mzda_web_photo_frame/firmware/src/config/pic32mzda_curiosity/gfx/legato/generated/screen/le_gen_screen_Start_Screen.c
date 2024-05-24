#include "gfx/legato/generated/screen/le_gen_screen_Start_Screen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Start_Screen_MM_PanelWidget;
leTextFieldWidget* Start_Screen_StartScreenLabel;
leTextFieldWidget* Start_Screen_TitleText;
leImageWidget* Start_Screen_MicrochipLogo;
leImageWidget* Start_Screen_HarmonyLogo;
leButtonWidget* Start_Screen_FullScreenButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Start_Screen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Start_Screen(void)
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

    Start_Screen_MM_PanelWidget = leWidget_New();
    Start_Screen_MM_PanelWidget->fn->setPosition(Start_Screen_MM_PanelWidget, 0, 0);
    Start_Screen_MM_PanelWidget->fn->setSize(Start_Screen_MM_PanelWidget, 480, 272);
    Start_Screen_MM_PanelWidget->fn->setScheme(Start_Screen_MM_PanelWidget, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_MM_PanelWidget);

    Start_Screen_StartScreenLabel = leTextFieldWidget_New();
    Start_Screen_StartScreenLabel->fn->setPosition(Start_Screen_StartScreenLabel, 0, 0);
    Start_Screen_StartScreenLabel->fn->setSize(Start_Screen_StartScreenLabel, 480, 40);
    Start_Screen_StartScreenLabel->fn->setScheme(Start_Screen_StartScreenLabel, &TitleScheme);
    Start_Screen_StartScreenLabel->fn->setBorderType(Start_Screen_StartScreenLabel, LE_WIDGET_BORDER_LINE);
     Start_Screen_StartScreenLabel->fn->setHAlignment(Start_Screen_StartScreenLabel, LE_HALIGN_CENTER);
    Start_Screen_StartScreenLabel->fn->setString(Start_Screen_StartScreenLabel, (leString*)&string_Start_Screen_Text);
    Start_Screen_StartScreenLabel->fn->setFont(Start_Screen_StartScreenLabel, (leFont*)&Font1);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_StartScreenLabel);

    Start_Screen_TitleText = leTextFieldWidget_New();
    Start_Screen_TitleText->fn->setPosition(Start_Screen_TitleText, 0, 232);
    Start_Screen_TitleText->fn->setSize(Start_Screen_TitleText, 480, 40);
    Start_Screen_TitleText->fn->setScheme(Start_Screen_TitleText, &TitleScheme);
    Start_Screen_TitleText->fn->setBorderType(Start_Screen_TitleText, LE_WIDGET_BORDER_LINE);
    Start_Screen_TitleText->fn->setHAlignment(Start_Screen_TitleText, LE_HALIGN_CENTER);
    Start_Screen_TitleText->fn->setString(Start_Screen_TitleText, (leString*)&string_Title);
    Start_Screen_TitleText->fn->setFont(Start_Screen_TitleText, (leFont*)&Font1);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_TitleText);

    Start_Screen_MicrochipLogo = leImageWidget_New();
    Start_Screen_MicrochipLogo->fn->setPosition(Start_Screen_MicrochipLogo, 5, 45);
    Start_Screen_MicrochipLogo->fn->setSize(Start_Screen_MicrochipLogo, 134, 32);
    Start_Screen_MicrochipLogo->fn->setBackgroundType(Start_Screen_MicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_MicrochipLogo->fn->setBorderType(Start_Screen_MicrochipLogo, LE_WIDGET_BORDER_NONE);
    Start_Screen_MicrochipLogo->fn->setImage(Start_Screen_MicrochipLogo, (leImage*)&mchpLogo_small);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_MicrochipLogo);

    Start_Screen_HarmonyLogo = leImageWidget_New();
    Start_Screen_HarmonyLogo->fn->setPosition(Start_Screen_HarmonyLogo, 100, 99);
    Start_Screen_HarmonyLogo->fn->setSize(Start_Screen_HarmonyLogo, 276, 127);
    Start_Screen_HarmonyLogo->fn->setScheme(Start_Screen_HarmonyLogo, &WhiteScheme);
    Start_Screen_HarmonyLogo->fn->setBorderType(Start_Screen_HarmonyLogo, LE_WIDGET_BORDER_NONE);
    Start_Screen_HarmonyLogo->fn->setImage(Start_Screen_HarmonyLogo, (leImage*)&slide_1);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_HarmonyLogo);

    Start_Screen_FullScreenButton = leButtonWidget_New();
    Start_Screen_FullScreenButton->fn->setPosition(Start_Screen_FullScreenButton, 0, 0);
    Start_Screen_FullScreenButton->fn->setSize(Start_Screen_FullScreenButton, 480, 272);
    Start_Screen_FullScreenButton->fn->setVisible(Start_Screen_FullScreenButton, LE_FALSE);
    Start_Screen_FullScreenButton->fn->setScheme(Start_Screen_FullScreenButton, &WhiteScheme);
    Start_Screen_FullScreenButton->fn->setBackgroundType(Start_Screen_FullScreenButton, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_FullScreenButton->fn->setBorderType(Start_Screen_FullScreenButton, LE_WIDGET_BORDER_NONE);
    Start_Screen_FullScreenButton->fn->setReleasedEventCallback(Start_Screen_FullScreenButton, event_Start_Screen_FullScreenButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_FullScreenButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Start_Screen(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Start_Screen(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Start_Screen_MM_PanelWidget = NULL;
    Start_Screen_StartScreenLabel = NULL;
    Start_Screen_TitleText = NULL;
    Start_Screen_MicrochipLogo = NULL;
    Start_Screen_HarmonyLogo = NULL;
    Start_Screen_FullScreenButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Start_Screen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Start_Screen(uint32_t lyrIdx)
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

