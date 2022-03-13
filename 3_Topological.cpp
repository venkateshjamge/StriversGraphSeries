#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//for Directed ACyclic
void dfs_Topo(vector<pair<int,int>>a[],int i,vector<int>&v,stack<int>&s){
    v[i]=1;
    for(auto x:a[i]){
        int temp=x.first;
        if(v[temp]==0){
            dfs_Topo(a,temp,v,s);
        }
    }
    s.push(i);
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>arr[n];
    int weight=1;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back({b,weight});
        //arr[b].push_back({a,weight});
    }

    stack<int>s;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        if(v[i]==0){
            dfs_Topo(arr,i,v,s);
        }
    }
    while(s.empty()==false){
        cout<<s.top();
        s.pop();
    }
}