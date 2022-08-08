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
bool f(pair<int,int> p1,pair<int,int>p2)
{
    return p1.first < p2.first || p1.first == p2.first && p1.second > p2.second ;
    // return p1.second < p2.second  ;
}
vector<int>graph[200005] ;
int vis[200005] ;
int time_node[200005] ;
int parent  [200005] ;
int timer = 1 ;
int cycle_start = -1 ;
int cycle_end = -1 ;
bool dfs(int node , int per){
    vis[node] = 1;

    time_node[node] = timer ;
    timer++;

    for(int child : graph[node]){
        if(child == per) continue;
        parent[child] = node ;

        if(!vis[child]){
            if(dfs(child , node )) {
                return true ;
            }
        }
    
    else if(time_node[node] > time_node[child] && vis[child]) {
        cycle_start = child ;
        cycle_end = node ;
        return true ;
    }
}
return false ;
}
void solve(){
    int n , m ;
    cin>>n>>m ;

    for(int i = 1 ; i<=m ;i++){
        int x  , y ;
        cin>>x>>y ;
        graph[x].push_back(y) ;
        graph[y].push_back(x) ;
    }

    for(int i =1 ;i<=n ;i++){
        if(!vis[i])
            if(dfs(i , -1)) break ;
    }
    if(cycle_start==-1){
        cout<<"IMPOSSIBLE\n" ;
    }
    else {
         cout<<"find Cycle \n" ;
        vector<int>ans ;
        ans.push_back(cycle_start) ;
        for(int i = cycle_end ; i != cycle_start ; i = parent[i] ) ans.push_back(i) ;
        ans.push_back(cycle_start) ;

         cout<<ans.size()<<endl ;
         for(int i = ans.size()-1 ;i>=0 ;i--)cout<<ans[i]<<" ";
         cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    // cin >>t;
    while(t--){
        solve();
    }
}
