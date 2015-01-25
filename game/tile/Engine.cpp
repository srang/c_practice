#include "Engine.h"
#include <SFML/Graphics.hpp>

Engine::Engine() { }

Engine::~Engine() { }

bool Engine::init()
{
  window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG");
  if(!window)
    return false;
  return true;
}
void Engine::draw()
{ }

void Engine::read()
{
  sf::Event evt;
  while(window->PollEvent(evt))
  {
    if(evt.Type == sf::Event::Closed)
      window->Close();
  }
}

void Engine::update()
{ }

void Engine::game()
{
  while(window->IsOpened())
  {
    read();
    update();
    draw();
  }
}

void Engine::go()
{
  if(!init())
    throw "Could not initialize engine";

  game();
}
