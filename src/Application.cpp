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
    const int frameDelay = 1000 / 60;
    auto start =  SDL_GetTicks();
    int frameTime;
 
    SDL_Event event;
    
    while(!quit && (SDL_GetTicks() - start) < period * 1000)
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
        ground_ptr_->update();
        SDL_UpdateWindowSurface(this->window_ptr_);

        frameTime = SDL_GetTicks() - start;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    return 0;
}
