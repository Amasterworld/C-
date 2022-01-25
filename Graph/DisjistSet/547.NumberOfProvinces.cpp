
//547. Number of Provinces

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    
    vector<int> parents;
    
    int find(int i) {
        return parents[i] == i ? i : parents[i] = find(parents[i]);
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        parents.resize(n);
        
        for (int i = 0;i<n;i++) {
            parents[i] = i;
        }
        
        for (int i =0;i<n;i++) {
            for (int j = i+1;j<n;j++) {
                if (isConnected[i][j]) {
                    parents[find(i)] = find(j);
                }
            }
        }
        
        unordered_set<int> groups;
        for (int i: parents) {
            groups.insert(find(i));
        }
        
        return groups.size();
        
    }
};