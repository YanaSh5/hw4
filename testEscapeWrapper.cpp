#include "EscapeRoomWrapper.h"
#include "mtmtest.h"
#include <cstring>
#include <assert.h>
#include "Exceptions.h"
using namespace std;

using namespace mtm::escaperoom;


void testOperators() {

    EscapeRoomWrapper Escapy2((char*)"technionEscapy2",35,4,6);
    EscapeRoomWrapper Escapy3((char*)"technionEscapy2",35,2,3);
    EscapeRoomWrapper Escapy4((char*)"technionEscapy3",35,2,3);
    EscapeRoomWrapper Escapy5((char*)"technionEscapy3",35,2,4);
    EscapeRoomWrapper Escapy6((char*)"technionEscapy3",35,3,4);
    EscapeRoomWrapper Escapy7((char*)"technionEscapy4",35,3,4);
    ASSERT_TRUE(Escapy2==Escapy3);
    ASSERT_NO_THROW(EscapeRoomWrapper((char*)"technionEscapy",4));
    ASSERT_TRUE(Escapy2!=Escapy4);
    ASSERT_TRUE(Escapy4>Escapy5);
    ASSERT_TRUE(Escapy6>Escapy5);
    ASSERT_EQUALS(Escapy2.getName(),Escapy3.getName());
    ASSERT_TRUE(Escapy5<Escapy6);
    ASSERT_FALSE(Escapy6<Escapy7);
    ASSERT_FALSE(Escapy6>Escapy7);
    ASSERT_FALSE(Escapy6==Escapy7);
    ASSERT_TRUE(Escapy6!=Escapy7);

}

void testValidRate() {
    EscapeRoomWrapper Escapy((char*)"technionEscapy",50,4,6);
    ASSERT_THROWS(EscapeRoomIllegalRateException,Escapy.rate(6));
    ASSERT_THROWS(EscapeRoomIllegalRateException,Escapy.rate(-2));
    ASSERT_NO_THROW(Escapy.rate(0));
    ASSERT_NO_THROW(Escapy.rate(2));
    ASSERT_EQUALS(Escapy.getRate(),1);

}
void getsTestConstractor4params(){
    EscapeRoomWrapper Escapy((char*)"technionEscapy",50,4,5);
    ASSERT_EQUALS(Escapy.getName(),"technionEscapy");
    ASSERT_EQUALS(Escapy.level(),4);
    ASSERT_EQUALS(Escapy.getMaxTime(),50);
    ASSERT_EQUALS(Escapy.getMaxParticipants(),5);
    ASSERT_EQUALS(Escapy.getRate(),0);
}
void getsTestConstractor2params() {
    EscapeRoomWrapper Escapy((char*)"technionEscapy2",2);
    ASSERT_EQUALS(Escapy.getName(),"technionEscapy2");
    ASSERT_EQUALS(Escapy.level(),2);
    ASSERT_EQUALS(Escapy.getMaxTime(),60);
    ASSERT_EQUALS(Escapy.getMaxParticipants(),6);
    ASSERT_EQUALS(Escapy.getRate(),0);
}
void copyTest(){
    EscapeRoomWrapper Escapy((char*)"technionEscapy",2);
    EscapeRoomWrapper Escapy2=EscapeRoomWrapper(Escapy);
    ASSERT_EQUALS(Escapy.getName(),Escapy2.getName());
    ASSERT_EQUALS(Escapy.getRate(),Escapy2.getRate());
    ASSERT_EQUALS(Escapy.getMaxParticipants(),Escapy2.getMaxParticipants());
    ASSERT_EQUALS(Escapy.getMaxTime(),Escapy2.getMaxTime());
}
void assignmentTest(){
    EscapeRoomWrapper Escapy1((char*)"technionEscapy",20,6,8);
    EscapeRoomWrapper Escapy2((char*)"technionEscapy2",50,4,5);
    ASSERT_EQUALS(Escapy2.getName(),"technionEscapy2");
    ASSERT_EQUALS(5,Escapy2.getMaxParticipants());
    ASSERT_EQUALS(50,Escapy2.getMaxTime());
    Escapy2=Escapy1;
    ASSERT_EQUALS(Escapy2.getName(),"technionEscapy");
    ASSERT_EQUALS(Escapy2.getMaxParticipants(),8);
    ASSERT_EQUALS(Escapy2.getMaxTime(),20);
}

void printTest(){
    EscapeRoomWrapper Escapy1((char*)"technionEscapy",20,6,8);
    EscapeRoomWrapper Escapy2((char*)"technionEscapy2",50,4,5);
    ASSERT_PRINT("technionEscapy (20/6/8)",Escapy1);
    ASSERT_PRINT("technionEscapy2 (50/4/5)",Escapy2);
}


int main() {
    RUN_TEST(testOperators);
    RUN_TEST(testValidRate);
    RUN_TEST(getsTestConstractor4params);
    RUN_TEST(getsTestConstractor2params);
    RUN_TEST(copyTest);
    RUN_TEST(assignmentTest);
    RUN_TEST(printTest);
}