#include "Enigma.h"

using mtm::escaperoom::Enigma;
using mtm::escaperoom::Difficulty;
Enigma::Enigma(const std::string &name, const Difficulty &difficulty,
               const int &numOfElements) {
    this->name=name;
    this->difficulty=difficulty;
    this->numOfElements=numOfElements;
}
Difficulty Enigma::getDifficulty() const {
    return difficulty;
}
string Enigma::getName() const {
    return name;
}
bool Enigma::operator==(const Enigma &enigma) const {
    return ((getName()==enigma.getName())&&(getDifficulty()
                                            == enigma.getDifficulty()));
}
bool Enigma::operator!=(const Enigma& enigma) const{
    return (!(*this==enigma));
}
bool Enigma::operator>(const Enigma& enigma) const{
    return (getDifficulty()>enigma.getDifficulty());
}
bool Enigma::operator<(const Enigma& enigma) const{
    return (enigma>*this);
}
bool Enigma::areEqualyComplex(const Enigma &enigma) const {
    return (getDifficulty()==enigma.getDifficulty()) &&
            ((numOfElements==enigma.numOfElements));
}

std::ostream& mtm::escaperoom::operator<<(std::ostream &output, const Enigma &enigma) {
    return output<<enigma.getName() <<" ("
                 <<enigma.getDifficulty() << ") " <<enigma.numOfElements;
}

