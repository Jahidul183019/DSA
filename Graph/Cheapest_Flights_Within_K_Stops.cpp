//Leetcode 787

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>graph[n];

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            graph[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>> q;//node,(cost,stops)
        vector<int>dist(n,INT_MAX);

        dist[src]=0;
        q.push({src,{0,-1}});

        while(q.size()>0){
            auto val=q.front();
            int u=val.first;
            int cost=val.second.first;
            int stops=val.second.second;

            q.pop();
            for(auto edge : graph[u]){
                int v=edge.first;
                int wt=edge.second;
                if(dist[v]>cost+wt && stops+1<=k){
                    dist[v]=cost+wt;
                    q.push({v,{dist[v],stops+1}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;

        return dist[dst];
    }
};
