

#include "Flow.h"

void Flow::init()
{
    pinMode(pulse_ip, INPUT);
    volume = 0;
    maxFlow = 0;
    activeMeasurement = false;
    startTime = 0;
    wifi.init();
}

void Flow::measureFlow(String rfid)
{

    while (true)
    {

        // put your main code here, to run repeatedly:
        ontime = pulseIn(pulse_ip, HIGH);
        offtime = pulseIn(pulse_ip, LOW);

        period = ontime + offtime;
        if (period > 0)
        {
            freq = 1000000 / period;
        }
        else
        {
            freq = 0;
        }

        flow = freq / 7.5 * 1000 / 60;

        if (!activeMeasurement && flow > 0)
        {
            activeMeasurement = true;
            startTime = millis();
        }
        else if (flow > 0 && activeMeasurement)
        {
            if (flow > maxFlow)
            {
                maxFlow = flow;
            }
            volume += flow * 0.033;
            startTime = millis();
        }

        else if (flow == 0 && activeMeasurement && (millis() - startTime < 5000))
        {
            activeMeasurement = false;

            wifi.sendData((int)maxFlow * 1000, (int)volume * 1000, rfid);

            maxFlow = 0;
            volume = 0;
            return;
        }

        delay(10);
    }
}
