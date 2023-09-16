#include "Bloadstate.h"

bLoadingState::bLoadingState() {
    lImage.load("images/ui/LoadingScreen.png");
    music.load("audio/ui/beep.wav");
    timer=78;
}

void bLoadingState::tick() {
     if (timer>0){
        timer--;
        
    }
    else if(timer==0){
    setFinished(true);
    setNextState("Battle");
    timer=78;
    }
      
}

void bLoadingState::render(){
    lImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void bLoadingState::reset() {
    setFinished(false);
    setNextState("");
}
void bLoadingState::keyPressed(int key) {
    
}

void bLoadingState::mousePressed(int x, int y, int button) {

}