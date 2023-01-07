#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Ground.hpp"

class application {
private:
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;

  ground *ground_ptr_;
  // Other attributes here, for example an instance of ground

public:
  application(unsigned n_sheep, unsigned n_wolf); // Ctor
  ~application();                                 // dtor

  int loop(unsigned period); // main loop of the application.
                             // this ensures that the screen is updated
                             // at the correct rate.
                             // See SDL_GetTicks() and SDL_Delay() to enforce a
                             // duration the application should terminate after
                             // 'period' seconds
};

#endif // APPLICATION_HPP