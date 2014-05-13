#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:
    
    float centx;
    float centy;
    int radius;
    int ang;
    int rotate;
    float x, y;
    int lastx, lasty;
    
    float radiusNoise;
    float spiral;
    int waitCnt;
    int step;

    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    int sw;
    int speedX;
    int speedY;
    
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setX(int posX);
//    void setY(int posY);
    float ox;
    
//    int maxcon;
    int numcon;
    void connectTo(int f);
    int connections[10];
    bool friendOf(int x);


};

#endif
