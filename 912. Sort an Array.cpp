class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r) {
        int i = l, j = mid + 1, k = l;
        int B[r + 1];

        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                B[k] = nums[i];
                i++;
            }
            else {
                B[k] = nums[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            B[k] = nums[i];
            i++, k++;
        }
        while (j <= r) {
            B[k] = nums[j];
            j++, k++;
        }

        for (int m = l; m <= r; m++) nums[m] = B[m];
    }
    void mergeSort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
