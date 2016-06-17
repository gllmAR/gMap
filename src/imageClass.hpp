//
//  imageClass.hpp
//  gmap
//
//  Created by Guillaume Arseneault on 16-06-16.
//
//

#ifndef imageClass_hpp
#define imageClass_hpp

#include <ofMain.h>
#include "ofxOsc.h"

#include "ofxGLWarper.h"

class imageClass{
public:
    void setup(int i, string path);
    void update(int i, ofxOscMessage m);
    void draw();
    
    int screenX;
    int screenY;
    
    ofImage img;
    
    ofxGLWarper warper;
    
    
    ofPoint wTLPosition;
    ofPoint wTRPosition;
    ofPoint wBLPosition;
    ofPoint wBRPosition;
    
    ofParameter<float> alpha = 1;
    
    ofParameter<float> wTLx = 0;
    ofParameter<float> wTLy = 0;
    ofParameter<float> wTRx = 1;
    ofParameter<float> wTRy = 0;
    ofParameter<float> wBLx = 0;
    ofParameter<float> wBLy = 1;
    ofParameter<float> wBRx = 1;
    ofParameter<float> wBRy = 1;
    
    
    
};

#endif /* imageClass_hpp */
