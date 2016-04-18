#pragma once

#include <vector>		//To store all citizens of a population
#include <algorithm>	//To sort elements of vector
#include <cmath>		//For std::abs to get absolute value
#include <time.h>		//For time()

#include "Citizen.h"	//To get definition of Citizen

class Population
{
private:
	int population_size;				//Size of the population
	int max_generation;					//Maximum number of generations
	float elitism_rate;					//Percentage of population considered as elite citizens
	float mutation_rate;				//How much mutation will occur
	std::string target;					//Target string
	std::vector<Citizen> population;	//Population vector to hold all citizens	

public:
	Population();	//Defualt constructor
	Population(int w, int x, float y, float z, std::string s, std::vector<Citizen> p) : population_size(w), max_generation(x), elitism_rate(y), mutation_rate(z), target(s), population(p) {}

	void initPopulation(std::vector<Citizen> &population, std::vector<Citizen> &buffer);	//To initialise the population | buffer to store temporary population information
	void calcFitness(std::vector<Citizen> &population);	//To calculate the fitness of each citizen of the population
	static bool sortFunc(Citizen a, Citizen b);	//Sorting function
	void fitnessSort(std::vector<Citizen> &population);	//Sort population by fitness
	void eliteFilter(std::vector<Citizen> &population, std::vector<Citizen> &buffer, int elite_size);	//Put elite citizens into buffer
	void mutate(Citizen citizen);	//Mutate a citizen
	void mate(std::vector<Citizen> &population, std::vector<Citizen> &buffer);	//Filter out elite citizens, and multiply them
	void printBestSolution(std::vector<Citizen> &population);	//Print the best solution
	void swap(std::vector<Citizen> &population, std::vector<Citizen> &buffer);	//Swap the citizens of population and buffer

	int getMaxGen();	//Get maximum number of generations
};
