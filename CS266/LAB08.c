#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>

#define ARRAY_SIZE 10

int main()
{
    // Create a shared memory segment
    int *array = mmap(NULL, ARRAY_SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int i, j;

    // Initialize the array to all zeros
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = 0;
    }

    // Create a semaphore
    sem_t *mutex = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_init(mutex, 1, 1);

    // Create a writer process
    pid_t writer_pid = fork();
    if (writer_pid == 0)
    {
        // This is the writer process
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            // Wait for 3 seconds
            sleep(3);

            // Lock the semaphore
            sem_wait(mutex);

            // Write the counting to the array
            array[i] = i + 1;

            // Unlock the semaphore
            sem_post(mutex);
        }
        exit(0);
    }

    // Create five reader processes
    for (j = 0; j < 5; j++)
    {
        pid_t reader_pid = fork();
        if (reader_pid == 0)
        {
            // This is a reader process
            while (1)
            {
                // Wait for the semaphore to become available
                sem_wait(mutex);

                // Print all non-zero elements of the array
                printf("Reader process %d: array = ", j + 1);
                for (i = 0; i < ARRAY_SIZE; i++)
                {
                    if (array[i] != 0)
                    {
                        printf("%d ", array[i]);
                    }
                }
                printf("\n");

                // Reset the index to 0
                i = 0;

                // Unlock the semaphore
                sem_post(mutex);

                // Wait for 5 seconds
                sleep(5);
            }
            exit(0);
        }
    }

    // This is the parent process
    printf("Parent process ID: %d\n", getpid());

    // Wait for all child processes to exit
    for (i = 0; i < 6; i++)
    {
        wait(NULL);
    }

    // Cleanup the shared memory and semaphore
    sem_destroy(mutex);
    munmap(mutex, sizeof(sem_t));
    munmap(array, ARRAY_SIZE * sizeof(int));

    return 0;
}