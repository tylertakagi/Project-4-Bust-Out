// Tyler Takagi
// Project 4 Bust Out

#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "Brick.h"

class ofApp : public ofBaseApp{
public:

        Paddle* paddle;
        Ball* ball;
    
        void setup();
		void update();
		void draw();
    
        void prepareBricks();
        void ballCollision();
        void levelClear();
        void drawStartScreen();
        void drawGameScreen();
        void drawWinScreen();
        void drawGameOverScreen();
        void gameLogic();
    
        ofTrueTypeFont arcade;
        ofImage logo;
        ofImage gameOverLogo;
        ofImage gameWinLogo;
        ofSoundPlayer hitsPaddle;
        ofSoundPlayer hitsRed;
        ofSoundPlayer hitsGreen;
        ofSoundPlayer hitsBlue;
        ofSoundPlayer hitsSpecial;
        ofSoundPlayer hitsYellow;
        ofSoundPlayer hitsPink;
        ofSoundPlayer loseLife;
        ofSoundPlayer gameOver;
        ofSoundPlayer roundOne;
        ofSoundPlayer roundTwo;
        ofSoundPlayer roundThree;
        ofSoundPlayer roundFour;
        ofSoundPlayer themeSong;
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
		
};
