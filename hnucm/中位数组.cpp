#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int,vector<int>,less<int>>max_heap;      //大根堆存储左区间
priority_queue<int,vector<int>,greater<int>>min_heap;   //小根堆存储右区间，始终保持右区间元素>=左区间元素
void add(int x){
    if(max_heap.empty()||max_heap.top()>x) max_heap.push(x);
    else min_heap.push(x);
    if(max_heap.size()-min_heap.size()==2){
        min_heap.push(max_heap.top());
        max_heap.pop();
    }
    if(min_heap.size()-max_heap.size()==2){
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}
double query(){
    if(max_heap.empty()&&min_heap.empty()) return 0.00;
    if(max_heap.size()==min_heap.size()) return (max_heap.top()+min_heap.top())/2.0;
    return max_heap.size()>min_heap.size()?max_heap.top():min_heap.top();
}
void del(){
    if(max_heap.empty()&&min_heap.empty()) return ;
    if(max_heap.size()==min_heap.size()){
        max_heap.pop();
        min_heap.pop();
        return ;
    }
    max_heap.size()>min_heap.size()?max_heap.pop():min_heap.pop();
}
int main(){
    // freopen("data/median5.in","r",stdin);
    // freopen("data/median5.out","w",stdout);
    int n,q,v;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i){
        scanf("%d",&v);
        add(v);
    }
    for(int i=0;i<q;++i){
        int op;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&v);
            add(v);
        }
        else if(op==2) del();
        else printf("%.2f\n",query());
    }
    return 0;
}