#ifndef SHEPHERD_HPP
#define SHEPHERD_HPP

#include <SDL.h>
#include "Moving_character.hpp"

class shepherd : public moving_character{
private:
    SDL_Surface* image_ptr_;
public:
    shepherd();
    ~shepherd();
    SDL_Surface* get_image_ptr();
    void move(int dirx,int diry);
};

#endif // SHEPHERD_HPP