#pragma once

#include "ofMain.h"
#include "ofxOpenCV.h"
#include "ofxGui.h"
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
    
//    Create gui
    ofxPanel gui;

//    Load video
    ofVideoPlayer vid;
    ofImage vidFrame;
    Mat vidMat;
    Mat vidMatGray;
    Mat edgeMat;
    Mat frameMat;
    
//    Canny Edge Detection
    Mat vidMatEdge;
    ofxIntSlider edgeThreshold;
    
//    Hough Transform Lines
    ofxIntSlider lineThreshold;
    ofxIntSlider lowThreshold;
    
//    Region of Interest
    Mat mask;
    vector<cv::Point> keyPoints;
    
    
    float width;
    float height;
		
};
