#pragma once

#include "Entity.h" 
#include "Animation.h"
#define OXDIMESION 2688
#define OYDIMESION 2560


class Friend : public Entity {
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
        string entityName;
        ofImage sprite; 

    public:
        Friend(string id, string entityName, int ox, int oy);
        ~Friend();
        int getOX() { return ox; };
        int getOY() { return oy; };
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
};