#include "HelloWorldScene.h"
#include "MouseOverMenuItem.h"

USING_NS_CC;

#define winSize Director::getInstance()->getWinSize()

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


bool HelloWorld::init()
{
    if ( !Layer::init() ) return false;
    
    auto button = MouseOverMenuItem::create("CloseNormal.png", "CloseSelected.png", "", [](Ref* ref){
        // do anything if clicking
        log("click!");
    });
    
    button->setPosition(Vec2(winSize.width*.5, winSize.height*.5) );
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(button, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    log("Close callback");
}
