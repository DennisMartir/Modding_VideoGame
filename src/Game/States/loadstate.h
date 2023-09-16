#pragma once

#include "State.h"
#include "Player.h"
#include "Enemy.h"


class LoadingState : public State
{
    private:
        ofImage lImage;
        
    public:
         LoadingState();
        void tick();
        void render();
        void reset();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        int timer;
    
};