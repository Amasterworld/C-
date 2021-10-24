#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

 vector<vector<int> > threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int> > ans;
   // if(n<3) return []; //easy way out
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
    //check for duplicates in choosing the first element
        if(i>0 and nums[i-1]==nums[i])continue;
        int l=i+1; // l = left
        int r=n-1; // r = right,  n = size of the nums, n-1 = last index
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r]; // sum at i and at i+1 and at last index 
                if(sum==0){
                ans.push_back({nums[i],nums[l],nums[r]});
                l++; // increase l
                r--; // decease r  --> they are calculating  -->      <-- from two sides of the array
    //check for duplicates in the next two supporting elements
                    while(l < r && nums[l] == nums[l-1] && nums[r] == nums[r+1]){
                        l++;
                        r--;
                    }
                }               
                else if(sum>0)r--;
                else l++ ;
        }
    }
    return ans;
}

int main (){

  vector<int> nums = {2, -1, -4, -1, 0, 1, 3};
  vector<vector<int> > temp = threeSum(nums);
  for (int i = 0; i < temp.size(); i++) {
        for ( auto it = temp[i].begin(); it != temp[i].end(); ++it) 
            cout << *it << " ";
        cout << endl;
    }
  return 0;
}