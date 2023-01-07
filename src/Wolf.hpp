#ifndef WOLF_HPP
#define WOLF_HPP

#include "Project_sdl.hpp"

class wolf : public animal{
private:
    bool hunting;
    int hungry = 0;
public:
  wolf(SDL_Surface* window_surface_ptr, Type type);
  void move(std::vector<animal*> &animals);
};

#endif // WOLF_HPP