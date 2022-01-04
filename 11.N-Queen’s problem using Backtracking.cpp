#include <bits/stdc++.h>
using namespace std;
int n, B[15][15];
bool isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (B[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (B[i][j])
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (B[i][j])
            return false;
    }
 
    return true;
}
bool solve(int col)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if ( isSafe(i, col) )
        {
            B[i][col] = 1;
            if (solve(col + 1) == true)
                return true;
            B[i][col] = 0;
        }
    }
    return false;
}
int main()
{
	cout<<"Enter a number : ";
	cin>>n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
        		B[i][j] = 0;
	bool result;
	result = solve(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
            		cout<<B[i][j]<<"   ";
		}
        	cout<<endl;
    	}
    if(result == false)
    	cout<<"FAIL";
    else
    	cout<<"PASS";
    return 0;
}
