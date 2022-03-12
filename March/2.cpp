// 392. Is Subsequence

#include <iostream>

using namespace std;

// Two Pointer Approach.

bool isSubsequence(string s, string t)
{
    int t_size = t.size();
    int s_size = s.size();
    
    if(s_size > t_size) return false;
    if(s_size == 0) return true;
    
    int j = 0;
    
    for(int i = 0 ; i < t_size  ; i++)
    {
        if(t[i] == s[j]) j++;
        if(j == s_size) return true;
    }
    
    return false;
}

int main()
{
    string s = "bdf";
    string t = "abcdefgh";
    cout << isSubsequence(s,t) << endl;
}