#include <iostream>

using namespace std;


// Here we are just doing Level Order Traversal 

// Simple 2D Vector Approach to Traverse over the Triangle (Tree) . We will do Level order traversal.

double champagneTower_1(int poured, int query_row, int query_glass)
{
    query_row++;                            // My rows are indexed from 1.
    query_glass++;                          // My glasses are indexed from 1.

    double v[101][101] = {0.0};             // v[Row Number][Glass Number] = Quantity of champene it contains.    Note : Maximum Quantity that glass can contain is 1 Unit.
                                            // Total 100 Rows, we want 100 as a index because our index starts from 1. Hence size is 101.                        
                                        
    v[1][1] = poured;                       // Start with avialable capacity from first glass.

    for(int i = 1 ; i <= 99 ; i++)                    // Iterating through Rows. Note : When we are iterating over 99th row, 100th row will get initialized.
    {
        for(int j = 1 ; j <= i ; j++)                 // Iterating over the glasses of current row. Note : Row Number = Number of glasses it contains.
        {
            if(v[i][j] > 1)                           // Only the glass which contain champene more than 1 unit will overflow.
            {                                         // Remaining quantity will be split over below two glasses.
                v[i+1][j] += (v[i][j] - 1) / 2.0;     // Left Glass below current glass
                v[i+1][j+1] += (v[i][j] - 1) / 2.0;   // Right Glass below current glass.
                v[i][j] = 1;                          // Current glass will contain 1 unit.
            }
        }
    }
    return v[query_row][query_glass];
}

// Using 'flag' to avoid unneccessary iteration.

double champagneTower_2(int poured, int query_row, int query_glass)
{
    query_row++;                            // My rows are indexed from 1.
    query_glass++;                          // My glasses are indexed from 1.

    double v[101][101] = {0.0};             // v[Row Number][Glass Number] = Quantity of champene it contains.    Note : Maximum Quantity that glass can contain is 1 Unit.
                                            // Total 100 Rows, we want 100 as a index because our index starts from 1. Hence size is 101.                        
    
    v[1][1] = poured;                       // Start with avialable capacity from 1st glass.

    bool flag;

    for(int i = 1 ; i <= 99 ; i++)                    // Iterating through Rows. Note : When we are iterating over 99th row, 100th row will get initialized.
    {
        flag = true;
        for(int j = 1 ; j <= i ; j++)                 // Iterating over the glasses of the current row. Note : Row Number = Number of glasses it contains.
        {
            if(v[i][j] > 1)                           // Only the glass which contain champene more than 1 unit will overflow.
            {                                         // Remaining quantity will be split over below two glasses.
                v[i+1][j] += (v[i][j] - 1) / 2.0;     // Left Glass below current glass
                v[i+1][j+1] += (v[i][j] - 1) / 2.0;   // Right Glass below current glass.
                v[i][j] = 1;                          // Current glass will contain 1 unit.
                flag = false;
            }
        }
        if(flag == true) break;                       // If our current row has all the glasses less than or equal to 1 unit then no overflow will happen, hence no need to initialize below rows, so simply break the loop.
    }                                                 // All the below rows contains 0.0 with which we have intialized our 2D matrix intially.
    return v[query_row][query_glass];
}






int main()
{
    cout << champagneTower_2(212,33,17) << endl;
    
}