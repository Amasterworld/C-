/*
You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

    Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    Align the substitution table with the regular English alphabet.
    Each letter in message is then substituted using the table.
    Spaces ' ' are transformed to themselves.

    For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"

 
*/

/*Solution: map the key to the a b c ... z then decode from the msg -> the what we need to see, from the above example
after mapping the key, v->t, k->h, b->i, s->s = this, note that if the 1st char was mapped hence the same char in key will keep, like 'o', 
->HASHTABLE is the best solution for this  kind of problem
*/
#include<iostream>
#include<unordered_map>
class Solution{
private:
    std::unordered_map<char, char> u_m;
public:
    std::string  decodeMessage(const std::string& key, const std::string& msg){
        std::string ans;
        int i = 0;
        char j = 'a';
        while (i < key.size()){
            // check if they key[i] is present in u_m or != " "  if no add
           
                if( key[i] != ' ' && u_m.count(key[i]) == 0 ){
                    u_m[key[i]] = j;   
                    i++;
                    j++;
                } //  if key[i] is present in the u_, then only i++, j does not change
                else{
                    i++;
                }
           
        }
         //decode 
        for (const auto& word_in_msg : msg){
            auto it = u_m.find(word_in_msg);
            if (word_in_msg == ' '){
                ans += ' ';
            } 
            else{
                ans += u_m[word_in_msg];
            }
        } 
    return ans;
    }

};

int main(){

    std::string key = "the quick brown fox jumps over the lazy dog";
    std::string msg = "vkbs bs t suepuv";

    Solution s;
    std::cout<< s.decodeMessage(key, msg)<<'\n'; // Output: this is a secret

}