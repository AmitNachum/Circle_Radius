#include "circle.h"
#include "thread_struct.h"


static int running = 1;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* execute(void *arg);

void* execute(void *arg){
	thread_struct *worker = (thread_struct *)arg;
	if(worker == NULL) return worker;
	
	while (running)
	{
		float dt = delta_time();
		pthread_mutex_lock(&mtx);
		worker->update(worker->p_circle, dt);
		pthread_mutex_unlock(&mtx);
		SDL_Delay(16);
	}
	return NULL;
}


//SDL rendering is Controlled by the main thread only

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


		thread_struct thread_worker =
		{.p_circle = &circle_var, .renderer = renderer, .update = update_radius, .thread_id = 1};
	
		pthread_t thread1;
		pthread_create(&thread1,NULL,execute,&thread_worker);

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
		pthread_mutex_lock(&mtx);
    	draw_circle(&circle_var, renderer);   // full circle
    	draw_radius(&circle_var, renderer);   // rotating line
    	pthread_mutex_unlock(&mtx);
		
		SDL_RenderPresent(renderer);
	}

		pthread_join(thread1,NULL);
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window_ptr);
	SDL_Quit();

	printf("\n\n ==== Cleaned Everything ====\n\n Exiting.....\n");
	fflush(stdout);

return SUCCESS;
}
