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

using namespace std;
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

int RedAttack;
int BlueAttack;
int RedHealth;
int BlueHealth;
int RedDefence;
int BlueDefence;

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

// Helper function to split text by newline
std::vector<std::string> splitText(const std::string& text) {
    std::vector<std::string> lines;
    std::stringstream ss(text);
    std::string line;
    while (std::getline(ss, line)) {
        lines.push_back(line);
    }
    return lines;
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

    Soldiers* redInf1 = Redinf.createUnit();
    Soldiers* redBoat1 = Redboat.createUnit();
    Soldiers* redsh1 =Redsh.createUnit();
    Soldiers* blueInf1 = Blueinf.createUnit();
    Soldiers* blueBoat1 = Blueboat.createUnit();
    Soldiers* blueSh1 = Bluesh.createUnit();

    redInfantry.push_back(redInf1);
    redBoatman.push_back(redBoat1);
    redShieldBearer.push_back(redsh1);
    blueInfantry.push_back(blueInf1);
    blueBoatman.push_back(blueBoat1);
    blueShieldBearer.push_back(blueSh1);

    for (int i = 0; i < 4; ++i) {
        redInfantry.push_back(redInf1->clonis());
        redBoatman.push_back(redBoat1->clonis());
        redShieldBearer.push_back(redsh1->clonis());
        blueInfantry.push_back(blueInf1->clonis());
        blueBoatman.push_back(blueBoat1->clonis());
        blueShieldBearer.push_back(blueSh1->clonis());
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

    RedAttack = RedInfAttack + RedShieldAttack + RedBoatAttack;
    BlueAttack = BlueInfAttack + BlueShieldAttack + BlueBoatAttack;
    RedHealth = RedBoatHealth + RedShieldHealth + RedInfHealth;
    BlueHealth = BlueBoatHealth + BlueShieldHealth + BlueInfHealth;
    RedDefence = RedBoatDefence + RedShieldDefence + RedInfDefence;
    BlueDefence = BlueBoatDefence + BlueShieldDefence + BlueInfDefence;

   
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
    std::vector<SDL_Texture*> redInfantrySprites(10, redInfTexture);
    std::vector<SDL_Texture*> blueInfantrySprites(10, blueInfTexture);
    std::vector<SDL_Texture*> redBoatmanSprites(10, redBoatTexture);
    std::vector<SDL_Texture*> blueBoatmanSprites(10, blueBoatTexture);
    std::vector<SDL_Texture*> redShieldBearerSprites(10, shieldTexture);
    std::vector<SDL_Texture*> blueShieldBearerSprites(10, shieldTexture);

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
void renderGameStats(SDLContext &context, SDL_Texture* redTeamText, SDL_Texture* blueTeamText, TTF_Font* font) {
    int textPadding = 20; // Padding from the sides
    int lineHeight = 20;  // Height of each line

    //renderSprites(context);  // This must be called in the loop after clearing and before presenting

    // Define colors
    SDL_Color redColor = {255, 0, 0, 255};
    SDL_Color blueColor = {0, 0, 255, 255};

    // Red Team text
    std::string redText = "Red Team:\nInfantry: " + std::to_string(numRedInf) +
                          "\nBoatman: " + std::to_string(numRedBoat) +
                          "\nShieldbearers: " + std::to_string(numRedShield) +
                          "\nTotal Damage: " + std::to_string(RedAttack) +
                          "\nTotal Health: " + std::to_string(RedHealth) +
                          "\nTotal Defense: " + std::to_string(RedDefence);
    
    std::vector<std::string> redLines = splitText(redText);

    // Blue Team text
    std::string blueText = "Blue Team:\nInfantry: " + std::to_string(numBlueInf) +
                           "\nBoatman: " + std::to_string(numBlueBoat) +
                           "\nShieldbearers: " + std::to_string(numBlueShield) +
                           "\nTotal Damage: " + std::to_string(BlueAttack) +
                           "\nTotal Health: " + std::to_string(BlueHealth) +
                           "\nTotal Defense: " + std::to_string(BlueDefence);
    
    std::vector<std::string> blueLines = splitText(blueText);

    // Render each line of Red Team text
    int redTextY = 20; // Starting y position for the Red Team text
    for (const auto& line : redLines) {
        SDL_Surface* surface = TTF_RenderText_Blended(font, line.c_str(), redColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(context.renderer, surface);
        SDL_Rect redTextRect = {textPadding, redTextY, surface->w, surface->h};
        SDL_RenderCopy(context.renderer, texture, NULL, &redTextRect);
        redTextY += surface->h + 5; // Move to the next line
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    // Render each line of Blue Team text
    int blueTextY = 20; // Starting y position for the Blue Team text
    for (const auto& line : blueLines) {
        SDL_Surface* surface = TTF_RenderText_Blended(font, line.c_str(), blueColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(context.renderer, surface);
        SDL_Rect blueTextRect = {WINDOW_WIDTH - surface->w - textPadding, blueTextY, surface->w, surface->h};
        SDL_RenderCopy(context.renderer, texture, NULL, &blueTextRect);
        blueTextY += surface->h + 5; // Move to the next line
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

// Main game loop
void gameLoop(SDLContext &context, SDL_Texture* redTeamText, SDL_Texture* blueTeamText) {
 bool quit = false;
    SDL_Event e;

    SDL_Color redColor = {255, 0, 0, 255};  // Red Team color
    SDL_Color blueColor = {0, 0, 255, 255}; // Blue Team color
    std::string fontPath = "demo/Poppins-BlackItalic.ttf";  // Path to font

    // Load the font once
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 16);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    // Initial render of sprites and map, before entering the loop
    SDL_RenderClear(context.renderer);
    SDL_Rect mapRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderCopy(context.renderer, context.mapTexture, NULL, &mapRect);
    renderSprites(context);
    SDL_RenderPresent(context.renderer);

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Calculate updated stats for rendering
        std::string redText = "Red Team:\nInfantry: " + std::to_string(numRedInf) +
                              "\nBoatman: " + std::to_string(numRedBoat) +
                              "\nShieldbearers: " + std::to_string(numRedShield) +
                              "\nTotal Damage: " + std::to_string(RedAttack) +
                              "\nTotal Health: " + std::to_string(RedHealth) +
                              "\nTotal Defense: " + std::to_string(RedDefence);

        std::string blueText = "Blue Team:\nInfantry: " + std::to_string(numBlueInf) +
                               "\nBoatman: " + std::to_string(numBlueBoat) +
                               "\nShieldbearers: " + std::to_string(numBlueShield) +
                               "\nTotal Damage: " + std::to_string(BlueAttack) +
                               "\nTotal Health: " + std::to_string(BlueHealth) +
                               "\nTotal Defense: " + std::to_string(BlueDefence);

        // Update text textures with the latest stats
        SDL_DestroyTexture(redTeamText);  // Free the old texture
        SDL_DestroyTexture(blueTeamText); // Free the old texture
        redTeamText = renderText(redText, fontPath, redColor, 16, context.renderer);
        blueTeamText = renderText(blueText, fontPath, blueColor, 16, context.renderer);

        // Clear renderer before drawing
        SDL_RenderClear(context.renderer);

        // Render map and sprites
        SDL_RenderCopy(context.renderer, context.mapTexture, NULL, &mapRect);

        //renderSprites(context); // TODO: comment out this line to show the correct stats.

        // Render game stats (text)
        renderGameStats(context, redTeamText, blueTeamText, font);

        SDL_RenderPresent(context.renderer);
    }

    TTF_CloseFont(font);
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


void printPattern(const std::string &pattern, const std::string &color)
{
    std::cout << color << pattern << "\033[0m" << std::endl;
}

void testFactoryMethod();
void testTemplateMethod();
void testMementoMethod();
void testPrototypeMethod();

void testFactoryMethod()
{
    //Create 
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

   std::cout << std::endl;

    Soldiers *infantry = infantryFactory.createUnit();
    Soldiers *shieldBearer = shieldBearerFactory.createUnit();
    Soldiers *boatman = boatmanFactory.createUnit();

    std::cout << endl;

   std::cout << "- Testing Calculate Functions from Factory Method:\n\n";

    // Test calculateTotalHealthPerUnit
   std::cout << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << '\n';
   std::cout << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << '\n';
    std::cout << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n';

    std::cout<< endl;

    // Test calculateTotalDamagePerUnit
    std::cout << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n';

    std::cout << endl;

    // Test calculateTotalDefencePerUnit
   std::cout << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n';

   std::cout << endl;

    std::cout << "Boatman Total units: " << boatmanFactory.calculateTotalNumOfUnits() << "\n";
    std::cout << "ShieldBearer Total units: " << shieldBearerFactory.calculateToTalNumUnits() << "\n";
   std::cout << "Infantry Total units: " << infantryFactory.calculateTotalNumOfUnits() << "\n";
}

void testTemplateMethod()
{
    //engage and disengage
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[34m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "#############################";

    InfantryFactory factory1;
    BoatmanFactory factory2;
    ShieldBearerFactory factory3;

    Soldiers* shieldy = factory3.createUnit();
    Soldiers* boaty = factory2.createUnit();
    Soldiers* fantry = factory1.createUnit();


    std::cout<<yellow<<"INFANTRY IS ENGAGING: "<< reset<<std::endl;
    fantry->engage();
    printPattern(pattern, blue);
    std::cout<<yellow<<"INFANTRY IS DISENGAGING: "<< reset<<std::endl;
    fantry->disengage();
    printPattern(pattern, blue);

    std::cout<<yellow<<" BOATMAN IS ENGAGING: "<< reset<<std::endl;
    boaty->engage();
    printPattern(pattern, yellow);
    std::cout<<yellow<<" BOATMAN IS DISENGAGING: " << reset<<std::endl;
    boaty->disengage();

    std::cout<<yellow<<" SHIELDBEARER IS ENGAGING: "<< reset<<std::endl;
    shieldy->engage();
    printPattern(pattern, green);
    std::cout<<yellow<<"SHIELDBEARER IS DISENGAGING: "<< reset<<std::endl;
    shieldy->disengage();


}

void testMementoMethod()
{
    const std::string red = "\033[91m";
    const std::string green = "\033[92m";
    const std::string yellow = "\033[93m";
    const std::string blue = "\033[34m";
    const std::string purple = "\033[35m";
    const std::string reset = "\033[0m";
    const std::string pattern = "*~*~*~*~*~*~*~~*~";
    
    InfantryFactory inf;
    BoatmanFactory boat;
    ShieldBearerFactory shield;
    CareTaker care;

    Soldiers* shieldy = shield.createUnit();
    Soldiers* boaty = boat.createUnit();
    Soldiers* fantry = inf.createUnit();

    
    printPattern(pattern, red);
    std::cout << red << " Infantry  unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << fantry->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << fantry->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << fantry->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << fantry->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);

    printPattern(pattern , yellow);
    std::cout << red << "Boatman unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset <<boaty->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, yellow);

    printPattern(pattern, green);
    std::cout << red << "ShieldBearer unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset<<shieldy->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);

 
    Memento *saveB = boaty->militusMemento();
    care.addMemento(saveB);
    fantry->Attack(boaty);
    std::cout << yellow << "Boatman unit state after attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset << boaty->getDefensePerSoldier() <<std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);

    //restore:
    Memento* restB = care.getMemento();
    boaty->vivificaMemento(restB);
    std::cout << yellow << "Boatman unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset<<boaty->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
     

     Memento * saveF = fantry->militusMemento();
     care.addMemento(saveF);
    fantry->vivificaMemento(care.getMemento());
    std::cout << yellow << "Infantry unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << fantry->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << fantry->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset <<fantry->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << fantry->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);


    Memento* saveS = shieldy->militusMemento();
    care.addMemento(saveS);
    boaty->Attack(shieldy);
    std::cout << yellow << "ShieldBearer unit state after attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " <<reset<<shieldy->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    //restore:
    Memento* restS = care.getMemento();
    shieldy->vivificaMemento(restS);
    std::cout << yellow << "ShieldBearer unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset<<shieldy->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    //attack again
   fantry->Attack(shieldy);
    std::cout << blue<< "ShieldBearer unit state after attack again :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: "<<reset <<shieldy->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    //attack again
}

void testPrototypeMethod()
{
    const std::string blue = "\033[96m";
    const std::string green = "\033[35m";
    const std::string purple  = "\033[91m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "......................";

    ShieldBearerFactory sF;
    InfantryFactory iF ;
    BoatmanFactory bF ;

    Soldiers* shld = sF.createUnit();
    Soldiers* inf = iF.createUnit();
    Soldiers* btm = bF.createUnit();

    Soldiers * cloneShld = shld->clonis();
    Soldiers * cloneInf = inf->clonis();
    Soldiers * cloneBtm = btm->clonis();

    //display:
    std::cout << yellow << "Original ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shld->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shld->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shld->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shld->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneShld->getHealthPerSoldier() <<std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneShld->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneShld->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneShld->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);
    std::cout << yellow << "Original Infantry unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << inf->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << inf->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << inf->getDefensePerSoldier() <<std::endl;
    std::cout << purple << "Unit(s): " << reset << inf->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned Infantry unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneInf->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneInf->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneInf->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneInf->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern,blue);
    std::cout << yellow << "Original Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << btm->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << btm->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset<<btm->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << btm->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneBtm->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneBtm->getDamagePerSoldier()<<std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneBtm->getDefensePerSoldier()<<std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneBtm->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

}

// Main function
int main(int argc, char* argv[]) {
    bool demo = false;// to run demo GUI

    if(demo) {
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
    } else {
        testFactoryMethod();
        testTemplateMethod();
        testPrototypeMethod();
        testMementoMethod();
    }

    return 0;
}


