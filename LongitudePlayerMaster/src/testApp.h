#pragma once

#include "ofMain.h"
#include "ofxOMXPlayer.h"
#include "ofxOsc.h"

#define HOST1 "192.168.1.40"
#define HOST2 "192.168.1.41"
#define HOST3 "192.168.1.42"

#define PORT 12345

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
			
		ofxOMXPlayer omxPlayer;
		ofxOscSender sender1, sender2, sender3;
		ofxOscReceiver receiver;	
};

