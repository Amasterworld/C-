/*433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.


Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:

Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2

Example 3:

Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3

*/

/*SOLUTION: with the nature of this problem, normally can be solved by backtracking algorithm or DFS and then compare to get the minimum  steps. However, in this problem, used BFS to solve. 
each string after changing single char to create a gene string can be seens as a node or state (finite state machine). Two states are connected by an edge (transition) if they differ by one chars from 'ACGT'. And the added constrains are that the chars must be one of 'ACGT', and each states must be in a bank 

now the problem is very simple: what is shortest way from start to end? BFS or Dijistra or A star is good solution for shortest problem but here the distance betweens states are the same: 1, hence BFS.


Complexity Analysis:  because the constrain of this problem explicitly that the size of start end, == 8. and the chars for combination only 4 chars, so TC is O(n), n = bank.size();
However, now if we assume that if the string length n, and the chars for combination is m, hence we have pow(m,n) combinations because for each of the char has m options.

*/
#include<iostream>
#include<unordered_set>
#include<queue>
#include<string>

class Solution{

public:

    int minMutation(std::string start, std::string end, std::vector<std::string>& bank) {

        std::queue<std::string> queue_states;
        std::unordered_set<std::string> visited;

        int step{};
        /*add the start state to queue and visited*/
        queue_states.emplace(start);
        visited.insert(start);

        while(!queue_states.empty()){
            
            int queue_size = queue_states.size();
            for(int i = 0; i < queue_size; ++i){
                
                std::string curr_state = queue_states.front();
                queue_states.pop();
                /*stop when reach the end state*/
                if(curr_state == end){
                    return step;
                }


                /*check all possible new states con be created from curr_state with 4 chars 'A', 'C', 'G', and 'T'. Also check whether the new_state is in bank.*/

                for(auto c: "ACGT"){ // if you want you can do simething like this vector<char> com = {'A', 'C', 'G', 'T'} and use for loop the same, note that string in C++ can be seens as a vector
                    for(int j = 0; j < curr_state.size(); ++j){
                        
                        std::string new_state = curr_state;
                        new_state[j] = c;
                       
                        /*check whether a new_state was created before (visisted) and in a bank OR NOT*/
                        if (!visited.count(new_state) && find(bank.begin(), bank.end(), new_state) != bank.end()){
                            
                            queue_states.emplace(new_state);
                            visited.insert(new_state);
                        }
                    }

                }
            }
            /*increase each step when move the to next state*/
            step++;
        }

    return -1;
    }
};

int main(){

    std::vector<std::string>bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    std::string start = "AAAAACCC";
    std::string end = "AACCCCCC";
    Solution s;
    std::cout<<"the minimum step to reach the end is: "<<s.minMutation(start, end, bank); // output 3
    return 0;
}
