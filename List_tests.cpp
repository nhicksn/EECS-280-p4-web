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

TEST_MAIN()
