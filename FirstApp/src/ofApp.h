#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
//    bool visible;
//    
//    int xpos;
//    int ypos;
//    float speed;
    
        float playerRadius;
        float enemyRadius;
        float enemyX;
        float enemyY;
        int score;
        int speed;
        int enemySpeed;
        bool hasLostGame;
    
//image thingy
    ofImage image;
    
    
//font madness
    ofTrueTypeFont font;
 
//Sound stuff
    ofSoundPlayer sound;

    //variables for Arduino
    
    //allows for serial output -- we'll do this next week. :)
    ofSerial serial;
    //an arduino object
    ofArduino myArduino;
    //this variable will only be false when the code first runs arduino
    bool bSetupArduino;
    ///fucntions for arduino
    void setupArduino();
    void updateArduino();
		
};
