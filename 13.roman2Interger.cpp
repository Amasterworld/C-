/* Roman to Intergert:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

/*SOLUTION: switch and case is the best solution,
- also can use unordered_map to store  keys (Roman) and values(integer)
then using while loop to parse the string s, and check condition -> slower than uses switch and case
*/

#include <iostream>
#include <string>
//using namespace std;
class Solution{
public: 
    int romanToInt(std::string &s){

        int len_s = s.size(); // or s.size()
        int ans = 0;

        for (int i = 0; i < len_s; ++i){

            switch(s[i]){

                case 'I':
                    if (s[i+1] == 'V' || s[i+1] == 'X'  ){
                        ans -= 1;
                    }
                    else{
                        ans += 1;
                    }
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    if (s[i+1] == 'L' || s[i+1] == 'C'){
                        ans -= 10;
                    }
                    else{
                        ans += 10;
                    }
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    if(i+1 <len_s &&  (s[i+1] == 'D') || s[i+1] == 'M' ) {
                        ans -= 100;
                    }
                    else{
                        ans += 100;
                    }
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }   

        }

        return ans;
    }

};


int main(){
   std:: string  s = "MCMXCIV";

    Solution solu;
    std::cout<< solu.romanToInt(s);
    return 0;


}