//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "block.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <time.h>
//#include "grid.h"
#include "var.h"
using namespace std;



//Starts up SDL and creates window
bool init();
Grid grid;

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


void draw(vector<Block> blocks){

  
    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    for(Block block : blocks){

        SDL_Rect fillRect = { block.getPosX(), block.getPosY(),BLOCK_WIDTH,BLOCK_HEIGHT};
        //Render red filled quad
        SDL_SetRenderDrawColor( gRenderer, block.color[0], block.color[1], block.color[2], 0xFF );		
        SDL_RenderFillRect( gRenderer, &fillRect );
    }

}

vector<Block> loop(vector<Block> blocks, Grid grid){



    Uint32 time = SDL_GetTicks();
    for(int i = 0; i<blocks.size();i++){
        float dT = (time - blocks[i].getlastUpdate()) / 1000.0f;
        blocks[i].move(dT, grid);

        blocks[i].setlastUpdate(time);
		
        
    }
    draw(blocks);
    return blocks;

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
		int count = 0;
		int bcount = 0;
        vector<Block> blocks;
		// for(int b = 1; b<20;b++){
		// 	for(int i =1;i<20;i++){
				
		// 		Block block(i*5,5*b,bcount);
		// 		blocks.push_back(block);
		// 		bcount+=1;
		// 	}
			
		// 	for(int i =14;i<34;i++){
		// 		Block block(i*5,10*b*2,bcount);
		// 		blocks.push_back(block);
		// 		bcount+=1;
		// 	}
		// }
		srand(time(NULL));
		
        // for(int i =0;i<blocks.size();i++){

		

		// 	blocks[i].setBorn(time);
        //     blocks[i].setlastUpdate(time);
            
        // }
       
        
        //While application is running
        while( !quit )
        {
			
			count +=1;
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }
            

            Uint32 totalFrameTicks = 0;
            Uint32 totalFrames = 0;
			Uint32 time = SDL_GetTicks();	
		
            totalFrames++;
            Uint32 startTicks = SDL_GetTicks();
            Uint64 startPerf = SDL_GetPerformanceCounter();
			int colarr[3] = {255,0,255};
			Block block(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,bcount);
			blocks.push_back(block);
			blocks[bcount].color = colarr;
			blocks[bcount].setBorn(time);
            blocks[bcount].setlastUpdate(time);
			bcount+=1;

			int colarr2[3] = {0,0,255};
			Block block2(SCREEN_WIDTH/3,SCREEN_HEIGHT/3,bcount);
			blocks.push_back(block2);
			blocks[bcount].color = colarr2;
			blocks[bcount].setBorn(time);
            blocks[bcount].setlastUpdate(time);
			bcount+=1;


            
            blocks = loop(blocks, grid);
          

            //grid.printFilled();


           // End frame timing
            Uint32 endTicks = SDL_GetTicks();
            Uint64 endPerf = SDL_GetPerformanceCounter();
            Uint64 framePerf = endPerf - startPerf;
            float frameTime = (endTicks - startTicks) / 1000.0f;
          
            // Display strings
           // cout<< frameTime << endl;
            SDL_Delay(floor(16.666f - frameTime));

            
            // Display window
            SDL_RenderPresent(gRenderer);
			cout<<"count = "<< count<<endl;
			//if(count > 10) break;
        }
		blocks.clear();
		
	}

	//Free resources and close SDL

	close();

	return 0;
}
