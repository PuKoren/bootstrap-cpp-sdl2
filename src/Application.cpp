#include "Application.hpp"

Application::Application() {}

Application::~Application() {}

bool Application::run(SDL_Renderer *renderer, SDL_Event &event) {
  // check SDL events, and if user pressed escape or received a window close
  // event from OS, return false
  SDL_PollEvent(&event);
  if (event.type == SDL_WINDOWEVENT &&
      event.window.event == SDL_WINDOWEVENT_CLOSE) {
    return false;
  } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
    return false;
  }

  /*
  You game logic here. Draw using the provided SDL renderer.
  There is no more class done here, no state manager, nothing. Do it your way!
   */
  renderer = renderer;

  // when you return false, game exits
  return true;
}