#pragma once

#include "Entity.h"
#include "Animation.h"

class Rock: public Entity{
   private:
        int renderX = 950;
        int renderY = 950;
        string entityName;
        string id;
        ofImage sprite;
        bool dead = false;

    public:
        Rock(string id, string entityName, int ox, int oy);
        ~Rock();
        int getOX() { return ox; };
        int getOY() { return oy; };
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
        void reset();
        bool isDead() { return dead;};


};
