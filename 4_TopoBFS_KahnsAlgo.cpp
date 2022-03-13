#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//KahnsAlgorithem For

void bfs_Topo(vector<pair<int,int>>arr[],vector<int>&inDegree){
    
    queue<int>q;
    int n=inDegree.size();
    for(int x=0;x<n;x++){
        if(inDegree[x]==0){
            q.push(x);
        }
    }
    while(q.empty()==false){
        int a=q.front();
        cout<<a<<" ";
        q.pop();
        for(auto x:arr[a]){
            int temp=x.first;
            inDegree[temp]--;
            if(inDegree[temp]==0){
                q.push(temp);
            }
        }
    }
}



int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>arr[n];
    int weight=1;
    vector<int>inDegree(n,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back({b,weight});
        //arr[b].push_back({a,weight});
        inDegree[b]++;
    }

    stack<int>s;
    vector<int>v(n,0);
    bfs_Topo(arr,inDegree);
    
    
}