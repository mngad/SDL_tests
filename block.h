#include <SDL2/SDL.h>
#include "grid.h"

const float GRAVITY = 100.0f; 

class Block
{
    public:
        //The dimensions of the dot


        //Maximum axis velocity of the dot
        static const int BLOCK_VEL = 10;

        //Initializes the variables
        Block(int x,int y);

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Moves the dot
        void move(float, Grid);

        int getPosX();
        int getPosY();
        void setVelX(float);
        void setVelY(float);
        void setBorn(Uint32);
        void setlastUpdate(Uint32);
        Uint32 getlastUpdate();
    private:
        //The X and Y offsets of the dot
        int mPosX, mPosY;

        //The velocity of the dot
        float mVelX, mVelY;

        Uint32 born, lastUpdate;
    
};