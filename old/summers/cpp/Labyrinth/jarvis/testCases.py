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
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.regexTester("3 3\n###\n#.#\n###" , "Maximum rope length is 0." , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("7 6\n#######\n#.#.###\n#.#.###\n#.#.#.#\n#.....#\n#######" , "Maximum rope length is 8." , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 5\n##.##\n##.##\n.....\n##.##\n##.##" , "Maximum rope length is 4." , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 4\n###\n#.#\n#.#\n###" , "Maximum rope length is 1." , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


