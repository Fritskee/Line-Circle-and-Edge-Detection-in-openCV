#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(threshold.setup("Low Threshold Value", 80, 30, 130));
    camStream.initGrabber(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    camStream.update();
    matCam = toCv(camImage);
    if(camStream.isFrameNew()){
        camImage.setFromPixels(camStream.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    drawMat(matCam, 0, 0);
    
    matCam = toCv(camStream);
    
    cvtColor(matCam, matCam, CV_BGR2GRAY);
    GaussianBlur(matCam, matCam, 3);
    Canny(matCam, matCam, threshold, threshold*2);
    
    vector<Vec3f> circle;
    HoughCircles(matCam, circle, CV_HOUGH_GRADIENT, 2, 50, threshold*2, 100, 30, 50);
    for(int i = 0; i < circle.size(); i++){
        ofSetColor(255, 255, 255);
        ofDrawCircle(circle[i][0], circle[i][1], circle[i][2]);
    }
    for(int i = 0; i < circle.size(); i++){
        ofSetColor(0, 0, 0);
        ofDrawCircle(circle[i][0], circle[i][1], circle[i][2], 8);
    }
    gui.draw();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
