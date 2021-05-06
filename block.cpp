//The dot that will move around on the screen
#include <SDL.h>
#include <SDL_image.h>
#include "block.h"



Block::Block(){
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Block::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + BLOCK_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
        //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + BLOCK_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}
SDL_Rect Block::render()
{
    //Show the dot
    SDL_Rect fillRect = { mPosX, mPosY,BLOCK_WIDTH,BLOCK_HEIGHT};
    return fillRect;
}

