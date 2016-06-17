#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "imageClass.hpp"



#define port 9999


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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    


    
    ofxOscReceiver receiver;
    
    imageClass warp1;
    imageClass warp2;
    imageClass warp3;
    imageClass warp4;
    imageClass warp5;
    imageClass warp6;

};
