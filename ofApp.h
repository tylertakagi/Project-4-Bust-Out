// Tyler Takagi
// Project 4 Bust Out

#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:

        Paddle* paddle;
        Ball* ball;
    
        void setup();
		void update();
		void draw();
    
        void drawStartScreen();
        void drawGameScreen();
        void drawGameOverScreen();
        void gameLogic();
    
        ofTrueTypeFont arcade;
        ofImage logo;

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
