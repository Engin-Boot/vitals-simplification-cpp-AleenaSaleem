#include"VitalsInformation.h"

void Initialize(){
	int loopCounter = 0;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		allVitals[loopCounter].Initialize();
	}
}

void updateVitals(){
	int loopCounter;
	float value;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		cin>>value;
		allVitals[loopCounter].setValue(value);
	}
}

int main(){
	Initialize();
	MonitorVitals mv;
	string message="";
	AlertInSMS al;
	AlertInIntercom alIntercom;
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&message)==true);
	message = "";
	updateVitals();
	assert(mv.vitalsAreNormal(&alIntercom,&message)==false);
	message = "";
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&message)==false);


	return 0;
}
