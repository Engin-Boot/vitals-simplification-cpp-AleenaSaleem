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
	char c;
	while((c=getchar())!='E'){ //lets say 'E' is some terminating condition indicating device has been shut down
		for(loopCounter = 0; loopCounter < n_vitals; loopCounter++){
			allVitals[loopCounter].setCurrentValue();
		}
		bool status = vitalsAreNormal();
		//cout<<endl<<status<<endl;
	}
	return 0;
}
