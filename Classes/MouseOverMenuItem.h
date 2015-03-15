//
//  MouseOverMenuItem.h
//  MouseOver
//
//  Created by Baris Atamer on 3/15/15.
//
//

#ifndef __MouseOver__MouseOverMenuItem__
#define __MouseOver__MouseOverMenuItem__

#include "cocos2d.h"

USING_NS_CC;

class MouseOverMenuItem : public MenuItemImage
{
public:

    ~MouseOverMenuItem();
    
    static    MouseOverMenuItem * create(const std::string &normalImage, const std::string &selectedImage, const std::string &disabledImage, const ccMenuCallback& callback);
    
protected:
    EventListenerMouse* mouseListener;
    
private:
    void onMouseMove(Event *event);
    void setMouseListener();
};

#endif /* defined(__MouseOver__MouseOverMenuItem__) */
