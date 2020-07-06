#include "gfx/legato/generated/screen/le_gen_screen_MusicScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget1;
leButtonWidget* PlayPausebutton;
leButtonWidget* ButtonWidget0;
leSliderWidget* volumecontrol;
leRectangleWidget* RectangleWidget1;
leRectangleWidget* RectangleWidget0;
leLabelWidget* LabelWidget0;
leLabelWidget* LabelWidget1;
leImageWidget* ImageWidget0;
leButtonWidget* ButtonWidget1;
leLabelWidget* LabelWidget2;
leListWheelWidget* ListWheelWidget0;
leLabelWidget* LabelWidget4;

// string list for this screen
static leTableString tableString_startstring;
static leTableString tableString_endstring;
static leTableString tableString_Musicplayertitle;
static leTableString tableString_zFileNotFound;

static leBool showing = LE_FALSE;

leResult screenInit_MusicScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_MusicScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_startstring, string_startstring);
    leTableString_Constructor(&tableString_endstring, string_endstring);
    leTableString_Constructor(&tableString_Musicplayertitle, string_Musicplayertitle);
    leTableString_Constructor(&tableString_zFileNotFound, string_zFileNotFound);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget1 = leGradientWidget_New();
    GradientWidget1->fn->setPosition(GradientWidget1, 0, 0);
    GradientWidget1->fn->setSize(GradientWidget1, 480, 320);
    GradientWidget1->fn->setScheme(GradientWidget1, &gradientScheme);
    GradientWidget1->fn->setDirection(GradientWidget1, LE_DIRECTION_UP);
    root0->fn->addChild(root0, (leWidget*)GradientWidget1);

    PlayPausebutton = leButtonWidget_New();
    PlayPausebutton->fn->setPosition(PlayPausebutton, 170, 230);
    PlayPausebutton->fn->setSize(PlayPausebutton, 110, 70);
    PlayPausebutton->fn->setBackgroundType(PlayPausebutton, LE_WIDGET_BACKGROUND_NONE);
    PlayPausebutton->fn->setBorderType(PlayPausebutton, LE_WIDGET_BORDER_NONE);
    PlayPausebutton->fn->setPressedImage(PlayPausebutton, &play_pause_music);
    PlayPausebutton->fn->setReleasedImage(PlayPausebutton, &play_pause_music);
    root0->fn->addChild(root0, (leWidget*)PlayPausebutton);

    ButtonWidget0 = leButtonWidget_New();
    ButtonWidget0->fn->setPosition(ButtonWidget0, 290, 230);
    ButtonWidget0->fn->setSize(ButtonWidget0, 120, 70);
    ButtonWidget0->fn->setBackgroundType(ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget0->fn->setBorderType(ButtonWidget0, LE_WIDGET_BORDER_NONE);
    ButtonWidget0->fn->setPressedImage(ButtonWidget0, &forward_music_1);
    ButtonWidget0->fn->setReleasedImage(ButtonWidget0, &forward_music_1);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget0);

    volumecontrol = leSliderWidget_New();
    volumecontrol->fn->setPosition(volumecontrol, 420, 10);
    volumecontrol->fn->setSize(volumecontrol, 50, 300);
    volumecontrol->fn->setAlphaEnabled(volumecontrol, LE_TRUE);
    volumecontrol->fn->setScheme(volumecontrol, &volumeScheme);
    volumecontrol->fn->setBackgroundType(volumecontrol, LE_WIDGET_BACKGROUND_NONE);
    volumecontrol->fn->setValue(volumecontrol, 10);
    volumecontrol->fn->setGripSize(volumecontrol, 20);
    root0->fn->addChild(root0, (leWidget*)volumecontrol);

    RectangleWidget1 = leRectangleWidget_New();
    RectangleWidget1->fn->setPosition(RectangleWidget1, 60, 190);
    RectangleWidget1->fn->setSize(RectangleWidget1, 310, 23);
    RectangleWidget1->fn->setScheme(RectangleWidget1, &ProgressScheme);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget1);

    RectangleWidget0 = leRectangleWidget_New();
    RectangleWidget0->fn->setPosition(RectangleWidget0, 60, 190);
    RectangleWidget0->fn->setSize(RectangleWidget0, 22, 22);
    RectangleWidget0->fn->setScheme(RectangleWidget0, &volumeScheme);
    RectangleWidget0->fn->setBorderType(RectangleWidget0, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget0);

    LabelWidget0 = leLabelWidget_New();
    LabelWidget0->fn->setPosition(LabelWidget0, 20, 200);
    LabelWidget0->fn->setSize(LabelWidget0, 32, 14);
    LabelWidget0->fn->setBackgroundType(LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget0->fn->setString(LabelWidget0, (leString*)&tableString_startstring);
    root0->fn->addChild(root0, (leWidget*)LabelWidget0);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 370, 194);
    LabelWidget1->fn->setSize(LabelWidget1, 32, 21);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_endstring);
    root0->fn->addChild(root0, (leWidget*)LabelWidget1);

    ImageWidget0 = leImageWidget_New();
    ImageWidget0->fn->setPosition(ImageWidget0, 2, 3);
    ImageWidget0->fn->setSize(ImageWidget0, 49, 39);
    ImageWidget0->fn->setScheme(ImageWidget0, &whiteScheme);
    ImageWidget0->fn->setBackgroundType(ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget0->fn->setImage(ImageWidget0, &mchpLogo);
    root0->fn->addChild(root0, (leWidget*)ImageWidget0);

    ButtonWidget1 = leButtonWidget_New();
    ButtonWidget1->fn->setPosition(ButtonWidget1, 20, 230);
    ButtonWidget1->fn->setSize(ButtonWidget1, 135, 70);
    ButtonWidget1->fn->setScheme(ButtonWidget1, &whiteScheme);
    ButtonWidget1->fn->setBackgroundType(ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget1->fn->setBorderType(ButtonWidget1, LE_WIDGET_BORDER_NONE);
    ButtonWidget1->fn->setPressedImage(ButtonWidget1, &rewind_music_1);
    ButtonWidget1->fn->setReleasedImage(ButtonWidget1, &rewind_music_1);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget1);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 44, 9);
    LabelWidget2->fn->setSize(LabelWidget2, 377, 32);
    LabelWidget2->fn->setScheme(LabelWidget2, &whiteScheme);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setHAlignment(LabelWidget2, LE_HALIGN_CENTER);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_Musicplayertitle);
    root0->fn->addChild(root0, (leWidget*)LabelWidget2);

    ListWheelWidget0 = leListWheelWidget_New();
    ListWheelWidget0->fn->setPosition(ListWheelWidget0, 10, 50);
    ListWheelWidget0->fn->setSize(ListWheelWidget0, 400, 130);
    ListWheelWidget0->fn->setAlphaEnabled(ListWheelWidget0, LE_TRUE);
    ListWheelWidget0->fn->setScheme(ListWheelWidget0, &gradientScheme);
    ListWheelWidget0->fn->setBorderType(ListWheelWidget0, LE_WIDGET_BORDER_LINE);
    ListWheelWidget0->fn->setHAlignment(ListWheelWidget0, LE_HALIGN_LEFT);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setShaded(ListWheelWidget0, LE_FALSE);
    ListWheelWidget0->fn->setIndicatorFill(ListWheelWidget0, LE_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    ListWheelWidget0->fn->setFlickInitSpeed(ListWheelWidget0, 10);
    ListWheelWidget0->fn->setMaxMomentum(ListWheelWidget0, 3000);
    ListWheelWidget0->fn->setRotationUpdateRate(ListWheelWidget0, 20);
    root0->fn->addChild(root0, (leWidget*)ListWheelWidget0);

    LabelWidget4 = leLabelWidget_New();
    LabelWidget4->fn->setPosition(LabelWidget4, 10, 96);
    LabelWidget4->fn->setSize(LabelWidget4, 400, 44);
    LabelWidget4->fn->setVisible(LabelWidget4, LE_FALSE);
    LabelWidget4->fn->setScheme(LabelWidget4, &volumeScheme);
    LabelWidget4->fn->setBorderType(LabelWidget4, LE_WIDGET_BORDER_LINE);
    LabelWidget4->fn->setHAlignment(LabelWidget4, LE_HALIGN_CENTER);
    LabelWidget4->fn->setString(LabelWidget4, (leString*)&tableString_zFileNotFound);
    root0->fn->addChild(root0, (leWidget*)LabelWidget4);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    MusicScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_MusicScreen()
{
    MusicScreen_OnUpdate();
}

void screenHide_MusicScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget1 = NULL;
    PlayPausebutton = NULL;
    ButtonWidget0 = NULL;
    volumecontrol = NULL;
    RectangleWidget1 = NULL;
    RectangleWidget0 = NULL;
    LabelWidget0 = NULL;
    LabelWidget1 = NULL;
    ImageWidget0 = NULL;
    ButtonWidget1 = NULL;
    LabelWidget2 = NULL;
    ListWheelWidget0 = NULL;
    LabelWidget4 = NULL;

    tableString_startstring.fn->destructor(&tableString_startstring);
    tableString_endstring.fn->destructor(&tableString_endstring);
    tableString_Musicplayertitle.fn->destructor(&tableString_Musicplayertitle);
    tableString_zFileNotFound.fn->destructor(&tableString_zFileNotFound);
    showing = LE_FALSE;

    MusicScreen_OnHide();
}

void screenDestroy_MusicScreen()
{

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

