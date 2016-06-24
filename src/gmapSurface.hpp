//
//  gmapSurface.hpp
//  gmap
//
//  Created by Guillaume Arseneault on 16-06-24.
//
//

#ifndef gmapSurface_hpp
#define gmapSurface_hpp

#include <stdio.h>
#include <ofMain.h>
#include "ofxOsc.h"
#include "ofxGLWarper.h"

class gmapSurface{
public:
    void setup(int i, string path);
    void update(ofxOscMessage m);
    void draw();
    
    void loadXML(ofxXmlSettings XML, int preset);
    void saveXML(ofxXmlSettings XML, int preset);
    
    int screenX;
    int screenY;
    
    ofImage img;
    
    ofxGLWarper warper;
    
    
    ofPoint wTLPosition;
    ofPoint wTRPosition;
    ofPoint wBLPosition;
    ofPoint wBRPosition;
    
    string oscPath;
    string xmlPath;
    
    int myIndex = 0;
    
    ofParameter<float> alpha = 1;
    
    ofParameter<float> wTLx = 0;
    ofParameter<float> wTLy = 0;
    ofParameter<float> wTRx = 1;
    ofParameter<float> wTRy = 0;
    ofParameter<float> wBLx = 0;
    ofParameter<float> wBLy = 1;
    ofParameter<float> wBRx = 1;
    ofParameter<float> wBRy = 1;
    ofParameter<string> mediaPath;
    
    
    
};



#endif /* gmapSurface_hpp */
