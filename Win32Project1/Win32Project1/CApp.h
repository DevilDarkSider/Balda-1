#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
 
class CApp {
    private:
		int X,Y;
        bool    Running;
 
		SDL_Window* window;
		SDL_Renderer* renderer;

		SDL_Surface*    Surf_Display;
    public:
        CApp();
 
        int OnExecute();
 
    public:
 
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};
 
#endif