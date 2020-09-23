#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* default_GradientWidget0;
leImageWidget* default_WatermarkImage;
leImageWidget* default_LogoImage;
leLabelWidget* default_TitleLabel;
leWidget* default_SelectMediumPanel;
leWidget* default_InfoPanel;
leLabelWidget* default_SelectMediumLabel;
leButtonWidget* default_SDCardButton;
leButtonWidget* default_USBButton;
leWidget* default_ErrorMsgPanel;
leLabelWidget* default_LabelWidget3;
leLabelWidget* default_NoMediumLabel2;
leLabelWidget* default_NoMediumLabel1;
leLabelWidget* default_InfoLabel1;
leLabelWidget* default_InfoLabel2;
leButtonWidget* default_InfoOKButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    default_GradientWidget0 = leGradientWidget_New();
    default_GradientWidget0->fn->setPosition(default_GradientWidget0, 0, 0);
    default_GradientWidget0->fn->setSize(default_GradientWidget0, 480, 320);
    default_GradientWidget0->fn->setEnabled(default_GradientWidget0, LE_FALSE);
    default_GradientWidget0->fn->setScheme(default_GradientWidget0, &gradientScheme);
    default_GradientWidget0->fn->setDirection(default_GradientWidget0, LE_DIRECTION_UP);
    root0->fn->addChild(root0, (leWidget*)default_GradientWidget0);

    default_WatermarkImage = leImageWidget_New();
    default_WatermarkImage->fn->setPosition(default_WatermarkImage, 170, 106);
    default_WatermarkImage->fn->setSize(default_WatermarkImage, 141, 132);
    default_WatermarkImage->fn->setBackgroundType(default_WatermarkImage, LE_WIDGET_BACKGROUND_NONE);
    default_WatermarkImage->fn->setBorderType(default_WatermarkImage, LE_WIDGET_BORDER_NONE);
    default_WatermarkImage->fn->setImage(default_WatermarkImage, (leImage*)&mhc_3_logo);
    root0->fn->addChild(root0, (leWidget*)default_WatermarkImage);

    default_LogoImage = leImageWidget_New();
    default_LogoImage->fn->setPosition(default_LogoImage, 11, 11);
    default_LogoImage->fn->setSize(default_LogoImage, 32, 32);
    default_LogoImage->fn->setBackgroundType(default_LogoImage, LE_WIDGET_BACKGROUND_NONE);
    default_LogoImage->fn->setBorderType(default_LogoImage, LE_WIDGET_BORDER_NONE);
    default_LogoImage->fn->setImage(default_LogoImage, (leImage*)&mchpLogo);
    root0->fn->addChild(root0, (leWidget*)default_LogoImage);

    default_TitleLabel = leLabelWidget_New();
    default_TitleLabel->fn->setPosition(default_TitleLabel, 64, 14);
    default_TitleLabel->fn->setSize(default_TitleLabel, 398, 32);
    default_TitleLabel->fn->setScheme(default_TitleLabel, &whiteScheme);
    default_TitleLabel->fn->setBackgroundType(default_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    default_TitleLabel->fn->setHAlignment(default_TitleLabel, LE_HALIGN_CENTER);
    default_TitleLabel->fn->setString(default_TitleLabel, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)default_TitleLabel);

    default_SelectMediumPanel = leWidget_New();
    default_SelectMediumPanel->fn->setPosition(default_SelectMediumPanel, 0, 60);
    default_SelectMediumPanel->fn->setSize(default_SelectMediumPanel, 480, 260);
    default_SelectMediumPanel->fn->setBackgroundType(default_SelectMediumPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_SelectMediumPanel);

    default_SelectMediumLabel = leLabelWidget_New();
    default_SelectMediumLabel->fn->setPosition(default_SelectMediumLabel, 76, 0);
    default_SelectMediumLabel->fn->setSize(default_SelectMediumLabel, 333, 25);
    default_SelectMediumLabel->fn->setVisible(default_SelectMediumLabel, LE_FALSE);
    default_SelectMediumLabel->fn->setScheme(default_SelectMediumLabel, &whiteScheme);
    default_SelectMediumLabel->fn->setBackgroundType(default_SelectMediumLabel, LE_WIDGET_BACKGROUND_NONE);
    default_SelectMediumLabel->fn->setHAlignment(default_SelectMediumLabel, LE_HALIGN_CENTER);
    default_SelectMediumLabel->fn->setString(default_SelectMediumLabel, (leString*)&string_SelectSource);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SelectMediumLabel);

    default_SDCardButton = leButtonWidget_New();
    default_SDCardButton->fn->setPosition(default_SDCardButton, 58, 65);
    default_SDCardButton->fn->setSize(default_SDCardButton, 100, 100);
    default_SDCardButton->fn->setVisible(default_SDCardButton, LE_FALSE);
    default_SDCardButton->fn->setScheme(default_SDCardButton, &defaultScheme);
    default_SDCardButton->fn->setString(default_SDCardButton, (leString*)&string_SDCard);
    default_SDCardButton->fn->setPressedImage(default_SDCardButton, (leImage*)&sdcard1_0);
    default_SDCardButton->fn->setReleasedImage(default_SDCardButton, (leImage*)&sdcard1_0);
    default_SDCardButton->fn->setImagePosition(default_SDCardButton, LE_RELATIVE_POSITION_ABOVE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SDCardButton);

    default_USBButton = leButtonWidget_New();
    default_USBButton->fn->setPosition(default_USBButton, 319, 62);
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
    default_NoMediumLabel1->fn->setPosition(default_NoMediumLabel1, 92, 0);
    default_NoMediumLabel1->fn->setSize(default_NoMediumLabel1, 277, 25);
    default_NoMediumLabel1->fn->setVisible(default_NoMediumLabel1, LE_FALSE);
    default_NoMediumLabel1->fn->setScheme(default_NoMediumLabel1, &whiteScheme);
    default_NoMediumLabel1->fn->setBackgroundType(default_NoMediumLabel1, LE_WIDGET_BACKGROUND_NONE);
    default_NoMediumLabel1->fn->setHAlignment(default_NoMediumLabel1, LE_HALIGN_CENTER);
    default_NoMediumLabel1->fn->setString(default_NoMediumLabel1, (leString*)&string_NoValidMedium);
    default_ErrorMsgPanel->fn->addChild(default_ErrorMsgPanel, (leWidget*)default_NoMediumLabel1);

    default_LabelWidget3 = leLabelWidget_New();
    default_LabelWidget3->fn->setPosition(default_LabelWidget3, 126, 187);
    default_LabelWidget3->fn->setSize(default_LabelWidget3, 227, 32);
    default_LabelWidget3->fn->setScheme(default_LabelWidget3, &whiteScheme);
    default_LabelWidget3->fn->setBackgroundType(default_LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    default_LabelWidget3->fn->setHAlignment(default_LabelWidget3, LE_HALIGN_CENTER);
    default_LabelWidget3->fn->setString(default_LabelWidget3, (leString*)&string_Initializing);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_LabelWidget3);

    default_InfoPanel = leWidget_New();
    default_InfoPanel->fn->setPosition(default_InfoPanel, 0, 60);
    default_InfoPanel->fn->setSize(default_InfoPanel, 480, 260);
    default_InfoPanel->fn->setVisible(default_InfoPanel, LE_FALSE);
    default_InfoPanel->fn->setBackgroundType(default_InfoPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_InfoPanel);

    default_InfoLabel1 = leLabelWidget_New();
    default_InfoLabel1->fn->setPosition(default_InfoLabel1, 14, 4);
    default_InfoLabel1->fn->setSize(default_InfoLabel1, 448, 33);
    default_InfoLabel1->fn->setScheme(default_InfoLabel1, &whiteScheme);
    default_InfoLabel1->fn->setBackgroundType(default_InfoLabel1, LE_WIDGET_BACKGROUND_NONE);
    default_InfoLabel1->fn->setHAlignment(default_InfoLabel1, LE_HALIGN_CENTER);
    default_InfoLabel1->fn->setString(default_InfoLabel1, (leString*)&string_Title);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoLabel1);

    default_InfoLabel2 = leLabelWidget_New();
    default_InfoLabel2->fn->setPosition(default_InfoLabel2, 72, 29);
    default_InfoLabel2->fn->setSize(default_InfoLabel2, 336, 29);
    default_InfoLabel2->fn->setScheme(default_InfoLabel2, &whiteScheme);
    default_InfoLabel2->fn->setBackgroundType(default_InfoLabel2, LE_WIDGET_BACKGROUND_NONE);
    default_InfoLabel2->fn->setHAlignment(default_InfoLabel2, LE_HALIGN_CENTER);
    default_InfoLabel2->fn->setString(default_InfoLabel2, (leString*)&string_FileNotFound2);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoLabel2);

    default_InfoOKButton = leButtonWidget_New();
    default_InfoOKButton->fn->setPosition(default_InfoOKButton, 177, 189);
    default_InfoOKButton->fn->setSize(default_InfoOKButton, 120, 44);
    default_InfoOKButton->fn->setScheme(default_InfoOKButton, &defaultScheme);
    default_InfoOKButton->fn->setString(default_InfoOKButton, (leString*)&string_Ok);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoOKButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    default_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_default()
{
}

void screenHide_default()
{
    default_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    default_GradientWidget0 = NULL;
    default_WatermarkImage = NULL;
    default_LogoImage = NULL;
    default_TitleLabel = NULL;
    default_SelectMediumPanel = NULL;
    default_InfoPanel = NULL;
    default_SelectMediumLabel = NULL;
    default_SDCardButton = NULL;
    default_USBButton = NULL;
    default_ErrorMsgPanel = NULL;
    default_LabelWidget3 = NULL;
    default_NoMediumLabel2 = NULL;
    default_NoMediumLabel1 = NULL;
    default_InfoLabel1 = NULL;
    default_InfoLabel2 = NULL;
    default_InfoOKButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_default()
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

