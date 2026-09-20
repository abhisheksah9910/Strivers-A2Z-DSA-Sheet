#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size() - 1;
        int low = 0;
        int high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 7;

    int result = obj.search(nums, target);

    cout << "Target index: " << result << endl;

    return 0;
}