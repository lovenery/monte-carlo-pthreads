#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

double get_random() {
    // srand( time(NULL) );
    double min = -1;
    double max = 1;
    double f = (double) rand() / RAND_MAX;
    double x = min + f * (max - min);
    return x; // min <= x <= max
}

int main() {
    std::cout << "hi" << endl;

    long long int number_in_circle = 0;
    long long int number_of_tosses = 1000000;
    double x;
    double y;
    double distance_squared;
    double pi_estimate;
    
    for (int toss = 0; toss < number_of_tosses; toss++) {
        // cout << get_random() << endl;
        x = get_random();
        y = get_random();
        distance_squared = x*x + y*y;
        if (distance_squared <= 1) {
            number_in_circle++;
        }
    }
    pi_estimate = 4 * number_in_circle / ((double) number_of_tosses);

    cout << pi_estimate << endl;

    return 0;
}