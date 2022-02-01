/*There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that
 there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to
 dst with at most k stops. If there is no such route, return -1.

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown (0-1-2). 1 stop at node 1
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, 
as marked red in the picture.

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown, 0-2. 0 stop. 
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
*/

/* Bellam Ford algorithm, but here we need to read faster solution. It is more or less the smallest
 BFS.


*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int source, int target, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int>dist(n,INT_MAX);
        vector<int>stops(n,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minHeap;
        
        dist[source] = 0;
    stops[source] = 0;
    minHeap.push({0, source, 0});
    
    while(!minHeap.empty()){
        auto [curDist, curNode, curStops] = minHeap.top();
        minHeap.pop();
        if(curNode == target) return curDist;
        if(curStops == k+1) continue;
        for(auto &[nextNode, nextWeight] : adj[curNode]){
            int nextDist = curDist + nextWeight;
            int nextStops = curStops + 1;
            if(nextDist < dist[nextNode]){
                dist[nextNode] = nextDist;
                stops[nextNode] = nextStops;
                minHeap.push({nextDist, nextNode, nextStops});
            }else if(nextStops < stops[nextNode]){
                stops[nextNode] = nextStops;
                minHeap.push({nextDist, nextNode, nextStops});
            }
        }
    }
    return -1;
    }
};