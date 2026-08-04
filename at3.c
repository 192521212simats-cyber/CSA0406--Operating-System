#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t R1, R2;

void *P1(void *arg) {
    pthread_mutex_lock(&R1);
    printf("P1 locked R1\n");
    sleep(1);

    pthread_mutex_lock(&R2);
    printf("P1 locked R2\n");

    pthread_mutex_unlock(&R2);
    pthread_mutex_unlock(&R1);
    return NULL;
}

void *P2(void *arg) {
    pthread_mutex_lock(&R2);
    printf("P2 locked R2\n");
    sleep(1);

    pthread_mutex_lock(&R1);
    printf("P2 locked R1\n");

    pthread_mutex_unlock(&R1);
    pthread_mutex_unlock(&R2);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&R1, NULL);
    pthread_mutex_init(&R2, NULL);

    pthread_create(&t1, NULL, P1, NULL);
    pthread_create(&t2, NULL, P2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&R1);
    pthread_mutex_destroy(&R2);

    return 0;
}
