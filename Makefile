dlopen-tester: dlopen-tester.cc
	$(CXX) $< -o $@ -ldl
	
