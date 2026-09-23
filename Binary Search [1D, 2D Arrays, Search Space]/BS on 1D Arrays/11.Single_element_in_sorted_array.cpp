#include <iostream>
#include <vector>
using namespace std;

// 540. Single Element in a Sorted Array
//Brute force

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {

//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             if (n == 1) {
//                 return nums[0];
//             }

//             if (i == 0) {

//                 if (nums[i] != nums[i + 1]) {
//                     return nums[i];
//                 }

//             }
//             else if (i == n - 1) {

//                 if (nums[i] != nums[i - 1]) {
//                     return nums[i];
//                 }

//             }
//             else {

//                 if (nums[i] != nums[i - 1] &&
//                     nums[i] != nums[i + 1]) {

//                     return nums[i];
//                 }
//             }
//         }

//         return -1;
//     }
// };

//Optimal solution

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {

                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << "Single element: "
         << obj.singleNonDuplicate(nums) << endl;

    return 0;
}