#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SDL.h>
#include <vector>

#include "Moving_character.hpp"


enum Type {SHEEP, WOLF, SHEPHERD_DOG};

class animal : public moving_character{
private:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
  // load_surface_for
  
protected:
  Type type;
  bool alive;

public:
  animal(SDL_Surface* window_surface_ptr, Type type);
  ~animal();


  virtual void move(std::vector<animal*> &lst_animal) = 0;
    SDL_Surface* get_surface_ptr();
    SDL_Surface* get_image_ptr();
    void set_image_ptr(const char* img);
    bool get_alive();
    void set_alive(bool b);
    Type get_type();
};


#endif // ANIMAL_HPP