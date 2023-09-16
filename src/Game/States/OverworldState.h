#pragma once

#include "State.h"
#include "Area.h"
#include "Player.h"
#include "Enemy.h"
#include "Rock.h"
#include "Friend.h"
#include "Boss.h"
#include "OverworldCamera.h"

class OverworldState : public State
{
    private:
        ofImage overworldImage;
        Player *player;
        OverworldCamera *camera;
        Area *area;
        std::vector<Enemy*> enemies;
        Enemy *enemy;
        std::vector<Boss*> bosses;
        Boss *boss;
        Rock *rock;
        Friend *friendly;
        std::vector<Friend *> f;
        bool conversation;
        int timer;
        bool collide;
        
    public:
        OverworldState(Player *player, Area *area);
        Player* getPlayer() { return player;};
        void setEnemy(Enemy *enemy) { this->enemy = enemy;};
        Enemy* getEnemy() { return (Enemy*)enemy;};
        void setBoss(Boss *boss) { this->boss = boss;};
        Boss* getboss() { return boss;};
        Rock* getRock() { return rock; };
        void setFriend(Friend *friendly) { this->friendly = friendly;};
        Friend* getFriend() { return friendly;};
        void loadArea(Area *Area);
        Area* getArea() { return area;};
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};