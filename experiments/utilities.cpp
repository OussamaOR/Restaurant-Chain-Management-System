
#include <ctime>
#include <iostream>
#include <vector>
#include "utilities.h"

unsigned generate_random_interv(unsigned x, unsigned y) {        // including both
	if (x > y) std::swap(x, y);
	return (rand() % (y - x + 1)) + x;
}
void fill_vector(std::vector<unsigned>& vec, unsigned low , unsigned high) {
	for (int i = 0;i < vec.size();i++) {
		vec[i] = generate_random_interv(low, high);
	}
}