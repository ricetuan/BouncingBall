#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Constants.h"
#include "Ball.h"
#include "Coin.h"
#include "Rock.h"


class Cannon;
class PassCode;
class Dogi;
class BallExplode;
class ItemBox;

class GameScene : public cocos2d::Node
{
public:
    static GameScene* createWithLevel(int level);
    void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; };

 //   CREATE_FUNC(GameScene);
    
protected:
    bool _isMultiplayer;
    bool initWithLevel(int level);

    void onEnter() override;
    cocos2d::Scene* _physicsScene;
    
    cocos2d::PhysicsWorld* m_world;
    cocos2d::Node* _mainScene;
    int _level;
    //Ball
    cocos2d::Vector<Ball*> _ballsOnState;
    Ball* _ballWaitShooting;
    cocos2d::Sprite* _ballPreview;
    cocos2d::Vector<Ball*> _ballsInBag;

    
    //pointer instance
    Cannon* _cannon;
    Dogi* _dogi;
    cocos2d::Sprite* _edgeSp;
    PassCode* _passCode;
    ItemBox* _itemBox;
    cocos2d::ui::Button* _nextBallHolder;
    
    
    //coin && rock
    cocos2d::Vector<Coin*> _coinOnStage;
    cocos2d::Vector<Rock*> _rocksOnStage;
    
    int _currentScore;
    int _oneStarScore;
    int _twoStarScore;
    int _threeStarScore;

    void update(float dt) override;
    void updateBallPreview();
    bool allBallIsStoped();
    void resetEgde();
    
    void updateScoreLabel(int score);
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void onContactEnd(cocos2d::PhysicsContact &contact);

    void setupTouchHandling();
    void setupContactHandling();
    void setupBall();
    void setupMap();
    
    bool isGameOver();
    bool canUserGetItem();
    void triggerGameOver();
    
    
    //Util Method
    int evaluateStars(int currentScore);
    std::string getConfigFileName();
    void resetAllBallHp();
    void enableAllCoin();
    
    cocos2d::ui::TextBMFont* _scoreLabel;
    GameState _gameState;
    
    void backButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void ballHolderButtonPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    
    void createCoinByPosWhenBallHpIsZero(cocos2d::Vec2 pos);
    void createItemWhenTouchedItemBox(ItemCategory itemCategory);
};


#endif // __HELLOWORLD_SCENE_H__
