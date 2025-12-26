#include "circle.h"
void init_circle(circle *p_circle,float x_cor,float y_cor, float radius_val){

	p_circle->x_origin = x_cor;
	p_circle->y_origin = y_cor;
	p_circle->circle_radius = radius_val;
}


static float radius_angle = 0.1f;

float delta_time(void) {
    static Uint64 last = 0;
    Uint64 now = SDL_GetTicksNS();
    if (last == 0) {
        last = now;
        return 0.0f;
    }
    float dt = (now - last) / 1e9f;
    last = now;
    return dt;
}




void draw_radius(circle *p_circle, SDL_Renderer *dst)
{
    SDL_RenderLine(dst,
        p_circle->x_origin,
        p_circle->y_origin,
        p_circle->x_edge_update,
        p_circle->y_edge_update);
}




void draw_circle(circle * p_circle, SDL_Renderer *dst){

  for(float i = 1.0f; i < FULL; ++i){
		float theta = i * (PI/(FULL / 2.0f));
		float new_x = p_circle->x_origin + (p_circle->circle_radius * cos(theta));
		float new_y = p_circle->y_origin - (p_circle->circle_radius * sin(theta));

    SDL_RenderPoint(dst,new_x,new_y);
  }
}

void update_radius(circle *p_circle,float dt)
{ 
    if(!p_circle) return;

    radius_angle -= 0.9f * dt;

    if (radius_angle < 0.0f)
        radius_angle -= 2.0f * PI;

    p_circle->x_edge_update = p_circle->x_origin +
              p_circle->circle_radius * cos(radius_angle);
    p_circle->y_edge_update = p_circle->y_origin -
              p_circle->circle_radius * sin(radius_angle);
  
}


