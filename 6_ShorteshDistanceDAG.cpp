#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define INT_MAX 2147483647
//DirectedGraph
void topo(vector<pair<int,int>>arr[],int i,vector<int>&v,stack<int>&s){
    v[i]=1;
    for(auto x:arr[i]){
        int temp=x.first;
        if(v[temp]==0){
            topo(arr,temp,v,s);
        }
    }
    s.push(i);
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>arr[n];

    for(int i=0;i<e;i++){
        int a,b,weight;
        cin>>a>>b>>weight;
        arr[a].push_back({b,weight});
        //arr[b].push_back(a);
    }

    stack<int>s;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        if(v[i]==0){
            topo(arr,i,v,s);
        }
    }
    vector<int> dis(n,INT_MAX);
    int src=0;
    dis[src]=0;
    while(s.empty()==false){
        int a=s.top();
        cout<<a<<" ";
        s.pop();
        if(dis[a]!=INT_MAX){
            for(auto x:arr[a]){
                int temp=x.first;
                if(dis[temp]>(dis[a]+x.second)){
                    dis[temp]=dis[a]+x.second;
                }
            }
        } 
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
}