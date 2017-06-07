#include "Ball.h"

const int DEFAULT_VELOCITY = 1;

Ball::Ball() {
    
}

Ball::Ball(int r, ofColor color) {
    this->r = r;
    this->color = color;
}

void Ball::draw() {
    ofSetColor(0, 255, 0);
    ofDrawCircle(location.x, location.y, r);
    ofSetCircleResolution(100);
}

void Ball::move() {
    location += velocity;
}

bool Ball::hittingSides() {
    return (location.x + r > ofGetWidth() || location.x - r < 0);
}

void Ball::bounceHorizontally() {
    velocity.x *= -1;
    velocity.rotate(ofRandom(-30, 30));
    if (location.x > ofGetWidth()) {
        location.x = ofGetWidth() - r;
    } else if (location.x <= 0) {
        location.x = r;
    } else if (location.y >= ofGetWindowHeight() - r) {
        location.y = ofGetWindowHeight() - r;
        velocity.y *= -1;
    }
}

void Ball::bounce() {
    velocity.rotate(ofRandom(-45, 45));
    velocity.x *= -1;
    velocity.y *= -1;
}

bool Ball::hits(Brick* b) {
    if (location.x + r <= b->x + b->w && location.y + r <= b->y + b->h) {
        return true;
    }
}


