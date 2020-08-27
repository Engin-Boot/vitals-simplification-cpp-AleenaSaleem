#include <assert.h>
#include<iostream>

using namespace std;
const float bpmLimit[] = {70 , 150};
const float spo2Bar = 90;
const float respRateLimit[] = {30 , 95};

bool isBPMNormal(float bpm){
	bool retval=true;
	if(bpm < bpmLimit[0]) {
	cout<<"BPM Very Low"<<endl;
    retval= false;
  }
  if(bpm > bpmLimit[1]){
  	cout<<"BPM Very high"<<endl;
  	retval = false;
  }
  
  return retval;
}

bool isspo2Normal(float spo2){
	bool retval=true;
	if(spo2 < spo2Bar) {
	cout<<"Oxygen saturation low!"<<endl;
    retval = false;
  }
  return retval;
}

bool isRespRateNormal(float respRate){
	bool retval = true;
	if(respRate < respRateLimit[0]) {
	cout<<"Respiration rate low"<<endl;
    retval = false;
  }
  if(respRate > respRateLimit[1]){
  	cout<<"Respiration Rate High"<<endl;
  	retval = false;
  }
  return retval;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (checkBPM(bpm)&&checkspo2(spo2)&&checkRespRate(respRate));
}


int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(checkBPM(78) == true);
  assert(checkBPM(165) == false);
  assert(checkspo2(98) == true);
  assert(checkspo2(85) == false);
  assert(checkRespRate(87) == true);
  assert(checkRespRate(96) == false);
}
