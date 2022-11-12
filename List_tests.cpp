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
    List.pop_back();
    assert(List.size() == 0);
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

TEST(test_copy_constructor_empty) {
    List<int> List1;
    List<int> ListCopy(List1);
    assert(ListCopy.empty());
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

TEST(test_begin) {
    List<int> List;
    List.push_back(5);
    List.push_front(4);
    assert(*List.begin() == 4);
}

TEST(test_begin_equals_end){
    List<int> List;
    assert(List.begin() == List.end());
}

TEST(test_being_not_equal_end){
    List<int> List;
    List.push_back(5);
    List.push_front(4);
    assert(List.begin() != List.end());
}

TEST(test_begin_and_plus_and_minus) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(4);
    List<int>::Iterator iter = List1.begin();
    assert(*iter == 4);
    ++iter;
    assert(*iter == 5);
    --iter;
    assert(*iter == 4);
}

TEST(test_erase) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(4);
    List1.push_front(3);
    List<int>::Iterator iter = List1.begin();
    ++iter;
    cout << "test 1" << endl;
    List1.erase(iter);
    cout << "test 2" << endl;
    assert(List1.front() == 3);
    assert(List1.back() == 5);
    iter = List1.begin();
    List1.erase(iter);
    assert(List1.front() == 5);
}

TEST(test_erase_one_element) {
    List<int> List1;
    List1.push_back(5);
    List<int>::Iterator iter = List1.begin();
    List1.erase(iter);
    assert(List1.empty());
}

TEST(test_erase_two_elements) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(4);
    List<int>::Iterator iter = List1.begin();
    ++iter;
    List1.erase(iter);
    assert(List1.back() == 4);
    assert(List1.front() == 4);
}

TEST(test_insert_between_two) {
    List<int> List1;
    List1.push_back(5);
    List1.push_front(4);
    List<int>::Iterator iter = List1.begin();
    ++iter;
    List1.insert(iter, 6);
    assert(List1.front() == 4);
    List1.pop_front();
    assert(List1.front() == 6);
}


TEST_MAIN()
