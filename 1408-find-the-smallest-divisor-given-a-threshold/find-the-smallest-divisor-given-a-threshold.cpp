class Solution {
public:
    int SumOfD(vector<int> &arr,int div){
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(((long long)arr[i]+div-1)/(long long)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int t) {
        if(arr.size()>t) return -1;
        int low=1,high=*max_element(arr.begin(),arr.end());
        while(low<=high){
            int mid= low+(high-low)/2;
            if(SumOfD(arr,mid)<=t){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};