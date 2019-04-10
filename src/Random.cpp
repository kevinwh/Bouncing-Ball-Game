#include "Random.hpp"

Random::Random() {
	int seed = time(NULL);
	srand(seed);
	for (int i =0 ; i< 10; i++){
		rList[i] = rand() % 100;
		//printf("%d\n",rList[i]);
	}
}
