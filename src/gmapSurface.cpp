//
//  gmapSurface.cpp
//  gmap
//
//  Created by Guillaume Arseneault on 16-06-24.
//
//

#include "gmapSurface.hpp"


void gmapSurface::setup(int index, string path){
    
    screenX = ofGetWidth();
    screenY = ofGetHeight();
    mediaPath = path;
    img.load(mediaPath);
    warper.setup(); //initializates ofxGLWarper
    
    oscPath = string("/surface/")+std::to_string(index);
    xmlPath = string ("surface")+std::to_string(index);
    myIndex = index;
    
    
    wTLPosition = ofPoint(wTLx*screenX, wTLy*screenY);
    wTRPosition = ofPoint(wTRx*screenX, wTRy*screenY);
    wBLPosition = ofPoint(wBLx*screenX, wBLy*screenY);
    wBRPosition = ofPoint(wBRx*screenX, wBRy*screenY);
    
}

void gmapSurface::loadXML(ofxXmlSettings XML, int preset){
    
    wTLx = XML.getValue(xmlPath+"_"+"wTLx", 0.0);
    wTLy = XML.getValue(xmlPath+"_"+"wTLy", 0.0);
    wTRx = XML.getValue(xmlPath+"_"+"wTRx", 1.0);
    wTRy = XML.getValue(xmlPath+"_"+"wTRy", 0.0);
    wBLx = XML.getValue(xmlPath+"_"+"wBLx", 0.0);
    wBLy = XML.getValue(xmlPath+"_"+"wBLy", 1.0);
    wBRx = XML.getValue(xmlPath+"_"+"wBRx", 1.0);
    wBRy = XML.getValue(xmlPath+"_"+"wBRy", 1.0);
    alpha = XML.getValue(xmlPath+"_"+"alpha", 1.0);
    mediaPath = XML.getValue(xmlPath+"_"+"mediaPath", "img1.jpg");
    img.load(mediaPath);
    
    
}

void gmapSurface::saveXML(ofxXmlSettings XML, int preset){
    
    XML.setValue(xmlPath+"_"+"wTLx", wTLx);
    XML.setValue(xmlPath+"_"+"wTLy", wTLy);
    XML.setValue(xmlPath+"_"+"wTRx", wTRx);
    XML.setValue(xmlPath+"_"+"wTRy", wTRy);
    XML.setValue(xmlPath+"_"+"wBLx", wBLx);
    XML.setValue(xmlPath+"_"+"wBLy", wBLy);
    XML.setValue(xmlPath+"_"+"wBRx", wBRx);
    XML.setValue(xmlPath+"_"+"wBRy", wBRy);
    XML.setValue(xmlPath+"_"+"alpha", alpha);
    XML.setValue(xmlPath+"_"+"mediaPath", mediaPath);
    
    
}

void gmapSurface::update(ofxOscMessage m){
    
    
    
    if(m.getAddress() == oscPath +"/wTLx"){wTLx = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wTLy"){wTLy = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wTRx"){wTRx = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wTRy"){wTRy = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wBLx"){wBLx = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wBLy"){wBLy = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wBRx"){wBRx = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/wBRy"){wBRy = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/alpha"){alpha = m.getArgAsFloat(0);}
    else if(m.getAddress() == oscPath+"/mediaPath"){
        mediaPath = m.getArgAsString(0);
        img.load(mediaPath);
    }
    
    
    wTLPosition = ofPoint(wTLx*screenX, wTLy*screenY);
    wTRPosition = ofPoint(wTRx*screenX, wTRy*screenY);
    wBLPosition = ofPoint(wBLx*screenX, wBLy*screenY);
    wBRPosition = ofPoint(wBRx*screenX, wBRy*screenY);
    
    warper.setCorner(ofxGLWarper::TOP_LEFT, wTLPosition);
    warper.setCorner(ofxGLWarper::TOP_RIGHT, wTRPosition);
    warper.setCorner(ofxGLWarper::BOTTOM_LEFT, wBLPosition);
    warper.setCorner(ofxGLWarper::BOTTOM_RIGHT, wBRPosition);
    
}

void gmapSurface::draw(){
    warper.begin();
    ofSetColor(alpha*255, alpha*255, alpha*255, alpha*255);
    img.draw(0, 0, screenX, screenY);
    warper.end();
}