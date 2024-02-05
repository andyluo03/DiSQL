add_test([=[HelloTest.BasicAssertions]=]  /Users/andyluo/Dev/DiSQL/src/tests/bin/parse_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /Users/andyluo/Dev/DiSQL/src/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  parse_test_TESTS HelloTest.BasicAssertions)
