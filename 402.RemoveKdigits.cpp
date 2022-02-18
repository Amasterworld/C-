/*Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

*/

/*SOLUTION: whenever we need to find by deleting or inserting the create or find 
the greater or smaller number stack always is good data
for this problem: we want to get the smallest number that means we traveser the number in given num 
from left to right. We remove the number on the left when it is greater the number on the RIGHT
then we get the smallest number after k removing times
so what if the right righ number > the left number (num[i+1] > num[i])
very simple we only need to delete k time from right to left for example 123456, k =2, ofc 
the smallest number is 1234;
*/

class Solution{
public:
    string removeKdigits(string num, int k) {

        string ans = "";
        for( char curr_c: num){
            //here we use ans as the stack to save Space Complexity , and faster than uses stack. if the left number(in the ans) > right number(curr_c)
            
            while (!ans.empty() && ans.back() > curr_c && k > 0  ){

                ans.pop_back();
                k--;

            }
            // equally if( ans.empty() && c =='0' ) continue
            if (!ans.empty() || curr_c != '0') // add curr_c if it is not 0 and ans is empty
                ans.push_back(curr_c);

        }

        // if left number always smaller than right number then only need to delete from right to left until k ==0s
        while (!ans.empty() && k > 0){
         ans.pop_back();
         k--;       
        }


    return ans;
    }


};