#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int arr[40];
void quickSort(int izq, int der) 
{
    int i = izq, j = der;
    int tmp;
    int pivote = arr[(izq + der) / 2];

    /* partition */
    while (i <= j) 
    {
        while (arr[i] < pivote)
            i++;
        while (arr[j] > pivote)
            j--;
        if (i <= j) 
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    #pragma omp parallel for num_threads(2)
    for (int w = 0; w < 2; ++w)
    {
        if (izq < j && w)
            quickSort(izq, j);
        if (i < der && !w)
            quickSort(i, der);
    }    
}


int main()
{     
    int n;
    while ( scanf("%d", &n)==1 )
    {
        for (int i = 0; i < n; ++i)
              scanf("%d", &arr[i]);

        quickSort( 0, n-1 );

        for (int i = 0; i < n; ++i)
              printf("%d ", arr[i]);
        printf("\n");
    }
return 0;
}

//$ gcc -g -Wall -fopenmp -o A quicksort.c
//$ ./A