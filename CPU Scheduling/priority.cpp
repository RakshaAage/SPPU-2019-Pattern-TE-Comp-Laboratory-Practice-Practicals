#include<iostream>
using namespace std;

class bp  //to represent each process
{
    public:
        string task;
        int arr,bst,wt,tat;
        int prior;
};

class priority
{
    bp *book; //array of object
    public:
        int n;
        void get_data()
        {
            cout<<"Enter the total no of tasks: ";
            cin>>n;
            book= new bp[n];
            cout<<"Arrival time is zero for each process";
            for(int i=0;i<n;i++)
            {
                cout<<"\nEnter the task no : ";
                cin>>book[i].task;
                // cout<<"\nEnter the arrival time : ";
                // cin>>book[i].arr;
                cout<<"\nEnter the burst time : ";
                cin>>book[i].bst;
                cout<<"Enter the priority : ";
                cin>>book[i].prior;
            }
        }

        void task()
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (book[j].prior > book[j + 1].prior) {
                        bp temp = book[j];
                        book[j] = book[j + 1];
                        book[j + 1] = temp;
                    }
                }
            }

            book[0].wt = 0;
            for (int i = 1; i < n; i++) {
                book[i].wt = book[i - 1].wt + book[i - 1].bst;
            }

            for (int i = 0; i < n; i++) {
                book[i].tat = book[i].wt + book[i].bst;
            }
        }

        void display()
        {
            cout<<"\nTask no\tArrival time \tBurst Time\tPriority \tWaiting time \t Turn around time\n";
            for(int i=0;i<n;i++)
            {
                cout<<" "<<book[i].task<<"\t\t"<<book[i].arr<<"\t\t"<<book[i].bst<<"\t"<<book[i].prior<<"\t\t"<<book[i].wt<<"\t\t"<<book[i].tat<<endl;
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
    priority obj;
    obj.get_data();
    obj.task();
    obj.display();
    obj.avg();

    return 0;
}