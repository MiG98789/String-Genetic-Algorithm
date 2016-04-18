#include "Population.h"

Population::Population() //Default constructor
{
	population_size = 2000;
	max_generation = 20000;
	elitism_rate = 0.25f;
	mutation_rate = 0.1f;
	target = "Hello world!";
	population.clear();
}

void Population::initPopulation(std::vector<Citizen> &population, std::vector<Citizen> &buffer) //To initialise the population | buffer to store temporary population information
{
	for (int i = 0; i < population_size; i++)	//Initialise citizens
	{
		//Initialise each citizen
		Citizen citizen;
		citizen.fitness = 0;
		citizen.solution.clear();

		for (int j = 0; j < static_cast<int>(target.size()); j++)
		{
			citizen.solution += (rand() % 90) + 32;	//Set a random string for each citizen's solution
		}

		population.push_back(citizen);	//Push each citizen into the population vector
	}

	buffer.resize(population_size);
}

void Population::calcFitness(std::vector<Citizen> &population)	//To calculate the fitness of each citizen of the population
{
	for (int i = 0; i < population_size; i++)
	{
		population[i].fitness = 0;

		for (int j = 0; j < static_cast<int>(target.size()); j++)
		{
			population[i].fitness += abs(int(population[i].solution[j] - target[j]));
		}
	}
}

bool Population::sortFunc(Citizen a, Citizen b)	//Sorting function
{
	return (a.fitness < b.fitness);
}

void Population::fitnessSort(std::vector<Citizen> &population)	//Sort population by fitness
{
	std::sort(population.begin(), population.end(), Population::sortFunc);
}

void Population::eliteFilter(std::vector<Citizen> &population, std::vector<Citizen> &buffer, int elite_size)	//Put elite citizens into buffer
{
	for (int i = 0; i < elite_size; i++)
	{
		buffer[i] = population[i];
	}
}

void Population::mutate(Citizen citizen)	//Mutate a citizen
{
	int mutation_pos = rand() % target.size();	//Find the position in the solution string to mutate
	int mutation = rand() % 122;	//Find the character mutation

	citizen.solution[mutation_pos] = (citizen.solution[mutation_pos] + mutation) % 122;	//Replace the character with its mutation
}

void Population::mate(std::vector<Citizen> &population, std::vector<Citizen> &buffer)	//Filter out elite citizens, and multiply them
{
	int elite_size = population_size * elitism_rate;
	int mate_pos;	//Find the multiply position for two strings
	int i1, i2; //The i1-th and i2-th elite citizen will mate

	Population::eliteFilter(population, buffer, elite_size);	//Filter out elite citizens into buffer

	for (int i = elite_size; i < population_size; i++)	//For the remaining citizens, they get replaced by the multiplied elite citizens
	{
		i1 = rand() % (population_size / 2);
		i2 = rand() % (population_size / 2);
		mate_pos = rand() % static_cast<int>(target.size());

		buffer[i].solution = population[i1].solution.substr(0, mate_pos) + population[i2].solution.substr(mate_pos, elite_size - mate_pos);

		if (rand() < mutation_rate * RAND_MAX)	//As long as randomness is under the maximum mutation, mutate
		{
			mutate(buffer[i]);
		}
	}
}

void Population::printBestSolution(std::vector<Citizen> &population)	//Print the best solution
{
	std::cout << "Best solution: " << population[0].solution << " ,Fitness: " << population[0].fitness << "" << std::endl;
}

void Population::swap(std::vector<Citizen> &population, std::vector<Citizen> &buffer) //Swap the citizens of population and buffer
{
	std::vector<Citizen> temp = population; 
	population = buffer; 
	buffer = temp;
}

int Population::getMaxGen()	//Get maximum number of generations
{
	return max_generation;
}