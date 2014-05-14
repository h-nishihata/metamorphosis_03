#ifndef _OF_PEN
#define _OF_PEN

#define numsands 3

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    
    int centx;
    int centy;
    int ox;
    int oy;
    
    int identify;
    int waitCnt;
    int step;

    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    
    int speedX;
    int speedY;
    
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);
    
//    int maxcon;
//    int numcon;
//    int connections[];
//    void connectTo(int f);
//    bool friendOf(int x);

    sandPainter sands[numsands];
    
};

#endif
