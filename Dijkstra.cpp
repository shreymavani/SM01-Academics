#include<iostream>
#include<climits>
using namespace std;
class Dijkstra{
    private:
    int N,src,swi,destiny;
    int graph[1000][1000],dist[1000];
    string path[1000];
    bool Select[1000];

    public:

Dijkstra()
{
        int i,j;
        cout<<"Enter No. of junction ,you have in route=";
        cin>>N;
        cout<<"Enter their distance and the connectivity of road according to the route map:-\n";
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            cin>>graph[i][j];

        cout<<"Enter the junction no ur on =";
        cin>>src;

        cout<<"Press 0:-To print distance to all node \nPress 1:-To print distance for a particular node";
        cin>>swi;

        if(swi!=0)
        {
            cout<<"Enter no. of that particullar node=";
            cin>>destiny;
        }
}
    
int min_dist() 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int i = 0; i < N; i++) 
        if (Select[i] == false && dist[i] <= min) 
            min = dist[i], min_index = i; 
  
    return min_index; 
}
void printOne(int destiny)
{
    cout<<"\nDistance from "<<src<<" to "<<destiny<<" is "<<dist[destiny];
    cout<<" \npath is"<<path[destiny]+" "+to_string(destiny);
}
void printAll() 
{ 
    cout<<"\nVertex   Distance from Source\n"; 
    for (int i = 0; i < N; i++) 
    {cout<<"\nDistance from "<<src<<" to "<<i<<" is "<<dist[i];
    cout<<" \npath is"<<path[i]+" "+to_string(i);
    }
} 

void dijkstra() 
{ 
   
    for (int i = 0; i < N; i++) 
        dist[i] = INT_MAX, Select[i] = false; 
  
        dist[src] = 0; 
  
    for (int count = 0; count < N - 1; count++) { 
  
        int u = min_dist(); 

        Select[u] = true; 
  
        for (int i = 0; i < N; i++) 
                if (!Select[i] && graph[u][i] && dist[u] != INT_MAX 
                && dist[u] + graph[u][i] < dist[i]) 
                {
                    dist[i] = dist[u] + graph[u][i];
                    path[i] = path[u] +" "+ to_string(u);
                }
    } 

    if(swi==0)
    printAll();
    else
    printOne(destiny); 
}
};

int main()
{
    Dijkstra d;
    d.dijkstra();
    return 0;
}
