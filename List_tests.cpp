// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_empty) {
    List<int> List;
    List.push_back(5);
    assert(!List.empty());
    List.pop_front();
    assert(List.empty());
}

TEST(test_size) {
    List<double> List;
    List.push_back(5);
    assert(List.size() == 1);
    List.push_front(2);
    assert(List.size() == 2);
    List.pop_back();
    assert(List.size() == 1);
}

TEST(test_front) {
    List<string> List;
    List.push_back("hello");
    assert(List.front() == "hello");
    List.push_front("hi");
    assert(List.front() == "hi");
    List.push_back("bye");
    assert(List.front() == "hi");
}

TEST(test_back) {
    List<string> List;
    List.push_back("hello");
    assert(List.back() == "hello");
    List.push_back("hi");
    assert(List.back() == "hi");
    List.push_front("bye");
    assert(List.back() == "hi");
}

TEST(test_pop_front) {
    List<int> List;
    List.push_back(5);
    assert(List.front() == 5);
    List.pop_front();
    assert(List.empty());
    List.push_front(10);
    List.push_back(8);
    assert(List.front() == 10);
    List.pop_front();
    assert(List.front() == 8);
    List.pop_front();
    assert(List.empty());
}

TEST(test_pop_back) {
    List<int> List;
    List.push_back(5);
    assert(List.front() == 5);
    List.pop_back();
    assert(List.empty());
    List.push_front(10);
    List.push_back(8);
    assert(List.front() == 10);
    List.pop_back();
    assert(List.front() == 10);
    List.pop_back();
    assert(List.empty());
}

TEST(test_clear) {
    List<double> List;
    List.push_back(10);
    List.push_front(6);
    List.push_back(5);
    assert(List.front() == 6);
    assert(List.back() == 5);
    List.clear();
    assert(List.empty());
}

TEST(test_copy_constructor) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(6);
    assert(List1.front() == 6);
    assert(List1.back() == 5);
    List<int> ListCopy(List1);
    assert(ListCopy.front() == 6);
    assert(ListCopy.back() == 5);
}

TEST(test_equals_constructor) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(6);
    assert(List1.front() == 6);
    assert(List1.back() == 5);
    List<int> ListCopy;
    ListCopy.push_back(1000);
    ListCopy.push_front(600);
    assert(ListCopy.front() == 600);
    assert(ListCopy.back() == 1000);
    ListCopy = List1;
    assert(ListCopy.front() == 6);
    assert(ListCopy.back() == 5);
}

TEST_MAIN()
