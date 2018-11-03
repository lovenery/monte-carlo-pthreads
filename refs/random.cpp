#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

double get_random() {
    unsigned int seed = rand();
    double min = -1;
    double max = 1;
    double f = (double) rand_r(&seed) / RAND_MAX;
    double x = min + f * (max - min);
    return x; // min <= x <= max
}

int main() {
    srand( time(NULL) );
    
    for(int i = 0; i < 100; i++) {
        cout << get_random() << endl;
    }
    
    return 0;
}