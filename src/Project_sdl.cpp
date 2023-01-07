#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>


#include "Project_sdl.hpp"


void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}


animal* get_nearest(animal* a, Type type, std::vector<animal*> lst_animal){
        float dst = 10000000;
        animal* nearest = NULL;
        if (a != lst_animal[0])
            nearest = lst_animal[0];
        else
            nearest = lst_animal[1];
        for (auto itr = lst_animal.begin(); itr != lst_animal.end(); ++itr) {
            if((*itr)->get_type() == type && (*itr)->get_alive() && (*itr) != a){
               double tmp_dst = sqrt(pow(a->get_x() - (*itr)->get_x(),2) + pow(a->get_y() - (*itr)->get_y(),2));
                if(tmp_dst<dst)
                {
                    dst = tmp_dst;
                    nearest = (*itr);
                }
            }
        }
        if(nearest->get_type() != type || !nearest->get_alive())
            return NULL;
        return nearest;
}