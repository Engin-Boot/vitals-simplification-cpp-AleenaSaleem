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

void initializeVitalsInformation(string name, float lower float upper){
	int loopCounter=0;
	//string name;
	float lower, upper;
	for(loopCounter=0;loopCounter<n_vitals;loopCounter++){
		//cin>>name>>lower>>upper;
		allVitals[loopCounter].vitalValue = 0; //initially - before any real input
		allVitals[loopCounter].vitalName = name;
		allVitals[loopCounter].lower = lower;
		allVitals[loopCounter].upper = upper;
		cout<<allVitals[loopCounter].vitalName<<endl;
	}

}

void getCurrentVitalValues(float value){
	int loopCounter=0;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		//cin>>value;
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
	getCurrentVitalValues(); //This needs to be called continuously
	//bool status = vitalsAreNormal();
	initializeVitalsInformation("bpm", 70, 150);
	initializeVitalsInformation("SpO2" , 90, 100);
	initializeVitalsInformation("Resprate", 30, 70);
	//Hard coding initially
	getCurrentVitalValues(72);
	getCurrentVitalValues(95);
	getCurrentVitalValues(65);
	
	assert(vitalsAreNormal() == true);
	
	//Hard coding initially
	getCurrentVitalValues(75);
	getCurrentVitalValues(98);
	getCurrentVitalValues(75);
	
	assert(vitalsAreNormal() == false);

	return 0;
}
