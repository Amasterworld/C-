/*
3. Longest Substring Without Repeating 
Given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

/*SOLUTION: we can use two pointers to solve this problem
l1 pointers to increase indecies in the string s 
l2 pointers to keep the index of the char that will be the same at s[l1]
if this happens the set chat st will delete the char that will be repeated in s[l1]
and l2++;


*/


class Solution{
public:
    int lengthOfLongestSubstring(string& s) {
        
        set<char> st;
        int l1 = 0; // l1 pointers to increase indecies in the string s 
        int l2 = 0;
        int ans = 0;
        while (l1 < n){

            if (st.count(s[l1]) == 0){ // char at s[l1] does not in st
                
                st.insert(s[l1]);
                l1++;
                // find the max lengh of different 
                ans = max(ans, l1 - l2);            
            }
            else{ // if s[l1] is char having in set st then
                st.erase(s[l2]); // s[l2] is a char repeating with char at s[l1]
                l2++;

            }
            // after deleting the char can be repeatable char at s[l1] that mean in the next iteration it WILL NOT REPEAT anymore
            // for exaple s = "abcabcd", s[l1 ==3] == 'a', repeat s[l2 == 0] == 'a; st was ="abc" after erasing st = "bc"
            // hence in the next iteration st can insert and will be "bca"
        }




    }
};