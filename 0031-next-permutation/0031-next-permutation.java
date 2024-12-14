class Solution {
    public static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int breakpoint = 0;
        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                breakpoint = i - 1;
                break;
            }
            if(i == 1){
                reverseArray(nums);
                return;
            }
        }
        int index_replaced = 0;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[breakpoint]){
                index_replaced = i;
                break;
            }
        }
        int temp = nums[breakpoint];
        nums[breakpoint] = nums[index_replaced];
        nums[index_replaced] = temp;
        Arrays.sort(nums, breakpoint + 1, n);
        return;
    }
}