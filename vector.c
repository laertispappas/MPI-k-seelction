#include <stdlib.h>
#include <stdio.h>
#include "vector.h"


static int compare(const void *num1,const void *num2){
	return *((int *)num1)-*((int *)num2);
}

static void swap(int *x,int *y){
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
}

//i sinartisi afti 8a boruse na periexi eksisu enan algori8mo gia ti kaliteri 8esi tu aksona...
static int choose_pivot(int i,int j){	
	return ((i+j)/2);
}

static void quicksort(IntVectorPtr vector,int startPos,int endPos){	
	int i,j;	//diktes gia prospelasi
	int k,key;	//o trexon aksonas

	if ((vector!=NULL) && (vector->data!=NULL) && (vector->size>1) && (startPos<endPos))
	{
	
		k = choose_pivot(startPos,endPos);
		swap(&vector->data[startPos],&vector->data[k]);
		key = vector->data[startPos];
		i = startPos+1;
		j = endPos;
		
		while(i<=j)
		{
			while((i<=endPos) && (vector->data[i]<=key))
					i++;
			while((j>=startPos) && (vector->data[j]>key))
					j--;
			
				if(i<j)
					swap(&vector->data[i],&vector->data[j]);
		}
		swap(&vector->data[startPos],&vector->data[j]);
		quicksort(vector,startPos,j-1);
		quicksort(vector,j+1,endPos);
	}
}


IntVectorPtr VecNew(int initialCapacity)
{
    IntVectorPtr pVec = (IntVectorPtr) malloc(sizeof(IntVector));
    if (pVec ==NULL)
        	return NULL;

    pVec->data = (int *) malloc(initialCapacity*sizeof(int));
    if (pVec->data == NULL)
    {
			free(pVec);
      return NULL;
    }

    pVec->size = 0;
    pVec->capacity = initialCapacity;

    return pVec;
}


int VecAdd (IntVectorPtr pVec, int element )
{

	if((pVec==NULL) || (pVec->data==NULL))
		return -1; 	

    if (pVec->size >= pVec->capacity)
    {
        int *newData = (int*) realloc(pVec->data,pVec->capacity*2*sizeof(int));

        if (newData==NULL)
            return -1;
        pVec->data = newData;
        pVec->capacity *= 2;
    }

    pVec->data[pVec->size] = element;
    return pVec->size++;
}




void VecDelete(IntVectorPtr vector){

	if ((vector!=NULL))
	{

		if(vector->data!=NULL)
			free(vector->data);
		free(vector);
	}	
}


int VecErase(IntVectorPtr vector,int position){
	if((vector==NULL) || (vector->data==NULL) || (vector->size==0))
		return -1;
	if((position<0) || (position>=vector->size))
		return -1;

	if(position == vector->size-1)
		vector->size--;
	else
	{
		vector->data[position]=vector->data[--vector->size];
	}
	return position;
}

int MinFind(IntVectorPtr vector){

	if((vector==NULL) || (vector->data==NULL))
		return -1;


	int min=vector->data[0];
	int i;
		
	for(i=1;i<vector->size;i++)
	{
		if(vector->data[i]<min)
		{
			min=vector->data[i];
		}
	}

		return min;

}

int MaxFind(IntVectorPtr vector){

	int max=vector->data[0];
	int i;
	
	
	for(i=1;i<vector->size;i++)
	{
		if(vector->data[i]>max)
		{
			max=vector->data[i];
		}
	}

		return max;
}


double AverageFind(IntVectorPtr vector){
	double average=0;
	int i;
	for(i=0;i<vector->size;++i)
	{
		average+=vector->data[i];

	}
		return average;
}



int VecGetCapacity(IntVectorPtr v){
	if((v==NULL) || (v->data==NULL))
		return -1;	
	return v->capacity;
}


int VecGetSize(IntVectorPtr v){
	if((v==NULL) || (v->data==NULL))
		return -1;	
	return v->size;
}

int VecIsFull(IntVectorPtr v){
	if((v==NULL) || (v->data==NULL))
		return TRUE;
	return v->size==v->capacity ? TRUE:FALSE;
}

int VecSet(IntVectorPtr vector,int position,int element){
	int newCapacity;
	int *newData;

	if (vector==NULL || vector->data==NULL)
		return -1;
	
	if((position >= vector->size) || (position < 0))
		return -2;
	
	vector->data[position]=element;
	return element;
}


int VecGet(IntVectorPtr vector,int position){
	
	if (vector==NULL || vector->data==NULL)
		return -1;

	if((position>=vector->size) || (position < 0))
		return -2;	
	return vector->data[position];

}

int VecSearch(IntVectorPtr vector,int startPos,int element){
		int i;	
		if (vector==NULL || vector->data==NULL)
			return -1;

		if(startPos >= vector->size)
			return -1;

		if(startPos<0)
			startPos=0;

		for(i=startPos;i<vector->size;i++)
			if(vector->data[i] == element)
				return i;
		return -1;
}


//qsort usage
void VecQuickSort(IntVectorPtr vector){
	qsort(vector->data,vector->size,sizeof(int),compare);		
}

//ilopihsh tis quick sort
void VecQuickSort2(IntVectorPtr vector){		
	quicksort(vector,0,vector->size-1);
}

//bsearch usage
int VecBinarySearch(IntVectorPtr vector,int element){
	
	int *p;
	p=(int *)bsearch(&element,vector->data,vector->size,sizeof(int),compare);
	if(p==NULL)
		return -1;
	else 
		return p-vector->data; 	

}

//ilopoihsh ths binary search
int VecBinarySearch2(IntVectorPtr vector,int element){

int beg,end;
int mid;	
int position;

	beg=0;
	end=vector->size-1;
	mid=(beg+end)/2;

	
	if(vector==NULL || vector->data==NULL)
		return -1;	
	

	while(beg<=end && vector->data[mid]!=element)
	{
		if(element<vector->data[mid])
 			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}	
	if(vector->data[mid]==element)
		return mid;
	return VecSearch(vector,0,element);	
}
