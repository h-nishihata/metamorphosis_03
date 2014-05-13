#include "pen.h"

pen::pen(){
    
    centx = ofRandom(0,1440);
    centy = ofRandom(0,900);
    radius = ofRandom(5,20);
    rotate = ofRandom(-1,1);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    lastx = -999;
    lasty = -999;
    
    radiusNoise = ofRandom(10);
    spiral = ofRandom(-1,2);
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    sw = (int)ofRandom(1,8);
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);

//    if (speedX == 0) {
//        speedX = 1;
//    }
//    if (speedY == 0) {
//        speedY = 1;
//    }
//    maxcon = 10;

    
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
void pen::setX(int posX){
    ox = posX;
}

////--------------------------------------------------------------
//void pen::setY(int posY){
//    centy = posY;
//}
//--------------------------------------------------------------
void pen::update(){

    ang += rotate;
    radius += spiral;
    radiusNoise += ofRandom(-0.05, 0.1);
    
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
    
//        float thisRadius = radius + (ofNoise(radiusNoise) * 200) -100;
//        
//        
//        if ((ang > 0 && ang < 360) || (ang < 0 && ang > -360) ) {
//            x = centx + (thisRadius * cos(ang*3.141592/180));
//            y = centy + (thisRadius * sin(ang*3.141592/180));
//            if (lastx > -999) {
                ofSetColor(255,255,255);
//                ofSetColor(r+col,g+col,b,a);
//                ofSetLineWidth(sw);
                for (int n=-2; n<3; n++) {
                ofCircle(centx+n, centy, 10);
                }
for (int n=0; n<64; n++) {

    float d = this[n].centx;
    float e = this[n].centy;
    ofSetColor(255, 0, 0);
    ofLine(centx, centy, d, e);
//            cout << d << endl;
            }
//
//            lastx = x;
//            lasty = y;
//            
//        }
//        if ((ang > 360) || (ang < -360) ) {
//            ang = 0;
//        }
//        if(radius >= 500){
//            spiral = -spiral;
//        }else if (radius <= 0){
//            spiral = -spiral;
//        }
//    }

}

//--------------------------------------------------------------
void pen::connectTo(int f){

    if (numcon < 10) {
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


