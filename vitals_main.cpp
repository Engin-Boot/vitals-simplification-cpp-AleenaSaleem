#include"VitalsInformation.h"
void Initialize(){
	int loopCounter = 0;
	for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
		allVitals[loopCounter].Initialize();
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
		cout<<allVitals[loopCounter].getName()<<" status -  ";
		bool new_status = vitalIsNormal(allVitals[loopCounter].getValue() , allVitals[loopCounter].getLower() , allVitals[loopCounter].getUpper());
		status = status && new_status;
	}
	return status;
}

int main(){
	int loopCounter = 0;
	Initialize();
	int n_times_while_loop_runs = 5; // Don't know the terminating condition yet. While loop runs continuously until device shuts down.
	while(n_times_while_loop_runs){ 
		for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
			allVitals[loopCounter].setCurrentValue();
		}
		bool status = vitalsAreNormal();
		n_times_while_loop_runs--;
		//cout<<endl<<status<<endl;
	}
	//Add tests for vitalIsOk() and vitalsAreOk() - 3 for each
	return 0;
}
