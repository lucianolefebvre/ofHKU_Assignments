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
    enemySpeed = 5;
      font.loadFont("SourceSansPro-Bold.ttf", 20);
 sound.loadSound("russiaSong.mp3");
    sound.play();

    
    //make the connection. Remember you need to replace the string here with your actual port.
    // 57600 is the baud speed.
    myArduino.connect("/dev/tty.usbmodem1411", 57600);
    
    //a test to see if the arduion has been set up yet?
    bSetupArduino= false;

}

void ofApp::updateArduino(){
    //a call to update the arduion data ins and out
    myArduino.update();
}


//this will set up all of my arduio pins

void ofApp::setupArduino(){
    //this you can use ARD_OUTPUT but also ARD_INPUT to receive data! :)
    myArduino.sendDigitalPinMode(9, ARD_OUTPUT);
    
    
}

//--------------------------------------------------------------
//update is all the math stuff
// runs ones per frame before draw
void ofApp::update(){
    
    //if my arduio is ready
    if ( myArduino.isArduinoReady()){
        
        // 1st: setup the arduino if haven't already:
        if (bSetupArduino == false){
            
            // how to read in and out to the console.
            //            cout << "arduino running" << endl;
            //            cout << "what should the score be?" << endl;
            //            cin >> score;
            //            cout << "you set the score to " << score << endl;
            
            //this fundtion assigns the pins
            setupArduino();
            // we've starting running arduino so no need to call setup again! :)
            bSetupArduino = true;	// only do this once
        }
        
        // 2nd do the update of the arduino
        updateArduino();
    }
  
//     xpos += speed;
//     ypos += speed;
    //trubblemaker
//    enemyRadius ++;
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
//    ofSetColor(255,0,0);
//    ofCircle(enemyX,enemyY,enemyRadius);
    
    //creates eagle => player
    image.loadImage("eagle.png");
    image.draw(mouseX-100, mouseY-100);

    
    //putin instead of cirle
    image.loadImage("putin.png");
    image.draw(enemyX-100, enemyY-143);

    //this creates the player
//    ofSetColor(255, 255, 255);
//    ofCircle(mouseX,mouseY,playerRadius);

 
    //font load

    
    ofSetColor(255, 255, 255);
    font.drawString("Score "+ ofToString(score), 120,40);
    if(hasLostGame)
    {
        font.drawString("\nThis game is to much for you!!, thats OK. Just press any key to resart", 120,40);
     
        //turn off the LED  light by setting the 9th pin to ARD_LOW
        
        myArduino.sendDigital(9, ARD_HIGH);
    } else {
            myArduino.sendDigital(9, ARD_LOW);
       
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
            myArduino.sendDigital(9, ARD_HIGH);
        
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
