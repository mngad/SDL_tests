//The dot that will move around on the screen
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "block.h"
#include <iostream>
#include "var.h"

using namespace std;


Block::Block(int x, int y){
    //Initialize the offsets
    mPosX = x;
    mPosY = y;

    //Initialize the velocity
    mVelX = 0.f;
    mVelY = 0.f;

    Uint32 born, lastUpdate;
}

void Block::move(float dT, Grid grid)
{   
    //cout << dT << endl;
    //cout<< mVelY <<endl;
    grid.setUnFilled(mPosX/5,mPosY/5);
    int oldmPosX = mPosX;
    int oldmPosY = mPosY;
    if(mPosY + BLOCK_HEIGHT>= SCREEN_HEIGHT){
        mPosY = SCREEN_HEIGHT - BLOCK_HEIGHT;
        mVelY = 0.0f;
    }
    else{
        mVelY += dT * GRAVITY;
        mPosY += mVelY * dT;
        //cout<< "mpos before"<<mPosY <<endl;
        if( mPosY % 5 != 0 ){
            if(mPosY % 5 ==3) mPosY += 2;
            if(mPosY % 5 ==4) mPosY += 1;
            if(mPosY % 5 ==2) mPosY -= 2;
            if(mPosY % 5 ==1) mPosY -= 1;
        }
    }
    // if(grid.checkEmpty(mPosX/5, mPosY/5) == true){
    //     mPosX = oldmPosX;
    //     mPosY = oldmPosY;
    // }
    grid.setFilled(mPosX/5,mPosY/5);
    cout<< "mVelY after "<< mVelY/5 <<endl;
    cout<< "mposY after "<< mPosY/5 <<endl;

}


int Block::getPosX(){
    return mPosX;
}
int Block::getPosY(){
    return mPosY;
}
void Block::setVelX(float VelX){
    mVelX = VelX;

}
void Block::setVelY(float VelY){
    mVelY = VelY;
}
void Block::setBorn(Uint32 _born){
    born = _born;
}
void Block::setlastUpdate(Uint32 _lastUpdate){
    lastUpdate = _lastUpdate;
}

Uint32 Block::getlastUpdate(){
    return lastUpdate;
}


