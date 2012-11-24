#include <iostream>
#include "time-it.cpp"
#include "knuth-shuffle.cpp"

using namespace std;

template <class T>
void partition(T array[],int low, int high)
{

    if(high<=low)
    return;

    T temp;
    int i=low, j=high+1;

    while(i<j)
    {
        while(array[low]>=array[++i])
        {
            if(i==high)
            break;
        }
        while(array[low]<array[--j])
        {
            if(j==low)
            break;
        }

        if(i>=j)
        break;

        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }

    temp = array[j];
    array[j] = array[low];
    array[low] = temp;
    partition(array,low,j-1);
    partition(array,j+1,high);
}

int main(int argc, char *argv[])
{
    int size;
    try
    {
        double exetime=0;
        cin>>size;
        //Change array datatype as required
        int array[size];
        int i;
        for(i=0;i<size;i++)
        {
            cin>>array[i];
        }

        //To avoid the worst case
        shuffle(array,size);

        //change template parameter as required
        exetime=time_it<int>(partition,array,0,size-1);
        cout<<"The sorted array is: ";
        for(i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
        cout << "Sorted under " << exetime<< " seconds." << endl;
    }
    catch(...)
    {
        cout<<"An error has occurred , check the input"<<endl;
        return 1;
    }

    return 0;
}
