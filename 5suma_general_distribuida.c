#include <stdio.h>
#include <mpi.h>
#define MAESTRO 0

const int MAX_STRING = 100;

/*
Se desea hacer la suma de n elementos
se divide la suma en partes iguales
cada proceso suma un pedazo del arreglo
y despues regresan su resultado
*/

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

	int tareas = MAX_STRING%comm_sz;
	int tamanho_de_pedazos = MAX_STRING / comm_sz;
	int recorrido = tamanho_de_pedazos;

	if (tareas)
	{
		if (my_rank == MAESTRO)
			printf("Saliendo del sistema, no sale mai, no es divisible\n");
		return 0;		
	}


	if ( my_rank==MAESTRO )
	{		
		int suma=0;
		for (int i = 0; i < tamanho_de_pedazos; ++i)
			suma += arreglo_enteros[i];

		printf("suma del proceso maestro %d\n", suma);
		for (int q = 1; q < comm_sz; ++q)
		{
			MPI_Send ( &recorrido, 1, MPI_INT, q, 0, MPI_COMM_WORLD);
			MPI_Send ( &arreglo_enteros[recorrido], tamanho_de_pedazos, MPI_INT, q, 0, 
					MPI_COMM_WORLD);
			recorrido += tamanho_de_pedazos;
		}

		int resutados_de_las_tareas = 0;		
		for (int q = 1; q < comm_sz; ++q)
		{
			MPI_Recv(&resutados_de_las_tareas, 1, MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);	
			suma += resutados_de_las_tareas;
		}			

		printf("suma total %d\n",suma );
	}
	else
	{
		int suma = 0;
		MPI_Recv ( &recorrido, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv ( &arreglo_enteros[recorrido], tamanho_de_pedazos, MPI_INT, 0, 0, 
				MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		
		for (int i = 0; i < tamanho_de_pedazos; ++i)
			suma += arreglo_enteros[recorrido+i];

		printf("suma parcal del proceso %d es %d\n",my_rank, suma );
		MPI_Send ( &suma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}