#include<iostream>
#include<assert.h>
#include<sstream>
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
		//void setCurrentValue();
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
/*void Vital::setCurrentValue(){
	float value;
	cin>>value;
	this->vitalValue = value;
}*/

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
//.............................................................

class Alert{
	public:
		virtual void sendAlert(const string*, const string*)=0;
};

class AlertInSMS: public Alert{
	public:
		void sendAlert(const string*, const string*);
};
class AlertInIntercom: public Alert{
	public:
		void sendAlert(const string*,const string*);
};

void AlertInSMS::sendAlert(const string* name, const string* message){
	cout<<*name<<" - "<<*message<<endl;
}

void AlertInIntercom::sendAlert(const string* name, const string* message){
	cout<<*name<<" - "<<*message<<endl;
}
//...................................................................................
class MonitorVitals{
	public:
		Alert* alertNow;
		bool vitalsAreNormal(Alert*,string*, string*);
		void alertRequired(Alert*,string*, string*);
		void sendNow();
		
};


bool vitalIsNormal(float vitalValue , float lower, float upper,string* message){
	bool retval=true;
	if(vitalValue <= lower) {
	//cout<<"Very Low with value : "<<vitalValue<<endl;
	ostringstream ss;
    ss << vitalValue;
	*message = "Very Low with value : ";
	*message += ss.str();
    retval= false;
  }
  else if(vitalValue >= upper){
  	//cout<<"Very high with value : "<<vitalValue<<endl;
  	ostringstream ss;
    ss << vitalValue;
	*message = "Very high with value : ";
	*message += ss.str();
  	retval = false;
  }
  else{
  	ostringstream ss;
    ss << vitalValue;
	*message = "Normal with value : ";
	*message += ss.str();
  	//cout<<"Normal with value : "<<vitalValue<<endl;
  }
  return retval;
}

void MonitorVitals::alertRequired(Alert* alertNow,string* name, string* message){	
	this->alertNow = alertNow;
	(this->alertNow)->sendAlert(name,message);
}

bool MonitorVitals::vitalsAreNormal(Alert* alertNow,string* v_name, string* message){
	int loopCounter = 0;
	bool status = true;
	for(loopCounter=0;loopCounter<n_vitals;loopCounter++){
	//	cout<<allVitals[loopCounter].getName()<<" status -  ";
		*v_name = allVitals[loopCounter].getName();
		bool new_status = vitalIsNormal(allVitals[loopCounter].getValue() , allVitals[loopCounter].getLower() , allVitals[loopCounter].getUpper(),message);
		status = status && new_status;
	}
	alertRequired(alertNow,v_name,message);
	return status;
}
