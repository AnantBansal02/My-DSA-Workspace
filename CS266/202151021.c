#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

int A[N][N];
int B[N][N];
int mul[N][N];
int add[N][N];
int sub[N][N];
int tr_A = 0;
int tr_B = 0;
int result = 1;

struct v
{
    int i; /* row */
    int j; /* column */
};

void *addition(void *anant)
{
    struct v *data = anant;  
    add[data->i][data->j] = A[data->i][data->j] + B[data->i][data->j];
    pthread_exit(0);
}
void *subtraction(void *anant)
{
    struct v *data = anant;
    sub[data->i][data->j] = A[data->i][data->j] - B[data->i][data->j];
    pthread_exit(0);
}
void *multiply(void *anant)
{
    struct v *data = anant; // the structure that holds our data
    int i, sum = 0;         // the counter and sum

    // Row multiplied by column
    for (i = 0; i < N; i++)
    {
        sum += A[data->i][i] * B[i][data->j];
    }
    // assign the sum to its coordinate
    mul[data->i][data->j] = sum;

    // Exit the thread
    pthread_exit(0);
}
void *trace(void *anant)
{
    struct v *data = anant;
    tr_A += A[data->i][data->j];
    tr_B += B[data->i][data->j];
    pthread_exit(0);
}
void *check(void *anant)
{
    if(result == 0){
        pthread_exit(0);
    }
    struct v *data = anant;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < N; i++)
    {
        sum1 += A[data->i][i] * B[i][data->j];
        sum2 += B[data->i][i] * A[i][data->j];
    }
    if(sum1!=sum2){
        result = 0;
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{

    int i, j, count = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = rand() % 23;
            B[i][j] = rand() % 23;
        }
    }
    printf("Matrix A : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix B : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            // Assign a row and column for each thread
            struct v *data = (struct v *)malloc(sizeof(struct v));
            data->i = i;
            data->j = j;
            /* Now create the thread passing it data as a parameter */
            pthread_t tid;       // Thread ID
            pthread_attr_t attr; // Set of thread attributes
            // Get the default attributes
            pthread_attr_init(&attr);
            // Create the thread
            pthread_create(&tid, &attr, multiply, data);
            // Make sure the parent waits for all thread to complete
            pthread_join(tid, NULL);
            // Same for other thread for other operations!!

            //Addition
            pthread_t tid_2;       
            pthread_attr_t attr_2; 
            pthread_attr_init(&attr_2);
            pthread_create(&tid_2, &attr_2, addition, data);
            pthread_join(tid_2, NULL);

            //Subtraction
            pthread_t tid_3;       
            pthread_attr_t attr_3; 
            pthread_attr_init(&attr_3);
            pthread_create(&tid_3, &attr_3, subtraction, data);
            pthread_join(tid_3, NULL);

            //trace
            if(i==j){
                pthread_t tid_4;       
                pthread_attr_t attr_4; 
                pthread_attr_init(&attr_4);
                pthread_create(&tid_4, &attr_4, trace, data);
                pthread_join(tid_4, NULL);
            }
            //check
            pthread_t tid_5;       
            pthread_attr_t attr_5; 
            pthread_attr_init(&attr_5);
            pthread_create(&tid_5, &attr_5, check, data);
            pthread_join(tid_5, NULL);
            count++;
        }
    }

    // Print out the resulting matrix
    printf("Multiplication of A and B : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Print out the resulting matrix
    printf("Addition of A and B : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Print out the resulting matrix
    printf("Subtraction of A and B : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Trace of Matrix A : %d\n",tr_A);
    printf("Trace of Matrix B : %d\n",tr_B);
    printf("\n");
    if(result==1){
        printf("AB is equal to BA \n");
    }
    else{
        printf("AB is not equal to BA \n");
    }
    printf("\n");
}