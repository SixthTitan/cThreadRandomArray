/**
  * Thread Manager
  * This program displays the maximum and minimum values from an array
  * the numbers in the array are randomly generated each time it is run and the execution time is displayed
  * @author Lauren Brown
  * @version 2018.12.2
  * @license Open Source Apache License
  */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int result[10];

pthread_t thread_id;
clock_t total_time;

void RandomGen(int min, int max) {

    int i, n;
    time_t t;

    n = 10;

    /* Initializes random number generator */
    srand((unsigned) time(&t));

    /* Print 10 random numbers from 0 to 49 */
    for( i = min ; i < n ; i++ ) {
        printf("%d\n", rand() % max);
        result[i] = ( rand() % max);
    }

}

void MinArrayStack(int size) {
    int minimum = result[0];

    /** find the minimum element in the given array */
    for ( int i = 0; i < size; i++) {
        if (result[i] < minimum) {
            minimum = result[i];

        }
    }

    printf("\n Minimum value is %d.\n", minimum);
}

void MaxArrayStack(int size) {
    int maximum = result[0];

    /** find the maximum element in the given array */
    for ( int i = 0; i < size; i++) {
        if (result[i] > maximum) {
            maximum = result[i];

        }
    }

    printf("\n Maximum value is %d.\n", maximum);
}

void *ThreadRunner() {
    sleep(1);

    RandomGen(0, 50000); //Generate a random number between 0 to 50000

    printf(result, "\n");

    printf("\n***************************");
    MaxArrayStack(10);
    MinArrayStack(10);
    printf("\n***************************");

    return NULL;
}

void ThreadManager(pthread_t id) {

    pthread_create(&thread_id, NULL, ThreadRunner, NULL);
    pthread_join(thread_id, NULL);

    /** Retrieve and Display current running thread ID */
    size_t i;

    printf("\n");
    printf("\n Thread running on ID: ");

    for (i = sizeof(i); i; --i)
        printf("%01x", *(((unsigned char*) &id) + i - 1));

    total_time = clock(); // Track total execution time, here since this is our last function

}


int main() {
    pthread_t id = pthread_self();

    ThreadManager(id);
    printf("\n");

    printf("\n \n Time Elapsed: %f seconds\n", (double)( total_time) / CLOCKS_PER_SEC);

    return 0;
}