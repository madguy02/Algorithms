#include<iostream>
#include<vector>
#include<cstdlib>
#include "time-it.cpp"

using namespace std;

int size;

template<typename T>
void insertion_sort(vector<T> &array)
{
    int i,j;
    T temp;
    for(i=0;i<size;i++)
    {
        for(j=i;j>0;j--)
        {
            if(array[j]<array[j-1])
            {
                temp=array[j-1];          //swapping of the elements
                array[j-1]=array[j];
                array[j]=temp;
            }
            else break;
        }
    }
}
int main(int argc, char *argv[])
{
    try
    {
        double exetime;
        cin>>size;
        vector<int> vec(size); //Change vector parameter as required
        int i;
        for(i=0;i<size;i++)
        {
            cin>>vec[i];
        }
        exetime=time_it(insertion_sort,vec);
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
