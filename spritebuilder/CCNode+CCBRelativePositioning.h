#ifndef _SB_CCNODE_RELATIVEPOSITIONING_H__
#define _SB_CCNODE_RELATIVEPOSITIONING_H__

#include "cocos2d.h"
#include "CCBReader.h"

namespace spritebuilder {

extern cocos2d::Point getAbsolutePosition(const cocos2d::Point &pt, CCBReader::PositionType type, const cocos2d::Size &containerSize, const char *propName);

extern void setRelativeScale(cocos2d::Node *node, float scaleX, float scaleY, CCBReader::ScaleType type, const char* propName);

}

#endif // _SB_CCNODE_RELATIVEPOSITIONING_H__
