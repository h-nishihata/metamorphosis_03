#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -10;
    y = -10;
    img.loadImage("taikan.jpg");
    centX = -250;
    centY = -250;
    radius = 100;
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    ang += 0.1;
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){

    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
    
    if (ang > 0 && ang < 360) {
        x = centX + (radius * cos(ang*3.141592/180));
        y = centY + (radius * sin(ang*3.141592/180));
    }
    
    if (ang > 360) {
        ang = 0;
    }
    
    ofSetColor(100, 180, 100, 255);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
//    img.draw(x, y, ofGetWidth()*1.5, ofGetHeight()*1.5);
    
}
