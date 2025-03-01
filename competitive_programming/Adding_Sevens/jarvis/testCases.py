import testTemplate 
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="BYE")
	testcase = testTemplate.testInstance("010079010+010079=" , "010079010+010079=010106106" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("106010+010=" , "106010+010=106093" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1",footer="BYE")
	testcase = testTemplate.testInstance("063+063=" , "063+063=063" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("063 +063=" , "063 +063=063" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("063+	063=" , "063+	063=063" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


