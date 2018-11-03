#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

long long int number_of_tosses;
int number_of_threads;

void *thread_handler(void *) {
    // Random
    double min = -1;
    double max = 1;
    unsigned int seed = (unsigned)time(NULL);
    double x;
    double y;
    double distance_squared;

    // Toss
    long long int *number_in_circle = (long long int *)malloc( sizeof(long long int) );
    *number_in_circle = 0;
    long long int thread_number_of_tosses = number_of_tosses / number_of_threads;
    for (int toss = 0; toss < thread_number_of_tosses; toss++) {
        x = min + (double) rand_r(&seed) / RAND_MAX * (max - min);
        y = min + (double) rand_r(&seed) / RAND_MAX * (max - min);
        distance_squared = x*x + y*y;
        if (distance_squared <= 1) {
            (*number_in_circle)++;
        }
    }

    pthread_exit((void *) number_in_circle);
}

int main(int argc, char** argv) {
    // time_t start_time = time(NULL); // Timer

    // Setting global variables
    // 10 million = 10,000,000 (10000000)
    number_of_threads = atoi(argv[1]); //8;
    number_of_tosses = atoi(argv[2]); //1000000000;
    srand( (unsigned)time(NULL) );

    // Create pthreads
    pthread_t thread_array[number_of_threads];
    for (int i = 0; i < number_of_threads; i++) {
        if (pthread_create(&thread_array[i], NULL, thread_handler, NULL) != 0) {
            printf ("Create pthread error!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join pthreads
    long long int final_number_in_circle = 0;
    void* result;
    for (int i = 0; i < number_of_threads; i++) {
        pthread_join(thread_array[i], &result);
        // cout << "Thread ID: " << i << ", number of tosses: " << *(long long int *) result << endl;
        final_number_in_circle += *(long long int *) result;
    }

    // Print result
    double pi_estimate = 4 * final_number_in_circle / (double) number_of_tosses;
    cout << pi_estimate << endl;
    // cout << "pi_estimate: " << pi_estimate << endl;

    // cout << time(NULL) - start_time << "s." << endl; // Timer
    return 0;
}
