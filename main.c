#include "circle.h"

int main(void){
	circle circle_var = {0};
	init_circle(&circle_var,500.0f,500.0f,100.0f);

	
	SDL_Init(SDL_INIT_VIDEO);


	SDL_Window *window_ptr = SDL_CreateWindow("Circle",WIDTH,HEIGHT,0);
	printf("Attempting to open A window....\n");
	if(!window_ptr){

		SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Failed Window Creation: %s\n",SDL_GetError());
		return FAILED;
	}

	printf("We are after the attempt meaning passed the null check of window...\n\n");

	SDL_Renderer *renderer =
    SDL_CreateRenderer(window_ptr, NULL);

	int running = 1;


        while(running){
	    SDL_Event event;

	    while(SDL_PollEvent(&event)){
		if(event.type == SDL_EVENT_QUIT){
			running = 0;
		}
	    }

		/* clear background */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		/* draw geometry */
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		draw_circle(&circle_var,renderer);
		draw_radius(&circle_var,renderer);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window_ptr);
	SDL_Quit();

return SUCCESS;
}
