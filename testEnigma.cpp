#include "Enigma.h"
#include "mtmtest.h"
#include <cstring>
#include <assert.h>
#include "Exceptions.h"
using namespace std;

using namespace mtm::escaperoom;


void testOperators() {

    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    Enigma Enigma2("enigma1",HARD_ENIGMA,6);
    Enigma Enigma3("enigma1",HARD_ENIGMA,5);
    Enigma Enigma4("enigma1",MEDIUM_ENIGMA,6);
    Enigma Enigma5("enigma2",MEDIUM_ENIGMA,6);
    Enigma Enigma6("enigma3",EASY_ENIGMA,7);
    ASSERT_TRUE(Enigma1==Enigma2);
    ASSERT_TRUE(Enigma2==Enigma3);
    ASSERT_TRUE(Enigma4<Enigma3);
    ASSERT_TRUE(Enigma4!=Enigma3);
    ASSERT_FALSE(Enigma4>Enigma3);
    ASSERT_FALSE(Enigma4==Enigma3);
    ASSERT_TRUE(Enigma6<Enigma5);
    ASSERT_TRUE(Enigma5>Enigma6);

}
void getTest(){
    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    ASSERT_EQUALS(Enigma1.getName(),"enigma1");
    ASSERT_EQUALS(Enigma1.getDifficulty(),HARD_ENIGMA);
    ASSERT_NOT_EQUAL(Enigma1.getDifficulty(),MEDIUM_ENIGMA);
}
void areEqualyComplexTest(){
    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    Enigma Enigma2("enigma2",HARD_ENIGMA,6);
    Enigma Enigma3("enigma2",HARD_ENIGMA,6);
    Enigma Enigma4("enigma2",MEDIUM_ENIGMA,6);
    Enigma Enigma5("enigma2",MEDIUM_ENIGMA,4);
    ASSERT_TRUE(Enigma1.areEqualyComplex(Enigma2));
    ASSERT_TRUE(Enigma2.areEqualyComplex(Enigma1));
    ASSERT_TRUE(Enigma2.areEqualyComplex(Enigma3));
    ASSERT_FALSE(Enigma4.areEqualyComplex(Enigma3));
    ASSERT_FALSE(Enigma4.areEqualyComplex(Enigma5));
}
void copyTest(){
    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    Enigma Enigma2=Enigma(Enigma1);
    ASSERT_EQUALS(Enigma1.getName(),Enigma2.getName());
    ASSERT_EQUALS(Enigma1.getDifficulty(),Enigma2.getDifficulty());
    ASSERT_TRUE(Enigma1.areEqualyComplex(Enigma2));
}
void assignmentTest(){
    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    Enigma Enigma2("enigma2",EASY_ENIGMA,8);
    ASSERT_NOT_EQUAL(Enigma1.getName(),Enigma2.getName());
    ASSERT_NOT_EQUAL(Enigma1.getDifficulty(),Enigma2.getDifficulty());
    ASSERT_FALSE(Enigma1.areEqualyComplex(Enigma2));
    Enigma2=Enigma1;
    ASSERT_EQUALS(Enigma1.getName(),Enigma2.getName());
    ASSERT_EQUALS(Enigma1.getDifficulty(),Enigma2.getDifficulty());
    ASSERT_TRUE(Enigma1.areEqualyComplex(Enigma2));
}
void printTest(){
    Enigma Enigma1("enigma1",HARD_ENIGMA,6);
    Enigma Enigma2("enigma2",EASY_ENIGMA,8);
    ASSERT_PRINT("enigma1 (2) 6",Enigma1);
    ASSERT_PRINT("enigma2 (0) 8",Enigma2);
}


int main() {
    RUN_TEST(testOperators);
    RUN_TEST(getTest);
    RUN_TEST(areEqualyComplexTest);
    RUN_TEST(copyTest);
    RUN_TEST(assignmentTest);
    RUN_TEST(printTest);
}