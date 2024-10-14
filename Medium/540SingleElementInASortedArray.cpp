class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0]; //Single Array

        int st = 0;
        int end = n - 1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid]; //Start Answer
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid]; //End Answer

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid]; //Mid Answer

            if(mid % 2 == 0){ //Even Array
                if(nums[mid-1] == nums[mid]){
                    end = mid - 1;
                } else{
                    st = mid + 1;
                }
            } else{ // Odd Array
                if(nums[mid-1] == nums[mid]){
                    st = mid + 1;
                } else{
                    end = mid - 1;
                }
            }
        } 
        return -1;
        
    }
};