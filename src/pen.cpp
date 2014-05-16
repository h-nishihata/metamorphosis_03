#include "pen.h"

pen::pen(){
    
    centx = ofRandom(1440);
    centy = ofRandom(900);
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    //    speedX = 10;
    //    speedY = 10;
    
    //    maxcon = 10;
    //    connections[maxcon];
    
}
//--------------------------------------------------------------
void pen::setup(){
    
}
//--------------------------------------------------------------
void pen::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void pen::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void pen::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void pen::setID(int ID){
    identify = ID;
}

//--------------------------------------------------------------
void pen::update(){
    
    time++;
    /*
     if (flag == false) {
     col+=0.1;
     if(col > 200){
     flag = true;
     }
     }else if (flag == true){
     col-=0.1;
     if(col < 0){
     flag = false;
     }
     }
     */
    
    //  **********
    
    
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1440 || centx <= 0) {
        //        speedX = speedX*-1;
        centx = ofRandom(1440);
    }
    if (centy >= 900 || centy <= 0) {
        //        speedY = speedY*-1;
        centy = ofRandom(900);
    }
    
    float ax = 0.0;
    float ay = 0.0;
    int lencon = ofRandom(50)+10;
    
    for (int n=0; n<10; n++) {
        
        float ddx = this[n].centx-centx;
        float ddy = this[n].centy-centy;
        float d = sqrt(ddx*ddx + ddy*ddy);
        float t = atan2(ddy,ddx);
        
        if (this[n].identify > identify) {
            
            if (d>lencon) {
                ax += 10.0 * cos(t);
                ay += 10.0 * sin(t); // 10.0
            }
        } else {
            
            if (d<lencon) {
                ax += (lencon-d)/10 *cos(t+PI); //(lencon-d)/10 *
                ay += (lencon-d)/10 *sin(t+PI);
            }
        }
        
    }
    

    if (flag_t == false) {
        
        speedX += ax/500; //100
        speedY += ay/500;
        if(time > 200){
            flag_t = true;
        }
        
    }else if (flag_t == true){
        
        speedX -= ax/500; //100
        speedY -= ay/500;
        if(time > 400){
            flag_t = false;
            time = 0;
        }
        
    }

    speedX *= 0.99;
    speedY *= 0.99;
    
    if (speedX == speedY) {
        speedX += ofRandom(-0.1, 0.1);
        speedY += ofRandom(-0.1, 0.1);
    }
    
    if (speedX == 0) {
        speedX = ofRandom(-0.1, 0.1);
    }
    
    if (speedY == 0) {
        speedY = ofRandom(-0.1, 0.1);
    }
    
}

//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a --; }else{ a = 255;}
    }
    
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        for (int dx=-2; dx<3; dx++) {
            ofSetColor(r+20,g+20,b+20,a);
            ofCircle(centx+dx, centy, 1);
            
            ofSetColor(r-20,g-20,b-20,a);
            ofCircle(centx+dx-1, centy-1, 1);
        }
        
        for (int dy=-2; dy<3; dy++) {
            ofSetColor(r+50,g+50,b+50,a);
            ofCircle(centx, centy+dy, 1);
            
            ofSetColor(r-50,g-50,b-50,a);
            ofCircle(centx-1, centy+dy-1, 1);
        }
        
        
        //  **********

        for (int n=0; n <= 10; n++) {
            ox = this[n].centx;
            oy = this[n].centy;
            
            for (int s=0; s<numsands; s++) {
                ofSetColor(r,g,b);
                sands[s].render(centy, centy, ox, oy);
            }
        }

    }
}

/*
 //--------------------------------------------------------------
 void pen::connectTo(int f){
 
 if (numcon < maxcon) {
 if (! friendOf(f)) {
 connections[numcon] = f;
 numcon++;
 }
 }
 
 }
 
 //--------------------------------------------------------------
 bool pen::friendOf(int x){
 
 bool isFriend = false;
 for (int n=0; n<numcon; n++) {
 if (connections[n] == x) {
 isFriend = true;
 }
 }
 return isFriend;
 
 }
 */

