# Echtzeituhr I C 32-Bit Binary Counter RTC
ATTiny 84 TinyWireM in Arduino

[DS1672-33+](https://www.mouser.de/ProductDetail/Maxim-Integrated/DS1672-33+?qs=0Y9aZN%252BMVCX3bsc%252BYvzwKA==)


To set correct timestamp during compilation

```c
static const char PROGMEM compileDate[] = __DATE__;
static const char PROGMEM compileTime[] = __TIME__;


void setup()
{
  Serial.begin(9600);
  
  Serial.print(F("Date of Compilation:"));
  for (int i=0;i<sizeof(compileDate);i++) Serial.write(pgm_read_byte(&compileDate[i]));
  
  Serial.println();
  
  Serial.print(F("Time of Compilation:"));
  for (int i=0;i<sizeof(compileTime);i++) Serial.write(pgm_read_byte(&compileTime[i]));
  Serial.println(); 
}

void loop(){}
```
[mikrocontroller.net](https://www.mikrocontroller.net/topic/426551)
