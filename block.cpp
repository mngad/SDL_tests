//The dot that will move around on the screen
#include <SDL.h>
#include <SDL_image.h>
#include "block.h"
#include <iostream>

using namespace std;


Block::Block(){
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0.f;
    mVelY = 0.f;

    Uint32 born, lastUpdate;
}

void Block::move(float dT)
{   
    cout << dT << endl;
    cout<< mVelY <<endl;
 
    if(mPosY + BLOCK_HEIGHT>= SCREEN_HEIGHT){
        mPosY = SCREEN_HEIGHT - BLOCK_HEIGHT;
        mVelY = 0.0f;
    }
    else{
        mVelY += dT * GRAVITY;
        mPosY += mVelY * dT;
    }


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


