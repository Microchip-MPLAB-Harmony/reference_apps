#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_SlideShow_Screen();
    screenInit_Start_Screen();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_Start_Screen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_SlideShow_Screen:
        {
            screenHide_SlideShow_Screen();
            currentScreen = 0;
            break;
        }
        case screenID_Start_Screen:
        {
            screenHide_Start_Screen();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    if(changingToScreen >= 0)
        return;

    changingToScreen = id;
}

void legato_updateScreenState(void)
{
    if(leIsDrawing() == LE_TRUE)
        return;

    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_SlideShow_Screen:
            {
                screenShow_SlideShow_Screen();
                break;
            }
            case screenID_Start_Screen:
            {
                screenShow_Start_Screen();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_SlideShow_Screen:
        {
            screenUpdate_SlideShow_Screen();
            break;
        }
        case screenID_Start_Screen:
        {
            screenUpdate_Start_Screen();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

