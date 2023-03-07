#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_PanelWidget_0;
leButtonWidget* Screen0_BTNled;
leButtonWidget* Screen0_BTNgpio1;
leButtonWidget* Screen0_BTNgpio2;
leButtonWidget* Screen0_BTNhome;
leLabelWidget* Screen0_LbDev;
leImageWidget* Screen0_ImageWidget_0;
leImageWidget* Screen0_ImageWidget_1;
leLabelWidget* Screen0_LabelWidget_3;
leLabelWidget* Screen0_LabelWidget_2;
leLabelWidget* Screen0_LabelWidget_0;
leLabelWidget* Screen0_LabelWidget_1;
leLabelWidget* Screen0_LbTemp;
leLabelWidget* Screen0_LabelWidget_5;
leLabelWidget* Screen0_LbRSSI;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0(void)
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0(void)
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 432, 432);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_PanelWidget_0 = leWidget_New();
    Screen0_PanelWidget_0->fn->setPosition(Screen0_PanelWidget_0, 0, 0);
    Screen0_PanelWidget_0->fn->setSize(Screen0_PanelWidget_0, 432, 432);
    Screen0_PanelWidget_0->fn->setScheme(Screen0_PanelWidget_0, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_PanelWidget_0);

    Screen0_BTNled = leButtonWidget_New();
    Screen0_BTNled->fn->setPosition(Screen0_BTNled, 166, 320);
    Screen0_BTNled->fn->setSize(Screen0_BTNled, 100, 100);
    Screen0_BTNled->fn->setScheme(Screen0_BTNled, &ButtonScheme);
    Screen0_BTNled->fn->setBackgroundType(Screen0_BTNled, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BTNled->fn->setBorderType(Screen0_BTNled, LE_WIDGET_BORDER_NONE);
    Screen0_BTNled->fn->setPressedImage(Screen0_BTNled, (leImage*)&offcircle);
    Screen0_BTNled->fn->setReleasedImage(Screen0_BTNled, (leImage*)&oncircle);
    Screen0_BTNled->fn->setPressedEventCallback(Screen0_BTNled, event_Screen0_BTNled_OnPressed);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_BTNled);

    Screen0_LabelWidget_3 = leLabelWidget_New();
    Screen0_LabelWidget_3->fn->setPosition(Screen0_LabelWidget_3, 23, 36);
    Screen0_LabelWidget_3->fn->setSize(Screen0_LabelWidget_3, 54, 25);
    Screen0_LabelWidget_3->fn->setEnabled(Screen0_LabelWidget_3, LE_FALSE);
    Screen0_LabelWidget_3->fn->setScheme(Screen0_LabelWidget_3, &RedScheme);
    Screen0_LabelWidget_3->fn->setBackgroundType(Screen0_LabelWidget_3, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_3->fn->setString(Screen0_LabelWidget_3, (leString*)&string_LED);
    Screen0_BTNled->fn->addChild(Screen0_BTNled, (leWidget*)Screen0_LabelWidget_3);

    Screen0_BTNgpio1 = leButtonWidget_New();
    Screen0_BTNgpio1->fn->setPosition(Screen0_BTNgpio1, 58, 254);
    Screen0_BTNgpio1->fn->setSize(Screen0_BTNgpio1, 100, 100);
    Screen0_BTNgpio1->fn->setScheme(Screen0_BTNgpio1, &WhiteScheme);
    Screen0_BTNgpio1->fn->setBackgroundType(Screen0_BTNgpio1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BTNgpio1->fn->setBorderType(Screen0_BTNgpio1, LE_WIDGET_BORDER_NONE);
    Screen0_BTNgpio1->fn->setPressedImage(Screen0_BTNgpio1, (leImage*)&offcircle);
    Screen0_BTNgpio1->fn->setReleasedImage(Screen0_BTNgpio1, (leImage*)&oncircle);
    Screen0_BTNgpio1->fn->setImagePosition(Screen0_BTNgpio1, LE_RELATIVE_POSITION_ABOVE);
    Screen0_BTNgpio1->fn->setImageMargin(Screen0_BTNgpio1, 0);
    Screen0_BTNgpio1->fn->setPressedEventCallback(Screen0_BTNgpio1, event_Screen0_BTNgpio1_OnPressed);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_BTNgpio1);

    Screen0_LabelWidget_2 = leLabelWidget_New();
    Screen0_LabelWidget_2->fn->setPosition(Screen0_LabelWidget_2, 8, 36);
    Screen0_LabelWidget_2->fn->setSize(Screen0_LabelWidget_2, 81, 25);
    Screen0_LabelWidget_2->fn->setEnabled(Screen0_LabelWidget_2, LE_FALSE);
    Screen0_LabelWidget_2->fn->setScheme(Screen0_LabelWidget_2, &RedScheme);
    Screen0_LabelWidget_2->fn->setBackgroundType(Screen0_LabelWidget_2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_2->fn->setString(Screen0_LabelWidget_2, (leString*)&string_GPIO1);
    Screen0_BTNgpio1->fn->addChild(Screen0_BTNgpio1, (leWidget*)Screen0_LabelWidget_2);

    Screen0_BTNgpio2 = leButtonWidget_New();
    Screen0_BTNgpio2->fn->setPosition(Screen0_BTNgpio2, 274, 254);
    Screen0_BTNgpio2->fn->setSize(Screen0_BTNgpio2, 100, 100);
    Screen0_BTNgpio2->fn->setScheme(Screen0_BTNgpio2, &ButtonScheme);
    Screen0_BTNgpio2->fn->setBackgroundType(Screen0_BTNgpio2, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BTNgpio2->fn->setBorderType(Screen0_BTNgpio2, LE_WIDGET_BORDER_NONE);
    Screen0_BTNgpio2->fn->setPressedImage(Screen0_BTNgpio2, (leImage*)&offcircle);
    Screen0_BTNgpio2->fn->setReleasedImage(Screen0_BTNgpio2, (leImage*)&oncircle);
    Screen0_BTNgpio2->fn->setImageMargin(Screen0_BTNgpio2, 0);
    Screen0_BTNgpio2->fn->setPressedEventCallback(Screen0_BTNgpio2, event_Screen0_BTNgpio2_OnPressed);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_BTNgpio2);

    Screen0_LabelWidget_0 = leLabelWidget_New();
    Screen0_LabelWidget_0->fn->setPosition(Screen0_LabelWidget_0, 7, 39);
    Screen0_LabelWidget_0->fn->setSize(Screen0_LabelWidget_0, 87, 25);
    Screen0_LabelWidget_0->fn->setEnabled(Screen0_LabelWidget_0, LE_FALSE);
    Screen0_LabelWidget_0->fn->setScheme(Screen0_LabelWidget_0, &RedScheme);
    Screen0_LabelWidget_0->fn->setBackgroundType(Screen0_LabelWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_0->fn->setString(Screen0_LabelWidget_0, (leString*)&string_GPIO2);
    Screen0_BTNgpio2->fn->addChild(Screen0_BTNgpio2, (leWidget*)Screen0_LabelWidget_0);

    Screen0_BTNhome = leButtonWidget_New();
    Screen0_BTNhome->fn->setPosition(Screen0_BTNhome, 176, 176);
    Screen0_BTNhome->fn->setSize(Screen0_BTNhome, 80, 80);
    Screen0_BTNhome->fn->setBackgroundType(Screen0_BTNhome, LE_WIDGET_BACKGROUND_NONE);
    Screen0_BTNhome->fn->setBorderType(Screen0_BTNhome, LE_WIDGET_BORDER_NONE);
    Screen0_BTNhome->fn->setPressedImage(Screen0_BTNhome, (leImage*)&home);
    Screen0_BTNhome->fn->setReleasedImage(Screen0_BTNhome, (leImage*)&home);
    Screen0_BTNhome->fn->setPressedEventCallback(Screen0_BTNhome, event_Screen0_BTNhome_OnPressed);
    Screen0_BTNhome->fn->setReleasedEventCallback(Screen0_BTNhome, event_Screen0_BTNhome_OnReleased);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_BTNhome);

    Screen0_LbDev = leLabelWidget_New();
    Screen0_LbDev->fn->setPosition(Screen0_LbDev, 166, 35);
    Screen0_LbDev->fn->setSize(Screen0_LbDev, 100, 39);
    Screen0_LbDev->fn->setScheme(Screen0_LbDev, &RedScheme);
    Screen0_LbDev->fn->setBackgroundType(Screen0_LbDev, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LbDev->fn->setString(Screen0_LbDev, (leString*)&string_device);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_LbDev);

    Screen0_ImageWidget_0 = leImageWidget_New();
    Screen0_ImageWidget_0->fn->setPosition(Screen0_ImageWidget_0, 33, 88);
    Screen0_ImageWidget_0->fn->setSize(Screen0_ImageWidget_0, 148, 80);
    Screen0_ImageWidget_0->fn->setBackgroundType(Screen0_ImageWidget_0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_0->fn->setBorderType(Screen0_ImageWidget_0, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_0->fn->setImage(Screen0_ImageWidget_0, (leImage*)&tbox);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_ImageWidget_0);

    Screen0_LabelWidget_1 = leLabelWidget_New();
    Screen0_LabelWidget_1->fn->setPosition(Screen0_LabelWidget_1, 92, 27);
    Screen0_LabelWidget_1->fn->setSize(Screen0_LabelWidget_1, 41, 25);
    Screen0_LabelWidget_1->fn->setScheme(Screen0_LabelWidget_1, &RedScheme);
    Screen0_LabelWidget_1->fn->setBackgroundType(Screen0_LabelWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_1->fn->setString(Screen0_LabelWidget_1, (leString*)&string_Cese);
    Screen0_ImageWidget_0->fn->addChild(Screen0_ImageWidget_0, (leWidget*)Screen0_LabelWidget_1);

    Screen0_LbTemp = leLabelWidget_New();
    Screen0_LbTemp->fn->setPosition(Screen0_LbTemp, 31, 27);
    Screen0_LbTemp->fn->setSize(Screen0_LbTemp, 62, 25);
    Screen0_LbTemp->fn->setScheme(Screen0_LbTemp, &RedScheme);
    Screen0_LbTemp->fn->setBackgroundType(Screen0_LbTemp, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LbTemp->fn->setString(Screen0_LbTemp, (leString*)&string_String23);
    Screen0_ImageWidget_0->fn->addChild(Screen0_ImageWidget_0, (leWidget*)Screen0_LbTemp);

    Screen0_ImageWidget_1 = leImageWidget_New();
    Screen0_ImageWidget_1->fn->setPosition(Screen0_ImageWidget_1, 252, 88);
    Screen0_ImageWidget_1->fn->setSize(Screen0_ImageWidget_1, 148, 80);
    Screen0_ImageWidget_1->fn->setBackgroundType(Screen0_ImageWidget_1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget_1->fn->setBorderType(Screen0_ImageWidget_1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget_1->fn->setImage(Screen0_ImageWidget_1, (leImage*)&tbox);
    Screen0_PanelWidget_0->fn->addChild(Screen0_PanelWidget_0, (leWidget*)Screen0_ImageWidget_1);

    Screen0_LabelWidget_5 = leLabelWidget_New();
    Screen0_LabelWidget_5->fn->setPosition(Screen0_LabelWidget_5, 72, 26);
    Screen0_LabelWidget_5->fn->setSize(Screen0_LabelWidget_5, 67, 31);
    Screen0_LabelWidget_5->fn->setScheme(Screen0_LabelWidget_5, &RedScheme);
    Screen0_LabelWidget_5->fn->setBackgroundType(Screen0_LabelWidget_5, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget_5->fn->setString(Screen0_LabelWidget_5, (leString*)&string_dbm);
    Screen0_ImageWidget_1->fn->addChild(Screen0_ImageWidget_1, (leWidget*)Screen0_LabelWidget_5);

    Screen0_LbRSSI = leLabelWidget_New();
    Screen0_LbRSSI->fn->setPosition(Screen0_LbRSSI, 25, 29);
    Screen0_LbRSSI->fn->setSize(Screen0_LbRSSI, 56, 25);
    Screen0_LbRSSI->fn->setScheme(Screen0_LbRSSI, &RedScheme);
    Screen0_LbRSSI->fn->setBackgroundType(Screen0_LbRSSI, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LbRSSI->fn->setString(Screen0_LbRSSI, (leString*)&string_String55);
    Screen0_ImageWidget_1->fn->addChild(Screen0_ImageWidget_1, (leWidget*)Screen0_LbRSSI);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    Screen0_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen0(void)
{
    Screen0_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_PanelWidget_0 = NULL;
    Screen0_BTNled = NULL;
    Screen0_BTNgpio1 = NULL;
    Screen0_BTNgpio2 = NULL;
    Screen0_BTNhome = NULL;
    Screen0_LbDev = NULL;
    Screen0_ImageWidget_0 = NULL;
    Screen0_ImageWidget_1 = NULL;
    Screen0_LabelWidget_3 = NULL;
    Screen0_LabelWidget_2 = NULL;
    Screen0_LabelWidget_0 = NULL;
    Screen0_LabelWidget_1 = NULL;
    Screen0_LbTemp = NULL;
    Screen0_LabelWidget_5 = NULL;
    Screen0_LbRSSI = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen0(void)
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
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

