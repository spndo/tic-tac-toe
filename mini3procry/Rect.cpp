//
//  Rect.cpp
//  glutapp
//
//  Created by Test on 2/22/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Rect.h"

using namespace std;


void Rect::drawXO() {
    glColor3f(0.0, 0.0, 0.0);
    
    if (color) {
        glColor3f(0.0, 1.0, 1.0);
    }
    
    if (!cross) {
        float xt = x + 0.2;
        float yt = y - 0.2;

        glBegin(GL_LINES);
        
        glBegin(GL_LINES);
        glVertex2f(xt, yt);
        glVertex2f(xt+0.2, yt-0.2);
        
        glVertex2f(xt+0.2, yt);
        glVertex2f(xt, yt-0.2);
        
        glEnd();
        
    }
    
    else {
        if (color) {
            glColor3f(0.0, 1.0, 1.0);
        }
        
        // Default value to make circle as round as possible.
        float cx = x + 0.3;
        float cy = y - 0.3;
        
        
        
        /* To actually draw circle. */
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++){
            float theta = 2*M_PI/100*i;
            float xx = 0.15*cos(theta)+cx;
            float yy = 0.15*sin(theta)+cy;
            glVertex2f(xx, yy);
        }
        glEnd();
        
    }
    
}

void Rect::colored() {
    color = true;
}

void Rect::build() {
    
    glColor3f(0.0, 0.0, 0.0);
    
    // Draw some rectangles?
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x, y - height);
    glVertex2f(x + width, y - height);
    glVertex2f(x + width, y);
    
    glEnd();
    
}

bool Rect::contains(float xx, float yy){
    if ((xx <= x+width)&&(xx>=x)&&(yy>=(y-height))&&(yy<=y))
        return true;
    else
        return false;
    
}

