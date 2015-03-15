//
//  MouseOverMenuItem.cpp
//  MouseOver
//
//  Created by Baris Atamer on 3/15/15.
//
//

#include "MouseOverMenuItem.h"

MouseOverMenuItem::~MouseOverMenuItem()
{
    _eventDispatcher->removeEventListener(mouseListener);
}

MouseOverMenuItem* MouseOverMenuItem::create(const std::string &normalImage, const std::string &selectedImage, const std::string &disabledImage, const ccMenuCallback &callback)
{
    MouseOverMenuItem *ret = new (std::nothrow) MouseOverMenuItem();

    if (ret && ret->initWithNormalImage(normalImage, selectedImage, disabledImage, callback))
    {
        ret->setMouseListener();
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void MouseOverMenuItem::onMouseMove(Event *event)
{
    EventMouse* e = (EventMouse*)event;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 locationInNode = convertToNodeSpace(Vec2(e->getCursorX(), e->getCursorY() + visibleSize.height ));

    Rect r = Rect(0,0, getContentSize().width, getContentSize().height);
    
    // Show selected image if mouse over
    r.containsPoint(locationInNode) ? selected() : unselected();
}

void MouseOverMenuItem::setMouseListener()
{
    // Create a mouse listener
    mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(MouseOverMenuItem::onMouseMove, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}