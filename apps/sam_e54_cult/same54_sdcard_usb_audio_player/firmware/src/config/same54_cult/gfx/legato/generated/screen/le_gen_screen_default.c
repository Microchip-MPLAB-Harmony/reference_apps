#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget0;
leImageWidget* WatermarkImage;
leImageWidget* LogoImage;
leLabelWidget* TitleLabel;
leWidget* SelectMediumPanel;
leLabelWidget* SelectMediumLabel;
leButtonWidget* SDCardButton;
leButtonWidget* USBButton;
leWidget* ErrorMsgPanel;
leLabelWidget* NoMediumLabel2;
leLabelWidget* NoMediumLabel1;
leLabelWidget* LabelWidget3;
leWidget* InfoPanel;
leLabelWidget* InfoLabel1;
leLabelWidget* InfoLabel2;
leButtonWidget* InfoOKButton;

// string list for this screen
static leTableString tableString_Title;
static leTableString tableString_SelectSource;
static leTableString tableString_SDCard;
static leTableString tableString_USB;
static leTableString tableString_NoValidMedium2;
static leTableString tableString_NoValidMedium;
static leTableString tableString_Initializing;
static leTableString tableString_FileNotFound2;
static leTableString tableString_Ok;

static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Title, string_Title);
    leTableString_Constructor(&tableString_SelectSource, string_SelectSource);
    leTableString_Constructor(&tableString_SDCard, string_SDCard);
    leTableString_Constructor(&tableString_USB, string_USB);
    leTableString_Constructor(&tableString_NoValidMedium2, string_NoValidMedium2);
    leTableString_Constructor(&tableString_NoValidMedium, string_NoValidMedium);
    leTableString_Constructor(&tableString_Initializing, string_Initializing);
    leTableString_Constructor(&tableString_FileNotFound2, string_FileNotFound2);
    leTableString_Constructor(&tableString_Ok, string_Ok);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget0 = leGradientWidget_New();
    GradientWidget0->fn->setPosition(GradientWidget0, 0, 0);
    GradientWidget0->fn->setSize(GradientWidget0, 480, 320);
    GradientWidget0->fn->setEnabled(GradientWidget0, LE_FALSE);
    GradientWidget0->fn->setScheme(GradientWidget0, &gradientScheme);
    GradientWidget0->fn->setDirection(GradientWidget0, LE_DIRECTION_UP);
    root0->fn->addChild(root0, (leWidget*)GradientWidget0);

    WatermarkImage = leImageWidget_New();
    WatermarkImage->fn->setPosition(WatermarkImage, 170, 106);
    WatermarkImage->fn->setSize(WatermarkImage, 141, 132);
    WatermarkImage->fn->setBackgroundType(WatermarkImage, LE_WIDGET_BACKGROUND_NONE);
    WatermarkImage->fn->setImage(WatermarkImage, &mplabharmonylogo);
    root0->fn->addChild(root0, (leWidget*)WatermarkImage);

    LogoImage = leImageWidget_New();
    LogoImage->fn->setPosition(LogoImage, 11, 11);
    LogoImage->fn->setSize(LogoImage, 32, 32);
    LogoImage->fn->setBackgroundType(LogoImage, LE_WIDGET_BACKGROUND_NONE);
    LogoImage->fn->setImage(LogoImage, &mchpLogo);
    root0->fn->addChild(root0, (leWidget*)LogoImage);

    TitleLabel = leLabelWidget_New();
    TitleLabel->fn->setPosition(TitleLabel, 64, 14);
    TitleLabel->fn->setSize(TitleLabel, 398, 32);
    TitleLabel->fn->setScheme(TitleLabel, &whiteScheme);
    TitleLabel->fn->setBackgroundType(TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    TitleLabel->fn->setHAlignment(TitleLabel, LE_HALIGN_CENTER);
    TitleLabel->fn->setString(TitleLabel, (leString*)&tableString_Title);
    root0->fn->addChild(root0, (leWidget*)TitleLabel);

    SelectMediumPanel = leWidget_New();
    SelectMediumPanel->fn->setPosition(SelectMediumPanel, 0, 60);
    SelectMediumPanel->fn->setSize(SelectMediumPanel, 480, 260);
    SelectMediumPanel->fn->setBackgroundType(SelectMediumPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, SelectMediumPanel);

    SelectMediumLabel = leLabelWidget_New();
    SelectMediumLabel->fn->setPosition(SelectMediumLabel, 76, 0);
    SelectMediumLabel->fn->setSize(SelectMediumLabel, 333, 25);
    SelectMediumLabel->fn->setVisible(SelectMediumLabel, LE_FALSE);
    SelectMediumLabel->fn->setScheme(SelectMediumLabel, &whiteScheme);
    SelectMediumLabel->fn->setBackgroundType(SelectMediumLabel, LE_WIDGET_BACKGROUND_NONE);
    SelectMediumLabel->fn->setHAlignment(SelectMediumLabel, LE_HALIGN_CENTER);
    SelectMediumLabel->fn->setString(SelectMediumLabel, (leString*)&tableString_SelectSource);
    SelectMediumPanel->fn->addChild(SelectMediumPanel, (leWidget*)SelectMediumLabel);

    SDCardButton = leButtonWidget_New();
    SDCardButton->fn->setPosition(SDCardButton, 58, 65);
    SDCardButton->fn->setSize(SDCardButton, 100, 100);
    SDCardButton->fn->setVisible(SDCardButton, LE_FALSE);
    SDCardButton->fn->setScheme(SDCardButton, &defaultScheme);
    SDCardButton->fn->setString(SDCardButton, (leString*)&tableString_SDCard);
    SDCardButton->fn->setPressedImage(SDCardButton, &sdcard1);
    SDCardButton->fn->setReleasedImage(SDCardButton, &sdcard1);
    SDCardButton->fn->setImagePosition(SDCardButton, LE_RELATIVE_POSITION_ABOVE);
    SelectMediumPanel->fn->addChild(SelectMediumPanel, (leWidget*)SDCardButton);

    USBButton = leButtonWidget_New();
    USBButton->fn->setPosition(USBButton, 319, 62);
    USBButton->fn->setSize(USBButton, 100, 100);
    USBButton->fn->setAlphaEnabled(USBButton, LE_TRUE);
    USBButton->fn->setVisible(USBButton, LE_FALSE);
    USBButton->fn->setScheme(USBButton, &defaultScheme);
    USBButton->fn->setString(USBButton, (leString*)&tableString_USB);
    USBButton->fn->setPressedImage(USBButton, &usbicon);
    USBButton->fn->setReleasedImage(USBButton, &usbicon);
    USBButton->fn->setImagePosition(USBButton, LE_RELATIVE_POSITION_ABOVE);
    SelectMediumPanel->fn->addChild(SelectMediumPanel, (leWidget*)USBButton);

    ErrorMsgPanel = leWidget_New();
    ErrorMsgPanel->fn->setPosition(ErrorMsgPanel, 10, 189);
    ErrorMsgPanel->fn->setSize(ErrorMsgPanel, 458, 57);
    ErrorMsgPanel->fn->setScheme(ErrorMsgPanel, &whiteScheme);
    ErrorMsgPanel->fn->setBackgroundType(ErrorMsgPanel, LE_WIDGET_BACKGROUND_NONE);
    SelectMediumPanel->fn->addChild(SelectMediumPanel, ErrorMsgPanel);

    NoMediumLabel2 = leLabelWidget_New();
    NoMediumLabel2->fn->setPosition(NoMediumLabel2, -2, 28);
    NoMediumLabel2->fn->setSize(NoMediumLabel2, 466, 25);
    NoMediumLabel2->fn->setVisible(NoMediumLabel2, LE_FALSE);
    NoMediumLabel2->fn->setScheme(NoMediumLabel2, &whiteScheme);
    NoMediumLabel2->fn->setBackgroundType(NoMediumLabel2, LE_WIDGET_BACKGROUND_NONE);
    NoMediumLabel2->fn->setHAlignment(NoMediumLabel2, LE_HALIGN_CENTER);
    NoMediumLabel2->fn->setString(NoMediumLabel2, (leString*)&tableString_NoValidMedium2);
    ErrorMsgPanel->fn->addChild(ErrorMsgPanel, (leWidget*)NoMediumLabel2);

    NoMediumLabel1 = leLabelWidget_New();
    NoMediumLabel1->fn->setPosition(NoMediumLabel1, 92, 0);
    NoMediumLabel1->fn->setSize(NoMediumLabel1, 277, 25);
    NoMediumLabel1->fn->setVisible(NoMediumLabel1, LE_FALSE);
    NoMediumLabel1->fn->setScheme(NoMediumLabel1, &whiteScheme);
    NoMediumLabel1->fn->setBackgroundType(NoMediumLabel1, LE_WIDGET_BACKGROUND_NONE);
    NoMediumLabel1->fn->setHAlignment(NoMediumLabel1, LE_HALIGN_CENTER);
    NoMediumLabel1->fn->setString(NoMediumLabel1, (leString*)&tableString_NoValidMedium);
    ErrorMsgPanel->fn->addChild(ErrorMsgPanel, (leWidget*)NoMediumLabel1);

    LabelWidget3 = leLabelWidget_New();
    LabelWidget3->fn->setPosition(LabelWidget3, 126, 187);
    LabelWidget3->fn->setSize(LabelWidget3, 227, 32);
    LabelWidget3->fn->setScheme(LabelWidget3, &whiteScheme);
    LabelWidget3->fn->setBackgroundType(LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget3->fn->setHAlignment(LabelWidget3, LE_HALIGN_CENTER);
    LabelWidget3->fn->setString(LabelWidget3, (leString*)&tableString_Initializing);
    SelectMediumPanel->fn->addChild(SelectMediumPanel, (leWidget*)LabelWidget3);

    InfoPanel = leWidget_New();
    InfoPanel->fn->setPosition(InfoPanel, 0, 60);
    InfoPanel->fn->setSize(InfoPanel, 480, 260);
    InfoPanel->fn->setVisible(InfoPanel, LE_FALSE);
    InfoPanel->fn->setBackgroundType(InfoPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, InfoPanel);

    InfoLabel1 = leLabelWidget_New();
    InfoLabel1->fn->setPosition(InfoLabel1, 14, 4);
    InfoLabel1->fn->setSize(InfoLabel1, 448, 33);
    InfoLabel1->fn->setScheme(InfoLabel1, &whiteScheme);
    InfoLabel1->fn->setBackgroundType(InfoLabel1, LE_WIDGET_BACKGROUND_NONE);
    InfoLabel1->fn->setHAlignment(InfoLabel1, LE_HALIGN_CENTER);
    InfoLabel1->fn->setString(InfoLabel1, (leString*)&tableString_Title);
    InfoPanel->fn->addChild(InfoPanel, (leWidget*)InfoLabel1);

    InfoLabel2 = leLabelWidget_New();
    InfoLabel2->fn->setPosition(InfoLabel2, 72, 29);
    InfoLabel2->fn->setSize(InfoLabel2, 336, 29);
    InfoLabel2->fn->setScheme(InfoLabel2, &whiteScheme);
    InfoLabel2->fn->setBackgroundType(InfoLabel2, LE_WIDGET_BACKGROUND_NONE);
    InfoLabel2->fn->setHAlignment(InfoLabel2, LE_HALIGN_CENTER);
    InfoLabel2->fn->setString(InfoLabel2, (leString*)&tableString_FileNotFound2);
    InfoPanel->fn->addChild(InfoPanel, (leWidget*)InfoLabel2);

    InfoOKButton = leButtonWidget_New();
    InfoOKButton->fn->setPosition(InfoOKButton, 177, 189);
    InfoOKButton->fn->setSize(InfoOKButton, 120, 44);
    InfoOKButton->fn->setScheme(InfoOKButton, &defaultScheme);
    InfoOKButton->fn->setString(InfoOKButton, (leString*)&tableString_Ok);
    InfoPanel->fn->addChild(InfoPanel, (leWidget*)InfoOKButton);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    default_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_default()
{
    default_OnUpdate();
}

void screenHide_default()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget0 = NULL;
    WatermarkImage = NULL;
    LogoImage = NULL;
    TitleLabel = NULL;
    SelectMediumPanel = NULL;
    SelectMediumLabel = NULL;
    SDCardButton = NULL;
    USBButton = NULL;
    ErrorMsgPanel = NULL;
    NoMediumLabel2 = NULL;
    NoMediumLabel1 = NULL;
    LabelWidget3 = NULL;
    InfoPanel = NULL;
    InfoLabel1 = NULL;
    InfoLabel2 = NULL;
    InfoOKButton = NULL;

    tableString_Title.fn->destructor(&tableString_Title);
    tableString_SelectSource.fn->destructor(&tableString_SelectSource);
    tableString_SDCard.fn->destructor(&tableString_SDCard);
    tableString_USB.fn->destructor(&tableString_USB);
    tableString_NoValidMedium2.fn->destructor(&tableString_NoValidMedium2);
    tableString_NoValidMedium.fn->destructor(&tableString_NoValidMedium);
    tableString_Initializing.fn->destructor(&tableString_Initializing);
    tableString_FileNotFound2.fn->destructor(&tableString_FileNotFound2);
    tableString_Ok.fn->destructor(&tableString_Ok);
    showing = LE_FALSE;

    default_OnHide();
}

void screenDestroy_default()
{

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

