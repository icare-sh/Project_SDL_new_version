#include "Shepherd_dog.hpp"

shepherd_dog::shepherd_dog(SDL_Surface* window_surface_ptr, Type type, shepherd* shepherd_ptr, int i) : animal(window_surface_ptr, type){
    this->angle = rand() % 360;
    this->shepherd_ptr = shepherd_ptr;
    this->set_image_ptr("media/dog.bmp");
}

void shepherd_dog::move(std::vector<animal*> &lst_animal){
    this->angle += 0.05f;
    if ((cos(angle) >= 0 && cos(angle) <= 1) && (sin(angle) >= -1 && sin(angle) <= 0)) {
        this->directionx = 1;
        this->directiony = -1;
    }
    if ((cos(angle) <= 1 && cos(angle) >= 0) && (sin(angle) >= 0 && sin(angle) <= 1)) {
        this->directionx = 1;
        this->directiony = 1;
    }
    if ((cos(angle) >= -1 && cos(angle) <= 0) && (sin(angle) <= 0 && sin(angle) >= -1)) {
        this->directionx = -1;
        this->directiony = -1;
    }
    if ((cos(angle) <= 0 && cos(angle) >= -1) && (sin(angle) <= 1 && sin(angle) >= 0)) {
        this->directionx = -1;
        this->directiony = 1;
    }
    this->x = shepherd_ptr->get_x() + 100 * cos(angle);
    this->y = shepherd_ptr->get_y() + 100 * sin(angle);
}