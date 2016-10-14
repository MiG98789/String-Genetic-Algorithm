# String Genetic Algorithm

## Introduction
This program uses a genetic algorithm to evolve a random string into pre-determined string, which is "Hello world!" by default. It was created by using Visual C++ for Visual Studio 2015.

## Code
### Classes
Two classes, namely the Population class and Citizen class, were made for the purpose of this genetic algorithm. All the functions used are declared in the Population class, and defined in Population.cpp.

#### Population
The Population class defines the population that holds every citizen of a generation, where the population is defined as `std::vector<Citizen> Population;` in Population.h. 
Some variables, such as `target` and `population_size` are defined in the default constructor to facilitate any modifications related to their values, such as the target string.

#### Citizen
The Citizen class defines each citizen of a population through each of their solutions and fitness. These are defined by the member variables `solution` and `fitness`.

