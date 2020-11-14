
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    MyClass m;

    font.load("RictyDiminished-Regular.ttf",12);

    epome.setup();

    ofEnableDepthTest();
    cam.setDistance(camDis); //EasyCam
    cam.setFov(10.0f);

}

//--------------------------------------------------------------
void ofApp::update(){

    epome.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    camDeg = 360/epome.getDirTotal()*int(epome.getDirection());
    cam.orbitDeg(0,camDeg,camDis,{-260,0,0});
    cam.rotate(-10.0,0.0,cos(camDeg*PI/180),sin(camDeg*PI/180));

    cam.begin();

        ofBackground(0);

        if(ofGetFrameRate() != 0){ t += 20 / ofGetFrameRate(); }
        if(epome.getReset() == 1 || t >= 720){
            epome.setReset(1);
            t = 0;
        } 

        tDeg = t * PI/180;
        
        PointLight2.setAmbientColor(ofFloatColor(brightness2));
        PointLight2.setAmbientColor(ofFloatColor(-0.1));
        PointLight2.setPosition(LightPoint4);
        PointLight2.enable(); 
        
        PointLight3.setAmbientColor(ofFloatColor(brightness2));
        PointLight3.setAmbientColor(ofFloatColor(0.0));
        PointLight3.setPosition(LightPoint5);
        PointLight3.enable(); 
        int BoxRotate = t/2;

        ofSetColor(255);

        ofPushMatrix();
            ofTranslate(140*cos(-tDeg-0.3*PI),-30,-20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),50);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(140*cos(-tDeg),30,0);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),60);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(130*cos(-tDeg+0.1*PI),70,10);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),40);    
        ofPopMatrix();

        ofPushMatrix();
            ofTranslate(60*cos(-tDeg-0.8*PI),-50,0);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),60);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(60*cos(-tDeg-0.6*PI),-10,-40);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),70);    
        ofPopMatrix();
        ofPushMatrix();
            ofTranslate(70*cos(-tDeg-0.2*PI),20,20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),80);    
        ofPopMatrix();

        ofPushMatrix();
            ofTranslate(90*cos(-tDeg+0.9*PI),-10,-20);
            // ofRotateDeg(t,45,45,45);
            ofRotateDeg(20,0,1,0);
            ofRotateDeg(BoxRotate,1,0,0);
            ofDrawBox(ofPoint(0,0,0),45);    
        ofPopMatrix();

        //中心点
        // ofPushMatrix();
        //     ofSetColor(255,0,0);
        //     ofDrawSphere(ofPoint(0,0,0),1);   
        // ofPopMatrix();

        //中心線
        // ofDrawLine(-ofGetWidth()/2, 0, 0, ofGetWidth()/2, 0, 0);
            
        PointLight3.disable();
        PointLight2.disable();
    
    cam.end();

    if(text == 1){
        // ofBackground(0);
        ofSetColor(255);
        font.drawString("Framerate: " + ofToString(ofGetFrameRate()) , 10, 20);
        
        font.drawString("Direction: " + ofToString(epome.getDirection()) , 10, 60);
        font.drawString("BaseDirection: " + ofToString(epome.getBaseDirection()) , 10, 80);
        font.drawString("GPIOPhotoReflector: " + ofToString(epome.getGPIOPhotoReflector()) , 10, 100);

        font.drawString( "t:  "  + ofToString(t) , 10, 140);
    }

     epome.draw();

}

void ofApp::keyPressed(int key){

    if (key == 'r'){
        epome.setReset(1);
    }

    if (key == 't'){ 
        if(text == 0){
            text = 1;
        }else{
            text = 0;
        }
    }

    epome.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
