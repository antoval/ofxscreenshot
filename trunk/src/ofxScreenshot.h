/**
 * Addon to take screenshots from your application. I created this addon,
 * based on some information I found in the forum of openFrameworks a while
 * ago. If you recognize your code, please tell me I'll add you as the author.
 *
 * I add this code into an addon as I wanted to be able to quickly create
 * screenshots for my videos.
 *
 * @date 2009.11.20
 * @author	Diederick Huijbers <diederick@apollomedia.nl>
 *
 */

#ifndef OFXSCREENSHOTH
#define OFXSCREENSHOTH
#include "ofMain.h"

class ofxScreenshot {
public:
	string 		filename;
	int 		frame_count;
	ofImage 	img;
	float 		seconds;
	float		minutes;

	ofxScreenshot(string sFileName);
	void 		grabFrame();
	void 		pause();
	void 		record();
	void 		setPaused(bool bPaused);
	bool 		isPaused();
	void		toggle();

private:
	bool paused;
};
#endif
