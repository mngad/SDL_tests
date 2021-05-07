#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "block.h"
#include <iostream>
#include "var.h"
#include <stdlib.h>  

Grid::Grid(){
        GRIDWIDTH = SCREEN_WIDTH / (BLOCK_WIDTH);
        GRIDHEIGHT = SCREEN_HEIGHT / (BLOCK_HEIGHT);

        gridArray = new int[GRIDWIDTH * GRIDHEIGHT];
        for( int i =0; i<GRIDWIDTH * GRIDHEIGHT;i++){
            gridArray[i] = 0;
        }
        

    
}

void Grid::setFilled(int x, int y){
    
    gridArray[x +(GRIDWIDTH * y)] = 1;
    //gridArray[9] = 8;

}
void Grid::setUnFilled(int x, int y){
    gridArray[x +(GRIDWIDTH * y)] = 0;

}

void Grid::printFilled(){
    std::cout<<"0,1,2,3,4,5,6,7,8,9"<<std::endl;
    std::cout<<"0:";
    int count = 0;
    for(int a = 1; a<(GRIDWIDTH * GRIDHEIGHT)+1;a++){
        std::cout<<gridArray[a-1]<<",";
        if(a%(SCREEN_WIDTH/5) == 0 && a != 0) {
            count +=1;
            std::cout<<""<<std::endl;
            std::cout<<count<<":";
        }
    }
    std::cout<<""<<std::endl;

}

bool Grid::checkEmpty(int x, int y){
    if((gridArray[x +(GRIDWIDTH * y)] == 0) || (y == GRIDHEIGHT / 5)){
        return true;
    }
    else{
        //std::cout<<"x = "<<x<<", y = "<<y<<std::endl;
        return false;
    }


}
