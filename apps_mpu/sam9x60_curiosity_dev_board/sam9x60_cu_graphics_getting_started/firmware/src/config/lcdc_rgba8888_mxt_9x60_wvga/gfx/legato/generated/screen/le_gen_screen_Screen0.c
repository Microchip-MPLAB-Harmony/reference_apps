#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
static leWidget* root0;

leWidget* Screen0_BackgroundPanel;
leImageWidget* Screen0_mchpLogo;
leImageWidget* Screen0_mhgsLogo;
leLabelWidget* Screen0_fastLabel;
leLabelWidget* Screen0_easyLabel;
leLabelWidget* Screen0_smartLabel;
leButtonWidget* Screen0_qsButton;

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
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_BackgroundPanel = leWidget_New();
    Screen0_BackgroundPanel->fn->setPosition(Screen0_BackgroundPanel, 0, 0);
    Screen0_BackgroundPanel->fn->setSize(Screen0_BackgroundPanel, 800, 480);
    Screen0_BackgroundPanel->fn->setScheme(Screen0_BackgroundPanel, &WhiteScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_BackgroundPanel);

    Screen0_mchpLogo = leImageWidget_New();
    Screen0_mchpLogo->fn->setPosition(Screen0_mchpLogo, 5, 5);
    Screen0_mchpLogo->fn->setSize(Screen0_mchpLogo, 120, 28);
    Screen0_mchpLogo->fn->setBackgroundType(Screen0_mchpLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mchpLogo->fn->setBorderType(Screen0_mchpLogo, LE_WIDGET_BORDER_NONE);
    Screen0_mchpLogo->fn->setImage(Screen0_mchpLogo, (leImage*)&mchpLogo_small);
    root0->fn->addChild(root0, (leWidget*)Screen0_mchpLogo);

    Screen0_mhgsLogo = leImageWidget_New();
    Screen0_mhgsLogo->fn->setPosition(Screen0_mhgsLogo, 30, 60);
    Screen0_mhgsLogo->fn->setSize(Screen0_mhgsLogo, 180, 169);
    Screen0_mhgsLogo->fn->setBackgroundType(Screen0_mhgsLogo, LE_WIDGET_BACKGROUND_NONE);
    Screen0_mhgsLogo->fn->setBorderType(Screen0_mhgsLogo, LE_WIDGET_BORDER_NONE);
    Screen0_mhgsLogo->fn->setImage(Screen0_mhgsLogo, (leImage*)&MHGS_logo_smaller);
    root0->fn->addChild(root0, (leWidget*)Screen0_mhgsLogo);

    Screen0_fastLabel = leLabelWidget_New();
    Screen0_fastLabel->fn->setPosition(Screen0_fastLabel, 225, 87);
    Screen0_fastLabel->fn->setSize(Screen0_fastLabel, 65, 40);
    Screen0_fastLabel->fn->setScheme(Screen0_fastLabel, &RedScheme);
    Screen0_fastLabel->fn->setBackgroundType(Screen0_fastLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_fastLabel->fn->setString(Screen0_fastLabel, (leString*)&string_Fast);
    root0->fn->addChild(root0, (leWidget*)Screen0_fastLabel);

    Screen0_easyLabel = leLabelWidget_New();
    Screen0_easyLabel->fn->setPosition(Screen0_easyLabel, 300, 87);
    Screen0_easyLabel->fn->setSize(Screen0_easyLabel, 70, 40);
    Screen0_easyLabel->fn->setScheme(Screen0_easyLabel, &GreenScheme);
    Screen0_easyLabel->fn->setBackgroundType(Screen0_easyLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_easyLabel->fn->setString(Screen0_easyLabel, (leString*)&string_Easy);
    root0->fn->addChild(root0, (leWidget*)Screen0_easyLabel);

    Screen0_smartLabel = leLabelWidget_New();
    Screen0_smartLabel->fn->setPosition(Screen0_smartLabel, 375, 87);
    Screen0_smartLabel->fn->setSize(Screen0_smartLabel, 100, 40);
    Screen0_smartLabel->fn->setScheme(Screen0_smartLabel, &BlueScheme);
    Screen0_smartLabel->fn->setBackgroundType(Screen0_smartLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_smartLabel->fn->setString(Screen0_smartLabel, (leString*)&string_Smart);
    root0->fn->addChild(root0, (leWidget*)Screen0_smartLabel);

    Screen0_qsButton = leButtonWidget_New();
    Screen0_qsButton->fn->setPosition(Screen0_qsButton, 256, 142);
    Screen0_qsButton->fn->setSize(Screen0_qsButton, 160, 74);
    Screen0_qsButton->fn->setBackgroundType(Screen0_qsButton, LE_WIDGET_BACKGROUND_NONE);
    Screen0_qsButton->fn->setBorderType(Screen0_qsButton, LE_WIDGET_BORDER_NONE);
    Screen0_qsButton->fn->setPressedImage(Screen0_qsButton, (leImage*)&QuickstartDown_WQVGA);
    Screen0_qsButton->fn->setReleasedImage(Screen0_qsButton, (leImage*)&QuickstartUp_WQVGA);
    root0->fn->addChild(root0, (leWidget*)Screen0_qsButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0(void)
{
    root0->fn->setSize(root0, root0->rect.width, root0->rect.height);
}

void screenHide_Screen0(void)
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_BackgroundPanel = NULL;
    Screen0_mchpLogo = NULL;
    Screen0_mhgsLogo = NULL;
    Screen0_fastLabel = NULL;
    Screen0_easyLabel = NULL;
    Screen0_smartLabel = NULL;
    Screen0_qsButton = NULL;


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

