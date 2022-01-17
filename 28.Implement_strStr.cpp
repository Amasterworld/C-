/*Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0

*/

/*SOLUTION: - 1st approach is using two pointers traveser in haystack, whenver meets the 1st char 
in needle[l1] (l1=0) then increase l1++, l2++, keep increasing if they are the same and l1 and l2 <length of the both input 
finally if l1 == needle.size() then return firstOcc (firstOcc = l2 whenver haystack[l2] == needlle[l1])
else reset l1 = 0; and l2 = firstOcc, l2++ in while loo
-VERY SLOW
- 2nd Oppoarch: using ASCII change the char to the number
caculate n_sum of  needle , and h_sum of haystack from 0 to needle size
if they are the same, flag == true and check their order, if yes return, else break
check the remaining length of the haystack if -i -i<  neele.size() return -1
update h_sum, h_sum = h_sum - haystack[i] + haystack[i + needle.size()]

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        if (needle == "") return 0;
        if (haystackSize < needleSize) return -1;
        int nsum = 0;
        int hsum = 0;
        bool found = false;
        // using ASCII Table to sum all char in sum for example neeld ="ll" -> l= 108, ll = 108x2 =216
        for (int i = 0; i < needleSize; ++i) 
            nsum += (int) needle[i];
        // similarly, to get the sum of neeleSize in haystack, for example haystack == "hello" 
        // hsum = 205 = h-104 +101-e =205.
        for (int j = 0; j < needleSize; ++j) 
            hsum += (int) haystack[j];
        
        
        for (int i = 0; i < haystackSize; ++i) {
            if (hsum == nsum) {  //(1)
                bool found = true;
                // the sum of them only guarantee that the chars appear between needle and haystack from i are the same, but their order cannot be guaranteed, for example "----ippi", needle ="pi", we want to return at 6, not 4
                // then we need to check the order of chars in  needle and haystack from i.
                for (int j = 0; j < needleSize; ++j) {
                    if (needle[j] != haystack[j + i]) {
                        found = false;
                        break;
                    }
                }
                if (found) return i;
            }
            // if the remaining length of the haystackSize   smailler than needleSize and no char between them is in common so far -> the haystack cannot contain the needle. 
            // that means they
            if (haystackSize - i - 1 < needleSize) return -1; 
           // minus the (int) of char at i and plus of the char at [i+needleSize]
            
            hsum = hsum - (int) haystack[i] + (int) haystack[i + needleSize];
            // check the cond (1), whenever they are  == it is the 1st occurence 
        }
        return -1;
    }
};