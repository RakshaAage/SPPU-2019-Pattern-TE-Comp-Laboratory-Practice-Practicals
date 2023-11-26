#include<iostream>
using namespace std;

class bp  //to represent each process
{
    public:
        string task;
        int arr,bst,wt,tat;
};

class sjf
{
    bp *book; //array of object
    public:
        int n;
        void get_data()
        {
            cout<<"Enter the total no of tasks: ";
            cin>>n;
            book= new bp[n];
            // cout<<"Arrival time is zero for each process";
            for(int i=0;i<n;i++)
            {
                cout<<"\nEnter the task no : ";
                cin>>book[i].task;
                cout<<"\nEnter the arrival time : ";
                cin>>book[i].arr;
                cout<<"\nEnter the burst time : ";
                cin>>book[i].bst;
            }
        }

        void task()
        {
            for(int i=0;i<n-1;i++)      // sorted in ascending order based on their burst time
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if(book[j].bst>book[j+1].bst)
                    {
                        bp temp=book[j];
                        book[j]=book[j+1];
                        book[j+1]=temp;
                    }
                }
            }

           int* remain = new int[n];
        for (int i = 0; i < n; i++) {
            remain[i] = book[i].bst;
        }
        int current = 0;
        int completed = 0;
        int* completion_Time = new int[n];
        
        do {
            int short_index = -1;
            int short_time = 9999;
            for (int i = 0; i < n; i++) {    //finds the process with the shortest remaining burst time among those that have arrived and have remaining burst time.
                if (remain[i] > 0 && book[i].arr <= current && remain[i] < short_time) {
                    short_time = remain[i];
                    short_index = i;
                } 
            }

            if (short_index == -1) {
                current++;
            } else {
                remain[short_index]--;
                if (remain[short_index] == 0) {
                    completed++;
                    completion_Time[short_index] = current + 1;
                    book[short_index].wt = completion_Time[short_index] - book[short_index].bst - book[short_index].arr;
                }
                current++;
            }
        } while (completed < n);

        for (int i = 0; i < n; i++) {
            book[i].tat = completion_Time[i] - book[i].arr;
        }

        delete[] remain;
        delete[] completion_Time;

        }

        void display()
        {
            cout<<"\nTask no\tArrival time \tBurst Time\tWaiting time \t Turn around time\n";
            for(int i=0;i<n;i++)
            {
                cout<<" "<<book[i].task<<"\t\t"<<book[i].arr<<"\t\t"<<book[i].bst<<"\t"<<book[i].wt<<"\t\t"<<book[i].tat<<endl;
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
    sjf obj;
    obj.get_data();
    obj.task();
    obj.display();
    obj.avg();

    return 0;
}