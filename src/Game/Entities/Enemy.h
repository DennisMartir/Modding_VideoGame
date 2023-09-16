#pragma once

#include "Entity.h" 
#include "Animation.h"

class Enemy : public Entity {
    private:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
        int renderX = 1000;
        int renderY = 1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        string id;
        int moveTimer;
        bool dead = false;
        bool isBoss = false;
        string entityName;
        ofImage sprite; 
        int health;
        int maxHealth;
        int baseDamage;
        ofImage fightingSprite;
        int fx, fy, fw, fh;
        


    
    public:
        Enemy(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, int fx, int fy, int fw, int fh);
        Enemy(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, int fx, int fy, int fw, int fh, bool isBoss);
        ~Enemy();
        int getOX() { return ox; };
        int getOY() { return oy; };
        bool isDead() { return dead;};
        void kill() { this->dead = true;};
        void revive() { this->dead = false;};
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void setIsBoss(bool isBoss) { this->isBoss = isBoss;};
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
        int getHealth() { return health; };
        bool getIsBoss() { return isBoss; };
        void setHealth(int health) { this->health = health; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
        int getMaxHealth() {return maxHealth; };
       virtual void renderFighting();
};