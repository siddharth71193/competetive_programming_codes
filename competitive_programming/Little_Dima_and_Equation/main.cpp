/*
Project name : Little_Dima_and_Equation
Created on : Thu Aug 21 21:05:25 2014
Author : Anant Pushkar
http://codeforces.com/contest/460/problem/B
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
#include<set>
#include<cmath>
typedef long long int lld;
using namespace std;

lld sumOfDig(lld n){
	lld s=0;
	while(n){
		s+=(n%10);
		n/=10;
	}
	return s;
}

int main(){
	lld a,b,c,t,x,count=0,flag=0;
	queue<lld> que;
	cin>>a>>b>>c;
	for(t=1;t<=81;t++){
		x=b*pow(t,a)+c;
		if(x<1000000000 && x>0 && t==sumOfDig(x)){count++;que.push(x);}
	}

	cout<<count<<endl;
	if(!que.empty()){cout<<que.front();que.pop();flag=1;}
	while(!que.empty()){cout<<" "<<que.front(); que.pop();}
	if(flag)
		cout<<endl;
}
