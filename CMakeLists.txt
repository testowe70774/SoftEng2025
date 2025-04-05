cmake_minimum_required(VERSION 3.10)
project(SortLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MDd")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

set(SOURCES
  # add list of source files
)

set(HEADERS
  # add list of header files
)


add_library(SortLib SHARED ${SOURCES} ${HEADERS})

#target_link_libraries(SortLib PUBLIC Lib::Lib)

target_compile_definitions(SortLib PRIVATE BUILDING_CLIENT_DLL)



#enable_testing()

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#add_subdirectory(externals/googletest)

#add_executable(test_sort1 src/tests/smoke/test_sort1.cpp)
#target_link_libraries(test_sort1 gtest gtest_main SortLib)
#target_include_directories(test_sort1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

#add_executable(test_sort2 src/tests/smoke/test_sort2.cpp)
#target_link_libraries(test_sort2 gtest gtest_main SortLib)
#target_include_directories(test_sort2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

#add_test(NAME test_sort1 COMMAND test_sort1)
#add_test(NAME test_sort2 COMMAND test_sort2)