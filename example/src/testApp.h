#pragma once

#include "ofMain.h"
#include "ofxDeltaTracker.h"

class testApp : public ofBaseApp{
	
	ofxDeltaTracker<ofVec3f >	vec3fTracker;
	ofxDeltaTracker<ofVec2f >	wobbleTracker;
	
	ofNode		testNode;
	ofVec3f*	vec3fPtr;

	//	ofxDeltaTracker can be of any type which implements (x - x) == 0
	
	//	ofxDeltaTracker<ofVec2f >	vec2fTracker;
	//	ofxDeltaTracker<float	> 	floatTracker;
	//	ofxDeltaTracker<int	    >	intTracker;
	
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
