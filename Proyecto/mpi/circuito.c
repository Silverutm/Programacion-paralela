#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define and &&
#define or ||
#define bool int
#define not !

#include "../circuito.h"
//#include <iostream>
//#include <bitset>
//using namespace std;

void verificar(int my_rank)
{
	char cosa[20];
	int copia;
	cosa[16] = '\n';cosa[17]=0;
	int	ini = (1<<8) *  my_rank,
		fin = ini + (1<<8);

	for (; ini < fin; ++ini)
	{
		//bitset <16> mibitset(ini);			
		if ( f1(copia) )
		{
			copia = ini;
			for (int i = 15; i >= 0; --i)
			{
				cosa[i] = (copia&1) + '0';
				copia >>= 1;
			}
			printf("%s",cosa );
			//bitset <16> mibitset(ini);
			//#pragma omp critical
			//cout<<mibitset.to_string()+"\n";
		}
		//Los que no son solucion
		/*else
		{
			#pragma omp critical
			cout<<"..........."<<mibitset<<"\n";
		}*/	
	}

}

int main()
{	
	//recibir el numero de hilos a crear
	//int num_hilos = 1<<8;

	int comm_sz; //numero de procesos
	int my_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size( MPI_COMM_WORLD, &comm_sz );
	MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
	
	//verificar(my_rank);	
	{
		char cosa[20];
		int copia;
		cosa[16] = '\n';cosa[17]=0;
		int	ini = (1<<8) *  my_rank,
			fin = ini + (1<<8);

		for (; ini < fin; ++ini)
		{
			//bitset <16> mibitset(ini);			
			if ( f1(copia) )
			{
				copia = ini;
				for (int i = 15; i >= 0; --i)
				{
					cosa[i] = (copia&1) + '0';
					copia >>= 1;
				}
				printf("%s",cosa );
				//bitset <16> mibitset(ini);
				//#pragma omp critical
				//cout<<mibitset.to_string()+"\n";
			}
			//Los que no son solucion
			/*else
			{
				#pragma omp critical
				cout<<"..........."<<mibitset<<"\n";
			}*/	
		}
	}

	MPI_Finalize();
	return 0;
}


//$ mpicc -std=c99 -o A circuito.c
//$ mpiexec -n 256 ./A
