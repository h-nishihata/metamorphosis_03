#include "pen.h"

pen::pen(){
    
    centx = ofRandom(1920);
    centy = ofRandom(1200);
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    if (ofRandom(100) > 90) {
        setEraser = true;
    }else{
        setEraser = false;
    }
    
    flag = false;
    a = ofRandom(100, 255);
    waiting = ofRandom(0,80);
        
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
    
    if (flag == false) {
        r+=0.1;
        g+=0.1;
        b+=0.1;
        if(r>=255 || g>=255 || b>=25){
            flag = true;
        }
    }else if (flag == true){
        r-=0.1;
        g-=0.1;
        b-=0.1;
        if(r<=60 || g<=60 || b<=60){
            flag = false;
        }
    }
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a -=0.1; }else{ a = 255; }
    }
    
    
    //  *****   add velocity to position    *****
    
    time++;
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1920 || centx <= 0) {
        centx = ofRandom(1920);
        centy = ofRandom(1200);
    }
    if (centy >= 1200 || centy <= 0) {
        centy = ofRandom(1200);
        centy = ofRandom(1200);
    }
    
    
    float ax = 0.0;
    float ay = 0.0;
    int lencon = (r+g+b)/3;
    
    for (int n=0; n<10; n++) {
        
        float ddx = this[n].centx-centx;
        float ddy = this[n].centy-centy;
        float d = sqrt(ddx*ddx + ddy*ddy);
        float t = atan2(ddy,ddx);
        
        if (this[n].identify > identify) {
            
            if (d>lencon) {
                ax += 10.0 * cos(t);
                ay += 10.0 * sin(t);
            }
        } else {
            
            if (d<lencon) {
                ax += (lencon-d)/10 * cos(t+PI);
                ay += (lencon-d)/10 * sin(t+PI);
            }
        }
        
    }
    
    
    if (flag_t == false) {
        
        speedX += ax/200;
        speedY += ay/200;
        if(time > r+g+b-100){
            flag_t = true;
        }
        
    }else if (flag_t == true){
        
        speedX -= ax/200;
        speedY -= ay/200;
        if(time > r+g+b){
            flag_t = false;
            time = 0;
        }
        
    }
    
    
    speedX *= 0.95;
    speedY *= 0.95;
    
    if (ofRandom(1000)>990) {
        speedX += ofRandom(3) - ofRandom(3);
        speedY += ofRandom(3) - ofRandom(3);
    }
    
    if (speedX == speedY) {
        speedX -= 0.1;
        speedY += 0.1;
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
    
//    if (step < waitCnt) {
//        step++;
//    }
//    else {
    
//        for (int dx=-2; dx<3; dx++) {
//            ofSetColor(r+80,g+80,b+80,a);
//            ofCircle(centx+dx, centy, 1);
//            
//            ofSetColor(r+70,g+70,b+70,a);
//            ofCircle(centx+dx-1, centy-1, 1);
//        }
//        
//        for (int dy=-2; dy<3; dy++) {
//            ofSetColor(r+60,g+60,b+60,a);
//            ofCircle(centx, centy+dy, 1);
//            
//            ofSetColor(r+50,g+50,b+50,a);
//            ofCircle(centx-1, centy+dy-1, 1);
//        }

    if (setEraser) {
        ofSetColor(255, 255, 255, 0);
    }else{
        ofSetColor(r+40, g+40, b+40,a);
    }

    
    
        for (int n=0; n <= 1; n++) {
            ox = this[n].centx;
            oy = this[n].centy;
            
            for (int s=0; s<numsands; s++) {
//                ofSetColor(r+40, g+40, b+40,a);
                sands[s].render(centy, centy, ox, oy);
            }
        }
        
//      }
}