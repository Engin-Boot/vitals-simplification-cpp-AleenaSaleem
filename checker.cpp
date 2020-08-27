#include<iostream>
#include<assert.h>
using namespace std;

const int n_vitals = 3; //3 In this case.
typedef struct Vitals{
	string vitalName="";
	float vitalValue;
	float lower,upper;
}vital;
vital allVitals[n_vitals];

void initializeVitalsInformation(){
	int loopCounter=0;
	string name;
	float lower, upper;
	for(loopCounter=0;loopCounter<n_vitals;loopCounter++){
		cin>>name>>lower>>upper;
		allVitals[loopCounter].vitalValue = 0; //initially - before any real input
		allVitals[loopCounter].vitalName = name;
		allVitals[loopCounter].lower = lower;
		allVitals[loopCounter].upper = upper;
		cout<<allVitals[loopCounter].vitalName<<endl;
	}

}

void getCurrentVitalValues(){
	int loopCounter=0;
	float value;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		cin>>value;
		allVitals[loopCounter].vitalValue = value;
	}
}

bool vitalIsNormal(float vitalValue , float lower, float upper){
	bool retval=true;
	if(vitalValue <= lower) {
	cout<<"Very Low with value : "<<vitalValue<<endl;
    retval= false;
  }
  else if(vitalValue >= upper){
  	cout<<"Very high with value : "<<vitalValue<<endl;
  	retval = false;
  }
  else{
  	cout<<"Normal with value : "<<vitalValue<<endl;
  }
  return retval;
}

bool vitalsAreNormal(){
	int loopCounter = 0;
	bool status = true;
	for(loopCounter=0;loopCounter<n_vitals;loopCounter++){
		cout<<allVitals[loopCounter].vitalName<<" status -  ";
		bool new_status = vitalIsNormal(allVitals[loopCounter].vitalValue , allVitals[loopCounter].lower , allVitals[loopCounter].upper);
		status = status && new_status;
	}
	return status;
}
int main(){
	initializeVitalsInformation(); // one time thing
	//Check if all vitals are in normal range
	int loopCounter=0;     
	getCurrentVitalValues(); //This needs to be called continuously hard coding initially
	//bool status = vitalsAreNormal();
		/*
		allVitals[0].vitalValue = 72; 
		allVitals[0].vitalName = "bpm";
		allVitals[0].lower = 70;
		allVitals[0].upper = 150;
		
		allVitals[1].vitalValue = 95; 
		allVitals[1].vitalName = "SpO2";
		allVitals[1].lower = 90;
		allVitals[1].upper = 100;
		
		allVitals[2].vitalValue = 65; 
		allVitals[2].vitalName = "RespRate";
		allVitals[2].lower = 30;
		allVitals[2].upper = 70;
		*/
	assert(vitalsAreNormal() == true);
	assert(vitalsAreNormal() == false);

	return 0;
}
