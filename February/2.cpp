/* 438. Find All Anagrams in a String */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



/***************************************************   Given two strings are anagram or not.   ************************************************************

Anagram : 1]If one string can be formed by rearranging the letters in other string, then they both are anagram of each other.
          2]Size of both the strings must be same.

/* 1st Method : Sort Strings

Logic : 1] Sort Both Strings.
        2] Compare the Sorted Strings.

*/
bool isAnagram_1(string s, string p)
{
    int s_size = s.length();
    int p_size = p.length();

    if(s_size != p_size) return false;

    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    for(int i = 0 ; i < s_size ; i++)
    {
        if (s[i] != p[i])
        {
            return false;
        }
    }
    return true;
}





/* 2nd Method : Count Characters.

Logic :
1] Strings contains lowercase english letters only.
2] Hence create a integer vector of size 26. Were  indexing in done in this way  0 1 2 3 4 5 6 . . . . . 24 25 
                                                                                 a b c d e f g . . . . .  y z
3] For 1st string increment the counter for respective letter. 
   For 2nd string decrement the counter for respective letter.
4] At last if vectors each element is 0, then they are anagram, otherwise they are not.
*/

bool isAnagram_2(string str1, string str2)
{
    if(str1.size() != str2.size()) return false;

    vector<int> tracker(26,0);
    for(int i = 0 ; i < str1.size() ; i++)
    {
        tracker[str1[i] - 'a']++;        // Suppose character is 'd' then 'd' - 'a' = 100 - 97 = 3
        tracker[str2[i] - 'a']--;
    }

    for(int i = 0 ; i < 26 ; i++)
    {
        if(tracker[i]) return false;
    }

    return true;
}




/*
Method 3 : Map.

Concept : 1] Map is a collection of Key:Value pairs.
          2] It allows fast access to a value using key.
          3] Map ensures that all keys are unique.

Logic : 
        1] Create a map, and put string 1 into the map, with character as key and its count as value.
        2] While iterating over string 2, decrease the count for each character.
        3] At last if all the values are 0, then its a Anagram otherwise not.
*/

bool isAnagram_3(string str1, string str2)
{
    int str1Size = str1.size();
    int str2Size = str2.size();
    if (str1Size != str2Size) return false;

    unordered_map<char,int> tracker;
    unordered_map<char,int> :: iterator itr;

    for(int i = 0 ; i < str1Size ; i++)
    {
        tracker.insert(pair<char, int>(str1[i],tracker[ str1[i] ]++));
        tracker[ str2[i] ]--;
    }

    for(itr = tracker.begin() ; itr != tracker.end() ; itr++)
    {
        if(itr->second != 0) return false;
    }

    return true;

}

/****************************************************************************************************************************************************/

vector<int> findAnagrams_1(string s, string p)                       // Brute Force
{
    vector<int> answer;
    int s_size = s.size();
    int p_size = p.size();
    string substring_s = "";

    for(int i = 0 ; i <= s_size - p_size ; i++)
    {
        substring_s = s.substr(i, p_size);
        if(isAnagram_3(substring_s, p))
        {
            answer.push_back(i);
        }
    }
    return answer;
}

/*
Inspite of trying all 3 methods to check wheather given two strings are anagram or not, I am getting TLE on Leetcode.
Hence I need to change the main logic of the problem.

/********************************************************************************************************************************/

// Sliding Window Approach

/*
Logic : 1] If two words are Anagram means in both words, "Same letters are occuring same number of times".
        2] Hence we can calculate "Hash" of words, if Hash is same then they are Anagram otherwise not.
        3] A word can have maximum 26 letters and any letter can occur either zero or single or multiple times.
        4] Example ---> parashare : 3 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 2 1 0 0 0 0 0 0 0 
                                    a b c d e f g h i j k l m n o p q r s t u v w x y z 

Let it sink in -----> 1] Hash length is not equal to length of the string. 
                      2] String length can be anything, 100, 500, 1000 etc.
                      3] Hash lenght is equal to the all the possible letters that can occur in the string. (which is 26)
                      4] And the frequency of letter, how many times it has occured in the string, it is our Hash's value.

*/                    

vector<int> findAnagrams_2(string s, string p)
{
    vector<int> answer;
    int window_size = p.size();
    int string_size = s.size();
    int left = 0;                                             // It will point the left end of the window
    int right = 0;                                            // It will point the right end of the window
    vector<int> target_hash(26,0);
    vector<int> current_hash(26,0);

    if(string_size < window_size) return answer;

    while(right < window_size)
    {
        current_hash[ s[right] - 'a' ]+=1;                    // Forming our 1st window. (We will slide it in future)
        target_hash[ p[right] - 'a']+=1;                      // Also calculting our target hash.
        right++;
    }   
    right--;                                                // Now 'right' is present at the ending point of our window.

    while(right < string_size)                              // Sliding the window --> Updating Current Hash on fly --> Comparing it with Target Hash --> Updating 'answer'(if required)
    {
        if(current_hash == target_hash) 
           answer.push_back(left);

        right++;                                           // 1]Move the Right Pointer.
        if(right != string_size)
           current_hash[ s[right] - 'a' ]+=1;               // 2]Update the hash for latest character.
        current_hash[s[left] - 'a']-=1;                     // 3]Discard the change for 'left' pointer.
        left++;                                            // 4]Move the Left Pointer. 
                                                           // Thus "Window" is slided successfully !!!                                                       
    }  
    return answer;
}







/**********************************************************************************************************************************/
int main()
{
    string s = "abab";
    string p = "ab";

    vector<int> answer = findAnagrams_2(s,p);

    for(int i = 0 ; i < answer.size() ; i++)
    {
        cout << answer[i] << " ";
    }
}