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

