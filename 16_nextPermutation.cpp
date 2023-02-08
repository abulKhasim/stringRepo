// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// problem link: https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;

        for(k=n-2; k>=0; k--){
            if(nums[k] < nums[k+1])
                break;
        }

        if(k < 0){
            reverse(nums.begin(), nums.end());
        }else{
            for(l=n-1; l>k; l--){
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[k], nums[l]);
            int s = k+1, r = n-1;
            while(s <= r){
                swap(nums[s++], nums[r--]);
            }
        }
    }
};