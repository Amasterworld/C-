/*12. Integer to Roman - leetcode
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

    1 <= num <= 3999

SOLUTION: the simplest solution for this problem is: using if else to check while the num >=1000 (based on the contrains) then ans+='M' and then num -= 1000
and then keep checking num >= 900 ans += "CM"; num -= 900; keep checking num with the following condition 500 400 100 90 50m 40 10 5 4 and finally 1

it can be fast because we do not need to make an extra container but the code is not compact

here, I use the vector<pair<int, string> > to store the threshold of the Roman number (to use vector pair I must order it for the progra, if you are lazy to do it
you can use map<int, string, greater<int>> mp to do it)
*/
#include<iostream>
#include<vector>
#include<string>
class Solution{
private:
    std::vector< std::pair<int, std::string> >  vec_num = { {1000,"M"}, {900,"CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };  
    size_t m_num;
public:

    Solution(size_t num) : m_num(num){}

    std::string intToRoman(){

        std::string ans{};
        // compare the input number, num, 
        for(auto it : vec_num){
            while (m_num >= it.first){
                
                ans += it.second;
                //reduce num
                m_num -= it.first;

            }
        }
        return ans;
    }
};

int main(){
    size_t num = 1994;
    Solution s(num);
    std::cout<<s.intToRoman()<<'\n';// MCMXCIV - correct

    //size_t num = 3999;
    //std::cout<<s.intToRoman()<<'\n';// "MMMCMXCIX" -correct 
 
    return 0;
}