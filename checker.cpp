#include <assert.h>
#include<iostream>

using namespace std;
const float bpmLimit[] = {70 , 150};
const float spo2Bar[] = {90 , 100};
const float respRateLimit[] = {30 , 95};


bool vitalIsNormal(float vitalValue , float lower, float upper){
	bool retval=true;
	if(vitalValue <= lower) {
	cout<<"Very Low "<<vitalValue<<endl;
    retval= false;
  }
  else if(vitalValue >= upper){
  	cout<<"Very high "<<vitalValue<<endl;
  	retval = false;
  }
  else{
  	cout<<"Normal "<<vitalValue<<endl;
  }
  return retval;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (vitalIsNormal(bpm , bpmLimit[0], bpmLimit[1]) && vitalIsNormal(spo2 , spo2Bar[0], spo2Bar[1]) && vitalIsNormal(respRate , respRateLimit[0],respRateLimit[1]));
}

int main() {
	cout<<"1 Testing 'vitalsAreOK()' Method: "<<endl;
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  	cout<<"\nTesting 'vitalIsOK()' Method: "<<endl;
  assert(vitalIsNormal(80, bpmLimit[0],bpmLimit[1]) == true);
  assert(vitalIsNormal(87, spo2Bar[0],spo2Bar[1]) == false);
  assert(vitalIsNormal(98, respRateLimit[0],respRateLimit[1]) == false);
  
}
