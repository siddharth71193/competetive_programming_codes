'''
Project name : Digit_Recognizer
Created on : Fri Sep 26 00:08:04 2014
Author : Anant Pushkar
https://www.kaggle.com/c/digit-recognizer
'''
import sys
from sklearn.ensemble import RandomForestClassifier
import csv
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
class DataReader:
	def __init__(self,fname):
		data = []
		with open('data/'+fname) as csvfile:
			spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
			for row in spamreader:
				data.append(row)
		
		self.data = data[1::]
		self.index_of = {}
		index=0
		for key in data[0]:
			self.index_of[key] = index
			index += 1
	
	def get(self,keylist):
		data = []
		for d in self.data:
			arr = []
			for key in keylist:
				arr.append(d[self.index_of[key]])
			data.append(arr)
		return data

def filter_data(train_data):
	return train_data

features = []
for i in xrange(784):
	features.append("pixel"+str(i))

train = DataReader("train.csv")
train_data = filter_data(train.get(features))

target = train.get(["label"])
'''	
print features
for data in train_data:
	print data
'''

clf = RandomForestClassifier(n_estimators=10)
clf = clf.fit(train_data, target)

test = DataReader("test.csv")
test_data = filter_data(test.get(features))

prediction = clf.predict(test_data)
result = open("data/submission.csv","w")

result.write("ImageId,Label\n")
index = 1
for data in prediction:
	result.write(str(index)+","+str(data)+"\n")
	index += 1
result.close()
