#include "gfx/legato/generated/screen/le_gen_screen_Game_Level1.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget2;
leWidget* PanelWidget3;
leImageWidget* HeartImage1_level1;
leImageWidget* HeartImage2_level1;
leImageWidget* HeartImage3_level1;
leLabelWidget* Snake_size_text_1;
leLabelWidget* LIfe_text_1;
leLabelWidget* Snake_size_value_level1;
leGradientWidget* GradientWidget0;
leImageWidget* ImageWidget0;
leLabelWidget* Game_Over_level1;
leLabelWidget* Title_label_game_level_1;
leLabelWidget* Game_Won_level1;

// string list for this screen
static leTableString tableString_Snake_Size_text;
static leTableString tableString_Snake_Lifes_label;
static leTableString tableString_Snake_size_value_level_1;
static leTableString tableString_Game_Over_Text;
static leTableString tableString_Game_title_label;
static leTableString tableString_Game_Won_Text;

static leBool showing = LE_FALSE;

leResult screenInit_Game_Level1()
{
    return LE_SUCCESS;
}

leResult screenShow_Game_Level1()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Snake_Size_text, string_Snake_Size_text);
    leTableString_Constructor(&tableString_Snake_Lifes_label, string_Snake_Lifes_label);
    leTableString_Constructor(&tableString_Snake_size_value_level_1, string_Snake_size_value_level_1);
    leTableString_Constructor(&tableString_Game_Over_Text, string_Game_Over_Text);
    leTableString_Constructor(&tableString_Game_title_label, string_Game_title_label);
    leTableString_Constructor(&tableString_Game_Won_Text, string_Game_Won_Text);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget2 = leWidget_New();
    PanelWidget2->fn->setPosition(PanelWidget2, 0, 98);
    PanelWidget2->fn->setSize(PanelWidget2, 700, 380);
    PanelWidget2->fn->setScheme(PanelWidget2, &PanelScheme);
    root0->fn->addChild(root0, PanelWidget2);

    PanelWidget3 = leWidget_New();
    PanelWidget3->fn->setPosition(PanelWidget3, 700, 99);
    PanelWidget3->fn->setSize(PanelWidget3, 100, 380);
    PanelWidget3->fn->setScheme(PanelWidget3, &RightPanelscheme);
    PanelWidget3->fn->setBorderType(PanelWidget3, LE_WIDGET_BORDER_BEVEL);
    root0->fn->addChild(root0, PanelWidget3);

    HeartImage1_level1 = leImageWidget_New();
    HeartImage1_level1->fn->setPosition(HeartImage1_level1, 716, 136);
    HeartImage1_level1->fn->setSize(HeartImage1_level1, 66, 50);
    HeartImage1_level1->fn->setBackgroundType(HeartImage1_level1, LE_WIDGET_BACKGROUND_NONE);
    HeartImage1_level1->fn->setImage(HeartImage1_level1, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage1_level1);

    HeartImage2_level1 = leImageWidget_New();
    HeartImage2_level1->fn->setPosition(HeartImage2_level1, 716, 201);
    HeartImage2_level1->fn->setSize(HeartImage2_level1, 66, 50);
    HeartImage2_level1->fn->setBackgroundType(HeartImage2_level1, LE_WIDGET_BACKGROUND_NONE);
    HeartImage2_level1->fn->setImage(HeartImage2_level1, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage2_level1);

    HeartImage3_level1 = leImageWidget_New();
    HeartImage3_level1->fn->setPosition(HeartImage3_level1, 716, 265);
    HeartImage3_level1->fn->setSize(HeartImage3_level1, 66, 50);
    HeartImage3_level1->fn->setBackgroundType(HeartImage3_level1, LE_WIDGET_BACKGROUND_NONE);
    HeartImage3_level1->fn->setImage(HeartImage3_level1, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage3_level1);

    Snake_size_text_1 = leLabelWidget_New();
    Snake_size_text_1->fn->setPosition(Snake_size_text_1, 702, 324);
    Snake_size_text_1->fn->setSize(Snake_size_text_1, 95, 33);
    Snake_size_text_1->fn->setBackgroundType(Snake_size_text_1, LE_WIDGET_BACKGROUND_NONE);
    Snake_size_text_1->fn->setHAlignment(Snake_size_text_1, LE_HALIGN_CENTER);
    Snake_size_text_1->fn->setString(Snake_size_text_1, (leString*)&tableString_Snake_Size_text);
    root0->fn->addChild(root0, (leWidget*)Snake_size_text_1);

    LIfe_text_1 = leLabelWidget_New();
    LIfe_text_1->fn->setPosition(LIfe_text_1, 702, 104);
    LIfe_text_1->fn->setSize(LIfe_text_1, 95, 33);
    LIfe_text_1->fn->setBackgroundType(LIfe_text_1, LE_WIDGET_BACKGROUND_NONE);
    LIfe_text_1->fn->setHAlignment(LIfe_text_1, LE_HALIGN_CENTER);
    LIfe_text_1->fn->setString(LIfe_text_1, (leString*)&tableString_Snake_Lifes_label);
    root0->fn->addChild(root0, (leWidget*)LIfe_text_1);

    Snake_size_value_level1 = leLabelWidget_New();
    Snake_size_value_level1->fn->setPosition(Snake_size_value_level1, 710, 350);
    Snake_size_value_level1->fn->setSize(Snake_size_value_level1, 80, 32);
    Snake_size_value_level1->fn->setBackgroundType(Snake_size_value_level1, LE_WIDGET_BACKGROUND_NONE);
    Snake_size_value_level1->fn->setBorderType(Snake_size_value_level1, LE_WIDGET_BORDER_LINE);
    Snake_size_value_level1->fn->setHAlignment(Snake_size_value_level1, LE_HALIGN_CENTER);
    Snake_size_value_level1->fn->setString(Snake_size_value_level1, (leString*)&tableString_Snake_size_value_level_1);
    root0->fn->addChild(root0, (leWidget*)Snake_size_value_level1);

    GradientWidget0 = leGradientWidget_New();
    GradientWidget0->fn->setPosition(GradientWidget0, 0, 0);
    GradientWidget0->fn->setSize(GradientWidget0, 800, 100);
    GradientWidget0->fn->setScheme(GradientWidget0, &Gradient_scheme);
    GradientWidget0->fn->setDirection(GradientWidget0, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget0);

    ImageWidget0 = leImageWidget_New();
    ImageWidget0->fn->setPosition(ImageWidget0, 4, 3);
    ImageWidget0->fn->setSize(ImageWidget0, 250, 58);
    ImageWidget0->fn->setBackgroundType(ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget0->fn->setImage(ImageWidget0, &MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)ImageWidget0);

    Game_Over_level1 = leLabelWidget_New();
    Game_Over_level1->fn->setPosition(Game_Over_level1, 156, 151);
    Game_Over_level1->fn->setSize(Game_Over_level1, 427, 232);
    Game_Over_level1->fn->setVisible(Game_Over_level1, LE_FALSE);
    Game_Over_level1->fn->setScheme(Game_Over_level1, &Game_Over_scheme);
    Game_Over_level1->fn->setString(Game_Over_level1, (leString*)&tableString_Game_Over_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Over_level1);

    Title_label_game_level_1 = leLabelWidget_New();
    Title_label_game_level_1->fn->setPosition(Title_label_game_level_1, 210, 38);
    Title_label_game_level_1->fn->setSize(Title_label_game_level_1, 384, 53);
    Title_label_game_level_1->fn->setScheme(Title_label_game_level_1, &Title_text_scheme);
    Title_label_game_level_1->fn->setBackgroundType(Title_label_game_level_1, LE_WIDGET_BACKGROUND_NONE);
    Title_label_game_level_1->fn->setString(Title_label_game_level_1, (leString*)&tableString_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)Title_label_game_level_1);

    Game_Won_level1 = leLabelWidget_New();
    Game_Won_level1->fn->setPosition(Game_Won_level1, 156, 151);
    Game_Won_level1->fn->setSize(Game_Won_level1, 427, 232);
    Game_Won_level1->fn->setVisible(Game_Won_level1, LE_FALSE);
    Game_Won_level1->fn->setScheme(Game_Won_level1, &Game_Over_scheme);
    Game_Won_level1->fn->setHAlignment(Game_Won_level1, LE_HALIGN_CENTER);
    Game_Won_level1->fn->setString(Game_Won_level1, (leString*)&tableString_Game_Won_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Won_level1);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Game_Level1()
{
}

void screenHide_Game_Level1()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget2 = NULL;
    PanelWidget3 = NULL;
    HeartImage1_level1 = NULL;
    HeartImage2_level1 = NULL;
    HeartImage3_level1 = NULL;
    Snake_size_text_1 = NULL;
    LIfe_text_1 = NULL;
    Snake_size_value_level1 = NULL;
    GradientWidget0 = NULL;
    ImageWidget0 = NULL;
    Game_Over_level1 = NULL;
    Title_label_game_level_1 = NULL;
    Game_Won_level1 = NULL;

    tableString_Snake_Size_text.fn->destructor(&tableString_Snake_Size_text);
    tableString_Snake_Lifes_label.fn->destructor(&tableString_Snake_Lifes_label);
    tableString_Snake_size_value_level_1.fn->destructor(&tableString_Snake_size_value_level_1);
    tableString_Game_Over_Text.fn->destructor(&tableString_Game_Over_Text);
    tableString_Game_title_label.fn->destructor(&tableString_Game_title_label);
    tableString_Game_Won_Text.fn->destructor(&tableString_Game_Won_Text);
    showing = LE_FALSE;
}

void screenDestroy_Game_Level1()
{

}

leWidget* screenGetRoot_Game_Level1(uint32_t lyrIdx)
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

