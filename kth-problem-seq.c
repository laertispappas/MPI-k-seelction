#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <time.h>


#define SIZE_OF_SAMPLES  100000000

void vecPrint(IntVectorPtr vector){
	int i;
	int size;
	size=VecGetSize(vector);	
	for(i=0;i<size;i++)
		printf("%d%c",VecGet(vector,i),(i==size-1) ? '\n' : ' ');
}

void main()
{
	IntVectorPtr pVec = VecNew(SIZE_OF_SAMPLES);
	int i, elem;
	int solution;
	clock_t start, end;	
	srand((unsigned)time(NULL));
	int k = 250;

  for (i=SIZE_OF_SAMPLES; i > 0; i--) {
	  VecAdd(pVec, i + rand() - rand()%i);
  }

	start = clock();

	VecQuickSort(pVec);
	solution = VecGet(pVec, k -1 );

	end = clock();
	VecDelete(pVec);
	printf("Solution found solution=%d \ntime: %f\n", solution, (end-start)/(double)CLOCKS_PER_SEC);

}

