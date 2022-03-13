#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void bfs(vector<pair<int,int>> arr[],int i,vector<int>&v){
    queue<int>q;
    q.push(i);
    v[i]=1;
    while(q.empty()==false){
        int a=q.front();
        cout<<a<<" ";
        q.pop();
        for(auto x:arr[a]){
            int temp=x.first;
            if(v[temp]==0){
                q.push(temp);
                v[temp]=1;
            }
        }
    }
}
void dfs(vector<pair<int,int>>arr[],int i,vector<int> &v){
    cout<<i<<" ";
    v[i]=1;
    for(auto x:arr[i]){
        int a=x.first;
        if(v[a]=false){
            dfs(arr,a,v);
        }
    }
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
        arr[b].push_back({a,weight});
    }
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            bfs(arr,i,visited);
        }
    }
    cout<<"\n";
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(arr,i,v);
        }
    }

}