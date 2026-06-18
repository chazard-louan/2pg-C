//
// Created by louan on 18/06/2026.
//

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "My Game"
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}