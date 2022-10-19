/* 692. Top K frequency words - leetcode.

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

*/


  /*SOLUTION: if we use only hashtable to count the frequency of the strings in the given 'words' string we can easily realize that u_m.first contains string, u_m.second contains its frequency e.g., ("love", 2)
the problem here is: we CANNOT sort the hashtable by the second (use map instead of unordered_map) -> one of the solution we can use is: using priority_queue of vector to store u_m by (second, first) with custom comperator
but we cost O(nlogn) time complexity and O(n) to contain the vector of pair (second, first)
and then we also cost O(k) to contain vector ans

Note: in some solution they also can use vector<pair<string, int>> to contain elements and then sort this vector by custom comparator (by the second)
*/ 
  

class Solution{
 
private:
    
  struct comp{
    
    bool operator()(const pair<int, string> freq_str1, const pair<int, string> freq_str2){
      //if their frequency is the same hence sort by lexicographical order lowest -> heighest
      if(freq_str1.first == freq_str2.first){
        return freq_str1.second < freq_str2.second;
      }
      else{
        return freq_str1.first < freq_str2.first;
      }
    }
  
  };
public:

    vector<string> topKFrequent(vector<string>& words, int k) {   
      
      vector<string> ans;
      unordered_map<string, int> freq_words;
      priority_queue< pair<int, string>, vector<pair<int, string>>, comp> p_q; // to sort the frequency of words
      
      /*count the frequency of word in words*/
      
      for(const auto word: words){
        freq_words[word]++;
      }
      /*put elelemts in freq_words into the p_q*/
      for(const auto eles: freq_words){
        p_q.emplace(eles.second, eles.first);
      }
      /*finally traverse the p_q k times and get put these string into ans
      note that p_q.top() is a pair and we want to get its string that mean we need to access to second not the first
      */
      while(k--){
        ans.emplace_back(p_q.top().second);
          p_q.pop();
      }
        return ans;
    }
    


};
