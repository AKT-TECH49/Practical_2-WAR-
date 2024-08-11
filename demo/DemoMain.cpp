#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#include <iostream>
#include "../SoldierFactory.h"
#include "../Soldiers.h"
#include "../ShieldBearer.h"
#include "../ShieldBearerFactory.h"
#include "../Infantry.h"
#include "../InfantryFactory.h"
#include "../Boatman.h"
#include "../BoatmanFactory.h"
#include "../Memento.h"
#include "../CareTaker.h"

#include <string>
#include <vector>
#include <sstream>

// Constants for window dimensions
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 1024;
const int SIDE_PANEL_WIDTH = 200;
int RedInfHealth;
int BlueInfHealth;
int RedBoatHealth;
int BlueBoatHealth;
int RedShieldHealth;
int BlueShieldHealth;

int RedInfAttack;
int BlueInfAttack;
int RedBoatAttack;
int BlueBoatAttack;
int RedShieldAttack;
int BlueShieldAttack;

int RedInfDefence;
int BlueInfDefence;
int RedBoatDefence;
int BlueBoatDefence;
int RedShieldDefence;
int BlueShieldDefence;

int  numRedInf;
int  numBlueInf;
int  numRedBoat;
int  numBlueBoat;
int  numRedShield;
int  numBlueShield;

int RedAttack = RedInfAttack + RedShieldAttack + RedBoatAttack;
int BlueAttack = BlueInfAttack + BlueShieldAttack + BlueBoatAttack;
int RedHealth = RedBoatHealth + RedShieldHealth + RedInfHealth;
int BlueHealth = BlueBoatHealth + BlueShieldHealth + BlueInfHealth;
int RedDefence = RedBoatDefence + RedShieldDefence + RedInfDefence;
int BlueDefence = BlueBoatDefence + BlueShieldDefence + BlueInfDefence;

// Struct to manage SDL objects
struct SDLContext {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* mapTexture;
    SDL_Texture* spriteTexture;
};

// Function to initialize SDL, IMG, TTF and create window and renderer
bool initializeSDL(SDLContext &context) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    context.window = SDL_CreateWindow("War Simulation",
                                      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                      WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!context.window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    context.renderer = SDL_CreateRenderer(context.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!context.renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(context.window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    return true;
}

// Function to load a texture from a file path
SDL_Texture* loadTexture(const std::string &filePath, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (!surface) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

// Function to render text
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer) {
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (!font) {
        std::cerr << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Surface *surf = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surf) {
        TTF_CloseFont(font);
        std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

// Function to render the map
void renderMap(SDLContext &context) {
    SDL_Rect leftPanelRect = {0, 0, SIDE_PANEL_WIDTH, WINDOW_HEIGHT};
    SDL_Rect rightPanelRect = {WINDOW_WIDTH - SIDE_PANEL_WIDTH, 0, SIDE_PANEL_WIDTH, WINDOW_HEIGHT};
    SDL_Rect centerPanelRect = {SIDE_PANEL_WIDTH, 0, WINDOW_WIDTH - 2 * SIDE_PANEL_WIDTH, WINDOW_HEIGHT};

    SDL_SetRenderDrawColor(context.renderer, 169, 169, 169, 255);

    SDL_RenderFillRect(context.renderer, &leftPanelRect);
    SDL_RenderFillRect(context.renderer, &rightPanelRect);

    SDL_RenderCopy(context.renderer, context.mapTexture, NULL, &centerPanelRect);
}

// Function to render sprites
void renderSprites(SDLContext &context) {
    InfantryFactory Redinf;
    InfantryFactory Blueinf;

    BoatmanFactory Redboat;
    BoatmanFactory Blueboat;

    ShieldBearerFactory Redsh;
    ShieldBearerFactory Bluesh;

    //create units for red and blue team
    std::vector<Soldiers*> redInfantry;
    std::vector<Soldiers*> redBoatman;
    std::vector<Soldiers*> redShieldBearer;
    std::vector<Soldiers*> blueInfantry;
    std::vector<Soldiers*> blueBoatman;
    std::vector<Soldiers*> blueShieldBearer;

    for (int i = 0; i < 9; ++i) {
        redInfantry.push_back(Redinf.createUnit());
        redBoatman.push_back(Redboat.createUnit());
        redShieldBearer.push_back(Redsh.createUnit());
        blueInfantry.push_back(Blueinf.createUnit());
        blueBoatman.push_back(Blueboat.createUnit());
        blueShieldBearer.push_back(Bluesh.createUnit());
    }

    RedInfHealth = Redinf.calculateTotalHealthPerUnit();
    BlueInfHealth = Blueinf.calculateTotalHealthPerUnit();
    RedBoatHealth = Redboat.calculateTotalHealthPerUnit();
    BlueBoatHealth = Blueboat.calculateTotalHealthPerUnit();
    RedShieldHealth = Redsh.calculateTotalHealthPerUnit();
    BlueShieldHealth = Bluesh.calculateTotalHealthPerUnit();

    RedInfAttack = Redinf.calculateTotalDamagePerUnit();
    BlueInfAttack = Blueinf.calculateTotalDamagePerUnit();
    RedBoatAttack = Redboat.calculateTotalDamagePerUnit();
    BlueBoatAttack = Blueboat.calculateTotalDamagePerUnit();
    RedShieldAttack = Redsh.calculateTotalDamagePerUnit();
    BlueShieldAttack = Bluesh.calculateTotalDamagePerUnit();

    RedInfDefence = Redinf.calculateTotalDefencePerUnit();
    BlueInfDefence = Blueinf.calculateTotalDefencePerUnit();
    RedBoatDefence = Redboat.calculateTotalDefencePerUnit();
    BlueBoatDefence = Blueboat.calculateTotalDefencePerUnit();
    RedShieldDefence = Redsh.calculateTotalDefencePerUnit();
    BlueShieldDefence = Bluesh.calculateTotalDefencePerUnit();

    numBlueBoat = Blueboat.calculateTotalNumOfUnits();
    numBlueInf = Blueinf.calculateTotalNumOfUnits();
    numBlueShield = Bluesh.calculateToTalNumUnits();
    numRedBoat = Redboat.calculateTotalNumOfUnits();
    numRedInf = Redinf.calculateTotalNumOfUnits();
    numRedShield = Redsh.calculateToTalNumUnits();

   
 // Load textures for each soldier type and team
    SDL_Surface* redInfSurface = IMG_Load("demo/assets/tankpngred.png");
    SDL_Surface* blueInfSurface = IMG_Load("demo/assets/tankpngblue.png");
    SDL_Surface* redBoatSurface = IMG_Load("demo/assets/boatpngred.png");
    SDL_Surface* blueBoatSurface = IMG_Load("demo/assets/boatpngblue.png");
    SDL_Surface* shieldSurface = IMG_Load("demo/assets/shieldpng.png");

    SDL_Texture* redInfTexture = SDL_CreateTextureFromSurface(context.renderer, redInfSurface);
    SDL_Texture* blueInfTexture = SDL_CreateTextureFromSurface(context.renderer, blueInfSurface);
    SDL_Texture* redBoatTexture = SDL_CreateTextureFromSurface(context.renderer, redBoatSurface);
    SDL_Texture* blueBoatTexture = SDL_CreateTextureFromSurface(context.renderer, blueBoatSurface);
    SDL_Texture* shieldTexture = SDL_CreateTextureFromSurface(context.renderer, shieldSurface);

    SDL_FreeSurface(redInfSurface);
    SDL_FreeSurface(blueInfSurface);
    SDL_FreeSurface(redBoatSurface);
    SDL_FreeSurface(blueBoatSurface);

    // Create sprites according to team vectors
    std::vector<SDL_Texture*> redInfantrySprites(9, redInfTexture);
    std::vector<SDL_Texture*> blueInfantrySprites(9, blueInfTexture);
    std::vector<SDL_Texture*> redBoatmanSprites(9, redBoatTexture);
    std::vector<SDL_Texture*> blueBoatmanSprites(9, blueBoatTexture);
    std::vector<SDL_Texture*> redShieldBearerSprites(9, shieldTexture);
    std::vector<SDL_Texture*> blueShieldBearerSprites(9, shieldTexture);

    // Define sprite positions and sizes
    int spriteWidth = 64, spriteHeight = 64;
    int spacing = 10;  // Space between sprites
    int leftBoundary = SIDE_PANEL_WIDTH;
    int rightBoundary = WINDOW_WIDTH - SIDE_PANEL_WIDTH;
    int shieldRowY = WINDOW_HEIGHT / 4;
    int tankRowY = shieldRowY + spriteHeight + spacing;  // Position tanks in front of shields
    int boatRowY = tankRowY + spriteHeight + spacing;    // Position boats in front of tanks

    // Render Red Team Shields (back line)
    for (size_t i = 0; i < redShieldBearerSprites.size(); ++i) {
        SDL_Rect dstRect = {rightBoundary - (spriteWidth + spacing), shieldRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, redShieldBearerSprites[i], NULL, &dstRect);
    }

    // Render Red Team Infantry (middle line)
    for (size_t i = 0; i < redInfantrySprites.size(); ++i) {
        SDL_Rect dstRect = {rightBoundary - (2 * (spriteWidth + spacing)), tankRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, redInfantrySprites[i], NULL, &dstRect);
    }

    // Render Red Team Boatmen (front line)
    for (size_t i = 0; i < redBoatmanSprites.size(); ++i) {
        SDL_Rect dstRect = {rightBoundary - (3 * (spriteWidth + spacing)), boatRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, redBoatmanSprites[i], NULL, &dstRect);
    }

    // Render Blue Team Shields (back line)
    for (size_t i = 0; i < blueShieldBearerSprites.size(); ++i) {
        SDL_Rect dstRect = {leftBoundary + (spriteWidth + spacing), shieldRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, blueShieldBearerSprites[i], NULL, &dstRect);
    }

    // Render Blue Team Infantry (middle line)
    for (size_t i = 0; i < blueInfantrySprites.size(); ++i) {
        SDL_Rect dstRect = {leftBoundary + (2 * (spriteWidth + spacing)), tankRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, blueInfantrySprites[i], NULL, &dstRect);
    }

    // Render Blue Team Boatmen (front line)
    for (size_t i = 0; i < blueBoatmanSprites.size(); ++i) {
        SDL_Rect dstRect = {leftBoundary + (3 * (spriteWidth + spacing)), boatRowY + i * (spriteHeight + spacing), spriteWidth, spriteHeight};
        SDL_RenderCopy(context.renderer, blueBoatmanSprites[i], NULL, &dstRect);
    }

    // Present the updated renderer content to the screen
    SDL_RenderPresent(context.renderer);

    // Clean up textures
    SDL_DestroyTexture(redInfTexture);
    SDL_DestroyTexture(blueInfTexture);
    SDL_DestroyTexture(redBoatTexture);
    SDL_DestroyTexture(blueBoatTexture);
    SDL_DestroyTexture(shieldTexture);
}

// Function to render game stats
void renderGameStats(SDLContext &context, SDL_Texture* redTeamText, SDL_Texture* blueTeamText) {
    int redTeamTextWidth, redTeamTextHeight;
    SDL_QueryTexture(redTeamText, NULL, NULL, &redTeamTextWidth, &redTeamTextHeight);

    int blueTeamTextWidth, blueTeamTextHeight;
    SDL_QueryTexture(blueTeamText, NULL, NULL, &blueTeamTextWidth, &blueTeamTextHeight);

    SDL_Rect redTeamTextRect = {10, 10, redTeamTextWidth, redTeamTextHeight};
    SDL_Rect blueTeamTextRect = {WINDOW_WIDTH - SIDE_PANEL_WIDTH + 10, 10, blueTeamTextWidth, blueTeamTextHeight};

    SDL_RenderCopy(context.renderer, redTeamText, NULL, &redTeamTextRect);
    SDL_RenderCopy(context.renderer, blueTeamText, NULL, &blueTeamTextRect);
}

// Main game loop
void gameLoop(SDLContext &context, SDL_Texture* redTeamText, SDL_Texture* blueTeamText) {
   bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Calculate stats in renderSprites
        renderSprites(context);
        SDL_Color redColor = {255, 0, 0, 255};  // Red Team
        SDL_Color blueColor = {0, 0, 255, 255}; // Blue Team


        std::string fontPath = "demo/Poppins-BlackItalic.ttf";  // Replace with your font path
        std::string redText = "Red Team:\nInfantry: "+ std::to_string(numRedInf) +"\nBoatman:"+std::to_string(numRedBoat)+"\nShieldbearers: "+std::to_string(numRedShield)+"\nTotal Damage: "+std::to_string(RedAttack)+"\nTotal Health: "+std::to_string(RedHealth)+"\nTotal Defense: "+ std::to_string(RedDefence);
        std::string blueText = "Blue Team:\nInfantry:"+ std::to_string(numBlueInf) +"\nBoatman:"+std::to_string(numBlueShield)+"\nShieldbearers: "+std::to_string(numBlueShield)+"\nTotal Damage: "+std::to_string(BlueAttack)+"\nTotal Health: "+std::to_string(BlueHealth)+"\nTotal Defense: " + std::to_string(BlueDefence);

        // Update the text with the current stats

        // Render text with updated stats
        SDL_DestroyTexture(redTeamText);  // Free the old texture
        SDL_DestroyTexture(blueTeamText); // Free the old texture
        redTeamText = renderText(redText, fontPath, redColor, 16, context.renderer);
        blueTeamText = renderText(blueText, fontPath, blueColor, 16, context.renderer);

        // Render everything
        SDL_RenderClear(context.renderer);

        // Render map
        SDL_Rect mapRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_RenderCopy(context.renderer, context.mapTexture, NULL, &mapRect);

        // Render the updated sprites and texts
        renderSprites(context);
        renderGameStats(context, redTeamText, blueTeamText);

        SDL_RenderPresent(context.renderer);
    }

    SDL_DestroyTexture(redTeamText);
    SDL_DestroyTexture(blueTeamText);
}

// Cleanup function
void cleanup(SDLContext &context) {
    SDL_DestroyTexture(context.spriteTexture);
    SDL_DestroyTexture(context.mapTexture);
    SDL_DestroyRenderer(context.renderer);
    SDL_DestroyWindow(context.window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

// Main function
int main(int argc, char* argv[]) {
    SDLContext context;

    if (!initializeSDL(context)) {
        return 1;
    }

    // Load resources
    context.mapTexture = loadTexture("demo/assets/amcharts.pixelMap.png", context.renderer);
    context.spriteTexture = loadTexture("demo/assets/shieldpng.png", context.renderer);
    if (!context.mapTexture || !context.spriteTexture) {
        cleanup(context);
        return 1;
    }


    SDL_Texture* redTeamText = NULL;
    SDL_Texture* blueTeamText = NULL;


    // Run the main game loop
    gameLoop(context, redTeamText, blueTeamText);

    cleanup(context);

    return 0;
}