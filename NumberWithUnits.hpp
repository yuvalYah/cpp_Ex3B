#pragma once

#include <iostream>
#include <map>

namespace ariel
{
    class NumberWithUnits
    {
        private:
            double _len;
            std::string _type="";

            std::map<std::string, double> family;

            bool is_family(NumberWithUnits& c1);
       
        public:

            NumberWithUnits( double len, const std::string &type );
            static void read_units(std::ifstream& file );
            std::string getUnit()const;
            double getLen()const;
            
            NumberWithUnits operator+ (const NumberWithUnits& c1)const;//v
            NumberWithUnits& operator+=(const NumberWithUnits& c1);//v
            NumberWithUnits operator+ (){ // v
                return *this;
            }
            NumberWithUnits operator- (const NumberWithUnits& c1) const ;//v
            NumberWithUnits& operator-= (const NumberWithUnits& c1);//v
            NumberWithUnits operator- (){ //v
                // this->_len = -_len;
                // return *this;
                return NumberWithUnits(-_len , _type);
            }

            friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);//v
            friend bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2);
            friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);
            NumberWithUnits& operator++() {
                _len = _len +1;
               return *this;

            }
            const NumberWithUnits operator++(int) {
                NumberWithUnits copy = *this;
                _len = _len +1;
                return copy;

            }
            NumberWithUnits& operator--() {
                _len = _len - 1;
                return *this;
            }
            const NumberWithUnits operator--(int) {
                NumberWithUnits copy = *this;
                _len = _len - 1;
                return copy;
            }
            friend NumberWithUnits operator*(double x ,const NumberWithUnits& c1);
            friend NumberWithUnits operator*(const NumberWithUnits& c1,double x  );


            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& c);
            friend std::istream& operator>> (std::istream& is, NumberWithUnits& c);









    };
}
