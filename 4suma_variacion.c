#include <stdio.h>
#include <mpi.h>


int main()
{	
	int comm_sz; 
	int my_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size( MPI_COMM_WORLD, &comm_sz );
	MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );

	/*
	Es este programa simularemos pipelining
	El proceso 0 comienza enviando un valor al siguiente proceso (my_rank+1)%com_sz
	Los demas procesos reciben un mensaje de su proceso anterior my_rank - 1
	Y estos procesos envian el resultado a su sucesor (my_rank+1)%com_sz
	El proceso 0 recibe el resultado final y lo imprime
	Se permite una cantidad grande de procesos

	Este programa hace la suma de 0 hasta comm_sz - 1

	La diferencia de este programa con el anterior es que este declara las variables afuera del 
	scope de la verificacion del numero de rango
	*/
	int mi_variable;
	int resultado;
	if ( my_rank==0 )
	{
		mi_variable = 0;
		MPI_Send ( &mi_variable, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

		int resultadoGlobal;
		MPI_Recv(&resultadoGlobal, 1, MPI_INT, comm_sz - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		printf("El valor total de la suma es %d\n",resultadoGlobal );
	}
	else 
	{
		
		MPI_Recv(&mi_variable, 1, MPI_INT, my_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		resultado = mi_variable + my_rank;
		MPI_Send ( &resultado, 1, MPI_INT, (my_rank+1)%comm_sz, 0, MPI_COMM_WORLD);
	}	

	MPI_Finalize();
	return 0;
}