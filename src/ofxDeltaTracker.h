#ifndef GUARD_ofxDeltaTracker
#define GUARD_ofxDeltaTracker

/*
 *     _____    ___     
 *    /    /   /  /     PAL toolkit
 *   /  __/ * /  /__    (c) ponies & light, 2012. All rights reserved.
 *  /__/     /_____/    poniesandlight.co.uk
 *
 *  ofxDeltaTracker.h
 *  Created by Tim Gfrerer on 07/02/2012.
 *         
 *  
 */


/*	Helper to return only the change in a variable's value 
 *  (the delta value) since the last call to update.
 *
 *  This is useful when converting absolute movement to relative movement, 
 *  e.g. when using ofNode.move() instead of ofNode.setPosition(); 
 * 
 *  In this case, using multiple ofxDeltaTracker[s] for one ofNode allows you to  
 *  combine multiple relative movements. [see example project]
 * 
 *
 */


#include "ofMain.h"



template <class T>
class ofxDeltaTracker {

	T lastValue;
	T delta;
	
public:
	
	T value;

	void setup()			{ lastValue = value;											};
	void reset()			{ setup();														};
	
	void update()			{ delta = value - lastValue; if (delta != 0) lastValue = value;	};

	const T& getDelta()	    { return delta;													};

};



#endif