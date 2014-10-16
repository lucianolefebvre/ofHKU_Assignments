#include "ofApp.h"

//--------------------------------------------------------------
// setup is for all the stuff you will need, like when you cook. you set up your stuff
// runs only ones. peace out later.
void ofApp::setup(){
//    // hee yo this is a comment yo.
//    /*more comments you know
//     maa bitches, get moeny
//     */
//    ofHideCursor();
//    xpos = 10;
//    ypos = 10;
//    speed = 1;
    enemyRadius = 20;
    playerRadius = 60;
    enemyY = 0 - enemyRadius; //enemy starts of screen
    enemyX = ofRandom(ofGetWidth());
    hasLostGame = false;
    score = 0;
    ofSetVerticalSync(true);
    enemySpeed = 10;
   

}

//--------------------------------------------------------------
//update is all the math stuff
// runs ones per frame before draw
void ofApp::update(){
//     xpos += speed;
//     ypos += speed;
    //trubblemaker
    enemyRadius ++;
    if(hasLostGame == false){
        if(enemyY > ofGetHeight()+enemyRadius)
        {
            score ++;
            enemyRadius += 2;
            enemyY = 0 - enemyRadius;
            enemyX = ofRandom(ofGetWidth());
        }
        enemyY += enemySpeed;
        if (ofDist(mouseX, mouseY, enemyX, enemyY) <= enemyRadius + playerRadius) {
            hasLostGame = true;
        }
    }
}

//--------------------------------------------------------------
//were you play sound and video, were you draw. it formed a cycle with update.
// runs ones per frame after update
void ofApp::draw(){
//    ofSetColor(255, 0, mouseY);
//    
//    // visible is de boolean die erik heeft aangemaakt in ofApp.h
//    // DRAW A CIRCLE THAT CHANGES BY THE SPEED
//    if(visible){
//        ofCircle(xpos, 100, 100);
//    }
    ofBackground(0, 0, 0);
    //this creates the enemy
    ofSetColor(255,0,0);
    ofCircle(enemyX,enemyY,enemyRadius);
    
    //this creates the player
    ofSetColor(255, 255, 255);
    ofCircle(mouseX,mouseY,playerRadius);
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Score "+ ofToString(score), 120,40);
    if(hasLostGame)
    {
        ofDrawBitmapString("\nThis game is to much for you!!, thats OK. Just press any key to resart", 120,40);
        
    }
    
}

//--------------------------------------------------------------
// curly brakes define the scope (is the listener)
// what happens in Vegas stays in Vegas
void ofApp::keyPressed(int key){
//    visible = false;
//    // visible is a boolean in ofApp.h made by terwany.
    enemyX = ofRandom(ofGetWidth());
    enemySpeed += 0.02;
    
}

//--------------------------------------------------------------
// feels more natural
void ofApp::keyReleased(int key){
//    visible = true;
    if(hasLostGame)
    {
        enemyX = ofRandom(ofGetWidth());
        enemyRadius = 20;
        enemyY = 0 - enemyRadius;
        hasLostGame = false;
        score = 0;
    }
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
