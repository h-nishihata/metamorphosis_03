#include "TestLayer2.h"


//--------------------------------------------------------------------------------------------------------------
void TestLayer2::setup(){
    
    fbo.allocate(1440, 900);
    processFbo.allocate(1440, 900);
    
    image.loadImage("taikan.jpg");
    pixels = image.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 1440 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
//        pens[i].setX(ofRandom(0,1440));
//        pens[i].setY(ofRandom(0,900));

    }
    alpha = 60;
    end_0 = true;
    end_1 = true;
    
//    for (int k=0; k<NUM*2.2; k++) {
//        int a = ofRandom(NUM);
//        int b = (a + ofRandom(22));
//
//        if (b > NUM) {
//            b = 0;
//        }else if (b < 0){
//            b = 0;
//        }
//        if (a != b) {
//            pens[a].connectTo(b);
//            pens[b].connectTo(a);
//        }
//    cout << b << endl;
//        cout << a << " made friends with " << b <<endl;
//    }
//    for (int j=0; j<NUM; j++) {
//        cout << pens[j].centx << endl;
//    }

}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::update(){

    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::draw(){
    
    ofTranslate(0, 900);
    ofRotateX(180);

//// setting
//    if (end_0 == true) {
//        waiting_1++;
//        if (alpha < 60) {
//            alpha+=0.1;
//        }
//    }
//    
//// phase 1
//    if (end_1 == true) {
//    if (waiting_2 < 80) {
//            waiting_2++;
//    }else{
//        end_0 = false;
//        end_2 = true;
//        if (alpha > 0) {
//            alpha-=5;
//        }
//    }
//    }
//
//// elase all
//    if (end_2 == true) {
//        if (waiting_3 < 700) {
//            waiting_3++;
//        }else{
//            end_1 = false;
//            end_3 = true;
//            if (alpha < 60) {
//                alpha+=0.1;
//            }
//        }
//    }
//
//// phase 2
//    if (end_3 == true) {
//        if (waiting_4 < 80) {
//            waiting_4++;
//        }else{
//            end_2 = false;
//            end_4 = true;
//            if (alpha > 0) {
//                alpha-=5;
//            }
//        }
//    }
//    
//// reset
//    if (end_4 == true) {
//        if (waiting_5 < 700) {
//            waiting_5++;
//        }else{
//            waiting_1 = waiting_2 = waiting_3 = waiting_4 = waiting_5 = 0;
//            end_2 = end_3 = end_4 = false;
//            end_0 = end_1 = true;
//        }
//    }
    
    fbo.begin();
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }

//        for (int m=0; m<NUM; m++) {
//        for (int n=0; n<pens[m].numcon; n++) {
//            int fP[n];
//            fP[n] = pens[m].connections[n];
//            pen otherPen;
//            otherPen =  pens[pens[m].connections[n]];
//            float ox = pens[fP[n]].centx;
//            float oy = pens[fP[n]].centy;

//            ofCircle(ox+(pens[m].centx-ox)*sin(ofRandom(1)),
//                     oy+(pens[m].centy-oy)*sin(ofRandom(1)), 10);
//    
//        }
//        }
    
    ofSetColor(200, 180, 100, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);

//    cout << "speedX is " << pens[0].speedX << endl;

    
}
