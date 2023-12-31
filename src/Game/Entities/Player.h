#pragma once

#include "Entity.h" 
#include "Animation.h"

#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560


class Player : public Entity {
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        vector<char> pressedKeys;
        int health;
        int maxHealth;
        int baseDamage;
        ofImage fightingSprite;
         int fx, fy, fw, fh;
        

    
    public:
        Player(int health, int baseDamage, string fightingpath, int fx, int fy, int fw, int fh);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        int getHealth() { return health; };
        void setHealth(int health) { this->health = health; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
        int getMaxHealth() {return maxHealth; };
        void reverseMovement();
        virtual void renderFighting();
};