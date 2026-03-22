class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        if(nums1.size()==1) return true;
        if(nums1.size()==2){
            if(nums1[0]%2==0 && nums1[1]%2==0) return true;
            else if(nums1[0]%2==1 && nums1[1]%2==1) return true;
            else if(nums1[0]%2==0 && nums1[1]%2==1) return false;
            else return true;
        }
        int e=0, o=0;
        for(auto it : nums1){
            if(it%2==0) e++;
            else o++;
        }
        if(e==nums1.size() || o==nums1.size()) return true;
        else if(nums1[0]%2==0) return false;
        else if(e<nums1.size()) return true;
        else return false;
    }
};