#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -100;
    y = -10;
    speedX = 0.15;
    speedY = 0.15;
    img.loadImage("tanyu.jpg");
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -1695) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -168) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    
    ofSetColor(150,150,30);
    img.draw(x, y, img.width, img.height);
    
}
