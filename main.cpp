#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < nums2.size(); i++) {
            nums1[m] = nums2[i];
            m++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    cout << "Input: nums1 = ";
    printVector(nums1);
    cout << ", m = " << m << ", nums2 = ";
    printVector(nums2);
    cout << ", n = " << n << endl;
    sol.merge(nums1, m, nums2, n);
    cout << "Output: ";
    printVector(nums1);
    cout << endl;

    // Example 2
    nums1 = {1};
    m = 1;
    nums2 = {};
    n = 0;
    cout << "Input: nums1 = ";
    printVector(nums1);
    cout << ", m = " << m << ", nums2 = ";
    printVector(nums2);
    cout << ", n = " << n << endl;
    sol.merge(nums1, m, nums2, n);
    cout << "Output: ";
    printVector(nums1);
    cout << endl;

    // Example 3
    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    cout << "Input: nums1 = ";
    printVector(nums1);
    cout << ", m = " << m << ", nums2 = ";
    printVector(nums2);
    cout << ", n = " << n << endl;
    sol.merge(nums1, m, nums2, n);
    cout << "Output: ";
    printVector(nums1);
    cout << endl;

    return 0;
}
