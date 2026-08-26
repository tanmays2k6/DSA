class Solution {
public:
    int countS(vector<int>&arr,int p){
        int s=1;
        long long ps=0;
        for(int i=0;i<arr.size();i++){
            if(ps+arr[i]<=p){
                ps+=arr[i];
            }else{
                s+=1;
                ps=arr[i];
            }
        }
        return s;

    }
    
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;
            int s=countS(arr,mid);
            if(s>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
        
    }
};