#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;


class union_find
{
    private:
    int *array,*siz;
    int N;
    public:
    union_find(int x)
    {
        N=x;
        array=new int[N];
        siz=new int[N];
        fill_n(siz,N,1); // size of each tree is 1
        for(int i=0;i<N;i++)
            array[i]=i; //Each node is its root
    }

    ~union_find()
    {
        delete []array;
    }

    int root(int x)
    {
        while(x!=array[x])
        {
            array[x]=array[array[x]]; //linking the nodes directly to their grandparents so that the tree flattens
            x=array[x]; //Traversing up the tree structure
        }
        return x;
    }

    void unionof(int p, int q)
    {
        int pid=root(p);
        int qid=root(q);
        if(siz[pid]<siz[qid])
        {
            siz[qid]+=siz[pid]; //updating the size of the tree
            array[pid]=qid; //Change the root of p to root of q
        }
        else
        {
            siz[pid]+=siz[qid];
            array[qid]=pid; //Change the root of q to root of p
        }
    }
    bool connected(int p,int q)
    {
        return (root(p)==root(q)); // the elements are connected only if the roots are the same
    }
};

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        cout<<"Incorrect use \nFormat:./union-find-lazy-approch [FILENAME]"<<endl;
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
