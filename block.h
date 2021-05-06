#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class Block
{
    public:
        //The dimensions of the dot
        static const int BLOCK_WIDTH = 20;
        static const int BLOCK_HEIGHT = 20;

        //Maximum axis velocity of the dot
        static const int BLOCK_VEL = 10;

        //Initializes the variables
        Block();

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Moves the dot
        void move();

        //Shows the dot on the screen
        SDL_Rect render();

    private:
        //The X and Y offsets of the dot
        int mPosX, mPosY;

        //The velocity of the dot
        int mVelX, mVelY;
};