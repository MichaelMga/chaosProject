

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
     
 int main(int argc, char *argv[])
 {
   SDL_Window *window = NULL;
   SDL_Surface *windowSurface = NULL;
   SDL_Surface *image1 = NULL;
   SDL_Surface *image2 = NULL;  
   SDL_Surface *currentImage = image1;
   
 
    
   image1 = IMG_Load("resources/warrior.png");
   image2 = IMG_Load("resources/hello.png");
   
   SDL_Init(SDL_INIT_VIDEO);
   
   window = SDL_CreateWindow("Chaos project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
   
   
      windowSurface = SDL_GetWindowSurface(window);
      
      
   int isRunning = 1;
   
   SDL_Event ev;
   
   
   while(isRunning != 0){
   
     while(SDL_PollEvent(&ev) != 0)
     {
       if(ev.type == SDL_QUIT){
          isRunning = 0;
       } else if (ev.type == SDL_KEYDOWN) {
            
            switch(ev.key.keysm.sym){
                  
              case SDLK_1 :
                currentImage = image1;
              
              case SDLK_2 :
                currentImage = image2;      
               
            
           }
         }
       } 
       
       SDL_BlitSurface(currentImage,NULL, windowSurface, NULL );
       
       SDL_UpdateWindowSurface(window);
       
    }
    
    return 0;
  }
