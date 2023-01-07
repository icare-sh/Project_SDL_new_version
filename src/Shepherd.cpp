#include "Shepherd.hpp"
#include "Project_sdl.hpp"

shepherd::shepherd() {
    this->image_ptr_ = IMG_Load("media/berger2.png");
    if (this->image_ptr_ == NULL) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
    }
    this->x = screen_w_max/2;
    this->y = screen_h_max/2;
    this->speed = 8;
}

shepherd::~shepherd() {
    SDL_FreeSurface(this->image_ptr_);
}

void shepherd::move(int dirx, int diry) {
    if(this->x <= -1)
        this->x = 0;
    if(this->y <= -1)
        this->y = 0;
    if(this->x >= screen_w_max)
        this->x = screen_w_max;
    if(this->y >= screen_h_max)
        this->y = screen_h_max;
    this->x = this->x + dirx * this->speed;
    this->y = this->y + diry * this->speed;
}


SDL_Surface* shepherd::get_image_ptr(){
    return this->image_ptr_;
}