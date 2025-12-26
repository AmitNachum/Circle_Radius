#pragma once
#include <pthread.h>
#include <SDL3/SDL.h>

#define THREAD_COUNT 1

typedef struct thread_worker {
    circle *p_circle;                  // 8
    SDL_Renderer *renderer;             // 8
    void (*update)(circle *,float); // 8
    int thread_id;                      // 4
} thread_struct;
