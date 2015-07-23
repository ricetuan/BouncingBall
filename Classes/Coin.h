//
//  Coin.h
//  BouncingBall
//
//  Created by Liang Fan on 7/23/15.
//
//

#ifndef __BouncingBall__Coin__
#define __BouncingBall__Coin__

#include "cocos2d.h"

class Coin : public cocos2d::Sprite
{
public:
    CREATE_FUNC(Coin);
    void runGetCoinAnimation();
private:
    bool init() override;
    cocos2d::Spawn* _action;
    
};
#endif /* defined(__BouncingBall__Coin__) */