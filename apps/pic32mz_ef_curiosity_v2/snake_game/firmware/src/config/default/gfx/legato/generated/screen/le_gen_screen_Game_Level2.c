#include "gfx/legato/generated/screen/le_gen_screen_Game_Level2.h"

// screen member widget declarations
leWidget* root0;

leWidget* Game_Level2_PanelWidget1;
leRectangleWidget* Game_Level2_Barrier_upper_left_horizontal;
leRectangleWidget* Game_Level2_Barrier_upper_left_vertical;
leRectangleWidget* Game_Level2_Barrier_lower_left_horizontal;
leRectangleWidget* Game_Level2_Barrier_lower_left_vertical;
leRectangleWidget* Game_Level2_Barrier_Upper_right_horizontal;
leRectangleWidget* Game_Level2_Barrier_upper_right_vertical;
leRectangleWidget* Game_Level2_Barrier_lower_right_horizontal;
leRectangleWidget* Game_Level2_Barrier_lower_right_vertical;
leWidget* Game_Level2_PanelWidget4;
leImageWidget* Game_Level2_HeartImage1_level2;
leImageWidget* Game_Level2_HeartImage2_level2;
leImageWidget* Game_Level2_HeartImage3_level2;
leLabelWidget* Game_Level2_Life_text_2;
leLabelWidget* Game_Level2_Snake_size_text_2;
leLabelWidget* Game_Level2_Snake_size_value_level2;
leLabelWidget* Game_Level2_Game_Over_level2;
leGradientWidget* Game_Level2_GradientWidget1;
leImageWidget* Game_Level2_ImageWidget3;
leLabelWidget* Game_Level2_LabelWidget2;
leLabelWidget* Game_Level2_Game_Won_level2;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Game_Level2()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Game_Level2()
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

    Game_Level2_PanelWidget1 = leWidget_New();
    Game_Level2_PanelWidget1->fn->setPosition(Game_Level2_PanelWidget1, 0, 99);
    Game_Level2_PanelWidget1->fn->setSize(Game_Level2_PanelWidget1, 700, 380);
    Game_Level2_PanelWidget1->fn->setScheme(Game_Level2_PanelWidget1, &PanelScheme);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_PanelWidget1);

    Game_Level2_Barrier_upper_left_horizontal = leRectangleWidget_New();
    Game_Level2_Barrier_upper_left_horizontal->fn->setPosition(Game_Level2_Barrier_upper_left_horizontal, 140, 140);
    Game_Level2_Barrier_upper_left_horizontal->fn->setSize(Game_Level2_Barrier_upper_left_horizontal, 100, 20);
    Game_Level2_Barrier_upper_left_horizontal->fn->setScheme(Game_Level2_Barrier_upper_left_horizontal, &Bars_scheme);
    Game_Level2_Barrier_upper_left_horizontal->fn->setBorderType(Game_Level2_Barrier_upper_left_horizontal, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_upper_left_horizontal->fn->setThickness(Game_Level2_Barrier_upper_left_horizontal, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_upper_left_horizontal);

    Game_Level2_Barrier_upper_left_vertical = leRectangleWidget_New();
    Game_Level2_Barrier_upper_left_vertical->fn->setPosition(Game_Level2_Barrier_upper_left_vertical, 140, 160);
    Game_Level2_Barrier_upper_left_vertical->fn->setSize(Game_Level2_Barrier_upper_left_vertical, 20, 100);
    Game_Level2_Barrier_upper_left_vertical->fn->setScheme(Game_Level2_Barrier_upper_left_vertical, &Bars_scheme);
    Game_Level2_Barrier_upper_left_vertical->fn->setBorderType(Game_Level2_Barrier_upper_left_vertical, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_upper_left_vertical->fn->setThickness(Game_Level2_Barrier_upper_left_vertical, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_upper_left_vertical);

    Game_Level2_Barrier_lower_left_horizontal = leRectangleWidget_New();
    Game_Level2_Barrier_lower_left_horizontal->fn->setPosition(Game_Level2_Barrier_lower_left_horizontal, 140, 420);
    Game_Level2_Barrier_lower_left_horizontal->fn->setSize(Game_Level2_Barrier_lower_left_horizontal, 100, 20);
    Game_Level2_Barrier_lower_left_horizontal->fn->setScheme(Game_Level2_Barrier_lower_left_horizontal, &Bars_scheme);
    Game_Level2_Barrier_lower_left_horizontal->fn->setBorderType(Game_Level2_Barrier_lower_left_horizontal, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_lower_left_horizontal->fn->setThickness(Game_Level2_Barrier_lower_left_horizontal, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_lower_left_horizontal);

    Game_Level2_Barrier_lower_left_vertical = leRectangleWidget_New();
    Game_Level2_Barrier_lower_left_vertical->fn->setPosition(Game_Level2_Barrier_lower_left_vertical, 140, 320);
    Game_Level2_Barrier_lower_left_vertical->fn->setSize(Game_Level2_Barrier_lower_left_vertical, 20, 100);
    Game_Level2_Barrier_lower_left_vertical->fn->setScheme(Game_Level2_Barrier_lower_left_vertical, &Bars_scheme);
    Game_Level2_Barrier_lower_left_vertical->fn->setBorderType(Game_Level2_Barrier_lower_left_vertical, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_lower_left_vertical->fn->setThickness(Game_Level2_Barrier_lower_left_vertical, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_lower_left_vertical);

    Game_Level2_Barrier_Upper_right_horizontal = leRectangleWidget_New();
    Game_Level2_Barrier_Upper_right_horizontal->fn->setPosition(Game_Level2_Barrier_Upper_right_horizontal, 440, 140);
    Game_Level2_Barrier_Upper_right_horizontal->fn->setSize(Game_Level2_Barrier_Upper_right_horizontal, 100, 20);
    Game_Level2_Barrier_Upper_right_horizontal->fn->setScheme(Game_Level2_Barrier_Upper_right_horizontal, &Bars_scheme);
    Game_Level2_Barrier_Upper_right_horizontal->fn->setBorderType(Game_Level2_Barrier_Upper_right_horizontal, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_Upper_right_horizontal->fn->setThickness(Game_Level2_Barrier_Upper_right_horizontal, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_Upper_right_horizontal);

    Game_Level2_Barrier_upper_right_vertical = leRectangleWidget_New();
    Game_Level2_Barrier_upper_right_vertical->fn->setPosition(Game_Level2_Barrier_upper_right_vertical, 520, 160);
    Game_Level2_Barrier_upper_right_vertical->fn->setSize(Game_Level2_Barrier_upper_right_vertical, 20, 100);
    Game_Level2_Barrier_upper_right_vertical->fn->setScheme(Game_Level2_Barrier_upper_right_vertical, &Bars_scheme);
    Game_Level2_Barrier_upper_right_vertical->fn->setBorderType(Game_Level2_Barrier_upper_right_vertical, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_upper_right_vertical->fn->setThickness(Game_Level2_Barrier_upper_right_vertical, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_upper_right_vertical);

    Game_Level2_Barrier_lower_right_horizontal = leRectangleWidget_New();
    Game_Level2_Barrier_lower_right_horizontal->fn->setPosition(Game_Level2_Barrier_lower_right_horizontal, 440, 420);
    Game_Level2_Barrier_lower_right_horizontal->fn->setSize(Game_Level2_Barrier_lower_right_horizontal, 100, 20);
    Game_Level2_Barrier_lower_right_horizontal->fn->setScheme(Game_Level2_Barrier_lower_right_horizontal, &Bars_scheme);
    Game_Level2_Barrier_lower_right_horizontal->fn->setBorderType(Game_Level2_Barrier_lower_right_horizontal, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_lower_right_horizontal->fn->setThickness(Game_Level2_Barrier_lower_right_horizontal, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_lower_right_horizontal);

    Game_Level2_Barrier_lower_right_vertical = leRectangleWidget_New();
    Game_Level2_Barrier_lower_right_vertical->fn->setPosition(Game_Level2_Barrier_lower_right_vertical, 520, 320);
    Game_Level2_Barrier_lower_right_vertical->fn->setSize(Game_Level2_Barrier_lower_right_vertical, 20, 100);
    Game_Level2_Barrier_lower_right_vertical->fn->setScheme(Game_Level2_Barrier_lower_right_vertical, &Bars_scheme);
    Game_Level2_Barrier_lower_right_vertical->fn->setBorderType(Game_Level2_Barrier_lower_right_vertical, LE_WIDGET_BORDER_NONE);
    Game_Level2_Barrier_lower_right_vertical->fn->setThickness(Game_Level2_Barrier_lower_right_vertical, 2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Barrier_lower_right_vertical);

    Game_Level2_PanelWidget4 = leWidget_New();
    Game_Level2_PanelWidget4->fn->setPosition(Game_Level2_PanelWidget4, 700, 99);
    Game_Level2_PanelWidget4->fn->setSize(Game_Level2_PanelWidget4, 100, 380);
    Game_Level2_PanelWidget4->fn->setScheme(Game_Level2_PanelWidget4, &RightPanelscheme);
    Game_Level2_PanelWidget4->fn->setBorderType(Game_Level2_PanelWidget4, LE_WIDGET_BORDER_BEVEL);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_PanelWidget4);

    Game_Level2_HeartImage1_level2 = leImageWidget_New();
    Game_Level2_HeartImage1_level2->fn->setPosition(Game_Level2_HeartImage1_level2, 716, 136);
    Game_Level2_HeartImage1_level2->fn->setSize(Game_Level2_HeartImage1_level2, 66, 50);
    Game_Level2_HeartImage1_level2->fn->setBackgroundType(Game_Level2_HeartImage1_level2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_HeartImage1_level2->fn->setBorderType(Game_Level2_HeartImage1_level2, LE_WIDGET_BORDER_NONE);
    Game_Level2_HeartImage1_level2->fn->setImage(Game_Level2_HeartImage1_level2, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_HeartImage1_level2);

    Game_Level2_HeartImage2_level2 = leImageWidget_New();
    Game_Level2_HeartImage2_level2->fn->setPosition(Game_Level2_HeartImage2_level2, 716, 201);
    Game_Level2_HeartImage2_level2->fn->setSize(Game_Level2_HeartImage2_level2, 66, 50);
    Game_Level2_HeartImage2_level2->fn->setBackgroundType(Game_Level2_HeartImage2_level2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_HeartImage2_level2->fn->setBorderType(Game_Level2_HeartImage2_level2, LE_WIDGET_BORDER_NONE);
    Game_Level2_HeartImage2_level2->fn->setImage(Game_Level2_HeartImage2_level2, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_HeartImage2_level2);

    Game_Level2_HeartImage3_level2 = leImageWidget_New();
    Game_Level2_HeartImage3_level2->fn->setPosition(Game_Level2_HeartImage3_level2, 716, 265);
    Game_Level2_HeartImage3_level2->fn->setSize(Game_Level2_HeartImage3_level2, 66, 50);
    Game_Level2_HeartImage3_level2->fn->setBackgroundType(Game_Level2_HeartImage3_level2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_HeartImage3_level2->fn->setBorderType(Game_Level2_HeartImage3_level2, LE_WIDGET_BORDER_NONE);
    Game_Level2_HeartImage3_level2->fn->setImage(Game_Level2_HeartImage3_level2, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_HeartImage3_level2);

    Game_Level2_Life_text_2 = leLabelWidget_New();
    Game_Level2_Life_text_2->fn->setPosition(Game_Level2_Life_text_2, 702, 104);
    Game_Level2_Life_text_2->fn->setSize(Game_Level2_Life_text_2, 95, 33);
    Game_Level2_Life_text_2->fn->setBackgroundType(Game_Level2_Life_text_2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_Life_text_2->fn->setHAlignment(Game_Level2_Life_text_2, LE_HALIGN_CENTER);
    Game_Level2_Life_text_2->fn->setString(Game_Level2_Life_text_2, (leString*)&string_Snake_Lifes_label);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Life_text_2);

    Game_Level2_Snake_size_text_2 = leLabelWidget_New();
    Game_Level2_Snake_size_text_2->fn->setPosition(Game_Level2_Snake_size_text_2, 702, 324);
    Game_Level2_Snake_size_text_2->fn->setSize(Game_Level2_Snake_size_text_2, 95, 33);
    Game_Level2_Snake_size_text_2->fn->setBackgroundType(Game_Level2_Snake_size_text_2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_Snake_size_text_2->fn->setHAlignment(Game_Level2_Snake_size_text_2, LE_HALIGN_CENTER);
    Game_Level2_Snake_size_text_2->fn->setString(Game_Level2_Snake_size_text_2, (leString*)&string_Snake_Size_text);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Snake_size_text_2);

    Game_Level2_Snake_size_value_level2 = leLabelWidget_New();
    Game_Level2_Snake_size_value_level2->fn->setPosition(Game_Level2_Snake_size_value_level2, 710, 350);
    Game_Level2_Snake_size_value_level2->fn->setSize(Game_Level2_Snake_size_value_level2, 80, 32);
    Game_Level2_Snake_size_value_level2->fn->setBackgroundType(Game_Level2_Snake_size_value_level2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_Snake_size_value_level2->fn->setBorderType(Game_Level2_Snake_size_value_level2, LE_WIDGET_BORDER_LINE);
    Game_Level2_Snake_size_value_level2->fn->setHAlignment(Game_Level2_Snake_size_value_level2, LE_HALIGN_CENTER);
    Game_Level2_Snake_size_value_level2->fn->setString(Game_Level2_Snake_size_value_level2, (leString*)&string_Snake_size_value_level_2);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Snake_size_value_level2);

    Game_Level2_Game_Over_level2 = leLabelWidget_New();
    Game_Level2_Game_Over_level2->fn->setPosition(Game_Level2_Game_Over_level2, 128, 150);
    Game_Level2_Game_Over_level2->fn->setSize(Game_Level2_Game_Over_level2, 427, 232);
    Game_Level2_Game_Over_level2->fn->setAlphaAmount(Game_Level2_Game_Over_level2, 200);
    Game_Level2_Game_Over_level2->fn->setVisible(Game_Level2_Game_Over_level2, LE_FALSE);
    Game_Level2_Game_Over_level2->fn->setScheme(Game_Level2_Game_Over_level2, &Game_Over_scheme);
    Game_Level2_Game_Over_level2->fn->setBorderType(Game_Level2_Game_Over_level2, LE_WIDGET_BORDER_LINE);
    Game_Level2_Game_Over_level2->fn->setString(Game_Level2_Game_Over_level2, (leString*)&string_Game_Over_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Game_Over_level2);

    Game_Level2_GradientWidget1 = leGradientWidget_New();
    Game_Level2_GradientWidget1->fn->setPosition(Game_Level2_GradientWidget1, 0, 0);
    Game_Level2_GradientWidget1->fn->setSize(Game_Level2_GradientWidget1, 800, 100);
    Game_Level2_GradientWidget1->fn->setScheme(Game_Level2_GradientWidget1, &Gradient_scheme);
    Game_Level2_GradientWidget1->fn->setDirection(Game_Level2_GradientWidget1, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_GradientWidget1);

    Game_Level2_ImageWidget3 = leImageWidget_New();
    Game_Level2_ImageWidget3->fn->setPosition(Game_Level2_ImageWidget3, 4, 3);
    Game_Level2_ImageWidget3->fn->setSize(Game_Level2_ImageWidget3, 361, 84);
    Game_Level2_ImageWidget3->fn->setBackgroundType(Game_Level2_ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_ImageWidget3->fn->setBorderType(Game_Level2_ImageWidget3, LE_WIDGET_BORDER_NONE);
    Game_Level2_ImageWidget3->fn->setImage(Game_Level2_ImageWidget3, (leImage*)&MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_ImageWidget3);

    Game_Level2_LabelWidget2 = leLabelWidget_New();
    Game_Level2_LabelWidget2->fn->setPosition(Game_Level2_LabelWidget2, 210, 54);
    Game_Level2_LabelWidget2->fn->setSize(Game_Level2_LabelWidget2, 384, 53);
    Game_Level2_LabelWidget2->fn->setScheme(Game_Level2_LabelWidget2, &Title_text_scheme);
    Game_Level2_LabelWidget2->fn->setBackgroundType(Game_Level2_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    Game_Level2_LabelWidget2->fn->setString(Game_Level2_LabelWidget2, (leString*)&string_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_LabelWidget2);

    Game_Level2_Game_Won_level2 = leLabelWidget_New();
    Game_Level2_Game_Won_level2->fn->setPosition(Game_Level2_Game_Won_level2, 128, 150);
    Game_Level2_Game_Won_level2->fn->setSize(Game_Level2_Game_Won_level2, 427, 232);
    Game_Level2_Game_Won_level2->fn->setVisible(Game_Level2_Game_Won_level2, LE_FALSE);
    Game_Level2_Game_Won_level2->fn->setScheme(Game_Level2_Game_Won_level2, &Game_Over_scheme);
    Game_Level2_Game_Won_level2->fn->setHAlignment(Game_Level2_Game_Won_level2, LE_HALIGN_CENTER);
    Game_Level2_Game_Won_level2->fn->setString(Game_Level2_Game_Won_level2, (leString*)&string_Game_Won_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Level2_Game_Won_level2);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

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

    Game_Level2_PanelWidget1 = NULL;
    Game_Level2_Barrier_upper_left_horizontal = NULL;
    Game_Level2_Barrier_upper_left_vertical = NULL;
    Game_Level2_Barrier_lower_left_horizontal = NULL;
    Game_Level2_Barrier_lower_left_vertical = NULL;
    Game_Level2_Barrier_Upper_right_horizontal = NULL;
    Game_Level2_Barrier_upper_right_vertical = NULL;
    Game_Level2_Barrier_lower_right_horizontal = NULL;
    Game_Level2_Barrier_lower_right_vertical = NULL;
    Game_Level2_PanelWidget4 = NULL;
    Game_Level2_HeartImage1_level2 = NULL;
    Game_Level2_HeartImage2_level2 = NULL;
    Game_Level2_HeartImage3_level2 = NULL;
    Game_Level2_Life_text_2 = NULL;
    Game_Level2_Snake_size_text_2 = NULL;
    Game_Level2_Snake_size_value_level2 = NULL;
    Game_Level2_Game_Over_level2 = NULL;
    Game_Level2_GradientWidget1 = NULL;
    Game_Level2_ImageWidget3 = NULL;
    Game_Level2_LabelWidget2 = NULL;
    Game_Level2_Game_Won_level2 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Game_Level2()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

