#pragma once
#include <vector>
#include <string>
#include <array>

class IpAdress
{

public:
    IpAdress() {}

    explicit IpAdress (const std::string& theString);

    bool operator < (const IpAdress& theIpAdress);

    bool operator <= (const IpAdress& theIpAdress);

    bool operator > (const IpAdress& theIpAdress);

    bool operator >= (const IpAdress& theIpAdress);

    bool operator == (const IpAdress& theIpAdress);

    bool operator != (const IpAdress& theIpAdress);

    friend std::istream& operator>>(std::istream& theInput, IpAdress& theIpAdress);

    friend std::ostream& operator<<(std::ostream& theOutput, IpAdress& theIpAdress);

private:

    std::string GetIpAdress (const std::string& theString);
    void TransformToNumbers();

private:
    std::array<uint8_t, 4> myNumbers;
    std::string myStringRepresentation;
};
