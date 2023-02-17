#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Menu_PanelWidget0;
leGradientWidget* Menu_GradientWidget2;
leImageWidget* Menu_ImageWidget1;
leLabelWidget* Menu_LabelWidget1;
leButtonWidget* Menu_ButtonWidget_0;
leButtonWidget* Menu_ButtonWidget_1;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Menu(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Menu(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Menu_PanelWidget0 = leWidget_New();
    Menu_PanelWidget0->fn->setPosition(Menu_PanelWidget0, 0, 99);
    Menu_PanelWidget0->fn->setSize(Menu_PanelWidget0, 800, 380);
    Menu_PanelWidget0->fn->setScheme(Menu_PanelWidget0, &PanelScheme);
    root0->fn->addChild(root0, (leWidget*)Menu_PanelWidget0);

    Menu_GradientWidget2 = leGradientWidget_New();
    Menu_GradientWidget2->fn->setPosition(Menu_GradientWidget2, 0, 0);
    Menu_GradientWidget2->fn->setSize(Menu_GradientWidget2, 800, 100);
    Menu_GradientWidget2->fn->setScheme(Menu_GradientWidget2, &Gradient_scheme);
    Menu_GradientWidget2->fn->setDirection(Menu_GradientWidget2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)Menu_GradientWidget2);

    Menu_ImageWidget1 = leImageWidget_New();
    Menu_ImageWidget1->fn->setPosition(Menu_ImageWidget1, 4, 3);
    Menu_ImageWidget1->fn->setSize(Menu_ImageWidget1, 361, 84);
    Menu_ImageWidget1->fn->setBackgroundType(Menu_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Menu_ImageWidget1->fn->setBorderType(Menu_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Menu_ImageWidget1->fn->setImage(Menu_ImageWidget1, (leImage*)&MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)Menu_ImageWidget1);

    Menu_LabelWidget1 = leLabelWidget_New();
    Menu_LabelWidget1->fn->setPosition(Menu_LabelWidget1, 210, 54);
    Menu_LabelWidget1->fn->setSize(Menu_LabelWidget1, 384, 53);
    Menu_LabelWidget1->fn->setScheme(Menu_LabelWidget1, &Title_text_scheme);
    Menu_LabelWidget1->fn->setBackgroundType(Menu_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    Menu_LabelWidget1->fn->setString(Menu_LabelWidget1, (leString*)&string_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)Menu_LabelWidget1);

    Menu_ButtonWidget_0 = leButtonWidget_New();
    Menu_ButtonWidget_0->fn->setPosition(Menu_ButtonWidget_0, 251, 156);
    Menu_ButtonWidget_0->fn->setSize(Menu_ButtonWidget_0, 287, 72);
    Menu_ButtonWidget_0->fn->setScheme(Menu_ButtonWidget_0, &Unselected_Level_label_scheme);
    Menu_ButtonWidget_0->fn->setToggleable(Menu_ButtonWidget_0, LE_TRUE);
    Menu_ButtonWidget_0->fn->setString(Menu_ButtonWidget_0, (leString*)&string_Level1);
    Menu_ButtonWidget_0->fn->setImagePosition(Menu_ButtonWidget_0, LE_RELATIVE_POSITION_BELOW);
    Menu_ButtonWidget_0->fn->setPressedEventCallback(Menu_ButtonWidget_0, event_Menu_ButtonWidget_0_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Menu_ButtonWidget_0);

    Menu_ButtonWidget_1 = leButtonWidget_New();
    Menu_ButtonWidget_1->fn->setPosition(Menu_ButtonWidget_1, 248, 286);
    Menu_ButtonWidget_1->fn->setSize(Menu_ButtonWidget_1, 298, 72);
    Menu_ButtonWidget_1->fn->setScheme(Menu_ButtonWidget_1, &Unselected_Level_label_scheme);
    Menu_ButtonWidget_1->fn->setToggleable(Menu_ButtonWidget_1, LE_TRUE);
    Menu_ButtonWidget_1->fn->setString(Menu_ButtonWidget_1, (leString*)&string_Level2);
    Menu_ButtonWidget_1->fn->setPressedEventCallback(Menu_ButtonWidget_1, event_Menu_ButtonWidget_1_OnPressed);
    root0->fn->addChild(root0, (leWidget*)Menu_ButtonWidget_1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Menu(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Menu(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Menu_PanelWidget0 = NULL;
    Menu_GradientWidget2 = NULL;
    Menu_ImageWidget1 = NULL;
    Menu_LabelWidget1 = NULL;
    Menu_ButtonWidget_0 = NULL;
    Menu_ButtonWidget_1 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Menu(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Menu(uint32_t lyrIdx)
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

