#include "AppDelegate.h"
#include "MainMenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto fileUtils = FileUtils::getInstance();
    auto screenSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;
    
    // check which assets the devices requires
    if ( 2048 == screenSize.width || 2048 == screenSize.height ) // retina iPad
    {
        resDirOrders.push_back("ipadhd");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        resDirOrders.push_back("iphonehd6");
        
        glview->setDesignResolutionSize(1536, 2048, ResolutionPolicy::NO_BORDER);
    }
    else if ( 1024 == screenSize.width || 1024 == screenSize.height ) // non retina iPad
    {
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        resDirOrders.push_back("iphonehd6");
        
        glview->setDesignResolutionSize(768, 1024, ResolutionPolicy::NO_BORDER);
    }
    else if ( 1334 == screenSize.width || 1334 == screenSize.height ) // iphone 6
    {
        resDirOrders.push_back("iphonehd6");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(750, 1334, ResolutionPolicy::NO_BORDER);
    }
    else if ( 1136 == screenSize.width || 1136 == screenSize.height ) // retina iPhone (5 and 5S)
    {
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(640, 1136, ResolutionPolicy::NO_BORDER);
    }
    else if ( 960 == screenSize.width || 960 == screenSize.height ) // retina iPhone (4 and 4S)
    {
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(640, 960, ResolutionPolicy::NO_BORDER);
    }
    else // non retina iPhone and Android devices
    {
        if ( 1080 < screenSize.width ) // android devices that have a high resolution
        {
            resDirOrders.push_back("iphonehd");
            resDirOrders.push_back("iphone");
            
            glview->setDesignResolutionSize(640, 960, ResolutionPolicy::NO_BORDER);
        }
        else // non retina iPhone and Android devices with lower resolutions
        {
            resDirOrders.push_back("iphone");
            
            glview->setDesignResolutionSize(320, 480, ResolutionPolicy::NO_BORDER);
        }
    }
    
    fileUtils->setSearchPaths(resDirOrders);

    // create a scene. it's an autorelease object
    auto scene = MainMenu::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
