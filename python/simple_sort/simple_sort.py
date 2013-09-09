import sys
from decimal import *

test_cases = open(sys.argv[1], 'r')
 
for test in test_cases:
    # ignore test if it is an empty line
    # 'test' represents the test case, do something with it
    # ...
    # ignore test if it is an empty line
    if not test.strip():
        continue
    
    test_line = test.strip("\n")
    
    string_list = test_line.split();
    
    try:
        int_list = [Decimal(num_string) for num_string in string_list]
    except:
        continue
        
    int_list.sort()
    
    for sorted in int_list[:-1]:
        #sys.stdout.write(sorted + " ")
        sys.stdout.write(str(sorted) + " ")
        
    #sys.stdout.write(int_list[-1] + "\n")
    sys.stdout.write(str(int_list[-1]) + "\n")
        
test_cases.close()