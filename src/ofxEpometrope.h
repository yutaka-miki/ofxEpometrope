#pragma once
#include "ofMain.h"

#include "math.h"
#include "pigpio.h"
#include "ofxRPiTouch.h"

class ofxEpometrope {

public:
    ofxEpometrope();
    int getWidth();
    int getHeight();
    float getDirection();
    int getBaseDirection();
    bool getReset();
    void setReset(int a);
    bool getGPIOPhotoReflector();
    int getDirTotal();
    

    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofxRPiTouch touch;
    vector <int> fingersFound;
    // ofTrueTypeFont font;

    int Width; //public
    int Height; //public

    bool pGM = 0;
    bool pReset = 0;
    bool reset = 0; //public

    float deltaTime1 = 0.0;
    float deltaTime2 = 0.0;

    float dir1 = 0.0;
    float dir2 = 0.0; //public
    float dirSpeed = 10.0;
    int DirTotal = 16;//public
    int mid = (DirTotal-2)/2;

    int MorS;
    int BaseDir;
    int GPIOPhotoReflector;
    int GPIO1 = 20; 
    int GPIO2 = 16; 

    float X;
    float x;

    bool Check_Angle = 0;
    bool CheckSpeed = 0;

    // bool text = 0;
   

    //i2c(Top)-----------------------------------------------------
    /*
    int i_i2c;
    int handle;//master
    int result;//master
    bsc_xfer_t xfer; //slave
    int status;//slave
    char a ;
    */
    //i2c(Bottom)--------------------------------------------------

};