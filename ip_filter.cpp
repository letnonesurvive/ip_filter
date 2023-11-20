// otus-cpp-dz2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "IpAdress.h"

using namespace std;
 
int main (int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file> where:"     << endl;
        cout << "    <input_file>  is a name of the file with ip adresses to be read"         << endl;
        return 1;
    }

    std::ifstream anInputFile (argv[1]);

    vector<IpAdress> anIpAdresses;
    string anInputString;

    if (!anInputFile.is_open()) {
        cout << "File doesn't open" << endl;
        return 1;
    }

    while (std::getline (anInputFile, anInputString)) {
         anIpAdresses.emplace_back (anInputString);
    }
    
    std::sort (anIpAdresses.begin(), anIpAdresses.end(), [](IpAdress& theFirst, const IpAdress& theSecond) {
        return theFirst > theSecond;
    });

    setlocale(LC_ALL, "Russian");

    cout << endl;
    cout << "1. ������ ������ ������� ����� ����������. ���� ������ - ���� �����." << endl;
    for (auto& anIp : anIpAdresses) {
        cout << anIp << endl;
    }

    cout << endl;
    cout << "2. ����� ������ ������ �������, ������ ���� ������� ����� 1. ������� ���������� �� ��������. \n"
            "���� ������ - ���� �����. ������ ����� �� �����������." << endl;
    IpAdress aVal2 ("2.0.0.0\t");
    for (auto& anIp : anIpAdresses) {
        if (anIp < aVal2) {
            cout << anIp << endl;
        }
    }

    cout << endl;
    cout << "3. ����� ������������ ������ �������, ������ ���� ������� ����� 46, � ������ 70. ������� \n"
            "���������� �� ��������. ���� ������ - ���� �����. ������ ����� �� �����������." << endl;
    IpAdress aVal3 ("46.70.0.0\t");
    IpAdress aVal4 ("47.0.0.0\t");
    IpAdress aVal5 ("46.71.0.0\t");

    for (auto& anIp : anIpAdresses) {
        if ((aVal3 <= anIp) && (anIp < aVal4) && (anIp < aVal5)) {
            cout << anIp << endl;
        }
    }

    cout << endl;
    cout << "4. ����� ������������ ������ �������, ����� ���� ������� ����� 46. ������� ���������� �� \n"
            "��������. ���� ������ - ���� �����. ������ ����� �� �����������." << endl;
    IpAdress aVal6 ("46.0.0.0\t");
    for (auto& anIp : anIpAdresses) {
        if (anIp >= aVal6 && anIp < aVal4) {
            cout << anIp << endl;
        }
    }

    return 0;
}
