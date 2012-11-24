#include <iostream>
#include <vector>
#include "time-it.cpp"

using namespace std;

static int step=1;
template<class T>
void split(vector<T> &array,int low,int high)
{

    if(low<high)
    {
        int mid=(low+high)/2;
        split(array ,low ,mid);
        split(array, mid+1,high);
        merge(array, low, mid, high);
    }
    return;
}

template <class T>
void merge(vector<T> &array,int low, int mid, int high )
{
    int l=low;
    int m=mid+1;
    int k=0;
    vector<T> sec(array.size());
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
        vector<int> vec(size); //Change vector parameter as required
        int i;
        for(i=0;i<size;i++)
        {
            cin>>vec[i];
        }
        exetime=time_it(split,vec,0,size-1);
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
