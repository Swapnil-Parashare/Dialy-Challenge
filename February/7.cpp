#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


/******************************************************     Using Maps      *******************************************************************/

char findTheDifference_1(string s, string t)
{
    unordered_map<char,int> map;

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(map.find(s[i]) != map.end())                                 // If key(char) exist, increase its value by 1.
        {
            map[s[i]] = map[s[i]] + 1;
        }
        else                                                            // If key(char) does not exist, put key(char) and makes its initial value 1.
        {
            map.insert(make_pair(s[i],1));
        }
    }

    for(int i = 0 ; i < t.size() ; i++)
    {
        if(map.find(t[i]) == map.end())                                 // If key does not exist, return the 'char'.
        {
            return t[i];
        } 
        else if(map[t[i]] == 0)                                         // If key exists, but its value is 0, return the 'char'.
        {
            return t[i]; 
        }
        else
        {
            map[t[i]] = map[t[i]] - 1;                                  // If key exists with non-zero value, decrease its value by 1.
        }
    }

    return (char)0;
}
/*

1] unordered_map.insert(make_pair(key,value)); ---------> This syntax works only if 'key' does not exist previously.
2] If key exists previously then, its value is not modified.

*/

/*********************************************   Just return difference in their sum     ********************************************************/

int sum(string s)
    {
        int temp = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            temp += (int)s[i];
        }
        return temp;
    }
    
char findTheDifference_2(string s, string t)
{
    return (char)(sum(t)-sum(s));
}

/*************************************  Sorting and Comparing   ***************************************************************************/

char findTheDifference_3(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i;
    for(i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != t[i]) return t[i];
    }
    return t[i];

}

/**********************************    Bit Manipulation (XOR operation)  **********************************************************************/

// Bit Manipulation (XOR operation)
char findTheDifference(string s, string t)
{
    char x = '\000';
    for(int i = 0 ; i < s.size() ; i++)
    {
        x = x ^ s[i];
    }
    for(int i = 0 ; i < t.size() ; i++)
    {
        x = x ^ t[i];
    }
    return x;
}




/*
IMP:-
    char x = 0;
    char x = '\000';

    Both the above statement are same. '\000' is the NULL character. 
    In character we inintialize the character as null in this way.

    A] XOR with NULL character.
    1] 'char' ^ '\000' = 'char' 
    2] 'char' ^ 'char'= '\000'  

a) XOR of a character with itself is '\000'. 
b) XOR of a character with '\000' is character itself.
Example : s = abc , t=abcd
Now answer = '\000' ^ a ^ b ^ c ^ a ^ b ^ c ^ d;          Now here the same characters will cancel each other due to XOR operation.
So only one extra letter will be left, which will be returned.
*/

int main()
{
    string s = "a";
    string t = "aa";

    cout << findTheDifference_2(s,t) << endl;

}