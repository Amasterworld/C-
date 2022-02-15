/*Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word
 or phrase, typically using all the original letters exactly once.


Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

/*SOLUTION: we can see that the strings:  eat tea or ate after sorthing they are the same: aet
hence we can use a sorted string as the key and the origial string is a value
after doing this we only need to traveser the value of the container and emplace_back to the
ans. DONE
*/

class Solution{
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string> > u_m; // sorted string, original strings

        for (const string& s: strs){

            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            // emplace to the Map
            u_m[sorted_s].emplace_back(s);
        
        }
        // traveser the second of u_m to get the answer
        for(const auto& s : u_m){

            ans.emplace_back(s.second);
        }

    return ans;
    // time compleixty: we need to call n times to sort, and n insertion to the u_m
    // sorting all the keys has TS O(nmlogm), m is maximum size of string
    // insert n strings to the u_m takes O(n*m) 
    //--> total we have O(nmlogm) TC

    }





};
