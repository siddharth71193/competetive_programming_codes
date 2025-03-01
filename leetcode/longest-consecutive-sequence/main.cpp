/*
Project name : longest-consecutive-sequence
Created on : Tue Aug 19 17:27:59 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/longest-consecutive-sequence/
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
#include<unordered_set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int size = num.size() , count , max = INT_MIN , n;
        unordered_set<int> lookup(num.begin() , num.end()) , dummy(num.begin() , num.end());
        unordered_set<int>::iterator it = lookup.begin();
        
        for(;it!=lookup.end();++it)if(dummy.find(*it)!=dummy.end()){
            count = 1;
            dummy.erase(dummy.find(*it));
            
            n = *it;
            //cout<<"expanding "<<n<<endl;
            while(dummy.find(n-1)!=dummy.end()){
                dummy.erase(dummy.find(n-1));
                //cout<<"erasing "<<n-1<<endl;
                ++count;
                --n;
            }
            
            n = *it;
            while(dummy.find(n+1)!=dummy.end()){
                dummy.erase(dummy.find(n+1));
                //cout<<"erasing "<<n+1<<endl;
                ++count;
                ++n;
            }
            
            max = max<count ? count : max;
        }
        
        return max;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solution s;
	int arr[11]={-8,-4,9,9,4,6,1,-4,-1,6,8};
	vector<int> v(arr , arr+11);
	cout<<s.longestConsecutive(v)<<endl;
	return 0;
}

