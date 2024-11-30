#include "Game.h"

int main()
{
    Game game;

    game.initVariables();
    game.initEnemies();

    sf::Clock clk;
    sf::Time deltaTime;

    while (game.getWindowIsOpen() == true)
    {
        deltaTime = clk.restart();

        game.pollEvents();

        game.update(deltaTime.asSeconds());

        game.render(deltaTime.asSeconds());
    }

    return 0;
}