#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int size=4;
    vector <int> refrenceString ={7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    vector <int> pages;
    int hits = 0;
    int faults = 0;
    for(int ref_page: refrenceString){
        auto it = find(pages.begin(), pages.end(), ref_page);
        if(it!=pages.end()){
            pages.erase(it);
            pages.push_back(ref_page);
            hits++;
        }
        else{
            faults++;
            if(pages.size()<size){
                pages.push_back(ref_page);
            }
            else{
                pages.pop_back();
                pages.push_back(ref_page);
            }
        }
    }
    cout<<"\nHits: "<<hits;
    cout<<"\nMisses: "<<faults;
    
    return 0;
}