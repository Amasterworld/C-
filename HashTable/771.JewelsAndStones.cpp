/*771. Jewels and Stones - leetcode
 * You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. \
 * You want to know how many of the stones you have are also jewels.

Letters are case-sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

 SOLUTION: to solve this problem, we can use brute-force, traverse both string and compare to each other if they are == then count++, but the TC is  TC O (n*m)
 better solution: + using unordered_map to count the frequency of the stone, e.g., the stone a,frequency = 1, AA, frequency == 2, b, frequency == 4
                  + traverse the string jewel and use find method to to find them if, it is found then count += it->second
                  + finally return count

 */
#include <iostream>
#include <unordered_map>
#include <string>
class Solution{

public:
    int numJewelsInStones(const std::string& jewels, const  std::string& stones) {

        int count = 0;
        std::unordered_map<char, int> freq_stones;
        for (auto stone : stones){
            freq_stones[stone]++;
        }
        for(const auto& jewel : jewels ){
            auto it = freq_stones.find(jewel);
            // if the jewel is found
            if (it != freq_stones.end()){
                count += it->second;
            }
        }
        return count;

    }

};

int main() {
    std::cout << "Jewels and Stones" << std::endl;
    std::string jewels ="aA";
    std::string stones ="aAAbbbb";
    Solution s;
    std::cout<<s.numJewelsInStones(jewels, stones); // output 3 - correct

    //std::string jewels ="z";
    //std::string stones ="ZZ";
    //std::cout<<s.numJewelsInStones(jewels, stones); // output 0 - correct
    return 0;
}
