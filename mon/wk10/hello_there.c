// 

#include <stdio.h>
#include <pthread.h>

// the function being called as a thread must be a 
// function pointer (void *)
void *thread_func(void *data) {
    char *message = data;
    
    while (1) {
        printf("%s", message);
    }
    
    return NULL;
}

int main (void) {    
    // calling the function normally
    // thread_func("Hello\n");
    
    // spawn a thread with the function printing hello
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, "Hello\n");
    
    while (1) {
        printf("there!\n");
    }
    
    // get rid of the other thread (cancel)
    pthread_cancel(thread);
    
}
