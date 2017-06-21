/** Created by Dennis on 18-Jun-17.
**/
#include "mtmtest.h"
#include "Enigma.h"
using namespace std;

using namespace mtm::escaperoom;
using std::string;

struct enigma_t {
    Enigma e1;
    Enigma e2;
    Enigma e3;
    Enigma e4;
    Enigma e5;
    Enigma e6;
    Enigma e7;
};

static enigma_t setUp();

static void
AssertParams(const string &s1, const Difficulty &difficulty,
             const int &numOfElements, const Enigma &enigma);

bool testCtor() {
    enigma_t enigmas = setUp();

    AssertParams("enigma1",EASY_ENIGMA,1,enigmas.e1);
    AssertParams("enigma5",HARD_ENIGMA,5,enigmas.e5);
    AssertParams("enigma7",HARD_ENIGMA,7,enigmas.e7);

    return true;
}

bool testIsEqualAndNotEqualOp(){
    enigma_t enigmas = setUp();

    ASSERT_TRUE(enigmas.e1 != enigmas.e2);
    ASSERT_TRUE(enigmas.e1 == enigmas.e1);

    Enigma temp ("enigma4",EASY_ENIGMA,4);
    ASSERT_TRUE(enigmas.e4 != temp);

    Enigma temp2 ("enigma5",HARD_ENIGMA,1);
    ASSERT_TRUE(enigmas.e5 == temp2);
    ASSERT_TRUE(enigmas.e7 != temp2);
    return true;
}

bool testGreaterLessThenOp(){
    enigma_t enigmas = setUp();

    ASSERT_TRUE(enigmas.e7 > enigmas.e1);
    ASSERT_TRUE(enigmas.e5 > enigmas.e4);
    ASSERT_FALSE(enigmas.e7 > enigmas.e6);
    ASSERT_TRUE(enigmas.e2 < enigmas.e6);
    ASSERT_FALSE(enigmas.e6 < enigmas.e6);

    Enigma temp ("enigma3",HARD_ENIGMA,3);
    ASSERT_TRUE(temp > enigmas.e3);

    return true;
}

bool testOsStreamOp(){
    enigma_t enigmas = setUp();
    ASSERT_PRINT("enigma1 (0) 1",enigmas.e1);
    ASSERT_PRINT("enigma2 (0) 2",enigmas.e2);
    ASSERT_PRINT("enigma6 (2) 6",enigmas.e6);
    ASSERT_PRINT("enigma4 (1) 4",enigmas.e4);

    return true;
}

bool testAreEqualyComplex(){
    enigma_t enigmas = setUp();

    Enigma t1 ("t1",EASY_ENIGMA,1);

    ASSERT_TRUE(enigmas.e1.areEqualyComplex(t1));
    ASSERT_FALSE(enigmas.e2.areEqualyComplex(t1));

    Enigma t2 ("enigma7",HARD_ENIGMA,7);

    ASSERT_TRUE(enigmas.e7.areEqualyComplex(t2));
    ASSERT_TRUE(enigmas.e7.areEqualyComplex(enigmas.e7));
    ASSERT_FALSE(enigmas.e7.areEqualyComplex(enigmas.e6));


    return true;
}

static void
AssertParams(const string &s1, const Difficulty &difficulty,
             const int &numOfElements, const Enigma &enigma) {

    ASSERT_TRUE(s1 == enigma.getName());
    ASSERT_TRUE(difficulty == enigma.getDifficulty());
    Enigma temp (s1,difficulty,numOfElements);
    ASSERT_TRUE(temp == enigma);
}

static enigma_t setUp() {
    enigma_t enigmas = {
            Enigma("enigma1",EASY_ENIGMA,1),
            Enigma("enigma2",EASY_ENIGMA,2),
            Enigma("enigma3",MEDIUM_ENIGMA,3),
            Enigma("enigma4",MEDIUM_ENIGMA,4),
            Enigma("enigma5",HARD_ENIGMA,5),
            Enigma("enigma6",HARD_ENIGMA,6),
            Enigma("enigma7",HARD_ENIGMA,7)
    };
    return enigmas;
}

int main() {
    RUN_TEST(testCtor);
    RUN_TEST(testIsEqualAndNotEqualOp);
    RUN_TEST(testGreaterLessThenOp);
    RUN_TEST(testOsStreamOp);
    RUN_TEST(testAreEqualyComplex);
    return 0;
}