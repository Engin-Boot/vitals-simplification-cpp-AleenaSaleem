#include<iostream>
#include<assert.h>

using namespace std;

const int n_vitals = 3;

class Vital{
	
	string vitalName;
	float vitalValue, lower, upper;
	public:
		Vital();
		Vital(string,float,float);
		void setName(string);
		void setValue(float);
		void setLower(float);
		void setUpper(float);
		string getName();
		float getValue();
		float getLower();
		float getUpper();
		void Initialize();
		void setCurrentValue();
};

Vital allVitals[n_vitals];

Vital::Vital(){
	this->vitalValue = 0;
	this->lower = 0;
	this->upper = 0;
}
Vital::Vital(string name, float lower, float upper){
	this->vitalName = name;
	this->lower = lower;
	this->upper = upper;
}

void Vital::Initialize(){
	string name;
	float lower, upper;
	cin>>name>>lower>>upper;
	this->vitalName = name;
	this->lower = lower;
	this->upper = upper;
}
void Vital::setName(string name){
	this->vitalName = name;
}

void Vital::setValue(float value){
	this->vitalValue = value;
}

void Vital::setLower(float lower){
	this->lower = lower;
}

void Vital::setUpper(float upper){
	this->upper =  upper;
}
void Vital::setCurrentValue(){
	int loopCounter=0;
	float value;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		cin>>value;
		allVitals[loopCounter].vitalValue = value;
	}
}

string Vital::getName(){
	return this->vitalName;
}

float Vital::getValue(){
	return this->vitalValue;
}
float Vital::getLower(){
	return this->lower;
}

float Vital::getUpper(){
	return this->upper;
}
