#include <bits/stdc++.h>
using namespace std;
int cost[15][15],stk[15],visited[15],i,j,k,n,m,top = 0,v,a,b;
int main()
{
    cout <<"Enter no of vertices : ";
    cin >> n;
    cout <<"Enter no of edges: " ;
    cin >> m;
    for(k=1; k<=m; k++)
    {
    	cout<<"Enter the "<<k<<" edge : ";
        cin >>i>>j;
        cost[i][j]=1;
        cost[j][i]=1;
    }
    cout<<"Adjacency Matrix Representation\n";
    cout<<"     ";
    for (a = 1; a <= n; a++)
    {
    	cout<<a<<"     ";
    }
    cout<<"\n";
    for (a = 1; a <= n; a++)
    {
    	cout<<a<<"    ";
        for (b = 1; b <= n; b++)
            cout<<cost[a][b]<<"     ";
        cout<<"\n";
    }
    cout <<"Enter initial vertex to traverse from : ";
    cin >>v;
    cout <<"DFS ORDER OF VISITED VERTICES : ";
    cout << v ;
    visited[v] = 1;
    for(k=1; k<n; k++)
    {
        for(j=n; j>=1; j--)
        {
        	if(cost[v][j] != 0 && visited[j] != 1)
            {
            	top++;
                stk[top]=j;
            }
		}
        v = stk[top];
        stk[top] = stk[top + 1];
        top--;
        cout<<" : "<<v;
        visited[v]=1;
    }
    return 0;
}
