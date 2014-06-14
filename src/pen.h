#ifndef _OF_PEN
#define _OF_PEN

#define numsands 10 // 10

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    
    //  stroke
    int centx;
    int centy;
    int identify;
    int ox;
    int oy;
    int time;
    bool flag_t;
    float speedX;
    float speedY;

    int waitCnt;
    int step;

    
    //  colors
    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    
    
    //  functions
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);

    sandPainter sands[numsands];
    
};

#endif
