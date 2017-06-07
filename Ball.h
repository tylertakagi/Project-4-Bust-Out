#pragma once
#include "ofMain.h"
#include "Brick.h"

class Ball {
public:
    ofVec2f location, velocity, acceleration;
    int r;
    ofColor color;
    
    Ball();
    Ball(int r, ofColor color);
    
    void draw();
    void move();
    bool hittingSides();
    void bounceHorizontally();
    void bounce();
    bool hits(Brick* b);
};
