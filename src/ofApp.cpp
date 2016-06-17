#include "ofApp.h"
#include "stdio.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //warper.activate();// this allows ofxGLWarper to automatically listen to the mouse and
    ofBackground(0);
    receiver.setup(port);
    ofHideCursor();
    
    warp1.setup(1, "img1.jpg");
    warp2.setup(2, "img2.jpg");
    warp3.setup(3, "img3.jpg");
    warp4.setup(4, "img4.jpg");
    warp5.setup(5, "img5.jpg");
    warp6.setup(6, "img6.jpg");

    ofEnableBlendMode(OF_BLENDMODE_ADD);
  

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
            warp1.update(1, m);
            warp2.update(2, m);
            warp3.update(3, m);
            warp4.update(4, m);
            warp5.update(5, m);
            warp6.update(6, m);
        
       
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
        warp1.draw();
        warp2.draw();
        warp3.draw();
        warp4.draw();
        warp5.draw();
        warp6.draw();
    
    
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
