#include "Brick.h"
#include "Paddle.h"

const char RED = 'r';
const char GREEN = 'g';
const char BLUE = 'b';
const char YELLOW = 'y';
const char PINK = 'p';
const char SPECIAL = 's';


const int RED_POINTS = 100;
const int GREEN_POINTS = 200;
const int BLUE_POINTS = 300;
const int YELLOW_POINTS = 400;
const int PINK_POINTS = 500;
const int SPECIAL_POINTS = 1000;


Brick::Brick() {
    
}

Brick::Brick(int x, int y, int w, int h, char kind) {
    this->x = x;
    this->y = y;
    this->w = 100;
    this->h = 50;
    if (kind == RED) {
        this->points = RED_POINTS;
        this->type = 1;
        this->color = ofColor(255, 0, 0);
    } else if (kind == GREEN) {
        this->points = GREEN_POINTS;
        this->type = 2;
        this->color = ofColor(0, 255, 0);
    } else if (kind == BLUE) {
        this->points = BLUE_POINTS;
        this->type = 3;
        this->color = ofColor(0, 0, 255);
    } else if (kind == SPECIAL) {
        this->points = SPECIAL_POINTS;
        this->type = 4;
        this->color = ofColor(50, 185, 20);
    } else if (kind == YELLOW) {
        this->points = YELLOW_POINTS;
        this->type = 5;
        this->color = ofColor(255, 255, 0);
    } else if (kind == PINK) {
        this->points = PINK_POINTS;
        this->type = 6;
        this->color = ofColor(255, 105, 180);
    }
}

void Brick::draw() {
    if (!destroyed) {
        ofSetColor(color);
        ofDrawRectangle(x, y, w, h);
    }
}

void Brick::destroy() {
    destroyed = true;
}











