
#include <bits/stdc++.h>
using namespace std;

class AdjacencyList
{
public:
    int vertex;
    vector<vector<int>> list;

    AdjacencyList(int vertex)
    {
        this->vertex = vertex;
        list.resize(vertex);
    }

    void InsertVertex(int u, int v)
    {
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void deleteEdge(int u,int v){
        if((u >= 0 && u < vertex) && (v >= 0 && v < vertex)){
            auto x = find(list[u].begin(),list[u].end(),v);
            if(x != list[u].end()){
                list[u].erase(x); 
            }

            auto y = find(list[v].begin(),list[v].end(),u);
            if(y != list[v].end()){
                list[v].erase(y);
            }
            cout<<"Edge Deleted"<<endl;
        }
        else{
            cout<<"Invalid Coordinates "<<endl;
        } 
    }


    void display()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << "vertex: " << i << ": ";
            for (int j : list[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void BreadthFirstSearch(int start){
        vector<bool> visited(vertex,false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            cout<<x<<" ";
            for(auto y : list[x]){
                if(!visited[y]){
                    visited[y] = true;
                    q.push(y);
                }
            }
        }
    }

    void DepthFirstSearch(int start){
        stack<int> s;
        vector<bool> visited(vertex,false);
        s.push(start);
        visited[start] = true;

        while(!s.empty()){
            int x = s.top();
            s.pop();
            cout<<x<<" ";

            for(int y : list[x]){
                if(!visited[y]){
                    s.push(y);
                    visited[y] = true;
                }
            }
        }
    }
};
int main()
{
    AdjacencyList al(5);
    // al.InsertVertex(0, 1);
    // al.InsertVertex(1, 2);
    // al.InsertVertex(2, 3);
    // al.InsertVertex(3, 4);
    // al.InsertVertex(0, 4);

    // al.InsertVertex(0,1);
    // al.InsertVertex(0,3);
    // al.InsertVertex(3,0);
    // al.InsertVertex(3,1);
    // al.InsertVertex(1,0);
    // al.InsertVertex(1,2);
    // al.InsertVertex(1,3);
    // al.InsertVertex(2,1);

    al.InsertVertex(0,1);
    al.InsertVertex(0,3);
    al.InsertVertex(1,3);
    al.InsertVertex(1,2);



    cout<<endl;
    al.display();

    cout<<"Breadth First Search: ";
    al.BreadthFirstSearch(0);

    cout<<endl;
    cout<<"Depth First Search: ";
    al.DepthFirstSearch(0);
    return 0;
}
