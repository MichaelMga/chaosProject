/**
 * hello6_keyboard.c - Move the sprite using the arrow keys or WASD
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

// speed in pixels/second
#define SPEED (300)

int main(void)
{
    // attempt to initialize graphics and timer system
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello, CS50!",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_WIDTH, WINDOW_HEIGHT,0);
    
    

    // create a renderer, which sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    
    
    
    // load the image into memory using SDL_image library function
    SDL_Surface* surface = IMG_Load("resources/env.jpg");


    // load the image data into the graphics hardware's memory
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    // struct to hold the position and size of the sprite
    SDL_Rect dest;

    // get and scale the dimensions of texture
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    
    // start sprite in center of screen
    dest.y = (WINDOW_WIDTH - dest.w) / 2;
    dest.x = (WINDOW_HEIGHT - dest.h) / 2;
    
    
   
    // set to 1 when window close button is pressed
    int close_requested = 0;
    
    // animation loop
    while (!close_requested)
    {
        // process events
        SDL_Event event;
        
        while(SDL_PollEvent(&event)){
          
          switch (event.type)
            {
               case SDL_QUIT:
               close_requested = 1;
               break;
               
               case SDL_KEYDOWN:
               
   
             surface = IMG_Load("resources/warrior.png");


             tex = SDL_CreateTextureFromSurface(rend, surface);
             SDL_FreeSurface(surface);

             SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
               
             break;
                       
            } 
            
          }
                 
                  
        // clear the window
        SDL_RenderClear(rend);

        // draw the image to the window
        SDL_RenderCopy(rend,tex,NULL,&dest);
        
        SDL_RenderPresent(rend);

        // wait 1/60th of a second
        SDL_Delay(1000/60);
    }
       
    // clean up resources before exiting
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
