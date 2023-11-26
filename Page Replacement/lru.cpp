#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int size=3;
    vector <int> refrenceString ={1, 2, 1, 0, 3, 0, 4, 2, 4};
    vector <int> pages;
    int faults =0;
    int hits =0;
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
                pages.erase(pages.begin());
                pages.push_back(ref_page);
            }
        }
    }
    cout<<"\nHits: "<<hits;
    cout<<"\nMisses: "<<faults;
    return 0;
}