// Author : Anant Bansal
// IMPORTANT NOTE : Run this code IGNORING WARNINGS!!! build will be Successfull in VSCode Environment in Linux OS

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include  <sys/types.h>
#include <semaphore.h>

#define N 5
#define M 3

int available[M];
int max[N][M];
int allocation[N][M];
int need[N][M];
pthread_mutex_t mutex;

// function that will perform request of resources
int request_resources(int cust_id, int request[])
{
    int i;
    // check if the request is within the need
    for (i = 0; i < M; i++)
    {
        if (request[i] > need[cust_id][i])
        {
            return -1;
        }
    }

    // check if the request is within the available
    for (i = 0; i < M; i++)
    {
        if (request[i] > available[i])
        {
            return -1;
        }
    }

    // allocate the resources
    for (i = 0; i < M; i++)
    {
        allocation[cust_id][i] += request[i];
        need[cust_id][i] -= request[i];
        available[i] -= request[i];
    }

    return 0;
}

// function that will perform release of resources
void release_resources(int cust_id, int release[])
{
    int i;
    // release the resources
    for (i = 0; i < M; i++)
    {
        allocation[cust_id][i] -= release[i];
        need[cust_id][i] += release[i];
        available[i] += release[i];
    }
}

// function for creating a requesting thread
void *thread_request(void *arg)
{
    int cust_id = (int)arg;
    int request[M];
    int i, safe;

    while (1)
    {
        // generate a random request vector not exceeding the max requirement for customer i
        for (i = 0; i < M; i++)
        {
            request[i] = rand() % (max[cust_id][i] - allocation[cust_id][i] + 1);
        }

        // try to request the resources
        pthread_mutex_lock(&mutex);
        if (request_resources(cust_id, request) == 0) // successful allocation)
        {
            printf("Customer %d requested resources: [ ", cust_id);
            for (i = 0; i < M; i++)
            {
                printf("%d ", request[i]);
            }
            printf("]\n");

            // check if the system is in a safe state
            safe = is_safe();
            if (safe)
            {
                printf("Customer %d successfully acquired resources\n", cust_id);
            }
            else
            {
                printf("Customer %d is waiting for resources\n", cust_id);
            }
        }
        else
        {
            // System will not be in safe state if given resources!!!
            printf("Customer %d failed to acquire resources\n", cust_id);
        }
        pthread_mutex_unlock(&mutex);

        // sleep for a random amount of time
        sleep(rand() % 5);
    }

    pthread_exit(NULL);
}

// function for creating a releasing thread
void *thread_release(void *arg)
{
    int cust_id = (int)arg;
    int release[M];
    int i;

    while (1)
    {
        // generate a random release vector
        for (i = 0; i < M; i++)
        {
            release[i] = rand() % (allocation[cust_id][i] + 1);
        }

        // release the resources
        pthread_mutex_lock(&mutex);
        release_resources(cust_id, release);
        printf("Customer %d released resources: [ ", cust_id);
        for (i = 0; i < M; i++)
        {
            printf("%d ", release[i]);
        }
        printf("]\n");
        pthread_mutex_unlock(&mutex);

        // sleep for a random amount of time
        sleep(rand() % 5);
    }

    pthread_exit(NULL);
}

// function to check if the system is in safe state every time we allocate resources
int is_safe()
{
    int work[M];
    int finish[N];
    int i, j, k, safe;
    // initialize work and finish vectors
    for (i = 0; i < M; i++)
    {
        work[i] = available[i];
    }
    for (i = 0; i < N; i++)
    {
        finish[i] = 0;
    }

    // check if there exists a process that can finish
    safe = 0;
    for (i = 0; i < N; i++)
    {
        if (finish[i] == 0)
        {
            for (j = 0; j < M; j++)
            {
                if (need[i][j] > work[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                for (k = 0; k < M; k++)
                {
                    work[k] += allocation[i][k];
                }
                finish[i] = 1;
                safe = 1;
            }
        }
    }

    // check if all processes can finish
    while (safe)
    {
        safe = 0;
        for (i = 0; i < N; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < M; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == M)
                {
                    for (k = 0; k < M; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    safe = 1;
                }
            }
        }
    }

    // check if all processes finished
    for (i = 0; i < N; i++)
    {
        if (finish[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    pthread_t threads[N];
    int i, j;

    // initialize available resources
    for (i = 0; i < M; i++)
    {
        printf("Enter the number of available resources for resource %d: ", i);
        scanf("%d", &available[i]);
    }

    // initialize maximum allocation and need matrices
    for (i = 0; i < N; i++)
    {
        printf("Enter the maximum number of resources for Customer %d: (A vector of length = Resources.size())", i);
        for (j = 0; j < M; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j];
        }
    }

    // create threads for resource request and release
    for (i = 0; i < N; i++)
    {
        pthread_create(&threads[i], NULL, thread_request, (void *)i);
    }
    for (i = 0; i < N; i++)
    {
        pthread_create(&threads[i], NULL, thread_release, (void *)i);
    }

    // wait for all threads to finish and join them
    for (i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}