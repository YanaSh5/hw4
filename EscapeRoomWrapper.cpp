#include <iostream>
#include "EscapeRoomWrapper.h"

using mtm::escaperoom::EscapeRoomWrapper;

EscapeRoomWrapper::EscapeRoomWrapper(char* name ,const int& escapeTime
        ,const int& level,const int& maxParticipants){
   escapy=escapeRoomCreate(name, escapeTime, maxParticipants, level);
    if (escapy==NULL){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& level){
    escapy=escapeRoomCreate(name, 60, 6, level);
    if (escapy==NULL){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::~EscapeRoomWrapper(){
    escapeRoomDestroy(this->escapy);
}

EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper& room) {
    escapy=escapeRoomCopy(room.escapy);
    if (escapy==NULL){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper& EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room){
    if (this==&room){
        return *this;
    }
    escapeRoomDestroy(this->escapy);
    escapy=escapeRoomCopy(room.escapy);
    return *this;
}

bool EscapeRoomWrapper::operator==(const EscapeRoomWrapper &room) const {
    return (areEqualRooms(this->escapy, room.escapy));
}
bool EscapeRoomWrapper::operator!=(const EscapeRoomWrapper &room) const {
    return !(*this==room);
}
bool EscapeRoomWrapper::operator>(const EscapeRoomWrapper &room) const {
    return (isBiggerRoom(this->escapy, room.escapy));
}
bool EscapeRoomWrapper::operator<(const EscapeRoomWrapper &room) const {
    return isBiggerRoom(room.escapy,this->escapy);
}
int EscapeRoomWrapper::level() const{
    return getLevel(this->escapy);
}
void EscapeRoomWrapper::rate(const int& newRate) const{
    RoomResult result=updateRate(this->escapy, newRate);
    if (result==ESCAPEROOM_BAD_PARAM || result==ESCAPEROOM_NULL_ARG){
        throw EscapeRoomIllegalRateException();
    }
}
std::string EscapeRoomWrapper::getName() const{
    std::string str(roomGetName(this->escapy));
    return str;
}
double EscapeRoomWrapper::getRate() const{
    return roomGetRate(this->escapy);
}
int EscapeRoomWrapper::getMaxTime() const{
    return roomGetMaxTime(this->escapy);
}
int EscapeRoomWrapper::getMaxParticipants() const {
    return roomGetMaxParticipants(this->escapy);
}
std::ostream& mtm::escaperoom::operator<<(std::ostream &output,
                                          const EscapeRoomWrapper &room) {
    return output << room.getName() << " (" << room.getMaxTime() << "/"
                  << room.level() << "/" << room.getMaxParticipants()<< ")";
}