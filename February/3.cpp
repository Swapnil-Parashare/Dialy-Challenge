#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int,int> map ;
    int counter = 0;
    int key;
    int find;

    for(int i = 0 ; i < nums1.size() ; i++)
    {
        for(int j = 0 ; j < nums2.size() ; j++)
        {
            key = nums1[i] + nums2[j];                          // All the sums which are possible are our keys.j
            if( map.find(key) == map.end() )
            {
                map.insert({key,1});
            }
            else
            {
                map[key] = map[key] + 1;
            }
        }
    }

    for(int i = 0 ; i < nums3.size() ; i++)
    {
        for(int j = 0 ; j < nums4.size() ; j++)
        {
            key = nums3[i] + nums4[j];
            if(map.find(-key) != map.end())
            {
                counter += map.at(-key);
            }
        }
    }
    return counter;
}

int main()
{
    
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    cout << fourSumCount(nums1,nums2,nums3,nums4) << endl;





}
