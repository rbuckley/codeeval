import sys
 
test_cases = open(sys.argv[1], 'r')
 
for test in test_cases:
    # 'test' represents the test case, do something with it
    # ...
    # ...
    # ignore test if it is an empty line
    if not test.strip():
        continue
    
    # Remove the trailing newline
    test_line = test.strip("\n")
    
    print test_line
    
test_cases.close()