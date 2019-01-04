#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t lock;

int iteraciones;
double pi = 0.0;

void * sacar_pi(void * hilo)
{
	double suma = 0.0, factor;
	long mi_hilo = (long)hilo;
	int k= 1 + mi_hilo*iteraciones;
	for (int z = 1; z <= iteraciones; ++z)
	{
		if (k&1) factor = 1.0;
		else factor = -1.0;
		suma += factor/(2*k-1);
		++k;
	}
	pthread_mutex_lock(&lock);
		pi += suma;	//seccion critica
	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(int argc, char const *argv[])
{	
	//recibir el numero de hilos a crear
	int num_hilos = strtol(argv[1],NULL,10)	;

	pthread_t* manejador_de_hilos;
	manejador_de_hilos = (pthread_t * )malloc( num_hilos * sizeof(pthread_t) );
	//inicializar mutex
	pthread_mutex_init(&lock, NULL);
	
	int n=10000000;
	iteraciones = n/num_hilos;

	for (long hilo = 0; hilo < num_hilos; ++hilo)
		pthread_create( &manejador_de_hilos[hilo], NULL, sacar_pi, (void *)hilo );

	for (long hilo = 0; hilo < num_hilos; ++hilo)
		pthread_join(manejador_de_hilos[hilo], NULL);
	
	pi *=4;

	printf("El valor de PI es %lf\n",pi );

	//destruir mutex
	pthread_mutex_destroy(&lock);
	//liberar memoria
	free(manejador_de_hilos);
	return 0;
}

//$ gcc -g -Wall -o A PI.c -lpthread
//$ ./A 500