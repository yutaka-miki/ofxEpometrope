#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    MyClass m;

    font.load("RictyDiminished-Regular.ttf",12);

    epome.setup();

    loadMovie.load(ofBufferFromFile("loadMovie").getText());
    TotalFrame = loadMovie.getTotalNumFrames();
    ofSleepMillis(1000);
    loadMovie.setFrame(0);
    loadMovie.play();

}

//--------------------------------------------------------------
void ofApp::update(){

    epome.update();

    if(epome.getReset() == 1 || loadMovie.getCurrentFrame()  >=  TotalFrame){
        epome.setReset(1);
        loadMovie.stop();
        loadMovie.setFrame(1);
        loadMovie.play();
    } 

}

//--------------------------------------------------------------
void ofApp::draw(){

    int Height = epome.getHeight();
    int Width = epome.getWidth();
    float dir = epome.getDirection();
    loadMovie.update();

    if(dir < H){
            loadMovie.draw(0, Height*(int(dir)%H-H+1), Width*W , Height*H);
    }else if(H <= dir && dir < 2*H){
            loadMovie.draw(-Width,Height*(int(dir)%H-H+1), Width*W, Height*H);
    }else if(2*H <= dir && dir < 3*H){
            loadMovie.draw(-2*Width, Height*(int(dir)%H-H+1), Width*W, Height*H);
    }else if(3*H <= dir && dir < 4*H){
            loadMovie.draw(-3*Width, Height*(int(dir)%H-H+1), Width*W, Height*H);
    }

    if(Check_Movie == 1){
        loadMovie.draw(0,0,Width,Height);
    }

     if(text == 1){
        // ofBackground(0);
        ofSetColor(255);
        font.drawString("Framerate: " + ofToString(ofGetFrameRate()) , 10, 20);
        
        font.drawString("Direction: " + ofToString(dir) , 10, 60);
        font.drawString("BaseDirection: " + ofToString(epome.getBaseDirection()) , 10, 80);
        font.drawString("GPIOPhotoReflector: " + ofToString(epome.getGPIOPhotoReflector()) , 10, 100);

        font.drawString(ofToString(loadMovie.getCurrentFrame()) + " / "  + ofToString(TotalFrame) , 10, 140);
    }

     epome.draw();

}

void ofApp::keyPressed(int key){

    if (key == 'b'){ 
        if(Check_Movie == 0){
            Check_Movie = 1;
        }else{
            Check_Movie= 0;
        }   
    }

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

 // Paste from Template (bottom) ----------------------------------
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
