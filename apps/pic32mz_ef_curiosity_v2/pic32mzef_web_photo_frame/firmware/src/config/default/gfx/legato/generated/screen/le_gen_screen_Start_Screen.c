#include "gfx/legato/generated/screen/le_gen_screen_Start_Screen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Start_Screen_MM_PanelWidget;
leImageWidget* Start_Screen_HarmonyLogo;
leImageWidget* Start_Screen_MicrochipLogo;
leLabelWidget* Start_Screen_fastLabel;
leLabelWidget* Start_Screen_easyLabel;
leLabelWidget* Start_Screen_smartLabel;
leLabelWidget* Start_Screen_StartScreenLabel;
leLabelWidget* Start_Screen_TitleText;
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

    Start_Screen_HarmonyLogo = leImageWidget_New();
    Start_Screen_HarmonyLogo->fn->setPosition(Start_Screen_HarmonyLogo, 100, 99);
    Start_Screen_HarmonyLogo->fn->setSize(Start_Screen_HarmonyLogo, 276, 127);
    Start_Screen_HarmonyLogo->fn->setScheme(Start_Screen_HarmonyLogo, &WhiteScheme);
    Start_Screen_HarmonyLogo->fn->setBorderType(Start_Screen_HarmonyLogo, LE_WIDGET_BORDER_NONE);
    Start_Screen_HarmonyLogo->fn->setMargins(Start_Screen_HarmonyLogo, 0, 0, 0, 0);
    Start_Screen_HarmonyLogo->fn->setImage(Start_Screen_HarmonyLogo, (leImage*)&slide_1);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_HarmonyLogo);

    Start_Screen_MicrochipLogo = leImageWidget_New();
    Start_Screen_MicrochipLogo->fn->setPosition(Start_Screen_MicrochipLogo, 5, 45);
    Start_Screen_MicrochipLogo->fn->setSize(Start_Screen_MicrochipLogo, 152, 40);
    Start_Screen_MicrochipLogo->fn->setBorderType(Start_Screen_MicrochipLogo, LE_WIDGET_BORDER_NONE);
    Start_Screen_MicrochipLogo->fn->setImage(Start_Screen_MicrochipLogo, (leImage*)&mchpLogo_light);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_MicrochipLogo);

    Start_Screen_fastLabel = leLabelWidget_New();
    Start_Screen_fastLabel->fn->setPosition(Start_Screen_fastLabel, 380, 40);
    Start_Screen_fastLabel->fn->setSize(Start_Screen_fastLabel, 100, 40);
    Start_Screen_fastLabel->fn->setScheme(Start_Screen_fastLabel, &RedScheme);
    Start_Screen_fastLabel->fn->setBackgroundType(Start_Screen_fastLabel, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_fastLabel->fn->setHAlignment(Start_Screen_fastLabel, LE_HALIGN_RIGHT);
    Start_Screen_fastLabel->fn->setVAlignment(Start_Screen_fastLabel, LE_VALIGN_TOP);
    Start_Screen_fastLabel->fn->setString(Start_Screen_fastLabel, (leString*)&string_Fast);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_fastLabel);

    Start_Screen_easyLabel = leLabelWidget_New();
    Start_Screen_easyLabel->fn->setPosition(Start_Screen_easyLabel, 380, 90);
    Start_Screen_easyLabel->fn->setSize(Start_Screen_easyLabel, 100, 40);
    Start_Screen_easyLabel->fn->setScheme(Start_Screen_easyLabel, &GreenScheme);
    Start_Screen_easyLabel->fn->setBackgroundType(Start_Screen_easyLabel, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_easyLabel->fn->setHAlignment(Start_Screen_easyLabel, LE_HALIGN_RIGHT);
    Start_Screen_easyLabel->fn->setVAlignment(Start_Screen_easyLabel, LE_VALIGN_TOP);
    Start_Screen_easyLabel->fn->setString(Start_Screen_easyLabel, (leString*)&string_Easy);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_easyLabel);

    Start_Screen_smartLabel = leLabelWidget_New();
    Start_Screen_smartLabel->fn->setPosition(Start_Screen_smartLabel, 380, 140);
    Start_Screen_smartLabel->fn->setSize(Start_Screen_smartLabel, 100, 40);
    Start_Screen_smartLabel->fn->setScheme(Start_Screen_smartLabel, &BlueScheme);
    Start_Screen_smartLabel->fn->setBackgroundType(Start_Screen_smartLabel, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_smartLabel->fn->setHAlignment(Start_Screen_smartLabel, LE_HALIGN_RIGHT);
    Start_Screen_smartLabel->fn->setVAlignment(Start_Screen_smartLabel, LE_VALIGN_TOP);
    Start_Screen_smartLabel->fn->setString(Start_Screen_smartLabel, (leString*)&string_Smart);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_smartLabel);

    Start_Screen_StartScreenLabel = leLabelWidget_New();
    Start_Screen_StartScreenLabel->fn->setPosition(Start_Screen_StartScreenLabel, 0, 0);
    Start_Screen_StartScreenLabel->fn->setSize(Start_Screen_StartScreenLabel, 480, 40);
    Start_Screen_StartScreenLabel->fn->setScheme(Start_Screen_StartScreenLabel, &TitleScheme);
    Start_Screen_StartScreenLabel->fn->setHAlignment(Start_Screen_StartScreenLabel, LE_HALIGN_CENTER);
    Start_Screen_StartScreenLabel->fn->setMargins(Start_Screen_StartScreenLabel, 0, 0, 0, 0);
    Start_Screen_StartScreenLabel->fn->setString(Start_Screen_StartScreenLabel, (leString*)&string_Start_Screen_Text);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_StartScreenLabel);

    Start_Screen_TitleText = leLabelWidget_New();
    Start_Screen_TitleText->fn->setPosition(Start_Screen_TitleText, 0, 232);
    Start_Screen_TitleText->fn->setSize(Start_Screen_TitleText, 480, 40);
    Start_Screen_TitleText->fn->setScheme(Start_Screen_TitleText, &TitleScheme);
    Start_Screen_TitleText->fn->setHAlignment(Start_Screen_TitleText, LE_HALIGN_CENTER);
    Start_Screen_TitleText->fn->setString(Start_Screen_TitleText, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)Start_Screen_TitleText);

    Start_Screen_FullScreenButton = leButtonWidget_New();
    Start_Screen_FullScreenButton->fn->setPosition(Start_Screen_FullScreenButton, 0, 0);
    Start_Screen_FullScreenButton->fn->setSize(Start_Screen_FullScreenButton, 480, 272);
    Start_Screen_FullScreenButton->fn->setVisible(Start_Screen_FullScreenButton, LE_FALSE);
    Start_Screen_FullScreenButton->fn->setScheme(Start_Screen_FullScreenButton, &WhiteScheme);
    Start_Screen_FullScreenButton->fn->setBackgroundType(Start_Screen_FullScreenButton, LE_WIDGET_BACKGROUND_NONE);
    Start_Screen_FullScreenButton->fn->setBorderType(Start_Screen_FullScreenButton, LE_WIDGET_BORDER_NONE);
    Start_Screen_FullScreenButton->fn->setMargins(Start_Screen_FullScreenButton, 0, 0, 0, 0);
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
    Start_Screen_HarmonyLogo = NULL;
    Start_Screen_MicrochipLogo = NULL;
    Start_Screen_fastLabel = NULL;
    Start_Screen_easyLabel = NULL;
    Start_Screen_smartLabel = NULL;
    Start_Screen_StartScreenLabel = NULL;
    Start_Screen_TitleText = NULL;
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

