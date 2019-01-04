#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void holamundo()
{
	int my_rank = omp_get_thread_num();
	printf("%d\n", my_rank);
}

int main(int argc, char const *argv[])
{	
	//recibir el numero de hilos a crear
	int num_hilos = strtol(argv[1],NULL,10)	;
	printf("%d\n", num_hilos);

	#pragma omp parallel num_threads(num_hilos)
	holamundo();

	return 0;
}