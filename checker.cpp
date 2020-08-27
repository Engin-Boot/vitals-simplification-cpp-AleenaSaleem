#include <assert.h>
#include<iostream>

using namespace std;
const float bpmLimit[] = {70 , 150};
const float spo2Bar = 90;
const float respRateLimit[] = {30 , 95};

bool checkBPM(float bpm){
	bool retval=true;
	if(bpm < bpmLimit[0] || bpm > bpmLimit[1]) {
	cout<<"BPM abnormal"<<endl;
    retval= false;
  }
  
  return retval;
}

bool checkspo2(float spo2){
	bool retval=true;
	if(spo2 < spo2Bar) {
	cout<<"Oxygen saturation low!"<<endl;
    retval = false;
  }
  return retval;
}

bool checkRespRate(float respRate){
	bool retval = true;
	if(respRate < respRateLimit[0] || respRate > respRateLimit[1]) {
	cout<<"Respiration rate abnormal"<<endl;
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
}
