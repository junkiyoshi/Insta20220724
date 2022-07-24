#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (int i = 0; i < 450; i++) {

		auto deg = ofRandom(360) + ofGetFrameNum() * ofRandom(0.2, 0.8) * (i % 2 == 0 ? 1 : -1);
		auto radius = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 150, 300);
		auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		auto size = ofRandom(10, 20);
		color.setHsb(ofRandom(255), 255, 255);

		ofFill();
		ofSetColor(color, 128);
		ofDrawCircle(location, size);

		ofNoFill();
		ofSetColor(color);
		ofDrawCircle(location, size);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}