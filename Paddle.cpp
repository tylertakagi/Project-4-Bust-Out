#include "Paddle.h"

Paddle::Paddle() {
    
}

Paddle::Paddle( float x, float y, int h, ofColor color) {
    this->x = x;
    this->y = y;
    this->w = 100;
    this->h = h;
    this->color = color;
}

void Paddle::draw() {
    ofSetColor(color);
    ofDrawRectangle(x, y, w, h);
}

void Paddle::setSize(int level) {
    w -= (level * 5);
}
