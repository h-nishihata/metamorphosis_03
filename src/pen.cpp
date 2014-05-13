#include "pen.h"

pen::pen(){
    
    centx = ofRandom(0,1440);
    centy = ofRandom(0,900);
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    speedX = ofRandom(-5,5);
    speedY = ofRandom(-5,5);
    
    if (speedX == 0) {
        speedX = 1;
    }
    if (speedY == 0) {
        speedY = 1;
    }
    
    maxcon = 10;
    connections[maxcon];
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
//void pen::setID(int ID){
//    identify = ID;
//}

//--------------------------------------------------------------
void pen::update(){
    
    //    if (flag == false) {
    //        col+=0.1;
    //        if(col > 200){
    //            flag = true;
    //        }
    //    }else if (flag == true){
    //        col-=0.1;
    //        if(col < 0){
    //            flag = false;
    //        }
    //    }
    
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1440 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 900 || centy <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
//    if(waiting < 80){
//        waiting++;
//    }else{
//        if(a > 0){ a --; }else{ a = 255;}
//    }
//    
//    if (step < waitCnt) {
//        step++;
//    }
//    else {
    
        //    ofSetColor(255, 0, 255);
        //    ofCircle(centx, centy, 20);
        
        
        for (int dx=-2; dx<3; dx++) {
            //            ofSetColor(r+50, g+50, b, a);
            ofSetColor(255,0,0);
            ofCircle(centx+dx, centy, 1);
            //            ofSetColor(r-50, g-50, b, a);
            ofSetColor(0,255,0);
            ofCircle(centx+dx-1, centy-1, 1);
        }
        
        for (int dy=-2; dy<3; dy++) {
            //            ofSetColor(r+20, g+20, b, a);
            ofSetColor(0,0,255);
            ofCircle(centx, centy+dy, 1);
            //            ofSetColor(r-20, g-20, b, a);
            ofSetColor(255,255,0);
            ofCircle(centx-1, centy+dy-1, 1);
        }
        
        //  **********
        float p = ofRandom(1.0);
        float g = ofRandom(0.01, 0.1);
        g += ofRandom(-0.050, 0.050);
        
        float maxg = 0.22;
        
        if (g < -maxg) {
            g = -maxg;
        }else if (g > maxg){
            g = maxg;
        }
        
        float w =g/10.0;
        
        for (int n=0; n <= 4; n++) {
            ox = this[n].centx;
            oy = this[n].centy;
            //        cout << n << " : " << this[n].centx << endl;
            //        if( ox == 0){
            //            ox = ofRandom(0,1440);
            //        }else if(oy == 0){
            //            oy = ofRandom(0,900);
            //        }
            ofSetColor(255);
            if( ox != 0 && oy != 0){
                ofCircle(ox+(centx-ox)*sin(p),
                         oy+(centy-oy)*sin(p), 1);
                
                
                
                for (int i=0; i<11; i++) {
                    //        ofSetColor(r, g, b, a);
                    ofSetColor(0,255,255);
                    ofCircle(ox+(centx-ox)*sin(p + sin(i*w)),
                             oy+(centy-oy)*sin(p + sin(i*w)), 1);
                }
            }
        }
        
//    }
}

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


