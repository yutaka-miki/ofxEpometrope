#include "ofxEpometrope.h"

ofxEpometrope::ofxEpometrope(){}

int ofxEpometrope::getHeight(){return Height;}
int ofxEpometrope::getWidth(){return Width;}

float ofxEpometrope::getDirection(){return dir2;}
bool ofxEpometrope::getReset(){return reset;}
void ofxEpometrope::setReset(int a){reset = a;}

bool ofxEpometrope::getGPIOPhotoReflector(){return gpioRead(GPIOPhotoReflector);}
int ofxEpometrope::getBaseDirection(){return BaseDir;}
int ofxEpometrope::getDirTotal(){return DirTotal;}

// void ofxEpometrope::resetZero(){
//     reset = 0;
// }

void ofxEpometrope::setup(){

    //大きすぎるデータの読み込みは動作に影響を与えるので注意！

    Width = ofToInt(ofBufferFromFile("/home/pi/openFrameworks/addons/ofxEpometrope/setting/Width").getText());
    Height= ofToInt(ofBufferFromFile("/home/pi/openFrameworks/addons/ofxEpometrope/setting/Height").getText());

    // Width = 800;
    // Height = 480;

    ofSetVerticalSync(false);
    // ofSetFrameRate(300);
    ofSetWindowShape(Width,Height);
    ofHideCursor();
    
    GPIOPhotoReflector =  ofToInt(ofBufferFromFile("/home/pi/openFrameworks/addons/ofxEpometrope/setting/GPIOPhotoReflector").getText());
    gpioInitialise();
    gpioSetMode(GPIOPhotoReflector,PI_INPUT);
    gpioSetMode(20,PI_OUTPUT);//master
    gpioSetMode(16,PI_INPUT);//slave

    MorS =  ofToInt(ofBufferFromFile("/home/pi/openFrameworks/addons/ofxEpometrope/setting/master_or_slave").getText());
    int dirAdjust = ofToInt(ofBufferFromFile("/home/pi/openFrameworks/addons/ofxEpometrope/setting/dirAdjust").getText()); // min:0  max:DirTotal/2
    if(MorS == 0){
        BaseDir = 0 + dirAdjust;
    }
    if(MorS == 1){
        BaseDir = DirTotal/2 + dirAdjust;
    }

    touch.init("/dev/input/event0");    // change according to your setup (evdev)
    ofLog()<<touch.getName();

    //i2c(Top)-----------------------------------------------------
    /*
    handle = i2cOpen(1,0x04,0);//master
    if(handle<0) {std::cout << "can not open i2c" << endl; }
    xfer.control = (0x04<<16) | 0x305 ;
    */
    //i2c(Bottom)--------------------------------------------------

}

void ofxEpometrope::update(){

    // if(gpioRead(16) == 1 ){
    if(gpioRead(16) == 1 || reset == 1){
        if( pReset == 0 ){
            reset = 1;
            gpioWrite(20,1);//master
        }else{
            reset = 0;
        }
        pReset = 1; 
    }else{
        // reset = 0;
        gpioWrite(20,0); //master
        pReset =  0;   
    }//if(gpioRead(16) == 1 ||  loadMovie.getCurrentFrame()  >= TotalFrame ){

    if(ofGetFrameRate() != 0){ deltaTime1= deltaTime1+ 1/ofGetFrameRate(); }

    if(gpioRead(GPIOPhotoReflector) == 1 ){
        
        if(pGM == 0 ){
            dir1 = BaseDir ;
            dir2 = dir1;

            if(deltaTime1 != 0){
              dirSpeed  =  DirTotal / (2 * deltaTime1) ;
            }else{
               dirSpeed = 1;
            }
            deltaTime1 = 0;
        }
        pGM = 1;

    }else{
        
        if(pGM == 1 ){
            dir1 = dir1 + DirTotal/2  ;
            if(dir1 <  0 || DirTotal <=  dir1){  dir1 = float(fmod(dir1,DirTotal)); }
            dir2 = dir1;

            if(deltaTime1 != 0){
                dirSpeed  =  DirTotal / (2 * deltaTime1) ;
            }else{
               dirSpeed = 1;
            }
            deltaTime1 = 0;
        }
       pGM = 0;

    } //if(gpioRead(GPIOPhotoReflector) == 1 ){

    if(ofGetFrameRate() != 0){ deltaTime2 = deltaTime2 + 1 / ofGetFrameRate(); }

     dir2 = dir2 +dirSpeed *deltaTime2  ;
    if(dir2 <  0 || DirTotal <=  dir2){  dir2 = float(fmod(dir2,DirTotal)); }
    deltaTime2 = 0;

    if(touch.getButton() == 1){ ofExit(); }

    //i2c(Top)-----------------------------------------------------
    /*
    i_i2c++;
    if(i_i2c >= 3){
        i_i2c = 0;
        //送信量を増やすと動かなくなることがあるので注意！
        
        if(MorS == 0){
            char buf[2] = {(char)CheckSpeed,(char)Check_Angle }; 
            result = i2cWriteI2CBlockData(handle,0x00,buf,2);
            if( result < 0 ) { std::cout << "can not send Data" << endl; }
        }
        if(MorS == 1){
            status = bscXfer(&xfer);
            if(xfer.rxCnt > 0){
                a = xfer.rxBuf[1];
                CheckSpeed = (unsigned char)a;
                a = xfer.rxBuf[2];
                Check_Angle = (unsigned char)a;
            }
        }
    }
    */
    //i2c(Bottom)--------------------------------------------------

}

void ofxEpometrope::draw(){

    if(Check_Angle== 1){
        X = Width/(DirTotal-1) ;
        ofBackground(0);
        if(int(dir2) == 0){
            x = int(dir2)+ mid ;
            ofSetColor(255);
        }
        if(1 <= int(dir2) && int(dir2) <= mid){
            x = int(dir2)+ mid ;
            ofSetColor(0,0,255);
        }
        if(mid+1 <= int(dir2) && int(dir2) <= DirTotal-1){
            x = int(dir2)+mid-DirTotal;
            ofSetColor(255,0,0);
        }
        ofRect(X*x,0,X,Height);
        ofSetColor(255);
    }

    if(CheckSpeed== 1){
        ofBackground(0);
        ofSetColor(255);
        if(dirSpeed > 65.0 ){ ofSetColor(255,0,0); }
        if(dirSpeed < 55.0 ){ ofSetColor(0,0,255); }
        ofRect(Width-(200*dirSpeed/DirTotal),0,Width,Height);
        ofSetColor(255);
    }

}

void ofxEpometrope::keyPressed(int key){
 
    if (key == 'q'){ 
        if(Check_Angle == 0){
            Check_Angle = 1;
        }else{
            Check_Angle = 0;
        }   
    }

    if (key == 'w'){ 
        if(CheckSpeed == 0){
            CheckSpeed = 1; 
        }else{
            CheckSpeed = 0; 
        }
    }

}