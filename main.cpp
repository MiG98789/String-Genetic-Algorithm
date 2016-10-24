#include "Population.h"

int main(int argc, char **argv)
{
	srand(time(NULL));	//Generate time-based seed

	Population pop;	//Create an object for Population
	std::vector<Citizen> population_init, buffer_init;	//For *population and *buffer to reference to
	std::vector<Citizen> *population, *buffer;

	pop.initPopulation(population_init, buffer_init);

	population = &population_init;
	buffer = &buffer_init;

	for (int i = 1; i <= pop.getMaxGen(); i++)
	{
		pop.calcFitness(*population);	//Calculate the fitness of every citizen
		pop.fitnessSort(*population);	//Sort the population according to each citizen's fitness
		pop.printBestSolution(i, *population);	//Print the best citizen

		if ((*population)[0].fitness == 0)	//If the solution has been found (i.e. fitness = 0), break
		{
			break;
		}

		pop.mate(*population, *buffer);	//Multiply the citizens of population and buffer
		pop.swap(*population, *buffer);	//Swap the citizens of population and buffer
	}

	return 0;
}
