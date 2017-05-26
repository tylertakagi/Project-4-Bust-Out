#pragma once
#include "ofMain.h"

class Ball {

public:

    ofVec2f location, velocity, acceleration;
    int r;
    ofColor color;
    
    Ball();
    Ball(int r, ofColor color);
    
    void draw();
    void move();
};
