#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    legato_initialize_schemes();

    leSetStringTable(&stringTable);

    currentScreen = -1;

    legato_showScreen(screenID_Splash);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenHide_Splash();
            currentScreen = 0;
            break;
        }
        case screenID_Menu:
        {
            screenHide_Menu();
            currentScreen = 0;
            break;
        }
        case screenID_Game_Level1:
        {
            screenHide_Game_Level1();
            currentScreen = 0;
            break;
        }
        case screenID_Game_Level2:
        {
            screenHide_Game_Level2();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    legato_hideCurrentScreen(currentScreen);

    switch(id)
    {
        case screenID_Splash:
        {
            screenShow_Splash();
            currentScreen = id;
            break;
        }
        case screenID_Menu:
        {
            screenShow_Menu();
            currentScreen = id;
            break;
        }
        case screenID_Game_Level1:
        {
            screenShow_Game_Level1();
            currentScreen = id;
            break;
        }
        case screenID_Game_Level2:
        {
            screenShow_Game_Level2();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
    }
}

