'''
Project name : Appleman_and_Toastman
Created on : Tue Aug 26 20:07:14 2014
Author : Anant Pushkar
http://codeforces.com/contest/462/problem/C
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def find_extra(x , p):
	if p==1:
		return 2 if x==2 else 0
	return find_extra(x/2,p-1) + find_extra(x-x/2,p-1)
def next_pow(x):
	count=0
	while x>0:
		x = x/2
		count += 1
	return count
	
n = int(raw_input())
p = next_pow(n)

arr = [int(x) for x in str(raw_input()).split(" ")]
arr.sort(reverse=True)

if n&(n-1) == 0:
	print str(sum(arr) * p)
else:
	print str(sum(arr) * p + sum(arr[0:find_extra(n,p)]))
	
	
	
	
