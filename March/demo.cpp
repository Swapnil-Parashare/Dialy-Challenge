#include <iostream>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    query_row++;                          
    query_glass++;                          

    double v[101][101] = {0.0};             

    v[1][1] = poured;
    
    bool flag;
    
    for(int i = 1 ; i <= 99 ; i++)         
    {
        flag = true;
        for(int j = 1 ; j <= i ; j++)        
        {
            if(v[i][j] >= 1)                         
            {                                        
                v[i+1][j] += (v[i][j] - 1) / 2.0;      
                v[i+1][j+1] += (v[i][j] - 1) / 2.0; 
                v[i][j] = 1;  
                flag = false;
            }
        }
        if(flag == true){
            cout << "I am out " << endl;
            break;
        }
    }
    return v[query_row][query_glass];
}


int main()
{
    cout << champagneTower(100000009,33,17) << endl;
}

/*
100000009
33
17*/