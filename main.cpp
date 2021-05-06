//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "block.h"
#include <iostream>
#include <SDL_ttf.h>
#include <vector>
#include <time.h>
using namespace std;



//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();



//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;



bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
   

	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


void draw(Block block){

  
    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    SDL_Rect fillRect = { block.getPosX(), block.getPosY(),block.BLOCK_WIDTH,block.BLOCK_HEIGHT};
    //Render red filled quad
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
    SDL_RenderFillRect( gRenderer, &fillRect );

}

Block loop(Block block){


    SDL_Event e;
    cout<< "block.getlastUpdate() = " <<block.getlastUpdate() << endl;
    Uint32 time = SDL_GetTicks();
	float dT = (time - block.getlastUpdate()) / 1000.0f;
    block.move(dT);
    cout<< "time = "<<time<<endl;
    block.setlastUpdate(time);
    cout<< "block.getlastUpdate() = " <<block.getlastUpdate() << endl;
    draw(block);
    return block;

}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;


        Block block;
        block.setlastUpdate(SDL_GetTicks());
        block.setBorn(SDL_GetTicks());
        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }
            srand(time(NULL));

            Uint32 totalFrameTicks = 0;
            Uint32 totalFrames = 0;

            totalFrames++;
            Uint32 startTicks = SDL_GetTicks();
            Uint64 startPerf = SDL_GetPerformanceCounter();


            
            block = loop(block);
            

            //Update screen
            SDL_RenderPresent( gRenderer );
           // End frame timing
            Uint32 endTicks = SDL_GetTicks();
            Uint64 endPerf = SDL_GetPerformanceCounter();
            Uint64 framePerf = endPerf - startPerf;
            float frameTime = (endTicks - startTicks) / 1000.0f;
          
            // Display strings
            cout<< frameTime << endl;
            SDL_Delay(floor(16.666f - frameTime));

            
            // Display window
            SDL_RenderPresent(gRenderer);
        }
		
	}

	//Free resources and close SDL
	close();

	return 0;
}
