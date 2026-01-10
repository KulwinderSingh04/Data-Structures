public class Solution {
    public void NextPermutation(int[] nums) {
        int n = nums.Length;
        int pivot = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        if(pivot == -1) {
            Array.Reverse(nums);
            return;
        }
        Array.Reverse(nums, pivot + 1, n - pivot - 1);
        int idx = -1;
        for(int i = pivot + 1; i < n; i++) {
            if(nums[i] > nums[pivot]) {
                (nums[i], nums[pivot]) = (nums[pivot], nums[i]);
                return;
            }
        }

    }
}