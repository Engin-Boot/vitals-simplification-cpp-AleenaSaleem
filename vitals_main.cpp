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
	int loopCounter = 0;
	Initialize();
	float value;
	MonitorVitals mv;
	string name="";
	string message="";
	AlertInSMS al;
	//mv.alertRequired(&al,&name,&message);
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&name,&message)==true);
	name = "";
	message = "";
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&name,&message)==false);
	name ="";
	message = "";
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&name,&message)==false);


	return 0;
}
