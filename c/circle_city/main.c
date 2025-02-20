#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
import math
def count_lattice(r):
    lim = int(math.sqrt(r))
    count = 0
    for x in xrange(-lim,lim+1):
        y = int(math.sqrt(r-x*x))
        if y*y+x*x==r:
            count += 2 if y!=0 else 1
    return count
T=int(raw_input())
for t in xrange(T):
    [r,k] = [int(x) for x in str(raw_input()).split(" ")]
    print "possible" if count_lattice(r)<=k else "impossible"
*/
int count_lattice(int r){
    int lim = sqrt(r);
    int count=0;
    int y;
    for(int x=-lim;x<lim+1;++x){
        y = sqrt(r-x*x);
        if(y*y+x*x==r){
            count += y!=0 ? 2 : 1;
        }
    }
    printf("%d\n",count);
    return count;
}
int main(){
    int t,r,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&k);
        printf("%s\n",count_lattice(r)<=k ? "possible" : "impossible");
    }
    return 0;
}
