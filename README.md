# Cooling-Fan
A cooling fan project using ATMEGA32 micro controller, LM35 temperature sensor , LM016L LCD display to view the current temperature from ADC, 4 LEDS (Green, Blue, Yellow, Red)to indicate the current temperatur level, a Buzzer to allert when temperature is high, 2 DC motors as an actuators tha acts according to the value of temperature.
the temperaure sensor is connected to the microcontroler via ADC channel 0.
Motor #1 is connected to the OC0 pin for PWM output.
* When the temperature is from (0C to 25C) the green LED is acctivated and no motors is switched on.
* When the temperature is from (25C to 50C) the Blue LED is acctivated and Motor #1 is running with 1/4 of its power
* When the temperature is from (50C to 75C) the Yellow LED is acctivated and Motor #1 is running with 1/2 of its power
* When the temperature is from (75C to 100C) the Red LED is acctivated and Motor #1 is running with all of its power
* When the temperature is greater than 100C the Blue LED & the Buzzer are acctivated, the LCD displays a warning message, and Motor #1  and motor #2 are running with all of its power 
