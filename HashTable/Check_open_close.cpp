#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;


// remember the .find() member function only can search for the keys
bool checkString(const string& s){
unordered_map<char, char> sCheck = { {')', '('}, {']', '['}, {'}', '{'}};
stack<char> store_stack;
    for (int i = 0; i < s.length(); ++i){
        //cout <<s[i]<<" ";
        if (s[i] == '(' || s[i]  == '[' ||  s[i] == '{'){

            store_stack.push(s[i]);
            continue;

        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
            
            auto it = sCheck.find(s[i]);
            if (it != sCheck.end()){  // if it is found.
                cout<< it->second << " ";
            }
           
            if (it != sCheck.end() && store_stack.top() == it->second){
                
                store_stack.pop();
                
                continue;

            }
            else{
                //cout <<" unested ";
                return false;
            }
        }



    }
    return store_stack.empty();
}


int main(){
    
     string s = "([{}][]{})";
    //string s = "({}][]{})";
    
    cout <<checkString(s);

    




    return 0;
}
