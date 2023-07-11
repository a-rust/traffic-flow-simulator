# Table of Contents
- [Table of Contents](#table-of-contents)
- [Project Description](#project-description)
  - [Simulation Features](#simulation-features)
- [Simulation](#simulation)
  - [Preliminaries](#preliminaries)
  - [Definitions](#definitions)
  - [Cellular Automaton Rules](#cellular-automaton-rules)

# Project Description
A 2-dimensional cellular automaton that simulates the flow of traffic on multi-lane highways.
## Simulation Features
- [x] Speed limits
- [x] Cars that change speed
- [x] Carpool lanes
- [x] Safety parameters to avoid collisions

# Simulation
## Preliminaries
The simulation will run on a 2-dimensional grid with a road consisting of a number of lanes (set by the user)
* All cars will be driving eastbound at a given speed
* For simplicity, all cars will be of the same size
* Each lane will have a minimum speed limit and a maximum speed limit
  * All cars driving on lane $l$ must be traveling within $l$'s minimum speed limit and maximum speed limit
  * The maximum speed limit of all non-carpool lanes will be some value set by the user
  * The maximum speed limit of all carpool lanes will be $1.25$ times the maximum speed limit of non-carpool lanes
  * The minimum speed limit of all lanes will be some value set by the user

## Definitions
1. Consider an arbitrary car $c$ of length $x$ driving eastbound on lane $l$ with a speed of $s$. Now suppose that $c$ covers the road on $l$ from $[r, r+x]$ for some $r\in \mathbb{R}$. We define a "space" in front of $c$ to be the road on $l$ spanning over $[r+x, r+2x]$
   * For example, if $c$ is $100$ meters long and driving on lane $l$ with a speed of $s$, and $c$ covers the road on $l$ from $[1000, 1100]$, then 1 space in front of $c$ will be the road on $l$ spanning over $[1100, 1200]$
2. Let $C_c$ be the set of all cars $c' \neq c$ on lane $l$ such that $c' \in C$ is located at least 1 space in front of $c$.
3. A car $c'\in C_c$ is "closest" to $c$ if the number of spaces between $c'$ and $c$ is less than the number of spaces between $c''$ and $c$ for all $c''\neq c' \in C_c$. 
4. For an arbitrary lane $l$, let the minimum speed limit and maximum speed limit be denoted by $l_\text{min}$ and $l_\text{max}$, respectively 
5. Let $N$ be the safety parameter used to update the speed of a car with the goal of improving traffic while also avoiding collisions

## Cellular Automaton Rules
For an arbitrary car $c$ of length $x$ traveling eastbound on lane $l$,
1. If for every $c' \in C_c$, $c'$ is at least $N$ spaces in front of $c$, then update the speed of $c$ to be the speed of the closest car in front $c$ plus some $\epsilon \in [l_\text{min}, l_\text{max}]$, where $\epsilon$ is set by the user
2. If there exists some $c' \in C_c$ such that $c'$ is within N spaces of $c$, then update the speed of $c$ to be the speed of the closest car in front $c$ minus some $\epsilon \in [l_\text{min}, l_\text{max}]$, where $\epsilon$ is set by the user
