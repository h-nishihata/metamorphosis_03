//
//  sandPainter.h
//  metamorphosis_03
//
//  Created by Lancelot on 2014/05/14.
//
//

#ifndef SANDPAINTER
#define SANDPAINTER

#include "ofMain.h"
class sandPainter{
public:
    sandPainter();
    void setup();
    void update();
    void render(float x, float y, float ox, float oy);
    
    float p;
    float g;
};

#endif