#include <iostream>
using namespace std;

struct Birthday{
  int year;
  string month;
  int day;
};

struct Person{
  Birthday b;
  string gender;
} person;

struct MD{
  string m;
  int d;
} md;

MD monthAndDate(int val, int n = 0){
  if(val <= 31) return {"January", val};
  else if(val <= 60) return {"February", val - 31};
  else if(val <= 91) return {"March", val - 60};
  else if(val <= 121) return {"April", val - 91};
  else if(val <= 152) return {"May", val - 121};
  else if(val <= 182) return {"June", val - 152};
  else if(val <= 213) return {"July", val - 182};
  else if(val <= 244) return {"August", val - 213};
  else if(val <= 274) return {"September", val - 244};
  else if(val <= 305) return {"October", val - 274};
  else if(val <= 335) return {"November", val - 305};
  else if(val <= 366) return {"December", val - 334 - n};
  else return {"Wrong NIC Number", -1};
}

Person _nic(string nic,int n = 0){
  int year = atoi(nic.substr(0, 2 + n).c_str());
  person.b.year = n ? year: 1900 + year;
  int gen = atoi(nic.substr(2 + n, 3).c_str());
  person.gender = (gen < 500) ? "Male": "Female";
  gen = (gen > 500) ? gen - 500: gen;
  md = monthAndDate(gen);
  person.b.month = md.m;  
  person.b.day = md.d;
  return person;
}


int main(){
  string nic;
  cout << "[?] Valid for all(old + new) SL NICs." << endl;
  cout << "[i] Enter NIC No(without V): ";
  cin >> nic;
  cout << "----------------------------------------" << endl;
  if((nic.length() == 9 || nic.length() == 12)){
    int n = (nic.length() == 9) ? 0: 2;
    person = _nic(nic, n);
    if(person.b.day != -1){
      cout << "[*] Birth Day: " << person.b.year << " " << person.b.month << " " << person.b.day << endl;
      cout << "[*] Gender: " << person.gender << endl;
    } else cout << "[x] Wrong NIC Number" << endl;
  } else cout << "[x] Wrong NIC Number" << endl;
  return 0;
}
