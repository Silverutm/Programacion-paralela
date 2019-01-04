#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "../circuito.h"
#include <iostream>
#include <bitset>
using namespace std;

void verificar()
{
	int my_rank = omp_get_thread_num(),
		ini = (1<<8) *  my_rank,
		fin = ini + (1<<8);

	for (; ini < fin; ++ini)
	{
		//bitset <16> mibitset(ini);		
		if ( f1(ini) )
		{
			bitset <16> mibitset(ini);
			#pragma omp critical
			cout<<mibitset<<"\n";
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
	int num_hilos = 1<<8;

	#pragma omp parallel num_threads(num_hilos)
	verificar();	
	return 0;
}


//$ g++ -std=c++11 -g -Wall -fopenmp -o A circuito.cpp
//$ ./A > salida.txt
