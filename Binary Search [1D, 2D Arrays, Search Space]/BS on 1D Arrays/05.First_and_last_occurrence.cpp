#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        return {first, last};
    }
};

int main() {
    Solution obj;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = obj.searchRange(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}