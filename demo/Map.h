#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
using namespace std;

enum class CellType {
    UNKNOWN,
    LAND,
    OCEAN
};

class Map {
public:
    void initializeMapFromSVG(const std::string& svgFilePath);
    bool isPointInOcean(double x, double y);
    CellType getCellType(int x, int y) const;

private:
    std::vector<std::vector<CellType>> mapArray;
    double svgWidth;
    double svgHeight;
};

#endif
