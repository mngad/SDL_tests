//The dot that will move around on the screen
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "block.h"
#include <iostream>
#include "var.h"

using namespace std;


Block::Block(int x, int y, int _ID){
    //Initialize the offsets
    color = new int[3];

    mPosX = x;
    mPosY = y;
    ID = _ID;
    //Initialize the velocity
    mVelX = 0.f;
    mVelY = 0.f;

    Uint32 born, lastUpdate;
}

void Block::move(float dT, Grid grid)
{   
    

    if(mVelY + (dT * GRAVITY)<1000) mVelY +=(dT * GRAVITY);
    
 
    int oldmPosX = mPosX;
    int oldmPosY = mPosY;
    // cout<<"mPosY + BLOCK_HEIGHT = "<<mPosY + BLOCK_HEIGHT<<endl;
    // cout<<"SCREEN_HEIGHT = "<<SCREEN_HEIGHT<<endl;
    if(mPosY + BLOCK_HEIGHT>= SCREEN_HEIGHT){
        mPosY = SCREEN_HEIGHT - BLOCK_HEIGHT;
        mVelY = 0.0f;
    }
    else{
        
        
      
        mPosY += mVelY * dT;
        //cout<< "mpos before"<<mPosY <<endl;
        if( mPosY % 5 != 0 ){
            if(mPosY % 5 ==3) mPosY += 2;
            if(mPosY % 5 ==4) mPosY += 1;
            if(mPosY % 5 ==2) mPosY -= 2;
            if(mPosY % 5 ==1) mPosY -= 1;
        }
        if((mVelY * dT)>=3){ //if its nt going to move then don't check if the space is free
            //cout<<"posy after move, before check = "<<mPosY/5<<endl;
            if(grid.checkEmpty(mPosX/5, mPosY/5) == false)
            {
                //srand (time(NULL));
                int ran = rand() % 2;
                //cout<<"ran = "<<ran<<endl;

                
                mPosY = oldmPosY;
                
// checks for left right diag movement
                if(ran ==0 && (mPosX + 5)<=SCREEN_WIDTH){
                    if(grid.checkEmpty((mPosX + 5)/5, (mPosY+5)/5) == true){
                        mPosX+=5;
                        mPosY+=5;
                    }
                    else if(grid.checkEmpty((mPosX+5)/5, mPosY/5) == true) mPosX+=5;

                }
                if(ran ==1 && (mPosX - 5)>=0){
                    if(grid.checkEmpty((mPosX-5)/5, (mPosY+5)/5) == true){
                       mPosX-=5; 
                       mPosY +=5;
                    }
                    else if(grid.checkEmpty((mPosX-5)/5, mPosY/5) == true) mPosX-=5;

                }
                if(mVelY - (dT * GRAVITY)>0) mVelY -=(dT * GRAVITY);
                

                //cout<<"here"<<endl;
            }
        }
        grid.setUnFilled(oldmPosX/5,oldmPosY/5);
        grid.setFilled(mPosX/5,mPosY/5);
    }
    
    // cout<< "mVelY after "<< mVelY <<endl;
    // cout<< "mposY after "<< mPosY/5 <<endl;
    // cout<< "mVelX after "<< mVelX <<endl;
    // cout<< "mposX after "<< mPosX/5 <<endl;
    //cout<< "Vel, after = "<<mVelY <<endl;

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


