#include "gfx/legato/generated/le_gen_init.h"

static int32_t currentScreen;
static int32_t changingToScreen;

void legato_initializeScreenState(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_default();
    screenInit_MusicScreen();

    currentScreen = -1;
    changingToScreen = -1;

    legato_showScreen(screenID_default);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

static void legato_hideCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_default:
        {
            screenHide_default();
            currentScreen = 0;
            break;
        }
        case screenID_MusicScreen:
        {
            screenHide_MusicScreen();
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
    if(changingToScreen >= 0)
    {
        legato_hideCurrentScreen();

        switch(changingToScreen)
        {
            case screenID_default:
            {
                screenShow_default();
                break;
            }
            case screenID_MusicScreen:
            {
                screenShow_MusicScreen();
                break;
            }
        }

        currentScreen = changingToScreen;
        changingToScreen = -1;
    }

    switch(currentScreen)
    {
        case screenID_default:
        {
            screenUpdate_default();
            break;
        }
        case screenID_MusicScreen:
        {
            screenUpdate_MusicScreen();
            break;
        }
    }
}

leBool legato_isChangingScreens(void)
{
    return changingToScreen != -1;
}

