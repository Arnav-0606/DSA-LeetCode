class Solution{
public:

int shortestPath(int n,vector<vector<int>>&edges,string labels,int k){
	vector<vector<pair<int,int>>>adj(n);
	for(auto &edge:edges){
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];
		adj[u].push_back({v,w});
	}
		vector<vector<int>>dist(n,vector<int>(k+1,1e9));
		priority_queue<
		tuple<int,int,int>,
		vector<tuple<int,int,int>>,
		greater<tuple<int,int,int>>
		>pq;
		dist[0][1] = 0;
		pq.push({0,0,1});
		while(!pq.empty()){
			auto [dis, node, cons] = pq.top();
			pq.pop();
			if(dist[node][cons] < dis) continue;
			if(node==n-1) return dis;
			for(auto & ngb : adj[node]){
				int tempCons = cons;
				if(labels[node]==labels[ngb.first]){
tempCons++;
}
				else tempCons =1;
				if(tempCons>k) continue;
				int weight = ngb.second;
				if(dis + weight <dist[ngb.first][tempCons]){
				dist[ngb.first][tempCons]= dis+ weight;
pq.push({dist[ngb.first][tempCons],ngb.first,tempCons});
				}
				
			}
		}
		return -1;
}
};
