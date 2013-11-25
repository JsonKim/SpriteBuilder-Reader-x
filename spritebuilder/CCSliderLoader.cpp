#include "CCSliderLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_PREFERREDSIZE "preferredSize"
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|Normal"
#define PROPERTY_HANDLESPRITEFRAME_NORMAL "handleSpriteFrame|Normal"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|Highlighted"
#define PROPERTY_HANDLESPRITEFRAME_HIGHLIGHTED "handleSpriteFrame|Highlighted"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|Disabled"
#define PROPERTY_HANDLESPRITEFRAME_DISABLED "handleSpriteFrame|Disabled"


namespace spritebuilder {

void SliderLoader::onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_PREFERREDSIZE) == 0) {
        ((ControlSlider*)pNode)->setContentSize(pSize);
    }
    else {
        ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void SliderLoader::onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader)
{
    if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
        ((ControlSlider*)pNode)->setBackgroundSprite(cocos2d::Sprite::createWithSpriteFrame(pSpriteFrame));
    }
    else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_NORMAL) == 0) {
    }
    else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
    }
    else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_HIGHLIGHTED) == 0) {
    }
    else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
    }
    else if(strcmp(pPropertyName, PROPERTY_HANDLESPRITEFRAME_DISABLED) == 0) {
    }
    else {
        ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

}