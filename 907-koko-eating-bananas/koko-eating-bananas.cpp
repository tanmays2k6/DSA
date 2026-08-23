class Solution {
public:
    int findMax(vector<int> &v){
        int maxi=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }

    long long calcTotalHours(vector<int>&v,int hourly){
        long long totalH=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            totalH+=ceil(((long long)v[i]+hourly-1)/hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low=1 , high=findMax(v);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalH=calcTotalHours(v,mid);
            if(totalH<=h){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};