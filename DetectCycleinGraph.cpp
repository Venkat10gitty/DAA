#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
using namespace std;
class graph
{
    int v;
    list<int> *adjacencylist;
    bool checkcycle2(int v, bool vertvisited[], bool *recursionst);
    public:
    graph(int v);
    void drawedge(int v, int u);
    bool checkcycle();
};
graph::graph(int v)
{
    this->v=v;
    adjacencylist= new list<int>[v];
}
void graph::drawedge(int v, int u)
{
    adjacencylist[v].push_back(u);
}
bool graph::checkcycle2(int v, bool vertvisited[], bool *recursionst)
{
    if(vertvisited[v]==false)
    {
        vertvisited[v]=true;
        recursionst[v]=true;
        list<int>::iterator itr;
        for(itr=adjacencylist[v].begin();itr!=adjacencylist[v].end();++itr)
        {
            if(!vertvisited[*itr]&&checkcycle2(*itr, vertvisited, recursionst))
            {
                return true;
            }
            else if(recursionst[*itr])
            {
                return true;
            }
        }
    }
    recursionst[v]=false;
    return false;
}
bool graph::checkcycle()
{
    bool *vertvisited=new bool[v];
    bool *recursionst=new bool[v];
    for(int i=0;i<v;i++)
    {
        vertvisited[i]=false;
        recursionst[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(checkcycle2(i, vertvisited, recursionst))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n1,n2;
    int size;
    cin>>size;
    graph g(size);
    for(int i = 0; i<(size*2);i++) {
        cin>>n1>>n2;
        g.drawedge(n1,n2);
    }
    if(g.checkcycle())
        cout << "yes";
    else
        cout << "no";
    return 0;
}