#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SdkBase/MainApplication.h"
#include "SdkBase/SdkBase.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    CCLabelTTF *labelcallback = CCLabelTTF::create("callsdk", "Marker Felt", 26);
    CCMenuItemLabel *itemcallback = CCMenuItemLabel::create(labelcallback,this,menu_selector(HelloWorld::callSdk));

    CCLabelTTF *labellogout = CCLabelTTF::create("logout", "Marker Felt", 26);
    CCMenuItemLabel *itemlogout = CCMenuItemLabel::create(labellogout,this,menu_selector(HelloWorld::logout));

    CCLabelTTF *labelpay = CCLabelTTF::create("pay", "Marker Felt", 26);
    CCMenuItemLabel *itempay = CCMenuItemLabel::create(labelpay,this,menu_selector(HelloWorld::pay));

    CCMenu *menu = CCMenu::create(itemcallback, NULL);
    menu->addChild(itemlogout);
    menu->addChild(itempay);
    menu->alignItemsVertically();
    addChild(menu);
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    menu->setPosition(ccp(s.width / 2, 100));

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::logout(CCObject* pSender)
{
    CCLOG("logout");
    MainApplication* instance = MainApplication::getInstance();
    SdkBase *sb = SdkBase::getInstance();
    sb->logout();
    sb->login();
    sb->changeAccount();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::pay(CCObject* pSender)
{
    CCLOG("pay");
    MainApplication* instance = MainApplication::getInstance();
    SdkBase *sb = SdkBase::getInstance();
    sb->pay();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::callSdk(CCObject* pSender)
{
    CCLOG("callSdk");
    MainApplication* instance = MainApplication::getInstance();
    SdkBase *sb = SdkBase::getInstance();
    CCLOG("username:%s, sessionid: %s",sb->getLoginData()->getUsername().c_str(),
    		sb->getLoginData()->getSessionId().c_str());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
