#include <iostream>
#include <vector>
#include "time-it.cpp"
#define CUTOFF 7

using namespace std;

template <class T>
void selection_sort(T array[],int low, int high)
{
    int i,j,min;
    T temp;
    int len=(high-low+1);
    for(i=low;i<high;i++)
    {
        min=i;
        for(j=i;j<=high;j++)
        {
            if(array[min]>array[j])
            min=j;              //holding the index of the smallest element
        }
        temp=array[i];          //swapping of the elements
        array[i]=array[min];
        array[min]=temp;
    }
}

template<class T>
void split(T array[],int low,int high)
{
    if((high-low+1)<=CUTOFF)
    {
        selection_sort(array,low,high);
    }
    else if(low<high)
    {
        int mid=(low+high)/2;
        split(array ,low ,mid);
        split(array, mid+1,high);
        merge(array, low, mid, high);
    }
    return;
}

template <class T>
void merge(T array[],int low, int mid, int high )
{
    int l=low;
    int m=mid+1;
    int k=0;
    T sec[high-low+1];
    if(!(array[mid]<array[mid+1]))
    {
        while(l<=mid && m<=high)
        {
            if(array[l]<=array[m])
                sec[k++] = array[l++];
            else
                sec[k++] = array[m++];
        }

    }
    while(l<=mid)
    sec[k++]=array[l++];

    while(m<=high)
    sec[k++]=array[m++];


    for(int i=0;i<k;i++)
    {
        array[low+i]=sec[i];
    }

}

int main(int argc, char *argv[])
{
    int size;
    try
    {
        double exetime=0;
        cin>>size;
        int vec[size]; //Change vector parameter as required
        int i;
        for(i=0;i<size;i++)
        {
            cin>>vec[i];
        }
        exetime=time_it<int>(split,vec,0,size-1);
        cout<<"The sorted array is: ";
        for(i=0;i<size;i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
        cout << "sorted under " << exetime<< " seconds." << endl;
    }
    catch(...)
    {
        cout<<"An error has occurred , check the input"<<endl;
        return 1;
    }

    return 0;
}
