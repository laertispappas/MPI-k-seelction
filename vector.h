#ifndef _VECTOR_H
#define _VECTOR_H

#define TRUE 1
#define FALSE 0

typedef struct {
    int size;     /* αριθμός στοιχείων */
    int capacity; /* χωρητικότητα      */
    int *data;    /* δεδομένα          */
}IntVector,*IntVectorPtr;

IntVectorPtr VecNew(int initialCapacity);

int VecAdd (IntVectorPtr vector, int element);//pros8eti ena stixio sto telos tu dianismatos

void VecDelete(IntVectorPtr vector);//diagrafi olokliru tu dianismatos
int VecErase(IntVectorPtr vector,int position);//diagrafi sigekrimenu stixiu tu pinaka
int MinFind(IntVectorPtr vector);//evresi elaxistu
int MaxFind(IntVectorPtr vector);//evresi megaliteru
double AverageFind(IntVectorPtr vector);//evresi mesu oru
int VecGetCapacity(IntVectorPtr vector);//epistrefi tin xoritikotita
int VecGetSize(IntVectorPtr vector);//epistrefi to trexon mege8os tu dianisma
int VecIsFull(IntVectorPtr vector);//epistrefi true an ine gematos o pinakas allios false
int VecSet(IntVectorPtr vector,int position,int element);//allazi ena sigekrimeno stixio sto dianisma
int VecGet(IntVectorPtr vector,int position);//perni ena stixio apo to dianisma
int VecSearch(IntVectorPtr vector,int startPos,int element);//;anazitisi gia kapio stixio sto pinaka

void VecQuickSort(IntVectorPtr vector);
void VecQuickSort2(IntVectorPtr vector);

int VecBinarySearch(IntVectorPtr vector,int element);
int VecBinarySearch2(IntVectorPtr vector,int element);
#endif /* _VECTOR_H */
