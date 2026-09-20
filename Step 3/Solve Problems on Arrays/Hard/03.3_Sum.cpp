/*
============================================================
Problem: 3Sum
Platform: LeetCode 15
Topic: Arrays | Sorting | Two Pointers
============================================================

Problem Statement:
Given an integer array nums, return all unique triplets
[nums[i], nums[j], nums[k]] such that:

nums[i] + nums[j] + nums[k] = 0

The solution set must not contain duplicate triplets.

------------------------------------------------------------
Approaches:

1. Brute Force
   - Generate every possible triplet using three loops.
   - Sort each valid triplet and store it in a set to
     remove duplicates.

   Time Complexity : O(n³ × log M)
   Space Complexity: O(M)

   (M = Number of unique triplets)

------------------------------------------------------------
2. Optimal Approach (Sorting + Two Pointers)

Step 1:
Sort the array.

Step 2:
Fix one element (i).

Step 3:
Use two pointers:
- left = i + 1
- right = n - 1

Step 4:
Calculate:
sum = nums[i] + nums[left] + nums[right]

- If sum == 0:
    Store the triplet.
    Move both pointers.
    Skip duplicate values.

- If sum < 0:
    Increase left pointer.

- If sum > 0:
    Decrease right pointer.

Duplicate Handling:
- Skip duplicate values for the fixed element.
- Skip duplicate values after finding a valid triplet.

------------------------------------------------------------
Example:

Input:
nums = [-1,0,1,2,-1,-4]

Sorted:
[-4,-1,-1,0,1,2]

Output:
[-1,-1,2]
[-1,0,1]

------------------------------------------------------------
Why Sorting?

Sorting allows us to:
✔ Use the two-pointer technique.
✔ Skip duplicate values efficiently.
✔ Reduce the complexity from O(n³) to O(n²).

------------------------------------------------------------
Complexity:

Brute Force
Time  : O(n³)
Space : O(M)

Optimal Approach
Time  : O(n²)
Space : O(1)      // Ignoring the output array

============================================================
*/

#include<bits/stdc++.h>
using namespace std;

            //Brute Force

// int main(){
//     vector<int> nums{-1,0,1,2,-1,-4};
//     int n = nums.size();
//     set<vector<int>> st;

//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 if(nums[i] + nums[j] + nums[k] == 0){
//                     vector<int> temp{nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }

//     for(auto it : st){
//         for(int x : it){
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }

            //Optimal Approach (Sorting + Two Pointers)

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++){
        if(nums[i] > 0){
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        int j = i + 1;
        int k = n - 1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while(j < k && nums[j] == nums[j - 1]){
                    j++;
                }

                while(j < k && nums[k] == nums[k + 1]){
                    k--;
                }
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }

    for(auto it : ans){
        for(int x : it){
            cout << x << " ";
        }
        cout << endl;
    }
}