#ifndef MOVING_OBJECT_HPP
#define MOVING_OBJECT_HPP

#include <SDL.h>

class moving_character {
protected:
    float x;
    float y;
    float speed;
    int directionx;
    int directiony;

public:
    void draw(SDL_Surface* image_ptr_,SDL_Surface* window_surface_ptr_);
    void move();
    int get_x();
    int get_y();
    int get_directionx();
    int get_directiony();
    void set_x(int x);
    void set_y(int y);
};

#endif // MOVING_OBJECT_HPP