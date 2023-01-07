#include "Application.hpp"

application::application(unsigned n_sheep, unsigned n_wolf)
{
    srand(time(NULL));
    this->window_ptr_ = SDL_CreateWindow("SDL_Project",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,0,0,SDL_WINDOW_FULLSCREEN_DESKTOP);
    this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);
    SDL_FillRect(this->window_surface_ptr_, NULL, SDL_MapRGB(this->window_surface_ptr_->format, 0, 255, 0));
    SDL_UpdateWindowSurface(this->window_ptr_);
    this->ground_ptr_ = new ground(this->window_surface_ptr_);
    for (int i = 0; i < 3; i++) {
        ground_ptr_->add_dog(i);
    }
    for( int i = 0; i < n_sheep; i++)
        ground_ptr_->add_sheep();
    for( int i = 0; i < n_wolf; i++)
        ground_ptr_->add_wolf();


}

application::~application()
{
    delete this->ground_ptr_;
    SDL_FreeSurface(this->window_surface_ptr_);
    SDL_DestroyWindow(this->window_ptr_);
}

int application::loop(unsigned period)
{
    bool quit = false;
    auto frameDelay = 1000 / 60;
    auto start = SDL_GetTicks();
    auto timeout = SDL_GetTicks() + period * 1000;
    int frameTime;
    auto remaining_sheeps = 0;
    int is_wolf_alive = 0;
 
    SDL_Event event;
    
    while(1)
    { 
        start = SDL_GetTicks();
        while( SDL_PollEvent( &event ) ){
            if(event.type == SDL_QUIT) {
                quit = true;
            }

            if(event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) { 
                    case SDLK_z:
                        this->ground_ptr_->moving_shepherd(0, -1);
                        break;
                    case SDLK_s:
                        this->ground_ptr_->moving_shepherd(0, 1);
                        break;
                    case SDLK_q:
                        this->ground_ptr_->moving_shepherd(-1, 0);
                        break;
                    case SDLK_d:
                        this->ground_ptr_->moving_shepherd(1, 0);
                        break;
                }
            }

        }
        for (auto a : this->ground_ptr_->getLstAnimals()) {
            if (a->get_type() == WOLF && a->get_alive()) 
                is_wolf_alive++;
            if (a->get_type() == SHEEP && a->get_alive()) 
                remaining_sheeps++;
        }

        if (is_wolf_alive == 0 || remaining_sheeps == 0 || quit == true || SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
            goto finish;
        
        is_wolf_alive = 0;
        remaining_sheeps = 0;
        
        ground_ptr_->update();
        SDL_UpdateWindowSurface(this->window_ptr_);
        
        frameTime = SDL_GetTicks() - start;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    
    }

    finish:
        if (is_wolf_alive == 0) {
            std::cout << "You win and you have " << remaining_sheeps << " sheeps remaining" << std::endl;
        } else
            std::cout << "There is " << is_wolf_alive << " wolves remaining" << std::endl;

        if (remaining_sheeps == 0) {
            std::cout << "You lose" << std::endl;
        } else if (is_wolf_alive != 0) {
            std::cout << "There is " << remaining_sheeps << " sheeps remaining" << std::endl;
            std::cout << "Time is over or you quit the game" << std::endl;
        }


    return 0;
}
