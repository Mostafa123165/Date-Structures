#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long ll;
#define nl "\n"
#define all(x) x.begin(), x.end()
#define fast cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
vector<int>graph[300005] ;
int vis[300005] ;
int aa[300005] ;
int n_blue=0 , n_red= 0 ;
int ans =0 ;
int sum =0 ;
bool f(pair<int,int> p1,pair<int,int>p2)
{
    return p1.first < p2.first || p1.first == p2.first && p1.second > p2.second ;
    // return p1.second < p2.second  ;
}
void solve(){
    int n , m ;
    cin>>n>>m ;
     int a[m] ;
     for(int i =0 ;i<m ;i++)cin>>a[i] ;
        sort(a,a+m);
        int mx = 0 ;
        vector<int>res ;
    for(int i =0 ;i<m ;i++){
         if(i==m-1){
             int diff = abs(a[0] - a[i] ) - 1;
             diff+=2;
             diff = n -diff ;
             if(diff>1)
                diff-=1 ;
              mx =max(mx , diff);
              res.push_back(diff) ;
        }
        else {
            int diff = (a[i+1] - a[i] ) - 2;
            mx =max(mx , diff);
            res.push_back(diff) ;
        }
    }
    int x =0 ;
    if(res.size() > 1){
     x = res[res.size()-2] ;
     x-=3 ;
 }
     mx+=x ;
    cout<<n-mx<<endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin >>t;
    while(t--){
        solve();
    }
}