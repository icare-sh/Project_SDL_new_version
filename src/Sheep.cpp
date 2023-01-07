#include "Sheep.hpp"
#include "math.h"
sheep::sheep(SDL_Surface* window_surface_ptr,Type type) : animal(window_surface_ptr, type){

    int x_g = rand() % 2;
    if (x_g == 0)
    {
        this->gender = MALE;
        this->set_image_ptr("media/sheep1.bmp");
    }
    else
    {
        this->gender = FEMALE;
        this->set_image_ptr("media/sheep_femme.bmp");
    }
    set_x(rand() % (screen_w_max - screen_w_min) + screen_w_min);
    set_y(rand() % (screen_h_max - screen_h_min) + screen_h_min);

    this->no_procreate_time = time_no_procreate_time;
    this->speed = 2;
}



void sheep::move(std::vector<animal*> &animals){

    animal* nearest = get_nearest(this, WOLF, animals);
    bool speed_up = false;
    if(nearest != NULL && sqrt(pow(this->get_x() - nearest->get_x(),2) + pow(this->get_y() - nearest->get_y(),2)) < aura_hunting ) {
        this->directionx = nearest->get_directionx();
        this->directiony = nearest->get_directiony();
        speed_up = true;
    }
    

    sheep* nearest_c = (sheep*)get_nearest(this, SHEEP, animals);

    if(nearest_c != NULL && sqrt(pow(this->get_x() - nearest_c->get_x(),2) + pow(this->get_y() - nearest_c->get_y(),2)) < dist_procreate ) {
        if (this-> no_procreate_time == 0 && nearest_c->get_time_noprocreate() == 0 && this->gender != nearest_c->get_gender()){
            animals.push_back(new sheep(this->get_surface_ptr(), SHEEP));
            this->no_procreate_time = time_no_procreate_time;
            nearest_c->set_time_noprocreate(time_no_procreate_time);
        }
    }

    if(this->no_procreate_time != 0)
        this->no_procreate_time--;

    if (this->x < screen_w_min){
        this->directionx = 1;
    }
    
    if(this->x > screen_w_max) {
        this->directionx = -1;
    }
    
    if(this->y < screen_h_min){
        this->directiony = 1;
    }
    
    if(this->y > screen_h_max ){
        this->directiony = -1;
    } 
    
    if (speed_up){
        this->x = this->x + this->directionx * this->speed * 2;
        this->y = this->y + this->directiony * this->speed * 2;
    }
    else{
        this->x = this->x + this->directionx * this->speed;
        this->y = this->y + this->directiony * this->speed;
    }
    
}

int sheep::get_time_noprocreate(){
    return this->no_procreate_time;
}

int sheep::set_time_noprocreate(int t){
    return this->no_procreate_time = t;
}

Gender sheep::get_gender() {
    return this->gender;
}