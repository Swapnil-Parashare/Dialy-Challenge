#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findPairs(vector<int>& nums, int k)
{
    int count = 0;
    unordered_map<int,int> map;

    for(int i = 0 ; i < nums.size() ; i++)                                              // Inserting vector in a map.
    {
        if(map.find(nums[i]) == map.end()) map.insert(make_pair(nums[i],1));
        else map[nums[i]] += 1;
    }

    if( k == 0)                                                                        // If required difference is 0.
    {
        for(auto i : map)
        {
            if(i.second > 1) count ++;
        }
        return count;
    }

    for(auto i : map)                                                                  // If required difference is other than 0.
    {
        if(map.find(i.first+k) != map.end()) count++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,3,1,5,4};
    cout << findPairs(nums,0) << endl;
}