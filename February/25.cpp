#include <iostream>
#include<algorithm>
#include<sstream>

using namespace std;

    int compareVersion(string version1, string version2)
     {
        
        
        int d1 = count(version1.begin(), version1.end(), '.');
        int d2 = count(version2.begin(), version2.end(), '.');
        
        int revisions = (d1 >= d2) ? d1 + 1 : d2 +1;
        
        int difference = abs(d1-d2);
        
        
        if(d1 < d2)
        {
            while(difference)
            {
                version1 += ".0";
                difference--;
            }
        }
        else if( d2 < d1)
        {
            while(difference)
            {
                version2 += ".0";
            }
        }
        
        
        replace(version1.begin(), version1.end(), '.',' ');
        replace(version2.begin(), version2.end(), '.',' ');        
        
        stringstream v1(version1);
        stringstream v2(version2);
        
        int temp1,temp2;
        while(revisions)
        {   
            v1 >> temp1;
            v2 >> temp2;
            if(temp1 < temp2) return -1;
            else if (temp1 > temp2) return 1;
            revisions--;
        }
        return 0;
             
    }

int main()
{
    string version1 = "1.01";
    string version2 = "1.001";

    cout << compareVersion(version1,version2);
}