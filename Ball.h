#pragma once
#include "ofMain.h"

class Ball {

public:

    ofVec2f location, velocity, acceleration;
    int r;
    int score;
    int lives;
    ofColor color;
    
    Ball();
    Ball(int r, int score, int lives, ofColor color);
    
    void draw();
    void move();
};
