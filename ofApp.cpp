#include "ofApp.h"

using namespace std;

const int START_SCREEN = 0;
const int GAME_SCREEN = 1;
const int GAME_OVER_SCREEN = 2;
const int DEFAULT_VELOCITY = 5;

int gameState = START_SCREEN;


void ofApp::setup(){
    ofSetBackgroundColor(50, 50, 50);
    
    paddle = new Paddle((ofGetWidth()/2), (ofGetHeight()-60), 100, 20, 0, ofColor(0, 255, 0));
   
    ball = new Ball(10, ofColor(0, 255, 0));
    ball->velocity.set(1, 5);
    ball->location.set((ofGetWidth()/2), (ofGetHeight()/2));
    
    
    vector<string> lines;
    ofBuffer buffer = ofBufferFromFile("data.txt");
    for (auto line : buffer.getLines()) {
        lines.push_back(line);
    }
    
    for (int i = 0; i < lines.size(); ++i) {
        string row = lines[i];
        cout << "ROW " << i + 1 <<endl;
        for (int j = 0; j < row.size(); ++j) {
            cout << "Block: " << row[j] << endl;
        }
    }
}

// replace cout shit with this when you have block class
// char code = row[j];
// blocks.push_back( new block( code, ??? * i, ???...);


void ofApp::update(){
    gameLogic();
}

void ofApp::draw(){
    if (gameState == START_SCREEN) {
        drawStartScreen();
    } else if (gameState == GAME_SCREEN) {
        drawGameScreen();
    } else if (gameState == GAME_OVER_SCREEN) {
        drawGameOverScreen();
    }
}

void ofApp::drawStartScreen() {
    ofSetColor(255, 255, 255);
    logo.load("logo.png");
    logo.draw((ofGetWidth()/2) - 258.5, (ofGetHeight()/2) - 69.5);
}

void ofApp::drawGameScreen() {
    paddle->draw();
    ball->draw();
}

void ofApp::drawGameOverScreen() {
    
}

void ofApp::gameLogic() {
    ball->move();
}

void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        gameState = (gameState + 1) % 3;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    paddle->x = x;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
