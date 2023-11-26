#include<iostream>
using namespace std;

class bp  //to represent each process
{
    public:
        string task;
        int arr,bst,wt,tat;
};

class fcfs
{
    bp *book; //array of object
    public:
        int n;
        void get_data()
        {
            cout<<"Enter the total no of tasks: ";
            cin>>n;
            book= new bp[n];
            
            for(int i=0;i<n;i++)
            {
                cout<<"Process "<<i+1<<" : ";
                cout<<"\nEnter the arrival time : ";
                cin>>book[i].arr;
                cout<<"\nEnter the burst time : ";
                cin>>book[i].bst;
            }
        }

        void task()
        {
            for(int i=0;i<n-1;i++)      // sorted in ascending order based on their arrival time
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if(book[j].arr>book[j+1].arr)
                    {
                        bp temp=book[j];
                        book[j]=book[j+1];
                        book[j+1]=temp;
                    }
                }
            }

            for(int i=0;i<n;i++)         // calculate wt and tat
            {
                book[i].wt=0;
                for(int j=i-1;j>=0;j--)
                {
                    book[i].wt += book[j].bst;
                }
                book[i].wt -= book[i].arr;     
                book[i].tat = book[i].bst+ book[i].wt;
            }
        }

        void display()
        {
            cout<<"\nTask no\tArrival time \tBurst Time\tWaiting time \t Turn around time\n";
            for(int i=0;i<n;i++)
            {
                cout<<" "<<i+1<<"\t\t"<<book[i].arr<<"\t\t"<<book[i].bst<<"\t"<<book[i].wt<<"\t\t"<<book[i].tat<<endl;
            }
        }

        void avg()
        {
            int sum_wt=0;
            int sum_tat=0;
            for(int i=0;i<n;i++)
            {
                sum_wt+= book[i].wt;
                sum_tat+= book[i].tat;
            }
            float avg_wt = float(sum_wt)/n;
            float avg_tat = float(sum_tat)/n;
            cout<<"Average WT : "<<avg_wt;
            cout<<"\nAverage TAT : "<<avg_tat;
        }
};

int main()
{
    fcfs obj;
    obj.get_data();
    obj.task();
    obj.display();
    obj.avg();

    return 0;
}