#include "ofApp.h"
#include "stdio.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    receiver.setup(port);
    ofHideCursor();
    
    
    for (int i =0; i<NUM_WARP; i++){
        surface.push_back(gmapSurface());
        surface.back().setup(i, "img1.jpg");
    }
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    metaLoadPreset(1);
    

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofxOscMessage m;
    
    for (int i =0; i<NUM_WARP; i++){
        surface[i].update(m);
    }
    
   
    
    
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
         if(m.getAddress() == "/gmap/save"){
             metaSavePreset(1);
             cout << "savvvve" << endl;
             ;}
         else if (m.getAddress() == "/gmap/load"){
             metaLoadPreset(1)
             ;}
         else if (m.getAddress() == "/gmap/num_warp"){
             {NUM_WARP = m.getArgAsInt(0);}
             for (int i =0; i<NUM_WARP; i++){
                 surface.push_back(gmapSurface());
                 surface.back().setup(i, "img1.jpg");
             }
             
             ;}
        
        for (int i =0; i<NUM_WARP; i++){
            surface[i].update(m);
        }
    
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    for (int i =0; i<NUM_WARP; i++){
        surface[i].draw();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::metaLoadPreset(int preset){
    
    XML.loadFile("mySettings.xml");
    
    NUM_WARP = XML.getValue("NUM_WARP", 10);
    
    for (int i =0; i<NUM_WARP; i++){
        surface[i].loadXML(XML, preset);
    }
    
    
    
}
//--------------------------------------------------------------

void ofApp::metaSavePreset(int preset){
    
    XML.loadFile("mySettings.xml");
    
    
    for (int i =0; i<NUM_WARP; i++){
        surface[i].saveXML(XML, preset);
    }
    
    XML.setValue("NUM_WARP", NUM_WARP);

    XML.saveFile("mySettings.xml");

    cout << "saved" << endl;
    
}
//--------------------------------------------------------------

void ofApp::initSurfaces(){

    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  //  screenX = w;
  //  screenY = h;
  

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
