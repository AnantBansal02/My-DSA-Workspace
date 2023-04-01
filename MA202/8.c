#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10

void input_matrix(float matrix[][MAX_SIZE], int size);
void print_matrix(float matrix[][MAX_SIZE], int size);
void find_eigenvectors(float matrix[][MAX_SIZE], float eigenvalues[], float eigenvectors[][MAX_SIZE], int size);
void normalize_vector(float vector[], int size);
float dot_product(float vector1[], float vector2[], int size);
void check_orthogonality(float eigenvectors[][MAX_SIZE], int size);

int main()
{
    float matrix[MAX_SIZE][MAX_SIZE];
    float eigenvalues[MAX_SIZE];
    float eigenvectors[MAX_SIZE][MAX_SIZE];
    int size;

    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    input_matrix(matrix, size);

    printf("The input matrix is:\n");
    print_matrix(matrix, size);

    find_eigenvectors(matrix, eigenvalues, eigenvectors, size);

    printf("\nEigenvalues:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", eigenvalues[i]);
    }

    printf("\n\nEigenvectors:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.2f ", eigenvectors[i][j]);
        }
        printf("\n");
    }

    check_orthogonality(eigenvectors, size);

    return 0;
}

void input_matrix(float matrix[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void print_matrix(float matrix[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void find_eigenvectors(float matrix[][MAX_SIZE], float eigenvalues[], float eigenvectors[][MAX_SIZE], int size)
{
    float identity[MAX_SIZE][MAX_SIZE];
    float temp[MAX_SIZE][MAX_SIZE];
    float eigenvalue;
    float eigenvector[MAX_SIZE];
    float magnitude;
    float tolerance = 0.0001;
    int iterations = 0;
    int max_iterations = 50;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                identity[i][j] = 1.0;
            }
            else
            {
                identity[i][j] = 0.0;
            }
            eigenvectors[i][j] = identity[i][j];
            temp[i][j] = matrix[i][j];
        }
    }

    do
    {
        eigenvalue = 0.0;

        // Multiply matrix by eigenvector
        for (int i = 0; i < size; i++)
        {
            eigenvector[i] = 0.0;
            for (int j = 0; j < size; j++)
            {
                eigenvector[i] += temp[i][j] * eigenvectors[j][i];
            }
        }
        // Find eigenvalue
        magnitude = sqrt(dot_product(eigenvector, eigenvector, size));
        normalize_vector(eigenvector, size);

        for (int i = 0; i < size; i++)
        {
            eigenvalue += eigenvector[i] * matrix[i][i] * eigenvector[i];
        }

        eigenvalues[iterations] = eigenvalue;

        // Gram-Schmidt orthogonalization of eigenvectors
        for (int i = 0; i < iterations; i++)
        {
            float dot_prod = dot_product(eigenvector, eigenvectors[i], size);
            for (int j = 0; j < size; j++)
            {
                eigenvector[j] -= dot_prod * eigenvectors[i][j];
            }
        }

        normalize_vector(eigenvector, size);

        // Update eigenvectors matrix
        for (int i = 0; i < size; i++)
        {
            eigenvectors[iterations][i] = eigenvector[i];
        }

        // Update temp matrix
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                temp[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                temp[i][j] -= eigenvalue * identity[i][j];
            }
        }

        iterations++;
    } while (iterations < size && iterations < max_iterations && magnitude > tolerance);
}

void normalize_vector(float vector[], int size)
{
    float magnitude = sqrt(dot_product(vector, vector, size));
    for (int i = 0; i < size; i++)
    {
        vector[i] /= magnitude;
    }
}

float dot_product(float vector1[], float vector2[], int size)
{
    float result = 0.0;
    for (int i = 0; i < size; i++)
    {
        result += vector1[i] * vector2[i];
    }
    return result;
}

void check_orthogonality(float eigenvectors[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            float dot_prod = dot_product(eigenvectors[i], eigenvectors[j], size);
            printf("\nDot product of eigenvectors %d and %d: %.2f", i + 1, j + 1, dot_prod);
            if (fabs(dot_prod) > 0.0001)
            {
                printf(" (not orthogonal)\n");
            }
            else
            {
                printf(" (orthogonal)\n");
            }
        }
    }
}