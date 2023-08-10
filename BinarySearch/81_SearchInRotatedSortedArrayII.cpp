/*81_SearchInRotatedSortedArrayII
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

SOLUTION: this problem is almost the same problem 74, the only different is that: in this problem the  numbers
can be repeatable. Therefore, we still can use BS to solve this problem



*/
class Solution{
private:
    bool binarySearch(int r, int l, int mid, std::vector<int>& nums, int target){
        
        while(l<=r){

            mid = r + (l-r)/2;
            int val_mid = nums[mid];

            if(target == val_mid){
                return true;
            }

            else if (target < val_mid){
                r = mid -1;

            }

            else if (target > val_mid){
                l = mid +1;
                
            }
        }
        return false; 
    }
public:
    bool search(std::vector<int>& nums, int target){

        int m = nums.size();
        if(m == 1 && nums[0] == target){
            return true;
        }
        else if (m == 1 && nums[0] != target){
            return false;
        }

        int pivot{};
        // find the pivot
        for (int i = 1;i < m; ++i){
            if (nums[i] >= nums[i-1]){
                continue;
            }
            else{
                pivot = i;
            }
        }
        
        int l{}, r{}, mid{};
        if (pivot >= 1 && target >= nums[0] && target <= nums[pivot-1]){

            l = 0;
            r = pivot-1;
        }
        else if (target >= nums[pivot] && target <= nums[m-1]){
            l = pivot;
            r = m-1;
        }
        // from C++17, we can use lamda function to reduce the code lines
        if (binarySearch(r, l, mid, nums, target)){
            return true;
        }
        return false;
         
    }

};

// or use lambda function for searchBinary

class Solution{
private:

public:
    bool search(std::vector<int>& nums, int target){

        int m = nums.size();
        if(m == 1 && nums[0] == target){
            return true;
        }
        else if (m == 1 && nums[0] != target){
            return false;
        }

        int pivot{};
        // find the pivot
        for (int i = 1;i < m; ++i){
            if (nums[i] >= nums[i-1]){
                continue;
            }
            else{
                pivot = i;
            }
        }
        
        int l{}, r{}, mid{};
        if (pivot >= 1 && target >= nums[0] && target <= nums[pivot-1]){

            l = 0;
            r = pivot-1;
        }
        else if (target >= nums[pivot] && target <= nums[m-1]){
            l = pivot;
            r = m-1;
        }
        // from C++17, we can use lamda function to reduce the code lines


        std::function<bool() > binary_search;
        binary_search = [&]() -> bool {

            while(l<=r){

                mid = r + (l-r)/2;
                int val_mid = nums[mid];

                if(target == val_mid){
                    return true;
                }

                else if (target < val_mid){
                    r = mid -1;

                }

                else if (target > val_mid){
                    l = mid +1;
                    
                }
            }
            return false; 
        };

        if (binary_search()){
            return true;
        }
        return false;
         
    }

};
/*all solutions are tested in leetcode engine*/