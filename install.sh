#!/bin/bash
g++ src/window.cpp src/Simulation.cpp src/Car.cpp src/Road.cpp -I /opt/homebrew/Cellar/sfml/2.5.1_2/include -o app -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system && ./app