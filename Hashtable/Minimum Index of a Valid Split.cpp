class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            map<int, int>mp;
            int countEnd = 0;
            int x = -1;
            for(int i=0; i<n; i++){
                mp[nums[i]]++;
                if(countEnd<mp[nums[i]]){
                    countEnd = mp[nums[i]];
                    x = nums[i];
                }
            }
            int j=0;
            int countStart=0;
            if(nums[0]==x){
                countStart++;
                countEnd--;
            }
            while(j<n-1){
                int startLen = j+1;
                int endLen = (n-j-1);
                if(countStart*2>startLen && countEnd*2>endLen){
                    return j;
                }
                j++;
                if(nums[j]==x){
                    countStart++;
                    countEnd--;
                }
            }
            return -1;
        }
    };