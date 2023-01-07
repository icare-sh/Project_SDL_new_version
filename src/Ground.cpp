#include "Ground.hpp"
#include "Shepherd_dog.hpp"
#include "SDL.h"


background::background(){
    this->image_ptr_ = IMG_Load("media/background.bmp"); 
}


background::~background(){
    SDL_FreeSurface(this->image_ptr_);
}

SDL_Surface* background::get_image_ptr(){
    return this->image_ptr_;
}

void background::draw(SDL_Surface* image_ptr, SDL_Surface* window_surface_ptr){
    SDL_Rect rect_background = SDL_Rect{0, 0, 0, 0};
    SDL_BlitSurface(image_ptr, NULL, window_surface_ptr, &rect_background);
}

ground::ground(SDL_Surface* window_surface_ptr)
{
    this->animals.reserve(max_nb_animals);
    this->shepherd_ = new shepherd();
    this->window_surface_ptr_ = window_surface_ptr;
    this->background_ = new background();
}

std::vector<animal*> ground::getLstAnimals(){
    return this->animals;
}

ground::~ground(){
    for (auto a : this->animals)
        delete a;
    this->animals.clear();
}
void ground::add_sheep()
{
    this->animals.push_back(new sheep(this->window_surface_ptr_, SHEEP));
}

void ground::moving_shepherd(int dirx, int diry) {
    this->shepherd_->move(dirx,diry);
}

void ground::add_wolf()
{
   this->animals.push_back(new wolf(this->window_surface_ptr_, WOLF));
}
void ground::add_dog(int i){
    this->animals.push_back(new shepherd_dog(this->window_surface_ptr_, SHEPHERD_DOG, this->shepherd_, i));
}
void ground::update()
{
    SDL_FillRect(this->window_surface_ptr_, NULL, SDL_MapRGB(this->window_surface_ptr_->format, 0, 255, 0));
    this->background_->draw(this->background_->get_image_ptr(),this->window_surface_ptr_);
    this->shepherd_->draw(this->shepherd_->get_image_ptr(),this->window_surface_ptr_);

    for (auto itr = animals.begin(); itr != animals.end(); ++itr) {
        if((*itr)->get_alive()){
        (*itr)->move(this->animals);
        (*itr)->draw((*itr)->get_image_ptr(),(*itr)->get_surface_ptr());
        }
    }
}