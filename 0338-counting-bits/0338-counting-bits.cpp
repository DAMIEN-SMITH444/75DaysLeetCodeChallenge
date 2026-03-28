class Solution {
public:
    vector<int> countBits(int n) {
        int k = n+1;
        vector<int>v(k);
        for(int i = 0 ; i < k ; i++){
            // v[i] = __builtin_popcount(i);
            int cnt = 0;
            int temp = i;
            while(temp != 0){
                cnt += (temp & 1);
                temp = temp >> 1;
            }
            v[i] = cnt;
        }
        return v;
    }
};