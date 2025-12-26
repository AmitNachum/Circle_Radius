#include "circle.h"
void init_circle(circle *p_circle,float x_cor,float y_cor, float radius_val){

	p_circle->x_origin = x_cor;
	p_circle->y_origin = y_cor;
	p_circle->circle_radius = radius_val;

}


static float radius_angle = 0.0f;
static Uint64 last = 0;

static float delta_time(){
  Uint64 now = SDL_GetTicksNS();
  float dt = (now - last) / 1e9f;
  last = now;
  return dt;
}



void draw_radius(circle *p_circle, SDL_Renderer *dst)
{
    radius_angle -= 0.5f * delta_time();
    if (radius_angle < 0.0f)
        radius_angle += 2.0f * PI * delta_time();

    float x = p_circle->x_origin +
              p_circle->circle_radius * cos(radius_angle);
    float y = p_circle->y_origin -
              p_circle->circle_radius * sin(radius_angle);

    SDL_RenderLine(dst,
        p_circle->x_origin,
        p_circle->y_origin,
        x,
        y);
}




void draw_circle(circle * p_circle, SDL_Renderer *dst){


	for(float i = 1.0f; i < FULL; ++i){
		float theta = i * (PI/(FULL / 2.0f));
		float new_x = p_circle->x_origin + (p_circle->circle_radius * cos(theta));
		float new_y = p_circle->y_origin - (p_circle->circle_radius * sin(theta));

		SDL_RenderPoint(dst,new_x,new_y);
	}


}