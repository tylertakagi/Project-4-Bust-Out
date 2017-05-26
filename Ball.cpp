#include "Ball.h"
#include "Paddle.h"


const int DEFAULT_VELOCITY = 1;

Ball::Ball() {
    
}

Ball::Ball(int r, ofColor color) {
    this->r = r;
    this->color = color;
}

void Ball::draw() {
    ofSetColor(0, 255, 0);
    ofDrawCircle(location.x, location.y, 2*r);
    ofSetCircleResolution(100);
}

void Ball::move() {
    location += velocity;
    if (location.x > ofGetWidth() || location.x < 0) {
        velocity.x *= -1;
    }
    if (location.y > ofGetHeight() || location.y < 0) {
        velocity.y *= -1;
    }
}
