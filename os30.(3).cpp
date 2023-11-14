#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    if (pthread_equal(pthread_self(), *((pthread_t*) arg))) {
        printf("The current thread is equal to the target thread\n");
    } else {
        printf("The current thread is not equal to the target thread\n");
    }
    return NULL;
}

int main() {
    pthread_t tid;
    int result;

    // Create a new thread
    result = pthread_create(&tid, NULL, thread_function, &tid);
    if (result != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    // Wait for the new thread to finish execution
    pthread_join(tid, NULL);
    return 0;
}
