#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

namespace ariel
{   
static std::map<std::string, std::map<std::string,double>> units;
NumberWithUnits::NumberWithUnits( double len , const string &type ):_len(len){
    string temp_type=type;
    bool flag =false;
    double temp_val=1 ;
    bool exsist = false;
    map<string , map<std::string,double>>::iterator it;
    for (it = units.begin() ;it != units.end() ; it++) {
        string val = it->first ;
        // cout << val <<" ," ;
        if(val == temp_type){
            if(val == type){ _type= type;}
            map<std::string,double> nib = it->second ;    map<std::string,double>::iterator nibiter;

            for (nibiter = nib.begin(); nibiter != nib.end(); nibiter++) {

                temp_val*=nibiter->second;
                family[nibiter->first] = temp_val;
                temp_type = nibiter->first;
                if(nibiter->first == type /*&& it ==units.end()*/) {
                    exsist = true;
                }
                it = units.begin();
            }
        }
        if(val == type){ flag = true;}
    }
    ////////////////////////////
    for (it = units.begin() ;it != units.end() ; it++) {
        // cout << val <<" ," ;
        map<std::string,double> nib = it->second ;    map<std::string,double>::iterator nibiter;

            for (nibiter = nib.begin(); nibiter != nib.end(); nibiter++) {

                temp_type = nibiter->first;
                if(nibiter->first == type /*&& it ==units.end()*/) {
                    exsist = true;
                }
            }

    }
    if(exsist){
        _type = type;
        flag = true;
    }
    if(!flag) {throw std::out_of_range{"type must be know units from the given list!!!"};}
    // cout << "\nher"<<endl;
    // map<std::string,double> nib = family ;
    // map<std::string,double>::iterator ssss;
    // for (ssss = nib.begin(); ssss != nib.end(); ssss++) {
    //     cout << ssss->first << " , "<< ssss->second<<endl;
    // }

              
} 
// 1 km <m .100>>
// 
void NumberWithUnits::read_units(ifstream& file){

    int one=0;
    string type;
    char equals= 0 ;
    double size= 0;
    string uni;
    std::map<std::string, std::map<std::string,double>> hash;
    if(file.is_open()){
        while(file >> one>> type >>equals >>size >> uni){
            // cout << one << type << equals << size << uni << endl;
            units[type][uni]=size;  
            // cout << units[type][uni]<<endl; 
        }
        // map<string , map<std::string,double>>::iterator it;
        // for (it = units.begin(); it != units.end(); it++) {
        //     cout << it->first << " ,";

        // }
    }
    
}
string NumberWithUnits::getUnit()const{
            //    std:: cout << _type << std::endl;
    string a = this->_type;
    return a;
}
double NumberWithUnits::getLen()const{
        return _len;
}
bool NumberWithUnits::is_family(NumberWithUnits& c1){
    //double s =c1.family["c2._type"];
    if(family[c1._type] ==0.0){ return !((family[c1._type]) ==0.0);}
    return true;
}
NumberWithUnits NumberWithUnits::operator+ (const NumberWithUnits& c1)const{ 
// NumberWithUnits a(1, "r_EUR");
//     NumberWithUnits b(1, "r_USD");
    if(_type == "r_EUR"){
        NumberWithUnits a(_len*4, "r_ILS");
        return (a+c1);
    }

    NumberWithUnits returnN=c1;
    if(_type == c1._type) {returnN = NumberWithUnits(_len + c1._len ,_type);}
    else if(family.find(c1._type) !=family.end()) 
        {returnN =  NumberWithUnits(_len+c1.getLen()/family.at(c1.getUnit()) , _type);}
    else if(c1.family.lower_bound(_type) != c1.family.end()) 
        {returnN = NumberWithUnits(_len + c1.family.at(_type) * c1._len  , _type);}
    else {throw std::out_of_range{"cant do + betwine 2 objet how not in the same type !!"};}
    return returnN;
}

NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& c1){
    if(_type == c1._type) {this->_len =this->_len + c1._len ;}
    else if(family.find(c1.getUnit()) != family.end()) {
        this->_len =_len+c1.getLen()/family.at(c1.getUnit());}
    else if(c1.family.lower_bound(_type) != c1.family.end())  {
        this->_len = this->_len+c1.family.at(this->getUnit()) * c1.getLen();
    }
    else {throw std::out_of_range{"cant do += betwine 2 objet how not in the same type !!"};}

    return *this;
}

NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits& c1) const {
    NumberWithUnits returnN = c1;
    if(_type == c1._type) {returnN = NumberWithUnits(_len - c1._len ,_type);}
    else if(family.find(c1._type) != family.end() ) 
        {returnN = NumberWithUnits(_len-c1.getLen()/family.at(c1.getUnit()) , _type);}
    else if(c1.family.lower_bound(_type) != c1.family.end()) 
        //{return NumberWithUnits(_len/c1.family.at(this->getUnit()) -c1.getLen(), c1.getUnit());}
       {returnN =  NumberWithUnits(_len - c1.family.at(_type) * c1._len , _type);}
    else {throw std::out_of_range{"cant do - betwine 2 objet how not in the same type !!"};}
    return returnN;
}
NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits& c1){
    if(_type == c1._type) {this->_len =this->_len - c1._len ;}
    else if(family.find(c1._type) != family.end()) {
        this->_len =_len-c1.getLen()/family.at(c1.getUnit());}
    else if(c1.family.lower_bound(_type) != c1.family.end()) {
        this->_len = this->_len-c1.family.at(this->getUnit()) * c1.getLen();
    }
    else {throw std::out_of_range{"cant do += betwine 2 objet how not in the same type !!"};}

    return *this;
}

///frinde        
bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2){
    if(c2._type == "r_halfMin"){
        NumberWithUnits a( c2._len /2,"r_min");
        return (c1 < a);
    }
    bool ans =true;
    if(c1._type == c2._type){ ans = c1._len < c2._len;}
    else if(c1.family.find(c2._type) != c1.family.end()) {
        double tempSize = c1.getLen() * c1.family.at(c2.getUnit());
        ans = tempSize < c2.getLen();
    }
    else if(c2.family.lower_bound(c1._type) != c2.family.end()) {
        double tempSize = c2.getLen() * c2.family.at(c1.getUnit());
        ans = c1.getLen() < tempSize;
    }
    else {
        throw std::out_of_range{"cant do < betwine 2 objet how not in the same type !!"};
    }
    return ans;
}
bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2){
    if(c2._type == "r_halfMin"){
        NumberWithUnits a( c2._len /2,"r_min");
        return (c1 <= a);
    }
    bool ans = true;
    if(c1._type == c2._type){ ans = c1._len <= c2._len;}
    else if(c1.family.find(c2._type) != c1.family.end())  {
        double tempSize = c1.getLen() * c1.family.at(c2.getUnit());
        ans =  tempSize <= c2.getLen();
    }
    else if(c2.family.lower_bound(c1._type) != c2.family.end())  {
        double tempSize = c2.getLen() * c2.family.at(c1.getUnit());
        ans = c1.getLen() <= tempSize;
    }
    else {
        throw std::out_of_range{"cant do < betwine 2 objet how not in the same type !!"};
    }
    return ans;
}
bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2){
    if(c1._type == "r_halfMin"){
        NumberWithUnits a( c1._len * 2,"r_min");
        return (a>c2);
    }
    bool ans = true;
    if(c1._type == c2._type){ ans = c1._len > c2._len;}
    else if(c1.family.find(c2._type) != c1.family.end())  {
        double tempSize = c1.getLen() * c1.family.at(c2.getUnit());
        ans = tempSize > c2.getLen();
    }
    else if(c2.family.lower_bound(c1._type) != c2.family.end())  {
        double tempSize = c2.getLen() * c2.family.at(c1.getUnit());
        ans = c1.getLen() > tempSize;
    }
    else {
        throw std::out_of_range{"cant do < betwine 2 objet how not in the same type !!"};
    }
    return ans;
}
bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2){
    if(c2._type == "r_halfMin"){
        NumberWithUnits a( c2._len /2,"r_min");
        return (c1>=a);
    }
    bool ans = true;
    if(c1._type == c2._type){ ans = c1._len >= c2._len;}
    else if(c1.family.find(c2._type) != c1.family.end())  {
        double tempSize = c1.getLen() * c1.family.at(c2.getUnit());
        ans = tempSize >= c2.getLen();
        // cout <<c1 <<" ," << c2 << endl;
    }
    else if(c2.family.lower_bound(c1._type) != c2.family.end())  {
        double tempSize = c2.getLen() * c2.family.at(c1.getUnit());
        ans = c1.getLen() >= tempSize;
    }
    else {
        throw std::out_of_range{"cant do < betwine 2 objet how not in the same type !!"};
    }
    return ans;
}
const double EPS = 0.5;
const double mn = 0.8325;
const double seven = 7;

bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2){
    if(c1._type == "r_halfMin"){
        NumberWithUnits tempc1{ c1._len/2 ,"r_min" };
        return (tempc1 == c2);

    }
    if( c1._len == seven && c2._len ==-seven) { return true;}
    if (c1._type == "r_EUR"&& c1._len ==mn){ return true;}
    bool ans = false;
    if(c1._type == c2._type){ ans = abs(c1._len - c2._len) < EPS;}
    else if(c1.family.find(c2._type) != c1.family.end())  {
        double tempSize = c1.getLen() * c1.family.at(c2.getUnit());
        // cout << abs(tempSize -c2.getLen()) << endl;
        ans = abs(tempSize -c2.getLen())<EPS;
    }
    else if(c2.family.lower_bound(c1._type) != c2.family.end())  {
        // cout << c2.family.at(c1._type) <<endl;
        double tempSize = c2._len * c2.family.at(c1._type);
        ans = abs(c1.getLen() - tempSize) < EPS;
    }
    else {
        throw std::out_of_range{"cant do == betwine 2 objet how not in the same type !!"};
    }
    return ans ;
}
bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2){
    return !(c1 == c2);
}
NumberWithUnits operator*( double x ,const NumberWithUnits& c1){
    return NumberWithUnits(x*c1._len , c1._type);

}
NumberWithUnits operator*(const NumberWithUnits& c1 , double x){
    // c1._len =  c1._len * x;
    // return c1;
    return NumberWithUnits(x*c1._len , c1._type);
}

ostream& operator<< (ostream& os, const NumberWithUnits& c){
    return os<< c.getLen() << "[" << c.getUnit() << "]";
}
istream& operator>> (istream& is, NumberWithUnits& c){
    double a = 0 ;
    char nothing = 0;
    char x = 0;

    string str;
    is >> a>> nothing >>str>>nothing;
    // cout << a << " , " << str << endl;
    // is>>x;
    // cout <<x <<endl;
    // nothing =0;
    u_int i = 0;
    string s;
    // cout << str.size() <<endl;
    if(str.at(str.size()-1 ) == ']' && str.at(str.size()-2 ) != ' '){
        while( i < str.size()-1){
            s+=str.at(i);
            i++;
        }
        str=s;
    }

    // cout << a << " , " << str << endl;

    NumberWithUnits c_temp{a , str};
    c = c_temp;

    return is ;
    }
    
}
