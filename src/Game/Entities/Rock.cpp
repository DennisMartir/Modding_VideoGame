#include "Rock.h"

Rock::Rock(string id, string entityName, int ox, int oy) : Entity(ox, oy, 64, 64, "images/objects/rock.png"){
    this->id = id;
    this->entityName = entityName;
    ofImage temp;

    temp.load("images/objects/rock.png");
}

void Rock::tickOverworld(){
    // overworldSprite = getCurrentFrame();
}

void Rock::tickFighting(){

}

void Rock::renderOverworld(){
    overworldSprite.draw(renderX, renderY, ow, oh);
}

Rock::~Rock(){}
