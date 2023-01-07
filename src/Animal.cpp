#include "Animal.hpp"
#include "Project_sdl.hpp"


animal::animal(SDL_Surface* window_surface_ptr, Type type){
    this->alive = true;
    this->type = type;
    this->x = rand() % screen_w_max;
    this->y = rand() % screen_h_max;
    this->directionx = rand() % 2 == 0 ? -1 : 1;
    this->directiony = rand() % 2 == 0 ? -1 : 1;
    this->window_surface_ptr_ = window_surface_ptr;
}

animal::~animal(){
    SDL_FreeSurface(this->image_ptr_);
}

Type animal::get_type(){
    return this->type;
}

bool animal::get_alive(){
    return this->alive;
}

void animal::set_alive(bool b){
    this->alive = b;
}

void animal::set_image_ptr(const char* file_path){
    this->image_ptr_ = IMG_Load(file_path);
}

SDL_Surface* animal::get_image_ptr(){
    return this->image_ptr_;
}

SDL_Surface* animal::get_surface_ptr(){
    return this->window_surface_ptr_;
}