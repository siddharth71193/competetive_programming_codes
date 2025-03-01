/*
Project name : Yodaness_Level
Created on : Fri Aug 29 20:54:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/YODANESS/
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	map<string,int> lookup;
	vector<string> arr;
	vector<int> pos , temp;
	int count_cross(int start , int end){
		if(end==start+1){
			return 0;
		}
		int mid  = (start+end)/2;
		int left = count_cross(start,mid);
		int right= count_cross(mid,end);
		
		int i=start , j=mid , count=0 , index=start;
		while(i<mid && j<end){
			if(pos[i]<pos[j]){
				temp[index] = pos[i];
				++i;
				count += j-mid;
			}else{
				temp[index] = pos[j];
				++j;
			}
			++index;
		}
		while(i<mid){
			temp[index++] = pos[i++];
			count += end-mid;
		}
		while(j<end){
			temp[index++] = pos[j++];
		}
		
		for(int i=start;i<end;++i){
			pos[i] = temp[i];
		}
		
		return count + left + right;
	}
public:
	Solver(int x):
	n(x),
	arr(vector<string>(x)),
	temp(vector<int>(x)),
	pos(vector<int>(x)){
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		string s;
		for(int i=0;i<n;++i){
			cin>>s;
			lookup[s] = i;
		}
		for(int i=0;i<n;++i){
			pos[i] = lookup[arr[i]];
		}
	}
	int solve(){
		return count_cross(0,n);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%d\n",s.solve());
	}
	
	return 0;
}

