
// quicksort algorithm 
#include <bits/stdc++.h>
using namespace std;

int Partition (vector<int>&v , int l , int r ){
    int j = l-1 ;
    int pivot = v[r] ;
    for(int i = l ; i <= r-1 ;i++){
        if(v[i] < pivot){
            j++ ;
            swap(v[j] , v[i]) ;
        }
    }
    j++;
    swap(v[j] , v[r]) ;
    return (j) ;
}

// # Time complexity QuickSort .
// complexity in worst case O(n*n) .
// complexity in best case O (n lgn) .
void QuickSort(vector<int> &v , int l , int r ){

    if(l < r) {
        int pos_pivot = Partition(v,l,r);
        QuickSort(v, l, pos_pivot - 1);
        QuickSort(v, pos_pivot + 1, r);
    }
}


int  main(){
vector<int>v = {50,110,54,55,40,70,50} ;
int size=7 ;
    QuickSort(v,0,6);
    for(int in : v)cout<<in<<" ";cout<<endl;
}