#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define INT_MAX 2147483647
//DirectedGraph
void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 
	
} 

int main(){
    int n,e;
    cin>>n>>e;
    vector<int>arr[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;//>>weight;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    stack<int>s;
    BFS(arr,n,2);  
}