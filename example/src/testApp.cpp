#include "testApp.h"

/*
 *     _____    ___     
 *    /    /   /  /     PAL toolkit
 *   /  __/ * /  /__    (c) ponies & light, 2012. All rights reserved.
 *  /__/     /_____/    poniesandlight.co.uk
 *
 *  ofxDeltaTrackerExample
 *  Created by Tim Gfrerer on 07/02/2012.
 *         
 *  
 */


//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofSetBackgroundAuto(false);
	// we will better see the the movement path if we draw a trail...
	
	testNode.setGlobalPosition(ofRandomWidth(), ofRandomHeight(), 0);
	// put the node at a random position for starters.
	
	vec3fTracker.value = testNode.getGlobalPosition();
	
	vec3fTracker.setup();
	// this initialises the delta tracker with the current value as first reference point.
	
	vec3fPtr = &vec3fTracker.value;
	// vec3fPtr gives us a shortcut to access the absolute target value directly outside of vec3fTracker.
	
	
	// now track some sin/cos movement:
	
	wobbleTracker.value = ofVec2f(0,1);
	wobbleTracker.setup();
	
}

//--------------------------------------------------------------
void testApp::update(){

	vec3fPtr->set(ofMap((ofGetElapsedTimeMillis()%12000)/12000.f, 0, 1, 0, ofGetWidth()), 
				  ofMap((ofGetElapsedTimeMillis()%12000)/12000.f, 0, 1, 0, ofGetHeight()));
	// this directly sets the absolute target value in ofxDeltaTracker.
	
	vec3fTracker.update();
	// recalculate the delta value.
	
	testNode.move(vec3fTracker.getDelta());
	// the node will only move the distance between its current position and its target position.
	
	
	wobbleTracker.value = ofVec2f(sin((ofGetElapsedTimeMillis()%3000) * TWO_PI  / 3000.f ) * 30,
								  -cos((ofGetElapsedTimeMillis()%3000) * TWO_PI  / 3000.f ) * 30);
	
	
	wobbleTracker.update();
	
	testNode.move(wobbleTracker.getDelta());
	// by moving testNode from its current position by wobbleTracker's delta, we are adding 
	// the wobble delta to testNode.
	
	ofLog() << " vec3fTracker.getDelta(): " << vec3fTracker.getDelta();
	ofLog() << "wobbleTracker.getDelta(): " << wobbleTracker.getDelta();
	// output the current delta. 
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(128, 10);
	ofFill();
	ofRect(0,0,ofGetWidth(),ofGetHeight());
	
	ofSetColor(255,255);
	testNode.draw();
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}