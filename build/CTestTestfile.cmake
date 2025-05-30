# CMake generated Testfile for 
# Source directory: C:/Users/dell/SoftEng2025
# Build directory: C:/Users/dell/SoftEng2025/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_sort1 "C:/Users/dell/SoftEng2025/build/test_sort1.exe")
set_tests_properties(test_sort1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;95;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_sort2 "C:/Users/dell/SoftEng2025/build/test_sort2.exe")
set_tests_properties(test_sort2 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;96;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_insert "C:/Users/dell/SoftEng2025/build/test_insert.exe")
set_tests_properties(test_insert PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;97;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_radix "C:/Users/dell/SoftEng2025/build/test_radix.exe")
set_tests_properties(test_radix PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;98;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_merge "C:/Users/dell/SoftEng2025/build/test_merge.exe")
set_tests_properties(test_merge PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;99;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_select "C:/Users/dell/SoftEng2025/build/test_select.exe")
set_tests_properties(test_select PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;100;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_bubble "C:/Users/dell/SoftEng2025/build/test_bubble.exe")
set_tests_properties(test_bubble PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;101;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
add_test(test_quick "C:/Users/dell/SoftEng2025/build/test_quick.exe")
set_tests_properties(test_quick PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/dell/SoftEng2025/CMakeLists.txt;102;add_test;C:/Users/dell/SoftEng2025/CMakeLists.txt;0;")
subdirs("externals/googletest")
