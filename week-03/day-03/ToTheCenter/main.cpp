#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;
void HappyLittleLines()
{
    //srand (time(NULL));
    SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH/2-(SCREEN_WIDTH/2)/2, SCREEN_HEIGHT/2-(SCREEN_HEIGHT/2)/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    int x = SCREEN_WIDTH/2-(SCREEN_WIDTH/2)/2;
    int y = 0;
    for (int i = 0; i < 3 ; ++i) {

        y = y + SCREEN_HEIGHT/2-(SCREEN_HEIGHT/2)/2;

        for (int j = 0; j < (SCREEN_WIDTH/2/10) ; ++j) {

            x = x+10;
            SDL_SetRenderDrawColor(gRenderer, rand()%255, rand()%255, rand()%255, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, x, y, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

        }
        x = SCREEN_WIDTH/2-(SCREEN_WIDTH/2)/2;
    }
    x = 0;
    y = SCREEN_HEIGHT/2-(SCREEN_HEIGHT/2)/2;
    for (int k = 0; k < 3 ; ++k) {

        x = x + SCREEN_WIDTH/2-(SCREEN_WIDTH/2)/2;

        for (int l = 0; l < (SCREEN_HEIGHT/2/10) ; ++l) {

            y = y+10;
            SDL_SetRenderDrawColor(gRenderer, rand()%255, rand()%255, rand()%255, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, x, y, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

        }
        y = SCREEN_HEIGHT/2-(SCREEN_HEIGHT/2)/2;
    }

}
void draw()
{


    HappyLittleLines();
    // Create a line drawing function that takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a line from that point to the center of the canvas.
    // Draw at least 3 lines with that function. Use loop for that.
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}