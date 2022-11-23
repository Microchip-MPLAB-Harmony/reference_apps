#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// screen member widget declarations
static leWidget* root0;

leWidget* default_PanelWidget0;
leImageWidget* default_WatermarkImage;
leImageWidget* default_LogoImage;
leLabelWidget* default_TitleLabel;
leWidget* default_SelectMediumPanel;
leLabelWidget* default_InsertSDcardLabel;
leImageWidget* default_USB_MSD_Icon;
leLabelWidget* default_SelectMediumLabel;
leButtonWidget* default_SDCardButton;
leButtonWidget* default_USBButton;
leWidget* default_ErrorMsgPanel;
leLabelWidget* default_InitializationText;
leLabelWidget* default_NoMediumLabel2;
leLabelWidget* default_NoMediumLabel1;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_default(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_default(void)
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

    default_PanelWidget0 = leWidget_New();
    default_PanelWidget0->fn->setPosition(default_PanelWidget0, 0, 0);
    default_PanelWidget0->fn->setSize(default_PanelWidget0, 480, 272);
    default_PanelWidget0->fn->setScheme(default_PanelWidget0, &BackgroundStartScreen);
    root0->fn->addChild(root0, (leWidget*)default_PanelWidget0);

    default_WatermarkImage = leImageWidget_New();
    default_WatermarkImage->fn->setPosition(default_WatermarkImage, 131, 71);
    default_WatermarkImage->fn->setSize(default_WatermarkImage, 210, 129);
    default_WatermarkImage->fn->setBackgroundType(default_WatermarkImage, LE_WIDGET_BACKGROUND_NONE);
    default_WatermarkImage->fn->setBorderType(default_WatermarkImage, LE_WIDGET_BORDER_NONE);
    default_WatermarkImage->fn->setImage(default_WatermarkImage, (leImage*)&HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)default_WatermarkImage);

    default_LogoImage = leImageWidget_New();
    default_LogoImage->fn->setPosition(default_LogoImage, 0, 0);
    default_LogoImage->fn->setSize(default_LogoImage, 140, 34);
    default_LogoImage->fn->setBackgroundType(default_LogoImage, LE_WIDGET_BACKGROUND_NONE);
    default_LogoImage->fn->setBorderType(default_LogoImage, LE_WIDGET_BORDER_NONE);
    default_LogoImage->fn->setImage(default_LogoImage, (leImage*)&MicrochipLogo_120x27);
    root0->fn->addChild(root0, (leWidget*)default_LogoImage);

    default_TitleLabel = leLabelWidget_New();
    default_TitleLabel->fn->setPosition(default_TitleLabel, 64, 36);
    default_TitleLabel->fn->setSize(default_TitleLabel, 398, 32);
    default_TitleLabel->fn->setScheme(default_TitleLabel, &grayScheme);
    default_TitleLabel->fn->setBackgroundType(default_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    default_TitleLabel->fn->setHAlignment(default_TitleLabel, LE_HALIGN_CENTER);
    default_TitleLabel->fn->setString(default_TitleLabel, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)default_TitleLabel);

    default_SelectMediumPanel = leWidget_New();
    default_SelectMediumPanel->fn->setPosition(default_SelectMediumPanel, 1, 1);
    default_SelectMediumPanel->fn->setSize(default_SelectMediumPanel, 480, 272);
    default_SelectMediumPanel->fn->setBackgroundType(default_SelectMediumPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_SelectMediumPanel);

    default_SelectMediumLabel = leLabelWidget_New();
    default_SelectMediumLabel->fn->setPosition(default_SelectMediumLabel, 67, 75);
    default_SelectMediumLabel->fn->setSize(default_SelectMediumLabel, 333, 25);
    default_SelectMediumLabel->fn->setVisible(default_SelectMediumLabel, LE_FALSE);
    default_SelectMediumLabel->fn->setScheme(default_SelectMediumLabel, &whiteScheme);
    default_SelectMediumLabel->fn->setBackgroundType(default_SelectMediumLabel, LE_WIDGET_BACKGROUND_NONE);
    default_SelectMediumLabel->fn->setHAlignment(default_SelectMediumLabel, LE_HALIGN_CENTER);
    default_SelectMediumLabel->fn->setString(default_SelectMediumLabel, (leString*)&string_SelectSource);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SelectMediumLabel);

    default_SDCardButton = leButtonWidget_New();
    default_SDCardButton->fn->setPosition(default_SDCardButton, 30, 86);
    default_SDCardButton->fn->setSize(default_SDCardButton, 100, 100);
    default_SDCardButton->fn->setVisible(default_SDCardButton, LE_FALSE);
    default_SDCardButton->fn->setScheme(default_SDCardButton, &defaultScheme);
    default_SDCardButton->fn->setString(default_SDCardButton, (leString*)&string_SDCard);
    default_SDCardButton->fn->setImagePosition(default_SDCardButton, LE_RELATIVE_POSITION_ABOVE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SDCardButton);

    default_USBButton = leButtonWidget_New();
    default_USBButton->fn->setPosition(default_USBButton, 352, 88);
    default_USBButton->fn->setSize(default_USBButton, 100, 100);
    default_USBButton->fn->setAlphaEnabled(default_USBButton, LE_TRUE);
    default_USBButton->fn->setVisible(default_USBButton, LE_FALSE);
    default_USBButton->fn->setScheme(default_USBButton, &defaultScheme);
    default_USBButton->fn->setString(default_USBButton, (leString*)&string_USB);
    default_USBButton->fn->setPressedImage(default_USBButton, (leImage*)&usbicon);
    default_USBButton->fn->setReleasedImage(default_USBButton, (leImage*)&usbicon);
    default_USBButton->fn->setImagePosition(default_USBButton, LE_RELATIVE_POSITION_ABOVE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_USBButton);

    default_ErrorMsgPanel = leWidget_New();
    default_ErrorMsgPanel->fn->setPosition(default_ErrorMsgPanel, 10, 189);
    default_ErrorMsgPanel->fn->setSize(default_ErrorMsgPanel, 458, 57);
    default_ErrorMsgPanel->fn->setScheme(default_ErrorMsgPanel, &whiteScheme);
    default_ErrorMsgPanel->fn->setBackgroundType(default_ErrorMsgPanel, LE_WIDGET_BACKGROUND_NONE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_ErrorMsgPanel);

    default_NoMediumLabel2 = leLabelWidget_New();
    default_NoMediumLabel2->fn->setPosition(default_NoMediumLabel2, -2, 28);
    default_NoMediumLabel2->fn->setSize(default_NoMediumLabel2, 466, 25);
    default_NoMediumLabel2->fn->setVisible(default_NoMediumLabel2, LE_FALSE);
    default_NoMediumLabel2->fn->setScheme(default_NoMediumLabel2, &whiteScheme);
    default_NoMediumLabel2->fn->setBackgroundType(default_NoMediumLabel2, LE_WIDGET_BACKGROUND_NONE);
    default_NoMediumLabel2->fn->setHAlignment(default_NoMediumLabel2, LE_HALIGN_CENTER);
    default_NoMediumLabel2->fn->setString(default_NoMediumLabel2, (leString*)&string_NoValidMedium2);
    default_ErrorMsgPanel->fn->addChild(default_ErrorMsgPanel, (leWidget*)default_NoMediumLabel2);

    default_NoMediumLabel1 = leLabelWidget_New();
    default_NoMediumLabel1->fn->setPosition(default_NoMediumLabel1, 91, 4);
    default_NoMediumLabel1->fn->setSize(default_NoMediumLabel1, 277, 25);
    default_NoMediumLabel1->fn->setVisible(default_NoMediumLabel1, LE_FALSE);
    default_NoMediumLabel1->fn->setScheme(default_NoMediumLabel1, &whiteScheme);
    default_NoMediumLabel1->fn->setBackgroundType(default_NoMediumLabel1, LE_WIDGET_BACKGROUND_NONE);
    default_NoMediumLabel1->fn->setHAlignment(default_NoMediumLabel1, LE_HALIGN_CENTER);
    default_NoMediumLabel1->fn->setString(default_NoMediumLabel1, (leString*)&string_NoValidMedium);
    default_ErrorMsgPanel->fn->addChild(default_ErrorMsgPanel, (leWidget*)default_NoMediumLabel1);

    default_InitializationText = leLabelWidget_New();
    default_InitializationText->fn->setPosition(default_InitializationText, 126, 202);
    default_InitializationText->fn->setSize(default_InitializationText, 227, 32);
    default_InitializationText->fn->setVisible(default_InitializationText, LE_FALSE);
    default_InitializationText->fn->setScheme(default_InitializationText, &grayScheme);
    default_InitializationText->fn->setBackgroundType(default_InitializationText, LE_WIDGET_BACKGROUND_NONE);
    default_InitializationText->fn->setHAlignment(default_InitializationText, LE_HALIGN_CENTER);
    default_InitializationText->fn->setString(default_InitializationText, (leString*)&string_Initializing);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_InitializationText);

    default_InsertSDcardLabel = leLabelWidget_New();
    default_InsertSDcardLabel->fn->setPosition(default_InsertSDcardLabel, 126, 202);
    default_InsertSDcardLabel->fn->setSize(default_InsertSDcardLabel, 227, 32);
    default_InsertSDcardLabel->fn->setScheme(default_InsertSDcardLabel, &grayScheme);
    default_InsertSDcardLabel->fn->setBackgroundType(default_InsertSDcardLabel, LE_WIDGET_BACKGROUND_NONE);
    default_InsertSDcardLabel->fn->setHAlignment(default_InsertSDcardLabel, LE_HALIGN_CENTER);
    default_InsertSDcardLabel->fn->setString(default_InsertSDcardLabel, (leString*)&string_InsertSDcardString);
    root0->fn->addChild(root0, (leWidget*)default_InsertSDcardLabel);

    default_USB_MSD_Icon = leImageWidget_New();
    default_USB_MSD_Icon->fn->setPosition(default_USB_MSD_Icon, 136, 6);
    default_USB_MSD_Icon->fn->setSize(default_USB_MSD_Icon, 50, 25);
    default_USB_MSD_Icon->fn->setVisible(default_USB_MSD_Icon, LE_FALSE);
    default_USB_MSD_Icon->fn->setBorderType(default_USB_MSD_Icon, LE_WIDGET_BORDER_NONE);
    default_USB_MSD_Icon->fn->setImage(default_USB_MSD_Icon, (leImage*)&usb_icon_50x25);
    root0->fn->addChild(root0, (leWidget*)default_USB_MSD_Icon);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    default_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_default(void)
{
    root0->fn->setSize(root0, root0->parent->rect.width, root0->parent->rect.height);

    default_OnUpdate(); // raise event
}

void screenHide_default(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    default_PanelWidget0 = NULL;
    default_WatermarkImage = NULL;
    default_LogoImage = NULL;
    default_TitleLabel = NULL;
    default_SelectMediumPanel = NULL;
    default_InsertSDcardLabel = NULL;
    default_USB_MSD_Icon = NULL;
    default_SelectMediumLabel = NULL;
    default_SDCardButton = NULL;
    default_USBButton = NULL;
    default_ErrorMsgPanel = NULL;
    default_InitializationText = NULL;
    default_NoMediumLabel2 = NULL;
    default_NoMediumLabel1 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_default(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_default(uint32_t lyrIdx)
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

