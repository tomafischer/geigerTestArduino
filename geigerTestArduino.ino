int pin = 2;
    int pin2 = 3;
    
    //counts per second. the receiving board can support only 20K cps
    long cps = 1000;
    
    long periodMicros = 0;
    
    unsigned long start;
    
    unsigned long startDebug;
    
    unsigned long end;
    
    
    
    void setup()
    
    {
    
    
    
      /* add setup code here */
    
    pinMode(pin, OUTPUT);
    pinMode(pin2, OUTPUT);
    
    start = micros();
    
    startDebug = micros();
    
    periodMicros = 1000000L / cps;
    
    Serial.begin(115200);
    
    Serial.println("Done setup");
    
    }
    
    
    
    long countedCPS = 0;
    
    void loop()
    
    {
    
    if (micros() - start > periodMicros) {
    
    start = micros();
    
    digitalWrite(pin, LOW);
    digitalWrite(pin2, LOW);
    
    countedCPS++;
    
    digitalWrite(pin, HIGH);
    digitalWrite(pin2, LOW);
    
    }
    
    if (micros() - startDebug > 1000000L) {
    
    Serial.print("CountedCPS: ");
    
    Serial.println(countedCPS);
    
    startDebug = micros();
    
    countedCPS = 0;
    
    }
    
    //Serial.println("loop");
    
      /* add main program code here */
    
    
    
    }
