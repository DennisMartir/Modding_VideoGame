#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
    conversation=false;
    timer=78;
    collide=false;
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::tick()
{
    player->tickOverworld();
    for (unsigned int i = 0; i < area->getEnemies().size()-1; i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            area->getEnemies().at(i)->tickOverworld();
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("Bload");
                setFinished(true);
            }
        }
    }
    
    if(area->getRemainingEnemies() <= 1) 
    {
        for (unsigned int i = 0; i < area->getEnemies().size(); i++)
        {
            if (!area->getEnemies().at(i)->isDead())
            {
                Boss* temp = (Boss*)area->getEnemies().at(i);
                temp->tickOverworld();
                if (player->collides(area->getEnemies().at(i)))
                {
                    setEnemy(area->getEnemies().at(i));
                    setNextState("Bload");
                    setFinished(true);
                }
            }
        }
    }
    

    // if(area->getRemainingEnemies()-1 <= 0) {

    //     for (unsigned int i = 0; i < area->getBoss().size(); i++)
    //     {
    //         if (!area->getBoss().at(i)->isDead())
    //         {
    //             area->getBoss().at(i)->tickOverworld();
    //             if (player->collides(area->getBoss().at(i)))
    //             {
    //                 setEnemy(area->getBoss().at(i));
    //                 setNextState("Bload");
    //                 setFinished(true);
    //             }
    //         }
    //     }
    // }
    for (unsigned int i = 0; i < area->getRocks().size(); i++)
    {
        if (player->collides(area->getRocks().at(i))) 
        {
            player->reverseMovement();
            
        }
    }

    for (unsigned int i = 0; i < area->getFriends().size(); i++)
    {
        area->getFriends().at(i)->tickOverworld();
        if (player->collides(area->getFriends().at(i))) 
        {
            player->reverseMovement();
            collide = true;
        }
    }
    camera->tick();
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();
    ofDrawBitmapString("Enemies Remaining: " + to_string(area->getRemainingEnemies()), 05, 30);
    ofDrawBitmapString("Health: " + to_string(player->getHealth()), 05, 15);
    ofDrawBitmapString(area->getAreaName(), 05, 45);

    for (unsigned int i = 0; i < area->getEnemies().size()-1; i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();
        }
    }

    if(area->getRemainingEnemies() <= 1)
    {
        for (unsigned int i = 0; i < area->getEnemies().size(); i++)
        {
            if (!area->getEnemies().at(i)->isDead())
            {
                Boss* temp = (Boss*)area->getEnemies().at(i);
                int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
                int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
                temp->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
                temp->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
                temp->renderOverworld();
            }
        }
    }

    // if(area->getRemainingEnemies() <= 1)
    // {
    //     for (unsigned int i = 0; i < area->getBoss().size(); i++)
    //     {
    //         if (!area->getBoss().at(i)->isDead())
    //         {
    //             int playerDistanceX = area->getBoss().at(i)->getOX() - camera->getPlayerX();
    //             int playerDistanceY = area->getBoss().at(i)->getOY() - camera->getPlayerY();
    //             area->getBoss().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
    //             area->getBoss().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
    //             area->getBoss().at(i)->renderOverworld();
    //         }
    //     }
    // }

    for (unsigned int i = 0; i < area->getRocks().size(); i++)
    {
        if (!area->getRocks().at(i)->isDead())
        {
            int playerDistanceX = area->getRocks().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getRocks().at(i)->getOY() - camera->getPlayerY();
            area->getRocks().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getRocks().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getRocks().at(i)->renderOverworld();
        }
    }

    for (unsigned int i = 0; i < area->getFriends().size(); i++)
    {

        int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
        area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getFriends().at(i)->renderOverworld();

    }

   if(conversation){
       if(timer>0){
           timer--;
           ofDrawBitmapString("Dame una A por favor",100,160);
       }
       else if(timer==0){
           timer=78;
           conversation=false;
           collide = false;
       }
   }

}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);

    // Kill all enemies
    // if (key == ',') {
    //     for(unsigned int i = 0; i < enemies.size(); i++){
    //         enemies.at(i)->setHealth(0);
    // }

    // }
    if (collide)
            {
             if(key == 'e'||key == 'E')
             {
               conversation=true; 
             }
            }

}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}