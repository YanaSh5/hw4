#include <functional>
#include "list.h"
#include "mtmtest.h"
#include "Exceptions.h"
using std::string;

/**
 * Function object for finding a target integer
 */
class EqualTo {
private:
    int target;
public:
    EqualTo(int i) : target(i) {}
    bool operator()(const int& i) const {
        return i == target;
    }
};


static void listCreateInsertTest() {
    List<string> list;
    list.insert("hadar", list.end());
    list.insert("yanush", list.end());
    list.insert("matam");
    ASSERT_EQUALS(list.getSize(), 3);
    List<string>::Iterator begin = list.begin();
    ASSERT_EQUALS(*begin, "hadar");
    List<string>::Iterator end = list.end();
    ASSERT_EQUALS(*end, "matam");
    list.insert("A+", list.begin());
    begin = list.begin();
    ASSERT_EQUALS(*begin, "A+");
    begin++;
    ASSERT_EQUALS(*begin, "hadar");
    ++begin;
    ASSERT_EQUALS(*begin, "yanush");
    end--;
    ASSERT_EQUALS(*begin, *end);
}

static void listOperatorsTest() {
    List<string> list;
    list.insert("Abercrombie", list.end());
    list.insert("Zara", list.end());
    list.insert("Mango");
    ASSERT_EQUALS(list.getSize(), 3);
    List<string>::Iterator it1 = list.begin();
    ASSERT_EQUALS(*it1, "Abercrombie");
    it1++;
    List<string>::Iterator it2 = list.end();
    ASSERT_EQUALS(*it2, "Mango");
    it2--;
    ASSERT_TRUE(it1==it2);
    it2--;
    ASSERT_TRUE(it1!=it2);
    it2--;
    ASSERT_THROWS(mtm::ListExceptions::ElementNotFound,*it2);
    it1++;
    it1++;
    ASSERT_THROWS(mtm::ListExceptions::ElementNotFound,*it1);
}





int main() {
    RUN_TEST(listCreateInsertTest);
    RUN_TEST(listOperatorsTest);
    return 0;
}
