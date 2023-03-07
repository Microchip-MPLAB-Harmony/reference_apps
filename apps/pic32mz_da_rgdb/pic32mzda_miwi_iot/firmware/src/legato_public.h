/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    legato_public.h

  Summary:
    This header file provides macro definitions for the function wrapper of widget.

  Description:
    This header file provides macro definitions for the function wrapper of widget.
    In terms of make widget function calling much easier, wrap the widget->fn to a
    simple macro function to use.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

#ifndef _LEGATO_PUBLIC_H
#define _LEGATO_PUBLIC_H


#define GET_WIDTH(widget) widget->fn->getWidth(widget)
#define GET_HEIGHT(widget) widget->fn->getHeight(widget)
#define SET_WIDTH(widget,w) widget->fn->setWidth(widget,w)
#define SET_HEIGHT(widget,h) widget->fn->setHeight(widget,h)
#define SET_SIZE(widget,w,h) widget->fn->setSize(widget,w,h)

#define GET_X(widget) widget->fn->getX(widget)
#define GET_Y(widget) widget->fn->getY(widget)
#define SET_X(widget,X) widget->fn->setX(widget, X)
#define SET_Y(widget,Y) widget->fn->setY(widget, Y)
#define SET_POS(widget,X, Y) widget->fn->setPosition(widget,X, Y)

#define SET_APLPHA_ENABLE(widget,val) widget->fn->setAlphaEnabled(widget, val)
#define SET_APLPHA_VALUE(widget,val)  widget->fn->setAlphaAmount(widget, val)

#define SET_VISIBLE(widget,VAL) widget->fn->setVisible(widget,VAL)

#define SET_STRING(widget,str) widget->fn->setString(widget, (leString*)str)

#define SET_IMAGE(widget,img) widget->fn->setImage(widget, (leImage*)img)
#define GET_IMAGE(widget) widget->fn->getImage(widget)
#define GET_RELEASED_IMAGE(widget)    widget->fn->getReleasedImage(widget)

#define TRANSLATE(widget,x,y) widget->fn->translate(widget, x, y)

#define SET_BKG_TYPE(widget,type) widget->fn->setBackgroundType(widget,type )
#define ADD_CHILD(widget,child)   widget->fn->addChild(widget, (leWidget*)child)

#define SET_RELEASED_IMAGE(widget,img) widget->fn->setReleasedImage(widget, (leImage*)img)
#define SET_PRESSED_IMAGE(widget,img) widget->fn->setPressedImage(widget, (leImage*)img)

#define SET_BOARDER(widget,type) widget->fn->setBorderType(widget, type)
#define SET_SCHEME(widget,scheme) widget->fn->setScheme(widget, scheme)

#define INSTALL_EVENT(widget,filter) widget->fn->installEventFilter(widget, filter)

#endif /* _LEGATO_PUBLIC_H */
