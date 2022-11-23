#include "gfx/legato/generated/screen/le_gen_screen_MusicScreen.h"

// screen member widget declarations
static leWidget* root0;

leWidget* MusicScreen_Background;
leButtonWidget* MusicScreen_PlayPausebutton;
leSliderWidget* MusicScreen_volumecontrol;
leImageWidget* MusicScreen_ImageWidget0;
leLabelWidget* MusicScreen_LabelWidget2;
leListWheelWidget* MusicScreen_ListWheelWidget0;
leButtonWidget* MusicScreen_NextTrackButton;
leButtonWidget* MusicScreen_PreviousTrackButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MusicScreen(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MusicScreen(void)
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

    MusicScreen_Background = leWidget_New();
    MusicScreen_Background->fn->setPosition(MusicScreen_Background, 0, 0);
    MusicScreen_Background->fn->setSize(MusicScreen_Background, 480, 272);
    MusicScreen_Background->fn->setScheme(MusicScreen_Background, &MusicScreenBackground);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_Background);

    MusicScreen_PlayPausebutton = leButtonWidget_New();
    MusicScreen_PlayPausebutton->fn->setPosition(MusicScreen_PlayPausebutton, 179, 178);
    MusicScreen_PlayPausebutton->fn->setSize(MusicScreen_PlayPausebutton, 90, 90);
    MusicScreen_PlayPausebutton->fn->setBackgroundType(MusicScreen_PlayPausebutton, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_PlayPausebutton->fn->setBorderType(MusicScreen_PlayPausebutton, LE_WIDGET_BORDER_NONE);
    MusicScreen_PlayPausebutton->fn->setToggleable(MusicScreen_PlayPausebutton, LE_TRUE);
    MusicScreen_PlayPausebutton->fn->setPressed(MusicScreen_PlayPausebutton, LE_TRUE);
    MusicScreen_PlayPausebutton->fn->setPressedImage(MusicScreen_PlayPausebutton, (leImage*)&pause_90x90);
    MusicScreen_PlayPausebutton->fn->setReleasedImage(MusicScreen_PlayPausebutton, (leImage*)&Play_Icon);
    MusicScreen_PlayPausebutton->fn->setPressedEventCallback(MusicScreen_PlayPausebutton, event_MusicScreen_PlayPausebutton_OnPressed);
    MusicScreen_PlayPausebutton->fn->setReleasedEventCallback(MusicScreen_PlayPausebutton, event_MusicScreen_PlayPausebutton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_PlayPausebutton);

    MusicScreen_volumecontrol = leSliderWidget_New();
    MusicScreen_volumecontrol->fn->setPosition(MusicScreen_volumecontrol, 425, 3);
    MusicScreen_volumecontrol->fn->setSize(MusicScreen_volumecontrol, 50, 263);
    MusicScreen_volumecontrol->fn->setAlphaEnabled(MusicScreen_volumecontrol, LE_TRUE);
    MusicScreen_volumecontrol->fn->setScheme(MusicScreen_volumecontrol, &volumeScheme);
    MusicScreen_volumecontrol->fn->setBackgroundType(MusicScreen_volumecontrol, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_volumecontrol->fn->setMaximumValue(MusicScreen_volumecontrol, 255);
    MusicScreen_volumecontrol->fn->setGripSize(MusicScreen_volumecontrol, 20);
    MusicScreen_volumecontrol->fn->setValueChangedEventCallback(MusicScreen_volumecontrol, event_MusicScreen_volumecontrol_OnValueChanged);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_volumecontrol);

    MusicScreen_ImageWidget0 = leImageWidget_New();
    MusicScreen_ImageWidget0->fn->setPosition(MusicScreen_ImageWidget0, 0, 0);
    MusicScreen_ImageWidget0->fn->setSize(MusicScreen_ImageWidget0, 137, 34);
    MusicScreen_ImageWidget0->fn->setScheme(MusicScreen_ImageWidget0, &whiteScheme);
    MusicScreen_ImageWidget0->fn->setBackgroundType(MusicScreen_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_ImageWidget0->fn->setBorderType(MusicScreen_ImageWidget0, LE_WIDGET_BORDER_NONE);
    MusicScreen_ImageWidget0->fn->setImage(MusicScreen_ImageWidget0, (leImage*)&MicrochipLogo_120x27);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ImageWidget0);

    MusicScreen_LabelWidget2 = leLabelWidget_New();
    MusicScreen_LabelWidget2->fn->setPosition(MusicScreen_LabelWidget2, 44, 9);
    MusicScreen_LabelWidget2->fn->setSize(MusicScreen_LabelWidget2, 377, 32);
    MusicScreen_LabelWidget2->fn->setScheme(MusicScreen_LabelWidget2, &whiteScheme);
    MusicScreen_LabelWidget2->fn->setBackgroundType(MusicScreen_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_LabelWidget2->fn->setHAlignment(MusicScreen_LabelWidget2, LE_HALIGN_CENTER);
    MusicScreen_LabelWidget2->fn->setString(MusicScreen_LabelWidget2, (leString*)&string_Musicplayertitle);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_LabelWidget2);

    MusicScreen_ListWheelWidget0 = leListWheelWidget_New();
    MusicScreen_ListWheelWidget0->fn->setPosition(MusicScreen_ListWheelWidget0, 70, 97);
    MusicScreen_ListWheelWidget0->fn->setSize(MusicScreen_ListWheelWidget0, 329, 76);
    MusicScreen_ListWheelWidget0->fn->setScheme(MusicScreen_ListWheelWidget0, &gradientScheme);
    MusicScreen_ListWheelWidget0->fn->setBackgroundType(MusicScreen_ListWheelWidget0, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_ListWheelWidget0->fn->setBorderType(MusicScreen_ListWheelWidget0, LE_WIDGET_BORDER_NONE);
    MusicScreen_ListWheelWidget0->fn->setVisibleItemCount(MusicScreen_ListWheelWidget0, 3);
    MusicScreen_ListWheelWidget0->fn->setShowIndicators(MusicScreen_ListWheelWidget0, LE_FALSE);
    MusicScreen_ListWheelWidget0->fn->setIndicatorArea(MusicScreen_ListWheelWidget0, 10);
    MusicScreen_ListWheelWidget0->fn->setShaded(MusicScreen_ListWheelWidget0, LE_FALSE);
    MusicScreen_ListWheelWidget0->fn->setFlickInitSpeed(MusicScreen_ListWheelWidget0, 10);
    MusicScreen_ListWheelWidget0->fn->setMaxMomentum(MusicScreen_ListWheelWidget0, 3000);
    MusicScreen_ListWheelWidget0->fn->setRotationUpdateRate(MusicScreen_ListWheelWidget0, 20);
    MusicScreen_ListWheelWidget0->fn->setAutoHideWheel(MusicScreen_ListWheelWidget0, LE_TRUE);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->setItemString(MusicScreen_ListWheelWidget0, 0, (leString*)&string_Done);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->setItemString(MusicScreen_ListWheelWidget0, 1, (leString*)&string_test);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->setItemString(MusicScreen_ListWheelWidget0, 2, (leString*)&string_Initializing);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->setItemString(MusicScreen_ListWheelWidget0, 3, (leString*)&string_InvalidFile);
    MusicScreen_ListWheelWidget0->fn->setSelectedItemChangedEventCallback(MusicScreen_ListWheelWidget0, event_MusicScreen_ListWheelWidget0_OnSelectionChanged);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ListWheelWidget0);

    MusicScreen_NextTrackButton = leButtonWidget_New();
    MusicScreen_NextTrackButton->fn->setPosition(MusicScreen_NextTrackButton, 296, 178);
    MusicScreen_NextTrackButton->fn->setSize(MusicScreen_NextTrackButton, 90, 90);
    MusicScreen_NextTrackButton->fn->setBackgroundType(MusicScreen_NextTrackButton, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_NextTrackButton->fn->setBorderType(MusicScreen_NextTrackButton, LE_WIDGET_BORDER_NONE);
    MusicScreen_NextTrackButton->fn->setPressedImage(MusicScreen_NextTrackButton, (leImage*)&NextTrackIcon);
    MusicScreen_NextTrackButton->fn->setReleasedImage(MusicScreen_NextTrackButton, (leImage*)&NextTrackIcon);
    MusicScreen_NextTrackButton->fn->setReleasedEventCallback(MusicScreen_NextTrackButton, event_MusicScreen_NextTrackButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_NextTrackButton);

    MusicScreen_PreviousTrackButton = leButtonWidget_New();
    MusicScreen_PreviousTrackButton->fn->setPosition(MusicScreen_PreviousTrackButton, 59, 178);
    MusicScreen_PreviousTrackButton->fn->setSize(MusicScreen_PreviousTrackButton, 90, 90);
    MusicScreen_PreviousTrackButton->fn->setBackgroundType(MusicScreen_PreviousTrackButton, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_PreviousTrackButton->fn->setBorderType(MusicScreen_PreviousTrackButton, LE_WIDGET_BORDER_NONE);
    MusicScreen_PreviousTrackButton->fn->setPressedImage(MusicScreen_PreviousTrackButton, (leImage*)&PreviousTrackIcon);
    MusicScreen_PreviousTrackButton->fn->setReleasedImage(MusicScreen_PreviousTrackButton, (leImage*)&PreviousTrackIcon);
    MusicScreen_PreviousTrackButton->fn->setReleasedEventCallback(MusicScreen_PreviousTrackButton, event_MusicScreen_PreviousTrackButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_PreviousTrackButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MusicScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MusicScreen(void)
{
    root0->fn->setSize(root0, root0->parent->rect.width, root0->parent->rect.height);

    MusicScreen_OnUpdate(); // raise event
}

void screenHide_MusicScreen(void)
{
    MusicScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MusicScreen_Background = NULL;
    MusicScreen_PlayPausebutton = NULL;
    MusicScreen_volumecontrol = NULL;
    MusicScreen_ImageWidget0 = NULL;
    MusicScreen_LabelWidget2 = NULL;
    MusicScreen_ListWheelWidget0 = NULL;
    MusicScreen_NextTrackButton = NULL;
    MusicScreen_PreviousTrackButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MusicScreen(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_MusicScreen(uint32_t lyrIdx)
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

