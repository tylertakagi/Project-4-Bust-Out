
#pragma once
#include "ofMain.h"

class Paddle {
    
    
public:
    
    float x;
    float y;
    int w;
    int h;
    ofColor color;
    
    Paddle();
    Paddle(float x, float y, int w, int h, ofColor color);
    
    void draw();
    void move();
};
