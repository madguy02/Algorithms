#include <ctime>
#include <cstdlib>

template <class T>
void shuffle(T array[], int size)
{
    int j;
    T temp;
    srand(time(0));
    for(int i=1;i<size;i++)
    {
        j=rand()%(i+1);
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
}
