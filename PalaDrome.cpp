/* Check a given string can form Paladrome
Paladrome string is a string that can be the same even they are written forwards or backwards.
for example s = "GATATG" shoud return true because s can be seen as s = "GATTAG" and now if you write forwards or backwards  they are the same even they are written forwards
or s = "eudde" also return true because s = "edude" 
but s = "GATTATGG" -> return false
*/


/*
SOULTION: we can easily see that the s can be Paladrome if the char_frequency in s should be even. Except in case, if char_frequency is odd, it must be ONLY ONE character.

-->  the both conditions above can be covered if at most one char has a frequency of appear is odd
*/
// we should store the string and check their frequencies --> hash table is the best

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
bool CanFormPaladrome(const string& s)  {

    unordered_map<char, int> char_frequency;
    for (int i = 0; i < s.length(); ++i){
        
        char_frequency[s[i]]++;



    }
    int count = 0;
    for (auto const& [key,value]: char_frequency){
        cout << key<<" "<< value <<endl;
        if (value%2 != 0) count++;


    }
    cout <<count<< endl;
    return count>1? false: true;
}

int main(){
    string s = "GATATTGG";

    cout<< CanFormPaladrome(s);



    return 0;
}
