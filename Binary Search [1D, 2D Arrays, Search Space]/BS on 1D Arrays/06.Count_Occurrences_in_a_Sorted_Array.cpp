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

    int countOccurrences(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target);

        return last - first;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int result = obj.countOccurrences(nums, target);

    cout << "Occurrences: " << result << endl;

    return 0;
}