
#include "Paddle.h"

Paddle::Paddle() {
    
}

Paddle::Paddle( float x, float y, int w, int h, ofColor color) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;
}

void Paddle::draw() {
    ofSetColor(color);
    ofDrawRectangle(x, y, w, h);
}
