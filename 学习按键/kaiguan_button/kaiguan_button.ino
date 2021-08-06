int buttonPin=12;
int buttonState;
int stat =0;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
int reading = digitalRead(buttonPin);
if(reading != lastButtonState)
{
  lastDebounceTime=millis();
  }
if((millis()-lastDebounceTime)>debounceDelay)
{
  if(reading != buttonState)
  {
    buttonState = reading;

    if(buttonState==HIGH){
    Serial.println("led HIGH");
      stat = stat + 1;
      if(stat >= 4)
      {
        stat=0;
        }
      }
      else{
        Serial.println("led LOW");}
    }
  
  }
switch(stat)
{
  case 1:
      Serial.println("1");
      break;
  case 2:
      Serial.println("2");
      break;
  case 3:
      Serial.println("3");
      break;
  default:
      Serial.println("0");
  }

  lastButtonState = reading;
}
