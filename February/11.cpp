    // 567. Permutation in String

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/******************************** Refere to 2.cpp :  " 438. Find All Anagrams in a String " ***************************************/


//Brute Force Approach.

bool isAnagram(string s1, string s2)
{
    if(s1.size() != s2.size()) return false;

    unordered_map< char, int > map;
    unordered_map<char,int> :: iterator itr;

    for(int i = 0 ; i < s1.size() ; i++)
    {
        map[s1[i]]++;
        map[s2[i]]--;
    }

    for(itr = map.begin() ; itr != map.end() ; itr++)
    {
        if(itr->second) return false;
    }

    return true;
}

bool checkInclusion_1(string s1, string s2)
{
        
        int s1_size = s1.size();
        int s2_size = s2.size();
            
        string substring_s2 = "";
        
        for(int i = 0 ; i <= s2_size - s1_size ; i++)
        {
            substring_s2 = s2.substr(i,s1_size);
            if(isAnagram(substring_s2,s1)) return true;
        }
        
        return false;
        
        
}

// Window Sliding Approach.

bool checkInclusion(string s1, string s2)
{
    int left = 0;
    int right = 0;
    int windowSize = s1.size();
    int stringSize = s2.size();
    vector<int> targetHash(26,0);
    vector<int> currentHash(26,0);

    if(windowSize > stringSize) return false;


    while(right < windowSize)
    {
        currentHash[ s2[right] - 'a' ] += 1;                        // Generating very first window.
        targetHash[ s1[right] - 'a' ] += 1;                         // Generating our target hash which will remain constant throughout.
        right++;
    }

    right--;

    while(right < stringSize)
    {
        if(currentHash == targetHash) return true;

        // Generating new window (i.e Sliding to next window)

        right++;                                                            // Moving right pointer.
        if(right != stringSize) currentHash[ s2[right] - 'a' ] += 1;        // Adding new character to hash.
        currentHash[ s2[left] - 'a' ] -= 1;                                 // Removing the old leftmost character from hash.
        left++;                                                             // Moving left pointer
    
        // New window created successfully.
    }
    return false;
}

int main()
{
    return 0;
}