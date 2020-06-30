#include "gfx/legato/generated/screen/le_gen_screen_Game_Level2.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget1;
leRectangleWidget* Barrier_upper_left_horizontal;
leRectangleWidget* Barrier_upper_left_vertical;
leRectangleWidget* Barrier_lower_left_horizontal;
leRectangleWidget* Barrier_lower_left_vertical;
leRectangleWidget* Barrier_Upper_right_horizontal;
leRectangleWidget* Barrier_upper_right_vertical;
leRectangleWidget* Barrier_lower_right_horizontal;
leRectangleWidget* Barrier_lower_right_vertical;
leWidget* PanelWidget4;
leImageWidget* HeartImage1_level2;
leImageWidget* HeartImage2_level2;
leImageWidget* HeartImage3_level2;
leLabelWidget* Life_text_2;
leLabelWidget* Snake_size_text_2;
leLabelWidget* Snake_size_value_level2;
leLabelWidget* Game_Over_level2;
leGradientWidget* GradientWidget1;
leImageWidget* ImageWidget3;
leLabelWidget* LabelWidget2;
leLabelWidget* Game_Won_level2;

// string list for this screen
static leTableString tableString_Snake_Lifes_label;
static leTableString tableString_Snake_Size_text;
static leTableString tableString_Snake_size_value_level_2;
static leTableString tableString_Game_Over_Text;
static leTableString tableString_Game_title_label;
static leTableString tableString_Game_Won_Text;

static leBool showing = LE_FALSE;

leResult screenInit_Game_Level2()
{
    return LE_SUCCESS;
}

leResult screenShow_Game_Level2()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Snake_Lifes_label, string_Snake_Lifes_label);
    leTableString_Constructor(&tableString_Snake_Size_text, string_Snake_Size_text);
    leTableString_Constructor(&tableString_Snake_size_value_level_2, string_Snake_size_value_level_2);
    leTableString_Constructor(&tableString_Game_Over_Text, string_Game_Over_Text);
    leTableString_Constructor(&tableString_Game_title_label, string_Game_title_label);
    leTableString_Constructor(&tableString_Game_Won_Text, string_Game_Won_Text);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget1 = leWidget_New();
    PanelWidget1->fn->setPosition(PanelWidget1, 0, 99);
    PanelWidget1->fn->setSize(PanelWidget1, 700, 380);
    PanelWidget1->fn->setScheme(PanelWidget1, &PanelScheme);
    root0->fn->addChild(root0, PanelWidget1);

    Barrier_upper_left_horizontal = leRectangleWidget_New();
    Barrier_upper_left_horizontal->fn->setPosition(Barrier_upper_left_horizontal, 140, 140);
    Barrier_upper_left_horizontal->fn->setSize(Barrier_upper_left_horizontal, 100, 20);
    Barrier_upper_left_horizontal->fn->setScheme(Barrier_upper_left_horizontal, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_upper_left_horizontal);

    Barrier_upper_left_vertical = leRectangleWidget_New();
    Barrier_upper_left_vertical->fn->setPosition(Barrier_upper_left_vertical, 140, 160);
    Barrier_upper_left_vertical->fn->setSize(Barrier_upper_left_vertical, 20, 100);
    Barrier_upper_left_vertical->fn->setScheme(Barrier_upper_left_vertical, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_upper_left_vertical);

    Barrier_lower_left_horizontal = leRectangleWidget_New();
    Barrier_lower_left_horizontal->fn->setPosition(Barrier_lower_left_horizontal, 140, 420);
    Barrier_lower_left_horizontal->fn->setSize(Barrier_lower_left_horizontal, 100, 20);
    Barrier_lower_left_horizontal->fn->setScheme(Barrier_lower_left_horizontal, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_lower_left_horizontal);

    Barrier_lower_left_vertical = leRectangleWidget_New();
    Barrier_lower_left_vertical->fn->setPosition(Barrier_lower_left_vertical, 140, 320);
    Barrier_lower_left_vertical->fn->setSize(Barrier_lower_left_vertical, 20, 100);
    Barrier_lower_left_vertical->fn->setScheme(Barrier_lower_left_vertical, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_lower_left_vertical);

    Barrier_Upper_right_horizontal = leRectangleWidget_New();
    Barrier_Upper_right_horizontal->fn->setPosition(Barrier_Upper_right_horizontal, 440, 140);
    Barrier_Upper_right_horizontal->fn->setSize(Barrier_Upper_right_horizontal, 100, 20);
    Barrier_Upper_right_horizontal->fn->setScheme(Barrier_Upper_right_horizontal, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_Upper_right_horizontal);

    Barrier_upper_right_vertical = leRectangleWidget_New();
    Barrier_upper_right_vertical->fn->setPosition(Barrier_upper_right_vertical, 520, 160);
    Barrier_upper_right_vertical->fn->setSize(Barrier_upper_right_vertical, 20, 100);
    Barrier_upper_right_vertical->fn->setScheme(Barrier_upper_right_vertical, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_upper_right_vertical);

    Barrier_lower_right_horizontal = leRectangleWidget_New();
    Barrier_lower_right_horizontal->fn->setPosition(Barrier_lower_right_horizontal, 440, 420);
    Barrier_lower_right_horizontal->fn->setSize(Barrier_lower_right_horizontal, 100, 20);
    Barrier_lower_right_horizontal->fn->setScheme(Barrier_lower_right_horizontal, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_lower_right_horizontal);

    Barrier_lower_right_vertical = leRectangleWidget_New();
    Barrier_lower_right_vertical->fn->setPosition(Barrier_lower_right_vertical, 520, 320);
    Barrier_lower_right_vertical->fn->setSize(Barrier_lower_right_vertical, 20, 100);
    Barrier_lower_right_vertical->fn->setScheme(Barrier_lower_right_vertical, &Bars_scheme);
    root0->fn->addChild(root0, (leWidget*)Barrier_lower_right_vertical);

    PanelWidget4 = leWidget_New();
    PanelWidget4->fn->setPosition(PanelWidget4, 700, 99);
    PanelWidget4->fn->setSize(PanelWidget4, 100, 380);
    PanelWidget4->fn->setScheme(PanelWidget4, &RightPanelscheme);
    PanelWidget4->fn->setBorderType(PanelWidget4, LE_WIDGET_BORDER_BEVEL);
    root0->fn->addChild(root0, PanelWidget4);

    HeartImage1_level2 = leImageWidget_New();
    HeartImage1_level2->fn->setPosition(HeartImage1_level2, 716, 136);
    HeartImage1_level2->fn->setSize(HeartImage1_level2, 66, 50);
    HeartImage1_level2->fn->setBackgroundType(HeartImage1_level2, LE_WIDGET_BACKGROUND_NONE);
    HeartImage1_level2->fn->setImage(HeartImage1_level2, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage1_level2);

    HeartImage2_level2 = leImageWidget_New();
    HeartImage2_level2->fn->setPosition(HeartImage2_level2, 716, 201);
    HeartImage2_level2->fn->setSize(HeartImage2_level2, 66, 50);
    HeartImage2_level2->fn->setBackgroundType(HeartImage2_level2, LE_WIDGET_BACKGROUND_NONE);
    HeartImage2_level2->fn->setImage(HeartImage2_level2, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage2_level2);

    HeartImage3_level2 = leImageWidget_New();
    HeartImage3_level2->fn->setPosition(HeartImage3_level2, 716, 265);
    HeartImage3_level2->fn->setSize(HeartImage3_level2, 66, 50);
    HeartImage3_level2->fn->setBackgroundType(HeartImage3_level2, LE_WIDGET_BACKGROUND_NONE);
    HeartImage3_level2->fn->setImage(HeartImage3_level2, &Converted_135447_1586215954_M19899_medical_clear);
    root0->fn->addChild(root0, (leWidget*)HeartImage3_level2);

    Life_text_2 = leLabelWidget_New();
    Life_text_2->fn->setPosition(Life_text_2, 702, 104);
    Life_text_2->fn->setSize(Life_text_2, 95, 33);
    Life_text_2->fn->setBackgroundType(Life_text_2, LE_WIDGET_BACKGROUND_NONE);
    Life_text_2->fn->setHAlignment(Life_text_2, LE_HALIGN_CENTER);
    Life_text_2->fn->setString(Life_text_2, (leString*)&tableString_Snake_Lifes_label);
    root0->fn->addChild(root0, (leWidget*)Life_text_2);

    Snake_size_text_2 = leLabelWidget_New();
    Snake_size_text_2->fn->setPosition(Snake_size_text_2, 702, 324);
    Snake_size_text_2->fn->setSize(Snake_size_text_2, 95, 33);
    Snake_size_text_2->fn->setBackgroundType(Snake_size_text_2, LE_WIDGET_BACKGROUND_NONE);
    Snake_size_text_2->fn->setHAlignment(Snake_size_text_2, LE_HALIGN_CENTER);
    Snake_size_text_2->fn->setString(Snake_size_text_2, (leString*)&tableString_Snake_Size_text);
    root0->fn->addChild(root0, (leWidget*)Snake_size_text_2);

    Snake_size_value_level2 = leLabelWidget_New();
    Snake_size_value_level2->fn->setPosition(Snake_size_value_level2, 710, 350);
    Snake_size_value_level2->fn->setSize(Snake_size_value_level2, 80, 32);
    Snake_size_value_level2->fn->setBackgroundType(Snake_size_value_level2, LE_WIDGET_BACKGROUND_NONE);
    Snake_size_value_level2->fn->setBorderType(Snake_size_value_level2, LE_WIDGET_BORDER_LINE);
    Snake_size_value_level2->fn->setHAlignment(Snake_size_value_level2, LE_HALIGN_CENTER);
    Snake_size_value_level2->fn->setString(Snake_size_value_level2, (leString*)&tableString_Snake_size_value_level_2);
    root0->fn->addChild(root0, (leWidget*)Snake_size_value_level2);

    Game_Over_level2 = leLabelWidget_New();
    Game_Over_level2->fn->setPosition(Game_Over_level2, 128, 150);
    Game_Over_level2->fn->setSize(Game_Over_level2, 427, 232);
    Game_Over_level2->fn->setAlphaAmount(Game_Over_level2, 200);
    Game_Over_level2->fn->setVisible(Game_Over_level2, LE_FALSE);
    Game_Over_level2->fn->setScheme(Game_Over_level2, &Game_Over_scheme);
    Game_Over_level2->fn->setBorderType(Game_Over_level2, LE_WIDGET_BORDER_LINE);
    Game_Over_level2->fn->setString(Game_Over_level2, (leString*)&tableString_Game_Over_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Over_level2);

    GradientWidget1 = leGradientWidget_New();
    GradientWidget1->fn->setPosition(GradientWidget1, 0, 0);
    GradientWidget1->fn->setSize(GradientWidget1, 800, 100);
    GradientWidget1->fn->setScheme(GradientWidget1, &Gradient_scheme);
    GradientWidget1->fn->setDirection(GradientWidget1, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget1);

    ImageWidget3 = leImageWidget_New();
    ImageWidget3->fn->setPosition(ImageWidget3, 4, 3);
    ImageWidget3->fn->setSize(ImageWidget3, 250, 58);
    ImageWidget3->fn->setBackgroundType(ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget3->fn->setImage(ImageWidget3, &MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)ImageWidget3);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 210, 38);
    LabelWidget2->fn->setSize(LabelWidget2, 384, 53);
    LabelWidget2->fn->setScheme(LabelWidget2, &Title_text_scheme);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)LabelWidget2);

    Game_Won_level2 = leLabelWidget_New();
    Game_Won_level2->fn->setPosition(Game_Won_level2, 128, 150);
    Game_Won_level2->fn->setSize(Game_Won_level2, 427, 232);
    Game_Won_level2->fn->setVisible(Game_Won_level2, LE_FALSE);
    Game_Won_level2->fn->setScheme(Game_Won_level2, &Game_Over_scheme);
    Game_Won_level2->fn->setHAlignment(Game_Won_level2, LE_HALIGN_CENTER);
    Game_Won_level2->fn->setString(Game_Won_level2, (leString*)&tableString_Game_Won_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Won_level2);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Game_Level2()
{
}

void screenHide_Game_Level2()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget1 = NULL;
    Barrier_upper_left_horizontal = NULL;
    Barrier_upper_left_vertical = NULL;
    Barrier_lower_left_horizontal = NULL;
    Barrier_lower_left_vertical = NULL;
    Barrier_Upper_right_horizontal = NULL;
    Barrier_upper_right_vertical = NULL;
    Barrier_lower_right_horizontal = NULL;
    Barrier_lower_right_vertical = NULL;
    PanelWidget4 = NULL;
    HeartImage1_level2 = NULL;
    HeartImage2_level2 = NULL;
    HeartImage3_level2 = NULL;
    Life_text_2 = NULL;
    Snake_size_text_2 = NULL;
    Snake_size_value_level2 = NULL;
    Game_Over_level2 = NULL;
    GradientWidget1 = NULL;
    ImageWidget3 = NULL;
    LabelWidget2 = NULL;
    Game_Won_level2 = NULL;

    tableString_Snake_Lifes_label.fn->destructor(&tableString_Snake_Lifes_label);
    tableString_Snake_Size_text.fn->destructor(&tableString_Snake_Size_text);
    tableString_Snake_size_value_level_2.fn->destructor(&tableString_Snake_size_value_level_2);
    tableString_Game_Over_Text.fn->destructor(&tableString_Game_Over_Text);
    tableString_Game_title_label.fn->destructor(&tableString_Game_title_label);
    tableString_Game_Won_Text.fn->destructor(&tableString_Game_Won_Text);
    showing = LE_FALSE;
}

void screenDestroy_Game_Level2()
{

}

leWidget* screenGetRoot_Game_Level2(uint32_t lyrIdx)
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

