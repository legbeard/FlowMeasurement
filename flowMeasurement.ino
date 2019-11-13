
#define pulse_ip D7
int ontime,offtime,duty;
float freq,period, flow, volume, maxFlow;
long startTime;
bool activeMeasurement;

void setup() {
  // put your setup code here, to run once:
   pinMode(pulse_ip,INPUT);
   Serial.begin(115200);
   volume = 0;
   maxFlow = 0;
   activeMeasurement = false;
   startTime = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  ontime = pulseIn(pulse_ip,HIGH);
  offtime = pulseIn(pulse_ip,LOW);
   
  period = ontime+offtime;
  if(period > 0){
    freq = 1000000/period;
  } else {
    freq = 0;
  }

  flow = freq/7.5*1000/60;
  
  Serial.print("Period :");
  Serial.print(period);
  Serial.print(" us, Frequency: ");
  Serial.print(freq);
  Serial.print(" Hz, Flow : ");
  Serial.print(flow);
  Serial.println(" mL/s");

  if(!activeMeasurement && flow > 0){
    activeMeasurement = true;
    startTime = millis();
  } 
  else if (flow > 0 && activeMeasurement) {
    if(flow > maxFlow)
    {
      maxFlow = flow;
    }
    volume += flow*0.01;
    startTime = millis();
  } 
  else if (flow == 0 && activeMeasurement)
  {
    activeMeasurement = false;

    Serial.print("Measurement finished, total volume: ");
    Serial.print(volume);
    Serial.print(" mL, Maximum flow: ");
    Serial.print(maxFlow);
    Serial.println(" mL/s");
    maxFlow = 0;
    volume = 0;
  }
  
  delay(10);
}
