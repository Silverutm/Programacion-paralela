#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

long long tam;
char es_primo[10000010];
int primos[1000000];
int num_hilos;
pthread_t* manejador_de_hilos;
long c;
long long i;
int n=0;

long long min(long long a, long long b)
{
	if (a<b) return a;
	return b;
}

long long max(long long a, long long b)
{
	if (a>b) return a;
	return b;
}

void tachar(int mi_hilo)
{		
	long long ini = i*i + (mi_hilo )*c*i;
	long long fin = min(tam,ini + c*i);
	
	for ( ;ini < fin; ini += i) 
		es_primo[ini] = 0;
	return ;
}

void criba()
{
	tam = 10000001;	
	for (int i = 0; i < tam; ++i)
		es_primo[i] = 1;
	es_primo[0] = es_primo[1] = 0;
	
	for (i = 2; i < tam; i++) 
		if (es_primo[i]) 
		{		
			primos[n++]=(int)i;
			if (i*i>tam) continue;

			c = max((tam - i*i)/i + 1, 1LL);
			c /= num_hilos;
			++c;

			int comm_sz; //numero de procesos
			int my_rank; // nombre de procesos
			MPI_Init(NULL,NULL);
			MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
			MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
			tachar(my_rank);
			MPI_Finalize();
					
		}
	return;
}

int main(int argc, char const *argv[])
{		
	
	criba();
	

	for (int i = 0; i < n; ++i)
		printf("%d\n", primos[i] );
	
	return 0;
}
//$ mpicc -std=c99 -o A criba.c
//$ mpiexec -n 256 ./A
y2nV5Pw46q