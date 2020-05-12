// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_init.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_utils.h"

laScheme GroupScheme;
laScheme RadioScheme;
laScheme LogoBarScheme;
laScheme TitleBoxScheme;
laScheme ScrollUpScheme;
laScheme VolumeButtonScheme;
laScheme BackgroundScheme;
laScheme TrackListScheme;
laGradientWidget* LogoBar;
laImageWidget* LogoImage;
laTextFieldWidget* AppNameText;
laTextFieldWidget* MessageTextBox;
laGroupBoxWidget* AppModeGroup;
laRadioButtonWidget* RadioButtonPlayer;
laRadioButtonWidget* RadioButtonReader;
laListWidget* TrackListBox;
laButtonWidget* ScrollUpButton;
laButtonWidget* ScrollDownButton;
laRectangleWidget* VolSliderBorder;
laSliderWidget* VolSlider;
laButtonWidget* VolButton;


static void ScreenCreate_MchpMainScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&GroupScheme, GFX_COLOR_MODE_RGB_565);
    GroupScheme.base = 0x0;
    GroupScheme.highlight = 0xC67A;
    GroupScheme.highlightLight = 0xA0A2;
    GroupScheme.shadow = 0xE800;
    GroupScheme.shadowDark = 0xE800;
    GroupScheme.foreground = 0x0;
    GroupScheme.foregroundInactive = 0xD71C;
    GroupScheme.foregroundDisabled = 0x8410;
    GroupScheme.background = 0x0;
    GroupScheme.backgroundInactive = 0xD71C;
    GroupScheme.backgroundDisabled = 0xC67A;
    GroupScheme.text = 0x86FD;
    GroupScheme.textHighlight = 0x1F;
    GroupScheme.textHighlightText = 0xFFFF;
    GroupScheme.textInactive = 0xD71C;
    GroupScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&RadioScheme, GFX_COLOR_MODE_RGB_565);
    RadioScheme.base = 0x0;
    RadioScheme.highlight = 0xFFFF;
    RadioScheme.highlightLight = 0xFFFF;
    RadioScheme.shadow = 0xFFFF;
    RadioScheme.shadowDark = 0xFFFF;
    RadioScheme.foreground = 0xE49B;
    RadioScheme.foregroundInactive = 0xD71C;
    RadioScheme.foregroundDisabled = 0x8410;
    RadioScheme.background = 0x0;
    RadioScheme.backgroundInactive = 0xD71C;
    RadioScheme.backgroundDisabled = 0xC67A;
    RadioScheme.text = 0xE49B;
    RadioScheme.textHighlight = 0x1F;
    RadioScheme.textHighlightText = 0xFFFF;
    RadioScheme.textInactive = 0xD71C;
    RadioScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&LogoBarScheme, GFX_COLOR_MODE_RGB_565);
    LogoBarScheme.base = 0xC67A;
    LogoBarScheme.highlight = 0xC67A;
    LogoBarScheme.highlightLight = 0x0;
    LogoBarScheme.shadow = 0x0;
    LogoBarScheme.shadowDark = 0x0;
    LogoBarScheme.foreground = 0xF800;
    LogoBarScheme.foregroundInactive = 0x0;
    LogoBarScheme.foregroundDisabled = 0x8410;
    LogoBarScheme.background = 0xFFFF;
    LogoBarScheme.backgroundInactive = 0xD71C;
    LogoBarScheme.backgroundDisabled = 0xC67A;
    LogoBarScheme.text = 0x0;
    LogoBarScheme.textHighlight = 0x1F;
    LogoBarScheme.textHighlightText = 0xFFFF;
    LogoBarScheme.textInactive = 0xD71C;
    LogoBarScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TitleBoxScheme, GFX_COLOR_MODE_RGB_565);
    TitleBoxScheme.base = 0xC67A;
    TitleBoxScheme.highlight = 0xC67A;
    TitleBoxScheme.highlightLight = 0x0;
    TitleBoxScheme.shadow = 0x0;
    TitleBoxScheme.shadowDark = 0x0;
    TitleBoxScheme.foreground = 0x0;
    TitleBoxScheme.foregroundInactive = 0xD71C;
    TitleBoxScheme.foregroundDisabled = 0x8410;
    TitleBoxScheme.background = 0x0;
    TitleBoxScheme.backgroundInactive = 0xD71C;
    TitleBoxScheme.backgroundDisabled = 0xC67A;
    TitleBoxScheme.text = 0xFFFF;
    TitleBoxScheme.textHighlight = 0x1F;
    TitleBoxScheme.textHighlightText = 0xFFFF;
    TitleBoxScheme.textInactive = 0xD71C;
    TitleBoxScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&ScrollUpScheme, GFX_COLOR_MODE_RGB_565);
    ScrollUpScheme.base = 0x0;
    ScrollUpScheme.highlight = 0xC67A;
    ScrollUpScheme.highlightLight = 0xA0A2;
    ScrollUpScheme.shadow = 0xE800;
    ScrollUpScheme.shadowDark = 0xE800;
    ScrollUpScheme.foreground = 0x0;
    ScrollUpScheme.foregroundInactive = 0xD71C;
    ScrollUpScheme.foregroundDisabled = 0x8410;
    ScrollUpScheme.background = 0xCBAF;
    ScrollUpScheme.backgroundInactive = 0xD71C;
    ScrollUpScheme.backgroundDisabled = 0xC67A;
    ScrollUpScheme.text = 0xAF92;
    ScrollUpScheme.textHighlight = 0x1F;
    ScrollUpScheme.textHighlightText = 0xFFFF;
    ScrollUpScheme.textInactive = 0xD71C;
    ScrollUpScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&VolumeButtonScheme, GFX_COLOR_MODE_RGB_565);
    VolumeButtonScheme.base = 0x0;
    VolumeButtonScheme.highlight = 0xC67A;
    VolumeButtonScheme.highlightLight = 0x0;
    VolumeButtonScheme.shadow = 0x0;
    VolumeButtonScheme.shadowDark = 0x0;
    VolumeButtonScheme.foreground = 0x0;
    VolumeButtonScheme.foregroundInactive = 0xD71C;
    VolumeButtonScheme.foregroundDisabled = 0x8410;
    VolumeButtonScheme.background = 0x0;
    VolumeButtonScheme.backgroundInactive = 0xD71C;
    VolumeButtonScheme.backgroundDisabled = 0xC67A;
    VolumeButtonScheme.text = 0x0;
    VolumeButtonScheme.textHighlight = 0x1F;
    VolumeButtonScheme.textHighlightText = 0xFFFF;
    VolumeButtonScheme.textInactive = 0xD71C;
    VolumeButtonScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&BackgroundScheme, GFX_COLOR_MODE_RGB_565);
    BackgroundScheme.base = 0xC67A;
    BackgroundScheme.highlight = 0xC67A;
    BackgroundScheme.highlightLight = 0xFFFF;
    BackgroundScheme.shadow = 0x8410;
    BackgroundScheme.shadowDark = 0x4208;
    BackgroundScheme.foreground = 0x0;
    BackgroundScheme.foregroundInactive = 0xD71C;
    BackgroundScheme.foregroundDisabled = 0x8410;
    BackgroundScheme.background = 0x0;
    BackgroundScheme.backgroundInactive = 0xD71C;
    BackgroundScheme.backgroundDisabled = 0xC67A;
    BackgroundScheme.text = 0x0;
    BackgroundScheme.textHighlight = 0x1F;
    BackgroundScheme.textHighlightText = 0xFFFF;
    BackgroundScheme.textInactive = 0xD71C;
    BackgroundScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TrackListScheme, GFX_COLOR_MODE_RGB_565);
    TrackListScheme.base = 0x0;
    TrackListScheme.highlight = 0xC67A;
    TrackListScheme.highlightLight = 0xA0A2;
    TrackListScheme.shadow = 0xE800;
    TrackListScheme.shadowDark = 0xE800;
    TrackListScheme.foreground = 0x0;
    TrackListScheme.foregroundInactive = 0xD71C;
    TrackListScheme.foregroundDisabled = 0x8410;
    TrackListScheme.background = 0x0;
    TrackListScheme.backgroundInactive = 0x4208;
    TrackListScheme.backgroundDisabled = 0xC67A;
    TrackListScheme.text = 0x9FB3;
    TrackListScheme.textHighlight = 0x4208;
    TrackListScheme.textHighlightText = 0x97DE;
    TrackListScheme.textInactive = 0xD71C;
    TrackListScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MchpMainScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_MchpMainScreen(laScreen* screen)
{
    laLayer* layer0;
    laRadioButtonGroup* radioButtonGroup_1;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &BackgroundScheme);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetMaskEnable(layer0, LA_TRUE);
    laLayer_SetMaskColor(layer0, 0x0);

    laScreen_SetLayer(screen, 0, layer0);

    LogoBar = laGradientWidget_New();
    laWidget_SetPosition((laWidget*)LogoBar, 0, 1);
    laWidget_SetSize((laWidget*)LogoBar, 480, 45);
    laWidget_SetScheme((laWidget*)LogoBar, &LogoBarScheme);
    laWidget_SetBackgroundType((laWidget*)LogoBar, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LogoBar, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)LogoBar, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LogoBar);

    LogoImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)LogoImage, 1, 2);
    laWidget_SetSize((laWidget*)LogoImage, 123, 32);
    laWidget_SetScheme((laWidget*)LogoImage, &LogoBarScheme);
    laWidget_SetBackgroundType((laWidget*)LogoImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LogoImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(LogoImage, &MCHP_LOGO);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LogoImage);

    AppNameText = laTextFieldWidget_New();
    laWidget_SetPosition((laWidget*)AppNameText, 34, 43);
    laWidget_SetSize((laWidget*)AppNameText, 260, 18);
    laWidget_SetScheme((laWidget*)AppNameText, &TitleBoxScheme);
    laWidget_SetBackgroundType((laWidget*)AppNameText, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)AppNameText, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)AppNameText, 0, 0, 0, 0);
    laTextFieldWidget_SetText(AppNameText, laString_CreateFromID(string_TitleString));
    laTextFieldWidget_SetCursorEnabled(AppNameText, LA_TRUE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)AppNameText);

    MessageTextBox = laTextFieldWidget_New();
    laWidget_SetPosition((laWidget*)MessageTextBox, 33, 239);
    laWidget_SetSize((laWidget*)MessageTextBox, 381, 28);
    laWidget_SetVisible((laWidget*)MessageTextBox, LA_FALSE);
    laWidget_SetScheme((laWidget*)MessageTextBox, &GroupScheme);
    laWidget_SetBackgroundType((laWidget*)MessageTextBox, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)MessageTextBox, LA_WIDGET_BORDER_NONE);
    laTextFieldWidget_SetText(MessageTextBox, laString_CreateFromID(string_NoFilesMessage));
    laTextFieldWidget_SetCursorEnabled(MessageTextBox, LA_TRUE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)MessageTextBox);

    AppModeGroup = laGroupBoxWidget_New();
    laWidget_SetPosition((laWidget*)AppModeGroup, 33, 62);
    laWidget_SetSize((laWidget*)AppModeGroup, 120, 170);
    laWidget_SetScheme((laWidget*)AppModeGroup, &GroupScheme);
    laWidget_SetBackgroundType((laWidget*)AppModeGroup, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)AppModeGroup, LA_WIDGET_BORDER_NONE);
    laGroupBoxWidget_SetText(AppModeGroup, laString_CreateFromID(string_GroupBoxTitle));
    laGroupBoxWidget_SetAlignment(AppModeGroup, LA_HALIGN_CENTER);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)AppModeGroup);

    RadioButtonPlayer = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonPlayer, 39, 105);
    laWidget_SetSize((laWidget*)RadioButtonPlayer, 108, 35);
    laWidget_SetScheme((laWidget*)RadioButtonPlayer, &RadioScheme);
    laWidget_SetBackgroundType((laWidget*)RadioButtonPlayer, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RadioButtonPlayer, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonPlayer, laString_CreateFromID(string_RadioButtonPlayer));
    laRadioButtonWidget_SetHAlignment(RadioButtonPlayer, LA_HALIGN_LEFT);
    laRadioButtonWidget_SetCircleButtonSize(RadioButtonPlayer, 30);
    laRadioButtonGroup_Create(&radioButtonGroup_1);
    laRadioButtonGroup_AddButton(radioButtonGroup_1, RadioButtonPlayer);
    laRadioButtonWidget_SetSelected(RadioButtonPlayer);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonPlayer, &RadioButtonPlayer_CheckedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)RadioButtonPlayer);

    RadioButtonReader = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonReader, 39, 167);
    laWidget_SetSize((laWidget*)RadioButtonReader, 108, 35);
    laWidget_SetScheme((laWidget*)RadioButtonReader, &RadioScheme);
    laWidget_SetBackgroundType((laWidget*)RadioButtonReader, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RadioButtonReader, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonReader, laString_CreateFromID(string_RadioButtonReader));
    laRadioButtonWidget_SetHAlignment(RadioButtonReader, LA_HALIGN_LEFT);
    laRadioButtonWidget_SetCircleButtonSize(RadioButtonReader, 30);
    laRadioButtonGroup_AddButton(radioButtonGroup_1, RadioButtonReader);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonReader, &RadioButtonReader_CheckedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)RadioButtonReader);

    TrackListBox = laListWidget_New();
    laWidget_SetPosition((laWidget*)TrackListBox, 173, 69);
    laWidget_SetSize((laWidget*)TrackListBox, 150, 162);
    laWidget_SetScheme((laWidget*)TrackListBox, &TrackListScheme);
    laWidget_SetBackgroundType((laWidget*)TrackListBox, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TrackListBox, LA_WIDGET_BORDER_BEVEL);
    laListWidget_SetSelectionMode(TrackListBox, LA_LIST_WIDGET_SELECTION_MODE_SINGLE);
    laListWidget_AppendItem(TrackListBox);
    laListWidget_SetSelectedItemChangedEventCallback(TrackListBox, &TrackListBox_SelectionChangedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TrackListBox);

    ScrollUpButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ScrollUpButton, 324, 69);
    laWidget_SetSize((laWidget*)ScrollUpButton, 38, 81);
    laWidget_SetScheme((laWidget*)ScrollUpButton, &ScrollUpScheme);
    laWidget_SetBackgroundType((laWidget*)ScrollUpButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ScrollUpButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ScrollUpButton, laString_CreateFromID(string_ScrollUp));
    laButtonWidget_SetReleasedEventCallback(ScrollUpButton, &ScrollUpButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ScrollUpButton);

    ScrollDownButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ScrollDownButton, 324, 150);
    laWidget_SetSize((laWidget*)ScrollDownButton, 38, 81);
    laWidget_SetScheme((laWidget*)ScrollDownButton, &ScrollUpScheme);
    laWidget_SetBackgroundType((laWidget*)ScrollDownButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ScrollDownButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ScrollDownButton, laString_CreateFromID(string_ScrollDown));
    laButtonWidget_SetReleasedEventCallback(ScrollDownButton, &ScrollDownButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ScrollDownButton);

    VolSliderBorder = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)VolSliderBorder, 412, 69);
    laWidget_SetSize((laWidget*)VolSliderBorder, 36, 138);
    laWidget_SetScheme((laWidget*)VolSliderBorder, &TrackListScheme);
    laWidget_SetBackgroundType((laWidget*)VolSliderBorder, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)VolSliderBorder, LA_WIDGET_BORDER_BEVEL);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)VolSliderBorder);

    VolSlider = laSliderWidget_New();
    laWidget_SetPosition((laWidget*)VolSlider, 416, 71);
    laWidget_SetSize((laWidget*)VolSlider, 28, 132);
    laWidget_SetScheme((laWidget*)VolSlider, &TrackListScheme);
    laWidget_SetBackgroundType((laWidget*)VolSlider, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)VolSlider, LA_WIDGET_BORDER_LINE);
    laSliderWidget_SetMaximumValue(VolSlider, 50);
    laSliderWidget_SetValueChangedEventCallback(VolSlider, &VolSlider_ValueChangedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)VolSlider);

    VolButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)VolButton, 401, 209);
    laWidget_SetSize((laWidget*)VolButton, 59, 38);
    laWidget_SetScheme((laWidget*)VolButton, &VolumeButtonScheme);
    laWidget_SetBackgroundType((laWidget*)VolButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)VolButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(VolButton, LA_TRUE);
    laButtonWidget_SetPressed(VolButton, LA_TRUE);
    laButtonWidget_SetPressedImage(VolButton, &AudioPlay16_2);
    laButtonWidget_SetReleasedImage(VolButton, &AudioMute16_2);
    laButtonWidget_SetPressedEventCallback(VolButton, &VolButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(VolButton, &VolButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)VolButton);

}




