#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
    rects.push_back(new Rect(-1,0.8,0.66 ,0.59 ));
    rects.push_back(new Rect(-0.33,0.8,0.65,0.59 ));
    rects.push_back(new Rect(0.33,0.8,0.66 ,0.59 ));
    rects.push_back(new Rect(-1,0.2,0.66,0.59 ));
    rects.push_back(new Rect(-0.33,0.2,0.65 ,0.59));
    rects.push_back(new Rect(0.33,0.2,0.66,0.59));
    rects.push_back(new Rect(-1,-0.4,0.66,0.59));
    rects.push_back(new Rect(-0.33,-0.4,0.65 ,0.59));
    rects.push_back(new Rect(0.33,-0.4,0.66,0.59));
    
    
    
    // Board State;
    for (int i = 0; i < 9; i++) {
        boardState[i]=0;
    }
}

void App::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(-1, 0.2);
    glVertex2f(1, 0.2);
    
    glVertex2f(-1, -0.4);
    glVertex2f(1, -0.4);
    
    glVertex2f(-1, 0.8);
    glVertex2f(1, 0.8);
    
    glVertex2f(-0.33, 0.8);
    glVertex2f(-0.33, -1);
    
    glVertex2f(0.33, 0.8);
    glVertex2f(0.33, -1);
    
    
    
    glEnd();
    
    
//    for (int i = 0; i < rects.size(); i++){
//        std::cout << boardState[i] <<std::endl ;
//        
//    }
//    std::cout<<std::endl;

    
    int win = checkWin();
    //std::cout<<win;
    if (win != 0 && over == false) {
        //std::cout<<win;
        over = true;
        
    }
    if (win == 1)
        
        std::cout<<"cross win";
    
    else if (win == 2)
        std::cout<<"circle win";
    
    
    for (int i = 0; i < rects.size(); i++) {
        if (boardState[i] == 1) {
            rects[i]->drawXO();
            
        }
        
        //player 2
        else if (boardState[i] == 2) {
            rects[i]->cross = true;
            rects[i]->drawXO();
        }
        //win
        else if (boardState[i] == 3) {
            rects[i]->colored();
            rects[i]->drawXO();
         
        }
        
        else if (boardState[i] == 4) {
            rects[i]->cross = true;
            rects[i]->colored();
            rects[i]->drawXO();
        }
        
    }
    
    for (int i = 0; i < rects.size(); i++ ) {
        rects[i]->build();
    }
    
   
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    if (!single) {
        for (int i = 0; i < rects.size(); i++) {
            //two player
            if (rects[i]->contains(x, y) && boardState[i] == 0 && over == false) {
                if (turn == true) {
                    boardState[i] = 1;
                    turn = false;
                }
                else if (turn == false) {
                    boardState[i] = 2;
                    turn = true;
                }
            }
        }
    }
    
    else if (single) {
        for (int i = 0; i < rects.size(); i++) {
            if (rects[i]->contains(x, y) && boardState[i] == 0 && over == false) {
                if (boardState[i] == 0) {
                    boardState[i] = 1;
                    
                }
                
                int count = 0;
                for (int j = 0; j < 9; j++) {
                    if (boardState[j] == 1) {
                        count++;
                    }
                }
                
                
                if (count >= 1 ) {
                    
                    int cont = 0;
                    for (int j = 0; j < 9; j++) {
                        if (boardState[j] == 0 ) {
                            boardState[j] = 2;
                            
                            break;
                        }
                        
                        
                        if (boardState[8] == 0 && j == 8) {
                            boardState[8] = 0;
                        }
                    }
                }
                
            }
        }
        
    }
    
    // Redraw the scene
    redraw();
}


int App::sumMS(int index) {
    return boardState[index] * MS[index];
}

int App::calc(int i1, int i2, int i3) {
    int s = 0;
    
    s = sumMS(i1) + sumMS(i2) + sumMS(i3);
    
    if (s == 15) {
        //win
        boardState[i1] = 3; boardState[i2] = 3; boardState[i3] = 3;
        
        return 1;
    }
    //stop playing the game after winning
    if (s == 30) {
        boardState[i1] = 4; boardState[i2] = 4; boardState[i3] = 4;
        return 2;
    }
    return 0;
}

int App::checkWin() {
    if (over)
        return 0;
    
    int val = 0;
    for (int i = 0; i < 9; i+=3) {
        if (!val) {
            val = calc(i, i + 1, i + 2);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (!val) {
            val = calc(i, i + 3, i + 6);
        }
    }
    
    
    if (!val) {
        val = calc(0, 4, 8);
    }
    
    if (!val) {
        val = calc(2, 4, 6);
    }



    
    return val;
    
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == '1') {
        single = true;
    }
    
    if (key == '2') {
        single = false;
    }

    
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
