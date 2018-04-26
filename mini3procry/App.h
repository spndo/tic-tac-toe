#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rect.h"
#include <vector>

class App: public GlutApp {
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    std::vector<Rect*> rects;
    std::vector<int> boardState = std::vector<int>(9);
    bool turn = true;
    bool over = false;
    
    bool single = false;
    
    int MS[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};
    
    int sumMS(int index);
    
    int calc(int i1, int i2, int i3);
    
    int checkWin();
    
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
   
    
    
    
    
    
};

#endif
