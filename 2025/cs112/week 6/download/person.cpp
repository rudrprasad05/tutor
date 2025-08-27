#include "person.h"

void person::set_id(string id){
	this->id = id;
}
void person::set_name(string name){
	this->name = name;
}
void person::set_address(string address){
	this->address = address;
}
void person::set_phone(string phone){
	this->phone = phone;
}
void person::set_email(string email){
	this->email = email;
}
void person::set_dob(string dob){
	this->dob = dob;
}
void person::set_citizenship(string citizenship){
	this->citizenship = citizenship;
}

void person::print(){
    cout<<"\nID: "<<id;
    cout<<"\nName: "<<name;
    cout<<"\nAddress: "<<address;
    cout<<"\nPhone: "<<phone;
    cout<<"\nEmail: "<<email;
    cout<<"\nDob: "<<dob;
    cout<<"\nCitizenship: "<<citizenship<<endl<<endl;
}

string person::get_id(){
	return id;
}
string person::get_name(){
	return name;
}
string person::get_address(){
	return address;
}
string person::get_phone(){
	return phone;
}
string person::get_email(){
	return email;
}
string person::get_dob(){
	return dob;
}
string person::get_citizenship(){
	return citizenship;
}
