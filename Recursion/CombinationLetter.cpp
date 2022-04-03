/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

'2' "abc"  '3' 'def' and so on
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

/*SOLUTION: using hash table to store  the digits and  their nums 
using back tracking algorithm to recur until the length of combination string == degits lenght
*/

#include <iostream>
#include<unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution{

    public:      
        
        unordered_map<char, string> keys = { {'2', "abc"}, {'3',"def"}, {'4',"ghi"}, {'5', "jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9',"wxyz"}  };
        vector<string> letterCombinations(string digits) {
            vector<string>ans;    

            combiBackTracking(dig, 0, "");
            return ans;

        } 
        void combiBackTracking(string dig, int sta, string combi){

            // to use backtracking algorithm, always put the cond to stop recursion

            if (combi != "" and combi.size() == dig.size()){  //(1)

                //cout<<" sta = "<<sta<<endl;  (*)
                ans.push_back(combi);
                return;// finish recursion 
                            
            }

            // combine the char from the number of digits, to do that we should access  our hash table via its key
            // digits ="23", digits[0] ==2 
            for (int i = 0; i < keys[dig[sta]]; ++i){

                combi += keys[digits[sta]][i]; // at i =0 combi = combi + "a"-> combi == a;
                combiBackTracking(dig, sta+1, combi);// (2)   // call itself and update sta =1 and update  combi ==a, cond (1) is NOT satisfied
                // now i = 0 again (recur) "a" = "a" + keys[digits[1]][0] -> combi = "ad"-> call itsself again, now cond (1) is satisfied
                // then ans push_back and return that means keep executing code lines below (2) 

                combi.pop_back(); // delete the last char in combi in order to add the new char, "ad" -> "a" and then increase i from 0 to 1
                // keep executing the code until finish the for loop
                // question: why sta cannot increase more than  digits length? if we use (*) we cann see that the sta number can be qually digits length (==2)
                // because when (1) is satisfied (sta+1 b4 that) but we pass the value not referecen and it only is a local var, when the program meets the retur;
                //  then this recursion is deleted and sta also is deleted and keep executing  code lines below (2) and sta == 1 for this recursion.

            }
        }




};
