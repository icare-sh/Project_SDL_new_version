#include "Wolf.hpp"
#include <numeric>
#include <iostream>
#include <cmath>

wolf::wolf(SDL_Surface* window_surface_ptr,Type type) : animal(window_surface_ptr, type){
    this->set_image_ptr("media/wolf1.bmp");
    this->speed = 2;
}


void wolf::move(std::vector<animal*> &animals){
    this->hungry++;
    if(this->hungry >= hunger_delay){
        this->alive = false;
    }
    animal* nearest_dog = get_nearest(this, SHEPHERD_DOG, animals);
    animal* nearest = get_nearest(this, SHEEP, animals);

    if(nearest_dog != NULL && sqrt(pow(this->get_x() - nearest_dog->get_x(),2) + pow(this->get_y() - nearest_dog->get_y(),2)) < aura_hunting ) {
        this->directionx = nearest_dog->get_directionx() * 2;
        this->directiony = nearest_dog->get_directiony() * 2;
        this->hunting = true;
    }

    if (nearest != NULL && sqrt(pow(this->get_x() - nearest->get_x(),2) + pow(this->get_y() - nearest->get_y(),2) <= aura_kill)) {
       nearest->set_alive(false);
       this->hungry = 0;
    }
    
    if (nearest_dog != NULL && hunting && sqrt(pow(this->get_x() - nearest_dog->get_x(),2) + pow(this->get_y() - nearest_dog->get_y(),2))   < aura_hunting * 1.5)
    {
        this->x = this->x + this->directionx * this->speed * 2;
        this->y = this->y + this->directiony * this->speed * 2;
    }else{
        hunting = false;
        this->x = this->x + this->directionx * this->speed;
        this->y = this->y + this->directiony * this->speed;
    }

      if (nearest != NULL && !hunting) {
         if (this->x <= nearest->get_x())
            this->directionx = 1;
         else if (this->x >= nearest->get_x())
            this->directionx = -1;

      if (this->y <= nearest->get_y())
         this->directiony = 1;
      else if (this->y >= nearest->get_y())
         this->directiony = -1;
      }

    this->x = this->x + this->directionx * this->speed;
    this->y = this->y + this->directiony * this->speed;
}