/*There is a bi-directional graph with n vertices, 
where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each 
edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to 
vertex destination.

Given edges and the integers n, source, and destination, 
return true if there is a valid path from source to destination, or false otherwise.

*/


/* we can use DFS or even disjoin set to check they are connected together

in file, we use BFS to solve the problem

*/
// BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        int m = edges.size();

        // create a graph based on the edges, note that it is bi-directinal
        vector<vector<int>> graph(n+1);
        
        for (int i = 0; i < edges.size(); ++i){

            graph[edges[i][0]].emplace_back(edges[i][1]);
            // because bi-direction
            graph[edges[i][1]].emplace_back(edges[i][0]);

        }
        /* we also can use: 
        for (auto& edge : edges){
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }       
        */
        // create a visited bool vector
        vector<bool> visited(n, false);
        // BFS of cource we should think about the queue (or pq )
        queue<int> q;
        q.emplace(source); // put the source to the queue
        while(!q.empty()){

            int src = q.front();
            q.pop();
            if (visited[src]) continue;
            // if the src reach the destination then return true
            if (src == destination) return true;
            // update src is visited
            visited[src]  = true;

            // get all possible path from src to the next vertecies

            for(auto & v : graph[src]){

                if (!visited[v]){
                    q.emplace(v); // also can use q.push(v), if v is a vector or pair then q.push({v})
                }
            }


        }
    return false;
    }
};



// driver code
int main(){
    int n = 10;
    vector<vector<int>> edges = {{0,7}, {0,8}, {6,1}, {2,0}, {0,4}, {5,8}, {4,7}, {1,3}};
    int source = 7;
    int destination = 1;
    Solution solu;
    cout<<solu.validPath(n, edges, source, destination);
    return 0;
}