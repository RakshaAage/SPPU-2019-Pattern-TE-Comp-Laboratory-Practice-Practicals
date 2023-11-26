#include<iostream>
using namespace std;

void nextFit(int blocksize[],int m, int procsize[],int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    int lastAllocatedBlock = 0;
    for(int i=0;i<n;i++)
    {
        int startind = lastAllocatedBlock ;
        int currentind = startind;
        bool blockAllocated = false;
        do
        {
            if(blocksize[currentind]>=procsize[i])
            {
                allocation[i]=currentind;
                int fragment = blocksize[currentind]-procsize[i];
                blocksize[currentind]=fragment;
                lastAllocatedBlock=currentind;
                blockAllocated=true;
                break;
            }
            currentind=(currentind+1)%m;
        } while (currentind!=startind);

        if(!blockAllocated)
        {
            for(int j=0;j<m;j++)
            {
                if(blocksize[j]>=procsize[i])
                {
                    allocation[i]=j;
                    int fragment = blocksize[j]-procsize[i];
                    blocksize[j]=fragment;
                    lastAllocatedBlock= j ;
                    break;
                }
            }
        }            
    }

    cout<<"Process no\tProcess size\tBlock no\tFragment\n";
    int procNotAllocated=0;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<procsize[i]<<"\t\t";
        if(allocation[i]!=-1)
        {
            cout<<allocation[i]+1;
            int fragmentSize= blocksize[allocation[i]];
            cout<<"\t\t"<<fragmentSize;
        }else
        {
            cout<<"Not allocated\t N/A";
            procNotAllocated++;
        }cout<<endl;
    }    
    cout<<"\nNumber of process allocated: "<<n-procNotAllocated;
    cout<<"\nNumber of process not allocated: "<<procNotAllocated;
}

int main() {
    int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;

    int blockSize[m];
    cout << "Enter the block sizes:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "For Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> n;

    int processSize[n];
    cout << "Enter the process sizes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    nextFit(blockSize, m, processSize, n);

    return 0;
}
