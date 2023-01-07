#include "Moving_character.hpp"
#include "Project_sdl.hpp"


void moving_character::draw(SDL_Surface* image_ptr_,SDL_Surface* window_surface_ptr_){
    SDL_Rect rsdt = SDL_Rect{(int)this->x,(int)this->y,shape_size,shape_size};
    SDL_BlitScaled(image_ptr_,NULL,window_surface_ptr_,&rsdt);
}


int moving_character::get_x(){
    return this->x;
}
int moving_character::get_y(){
    return this->y;
}

int moving_character::get_directionx(){
    return this->directionx;
}
int moving_character::get_directiony(){
    return this->directiony;
}

void moving_character::set_x(int x){
    this->x = x;
}
void moving_character::set_y(int y){
    this->y = y;
}
