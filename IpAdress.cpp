#include "IpAdress.h"

using namespace std;

IpAdress::IpAdress(const string& theString)
{
    myStringRepresentation = GetIpAdress (theString);
    TransformToNumbers();
}

bool IpAdress::operator < (const IpAdress& theIpAdress)
{
    bool aRes = false;
    for (size_t i = 0; i < myNumbers.size(); ++i) {
        if (myNumbers[i] == theIpAdress.myNumbers[i])
            continue;
        else if (myNumbers[i] < theIpAdress.myNumbers[i]) {
            aRes = true;
            return aRes;
        }
        else if (myNumbers[i] >= theIpAdress.myNumbers[i]) {
            aRes = false;
            return aRes;
        }
    }
    return aRes;
}

bool IpAdress::operator <= (const IpAdress& theIpAdress)
{
    return ((*this < theIpAdress) || (*this == theIpAdress));
}

bool IpAdress::operator > (const IpAdress& theIpAdress)
{
    if (*this == theIpAdress) {
        return false;
    }
    return !(*this < theIpAdress);
}

bool IpAdress::operator >= (const IpAdress& theIpAdress)
{
    return ((*this > theIpAdress) || (*this == theIpAdress));
}

bool IpAdress::operator == (const IpAdress& theIpAdress)
{
    bool aRes = true;
    for (size_t i = 0; i < myNumbers.size(); ++i) {
        if (myNumbers[i] != theIpAdress.myNumbers[i])
            aRes = false;
    }
    return aRes;
}

bool IpAdress::operator != (const IpAdress& theIpAdress)
{
    return !(*this == theIpAdress);
}

std::istream& operator>> (std::istream& theInput, IpAdress& theIpAdress) {
    string aStringRep;
    theInput >> aStringRep;
    theIpAdress  = IpAdress(aStringRep);
    return theInput;
}

std::ostream& operator<< (std::ostream& theOutput, IpAdress& theIpAdress) {
    theOutput << theIpAdress.myStringRepresentation;
    return theOutput;
}

string IpAdress::GetIpAdress (const string& theString)
{
    auto isFound = theString.find ("\t");
    string anIpString;
    if (isFound != string::npos) {
        anIpString = theString.substr (0, isFound);
    }
    return anIpString;
}

void IpAdress::TransformToNumbers()
{
    string aStringRepresentation = myStringRepresentation;
    vector <string> aStringNumbers;
    aStringNumbers.reserve(4);

    while (aStringRepresentation.size() != 0)
    {
        auto aSubStr = aStringRepresentation.find(".");
            if (aSubStr != string::npos) {
                auto aSubString = aStringRepresentation.substr (0, aSubStr);
                aStringNumbers.push_back (aSubString);
            }
            else {
                aStringNumbers.push_back (aStringRepresentation);
                break;
            }
        aStringRepresentation = aStringRepresentation.erase (0, aSubStr + 1);
    }

    for (size_t i = 0; i < myNumbers.size(); ++i) 
    {
        unsigned long ulongValue = std::stoul (aStringNumbers[i]);
        if (ulongValue <= 255) {
            myNumbers[i] = static_cast<uint8_t> (ulongValue);
        }
    }
}