#ifndef SHEPHERD_DOG_HPP
#define SHEPHERD_DOG_HPP
#pragma once

#include <math.h>
#include <SDL.h>

#include "Project_sdl.hpp"

class shepherd_dog : public animal {
private:
    float angle;
    shepherd* shepherd_ptr;
public:
    shepherd_dog(SDL_Surface* window_surface_ptr, Type type, shepherd* shepherd_ptr, int i);
    void move(std::vector<animal*> &animal);
};



#endif // SHEPHERD_DOG_HPP