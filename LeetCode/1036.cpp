class Solution {
public:
    int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int N=1e6;
    map<pair<int,int>,bool>mp;
    bool check(pair<int,int>p){
        return p.first>=0&&p.first<N&&p.second>=0&&p.second<N;
    }
    bool bfs(pair<int,int>s,pair<int,int>t,int block_size){
        map<pair<int,int>,bool>vis;
        int maxn=block_size*(block_size-1)/2;
        int cnt=1;
        vis[s]=1;
        queue<pair<int,int>>q;
        q.push(s);
        pair<int,int>now,ne;
        while(!q.empty()&&cnt<=maxn){
            now=q.front();
            q.pop();
            if(now==t) return true;
            for(int i=0;i<4;++i){
                ne.first=now.first+d[i][0];
                ne.second=now.second+d[i][1];
                if(check(ne)&&!vis[ne]&&!mp[ne]){
                    vis[ne]=1;
                    q.push(ne);
                    ++cnt;  //从起点出发经过的点数目
                }
            }
        }
        return cnt>maxn;    //判断起点是否会被障碍物封锁
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)    {   
        int block_size=blocked.size();
        for(int i=0;i<block_size;++i) mp[make_pair(blocked[i][0],blocked[i][1])]=1;
        pair<int,int>s=make_pair(source[0],source[1]);
        pair<int,int>t=make_pair(target[0],target[1]);
        return bfs(s,t,block_size)&bfs(t,s,block_size);
    }
};