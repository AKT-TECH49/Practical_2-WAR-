#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <vector>

#include <SDL.h>
#include "Map.h"

class Graphics {
   public:
      void drawMap(SDL_Renderer* renderer, const Map& map);

}

#endif;