#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <SDL.h>

class Application {
public:
  Application();
  ~Application();
  bool run(SDL_Renderer *, SDL_Event &);

private:
};

#endif