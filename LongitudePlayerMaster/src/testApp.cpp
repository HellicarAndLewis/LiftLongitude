#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
//	string videoPath = ofToDataPath("../../../video/Timecoded_Big_bunny_1.mov", true);
	string videoPath = ofToDataPath("../../../video/PEEK.mov", true);
	
	//Somewhat like ofFboSettings we may have a lot of options so this is the current model
	ofxOMXPlayerSettings settings;
	settings.videoPath = videoPath;
	settings.useHDMIForAudio = false;	//default true
	settings.enableTexture = true;		//default true
	settings.enableLooping = true;		//default true
	settings.enableAudio = true;		//default true, save resources by disabling
	settings.doFlipTexture = true;		//default false
	
	
	//so either pass in the settings
	omxPlayer.setup(settings);
	
	//or live with the defaults
	//omxPlayer.loadMovie(videoPath);

	// open an outgoing connection to HOST:PORT
	sender1.setup(HOST1, PORT);
	sender2.setup(HOST2, PORT);
	sender3.setup(HOST3, PORT);

	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	ofHideCursor();

//	shouldRestartVideo = false;
	//ofSetVerticalSync(true); //just trying framerate
	//ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update()
{
//	if(shouldRestartVideo){
//		omxPlayer.restartMovie();
//		shouldRestartVideo = false;
//	}
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		omxPlayer.restartMovie();
	}		
}


//--------------------------------------------------------------
void testApp::draw(){
	if(!omxPlayer.isTextureEnabled)
	{
		return;
	}
	
	omxPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	//draw a smaller version in the lower right
	//int scaledHeight	= omxPlayer.getHeight()/4;
	//int scaledWidth		= omxPlayer.getWidth()/4;
	//omxPlayer.draw(ofGetWidth()-scaledWidth, ofGetHeight()-scaledHeight, scaledWidth, scaledHeight);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	ofxOscMessage m;
	m.setAddress("/startVideo");
	m.addIntArg(1);
	//m.addFloatArg(ofGetElapsedTimef());
	sender1.sendMessage(m);
	sender2.sendMessage(m);
	sender3.sendMessage(m);
	//omxPlayer.restartMovie();
	//shouldRestartVideo = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
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
