#include "Map.h"

void Map::initializeMapFromSVG(const std::string& svgFilePath) {
    // Load and parse the SVG file
    // (Use an appropriate XML library to parse the SVG)
    
    // Assuming a parsed SVG structure:
    // - We have a list of paths or polygons representing land and ocean
    // - For simplicity, we assume two layers: "land" and "ocean"

    // Define the dimensions of the map (2D array)
    int mapWidth = 100;  // Example size
    int mapHeight = 100; // Example size
    mapArray.resize(mapHeight, std::vector<CellType>(mapWidth, CellType::UNKNOWN));

    // Example of checking if a point is within an ocean area in SVG
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            // Convert (x, y) to actual coordinates based on the SVG's scale
            double actualX = (x / static_cast<double>(mapWidth)) * svgWidth;
            double actualY = (y / static_cast<double>(mapHeight)) * svgHeight;
            
            // Check if (actualX, actualY) is within an ocean area
            if (isPointInOcean(actualX, actualY)) {
                mapArray[y][x] = CellType::OCEAN;
            } else {
                mapArray[y][x] = CellType::LAND;
            }
        }
    }
}
