#include "Paddle.h"

Paddle::Paddle() {
    
}

Paddle::Paddle( float x, float y, int w, int h, float v, ofColor color) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->v = 0;
    this->color = color;
}

void Paddle::draw() {
    ofRectangle(ofGetWidth()/2, ofGetHeight()/2, 100, 20);
    ofSetColor(color);
}

