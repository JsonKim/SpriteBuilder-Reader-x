#ifndef _SB_CCCONTROLBUTTONLOADER_H_
#define _SB_CCCONTROLBUTTONLOADER_H_

#include "CCControlLoader.h"
#include "extensions//GUI/CCControlExtension/CCControlButton.h"

namespace spritebuilder {
    
class CCBControlButton : public cocos2d::extension::ControlButton {
public:
    static CCBControlButton* create();
    
    virtual ~CCBControlButton() {}
    
    void setShadowOffset(const cocos2d::Size & size);
    void setShadowColor(const cocos2d::Color4B & color);
    void setShadowBlurRadius(float blurRadius);
    void enableShadow();
    void needsLayout();
    
private:
    cocos2d::Size _shadowOffset;
    cocos2d::Color4B _shadowColor;
    float _shadowBlurRadius;
};

/* Forward declaration. */
class CCBReader;

class ControlButtonLoader : public ControlLoader {
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~ControlButtonLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        SB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControlButtonLoader, loader);

    protected:
        /**
         * @js NA
         * @lua NA
         */
        virtual cocos2d::extension::ControlButton * createNode(cocos2d::Node * pParent, spritebuilder::CCBReader * ccbReader) {
            cocos2d::extension::ControlButton* pNode = CCBControlButton::create();
            pNode->setZoomOnTouchDown(false);

            return pNode;
        };

        virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);
		virtual void onHandlePropTypeByte(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader);
        virtual void onHandlePropTypeString(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader);
        virtual void onHandlePropTypeFontTTF(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader);
        virtual void onHandlePropTypeFloatScale(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader);
		virtual void onHandlePropTypePosition(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader);
        virtual void onHandlePropTypePoint(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Point pPoint, CCBReader * ccbReader);
        virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);
        virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
        virtual void onHandlePropTypeColor3(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color3B pColor3B, CCBReader * ccbReader);
		virtual void onHandlePropTypeColor4(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Color4B pColor4B, CCBReader * ccbReader);
};


}

#endif
