#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


//intput:
/**
10 11
1 2
1 3
1 5
1 10
2 4
3 6 
3 7 
3 9
6 7 
5 8 
8 9

*/



int ver,edge;//dinh va canh
vector<int> adj[1001];
bool visited[1001];

void nhap_vo_huong()
{
    cin>>ver>>edge;
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;//neu de bai cho danh sach ke
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}


//nếu đề bài cho danh sách kề của một đồ thị có hướng thì chỉ cần thay đổi hàm nhập 
void nhap_co_huong()
{
    cin>>ver>>edge;
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //do có hướng nên đỉnh x không thể là cạnh kề của đỉnh y (vì y nhập sau x)
    }
}


void BFS(int x)
{
    queue<int> q;//khởi tạo một hàng đợi rỗng
    q.push(x);//push đỉnh x vào hàng đợi
    visited[x]=true;//cho đỉnh x đã được thăm 
    while(!q.empty())//điều kiện dừng vòng lặp : hàng đợi rỗng (và cũng là lúc mảng visited full true value)
    {
        int v=q.front();//cho một biến v giữ lại giá trị của value đầu tiên trong hàng chờ
        q.pop();//lấy value đầu tiên trong hàng chờ ra
        cout<<v<<" ";
        for(auto const &i:adj[v])//duyệt vector danh sách kề
        {
            if(!visited[i])//nếu đỉnh kề thứ i của v mà chưa được thăm
            {
            q.push(i);//thì push i vào hàng đợi q 
            visited[i]=true;//đánh dấu là đã được thăm 
            }
        }
    }
    
}


int main()
{
    nhap_vo_huong();
    BFS(1);   
    return 0;
}