#include "gfx/legato/generated/screen/le_gen_screen_MusicScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* MusicScreen_GradientWidget1;
leButtonWidget* MusicScreen_PlayPausebutton;
leButtonWidget* MusicScreen_ButtonWidget0;
leSliderWidget* MusicScreen_volumecontrol;
leRectangleWidget* MusicScreen_RectangleWidget1;
leRectangleWidget* MusicScreen_RectangleWidget0;
leLabelWidget* MusicScreen_LabelWidget0;
leLabelWidget* MusicScreen_LabelWidget1;
leImageWidget* MusicScreen_ImageWidget0;
leButtonWidget* MusicScreen_ButtonWidget1;
leLabelWidget* MusicScreen_LabelWidget2;
leListWheelWidget* MusicScreen_ListWheelWidget0;
leLabelWidget* MusicScreen_LabelWidget4;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MusicScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MusicScreen()
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

    MusicScreen_GradientWidget1 = leGradientWidget_New();
    MusicScreen_GradientWidget1->fn->setPosition(MusicScreen_GradientWidget1, 0, 1);
    MusicScreen_GradientWidget1->fn->setSize(MusicScreen_GradientWidget1, 480, 320);
    MusicScreen_GradientWidget1->fn->setScheme(MusicScreen_GradientWidget1, &gradientScheme);
    MusicScreen_GradientWidget1->fn->setDirection(MusicScreen_GradientWidget1, LE_DIRECTION_UP);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_GradientWidget1);

    MusicScreen_PlayPausebutton = leButtonWidget_New();
    MusicScreen_PlayPausebutton->fn->setPosition(MusicScreen_PlayPausebutton, 170, 230);
    MusicScreen_PlayPausebutton->fn->setSize(MusicScreen_PlayPausebutton, 110, 70);
    MusicScreen_PlayPausebutton->fn->setBackgroundType(MusicScreen_PlayPausebutton, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_PlayPausebutton->fn->setBorderType(MusicScreen_PlayPausebutton, LE_WIDGET_BORDER_NONE);
    MusicScreen_PlayPausebutton->fn->setPressedImage(MusicScreen_PlayPausebutton, (leImage*)&play_pause_music_0);
    MusicScreen_PlayPausebutton->fn->setReleasedImage(MusicScreen_PlayPausebutton, (leImage*)&play_pause_music_0);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_PlayPausebutton);

    MusicScreen_ButtonWidget0 = leButtonWidget_New();
    MusicScreen_ButtonWidget0->fn->setPosition(MusicScreen_ButtonWidget0, 290, 230);
    MusicScreen_ButtonWidget0->fn->setSize(MusicScreen_ButtonWidget0, 120, 70);
    MusicScreen_ButtonWidget0->fn->setBackgroundType(MusicScreen_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_ButtonWidget0->fn->setBorderType(MusicScreen_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    MusicScreen_ButtonWidget0->fn->setPressedImage(MusicScreen_ButtonWidget0, (leImage*)&forward_music);
    MusicScreen_ButtonWidget0->fn->setReleasedImage(MusicScreen_ButtonWidget0, (leImage*)&forward_music);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ButtonWidget0);

    MusicScreen_volumecontrol = leSliderWidget_New();
    MusicScreen_volumecontrol->fn->setPosition(MusicScreen_volumecontrol, 420, 10);
    MusicScreen_volumecontrol->fn->setSize(MusicScreen_volumecontrol, 50, 300);
    MusicScreen_volumecontrol->fn->setAlphaEnabled(MusicScreen_volumecontrol, LE_TRUE);
    MusicScreen_volumecontrol->fn->setScheme(MusicScreen_volumecontrol, &volumeScheme);
    MusicScreen_volumecontrol->fn->setBackgroundType(MusicScreen_volumecontrol, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_volumecontrol->fn->setValue(MusicScreen_volumecontrol, 10);
    MusicScreen_volumecontrol->fn->setGripSize(MusicScreen_volumecontrol, 20);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_volumecontrol);

    MusicScreen_RectangleWidget1 = leRectangleWidget_New();
    MusicScreen_RectangleWidget1->fn->setPosition(MusicScreen_RectangleWidget1, 60, 190);
    MusicScreen_RectangleWidget1->fn->setSize(MusicScreen_RectangleWidget1, 310, 23);
    MusicScreen_RectangleWidget1->fn->setScheme(MusicScreen_RectangleWidget1, &ProgressScheme);
    MusicScreen_RectangleWidget1->fn->setBorderType(MusicScreen_RectangleWidget1, LE_WIDGET_BORDER_NONE);
    MusicScreen_RectangleWidget1->fn->setThickness(MusicScreen_RectangleWidget1, 2);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_RectangleWidget1);

    MusicScreen_RectangleWidget0 = leRectangleWidget_New();
    MusicScreen_RectangleWidget0->fn->setPosition(MusicScreen_RectangleWidget0, 60, 190);
    MusicScreen_RectangleWidget0->fn->setSize(MusicScreen_RectangleWidget0, 22, 22);
    MusicScreen_RectangleWidget0->fn->setScheme(MusicScreen_RectangleWidget0, &volumeScheme);
    MusicScreen_RectangleWidget0->fn->setBorderType(MusicScreen_RectangleWidget0, LE_WIDGET_BORDER_LINE);
    MusicScreen_RectangleWidget0->fn->setThickness(MusicScreen_RectangleWidget0, 2);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_RectangleWidget0);

    MusicScreen_LabelWidget0 = leLabelWidget_New();
    MusicScreen_LabelWidget0->fn->setPosition(MusicScreen_LabelWidget0, 20, 200);
    MusicScreen_LabelWidget0->fn->setSize(MusicScreen_LabelWidget0, 32, 14);
    MusicScreen_LabelWidget0->fn->setBackgroundType(MusicScreen_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_LabelWidget0->fn->setString(MusicScreen_LabelWidget0, (leString*)&string_startstring);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_LabelWidget0);

    MusicScreen_LabelWidget1 = leLabelWidget_New();
    MusicScreen_LabelWidget1->fn->setPosition(MusicScreen_LabelWidget1, 370, 194);
    MusicScreen_LabelWidget1->fn->setSize(MusicScreen_LabelWidget1, 32, 21);
    MusicScreen_LabelWidget1->fn->setBackgroundType(MusicScreen_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_LabelWidget1->fn->setString(MusicScreen_LabelWidget1, (leString*)&string_endstring);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_LabelWidget1);

    MusicScreen_ImageWidget0 = leImageWidget_New();
    MusicScreen_ImageWidget0->fn->setPosition(MusicScreen_ImageWidget0, 2, 3);
    MusicScreen_ImageWidget0->fn->setSize(MusicScreen_ImageWidget0, 49, 39);
    MusicScreen_ImageWidget0->fn->setScheme(MusicScreen_ImageWidget0, &whiteScheme);
    MusicScreen_ImageWidget0->fn->setBackgroundType(MusicScreen_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_ImageWidget0->fn->setBorderType(MusicScreen_ImageWidget0, LE_WIDGET_BORDER_NONE);
    MusicScreen_ImageWidget0->fn->setImage(MusicScreen_ImageWidget0, (leImage*)&mchpLogo);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ImageWidget0);

    MusicScreen_ButtonWidget1 = leButtonWidget_New();
    MusicScreen_ButtonWidget1->fn->setPosition(MusicScreen_ButtonWidget1, 20, 230);
    MusicScreen_ButtonWidget1->fn->setSize(MusicScreen_ButtonWidget1, 135, 70);
    MusicScreen_ButtonWidget1->fn->setScheme(MusicScreen_ButtonWidget1, &whiteScheme);
    MusicScreen_ButtonWidget1->fn->setBackgroundType(MusicScreen_ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_ButtonWidget1->fn->setBorderType(MusicScreen_ButtonWidget1, LE_WIDGET_BORDER_NONE);
    MusicScreen_ButtonWidget1->fn->setPressedImage(MusicScreen_ButtonWidget1, (leImage*)&rewind_music);
    MusicScreen_ButtonWidget1->fn->setReleasedImage(MusicScreen_ButtonWidget1, (leImage*)&rewind_music);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ButtonWidget1);

    MusicScreen_LabelWidget2 = leLabelWidget_New();
    MusicScreen_LabelWidget2->fn->setPosition(MusicScreen_LabelWidget2, 44, 9);
    MusicScreen_LabelWidget2->fn->setSize(MusicScreen_LabelWidget2, 377, 32);
    MusicScreen_LabelWidget2->fn->setScheme(MusicScreen_LabelWidget2, &whiteScheme);
    MusicScreen_LabelWidget2->fn->setBackgroundType(MusicScreen_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    MusicScreen_LabelWidget2->fn->setHAlignment(MusicScreen_LabelWidget2, LE_HALIGN_CENTER);
    MusicScreen_LabelWidget2->fn->setString(MusicScreen_LabelWidget2, (leString*)&string_Musicplayertitle);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_LabelWidget2);

    MusicScreen_ListWheelWidget0 = leListWheelWidget_New();
    MusicScreen_ListWheelWidget0->fn->setPosition(MusicScreen_ListWheelWidget0, 10, 50);
    MusicScreen_ListWheelWidget0->fn->setSize(MusicScreen_ListWheelWidget0, 400, 130);
    MusicScreen_ListWheelWidget0->fn->setAlphaEnabled(MusicScreen_ListWheelWidget0, LE_TRUE);
    MusicScreen_ListWheelWidget0->fn->setScheme(MusicScreen_ListWheelWidget0, &gradientScheme);
    MusicScreen_ListWheelWidget0->fn->setBorderType(MusicScreen_ListWheelWidget0, LE_WIDGET_BORDER_LINE);
    MusicScreen_ListWheelWidget0->fn->setHAlignment(MusicScreen_ListWheelWidget0, LE_HALIGN_LEFT);
    MusicScreen_ListWheelWidget0->fn->setShaded(MusicScreen_ListWheelWidget0, LE_FALSE);
    MusicScreen_ListWheelWidget0->fn->setFlickInitSpeed(MusicScreen_ListWheelWidget0, 10);
    MusicScreen_ListWheelWidget0->fn->setMaxMomentum(MusicScreen_ListWheelWidget0, 3000);
    MusicScreen_ListWheelWidget0->fn->setRotationUpdateRate(MusicScreen_ListWheelWidget0, 20);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    MusicScreen_ListWheelWidget0->fn->appendItem(MusicScreen_ListWheelWidget0);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_ListWheelWidget0);

    MusicScreen_LabelWidget4 = leLabelWidget_New();
    MusicScreen_LabelWidget4->fn->setPosition(MusicScreen_LabelWidget4, 10, 96);
    MusicScreen_LabelWidget4->fn->setSize(MusicScreen_LabelWidget4, 400, 44);
    MusicScreen_LabelWidget4->fn->setVisible(MusicScreen_LabelWidget4, LE_FALSE);
    MusicScreen_LabelWidget4->fn->setScheme(MusicScreen_LabelWidget4, &volumeScheme);
    MusicScreen_LabelWidget4->fn->setBorderType(MusicScreen_LabelWidget4, LE_WIDGET_BORDER_LINE);
    MusicScreen_LabelWidget4->fn->setHAlignment(MusicScreen_LabelWidget4, LE_HALIGN_CENTER);
    MusicScreen_LabelWidget4->fn->setString(MusicScreen_LabelWidget4, (leString*)&string_zFileNotFound);
    root0->fn->addChild(root0, (leWidget*)MusicScreen_LabelWidget4);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MusicScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MusicScreen()
{
}

void screenHide_MusicScreen()
{
    MusicScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MusicScreen_GradientWidget1 = NULL;
    MusicScreen_PlayPausebutton = NULL;
    MusicScreen_ButtonWidget0 = NULL;
    MusicScreen_volumecontrol = NULL;
    MusicScreen_RectangleWidget1 = NULL;
    MusicScreen_RectangleWidget0 = NULL;
    MusicScreen_LabelWidget0 = NULL;
    MusicScreen_LabelWidget1 = NULL;
    MusicScreen_ImageWidget0 = NULL;
    MusicScreen_ButtonWidget1 = NULL;
    MusicScreen_LabelWidget2 = NULL;
    MusicScreen_ListWheelWidget0 = NULL;
    MusicScreen_LabelWidget4 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MusicScreen()
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

