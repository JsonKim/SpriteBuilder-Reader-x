#include "CCControlButtonLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

namespace spritebuilder {;

#define PROPERTY_ZOOMONTOUCHDOWN "zoomOnTouchDown"
#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"
#define PROPERTY_FONTCOLOR "fontColor"
#define PROPERTY_LABELCOLOR_NORMAL "labelColor|Normal"
#define PROPERTY_LABELCOLOR_HIGHLIGHTED "labelColor|Highlighted"
#define PROPERTY_LABELCOLOR_DISABLED "labelColor|Disabled"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_TITLETTF_NORMAL "titleTTF|1"
#define PROPERTY_TITLETTF_HIGHLIGHTED "titleTTF|2"
#define PROPERTY_TITLETTF_DISABLED "titleTTF|3"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_TITLETTFSIZE_NORMAL "titleTTFSize|1"
#define PROPERTY_TITLETTFSIZE_HIGHLIGHTED "titleTTFSize|2"
#define PROPERTY_TITLETTFSIZE_DISABLED "titleTTFSize|3"
#define PROPERTY_LABELOPACITY_SELECTED "labelOpacity|Selected"
#define PROPERTY_LABELOPACITY_DISABLED "labelOpacity|Disabled"
#define PROPERTY_LABELANCHORPOINT "labelAnchorPoint"
#define PROPERTY_PREFEREDSIZE "preferredSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|Normal"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|Highlighted"
#define PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED "backgroundSpriteFrame|Selected"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|Disabled"
#define PROPERTY_BACKGROUNDOPACITY_SELECTED "backgroundOpacity|Selected"
#define PROPERTY_BACKGROUNDOPACITY_DISABLED "backgroundOpacity|Disabled"
#define PROPERTY_HORIZONTAL_PADDING "horizontalPadding"
#define PROPERTY_VERTICAL_PADDING "verticalPadding"
#define PROPERTY_OUTLINEWIDTH "outlineWidth"
#define PROPERTY_OUTLINECOLOR "outlineColor"
#define PROPERTY_SHADOWCOLOR "shadowColor"
#define PROPERTY_SHADOWBLURRADIUS "shadowBlurRadius"
#define PROPERTY_SHADOWOFFSET "shadowOffset"
#define PROPERTY_MAXSIZE "maxSize"

void ControlButtonLoader::onHandlePropTypeCheck(Node * pNode, Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_ZOOMONTOUCHDOWN) == 0) {
        ((ControlButton *)pNode)->setZoomOnTouchDown(pCheck);
    } else {
        ControlLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
	if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_SELECTED) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDOPACITY_DISABLED) == 0) {
		// TODO:
        // ((ControlButton *)pNode)->
	} else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_SELECTED) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_LABELOPACITY_DISABLED) == 0) {
		// TODO:
    } else {
        ControlLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeString(Node * pNode, Node * pParent, const char * pPropertyName, const char * pString, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleForState(String::create(pString), Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleForState(String::create(pString), Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleForState(String::create(pString), Control::State::DISABLED);
    } else {
        ControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeFontTTF(Node * pNode, Node * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLETTF_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleTTFForState(pFontTTF, Control::State::DISABLED);
	} else if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
		// TODO:
    } else {
        ControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeFloatScale(Node * pNode, Node * pParent, const char * pPropertyName, float pFloatScale, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, Control::State::DISABLED);
	} else if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
		// TOOD:
	} else if(strcmp(pPropertyName, PROPERTY_HORIZONTAL_PADDING) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_VERTICAL_PADDING) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_OUTLINEWIDTH) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_SHADOWBLURRADIUS) == 0) {
		// TODO:
    } else {
        ControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypePosition(Node * pNode, Node * pParent, const char * pPropertyName, Point pPosition, CCBReader * ccbReader) {
	if(strcmp(pPropertyName, PROPERTY_SHADOWOFFSET) == 0) {
		// TODO:
    } else {
        ControlLoader::onHandlePropTypePosition(pNode, pParent, pPropertyName, pPosition, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypePoint(Node * pNode, Node * pParent, const char * pPropertyName, Point pPoint, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_LABELANCHORPOINT) == 0) {
        ((ControlButton *)pNode)->setLabelAnchorPoint(pPoint);
    } else {
        ControlLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
        ((ControlButton *)pNode)->setPreferredSize(pSize);
	} else if(strcmp(pPropertyName, PROPERTY_MAXSIZE) == 0) {
		// TODO:
    } else {
        ControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
        if(pSpriteFrame != NULL) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::NORMAL);
        }
	} else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
        if(pSpriteFrame != NULL) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::HIGH_LIGHTED);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED) == 0) {
		// TODO:
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
        if(pSpriteFrame != NULL) {
            ((ControlButton *)pNode)->setBackgroundSpriteFrameForState(pSpriteFrame, Control::State::DISABLED);
        }
    } else {
        ControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_NORMAL) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::NORMAL);
    } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_HIGHLIGHTED) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::HIGH_LIGHTED);
    } else if(strcmp(pPropertyName, PROPERTY_LABELCOLOR_DISABLED) == 0) {
        ((ControlButton *)pNode)->setTitleColorForState(pColor3B, Control::State::DISABLED);
    } else {
        ControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void ControlButtonLoader::onHandlePropTypeColor4(Node * pNode, Node * pParent, const char * pPropertyName, Color4B pColor4B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_FONTCOLOR) == 0) {
		// ((ControlButton *)pNode)->setTitleColorForState(pColor4B, Control::State::NORMAL);
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_OUTLINECOLOR) == 0) {
		// TODO:
	} else if(strcmp(pPropertyName, PROPERTY_SHADOWCOLOR) == 0) {
		// TODO:
	} else {
        ControlLoader::onHandlePropTypeColor4(pNode, pParent, pPropertyName, pColor4B, ccbReader);
    }
}
};