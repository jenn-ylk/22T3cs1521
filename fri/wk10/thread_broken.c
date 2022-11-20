// an example of thread code with a bug in it, 
// that makes us not produce any output

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("Hello from thread!\n");

    return NULL;
}

// TODO: fix the main so the thread's output shows
int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    // wait for the thread to return before exiting the program
    pthread_join(thread, NULL);
    return 0;
}
