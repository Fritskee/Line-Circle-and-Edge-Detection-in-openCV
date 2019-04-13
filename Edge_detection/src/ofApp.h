#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace cv;
using namespace ofxCv;

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
    
//    load images
    ofImage image;
    Mat im;
    
//    gui
    ofxPanel gui;
    
//    Canny
    ofxIntSlider threshold;
    Mat mat;
    int adjustedThreshold;
    
//    Line tracking
    Vector<cv::Point> points;
    Mat trackLine(Mat matIn, Mat matOut, int i);
    int point;
    Boolean notFinished;
    
    int adjusted;
		
};
