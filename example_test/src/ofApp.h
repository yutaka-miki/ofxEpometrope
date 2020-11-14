#pragma once
#include "ofMain.h"

#include "ofxEpometrope.h"

class MyClass{

public:
	void set(int _i, float _f){
		i = _i; f = _f;
	};

	int i;
	float f;
};

class ofApp : public ofBaseApp{
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxEpometrope epome;

		ofTrueTypeFont font;
		bool text;
		
		ofEasyCam cam;

		float t = 0.0;
		float tDeg = 0.0;

		int StartPoint = 300;
		int BoxSize = 50;

		float brightness2 = 0.5;
		float brightness3 = -0.5;

		float camDeg = 0;
		int camDis = 1500;

		ofSpherePrimitive moon;	

		ofLight PointLight2;
		ofLight PointLight3;

		ofPoint LightPoint4 = ofPoint(-1000,250,-500); 
		ofPoint LightPoint5 = ofPoint(-1000,250,500); 

		bool flatMoon = 0;
		bool solidMoon = 0;
		bool nomBoxes = 0;

		float camRotateSpeed = 0.3;

		float elapsed4;
		float elapsed7;

};
