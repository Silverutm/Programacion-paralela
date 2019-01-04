#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAX_STRING 100


int main()
{
  
    int comm_sz; 
    int my_rank;
    int arreglo_enteros[MAX_STRING];
    for (int i = 0; i < MAX_STRING; ++i)
        arreglo_enteros[i] = i;


    MPI_Init(NULL, NULL);
    MPI_Comm_size( MPI_COMM_WORLD, &comm_sz );
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
    // Sum the numbers locally
    int local_sum = 0;
    int i;
    for (i = 0; i < 100/comm_sz; i++) {
    local_sum += arreglo_enteros[i+100/comm_sz*my_rank ];
    }

    // Print the random numbers on each process
    printf("Local sum for process %d: %d\n", my_rank, local_sum);

    // Reduce all of the local sums into the global sum
    int global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result
    if (my_rank == 0) {
    printf("Total sum = %d\n", global_sum);
    }

    MPI_Finalize();
}