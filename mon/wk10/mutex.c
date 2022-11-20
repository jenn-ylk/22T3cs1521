#include <stdio.h>
#include <pthread.h>

// _Atomic int global_total = 0;
int global_total = 0;
pthread_mutex_t total_mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_5000_to_counter(void *data) {
    for (int i = 0; i < 5000; i++) {
        // sleep for 10 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 5000}, NULL);
        
        // pthread_mutex_lock(&total_mutex);
        // increment the global total by 1
        int temp = global_total;
        temp += 1;
        global_total = temp;
        // pthread_mutex_unlock(&total_mutex);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_5000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_5000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // if program works correctly, should print 10000
    printf("Final total: %d\n", global_total);
}
