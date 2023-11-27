/*write a program which takes as input an array and finds the distance between a closest pair if equal entries*/



#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main()  {

    vector<string> s ={"All", "work", "and" , "no", "play", "makes", "for", "no", "play", "makes", "work","no", "fun", "and", "no", "result"};
    unordered_map<string, int> letter;
    
     int min_dist = INT_MAX;
    for (int i = 0; i <s.size(); i++) {
        std::cout<<"s at i "<<s[i]<<'\n';
        auto near = letter.find(s[i]);
        if (near != letter.end()) {
            //cout<near->first<<endl;
            min_dist = min(min_dist, i - near->second);
            cout<<"her " <<min_dist <<endl;

        }
    letter[s[i]] = i;
    }

    for (const auto& [key, value] : letter){
        cout <<key<<" "<<value<<endl;


    }
    return 0;
}