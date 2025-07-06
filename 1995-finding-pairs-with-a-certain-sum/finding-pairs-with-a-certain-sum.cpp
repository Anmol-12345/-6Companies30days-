class FindSumPairs {
public:
//first we have to seprate the nums1 and nums2
//so take two array
vector<int>vec1;
vector<int>vec2;

unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;

        for(int i =0;i<vec2.size();i++)
        {
            mp[vec2[i]]++;
        } 
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c =0;
        for(auto&i:vec1)
        {
            c += mp[tot-i];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */