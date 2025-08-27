#include <string>
#include <iostream>
using namespace std;

class person{
    public:
        person(){;}
        ~person(){;}

        void set_id(string);
        void set_name(string);
        void set_address(string);
        void set_phone(string);
        void set_email(string);
        void set_dob(string);
        void set_citizenship(string);
        void print();

        string get_id();
        string get_name();
        string get_address();
        string get_phone();
        string get_email();
        string get_dob();
        string get_citizenship();
    private:
        string id;
        string name;
        string address;
        string phone;
        string email;
        string dob;
        string citizenship;
};

