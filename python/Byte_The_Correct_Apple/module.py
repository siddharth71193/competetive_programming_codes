'''
Project name : Byte_The_Correct_Apple
Module name  : {module}
Created on : Tue Jul 29 13:49:49 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/byte-the-correct-apple
'''
import nltk
import math
class FeatureExtracter:
	def __init__(self , txt):
		self.tokens = [token.lower() for token in nltk.word_tokenize(txt)]
		self.count_nouns()
		self.normalize()
	
	def count_nouns(self):
		self.noun_freq = {}
		nounlist = [noun[0] for noun in nltk.pos_tag(self.tokens) if noun[1].startswith("NN") and len(noun[0])>3]
		for token in self.tokens:
			if token in nounlist:
				if token in self.noun_freq.keys():
					self.noun_freq[token] += 1
				else :
					self.noun_freq[token]  = 1
		self.noun_freq = dict([(key , self.noun_freq[key]) for key in self.noun_freq if self.noun_freq[key]>5])
		sorted_list = sorted(self.noun_freq, key=lambda x: -self.noun_freq[x])
		self.noun_freq = dict([(key , self.noun_freq[key]) for key in sorted_list ])
	
	def normalize(self):
		s = 0
		for key in self.noun_freq:
			s += self.noun_freq[key]
		for key in self.noun_freq:
			self.noun_freq[key] = math.log(float(self.noun_freq[key])/s)
				
fruit = open("apple-fruit.txt").read()
computers = open("apple-computers.txt").read()

extracter ={}
extracter["fruit"] = FeatureExtracter(fruit).noun_freq
extracter["company"] = FeatureExtracter(computers).noun_freq

print extracter
