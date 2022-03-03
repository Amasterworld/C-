/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/

/*SOLUTION: two pointers, traveser each char of string t, whenever meets the same char then increase var idx++
finally if idx == s.size() return true else return false
for exampple s = "acb", t ="ahbcd", a == a, idx++ == 0++ = 1, t[3] == s[1] == "c" 
id++ == 2; then never t[i] can be == s[2] =='b', idx == 2 != s.zie() ==3, then return false

 */

class Solution{
public:

    bool isSubsequence(string s, string t) {

        int m = s.size();
        int n = t.size();

        int idx = 0;
        int l = 0;
        while (l <n ){

            if (t[l] == s[idx]){
                idx++;
            }
            l++;
        }
         // if finally idx = s.size() that means every char in string s is met in 
         //t even the order return true
        // for example  s = "acb", t ="ahbcd", a == a, idx++ == 0++ = 1, 
        //t[3] == s[1] == "c" id++ == 2; then never t[i] can be == s[2] =='b'
        return idx == m ? true : false;

    }
};