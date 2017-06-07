#pragma once
#include "ofMain.h"

class Brick {
public:
    bool destroyed;
    int x;
    int y;
    int w;
    int h;
    int points;
    ofColor color;
    
    Brick();
    Brick(int x, int y, int w, int h, char kind);
    
    void draw();
    void destroy();
};
