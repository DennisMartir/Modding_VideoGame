#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Rock.h"
#include "Friend.h"
#include "Boss.h"
#include "OverworldCamera.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        Area *nextArea;
        string areaName;
        std::vector<Rock*> rocks;
        std::vector<Friend*> f;

    public:
        Area(Area *nextArea, string areaName, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Rock*> rocks, vector<Friend*> f);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        string getAreaName() { return areaName; };
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        void setRocks(std::vector<Rock*> rocks) {this->rocks = rocks; };
        vector<Enemy*> getEnemies() { return enemies;};
        vector<Rock*> getRocks() {return rocks;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        void setFriends(std::vector<Friend*> f) { this->f = f;};
        vector<Friend*> getFriends() { return f;};
        
};