#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

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

void draw()
{
    int xStart = 15;
    int yStart = SCREEN_HEIGHT-15;
    int xEnd = SCREEN_WIDTH-15;
    int yEnd = SCREEN_HEIGHT-15;
    for (int i = 0; i < SCREEN_HEIGHT/2 -15; i = i +15) {
        SDL_SetRenderDrawColor( gRenderer,0, 0, 0, 0 );
        SDL_RenderDrawLine(gRenderer,xStart+i, xEnd-i, yStart-i, yEnd-i );
    }

    int xStart2 = SCREEN_HEIGHT/2;
    int yStart2 = SCREEN_HEIGHT/2;
    int xEnd2 = 15;
    int yEnd2 = SCREEN_HEIGHT-15;

    for (int i = 0; i < SCREEN_HEIGHT-15; i = i +30) {

    SDL_SetRenderDrawColor( gRenderer,0, 0, 0, 0 );
    SDL_RenderDrawLine(gRenderer,xStart2+i/2, yStart2+i/2, xEnd2+i, yEnd2 );
    }
    int xStart3 = SCREEN_HEIGHT/2;
    int yStart3 = SCREEN_HEIGHT/2;
    int xEnd3 = SCREEN_HEIGHT-15;
    int yEnd3 = SCREEN_HEIGHT-15;

    for (int i = 0; i < SCREEN_HEIGHT-15; i = i +30) {

        SDL_SetRenderDrawColor( gRenderer,0, 0, 0, 0 );
        SDL_RenderDrawLine(gRenderer,xStart3-i/2, yStart3+i/2, xEnd3-i, yEnd3 );
    }

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