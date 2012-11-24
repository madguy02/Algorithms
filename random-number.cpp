#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<fstream>

using namespace std;

int main(int argc,char *argv[])
{
	if(argc<2)
	{
		cout<<"Wrong Format!\nUsage: ./random-number [limit]"<<endl;
		return 1;
	}
	ofstream fp("sort.txt");
	int limit=atoi(argv[1]);
	fp<<limit<<endl;
	srand(time(0));
	for(int i=0;i<limit;i++)
		fp<<(rand()%limit)+1<<" ";
	fp<<endl;
	fp.close();
	return 0;
}
