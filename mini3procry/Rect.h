//
//  Rect.hpp
//  glutapp
//
//  Created by Test on 2/22/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <stdio.h>
#include "GlutApp.h"
#include <math.h>


class Rect{
    float x;
    float y;
    float width;
    float height;
    
   
    
    
    //    float mx;
    //    float my;
    //
    
public:
    Rect(){
        x = 0.0;
        y = 0.0;
        width = 0.0;
        height = 0.0;
        
    }
    
    Rect (float x,float y, float width, float height){
        this -> x = x;
        this -> y = y;
        this -> width = width;
        this -> height = height;
        
        
        
    }
    
    
    
    float getX() {
        return x;
    }
    
    float getY() {
        return y;
    }
    
    float getW() {
        return width;
    }
    
    float getH() {
        return height;
    }
    
    void setX(float xx){
        //this -> x = x;
        xx = x;
    }
    
    void setY(float yy){
        //this -> y = y;
        yy = y;
    }
    
    void setW(float widthh){
        //this -> width = width;
        widthh = width;
    }
    
    void setH(float heightt){
        // this -> height = height;
        heightt = height;
    }
    
    
    
    void build();
    
    void drawXO();
 
    bool color = true;
    
    bool cross = false;
    
    void colored();
    
    bool contains(float x, float y);
    
    
    //new var
       
    ~Rect();
    
    
    
};


#endif /* Rect_hpp */
