#ifndef PROJECT_SDL_HPP
#define PROJECT_SDL_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "Animal.hpp"
#include "Shepherd.hpp"


// frame rate
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;

// sizes
constexpr unsigned screen_w_max = 1613;
constexpr unsigned screen_w_min = 230;
constexpr unsigned screen_h_max = 868;
constexpr unsigned screen_h_min = 180;
constexpr unsigned shape_size = 64;
constexpr unsigned max_nb_animals = 450;
constexpr unsigned aura_kill = 30;
constexpr unsigned dist_procreate = 15;
constexpr unsigned aura_hunting = 200;
constexpr unsigned hunger_delay = 2500;
constexpr unsigned time_no_procreate_time = 1000;
constexpr unsigned nb_shepherd_dog = 3;


// global functions
void init();
animal* get_nearest(animal* a, Type type, std::vector<animal*> lst_animal);

#endif // PROJECT_SDL_HPP