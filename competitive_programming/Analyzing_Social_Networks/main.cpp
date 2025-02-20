/*
Project name : Analyzing_Social_Networks
Created on : Sat Aug  2 21:22:27 2014
Author : Anant Pushkar

*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n , max_val;
	vector<deque<pair<int,int> > > adjList;
	vector<bool> lookup;
	int push_node(int v , stack<int> &s , int cost , stack<int> &ps , int p){
		if(debug)cout<<"v"<<v<<" cost"<<cost<<" par"<<p<<endl;
		if(cost<0){
			return 0;
		}
		if(lookup[v]){
			return 2;
		}
		s.push(v);
		ps.push(p);
		lookup[v] = 1;
		return 1;
	}
	int dfs(int v , int par){
		if(debug)cout<<"dfs at "<<v<<endl;
		if(lookup[v]){
			return 0;
		}
		int val=0 , size=adjList[v].size() , temp;
		lookup[v] = true;
		queue<int> q , d;
		for(int i=0;i<size;++i)if(adjList[v][i].first != par){
			if(adjList[v][i].second>=0){
				val += dfs(adjList[v][i].first , v) + adjList[v][i].second;
			}else if(adjList[v][i].second!=INT_MIN){
				q.push(adjList[v][i].first);
				d.push(adjList[v][i].second);
			}
			if(lookup[adjList[v][i].first]){
				adjList[v][i].second = 0;
			}
		}
		
		int x , y;
		while(!q.empty()){
			y = q.front();
			q.pop();
			
			x = d.front();
			d.pop();
			
			temp = dfs(y , v);
			if(temp>0){
				val += temp + x;
			}
		}
		
		if(debug)cout<<"returning from "<<v<<" with "<<val<<endl;
		max_val = val>max_val ? val : max_val;
		return val;
	}
public:
	Solver(int num):
	n(num),
	adjList(vector<deque<pair<int,int> > >(num)),
	lookup(vector<bool>(num,false)){
		max_val=INT_MIN;
		int u , v , w;
		for(int i=0;i<n-1;++i){
			scanf("%d %d %d",&u,&v,&w);
			--u;--v;
			adjList[u].push_back(make_pair(v,w));
			adjList[v].push_back(make_pair(u,w));
		}
	}
	int solve(){
		stack<int> s , p;
		
		int v , size , val , check , par , sum;
		for(int i=0;i<n;++i)if(!lookup[i]){
		/*
			push_node(i,s,0,p,i);
			val = 0;
			sum=0;
			
			while(!s.empty()){
				v = s.top();
				par = p.top();
				s.pop();
				p.pop();
				
				if(debug)cout<<"at "<<v<<" par"<<par<<endl;
				
				size = adjList[v].size();
				if(debug)cout<<"size : "<<size<<endl;
				for(int i=0;i<size;++i)if(adjList[v][i].first!=par){
					check = push_node(adjList[v][i].first , s , adjList[v][i].second , p , v);
					if(check==1 ){
						val += adjList[v][i].second;
					}
					if(check==2){
						sum += adjList[v][i].second;
					}
				}
			}
			
			val = val + sum/2;
			*/
			val = dfs(i,i);
			max_val = val>max_val ? val : max_val;
		}
		
		return max_val>0 ? max_val : 0;
	}
};	
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	printf("%d\n",s.solve());
	
	return 0;
}

