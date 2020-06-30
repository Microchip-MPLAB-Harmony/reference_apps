#include "gfx/legato/generated/screen/le_gen_screen_Game.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget1;
leRectangleWidget* RectangleWidget2;
leRectangleWidget* RectangleWidget0;
leRectangleWidget* RectangleWidget1;
leRectangleWidget* RectangleWidget3;
leRectangleWidget* RectangleWidget4;
leRectangleWidget* RectangleWidget5;
leRectangleWidget* RectangleWidget6;
leRectangleWidget* RectangleWidget7;
leRectangleWidget* RectangleWidget8;


static leBool showing = LE_FALSE;

leResult screenInit_Game()
{
    return LE_SUCCESS;
}

leResult screenShow_Game()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget1 = leWidget_New();
    PanelWidget1->fn->setPosition(PanelWidget1, 0, 0);
    PanelWidget1->fn->setSize(PanelWidget1, 800, 480);
    PanelWidget1->fn->setScheme(PanelWidget1, &PanelScheme);
    root0->fn->addChild(root0, PanelWidget1);

    RectangleWidget2 = leRectangleWidget_New();
    RectangleWidget2->fn->setPosition(RectangleWidget2, 387, 235);
    RectangleWidget2->fn->setSize(RectangleWidget2, 20, 20);
    RectangleWidget2->fn->setScheme(RectangleWidget2, &SnakePart_sheme);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget2);

    RectangleWidget0 = leRectangleWidget_New();
    RectangleWidget0->fn->setPosition(RectangleWidget0, 200, 100);
    RectangleWidget0->fn->setSize(RectangleWidget0, 100, 20);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget0);

    RectangleWidget1 = leRectangleWidget_New();
    RectangleWidget1->fn->setPosition(RectangleWidget1, 200, 120);
    RectangleWidget1->fn->setSize(RectangleWidget1, 20, 100);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget1);

    RectangleWidget3 = leRectangleWidget_New();
    RectangleWidget3->fn->setPosition(RectangleWidget3, 200, 379);
    RectangleWidget3->fn->setSize(RectangleWidget3, 100, 20);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget3);

    RectangleWidget4 = leRectangleWidget_New();
    RectangleWidget4->fn->setPosition(RectangleWidget4, 200, 279);
    RectangleWidget4->fn->setSize(RectangleWidget4, 20, 100);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget4);

    RectangleWidget5 = leRectangleWidget_New();
    RectangleWidget5->fn->setPosition(RectangleWidget5, 499, 100);
    RectangleWidget5->fn->setSize(RectangleWidget5, 100, 20);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget5);

    RectangleWidget6 = leRectangleWidget_New();
    RectangleWidget6->fn->setPosition(RectangleWidget6, 579, 120);
    RectangleWidget6->fn->setSize(RectangleWidget6, 20, 100);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget6);

    RectangleWidget7 = leRectangleWidget_New();
    RectangleWidget7->fn->setPosition(RectangleWidget7, 499, 379);
    RectangleWidget7->fn->setSize(RectangleWidget7, 100, 20);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget7);

    RectangleWidget8 = leRectangleWidget_New();
    RectangleWidget8->fn->setPosition(RectangleWidget8, 579, 279);
    RectangleWidget8->fn->setSize(RectangleWidget8, 20, 100);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget8);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Game()
{
}

void screenHide_Game()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget1 = NULL;
    RectangleWidget2 = NULL;
    RectangleWidget0 = NULL;
    RectangleWidget1 = NULL;
    RectangleWidget3 = NULL;
    RectangleWidget4 = NULL;
    RectangleWidget5 = NULL;
    RectangleWidget6 = NULL;
    RectangleWidget7 = NULL;
    RectangleWidget8 = NULL;
    showing = LE_FALSE;
}

void screenDestroy_Game()
{

}

leWidget* screenGetRoot_Game(uint32_t lyrIdx)
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

