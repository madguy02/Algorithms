#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

class union_find
{
    private:
    int *array;
    int N;
    public:
    union_find(int x)
    {
        N=x;
        array=new int[N];
        for(int i=0;i<N;i++)
        array[i]=i;
        cout<<"The array has been created!"<<endl;
    }

    ~union_find()
    {
        delete []array;
    }

    void unionof(int p, int q)
    {
        int pid=array[p];
        int qid=array[q];
        if(!connected(p,q))
        {
            for(int i=0;i<N;i++)
            {
            if(array[i]==pid)
            array[i]=qid;
            }
        }
    }
    bool connected(int p,int q)
    {
        return (array[p]==array[q]);
    }
};

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        cout<<"Incorrect use \nFormat:./union-find-eager-approch [FILENAME]"<<endl;
        exit(0);
    }
    int size,c;
    try
    {
        ifstream fp(argv[1]);
        int p,q,iter;
        fp>>size;
        union_find uf(size);
        fp>>iter;
        for(int i=1;i<=iter;i++)
        {
            fp>>p>>q;
            uf.unionof(p,q);
        }
        while(1)
        {
            cout<<"1.Connect 2.Exit: ";
            cin>>c;
            switch(c)
            {
                case 1:
                cout<<"Enter the value of p and q: ";
                cin>>p>>q;
                cout<<p<<" and "<<q<<" are ";
                if(!uf.connected(p,q))
                cout<<"not ";
                cout<<"connected"<<endl;
                break;

                case 2:
                exit(0);

                default:
                cout<<"Enter again!"<<endl;
            }
        }
        fp.close();
    }
    catch(...)
    {
        cout<<"NO FILE OR ACCESS RIGHTS!"<<endl;
        exit(0);
    }
}
