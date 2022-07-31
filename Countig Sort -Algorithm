#include <bits/stdc++.h>
using namespace std;
vector<int> res , freq   ; // resulting array
void CountingSort(vector<int>&v , int mx ){
    int size = (int)v.size() ;
    
    res.resize(size);
    freq.resize(mx+1);
    
    for(int i =0 ;i<size;i++)   freq[v[i]]++ ;

    for(int i =0 ;i< freq.size();i++)   if(i) freq[i] = freq[i]+freq[i-1];
    
    for(int i = size-1 ;i>=0 ;i--){
        int pos = freq[v[i]] ;
        res[pos-1] = v[i] ;
        freq[v[i]]-- ;
    }
    
    for(int i =0 ; i<res.size() ;i++)cout<<res[i]<<" ";
    cout<<endl; 
    
}
int main() {
    vector<int>v = {2,10,3,1,2,4,5,9} ;
    int mx = *max_element(v.begin(),v.end()) ;
    CountingSort(v , mx) ;
}
