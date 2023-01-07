#ifndef GROUND_HPP
#define GROUND_HPP

#include "Project_sdl.hpp"
#include "Wolf.hpp"
#include "Sheep.hpp"


class background {
  private:
    SDL_Surface* image_ptr_;
  public:
    background();
    ~background();
    SDL_Surface* get_image_ptr();
    void draw(SDL_Surface * image_ptr_,SDL_Surface* window_surface_ptr_);
};


class ground {
private:
  SDL_Surface* window_surface_ptr_;
  std::vector<animal*> animals;
  shepherd* shepherd_;
  background * background_;

public:
  ground(SDL_Surface* window_surface_ptr); // todo: Ctor
  ~ground(); // todo: Dtor, again for clean up (if necessary)
  void update(); // todo: "refresh the screen": Move animals and draw them
  // Possibly other methods, depends on your implementation
  std::vector<animal*> getLstAnimals();
  void moving_shepherd(int dirx,int diry);
  void add_sheep();
  void add_wolf();
  void add_dog(int i);

};

#endif // GROUND_HPP