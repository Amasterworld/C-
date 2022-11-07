/*1323. Maximum 69 Number

You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
*/

/*SOLUTION: this problem is very simple, if we convert it to the string ans then traverse it from left to right, if meets '9' continue, else num_in_string[i] = '9'
break; then convert one time from string to int and return;

now the question is: can we SOLVE this problem WITHOUT converting to string, yes we can use module % to get the remainder number + tracking index, if it is 9 hence keep /10 whe 
else get its index. At the end if we do not get any number 6 in reminder hence return the original num, else the new num after repleace 6 by 

HOW to get the new num? for example 9669 -> output 9969, 9969 - 9669 = 300 = 3* 10^(index of the last number six, from right to left), in this example it is 3
then have: 

  return  reminder == -1 ? num : num+3*(10^index)


*/
#include<iostream>
#include<math.h> // for using pow method
class Solution{

public:
    int maximum69Number(int num){

        int clone_num = num;
        int track_idx_six = -1;
        int curr_idx = 0;
        while(clone_num > 0){
                                   
            if(clone_num %10 == 6){
                
                track_idx_six = curr_idx;
            }
            clone_num /= 10;
            curr_idx++;
        }

        /*after checking all the reminder number of num if track_idx_six == -1 hence we return the original num */

        return track_idx_six == -1 ? num : num+(9-6)*pow(10, track_idx_six);
    }

};

int main(){

    int num = 9669;
    Solution s;
    std::cout<<"The maximum number after replacing at most number from 6 to 9 is " <<s.maximum69Number(num)<<'\n';

}
