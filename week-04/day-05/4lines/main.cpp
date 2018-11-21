#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 900;

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

void lines(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8, int depth){
 if(depth == 5){
     return;
 }
SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
 SDL_RenderDrawLine(gRenderer, x3, y3, x4, y4);
 SDL_RenderDrawLine(gRenderer, x5, y5, x6, y6);
 SDL_RenderDrawLine(gRenderer, x7, y7, x8, y8);
 lines(
            x1/3, y1+(y2-y1)/3,
            x2/3, y2-(y2-y1)/3,
            x3-(x3/2+x3/6), y3+(y4-y3)/3,
            x4-(x4/2+x4/6), y4-(y4-y3)/3,
            0, y5+(y7-y5)/3,
            x6-(2*(x6-x5)/3),y6+(y7-y5)/3,
            0,y7-(y7-y5)/3,
            x8-(2*(x8-x7)/3),y8-(y7-y5)/3,
            depth+1);
    lines(
            x1+(x3-x1)/3, 0,
            x2+(x4-x2)/3, y2-(2*(y2-y1)/3),
            x3-(x3-x1)/3, 0,
            x4-(x4-x2)/3, y4-(2*(y4-y3)/3),
            x5+(x6-x5)/3, y5/3,
            x6-(x6-x5)/3,y6/3,
            x7+(x8-x7)/3,y7-(((y7-y5)/3)/3)*2,
            x8-(x8-x7)/3,y8-(((y7-y5)/3)/3)*2,
            depth+1);
}

void draw()
{
SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
lines(SCREEN_WIDTH/3, 0,SCREEN_WIDTH/3,SCREEN_HEIGHT,SCREEN_WIDTH/3+SCREEN_WIDTH/3, 0, SCREEN_WIDTH/3+SCREEN_WIDTH/3, SCREEN_HEIGHT, 0, SCREEN_HEIGHT/3, SCREEN_WIDTH,SCREEN_HEIGHT/3, 0,SCREEN_HEIGHT/3+SCREEN_HEIGHT/3,SCREEN_WIDTH,SCREEN_HEIGHT/3+SCREEN_HEIGHT/3, 0);



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