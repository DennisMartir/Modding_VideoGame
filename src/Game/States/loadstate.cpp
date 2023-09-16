#include "loadstate.h"

LoadingState::LoadingState() {
    lImage.load("images/ui/LoadingScreen.png");
    music.load("audio/ui/beep.wav");
    timer=78;

}

void LoadingState::tick() {

    if (timer>0){
        timer--;
        
    }
    else if(timer==0){
    setFinished(true);
    setNextState("Overworld");
    timer=78;
    }
      
}

void LoadingState::render(){
    lImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}

void LoadingState::reset() {
    setFinished(false);
    setNextState("");
}
void LoadingState::keyPressed(int key) {
    
}

void LoadingState::mousePressed(int x, int y, int button) {

}