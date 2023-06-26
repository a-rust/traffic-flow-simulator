#include <SFML/Graphics.hpp>
#include "Car.h"
#include <time.h>

// Model parameters; randomly set for now
const int NUM_LANES = 10;
const int NUM_CARS = 500;
const int ROAD_WIDTH = 400;

void draw_cars(sf::RenderWindow& window, std::vector<Car>& cars) {
  for (Car& car: cars) {
    car.draw(window);
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Traffic Flow Simulator");
    Road highway(window, sf::Vector2f(window.getSize().x, ROAD_WIDTH), NUM_LANES);
    std::vector<Car> cars;
    srand(time(NULL));
    // Initial configuration of the simulation
    for (int i = 0; i < NUM_CARS; i++) {
        int lane = 1 + rand() % highway.lanes;
        int lane_position = 1 + rand() % (window.getSize().x / 25);
        Car c(window, highway, sf::Color::Green, lane, lane_position);
        cars.push_back(c);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

    highway.draw(window, highway.lanes);

    draw_cars(window, cars);

    window.display();
    }
    return 0;
}
