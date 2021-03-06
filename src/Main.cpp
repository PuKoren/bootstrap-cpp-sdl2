#include "Application.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

SDL_Window *m_window;
SDL_Renderer *m_renderer;

int main() {

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return false;
  }

  m_window =
      SDL_CreateWindow("GCW0 - SDL2", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 320, 240, SDL_WINDOW_SHOWN);
  if (m_window == nullptr) {
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    return false;
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED |
                                                    SDL_RENDERER_PRESENTVSYNC);
  if (m_renderer == nullptr) {
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    return false;
  }

  if (TTF_Init() != 0) {
    std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
    return false;
  }

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
    return false;
  }

  SDL_Surface *image = IMG_Load("data/image.png");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, image);

  SDL_RenderSetLogicalSize(m_renderer, 320, 240);
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_ShowCursor(SDL_DISABLE);

  SDL_Event event;
  Application app;
  while (app.run(m_renderer, event)) {
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  IMG_Quit();
  TTF_Quit();
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();

  return 0;
}