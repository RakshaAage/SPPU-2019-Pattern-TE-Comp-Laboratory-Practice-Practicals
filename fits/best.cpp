#include<iostream>
using namespace std;

void bestFit(int blocksize[],int m, int procsize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        int bestind=-1;
        for(int j=0;j<m;j++)
        {
            if(blocksize[j]>=procsize[i])
            {
                if(bestind==-1)
                {
                    bestind=j;
                }
                else if(blocksize[bestind]>blocksize[j])
                {
                    bestind=j;
                }
            }
        }
        if(bestind!=-1)
        {
            allocation[i]=bestind;
            blocksize[bestind]-=procsize[i];
        }
    }

    cout<<"Process No \tProcess Size\t Block No \tFragment size\n";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<procsize[i]<<"\t\t";
        if(allocation[i]!=-1)
        {
            cout<<allocation[i]+1;
            int fragment = blocksize[allocation[i]];
            cout<<"\t\t"<<fragment;
        }
        else
        {
            cout<<"Not allocated";
        }
        cout<<endl;
    }
}

int main()
{
    int n,m;
    int blockSize[10],processSize[10];
    cout<<"Enter the number of Blocks: ";
    cin>>m;
    cout<<"Enter the Block sizes: \n";
    for(int i=0;i<m;i++)
    {
        cout<<"For block "<<i+1<<" : ";
        cin>>blockSize[i];
    }
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<"Enter the process sizes: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"For process "<<i+1<<" : ";
        cin>>processSize[i];
    }

    bestFit(blockSize,m,processSize,n);

    return 0;
}