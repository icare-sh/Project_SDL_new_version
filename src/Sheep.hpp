#ifndef SHEEP_HPP
#define SHEEP_HPP

#include "Project_sdl.hpp"
enum Gender {MALE, FEMALE};

class sheep : public animal {
private:
    bool en_fuite;
    int no_procreate_time;
    Gender gender;
public:
  sheep(SDL_Surface* window_surface_ptr,Type type);
  void move(std::vector<animal*> &animals) override;
  int get_time_noprocreate();
  int set_time_noprocreate(int t);
  Gender get_gender();
};

#endif // SHEEP_HPP