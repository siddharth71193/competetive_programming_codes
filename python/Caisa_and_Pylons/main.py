'''
Project name : Caisa_and_Pylons
Created on : Sat Aug 30 13:08:14 2014
Author : Anant Pushkar
http://codeforces.com/contest/463/problem/B
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
n = int(raw_input())
h = [int(x) for x in str(raw_input()).split(" ")]
print max(h)
