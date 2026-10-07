class Solution {
public:
    int subarr(vector<int>& nums, int k){
        int l=0, r=0, cnt=0;
        unordered_map <int,int> mpp;

        while(r< nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l=l+1;
            }
        cnt=cnt+(r-l+1);
        r=r+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarr(nums,k) - subarr(nums,k-1);
    }
};