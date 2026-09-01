class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m=g.size(),n=g[0].size(),k=0,sx,sy;
        vector<vector<int>> id(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)for(int j=0;j<n;j++){
            if(g[i][j]=='S') sx=i,sy=j;
            if(g[i][j]=='L') id[i][j]=k++;
        }

        int N=1<<k,d=0;
        vector<vector<int>> vis(m*n,vector<int>(N,-1));
        queue<array<int,4>> q;
        q.push({sx,sy,0,E});
        vis[sx*n+sy][0]=E;

        int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

        while(q.size()){
            int z=q.size();
            while(z--){
                auto [x,y,mask,e]=q.front(); q.pop();
                if(mask==N-1) return d;
                if(!e) continue;

                for(int t=0;t<4;t++){
                    int X=x+dx[t],Y=y+dy[t];
                    if(X<0||X>=m||Y<0||Y>=n||g[X][Y]=='X') continue;

                    int ne=e-1,nm=mask;
                    if(g[X][Y]=='L') nm|=1<<id[X][Y];
                    if(g[X][Y]=='R') ne=E;

                    if(ne>vis[X*n+Y][nm])
                        vis[X*n+Y][nm]=ne,q.push({X,Y,nm,ne});
                }
            }
            d++;
        }
        return -1;
    }
};