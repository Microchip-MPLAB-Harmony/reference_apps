#include "gfx/legato/generated/screen/le_gen_screen_Game_Level1.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Game_Level1_PanelWidget2;
leWidget* Game_Level1_PanelWidget3;
leImageWidget* Game_Level1_HeartImage1_level1;
leImageWidget* Game_Level1_HeartImage2_level1;
leImageWidget* Game_Level1_HeartImage3_level1;
leLabelWidget* Game_Level1_Snake_size_text_1;
leLabelWidget* Game_Level1_LIfe_text_1;
leLabelWidget* Game_Level1_Snake_size_value_level1;
leGradientWidget* Game_Level1_GradientWidget0;
leImageWidget* Game_Level1_ImageWidget0;
leLabelWidget* Game_Level1_Game_Over_level1;
leLabelWidget* Game_Level1_Title_label_game_level_1;
leLabelWidget* Game_Level1_Game_Won_level1;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Game_Level1(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Game_Level1(void)
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

    Game_Level1_PanelWidget2 = leWidget_New();
    Game_Level1_PanelWidget2->fn->setPosition(Game_Level1_PanelWidget2, 0, 99);
    Game_Level1_PanelWidget2->fn->setSize(Game_Level1_PanelWidget2, 700, 380);
    Game_Level1_PanelWidget2->fn->setScheme(Game_Level1_PanelWidget2, &PanelScheme);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_PanelWidget2);

    Game_Level1_PanelWidget3 = leWidget_New();
    Game_Level1_PanelWidget3->fn->setPosition(Game_Level1_PanelWidget3, 700, 99);
    Game_Level1_PanelWidget3->fn->setSize(Game_Level1_PanelWidget3, 100, 380);
    Game_Level1_PanelWidget3->fn->setScheme(Game_Level1_PanelWidget3, &RightPanelscheme);
    Game_Level1_PanelWidget3->fn->setBorderType(Game_Level1_PanelWidget3, LE_WIDGET_BORDER_BEVEL);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_PanelWidget3);

    Game_Level1_HeartImage1_level1 = leImageWidget_New();
    Game_Level1_HeartImage1_level1->fn->setPosition(Game_Level1_HeartImage1_level1, 716, 136);
    Game_Level1_HeartImage1_level1->fn->setSize(Game_Level1_HeartImage1_level1, 66, 50);
    Game_Level1_HeartImage1_level1->fn->setBackgroundType(Game_Level1_HeartImage1_level1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_HeartImage1_level1->fn->setBorderType(Game_Level1_HeartImage1_level1, LE_WIDGET_BORDER_NONE);
    Game_Level1_HeartImage1_level1->fn->setImage(Game_Level1_HeartImage1_level1, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_HeartImage1_level1);

    Game_Level1_HeartImage2_level1 = leImageWidget_New();
    Game_Level1_HeartImage2_level1->fn->setPosition(Game_Level1_HeartImage2_level1, 716, 201);
    Game_Level1_HeartImage2_level1->fn->setSize(Game_Level1_HeartImage2_level1, 66, 50);
    Game_Level1_HeartImage2_level1->fn->setBackgroundType(Game_Level1_HeartImage2_level1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_HeartImage2_level1->fn->setBorderType(Game_Level1_HeartImage2_level1, LE_WIDGET_BORDER_NONE);
    Game_Level1_HeartImage2_level1->fn->setImage(Game_Level1_HeartImage2_level1, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_HeartImage2_level1);

    Game_Level1_HeartImage3_level1 = leImageWidget_New();
    Game_Level1_HeartImage3_level1->fn->setPosition(Game_Level1_HeartImage3_level1, 716, 265);
    Game_Level1_HeartImage3_level1->fn->setSize(Game_Level1_HeartImage3_level1, 66, 50);
    Game_Level1_HeartImage3_level1->fn->setBackgroundType(Game_Level1_HeartImage3_level1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_HeartImage3_level1->fn->setBorderType(Game_Level1_HeartImage3_level1, LE_WIDGET_BORDER_NONE);
    Game_Level1_HeartImage3_level1->fn->setImage(Game_Level1_HeartImage3_level1, (leImage*)&HeartLevel);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_HeartImage3_level1);

    Game_Level1_Snake_size_text_1 = leLabelWidget_New();
    Game_Level1_Snake_size_text_1->fn->setPosition(Game_Level1_Snake_size_text_1, 702, 324);
    Game_Level1_Snake_size_text_1->fn->setSize(Game_Level1_Snake_size_text_1, 95, 33);
    Game_Level1_Snake_size_text_1->fn->setBackgroundType(Game_Level1_Snake_size_text_1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_Snake_size_text_1->fn->setHAlignment(Game_Level1_Snake_size_text_1, LE_HALIGN_CENTER);
    Game_Level1_Snake_size_text_1->fn->setString(Game_Level1_Snake_size_text_1, (leString*)&string_Snake_Size_text);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_Snake_size_text_1);

    Game_Level1_LIfe_text_1 = leLabelWidget_New();
    Game_Level1_LIfe_text_1->fn->setPosition(Game_Level1_LIfe_text_1, 702, 104);
    Game_Level1_LIfe_text_1->fn->setSize(Game_Level1_LIfe_text_1, 95, 33);
    Game_Level1_LIfe_text_1->fn->setBackgroundType(Game_Level1_LIfe_text_1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_LIfe_text_1->fn->setHAlignment(Game_Level1_LIfe_text_1, LE_HALIGN_CENTER);
    Game_Level1_LIfe_text_1->fn->setString(Game_Level1_LIfe_text_1, (leString*)&string_Snake_Lifes_label);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_LIfe_text_1);

    Game_Level1_Snake_size_value_level1 = leLabelWidget_New();
    Game_Level1_Snake_size_value_level1->fn->setPosition(Game_Level1_Snake_size_value_level1, 710, 350);
    Game_Level1_Snake_size_value_level1->fn->setSize(Game_Level1_Snake_size_value_level1, 80, 32);
    Game_Level1_Snake_size_value_level1->fn->setBackgroundType(Game_Level1_Snake_size_value_level1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_Snake_size_value_level1->fn->setBorderType(Game_Level1_Snake_size_value_level1, LE_WIDGET_BORDER_LINE);
    Game_Level1_Snake_size_value_level1->fn->setHAlignment(Game_Level1_Snake_size_value_level1, LE_HALIGN_CENTER);
    Game_Level1_Snake_size_value_level1->fn->setString(Game_Level1_Snake_size_value_level1, (leString*)&string_Snake_size_value_level_1);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_Snake_size_value_level1);

    Game_Level1_GradientWidget0 = leGradientWidget_New();
    Game_Level1_GradientWidget0->fn->setPosition(Game_Level1_GradientWidget0, 0, 0);
    Game_Level1_GradientWidget0->fn->setSize(Game_Level1_GradientWidget0, 800, 100);
    Game_Level1_GradientWidget0->fn->setScheme(Game_Level1_GradientWidget0, &Gradient_scheme);
    Game_Level1_GradientWidget0->fn->setDirection(Game_Level1_GradientWidget0, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_GradientWidget0);

    Game_Level1_ImageWidget0 = leImageWidget_New();
    Game_Level1_ImageWidget0->fn->setPosition(Game_Level1_ImageWidget0, 4, 3);
    Game_Level1_ImageWidget0->fn->setSize(Game_Level1_ImageWidget0, 361, 84);
    Game_Level1_ImageWidget0->fn->setBackgroundType(Game_Level1_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_ImageWidget0->fn->setBorderType(Game_Level1_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Game_Level1_ImageWidget0->fn->setImage(Game_Level1_ImageWidget0, (leImage*)&MicrochipLogoHorizontalWhiteRed);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_ImageWidget0);

    Game_Level1_Game_Over_level1 = leLabelWidget_New();
    Game_Level1_Game_Over_level1->fn->setPosition(Game_Level1_Game_Over_level1, 156, 151);
    Game_Level1_Game_Over_level1->fn->setSize(Game_Level1_Game_Over_level1, 427, 232);
    Game_Level1_Game_Over_level1->fn->setVisible(Game_Level1_Game_Over_level1, LE_FALSE);
    Game_Level1_Game_Over_level1->fn->setScheme(Game_Level1_Game_Over_level1, &Game_Over_scheme);
    Game_Level1_Game_Over_level1->fn->setString(Game_Level1_Game_Over_level1, (leString*)&string_Game_Over_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_Game_Over_level1);

    Game_Level1_Title_label_game_level_1 = leLabelWidget_New();
    Game_Level1_Title_label_game_level_1->fn->setPosition(Game_Level1_Title_label_game_level_1, 210, 54);
    Game_Level1_Title_label_game_level_1->fn->setSize(Game_Level1_Title_label_game_level_1, 384, 53);
    Game_Level1_Title_label_game_level_1->fn->setScheme(Game_Level1_Title_label_game_level_1, &Title_text_scheme);
    Game_Level1_Title_label_game_level_1->fn->setBackgroundType(Game_Level1_Title_label_game_level_1, LE_WIDGET_BACKGROUND_NONE);
    Game_Level1_Title_label_game_level_1->fn->setString(Game_Level1_Title_label_game_level_1, (leString*)&string_Game_title_label);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_Title_label_game_level_1);

    Game_Level1_Game_Won_level1 = leLabelWidget_New();
    Game_Level1_Game_Won_level1->fn->setPosition(Game_Level1_Game_Won_level1, 156, 151);
    Game_Level1_Game_Won_level1->fn->setSize(Game_Level1_Game_Won_level1, 427, 232);
    Game_Level1_Game_Won_level1->fn->setVisible(Game_Level1_Game_Won_level1, LE_FALSE);
    Game_Level1_Game_Won_level1->fn->setScheme(Game_Level1_Game_Won_level1, &Game_Over_scheme);
    Game_Level1_Game_Won_level1->fn->setHAlignment(Game_Level1_Game_Won_level1, LE_HALIGN_CENTER);
    Game_Level1_Game_Won_level1->fn->setString(Game_Level1_Game_Won_level1, (leString*)&string_Game_Won_Text);
    root0->fn->addChild(root0, (leWidget*)Game_Level1_Game_Won_level1);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Game_Level1(void)
{
    root0->fn->setSize(root0, root0->parent->rect.width, root0->parent->rect.height);
}

void screenHide_Game_Level1(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Game_Level1_PanelWidget2 = NULL;
    Game_Level1_PanelWidget3 = NULL;
    Game_Level1_HeartImage1_level1 = NULL;
    Game_Level1_HeartImage2_level1 = NULL;
    Game_Level1_HeartImage3_level1 = NULL;
    Game_Level1_Snake_size_text_1 = NULL;
    Game_Level1_LIfe_text_1 = NULL;
    Game_Level1_Snake_size_value_level1 = NULL;
    Game_Level1_GradientWidget0 = NULL;
    Game_Level1_ImageWidget0 = NULL;
    Game_Level1_Game_Over_level1 = NULL;
    Game_Level1_Title_label_game_level_1 = NULL;
    Game_Level1_Game_Won_level1 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Game_Level1(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

