/*
Project name : kth_median
Created on : Wed Aug  6 09:51:29 2014
Author : Anant Pushkar
find kth median of two individually sorted arrays
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
inline int get_min(int a , int b){
	return a<b ? a : b;
}
inline int get_max(int a , int b){
	return a>b ? a : b;
}

class Solver{
	int n1 , n2 , target;
	vector<int> arr1 , arr2;
	void print_state(int s1 , int e1 , int s2 , int e2){
		cout<<"a1["<<s1<<":"<<e1<<"] : ";
		for(int i=s1;i<e1;++i){
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
		
		cout<<"a2["<<s2<<":"<<e2<<"] : ";
		for(int i=s2;i<e2;++i){
			cout<<arr2[i]<<" ";
		}
		cout<<endl;
		
		cout<<endl;
	}
	float get_median(int s1 , int e1 , int s2 , int e2 , int k){
		if(debug){
			cout<<"k:"<<k<<endl;
			print_state(s1,e1,s2,e2);
		}
		int i1 = k/2+s1>e1 ? e1-1 : k/2-1+s1 , i2 = k/2+s2>e2 ? e2-1 : k/2-1+s2 ;
		if(debug)cout<<"i1:"<<i1<<" i2:"<<i2<<" k/2:"<<k/2<<endl<<"==================================="<<endl;
		if(e1==s1){
			return arr2[s2+k-1];
		}
		if(e2==s2){
			return arr1[s1+k-1];
		}
		if(k==1){
			return get_min(arr1[s1] , arr2[s2]);
		}
		if(e1==s1+1 && e2==s2+1){
			return get_min(arr1[s1] , arr2[s2]);
		}
		if(arr1[i1]<arr2[i2]){
			return get_median(i1+1,e1,s2,e2,k-(i1-s1)-1);
		}else{
			return get_median(s1,e1,i2+1,e2,k-(i2-s2)-1);
		}
	}
public:
	Solver(int a , int b , int c):
	n1(a),
	n2(b),
	arr1(vector<int>(a)),
	arr2(vector<int>(b)),
	target(c){
		for(int i=0;i<n1;++i){
			scanf("%d",&arr1[i]);
		}
		for(int i=0;i<n2;++i){
			scanf("%d",&arr2[i]);
		}
		if(debug)cout<<"TARGET : "<<target<<endl<<endl;
	}
	float solve(){
		return get_median(0,n1,0,n2,target);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n1 , n2 , k;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d %d ",&n1,&n2,&k);
		Solver s(n1,n2,k);
		printf("%f\n",s.solve());
		if(debug)cout<<"##########################################################"<<endl;
	}
	
	return 0;
}

