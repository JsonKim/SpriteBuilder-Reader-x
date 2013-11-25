#ifndef _SB_CCSLIDERLOADER_H_
#define _SB_CCSLIDERLOADER_H_

#include "CCControlLoader.h"
#include "extensions//GUI/CCControlExtension/CCControlSlider.h"

namespace spritebuilder {

/* Forward declaration. */
class CCBReader;

class SliderLoader : public ControlLoader {
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~SliderLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    SB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SliderLoader, loader);

protected:
    virtual cocos2d::extension::ControlSlider * createNode(cocos2d::Node * pParent, spritebuilder::CCBReader * ccbReader) {
        auto pRet = cocos2d::extension::ControlSlider::create(cocos2d::Sprite::create(), cocos2d::Sprite::create(), cocos2d::Sprite::create());
        
        return pRet;
    }

    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSize(cocos2d::Node * pNode, cocos2d::Node * pParent, const char* pPropertyName, cocos2d::Size pSize, CCBReader * ccbReader);    
    /**
     * @js NA
     * @lua NA
     */
    virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, CCBReader * ccbReader);
};

}

#endif
