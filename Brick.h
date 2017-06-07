#pragma once
#include "ofMain.h"

class Brick {
public:
    bool destroyed;
    int x;
    int y;
    int w;
    int h;
    char kind;
    int points;
    int type;
    ofColor color;
    
    Brick();
    Brick(int x, int y, int w, int h, char kind);
    
    ofSoundPlayer hitsRed;
    
    void draw();
    void destroy();
    void music();
    
};


