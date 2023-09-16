#pragma once

#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Area.h"
enum Move {rock, paper, scissors, none};
enum Outcome {win, lose, draw};
class BattleState : public State {
    private: 
        ofImage stage;
        Player *player;
        Enemy *enemy;
        Boss *boss;
        Move choice = Move::none;
        Outcome outcome = Outcome::draw;
        int enemyChoice = 0;
        ofSoundPlayer buttonChange;
        ofSoundPlayer buttonSelect;
        ofImage button1;
        ofImage button2;
        ofImage button3;
        ofImage result1;
        ofImage result2;
        ofImage result3;

        int currentButton;
        int currentPlayerHealth;
        int currentEnemyHealth;
        int resultTimer;
        int phase;
        bool canInteract;
    public:
        BattleState(Player *player, Area *area);
        void tick();
        void render();
        void startBattle(Enemy *enemy);
        void renderHealthBar();
        void renderOutcome();
        int getCurrentPlayerHealth(){return currentPlayerHealth; }
        void setEnemy(Enemy *enemy) {this-> enemy = enemy;};
        Enemy* getEnemy() {return enemy;};
        void setStage(ofImage stage) {this-> stage = stage;};
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        void resetPlayer();

};