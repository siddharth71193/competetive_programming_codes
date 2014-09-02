'''
Project name : codeforce460b
Created on : Thu Aug 21 22:10:46 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
		
def sumOfDig(n):
	s=0
	while n:
		s = s+n%10
		n = n/10
	return s

def init():
	[a,b,c] = [int(x) for x in str(raw_input()).split(" ")]
	lis = []
	count=0
	for t in range(1,82):
		x=b*(t**a)+c
		if x<1000000000 and x>0 and t==sumOfDig(x):
			count = count+1
			lis.append(x)
	
	print count
	for i in lis:
		print i , 
	print ""
		

init()
