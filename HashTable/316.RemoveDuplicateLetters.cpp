/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible 
results.
Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
*/

/* SOLUTION:  every letter appears once and only once -> we need to store all chars and their frequencies
-> hash table is good solution for that. unordered_map
- we traveser a given string s from left to right that means which char is visited should change from false to true, 
-> another map or unordered_map<char, bool> 
->whenever we meet a char in s (left to right)  we reduce its frequency, and check  if it is visited then continue to
because every char only can appear once and then add it to the stack if the stack is empty, else we should check
note that: we store the indeces of chars that are our result in the stack. if stack is not empty
then we should check  2 condition: whethever the current char is smaller in lexicographical order than char at s[st.top] 
if yes we check 2nd condition : its frequency is > 0, if no that means this char cannot meet in the further
LAST CHANCE to get this char now, hence we should add it to the stack. So if 2nd is satisdied that measn
its frequency is > 0, hence we can remove it from stack and should remark it is not visited(to get it in the future)
note that the proces too check whether stack is empty,  the current char is smaller in lexicographical order, and its frequency, in a loop (while)

for exmaple s = "bcabc" -> the result is "abc", 1st add b to stack, then add c to stack, then add a, but a <c, stack is not empty
 a < c and frequency of c is 1(from 2 to 1, reudce 1 once we meet it) that means we can meets c in the future
then st.pop() and remakr visited at c is false;
and keep check again a< b, st is not empty, frequency of b is 1, do the same-> add index of char 'a' in s to stack

last step: now we have a stack that contain indexces of the char we need, take them out and reverse it



*/

class Solution{
public:
    string removeDuplicateLetters(string s) {

        string ans = "";
        int m = s.size();
        unordered_map <char, int> char_freq;
        unordered_map <char, bool> visited;
        stack<char> st;

        // store chars and their frequency
        for(char c : s){
            char_freq[c]++;
        }

        // set all visited chars are false
        for(char c : s){
            visited[c] = false;
        }

        // traveser each char in s from left to right
        for(char curr_c: s){
            //reduce its frequency once we meet it
            char_freq[curr_c]--;
            // if the chars are repeated and adjacent
            if (visited[curr_c] == true) continue;

            
            //check 3 condition: whether a stack is empty and 2+ conditions
            while(!st.empty() &&  curr_c  < st.top() &&  char_freq[st.top() ] > 0){
               
                // remakr it is unvisited
                visited[st.top()] = false;
                //remove from stack
                st.pop();
            }
            st.emplace(curr_c);
            // cout<<st.top()<<" ";
           
            //mark it as visited
            visited[curr_c] = true;

        }
        //char are stored in stack now we need to reserve them to get its frequency
        // we can do ans  = st.top + ans; in the loop if st does not contain many elements
        // otherwise it is very slow, insted ans += st.top() and then reverse ans

        while(!st.empty()){
            //cout<<st.top()<<" ";
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    } 

};