#include "ofxScreenshot.h"

ofxScreenshot::ofxScreenshot(string sFileName):filename(sFileName),frame_count(0), minutes(0), seconds(0), paused(true) {
}

void ofxScreenshot::grabFrame(){
	if (paused)
		return;

	// Create the filename.
	frame_count++;
	char buf[10];
	sprintf(buf, "%04d",frame_count);

	string file = filename +"_" +buf +".png";
	img.grabScreen(0,0,ofGetWidth(), ofGetHeight());
	img.saveImage(file);

	// Some debug info.
	float elapsedTime 	= ofGetElapsedTimef();
	seconds 			= (int)elapsedTime%60;
	minutes 			= (int)(elapsedTime/60);
	string ellapsed 	= " elapsed: " + ofToString(minutes, 0) + "min "+ ofToString(seconds, 0) + "sec\n";

	// Show the info.
	std::cout << ofToString(frame_count, 0) + " frames " +
	"at " + ofToString(ofGetFrameRate(),2) + "fps" + ellapsed;
}

void ofxScreenshot::setPaused(bool bPaused) {
	paused = bPaused;
}

void ofxScreenshot::pause() {
	paused = true;
}

void ofxScreenshot::record() {
	paused = false;
}

bool ofxScreenshot::isPaused() {
	return paused;
}

void ofxScreenshot::toggle() {
	paused = !paused;
}