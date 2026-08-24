class Solution {
public:
    bool possible(vector<int>& arr,int day, int m, int k){
        int cnt=0, nob=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                nob+=(cnt/k);
                cnt=0;
            }
        }
        nob+=(cnt/k);
        return nob>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long val=m*1LL*k*1LL;
        int n=arr.size();
        if(val>n) return -1;
        int mini=INT_MAX , maxi=INT_MIN;;
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        int low=mini, high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};