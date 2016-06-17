//
//  imageClass.cpp
//  gmap
//
//  Created by Guillaume Arseneault on 16-06-16.
//
//

#include "imageClass.hpp"

void imageClass::setup(int index, string path){
    
    screenX = ofGetWidth();
    screenY = ofGetHeight();
    img.load(path);
    warper.setup(); //initializates ofxGLWarper

    
    wTLPosition = ofPoint(wTLx*screenX, wTLy*screenY);
    wTRPosition = ofPoint(wTRx*screenX, wTRy*screenY);
    wBLPosition = ofPoint(wBLx*screenX, wBLy*screenY);
    wBRPosition = ofPoint(wBRx*screenX, wBRy*screenY);

}
void imageClass::update(int i, ofxOscMessage m){
    

 
               if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wTLx"){wTLx = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wTLy"){wTLy = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wTRx"){wTRx = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wTRy"){wTRy = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wBLx"){wBLx = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wBLy"){wBLy = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wBRx"){wBRx = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/wBRy"){wBRy = m.getArgAsFloat(0);}
          else if(m.getAddress() == string("/warper/")+std::to_string(i)+"/alpha"){alpha = m.getArgAsFloat(0);}
    
    
    wTLPosition = ofPoint(wTLx*screenX, wTLy*screenY);
    wTRPosition = ofPoint(wTRx*screenX, wTRy*screenY);
    wBLPosition = ofPoint(wBLx*screenX, wBLy*screenY);
    wBRPosition = ofPoint(wBRx*screenX, wBRy*screenY);
    
    warper.setCorner(ofxGLWarper::TOP_LEFT, wTLPosition);
    warper.setCorner(ofxGLWarper::TOP_RIGHT, wTRPosition);
    warper.setCorner(ofxGLWarper::BOTTOM_LEFT, wBLPosition);
    warper.setCorner(ofxGLWarper::BOTTOM_RIGHT, wBRPosition);
    
}

void imageClass::draw(){
    warper.begin();
    ofSetColor(alpha*255, alpha*255, alpha*255, alpha*255);
    img.draw(0, 0, screenX, screenY);
    warper.end();
}