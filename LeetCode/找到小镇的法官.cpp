class Solution {
    public int findJudge(int N, int[][] trust) {
        int d[]=new int[N+1];
        for(int[] t:trust){
            d[t[0]]--;
            d[t[1]]++;
        }
        for(int i=1;i<=N;++i){
            if(d[i]==N-1) return i;
        }
        return -1;
    }
}