#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int m,int E[][2],int workingNode,vector<int> *rez, int k){
    queue<int> q;
    vector<int> visited;
    vector<int>::iterator it;
    int adjMatrix[m][m];
    visited.push_back(workingNode);
for(int i=0; i<m;i++){
        for(int j=0; j<m;j++){
        adjMatrix[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
    adjMatrix[E[i][0]][E[i][1]]=1;
    }

    while(true){
    for(int i=0; i<m;i++)
    {
        if(adjMatrix[workingNode][i]==1)
            {
            it= find (visited.begin(), visited.end(), i);
                if(it== visited.end())
                {
                    q.push(i);
                    visited.push_back(i);
                }
            }
    }
workingNode = q.front();

if(q.size()==0){
    break;
}
q.pop();
    }
    for(int i=0; i<visited.size();i++){
        (*rez).push_back(visited[i]);
    }
}


int main()
{
    int m,k,f;
    cout<<"Insert number of nodes: ";
    cin>>m;
    cout<<"Insert number of verticies: ";
    cin>>k;
   // cout<<"Insert starting node: ";
   // cin>>f;
    f--;
    int E[k][2];
    for(int i=0;i<k;i++){
            cout<<"Insert "<<i+1<<" verticy: ";
        cin>>E[i][0]>>E[i][1];
    E[i][0]--;
    E[i][1]--;
    }

    for(int i=0; i<m;i++){
            vector <int> output;
        f=i;
         BFS(m,E,f,&output,k);
cout<<"Parent: "<<f+1;
for(int i=1; i<output.size();i++){
    cout<<" --> "<<output[i]+1;
}
cout<<endl;
    }

    return 0;
}

