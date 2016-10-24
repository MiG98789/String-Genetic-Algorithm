# String Genetic Algorithm

## Introduction
[![https://gyazo.com/a280452a09ca6af46ab252299be3aaf9](https://i.gyazo.com/a280452a09ca6af46ab252299be3aaf9.png)](https://gyazo.com/a280452a09ca6af46ab252299be3aaf9)

This program uses a genetic algorithm to evolve a random string into a pre-determined string, which is "Hello world!" by default. It was created using C++.

For every generation of the population, the best citizen's solution and fitness are printed. The lower the fitness, the closer the citizen's solution is to the target solution.

## Code
### Classes
Two classes, namely the `Population` class and `Citizen` class, were made for the purpose of this genetic algorithm. All the functions used are declared in the `Population` class, and defined in Population.cpp.

#### Population
The Population class defines the population that holds every citizen of a generation, where the population is defined as `std::vector<Citizen> Population` in Population.h. 
Some variables, such as `target` and `population_size` are defined in the default constructor to facilitate any modifications related to their values.

#### Citizen
The Citizen class defines each citizen of a population through each of their solutions and fitness. These are defined by the member variables `solution` and `fitness`.

