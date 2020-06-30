#include "gfx/legato/generated/screen/le_gen_screen_Menu.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget0;
leLabelWidget* Level1_label;
leLabelWidget* Level2_label;
leGradientWidget* GradientWidget2;
leImageWidget* ImageWidget1;
leLabelWidget* LabelWidget1;

// string list for this screen
static leTableString tableString_Level1;
static leTableString tableString_Level2;
static leTableString tableString_Game_title_label;

static leBool showing = LE_FALSE;

leResult screenInit_Menu()
{
    return LE_SUCCESS;
}

leResult screenShow_Menu()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Level1, string_Level1);
    leTableString_Constructor(&tableString_Level2, string_Level2);
    leTableString_Constructor(&tableString_Game_title_label, string_Game_title_label);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 0, 99);
    PanelWidget0->fn->setSize(PanelWidget0, 800, 380);
    PanelWidget0->fn->setScheme(PanelWidget0, &PanelScheme);
    root0->fn->addChild(root0, PanelWidget0);

    Level1_label = leLabelWidget_New();
    Level1_label->fn->setPosition(Level1_label, 239, 165);
    Level1_label->fn->setSize(Level1_label, 285, 72);
    Level1_label->fn->setScheme(Level1_label, &Level_label_scheme);
    Level1_label->fn->setBorderType(Level1_label, LE_WIDGET_BORDER_BEVEL);
    Level1_label->fn->setHAlignment(Level1_label, LE_HALIGN_CENTER);
    Level1_label->fn->setVAlignment(Level1_label, LE_VALIGN_TOP);
    Level1_label->fn->setString(Level1_label, (leString*)&tableString_Level1);
    root0->fn->addChild(root0, (leWidget*)Level1_label);

    Level2_label = leLabelWidget_New();
    Level2_label->fn->setPosition(Level2_label, 239, 277);
    Level2_label->fn->setSize(Level2_label, 285, 72);
    Level2_label->fn->setScheme(Level2_label, &Level_label_scheme);
    Level2_label->fn->setBorderType(Level2_label, LE_WIDGET_BORDER_BEVEL);
    Level2_label->fn->setHAlignment(Level2_label, LE_HALIGN_CENTER);
    Level2_label->fn->setVAlignment(Level2_label, LE_VALIGN_TOP);
    Level2_label->fn->setString(Level2_label, (leString*)&tableString_Level2);
    root0->fn->addChild(root0, (leWidget*)Level2_label);

    GradientWidget2 = leGradientWidget_New();
    GradientWidget2->fn->setPosition(GradientWidget2, 0, 0);
    GradientWidget2->fn->setSize(GradientWidget2, 800, 100);
    GradientWidget2->fn->setScheme(GradientWidget2, &Gradient_scheme);
    GradientWidget2->fn->setDirection(GradientWidget2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget2);

    ImageWidget1 = leImageWidget_New();
    ImageWidget1->fn->setPosition(ImageWidget1, 4, 3);
    ImageWidget1->fn->setSize(ImageWidget1, 250, 58);
    ImageWidget1->fn->setBackgroundType(ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget1->fn->setImage(ImageWidget1, &MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)ImageWidget1);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 210, 38);
    LabelWidget1->fn->setSize(LabelWidget1, 384, 53);
    LabelWidget1->fn->setScheme(LabelWidget1, &Title_text_scheme);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)LabelWidget1);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Menu()
{
}

void screenHide_Menu()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget0 = NULL;
    Level1_label = NULL;
    Level2_label = NULL;
    GradientWidget2 = NULL;
    ImageWidget1 = NULL;
    LabelWidget1 = NULL;

    tableString_Level1.fn->destructor(&tableString_Level1);
    tableString_Level2.fn->destructor(&tableString_Level2);
    tableString_Game_title_label.fn->destructor(&tableString_Game_title_label);
    showing = LE_FALSE;
}

void screenDestroy_Menu()
{

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

