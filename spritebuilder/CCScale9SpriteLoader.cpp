#include "CCScale9SpriteLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_CONTENTSIZE "contentSize"
#define PROPERTY_SPRITEFRAME "spriteFrame"
#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_FLIP "flip"
#define PROPERTY_MARGINLEFT "marginLeft"
#define PROPERTY_MARGINTOP "marginTop"
#define PROPERTY_MARGINRIGHT "marginRight"
#define PROPERTY_MARGINBOTTOM "marginBottom"

namespace spritebuilder {
    
Scale9SpriteLoader::Scale9SpriteLoader() :
    NodeLoader(),
    _contentSize(Size::ZERO),
    _marginLeft(0.0f), _marginTop(0.0f), _marginRight(0.0f), _marginBottom(0.0f)
{
        
}

void Scale9SpriteLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0) {
        ((Scale9Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
        
        if (this->_contentSize.equals(Size::ZERO)) {
            this->_contentSize = ((Scale9Sprite *)pNode)->getOriginalSize();
        }
        
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else {
        NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
        ((Scale9Sprite *)pNode)->setColor(pColor3B);
    } else {
        NodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
        ((Scale9Sprite *)pNode)->setOpacity(pByte);
    } else {
        NodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        // TODO Not exported by CocosBuilder yet!
        // ((Scale9Sprite *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
        this->_contentSize = pSize;
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeFloat(Node * pNode, Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_MARGINLEFT) == 0) {
        this->_marginLeft = pFloat;
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else if(strcmp(pPropertyName, PROPERTY_MARGINTOP) == 0) {
        this->_marginTop = pFloat;
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else if(strcmp(pPropertyName, PROPERTY_MARGINRIGHT) == 0) {
        this->_marginRight = pFloat;
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else if(strcmp(pPropertyName, PROPERTY_MARGINBOTTOM) == 0) {
        this->_marginBottom = pFloat;
        this->update(static_cast<Scale9Sprite*>(pNode));
    } else {
        NodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeFlip(Node * pNode, Node * pParent, const char * pPropertyName, bool * pFlip, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FLIP) == 0) {
        // static_cast<Scale9Sprite*>(pNode)->setFlippedX(pFlip[0]);
        // static_cast<Scale9Sprite*>(pNode)->setFlippedY(pFlip[1]);
        log("cocos2d-x Scale9Sprite not support flip.");
    } else {
        NodeLoader::onHandlePropTypeFlip(pNode, pParent, pPropertyName, pFlip, ccbReader);
    }
}
    
void Scale9SpriteLoader::update(Scale9Sprite * pNode) {
    Size originalSize = pNode->getOriginalSize();
    
    float scaleW = this->_contentSize.width / originalSize.width;
    float scaleH = this->_contentSize.height / originalSize.height;

    float marginLeft = this->_contentSize.width * this->_marginLeft / scaleW;
    float marginRight = this->_contentSize.width * this->_marginRight / scaleW;
    float marginTop = this->_contentSize.height * this->_marginTop / scaleH;
    float marginBottom = this->_contentSize.height * this->_marginBottom / scaleH;
    
    pNode->setPreferredSize(this->_contentSize);
    pNode->setInsetLeft(marginLeft);
    pNode->setInsetRight(marginRight);
    pNode->setInsetTop(marginTop);
    pNode->setInsetBottom(marginBottom);
}

}
