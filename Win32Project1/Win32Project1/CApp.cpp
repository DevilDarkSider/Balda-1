#include "CApp.h"
 
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

//	if (!SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer))
//		return false;

	SDL_Window* window = SDL_CreateWindow("Sphere Rendering", 
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
				640, 480, SDL_WINDOW_SHOWN);

	if (!window)
		return false;
	
//    if((Surf_Display = SDL_GetWindowSurface(window)) == NULL)
//        return false;

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
		return false;

 
    return true;
}
void CApp::OnEvent(SDL_Event* Event) 
{
    switch(Event->type)
	{
	case SDL_QUIT:
        Running = false;
		break;
	case SDL_KEYDOWN:
		{
			SDL_KeyboardEvent* kbdEvent = (SDL_KeyboardEvent*)Event;
			if (kbdEvent->keysym.sym == SDLK_0)
				Running = false;
		}
		break;
    }
}

void CApp::OnLoop() 
{

}

void CApp::OnRender()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);

	SDL_Rect r = {10, 10, 25, 35};
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 128);
	SDL_RenderFillRect(renderer, &r);

	SDL_RenderPresent(renderer);
}
void CApp::OnCleanup() {
    SDL_Quit();
}

 
CApp::CApp() {
    Surf_Display = NULL;
 
    Running = true;
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) 
	{
        while(SDL_PollEvent(&Event))
		{
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
 
int main(int argc, char* argv[]) {
    CApp theApp;
 
    return theApp.OnExecute();
}
