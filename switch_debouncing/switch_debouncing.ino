/*
 * Andre Augusto Giannotti Scota
 * https://sites.google.com/view/a2gs/
 *
 * A simple schema for GPIO switch debouncing
 *
 * MIT License
 */
#define GPIO_LED 10
#define GPIO_SWITCH 2
#define DEBOUNCE_DELAY 200

int switch_pin = 0;
int sts = 0;

long deltaDebounce = 0;

void setup()
{
	pinMode(GPIO_LED, OUTPUT);
	pinMode(GPIO_SWITCH, INPUT);
	digitalWrite(GPIO_LED, LOW);
}

void loop()
{
	switch_pin = digitalRead(GPIO_SWITCH);

	if((millis() - deltaDebounce) > DEBOUNCE_DELAY){
		if(switch_pin == HIGH){
			if(sts == 0){
				digitalWrite(GPIO_LED, HIGH);
				sts = 1;
				deltaDebounce = millis();
			}else if(sts == 1){
				digitalWrite(GPIO_LED, LOW);
				sts = 0;
				deltaDebounce = millis();
			}
		}
	}
}
