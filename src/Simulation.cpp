#include "Simulation.h"
#include <vector>

Simulation::Simulation(std::vector<int> carpool_lanes, int max_speed_limit, int min_speed_limit, int spaces_to_decrease, int decrease_speed, int spaces_to_increase, int increase_speed){
    this->carpool_lanes = carpool_lanes;
    this->max_speed_limit = max_speed_limit;
    this->min_speed_limit = min_speed_limit;
    this->spaces_to_decrease = spaces_to_decrease;
    this->decrease_speed = decrease_speed;
    this->spaces_to_increase = spaces_to_increase;
    this->increase_speed = increase_speed;
}

void Simulation::highway(sf::RenderWindow& window, std::vector<Car>& cars, Road road){
    // Checking the neighbors of each car
    for (int i = 0; i < cars.size(); i++) {
        Car& car1 = cars[i];

        // Will represent the closest car in front of car1 within the same lane as car1
        Car* nearest_car;
        // nearest_car_distance will update to represent the minimum distance between car1 and nearest_car
        //  Start by assuming that no car in car1's lane is in front of car1, and update accordingly
        float nearest_car_distance = window.getSize().x;
        // Looping through the every other car to see if it is a neighbor to car1
        for (int j = 0; j < cars.size(); j++) {
            // Continue if we compare car1 to car1 (i.e., car1 = car2)
            if (i == j){
                continue;
            }
            Car& car2 = cars[j];

            // Check to see if car1 and car2 are on the same lane
            if (car1.lane == car2.lane) {
                // Get the distance between car1 and car2
                float distance_between_cars = car2.getPosition().x - car1.getPosition().x;
                // Check to see if car2 is in front of car1, and check to see if the distance between car2 and car1 is smaller than the other distances between car1 and every other car in the lane of car1
                if (distance_between_cars > 0 && distance_between_cars < nearest_car_distance) {
                // Update the nearest car and the minimum distance if car2 is in fact the closest car to car1 (in the same lane)
                nearest_car = &car2;
                nearest_car_distance = distance_between_cars;
                }
            }
        }

        // Cellular automaton rules:

        // If there are any cars within N spaces in front of car1 (where each space is the length of car1), then decrease the speed of car1
            // Example, if the x position of car1 is 500, the x position of the closest car in front is 600, the length of car1 is 50, and spaces_to_decrease = 2, then the speed of car1 will decrease by decrease_speed
        if (nearest_car_distance <= this->spaces_to_decrease*car1.getSize().x) {
            car1.speed = car1.speed + this->decrease_speed;
        } 
        // If there are no cars within N spaces in front of car1 (where each space is the length of car1), then increase the speed of car1
            // Example, if the x position of car1 is 500, the x position of the closest car in front is 675, the length of car1 is 50, and num_cars_to_decrease_speed = 3, then the speed of car1 will increase by increase_speed
        else if (nearest_car_distance > this->spaces_to_increase*car1.getSize().x) {
            car1.speed = car1.speed + this->increase_speed;
        }

        // Carpool lanes
        bool car_in_carpool_lane = false;
        for (int& lane: carpool_lanes){
            if (car1.lane == lane){
                car_in_carpool_lane = true;
                break;
            }
        }

        if (car_in_carpool_lane){
            // Enforce a speed limit for cars in carpool lanes
            if (car1.speed < this->min_speed_limit) {
                car1.speed = this->min_speed_limit;
            } else if (car1.speed > ceil(1.25*this->max_speed_limit)) {
                car1.speed = ceil(1.25*this->max_speed_limit);
            }
        } else {
            // Enforce a speed limit for cars not in carpool lanes
            if (car1.speed < this->min_speed_limit) {
                car1.speed = this->min_speed_limit;
            } else if (car1.speed > this->max_speed_limit) {
                car1.speed = this->max_speed_limit;
            }
        }
        
        // Move car1 by the state of its speed
        car1.move(car1.speed, 0);

        // For illustrative purposes, if car1 reaches the end of the road, it will loop back
        if (car1.getPosition().x >= road.getSize().x){
            car1.setPosition(0, car1.getPosition().y);
        }
    }
}