// 338. Counting Bits

#include<iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> vec(n+1,0);
    for(int i = 1 ; i <= n ; i++)
    {
        if(i%2 == 0) 
        {
            vec[i] = vec[i/2];
        }
        else
        {
            vec[i] = vec[i/2] + 1; 
        }
    }
    return vec;
}

/***** Helper *****/
void display(vector<int> vec)
{
    cout << endl;
    for(int i = 0 ; i< vec.size() ; i++)
    {
        cout << vec[i] << " " << endl;
    }
    cout << endl;
}

int main()
{
    int x;
    cout << "\nNUMBER : ";
    cin >> x;
    vector<int> answer = countBits(x);
    display(answer);
}