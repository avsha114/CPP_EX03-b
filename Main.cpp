#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;


int main()
{
    ifstream units_file{"filename.txt"};
    NumberWithUnits::read_units(units_file);

    istringstream iss{""};
    NumberWithUnits a{1, "r_km"};
    iss >> a;
    cout << a;
}