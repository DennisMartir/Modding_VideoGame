#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetWindowTitle("PA2");
	setupAreas();
	// Declaration and Initialization of States
	player = new Player(100, 6,"images/entities/player/fightingframes/player-f1.png", 64,164,192,192);
	titleState = new TitleState();
	overworldState = new OverworldState(player, currentArea);
	battleState = new BattleState(player, currentArea);
	winState = new WinState();
	endGameState = new EndGameState();
	loadingState = new LoadingState();
	bloadingState= new bLoadingState();
    
	// Initial State
	currentState = titleState;
	paused=true;
	counter=0;
}

//--------------------------------------------------------------
void ofApp::setupAreas()
{
	//each area is 672 pixels wide and 640 pixels high, with 10 and 8 pixels of space between the player and the edge of the map respectively
	//each in-game pixel is 4 * 1 screen pixel

	vector<Enemy *> enemies2;
	vector<Rock*> rocks2;
	vector<Friend *>f2;
	// vector<Boss*> boss2;
	ofPoint entrancePosition2(4 * 110, 4 * 116);
	Enemy *area2Enemy1 = new Enemy("21", 30, 6, "enemy2", 4 * 120, 4 * 342,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Enemy *area2Enemy2 = new Enemy("22", 30, 6, "enemy2", 4 * 254, 4 * 130,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Enemy *area2Enemy3 = new Enemy("23", 30, 6, "enemy2", 4 * 542, 4 * 124,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Enemy *area2Enemy4 = new Enemy("24", 30, 6, "enemy2", 4 * 532, 4 * 368,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Enemy *area2Enemy5 = new Enemy("25", 30, 6, "enemy2", 4 * 266, 4 * 312,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Enemy *area2Enemy6 = new Enemy("26", 30, 6, "enemy2", 4 * 194, 4 * 532,"images/entities/enemy1/fightingframes/enemy2-f1.png", 400,164,192,192);
	Boss *area2Boss1 = new Boss("28", 30, 6, "enemy4", 4 * 400, 4 * 220,"images/entities/enemy4/fightingframes/enemy4-f1.png", 400,164,192,192);
	Rock *area2Rock1 = new Rock("44", "rock2", 4 * 164, 4 * 88);
	Rock *area2Rock2 = new Rock("45", "rock2", 4 * 244, 4 * 160);
	Rock *area2Rock3 = new Rock("46", "rock2", 4 * 368, 4 * 108);
	Rock *area2Rock4 = new Rock("47", "rock2", 4 * 364, 4 * 230);
	Rock *area2Rock5 = new Rock("48", "rock2", 4 * 92, 4 * 88);
	Rock *area2Rock6 = new Rock("49", "rock2", 4 * 380, 4 * 360);
	Rock *area2Rock7 = new Rock("50", "rock2", 4 * 482, 4 * 420);
	Friend *area2friend1= new Friend("27","enemy1",4*180, 4*200);
	enemies2.push_back(area2Enemy1);
	enemies2.push_back(area2Enemy2);
	enemies2.push_back(area2Enemy3);
	enemies2.push_back(area2Enemy4);
	enemies2.push_back(area2Enemy5);
	enemies2.push_back(area2Enemy6);
	enemies2.push_back(area2Boss1);
	rocks2.push_back(area2Rock1);
	rocks2.push_back(area2Rock2);
	rocks2.push_back(area2Rock3);
	rocks2.push_back(area2Rock4);
	rocks2.push_back(area2Rock5);
	rocks2.push_back(area2Rock6);
	rocks2.push_back(area2Rock7);
	f2.push_back(area2friend1);
	area2 = new Area(NULL, "Area 2: Ice Cave", "images/areas/area2.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition2, enemies2, rocks2, f2); 
	vector<Enemy *> enemies1;
	vector<Rock *> rocks1;
	vector<Friend *> f1;
	// vector<Boss *> boss1;
	ofPoint entrancePosition1(4 * 414, 4 * 566);
	Enemy *area1Enemy1 = new Enemy("11", 20, 4, "enemy1", 4 * 480, 4 * 432,"images/entities/enemy1/fightingframes/enemy1-f1.png", 400,164,192,192);
	Enemy *area1Enemy2 = new Enemy("12", 20, 4, "enemy1", 4 * 225, 4 * 178,"images/entities/enemy1/fightingframes/enemy1-f1.png", 400,164,192,192);
	Enemy *area1Enemy3 = new Enemy("13", 20, 4, "enemy1", 4 * 420, 4 * 178,"images/entities/enemy1/fightingframes/enemy1-f1.png", 400,164,192,192);
	Boss *area1Boss1 = new Boss("27", 30, 6, "enemy4", 4 * 166, 4 * 164,"images/entities/enemy4/fightingframes/enemy4-f1.png", 400,164,192,192);
	Rock *area1Rock1 = new Rock("37", "rock1", 4 * 432, 4 * 480);
	Rock *area1Rock2 = new Rock("38", "rock1", 4 * 196, 4 * 406);
	Rock *area1Rock3 = new Rock("39", "rock1", 4 * 464, 4 * 272);
	Rock *area1Rock4 = new Rock("40", "rock1", 4 * 146, 4 * 164);
	Rock *area1Rock5 = new Rock("41", "rock1", 4 * 312, 4 * 162);
	Rock *area1Rock6 = new Rock("42", "rock1", 4 * 468, 4 * 272);
	Rock *area1Rock7 = new Rock("43", "rock1", 4 * 486, 4 * 186);
	Friend *area1friend1= new Friend("14", "enemy2", 4*500, 4*320);
	enemies1.push_back(area1Enemy1);
	enemies1.push_back(area1Enemy2);
	enemies1.push_back(area1Enemy3);
	rocks1.push_back(area1Rock1);
	rocks1.push_back(area1Rock2);
	rocks1.push_back(area1Rock3);
	rocks1.push_back(area1Rock4);
	rocks1.push_back(area1Rock5);
	rocks1.push_back(area1Rock6);
	rocks1.push_back(area1Rock7);
	f1.push_back(area1friend1);
	enemies1.push_back(area1Boss1);
	area1 = new Area(area2, "Area 1: Forest", "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, rocks1, f1);
	currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if(paused){
	if (currentState != nullptr)
	{
		currentState->tick();
		if (currentState->hasFinished())
		{
			currentState->toggleMusic();
			if (currentState->getNextState() == "Title")
			{
				endGameState->setWin(false);
				area1->resetEnemies();
				area2->resetEnemies();
				currentArea = area1;
				battleState->resetPlayer();
				battleState->setStage(currentArea->getStage());
				overworldState->loadArea(currentArea);
				currentState = titleState;
			}
			else if(currentState->getNextState() == "Loading")
			{
				currentState= loadingState;
		
			}
			else if (currentState->getNextState() == "Overworld")
			{
			
				currentState = overworldState;
			}
			else if(currentState->getNextState() == "Bload")
			{
				currentState = bloadingState;
			}
			else if (currentState->getNextState() == "Battle")
			{
				battleState->startBattle(overworldState->getEnemy()); 

				currentState = battleState;
			}
			else if (currentState->getNextState() == "Win")
			{
				overworldState->getEnemy()->kill();

				currentState=loadingState;
				if (currentArea->getRemainingEnemies() == 0)
				{
					if (currentArea->getNextArea() == NULL)
					{
						endGameState->setWin(true);
						currentState = endGameState;
					}
					else
					{
						currentArea = currentArea->getNextArea();
						overworldState->loadArea(currentArea);
						battleState->setStage(currentArea->getStage());
						currentState = winState;
					}
				}
				else
				{
					currentState = winState;
				}
			}
			else if (currentState->getNextState() == "End")
				currentState = endGameState;
			currentState->toggleMusic();
			currentState->reset();
		}
	}
}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (currentState != nullptr)
	{
		currentState->render();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (currentState != nullptr)
		currentState->keyPressed(key);
	if(key=='r'||key=='R'){
	
      currentArea->resetEnemies();
	
	}
	if(key=='p'|| key=='P'){
		if(currentState==overworldState||currentState==battleState){
        paused= !paused;
    }
	}
}  


//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (currentState != nullptr)
		currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (currentState != nullptr)
		currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}