#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Menu_PanelWidget0;
leLabelWidget* Menu_Level1_label;
leLabelWidget* Menu_Level2_label;
leGradientWidget* Menu_GradientWidget2;
leImageWidget* Menu_ImageWidget1;
leLabelWidget* Menu_LabelWidget1;

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

    Menu_Level1_label = leLabelWidget_New();
    Menu_Level1_label->fn->setPosition(Menu_Level1_label, 239, 165);
    Menu_Level1_label->fn->setSize(Menu_Level1_label, 285, 72);
    Menu_Level1_label->fn->setScheme(Menu_Level1_label, &Unselected_Level_label_scheme);
    Menu_Level1_label->fn->setBorderType(Menu_Level1_label, LE_WIDGET_BORDER_BEVEL);
    Menu_Level1_label->fn->setHAlignment(Menu_Level1_label, LE_HALIGN_CENTER);
    Menu_Level1_label->fn->setVAlignment(Menu_Level1_label, LE_VALIGN_TOP);
    Menu_Level1_label->fn->setString(Menu_Level1_label, (leString*)&string_Level1);
    root0->fn->addChild(root0, (leWidget*)Menu_Level1_label);

    Menu_Level2_label = leLabelWidget_New();
    Menu_Level2_label->fn->setPosition(Menu_Level2_label, 239, 277);
    Menu_Level2_label->fn->setSize(Menu_Level2_label, 285, 72);
    Menu_Level2_label->fn->setScheme(Menu_Level2_label, &Unselected_Level_label_scheme);
    Menu_Level2_label->fn->setBorderType(Menu_Level2_label, LE_WIDGET_BORDER_BEVEL);
    Menu_Level2_label->fn->setHAlignment(Menu_Level2_label, LE_HALIGN_CENTER);
    Menu_Level2_label->fn->setVAlignment(Menu_Level2_label, LE_VALIGN_TOP);
    Menu_Level2_label->fn->setString(Menu_Level2_label, (leString*)&string_Level2);
    root0->fn->addChild(root0, (leWidget*)Menu_Level2_label);

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
    Menu_Level1_label = NULL;
    Menu_Level2_label = NULL;
    Menu_GradientWidget2 = NULL;
    Menu_ImageWidget1 = NULL;
    Menu_LabelWidget1 = NULL;


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

