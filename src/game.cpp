#include "Game.h"
#include "World.h"
#include "Components/Transform.h"
#include "Components/Physics.h"
#include "Components/Sprite.h"
#include "Components/ColliderAABB.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/CollisionAABBSystem.h"
#include <memory>
#include <sstream>
#include <time.h>  

World world;
SDL_Renderer* renderer;

Game::Game() {
    isRunning = false;
    countedFrames = 0;
}

void Game::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL TTF" << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        "ECS Engine 1.0v",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    isRunning = true;

    world.Init();

    world.RegisterComponent<Transform>();
    world.RegisterComponent<Physics>();
    world.RegisterComponent<Sprite>();

    auto renderSystem = world.RegisterSystem<RenderSystem>();
    renderSystem->SetRenderer(renderer);
    {
        Signature signature;
        signature.set(world.GetComponentType<Transform>());
        signature.set(world.GetComponentType<Sprite>());
        world.SetSystemSignature<RenderSystem>(signature);
    }
    renderSystem->Init();

    auto physicsSystem = world.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(world.GetComponentType<Transform>());
        signature.set(world.GetComponentType<Physics>());
        world.SetSystemSignature<PhysicsSystem>(signature);
    }
    physicsSystem->Init();

    auto collisionAABBSystem = world.RegisterSystem<CollisionAABBSystem>();
    {
        Signature signature;
        signature.set(world.GetComponentType<Transform>());
        signature.set(world.GetComponentType<ColliderAABB>());
        world.SetSystemSignature<CollisionAABBSystem>(signature);
    }
    collisionAABBSystem->Init();

    LoadLevel();
}

void Game::LoadLevel() {

    SDL_Surface* surface = IMG_Load("./assets/images/cat.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    Entity e1 = world.CreateEntity();
    world.AddComponent(e1, Transform{glm::vec2{300.0f, 100.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{2, 2}, 32, 32});
    world.AddComponent(e1, Physics{glm::vec2{-50.0f, 0.0f}, glm::vec2{0.0f, 0.0f}});
    world.AddComponent(e1, Sprite{texture});

    Entity e2 = world.CreateEntity();
    world.AddComponent(e2, Transform{glm::vec2{100.0f, 300.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{1, 1}, 32, 32});
    world.AddComponent(e2, Physics{glm::vec2{30.0f, 0.0f}, glm::vec2{0.0f, 0.0f}});
    world.AddComponent(e2, Sprite{texture});

    Entity e3 = world.CreateEntity();
    world.AddComponent(e3, Transform{glm::vec2{20.0f, 100.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{1, 1}, 32, 32});
    world.AddComponent(e3, Physics{glm::vec2{70.0f, 20.0f}, glm::vec2{0.0f, 0.0f}});
    world.AddComponent(e3, Sprite{texture});

    Entity e4 = world.CreateEntity();
    world.AddComponent(e4, Transform{glm::vec2{400.0f, 300.0f}, glm::vec2{0.0f, 0.0f}, glm::vec2{2, 2}, 32, 32});
    world.AddComponent(e4, Physics{glm::vec2{-30.0f, 0.0f}, glm::vec2{0.0f, 0.0f}});
    world.AddComponent(e4, Sprite{texture});

    int x, y , vx, vy;

    // srand(time(NULL));
    
    // for(int i = 0; i < 1000; ++i) {
    //     x = rand() % 640 + 1;
    //     y = rand() % 480 + 1;
    //     vx =rand() % 100 -50;
    //     vy =rand() % 100 -50;
    //     Entity entity = world.CreateEntity();
    //     world.AddComponent(entity, Physics{glm::vec2{vx, vy}, glm::vec2{0.0f, 0.0f}});
    //     world.AddComponent(entity, Transform{glm::vec2{x, y}, glm::vec2{0.0f, 0.0f}, glm::vec2{0, 0}});
    //     world.AddComponent(entity, Sprite{});
    // }
}

void Game::InputHandler() {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

static const int NUM_FPS_SAMPLES = 64;
float fpsSamples[NUM_FPS_SAMPLES];
int currentSample = 0;

void Game::Update() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(),  + (1000 / 60)));
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
    ticksLastFrame = SDL_GetTicks();

    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    world.Update(deltaTime);

    float avgFPS = countedFrames / ( SDL_GetTicks() / 1000.f );
    if( avgFPS > 100000 ) {
        avgFPS = 0;
    }
    std::stringstream ss;
    ss << avgFPS;
    std::string windowTitle = "Game Engine 1.0v - FPS: " + ss.str();
    SDL_SetWindowTitle(window, windowTitle.c_str());

    ++countedFrames;
}

void Game::Render() {
    // SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    // SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Game::IsRunning() const {
    return isRunning;
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}