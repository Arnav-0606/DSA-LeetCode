class DisjointSet{
public:
	vector<int>par;
	vector<int>rank;
	DisjointSet(int n){
		par.resize(n);
		rank.resize(n);
	}
	
	void createSet(int x){
par[x] = x;
rank[x] = 0;
	}

	int findSet(int x){
	if(par[x]==x) return x;
	return  par[x] = findSet(par[x]);
	}



	void unionSet(int x,int y){
		int px = findSet(x);
		int py = findSet(y);
		if(rank[px]==rank[py]){
			rank[px]++;
}
if(rank[px]>rank[py]){
par[py] = px;
}
else{
	par[px]=py;
}		
}
};

class Solution{
public :  
	bool checkSimilar(string s1,string s2){
    int swaps = 0;
    int stringsSize = s1.size();
        for(int i=0;i<stringsSize;i++){
        	if(s1[i]!=s2[i]){
        		swaps++;
        	}
        }
        return swaps<=2;
        }
	int numSimilarGroups(vector<string>&strs){
		int n = strs.size();
		DisjointSet ds(n);
        int grps = n;
		for(int i=0;i<n;i++){
			ds.createSet(i);
		}
		for(int i=0;i<n;i++){
	        for(int j =i+1;j<n;j++){
		        if(ds.findSet(i)!=ds.findSet(j)){
			        if(checkSimilar(strs[i],strs[j])){
				    ds.unionSet(i,j);
                    grps--;
                    }
		        }
            }
        }
        return grps;
    }
};
