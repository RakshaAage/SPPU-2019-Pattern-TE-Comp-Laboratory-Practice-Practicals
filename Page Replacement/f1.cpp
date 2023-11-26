#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> pages;
    int faults = 0;
    int hits = 0;
    int currentIndex = 0;
    int fsize;

    cout<<"Enter the frame size: ";
    cin>>fsize;
    cout<<"Page Reference Stream Length: ";   
    cin>>n; 

    int reference_string[n];
    cout<<"\nEnter the Reference Stream: ";
    for(int i=0;i<n;i++)
    {
        cin>>reference_string[i];
    }

    // Iterate through each page in the reference stream
    for (int ref_page : reference_string) {
         // Check if the page is already in memory
        auto it = find(pages.begin(), pages.end(), ref_page);
         // If the page is in memory, it's a hit
        if (it != pages.end()) {
            hits++;
        }
        else 
        {  // If the page is not in memory, it's a fault
            faults++;
            // Check if there is space in memory for a new page
            if (pages.size() < fsize) {
                pages.push_back(ref_page);
            }
            else {
                // If memory is full, replace a page using the FIFO strategy
                pages[currentIndex] = ref_page;
                // Update the index for FIFO
                currentIndex = (currentIndex + 1) % fsize; 
            }
        }
    }
    
    cout << "Total number of Page Hits: " << hits << endl;
    cout << "Total number of Page Faults: " << faults << endl;
    
    return 0;
}