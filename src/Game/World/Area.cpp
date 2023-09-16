#include "Area.h"

Area::Area(Area *nextArea, string areaName, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Rock*> rocks, vector<Friend*> f)
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->areaName = areaName;
    this->rocks = rocks;
    this->f=f;
}

void Area::resetEnemies(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}
