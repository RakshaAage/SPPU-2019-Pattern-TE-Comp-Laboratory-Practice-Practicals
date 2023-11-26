#include<iostream>
using namespace std;

class bp  //to represent each process
{
    public:
        string task;
        int arr,bst,wt,tat;
};

class round_robin
{
    bp *book; //array of object
    public:
        int n;
        int quantum;
        void get_data()
        {
            cout<<"Enter the total no of tasks: ";
            cin>>n;
            cout<<"Consider arrival time zero for each process";
            book= new bp[n];
            
            for(int i=0;i<n;i++)
            {
                cout<<"\nProcess "<<i+1<<" : ";
                // cout<<"\nEnter the arrival time : ";
                // cin>>book[i].arr;
                cout<<"Enter the burst time : ";
                cin>>book[i].bst;
            }
            cout << "\nEnter Quantum time : ";
            cin >> quantum;
        }

        void task()
        {
            int* remain = new int[n];
        for (int i = 0; i < n; i++) {
            remain[i] = book[i].bst;
        }
        int current = 0;
        int* completion = new int[n]; // Track completion time for each task

        while (true) {
            bool tasksCompleted = true;

            for (int i = 0; i < n; i++) {
                if (remain[i] > 0 && book[i].arr <= current) {
                    tasksCompleted = false;

                    if (remain[i] > quantum) {
                        current += quantum;
                        remain[i] -= quantum;
                    } else {
                        current += remain[i];
                        remain[i] = 0;
                        completion[i] = current;
                    }
                }
            }

            if (tasksCompleted) {
                break;
            }
        }

        // Calculate waiting time and turn-around time
        for (int i = 0; i < n; i++) {
            book[i].tat = completion[i] - book[i].arr;
            book[i].wt = book[i].tat - book[i].bst;
        }

        delete[] remain;
        delete[] completion;
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
    round_robin obj;
    obj.get_data();
    obj.task();
    obj.display();
    obj.avg();

    return 0;
}