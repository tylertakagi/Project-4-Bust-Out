#include "ofApp.h"

using namespace std;

const int START_SCREEN = 0;
const int GAME_SCREEN = 1;
const int GAME_OVER_SCREEN = 2;
const int WIN_SCREEN = 3;

const int DEFAULT_VELOCITY = 5;
const int PADDLE_OFFSET = 375;
const int BRICK_XSPACE = 30;
const int BRICK_YSPACE = 10;
const int SCORE_OFFSET = 500;
const int LIVES_OFFSET = 300;
const int LOGO_X = 258.5;
const int LOGO_Y = 69.5;

vector<Brick*> bricks;

int score = 0;
int lives = 3;
int gameState = START_SCREEN;
int level = 1;
int bricksLeft = bricks.size();

void ofApp::setup() {
    ofSetBackgroundColor(50, 50, 50);
    
    logo.load("logo.png");
    gameOverLogo.load("gameOver.png");
    gameWinLogo.load("gameWin.png");
    arcade.load("arcade.ttf", 15);
    hitsPaddle.load("paddleNoise.mp3");
    hitsRed.load("hitsRed.mp3");
    hitsGreen.load("hitsGreen.mp3");
    hitsBlue.load("hitsBlue.mp3");
    hitsYellow.load("hitsYellow.mp3");
    hitsPink.load("hitsPink.mp3");
    hitsSpecial.load("hitsSpecial.mp3");
    loseLife.load("loseLife.mp3");
    gameOver.load("gameOver.mp3");
    roundOne.load("roundOne.mp3");
    roundTwo.load("roundTwo.mp3");
    roundThree.load("roundThree.mp3");
    roundFour.load("roundFour.mp3");
    themeSong.load("AphexTwin.mp3");
    themeSong.play();
    
    paddle = new Paddle((ofGetWidth() / 2), (ofGetHeight() / 2 + PADDLE_OFFSET), 20, ofColor(0,255,0));
    ball = new Ball(20, ofColor(0, 255, 0));
    ball->velocity.set(1, 5);
    ball->location.set((ofGetWidth()/2), (ofGetHeight()/2));
}

void ofApp::update() {
    if (gameState == GAME_SCREEN) {
            gameLogic();
    }
}

void ofApp::draw() {
    if (gameState == START_SCREEN) {
        drawStartScreen();
    } else if (gameState == GAME_SCREEN) {
        drawGameScreen();
    } else if (gameState == GAME_OVER_SCREEN) {
        drawGameOverScreen();
    } else if (gameState == WIN_SCREEN) {
        drawWinScreen();
    }
}

void ofApp::drawStartScreen() {
    ofSetColor(255, 255, 255);
    logo.draw((ofGetWidth()/2) - LOGO_X, (ofGetHeight()/2) - LOGO_Y);
    arcade.drawString("Level 1: Easy", (ofGetWidth()/2) - 100, (ofGetHeight()/2) + 100);
    arcade.drawString("Level 2: Medium", (ofGetWidth()/2) - 100, (ofGetHeight()/2) + 120);
    arcade.drawString("Level 3: Hard", (ofGetWidth()/2) - 100, (ofGetHeight()/2) + 140);
    arcade.drawString("Level 4: Dont Do It!", (ofGetWidth()/2) - 100, (ofGetHeight()/2) + 160);
}

void ofApp::drawGameScreen() {
    paddle->draw();
    ball->draw();
    
    ofSetColor(0, 255, 0);
    std::string str_score = "Score: ";
    str_score += ofToString(score);
    arcade.drawString(str_score, (ofGetWidth() / 2) - SCORE_OFFSET, (ofGetHeight()/2) + LIVES_OFFSET);
    std::string str_lives = "Lives Left: ";
    str_lives += ofToString(lives);
    arcade.drawString(str_lives, (ofGetWidth()/2) - LIVES_OFFSET, (ofGetHeight()/2) + LIVES_OFFSET);
    
    for (int i = 0; i < bricks.size(); ++i) {
        bricks.at(i)->draw();
    }
    
    for (int i = 0; i < bricks.size(); ++i) {
        if (!bricks.at(i)->destroyed && ball->hits(bricks.at(i))) {
            bricks.at(i)->destroy();
            if (bricks.at(i)->type == 1) {
                hitsRed.play();
            } else if (bricks.at(i)->type == 2) {
                hitsGreen.play();
            } else if (bricks.at(i)->type == 3) {
                hitsBlue.play();
            } else if (bricks.at(i)->type == 4) {
                hitsSpecial.play();
                paddle->setSize(-10);
            } else if (bricks.at(i)->type == 5) {
                hitsYellow.play();
            } else if (bricks.at(i)->type == 6) {
                hitsPink.play();
            }
            ball->bounce();
            ++bricksLeft;
            score += bricks[i]->points;
            break;
        }
    }

    if ((ball->location.y) > (paddle->y)) {
        ball->location.set((ofGetWidth()/2), (ofGetHeight()/2));
        loseLife.play();
        --lives;
    }
    
    if (bricks.size() == bricksLeft) {
        ++level;
        paddle->setSize(level);
        prepareBricks();
        }
    
    if (lives == 0) {
        gameState = GAME_OVER_SCREEN;
        themeSong.stop();
        gameOver.play();
    }
    
    if (bricks.size() == bricksLeft && level > 4) {
        gameState = WIN_SCREEN;
    }
}

void ofApp::drawWinScreen() {
    gameOverLogo.draw((ofGetWidth()/2) - 178.5, (ofGetHeight()/2));
}

void ofApp::drawGameOverScreen() {
    gameOverLogo.draw((ofGetWidth()/2) - 348, (ofGetHeight()/2) - LOGO_Y);
    arcade.drawString("YOUR SCORE IS: ", (ofGetWidth()/2 - 150), (ofGetHeight()/2) - 75);
    arcade.drawString(ofToString(score),(ofGetWidth()/2) + 75, (ofGetHeight()/2) - 75);
}

void ofApp::gameLogic() {
    ball->move();
    if (ball->hittingSides()) {
        ball->bounceHorizontally();
    }
    
    if ((ball->location.y + ball->r) >= (paddle->y)) {
        if ((ball->location.x - ball->r) <= (paddle->x + (paddle->w))) {
            if ((ball->location.x + ball->r) >= (paddle->x)) {
                ball->velocity.y *= -1;
                ball->velocity.rotate(ofRandom(-20, 20));
                hitsPaddle.play();
            }
        }
    }
}

void ofApp::prepareBricks() {
    string filename = ofToString(level) + ".txt";
    vector<string> lines;
    ofBuffer buffer = ofBufferFromFile(filename);
    
    for (auto line : buffer.getLines()) {
        lines.push_back(line);
    }
 
    for (int i = 0; i < lines.size(); ++i) {
        string row = lines[i];
        for (int j = 0; j < row.size(); ++j) {
            char code = row[j];
            if (code == ' ') continue;
            Brick *b = new Brick((j*ofGetWidth()/row.size() + BRICK_XSPACE), (i*ofGetHeight()/10 + BRICK_YSPACE), (ofGetWidth()/row.size()), (ofGetHeight()/4), code);
            bricks.push_back(b);
        }
    }
}

void ofApp::keyPressed(int key){
    if (gameState == START_SCREEN) {
        if (key >= '1' && key <= '4') {
            level = key - 48;
            
            if (level == 1) roundOne.play();
            if (level == 2) roundTwo.play();
            if (level == 3) roundThree.play();
            if (level == 4) roundFour.play();
        }
        score = 0;
        lives = 3;
        prepareBricks();
        paddle->setSize(level);
        gameState = GAME_SCREEN;
        }
    
    if (gameState == GAME_OVER_SCREEN || gameState == WIN_SCREEN) {
        if (key == 'f') {
            gameState = START_SCREEN;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    paddle->x = x;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
