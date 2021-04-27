/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cfloat>

using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
 /* ifstream units_file{"myTestFile.txt"};
  NumberWithUnits::read_units(units_file);
    // CHECK((hourMAX+day1)==NumberWithUnits(DBL_MAX-24,"hour"));

    NumberWithUnits hourMAX=NumberWithUnits(DBL_MAX,"hour");
    NumberWithUnits day1=NumberWithUnits(1,"day");
    NumberWithUnits shit = hourMAX +day1;
    NumberWithUnits fsh (DBL_MAX+24,"hour");
    cout << ((shit)==fsh) << endl;
    cout << shit.getUnit() << " , " << (shit.getLen()/24) << endl;
    cout << fsh.getUnit() << " , " << fsh.getLen() << endl;
    */ofstream myfile;
    myfile.open ("myTestFile.txt");
    myfile << "1 km = 1000 m" << endl;
    myfile << "1 m = 100 cm" << endl;
    myfile << "1 kg = 1000 g" << endl;
    myfile << "1 ton = 1000 kg" << endl;
    myfile << "1 hour = 60 min" << endl;
    myfile << "1 min = 60 sec" << endl;
    myfile << "1 day = 24 hour" << endl;
    myfile << "1 month = 30 day" << endl;
    myfile << "1 year = 12 month" << endl;   
    myfile.close(); 
    ifstream unitsfile{"myTestFile.txt"};
    NumberWithUnits::read_units(unitsfile);

    myfile.open ("myTestFile.txt");
    myfile << "1 USD = 3.33 ILS" << endl;
    myfile.close(); 
    ifstream units_file{"myTestFile.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits hourMAX(3,"km");



  //  stringstream out_30_kg;
  //   stringstream out_1_hour;
  //   stringstream out__6_min;
  //   stringstream out_999999_day;
  //   stringstream out_MIN;
  //   stringstream out_MAX;
  //   out_30_kg << NumberWithUnits(30,"kg");
  //   out_1_hour << NumberWithUnits(1,"hour");
  //   out__6_min << NumberWithUnits(-6,"min");
  //   out_999999_day << NumberWithUnits(999999,"day");
  //   out_MAX << NumberWithUnits(DBL_MAX,"day");
  //   out_MIN << NumberWithUnits(DBL_MIN,"day");
  //   cout <<(out_30_kg.str()=="30[kg]") <<endl;
  //   cout << (out_1_hour.str()=="1[hour]") << endl;  
  //   cout << (out__6_min.str()=="-6[min]")<<endl;
  //   cout << (out_999999_day.str()=="999999[day]") << endl;
  //   cout << (out_MAX.str()=="1.79769e+308[day]") << endl;
  //   cout <<(out_MIN.str()=="2.22507e-308[day]") << endl;
  /*
  NumberWithUnits a{2, "km"};   // 2 kilometers
  cout << a << endl;           // Prints "2[km]".
  cout << (-a) << endl;    // Prints "-2[km]"
  cout << (3*a) << endl;    // Prints "6[km]"

  NumberWithUnits b{300, "m"};  // 300 meters
  cout << (b+a) << endl;   // Prints "2.3[km]". Note: units are determined by first number (a).
  cout << (b-a) << endl;   // Prints "-1700[m]". Note: units are determined by first number (b).

  cout << boolalpha; // print booleans as strings from now on:
  cout << (a>b) << endl;  // Prints "true"
  cout << (a<=b) << endl;  // Prints "false"
  cout << (a==NumberWithUnits{2000, "m"}) << endl;  // Prints "true"

  istringstream sample_input{"700 [ kg ]"};
  sample_input >> a;
  cout << a << endl;   // Prints "700[kg]"
  cout << (a += NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
  cout << a << endl;   // Prints "1700[kg]". Note that a has changed.

  try {
    cout << (a+b) << endl;  
  } catch (const std::exception& ex) {
    cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
  }
  cout << "End of demo!" << endl; */
  return 0;
}