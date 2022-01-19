class Solution {
public:
    //typedef<int, int> pairr;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        int m = edges.size();
      //  int n = edges[0].size();
        // creae a graph 
        
        vector<int> graph[n]; // array of vector, we also can use vector<vector<int> > graph(m,(n,0));
        
        for (int i = 0; i < m; ++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        bool visited[n];
        memset(visited, false, sizeof visited);
        stack<int> s;
        s.push(source);
       // visited[source] = true;
        while (!s.empty()){
            
            int  temp_s = s.top();
            s.pop(); 
            visited[temp_s] = true;
            if ( temp_s == destination) {
                cout<< temp_s;    
                return true;
            }
            for (int i = 0; i < graph[temp_s].size(); ++i){
              // cout<<e[0]<<" "<<e[1]<<endl;
                                                // [[0,1],[0,2],[3,5],[5,4],[4,3]]
                if (!visited[graph[temp_s][i]]){
                    s.push(graph[temp_s][i]);
                    
                }
                
                
            }
            
        }
        return false;
        
    }
};
