#include<iostream>
#include"knuth-shuffle.cpp"

template <class T>
int partition(T array[], int low, int high)
{
    int i,j=high+1;
    i=low;
    T temp;
    while(i<j)
    {
        while(array[low]>=array[++i])
        if(i==high)
        break;

        while(array[low]<array[--j])
        if(j==low)
        break;

        if(i<j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }

    }
    temp=array[low];
    array[low]=array[j];
    array[j]=temp;
    return j;
}

template <class T>
T selection(T array[],int k,int high)
{
    int low=0;

    //To avoid the worst case scenario
    shuffle(array,high+1);

    while(true)
    {
        int j=partition(array,low,high);

        //Using binary search technique
        if(j<k) low=j+1;
        else if(j>k) high=j-1;
        else return array[k];
    }

}

int main(int argc, char *argv[])
{
    int size,k;
    try
    {
        cin>>size;
        int array[size]; //Change vector parameter as required
        int i;
        for(i=0;i<size;i++)
        {
            cin>>array[i];
        }
        cin>>k;
        cout<<"The "<<k<<" largest element is: "<<selection<int>(array,k-1,size-1);
        cout<<endl;
    }
    catch(...)
    {
        cout<<"An error has occurred , check the input"<<endl;
        return 1;
    }
    return 0;
}
