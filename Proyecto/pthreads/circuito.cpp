#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../circuito.h"
#include <iostream>
#include <bitset>
using namespace std;

pthread_mutex_t lock;

void * verificar(void * hilo)
{
	long my_rank = long(hilo),
		ini = (1<<8) *  my_rank,
		fin = ini + (1<<8);

	for (; ini < fin; ++ini)
	{
		//bitset <16> mibitset(ini);		
		if ( f1(ini) )
		{
			bitset <16> mibitset(ini);			
			pthread_mutex_lock(&lock);
				cout<<mibitset<<"\n";				
			pthread_mutex_unlock(&lock);
		}
		//Los que no son solucion
		/*else
		{
			pthread_mutex_lock(&lock);
				cout<<"..........."<<mibitset<<"\n";
			pthread_mutex_unlock(&lock);
		}*/	
	}
	printf("....%ld....\n", long (hilo));
	return NULL;
}

int main()
{	
	//recibir el numero de hilos a crear
	long num_hilos = 1<<8;

	pthread_t* manejador_de_hilos;
	manejador_de_hilos = (pthread_t * )malloc( num_hilos * sizeof(pthread_t) );
	
	//inicializar mutex
	pthread_mutex_init(&lock, NULL);

	for (long hilo = 0; hilo < num_hilos; ++hilo)
		pthread_create( &manejador_de_hilos[hilo], NULL, verificar, (void *)hilo );

	for (long hilo = 0; hilo < num_hilos; ++hilo)
		pthread_join(manejador_de_hilos[hilo], NULL);

	//destruir mutex
	pthread_mutex_destroy(&lock);
	//liberar memoria
	free(manejador_de_hilos);
	return 0;
}


//$ g++ -std=c++11 -g -Wall -o A circuito.cpp -lpthread
//$ ./A > salida.txt
