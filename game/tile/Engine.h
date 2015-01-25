#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Engine
{
  private:
    sf::RenderWindow* window;

    bool init();
    void game();
    void draw();
    void read();
    void update();
  
  public:
    Engine();
    ~Engine();

    void go();
};
#endif
