
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map <int, int> myMap;



vector<int> twoSum(vector<int>& nums, int target){
        vector<int> result;
    for(int i= 0; i < nums.size(); i++){
    
        auto it = myMap.find(nums[i]);   // compare with specific KEY in myMap
            if (it != myMap.end()) { // if found it, hence its value is its index
                
                    //cout<<it->second<<" "<<i<<endl;
                    result.push_back(it->second);
                    result.push_back(i);
                    
            
            
                
            }
        // store the value of vector num in key (for comparing propose) 
        // and store its index to value (for taking late)
        myMap[ target - nums[i]] = i;
        
        }
        
        
    
  return result; 
}

int main(){
vector<int> num = {-3,4,3,90};
int target = 0;
cout <<twoSum(num, target)[0]<< twoSum(num, target)[2];


}