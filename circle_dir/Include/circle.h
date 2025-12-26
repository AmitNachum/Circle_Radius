#include <stdio.h>
#include <math.h>
#include <SDL3/SDL.h>



#define HEIGHT 900
#define WIDTH 900
#define FAILED 1
#define SUCCESS 0
#define PI 3.14159265359
#define FULL 360.0
#define WHITE 0XFFFFFF

typedef struct circle{
    float x_origin;
    float y_origin;
    float circle_radius;
}circle;



void draw_radius(circle * p_circle, SDL_Renderer *dst);
void init_circle(circle *p_circle,float x_cor,float y_cor, float radius_val);
void draw_circle(circle * p_circle, SDL_Renderer *dst);
