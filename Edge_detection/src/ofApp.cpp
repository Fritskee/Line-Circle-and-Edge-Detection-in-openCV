#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(threshold.setup("Edge Threshold", 100, 0, 200));

//    image.load("sinus.jpg");
//    image.load("sawtooth.jpg");
    image.load("squareEdge.jpg");
    image.resize(480, 640);
    im = toCv(image);
    
    adjusted = threshold;
    ofResetElapsedTimeCounter();
    point = 0;
    
    cvtColor(im, im, CV_BGR2GRAY);
    GaussianBlur(im, im, 3);
    Canny(im, mat, threshold, threshold*3);
    
    for(int i = 0; i < image.getWidth(); i++){
        for(int j = 0; j < image.getHeight(); j++){
            if(mat.data[int(i+image.getWidth()*j)] > 250){
                cv::Point p(i,j);
                points.push_back(p);
                break;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // To update when threshold is adjusted during runtime
    Canny(im, mat, threshold, threshold*3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    image.draw(0, 0);
    
    ofSetColor(255, 0, 0);
    if(ofGetElapsedTimeMillis() > 100){
        if(point < points.size() && !notFinished){
            point += 1;
        }else{
            point -= 1;
        }
        if(point >= points.size()){
            point = points.size()-1;
            notFinished = !notFinished;
        }
        if(point <= 0){
            point = 0;
            notFinished = !notFinished;
        }
    }
    
    ofDrawCircle(points[point].x, points[point].y, 15);
    
//    Mechanism for updating the path when threshold is adjusted
    if(threshold != adjusted){
        adjusted = threshold;
        while(!points.empty()){
            points.pop_back();
        }
        for(int i = 0; i < image.getWidth(); i++){
            for(int j = 0; j < image.getHeight(); j++){
                if(mat.data[int(i + image.getWidth()*j)] > 0){
                    cv::Point p(i,j);
                    points.push_back(p);
                    break;
                }
            }
        }
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

//--------------------------------------------------------------
Mat trackLine(Mat matIn, Mat matOut, int i){
    
}
