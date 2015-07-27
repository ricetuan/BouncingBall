//
//  JSONPacker.h
//  BouncingBall
//
//  Created by Liang Fan on 7/16/15.
//
//

#ifndef __BouncingBall__JSONPacker__
#define __BouncingBall__JSONPacker__

#include "cocos2d.h"
#include "Constants.h"

namespace JSONPacker
{
    struct BallConfig
    {
        cocos2d::Vec2 pos;
        std::string color;
    };
    
    
    struct StarConfig
    {
        int oneStar;
        int twoStar;
        int threeStar;
    };
    
    struct MapState
    {
        std::vector<BallConfig> ballsOnStage;
        std::vector<std::string> ballsInBag;
        std::vector<cocos2d::Vec2> rocks;
        std::vector<cocos2d::Vec2> coins;
        std::string passCode;
        StarConfig starConfig;
    };
    
    struct MultiSyncData
    {
        MultiplayState multiplayState;
        float angle;
        float speed;
        std::string deviceName;
    };

    //TODO: improve this speed
    const MapState unpackMapStateJSON(std::string json);
    
    std::string packMultiSyncDataJSON(MultiSyncData multiSyncData);
    MultiSyncData unpackMultiSyncDataJSON(std::string json);
}


#endif /* defined(__BouncingBall__JSONPacker__) */
