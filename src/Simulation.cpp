#include "Simulation.h"

Simulation::Simulation(){
}

void Simulation::next_state(sf::RenderWindow& window, std::vector<Car>& cars, Road road){
  for (Car& car: cars) {
    car.move(car.speed, 0);
    if (car.getPosition().x >= window.getSize().x){
        car.setPosition(0, car.getPosition().y);
    }
  }
}
