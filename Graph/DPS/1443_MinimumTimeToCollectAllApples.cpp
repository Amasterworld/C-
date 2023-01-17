
/*1443. Minimum Time to Collect All Apples in a Tree
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. 
You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, 
starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/

/*SOLUTION: - first step create a graph, 
            - uses dfs algorithm to reach the leaf of each branch
            - check whether leaf contains an apple, if yes +2 seconds to total time, 
            - if child_time != 0 even itself does not have an apple that means somewhere in its braches contains the node having the apple, hence each step from the
            node 0 to the current node should +2 second also

*/
#include<iostream>
#include<vector>


class Solution{

    int dfsMinTIme(std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple, std::vector<std::vector<int>>& graph, int curr_node){

        int time = 0, child_time;
        visited[curr_node] = true;
        for(const auto& sub_node : graph[curr_node]){
            /*keep depth search of the sub-nodes based on the graph
            until the child-time is returned in other words, reach the leaf
            */
            if(!visited[curr_node]){
                child_time = dfsMinTIme(edges, hasApple, graph, curr_node);
            }
            /* when curr_node is a leaf,  we should know that whether it contains an apple */
            if(hasApple[curr_node]){
                time += 2;
            }
            /*if the curr_node is not a leaf, but its brach containing apple(s) so still have to pay time to reach the curr_node from node 0*/
            if(child_time != 0){
                time += child_time;
            }
        }
        /*return total time of the curr_node to its parent*/
        return time;
    }
public:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) {
        
        std::vector<std::vector<int>> graph(n);
        std::vector<int> visited(n);


        for(const auto& edge: edges){
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);

        }
        return dfsMinTIme(edges, hasApple, graph, 0);// 0 is start node

    }
};