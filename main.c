#include <stdio.h>
#include <string.h>

void printArray(int* arr, int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i + 1 < size) printf(",");
    }
    printf("]");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1; // last index of nums1 valid element
    int j = n - 1; // last index of nums2
    int k = m + n - 1; // last index of nums1 (to start insert from)
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    // If nums2 still has elements, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    // Example 1
    int nums1_1[6] = {1,2,3,0,0,0};
    int nums2_1[3] = {2,5,6};
    int m1 = 3, n1 = 3;
    printf("Input: nums1 = ");
    printArray(nums1_1, 6);
    printf(", m = %d, nums2 = ", m1);
    printArray(nums2_1, 3);
    printf(", n = %d\n", n1);
    merge(nums1_1, 6, m1, nums2_1, 3, n1);
    printf("Output: ");
    printArray(nums1_1, 6);
    printf("\n");

    // Example 2
    int nums1_2[1] = {1};
    int nums2_2[1] = {}; // Empty array
    int m2 = 1, n2 = 0;
    printf("Input: nums1 = ");
    printArray(nums1_2, 1);
    printf(", m = %d, nums2 = ", m2);
    printArray(nums2_2, 0);
    printf(", n = %d\n", n2);
    merge(nums1_2, 1, m2, nums2_2, 0, n2);
    printf("Output: ");
    printArray(nums1_2, 1);
    printf("\n");

    // Example 3
    int nums1_3[1] = {0};
    int nums2_3[1] = {1};
    int m3 = 0, n3 = 1;
    printf("Input: nums1 = ");
    printArray(nums1_3, 1);
    printf(", m = %d, nums2 = ", m3);
    printArray(nums2_3, 1);
    printf(", n = %d\n", n3);
    merge(nums1_3, 1, m3, nums2_3, 1, n3);
    printf("Output: ");
    printArray(nums1_3, 1);
    printf("\n");

    return 0;
}
