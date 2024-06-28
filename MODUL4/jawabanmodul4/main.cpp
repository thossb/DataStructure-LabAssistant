#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[101];
int visited[101];

void DFS(int i)
{
    visited[i] = true;
    for(int j = 0; j < adjList[i].size(); j++)
    {
        int vertex = adjList[i][j];
        if(!visited[vertex])
        {
            DFS(vertex);
        }
    }
}

int main(void)
{
//    ios_base::sync_with_stdio(false); // unsynchronizing stream
//    cin.tie(NULL);                    // untying cin and cout - speeds up the execution time
//    cout.tie(NULL);

    int V, N;
    int A, B;
    int connectedgraf = 0;

    cin >> V >> N;
    for(int i = 0; i <= V; i++)
    {
        visited[i] = 0;
    }
    for(int i = 0; i < N; i++)
    {
        cin >> A >> B;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }
    for(int i = 1; i <= V; i++)
    {
        if(!visited[i])
        {
            DFS(i);
            connectedgraf++;
        }
    }
    connectedgraf -= 1;

    cout << connectedgraf << endl;

    return 0;
}
