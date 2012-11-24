#include<iostream>
#include<vector>

using namespace std;

template<class T>
double time_it(void (*action)(vector<T>&), vector<T> &arg) {
  clock_t start_time = clock();
  action(arg);
  clock_t finis_time = clock();
  return ((double) (finis_time - start_time)) / CLOCKS_PER_SEC;
}

template <class T>
double time_it(void (*action)(vector<T>&,int , int), vector<T> &arg, int low,int high) {
  clock_t start_time = clock();
  action(arg,low,high);
  clock_t finis_time = clock();
  return ((double) (finis_time - start_time)) / CLOCKS_PER_SEC;
}

template <class T>
double time_it(void (*action)(T [],int , int), T arg[], int low,int high) {
  clock_t start_time = clock();
  action(arg,low,high);
  clock_t finis_time = clock();
  return ((double) (finis_time - start_time)) / CLOCKS_PER_SEC;
}

template <class T>
double time_it(T (*action)(T[],int,int), T arg[], int k, int high)
{
    clock_t start_time= clock();
    T ele = action(arg,k,high);
    clock_t finish_time = clock();
    cout<<ele<<endl;
    return ((double)(finish_time - start_time)) / CLOCKS_PER_SEC;
}
