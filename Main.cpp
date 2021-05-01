#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
  

  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);
  
  NumberWithUnits tenKM{10, "km"};

  cout << "Basic operators:"<< endl;
  cout << "Should print 10[km]. Result: " << tenKM << endl;
  cout << "Should print -10[km]. Result: " << (-tenKM) << endl;
  cout << "Should print 7*10[km]. Result: " << (7*tenKM) << endl;
  cout << "Should print 10[km]*8. Result: " << (tenKM*8) << endl;
  cout << "Should print 10[km]. Result: " << tenKM << endl << endl; //To check original variable

  NumberWithUnits hundredM{100, "m"};  
  NumberWithUnits thousandCM{1000, "cm"};   
  NumberWithUnits fivehundredMM{500, "mm"};

  cout << "Add/Subtract operators:" << endl;
  cout << "Should print 10[km]+100[m]. Result: " << tenKM + hundredM << endl;
  cout << "Should print 100[m]+10[km]. Result: " << hundredM + tenKM << endl;
  cout << "Should print 10[km]+500[mm]. Result: " << tenKM + fivehundredMM << endl;
  cout << "Should print 10[km]-1000[cm]. Result: " << tenKM - thousandCM << endl;
  NumberWithUnits testAddition = tenKM; //copy
  cout << "Should print 10[km]+=100[m]. Result: " << (testAddition+=hundredM) << endl;
  cout << "Should print 10.1[km]. Result: " << testAddition << endl;
  cout << "Should print 10.1[km]-=1000[cm]. Result: " << (testAddition-=thousandCM) << endl;
  cout << "Should print 10.09[km]. Result: " << testAddition << endl << endl;

  cout << "Boolean operators:" <<endl;
  cout << boolalpha; // print booleans as strings from now on:
  cout << "Should print 10[km]>100[m]. Result: " << (tenKM > hundredM) << endl;
  cout << "Should print 100[m]<500[mm]. Result: " << (hundredM < fivehundredMM) << endl;
  cout << "Should print 10[km]<=500[mm]. Result: " << (thousandCM <= fivehundredMM) << endl;
  cout << "Should print 10[km]>=1000[cm]. Result: " << (tenKM >= NumberWithUnits{1000,"cm"}) << endl;
  cout << "Should print 10[km]==10000[m]. Result: " << (tenKM == NumberWithUnits{10000,"m"}) << endl;
  cout << "Should print 100[m]!=500[mm]. Result: " << (hundredM != fivehundredMM) << endl;
  cout << "Should print ++10.09[km]. Result: " << (++testAddition) << endl;
  cout << "Should print 11.09[km]++. Result: " << (testAddition++) << endl;
  cout << "Should print 12.09[km]. Result: " << (testAddition) << endl << endl;

  istringstream sample_input{"6 [ hour ]"};
  cout << "Testing input/output" << endl;
  sample_input >> testAddition;
  cout << "Input with >> should print 6[hour]. Result: " << testAddition <<endl<<endl;

  try {
    cout << (testAddition + tenKM) << endl;  
  } catch (exception& ex) {
    cout << ex.what() << endl;
    cout << "Tried to add units that won't convert and failed." << endl<<endl;
  }
  try {
    cout << NumberWithUnits{5,"year"} << endl;  
  } catch (exception& ex) {
    cout << ex.what()<<endl;
    cout << "Tried to create a unit that doesn't exist and failed." << endl;
  }

  return 0;
}
