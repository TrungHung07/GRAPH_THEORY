#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

//input:
//danh sach ke:
/**
9 9 
1 2
1 3 
1 5
2 4
3 6
3 7
3 9
5 8
8 9
*/

//input cho do thi co huong: 
/** danh sach ke: 
9 10 
1 2
1 3 
1 5
2 4
3 6
3 7
3 9
5 8
6 7
8 9
9 3
*/



int nVer,nEdges;
vector<int> adj[1001];
bool bVisited[100];

void input_vo_huong()
{
    cin>>nVer>>nEdges;
    for(int i=0;i<nEdges;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(bVisited,false,sizeof(bVisited));//bVisited= {false};
}



void input_co_huong()
{
    cin>>nVer>>nEdges;
    for(int i=0;i<nEdges;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);//ke chi co mot huong
        // adj[y].push_back(x);
    }
    memset(bVisited,false,sizeof(bVisited));//bVisited={false};
}


void DFS(int x)
{
    cout<<x<<" , ";
    bVisited[x]=true;
    for(auto const &i:adj[x])//duyet danh sach ke cua x
    {
        if(!bVisited[i])//neu dinh do ma chua duoc tham thi goi de quy
        {
            DFS(i);
        }
    }
}



int main()
{
    // input_vo_huong();
    // DFS(1);//bat dau duyet sau tu dinh 1
    input_co_huong();
    DFS(1);
    return 0;
}