aux_source_directory(. SRC)
add_executable(test_all.testbin ${SRC} gtest/gtest_main.cc)
target_link_libraries(test_all.testbin gtest)

add_executable(test_permutation.testbin test_permutation.cpp gtest/gtest_main.cc)
target_link_libraries(test_permutation.testbin gtest)

add_executable(test_rotate.testbin test_rotate_str.cpp gtest/gtest_main.cc)
target_link_libraries(test_rotate.testbin gtest)

add_executable(test_binary_search.testbin test_binary_search.cpp gtest/gtest_main.cc)
target_link_libraries(test_binary_search.testbin gtest)

add_executable(test_lru.testbin test_lru.cpp gtest/gtest_main.cc)
target_link_libraries(test_lru.testbin gtest)
