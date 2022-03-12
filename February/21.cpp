// 169. Majority Element.

#include <iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>                  // For sort() function.

using namespace std;


// Using Hashmap.

int majorityElement_1(vector<int>& nums)
{
    int size = nums.size();
    unordered_map<int, int> map;
    unordered_map<int,int> :: iterator itr;
    for(int i = 0 ; i < size ; i++)
    {
        map[nums[i]]++;
    }

    for(itr = map.begin() ; itr != map.end() ; itr++)
    {
        if(itr->second > size/2)
        return itr->first;
    }

    return 0;
}

// Using Sorting

int majorityElement(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}


int main()
{
    vector<int> input = {2,2,2,1,1,2,2};
}