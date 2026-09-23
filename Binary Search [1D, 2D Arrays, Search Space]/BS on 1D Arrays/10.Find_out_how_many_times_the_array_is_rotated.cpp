#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMinIndex(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {

            // Search space is already sorted
            if (arr[low] <= arr[high]) {

                if (arr[low] < ans) {
                    index = low;
                    ans = arr[low];
                }

                break;
            }

            int mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid]) {

                if (arr[low] < ans) {
                    index = low;
                    ans = arr[low];
                }

                low = mid + 1;
            }
            else {

                if (arr[mid] < ans) {
                    index = mid;
                    ans = arr[mid];
                }

                high = mid - 1;
            }
        }

        return index;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Number of rotations: "
         << obj.findMinIndex(arr) << endl;

    return 0;
}