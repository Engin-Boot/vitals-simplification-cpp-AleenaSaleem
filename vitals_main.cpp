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
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&name,&message)==false);
	updateVitals();
	assert(mv.vitalsAreNormal(&al,&name,&message)==false);


	return 0;
}

int main(){
	int loopCounter = 0;
	Initialize();
	float value;
	//int n_times_while_loop_runs = 3;
	// Don't know the terminating condition yet. While loop runs continuously until device shuts down.
	/*while(n_times_while_loop_runs){ 
		updateVitals();
		cout<<vitalsAreNormal()<<endl;
		
		n_times_while_loop_runs--;
		//cout<<endl<<status<<endl;
	}*/
	//Add tests for vitalIsOk() and vitalsAreOk() - 3 for each
	//How to ? There is no console input. Need to hard code!
	updateVitalsvalues();
	assert(vitalsAreNormal()==true);
	updateVitalsvalues();
	assert(vitalsAreNormal()==false);
	updateVitalsvalues();
	assert(vitalsAreNormal()==false);

	return 0;
}
