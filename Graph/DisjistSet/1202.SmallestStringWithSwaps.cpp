//1202 . Smallest String With Swaps
/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] 
indicates 2 indices(0-indexed) of the string.
You can swap the characters at any pair of indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

*/

/*SOLUTION: each char in s can swap for another based on the eles in pairs vector, that means we can see the char is connected to another char 
based on the eles in pairs vector
if all chars are connected together as the example 2 and 3, we only need to sort s, and done, otherwise we see each groups char connected together
a a subgraph, and then we only need to swap the smallest char (ASCII)   for the smallest position of the subgraph, until all chars are swapped
-> thefore the problem now can be solved by using disjoint set, join the possible char based on a given pairs vector
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

class UnionSet{

public: 
    // constructor
    UnionSet(int len_s): root(len_s), rank(len_s){
        for (int i = 0; i < len_s; ++i){

            root[i] = i;
            rank[i] = 1;
        }

    }

    int find(int x){// if x is root that means x == root x return x, else for exmaple 4-8, root at 8 = 4 that means 8 != root[8] (4)
        // then root[8] == find(4), recurs here  4== root][4] -> return 4 -> root[8] =4; we get the path 

        return x == root[x] ? x : root[x] = find(root[x]);

    }

    void union_set(int x, int y){

        int rootX = root[x];
        int rootY = root[y];
        // if they are not the same root
        if(rootX != rootY){
            // then union them based on their rank
            if (rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            }
            else{ // at the initial point rank of all ele = 1, then choose one of them to be a head and increase its rank

                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }


private:
vector<int> root;
vector<int> rank;

};


class Solution{
public:
     string smallestStringWithSwaps(string s, vector<vector<int>>& pairs){

        int len_s = s.size();
        unordered_map<int, vector<int> > mp;
        UnionSet uf(len_s);

        for (int i = 0; i < pairs.size(); ++i){
            // connect pairs[i][0] with pairs[i][1]
            uf.union_set(pairs[i][0], pairs[i][1]);

        }
        // store heads and their corresponding tails 
        for (int i = 0; i < len_s; ++i){

            mp[uf.find(i)].emplace_back(i);
        }

        // the size of mp is only 1 the measn only 1 head and its tals -> all of them are connected together as one graph, sort s -> done

        if (mp.size() == 1){
            sort(s.begin(), s.end());
            return s;
        }
        // sort and swap for the smalles idx  in the each sub-graph

        for (auto & ele : mp){

            priority_queue<int, vector<int>, greater<int> > idx;
            priority_queue<int, vector<int>, greater<int> > chars;

            vector<int> temp_ele = ele.second;
            for (auto ele_temp_ele : temp_ele){
                idx.push(ele_temp_ele);
                chars.push(s[ele_temp_ele]);

            }
            // idx and char are pq, and  pq.top() get the smallest element
            // idx has a form (0,3) char (b, d)  -> idx.top() = 0, char.top() = b
            while(!idx.empty()){

                s[idx.top()] = chars.top() ;

                idx.pop();
                chars.pop();
            }
        }
    return s;
    }
   
};
