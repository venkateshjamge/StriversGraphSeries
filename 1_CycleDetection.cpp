#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool cycle_Detect_bfs(vector<pair<int,int>>arr[],int i,vector<int> &v){
    v[i]=1;
    queue<int>q;
    int parent[v.size()];
    //cout<<v.size()<<"gdfd";
    for(int i=0;i<v.size();i++){
        parent[i]=-1;
    }
    q.push(i);
    while(q.empty()==false){
        int a=q.front();
        q.pop();
        for(auto x:arr[a]){
            int temp=x.first;
            
            if(v[temp]==0){
                q.push(temp);
                v[temp]=1;
                parent[temp]=a;
            }else if(temp!=parent[a]){
                cout<<temp;
                return true;
            }
            
        }   
    }
    return false;
}
bool cycle_Detect_Dfs(vector<pair<int,int>>arr[],int i,vector<int> &v,int par){

    v[i]=1;
    for(auto x:arr[i]){
        int temp=x.first;    
        if(v[temp]==0){
            if(cycle_Detect_Dfs(arr,temp,v,i)){
                return true;
            }
        }else if(temp!=par){
            //cout<<temp;
            return true;
        }
    } 
    return false;
    
}
int main(){
    int n,e,f=0;
    cin>>n>>e;
    vector<pair<int,int>>arr[n];
    int weight=1;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back({b,weight});
        arr[b].push_back({a,weight});
    }
    // vector<int>visited(n,0);
    // for(int i=0;i<n;i++){
    //     if(visited[i]==0){
    //         if(cycle_Detect_bfs(arr,i,visited)){
    //             cout<<"Yes!\n";
    //             f=1;
    //             break;
    //         }
    //     }
    // }
    // if(f==0){
    //     cout<<"No\n";
    // }
    

    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        if(v[i]==0){
            if(cycle_Detect_Dfs(arr,i,v,-1)){
                cout<<"YES!\n";
                f=1;
                break;
            }
        }
    }
    if(f==0){
        cout<<"NO!\n";
    }

}