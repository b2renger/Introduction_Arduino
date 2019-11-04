# Introduction Arduino

Code for a creative coding class with arduino for designers.

[Arduino](https://www.arduino.cc/) is a brand of open hardware electronic cards: ie cards whose diagrams are freely available and free of charge.

Arduino is a project that began in 2003 at the Ivrea Interaction Design Institute (now integrated with the Domus Academy - a private design school based in Milan, Italy) as a pedagogical project for students, seeking to enable them at reduced cost and as simply as possible to create objects interacting with their environment through sensors and actuators.

An arduino card consists of a platform of inputs / outputs directed by a microcontroller that can be programmed via the eponymous software. The arduino project has been used extensively in the areas of rapid prototyping, related to interactive multimedia programming related to the creation of shows or digital art installations.

Projects made with this type of card can then be autonomous, connected to the Internet (IOT), or can communicate directly with one or more computers.

These cards have a multitude of input and output components, expansion cards and a very active community. Arduino is a brand that means there are arduino card clones that have very similar characteristics. We will use by abuse the term arduino to define all the activity of creating circuits and programming cards.

There are different models of cards with more or fewer inputs / outputs, which require more or less energy to operate and whose processors (or micro-controllers) are more or less fast and or efficient. (Mega, Leonardo, Uno etc.)

Here we will focus on how to recover values ​​from different sensors, how to activate actuators and how to make  an arduino card and a  [processing](https://processing.org/) program to communicate with each other.

Each example will include a circuit diagram to make and code to write and upload to a board. The first part consists of a small inventory of sensors, the second will present some actuators (motors, leds and digits display), the third part will recover information from a sensor to transmit it to an actuator, and finally the fourth part will bring us to bridge the gap between a computer and our arduino board.

## CONTENTS
* [Introduction](https://github.com/b2renger/Introduction_arduino#introduction) <br>

* [Connect sensors and retrieve values](https://github.com/b2renger/Introduction_arduino#connecting-captors-and-receiving-values) <br>

  * [digital inputs and logic sensors]() <br>
    * [PIR](https://github.com/b2renger/Introduction_arduino#pir) <br>
    * [Tilt](https://github.com/b2renger/Introduction_arduino#tilt) <br>
    * [Microswitch](https://github.com/b2renger/Introduction_arduino#microswitch) <br>
    * [Button](https://github.com/b2renger/Introduction_arduino#button) <br>
  
  * [analog inputs]() <br>
    * [Potentiometer](https://github.com/b2renger/Introduction_arduino#potentiom%C3%A8tre) <br>
    * [Micro](https://github.com/b2renger/Introduction_arduino#micro) <br>
    * [Photo-resistance](https://github.com/b2renger/Introduction_arduino#photo-resistance) <br>
    * [Piezo Sensor](https://github.com/b2renger/Introduction_arduino#capteur-piezo) <br>
    * [Flex](https://github.com/b2renger/Introduction_arduino#flex) <br>
    * [FSR](https://github.com/b2renger/Introduction_arduino#fsr) <br>

  * [Distance Sensors](https://github.com/b2renger/Introduction_arduino#distance-sensor) <br>
    * [Infra-red](https://github.com/b2renger/Introduction_arduino#infra-red) <br>
    * [Ultra-sound](https://github.com/b2renger/Introduction_arduino#ultra-son) <br>
      * [Ultra-sound grove](https://github.com/b2renger/Introduction_arduino#ultra-son-grove) <br>
      * [Ultra-sound hc sr04](https://github.com/b2renger/Introduction_arduino#hc-sr04) <br>

  * [Digital sensors - SDA and SCL input]() <br>
    * [Accelerometer](https://github.com/b2renger/Introduction_arduino#acc%C3%A9l%C3%A9romecromancer) <br>
    * [Gyroscope](https://github.com/b2renger/Introduction_arduino#gyroscope) <br>
    * [Gesture](https://github.com/b2renger/Introduction_arduino#gesture) <br>
    
* [Connect actuators and enable devices](https://github.com/b2renger/Introduction_arduino#connecting-actuators-and-activating-permanent-prizes) <br>

  * [Turn on leds](https://github.com/b2renger/Introduction_arduino#leds-simples) <br>
    * [Turn on leds: blink](https://github.com/b2renger/Introduction_arduino#make-clink-one-led) <br>
    * [Turn on leds: pulse](https://github.com/b2renger/Introduction_arduino#make-pulsed-one-led) <br>

  * [Activate a vibrator](https://github.com/b2renger/Introduction_arduino#grader-motor) <br>
    * [Activate a vibrator: blink](https://github.com/b2renger/Introduction_arduino#vibreur-on-off) <br>
    * [Activate a vibrator: pulse](https://github.com/b2renger/Introduction_arduino#vibreur-pulse) <br>

  * [run a servomotor](https://github.com/b2renger/Introduction_arduino#servomotors) <br>
    * [classic sevomotor](https://github.com/b2renger/Introduction_arduino#servomoteur-classique) <br>
    * [servomotor with continuous rotation](https://github.com/b2renger/Introduction_arduino#servomotor-%C3%A0-rotatoin-continue) <br>
    * [Linear Servomotor](https://github.com/b2renger/Introduction_arduino#linear-servomotor) <br>

  * [light leds (neopixels)](https://github.com/b2renger/Introduction_arduino#alumer-des-leds-neopixels) <br>
    * [RGB](https://github.com/b2renger/Introduction_arduino#specify-color-rgb) <br>
    * [HSB](https://github.com/b2renger/Introduction_arduino#specify-color-in-hsv) <br>
  
  * [use a digits viewer](https://github.com/b2renger/Introduction_arduino#using-a-poster-using-a-4-digits) <br>

* [Control an actuator with a sensor](https://github.com/b2renger/Introduction_arduino#controler-a-actuateur-with-a-sensor) <br>
  * [Use the map function ()](https://github.com/b2renger/Introduction_arduino#use-map-function) <br>
  * [Potentiometer to conventional servo](https://github.com/b2renger/Introduction_arduino#potentiom%C3%A8tre-vers-servo-classique) <br>
  * [Flex to Continuous Servo](https://github.com/b2renger/Introduction_arduino#flex-vers-servo-continu) <br>
  * [FSR to neopixels HSB](https://github.com/b2renger/Introduction_arduino#fsr-vers-neopixels-hsb) <br>

* [Use sensors to control processing code](https://github.com/b2renger/Introduction_arduino#use-captors-to-control-contr%C3%B4ler-code-processing) <br>
  * [Control the playback of a video with a distance sensor](https://github.com/b2renger/Introduction_arduino#control-the-playback-of-video-with-a-distance-sensor) <br>
  * [Control an animation with photoresistance](https://github.com/b2renger/Introduction_arduino#controler-a-animation-with-photoresistance) <br>
  * [Control neopixels leds with the mouse](https://github.com/b2renger/Introduction_arduino#controler-ed-neopixels-with-mouse) <br>
  * [Save data to a file on your computer](https://github.com/b2renger/Introduction_arduino#register-designs-in-a-file) <br>

## Introduction

When we say that an arduino card is an input / output board it means that this board can measure electrical currents (input) or generate electrical currents (output).

Measuring currents makes it possible to connect sensors and check their status: for example, measuring the output current of a brightness sensor enables us to estimate the ambient luminosity.

Generating currents makes it possible to connect actuators and thus to run an engine more or less quickly or to light LEDs more or less. Code will drive the interaction and the link between our different elements.

An arduino card looks like this:

<img src="assets/carte_arduino_uno.png" width="360" height="480" /><br>

On the left hand side, try to find the **analog inputs** numbered from **A0** to **A5**, on the right you can find the **digital pins** numbered from 0 to 13.

Note that we are talking about *analog* inputs and digital *pins*. To sum up A0 up to A5 are inputs and only inputs; moreover they are *analog* which means that you will be able to measure values ​​between 0 and 1023.

The digital *pins* can be used either as inputs or as outputs (this is specified in the code we write) and handle only 0 and 1 (a digital or digital signal) - even if this is not quite true because some we have a small tilde **~** represented before their number, it means that these *pins* can generate a pulse width modulation (PWM) signal but that's another story and we will talk about it later.

It is important to also note the pins **5V** and **GND** these correspond to the power pins. Each component must be powered by electricity and we will use them systematically.

To simplify things avoid connecting sensors on the digital pins D0 and D1 at the beginning.

When we have been able to connect components to our board, we will use code to measure currents: **read** on a **digital** input or **analog** input, or **write** on a **digital** output.

The code is written in the Arduino Integrated Development Environment (IDE), which you can find and download at this address: https://www.arduino.cc/en/Main/Software

Take the * Desktop * version:

<img src="assets/download_arduino.png" width="480" height="240" /><br>

Once downloaded, installed and opened you should find yourself in front of a window looking like this:

<img src="assets/arduino_ide.png" width="600" height="740" /><br>

So we will type text in this page to program our electronic card.

The first two buttons at the top left allow you to **check** and **upload** your code to the card, the following buttons are used to create a new program, open a program or save a program, and the button all on the right is used to open the **serial monitor** (this is where our program can write information to inform us about the smooth running of the task or to observe raw sensor values).

The black area corresponds to the **error console**: the software will indicate here (and often in red) when there are errors in the program we have written, or communication problems with the card.

Finally the white area is the code area. You can see two functions already named **setup()** and **loop()**. This is the basic structure of any arduino program. 

In the braces that enclose the **setup()** function you will write code that will only be executed once at the beginning of your program. For example open a serial communication with our computer:

```c
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
```

And between the braces that delimit the **loop()** function you will write code that will be executed in a loop once the program has started. For instance : print in the serial monitor the value read on the analog input 0:

```c
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(0));
}
```
Remember that you must type the instructions exactly as the arduino card is waiting for them, the slightest typo (capital, semicolon or missing parenthesis) will cause your program to not work because the card will not be able to understand the instructions it must perform.

Note that it is possible to write comments in language for a human: by placing **//** in front of a line it will not be read / executed.

Once the program written it must be **uploaded** to the board. Beforehand you must specify on what **board type** you want to upload the program and say precisely the board or **port** on which to upload - because we could very well have several cards connected to one computer.

To do this you have to go to the *Tools* menu and then select *Arduino / Genuino Uno* as the **board type** and choose the right board from the **Port** menu (of course at this stage you need your card to be connected to a USB port of your computer):

<img src="assets/arduino_ide_selection_carte.png" width="900" height="640" /><br>

Once done, you can **check** your program and **upload** it.

When we make a circuit our card must be disconnected from our computer, when we code it is better to keep it connected.

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


## Connect sensors and recover values

This first part consists of a small inventory of sensors. Each time you will have an assembly schematics and code to read the value of the sensors and print it in the serial monitor.

In terms of code we will mainly use two functions: 
- [**digitalRead()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) to **read** a value from a **digital** pin.
- [**analogRead()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) to **read** a value of an **analog input**.

And more controls related to the serial monitor:   
- [**Serial.begin()**](https://www.arduino.cc/en/Serial/Begin) which allows to open a serial connection via the USB cable (to recall the acronym usb means Universal Serial Bus) to retrieve values with our computer.
- [**Serial.println()**](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/) which allows you to enter values ​​in the serial port.

In a general way the code will always be the same and it will consist of:

- open a serial connection to write the values ​​of the sensors on our computer.
- read the value received from a specific pin.
- write it in the serial monitor.

From an electronic point of view, sometimes we will use resistors and sometimes not. The principle of a resistance is to allow a little dissipation of the current that runs through our assembly. There are several values ​​from a few ohms to several million ohms, the higher the value, the more they will dissipate the current because at constant voltage: **U = R * I**, this is the **ohms law**; the voltage is equal to the resistance times the intensity - therefore the intensity is equal to the voltage divided by the resistance.

Depending on the current required for optimal operation of our sensors, we will have to choose a suitable resistor.


### Digital Inputs and Logic Sensors

We have 14 digital inputs. Typically a digital pin will only measure two types of current: either there is current, or there is none / *HIGH* or *LOW* / 1 or 0 / *True* or *False*.

#### Tilt

The * tilt * sensor can detect sudden changes in motion or orientation changes. A small metallic ball will come into contact with the wall and thus close a circuit to let the current flow.

Here is what it looks like:

<img src="assets/capteurs/tilt.jpg" width="270" height="270" /><br>

One leg connected to ground the other will be connected to current, if the ball and the body of the sensor come into contact : the current passes and can therefore be measured; we thus obtain either a 1 or a 0 depending on the state of the sensor.

Example of use :

<img src="assets/read_from_tilt.gif" width="480" height="270" /><br>


The circuit to realize:

<img src="read_from_tilt/read_from_tilt.png" width="480" height="360" /><br>

Here we use a resistor of 10 kilo ohms, to protect our sensor and our card: this allows us to lower the current flowing before measuring it.

The code is very simple, we must:

- open a serial connection to write the sensor values.
- specify in our program that we use pin 7 as an input.
- read the value received on pin 7.
- write it in the serial monitor.

The first two steps can only be performed once when the card is turned on: they will go into the **setup()**; the next two steps must be done in a loop to always update the value read on the sensor so they will go into the **loop()**.


```c
void setup() {
  Serial.begin(9600); // open the serial connection
  pinMode(7, INPUT); // specify that pin 7 will be used as an entry
}

void loop() {
  int value = digitalRead(7); // read the value on pin 7 and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### PIR

The [*PIR*](https://en.wikipedia.org/wiki/Passive_infrared_sensor) sensor is a Presence sensor with Infra Red, it can detect the presence of someone in a specific field of view. These are typically sensors in all public places whose lights turn on automatically.

These sensors return a 1 for a certain time (here 3 seconds) when they detect a presence and 0 otherwise.

<img src="assets/read_from_pir.gif" width="480" height="270" /><br>

Here instead of opening the **serial monitor**, the result is displayed in the **serial plotter** available via the *Tools* -> *Serial Tracer* menu.

The *PIR* is often accompanied by a small printed circuit and it is therefore not necessary to add resistance because it has already been done on the board accompanying the sensor.

<img src="read_from_PIR/read_from_pir.png" width="480" height="360" /><br>

The code is identical to the previous code if we have also connected the * PIR * sensor to input 7:

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  pinMode(7, INPUT); // specify that pin 7 will be used as an entry
}

void loop() {
  int value = digitalRead(7); // read the value on pin 7 and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```
[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Microswitch

The microswitch is in the same family as the switches or buttons. When we press the circuit is closed, we can then measure a 1 - otherwise the circuit is open and there is no current that passes so we measure a 0.

<img src="assets/read_from_microswitch.gif" width="480" height="270" /><br>

<img src="read_from_microswitch/read_from_microswitch.png" width="480" height="360" /><br>

Again the code is identical except that our component is connected to the digital input 2
```c
void setup() {
  Serial.begin(9600); // open the serial connection
  pinMode(2, INPUT); // specify that pin 7 will be used as an entry
}

void loop() {
  int value = digitalRead(2); // read the value on pin 7 and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Bouton

The buttons may appear at first glance as the simplest component to use, but this is not really the case - it is advisable to first use the microswitch before switching to the button. Circuits can be complicated (especially when you want to have many) and the code is not necessarily the simplest - we are used to having different types of button interactions that sometimes require a little bit of expertise.

Buttons are of different sizes and shapes, they can have 2, 3 or 4 legs but the principle is always the same: when you press the button, the circuit closes and thus the current can pass. By measuring this current on a digital pin one obtains either a 0 (open circuit = no current) or a 1 (closed circuit = the current passes). It is possible to obtain more complex behavior than this simple reading and to "recognize" double clicks, long presses, etc. by using a library.

<img src="assets/differents_boutons.jpg" width="480" height="360" /><br>

The arcade button has 3 pins, the small button at the bottom right has 4 and the button at the bottom left has 3 pins too (it is a capacitive button).

The electronic circuit is essentially the same for all the buttons: it is better to plug the button with 3 wires: 2 for the power supply (black and red) with a resistance of 10kohms on the ground, and a wire (yellow) for reading the value. The capacitive button grove is already mounted on a small card with a built-in resistor.

#### Circuits

##### Le bouton capacitif

<img src="read_from_button/read_from_button_grove.png" width="480" height="360" /><br>

##### Le bouton "classique"

<img src="read_from_button/read_from_button_classic.png" width="480" height="360" /><br>

##### Le bouton d'arcade

<img src="read_from_button/read_from_button_arcade.png" width="480" height="360" /><br>


#### Code
Unlike the previous examples there will be two code examples for two different behaviors.
- The first will just read the data on pin 2. The value read will therefore be 0 if the button is not pressed and 1 if it is.
- The second one will manipulate a variable to make it change its state. So every time we click the button (this means press and release), a variable will change its state to be either a 0 or 1.

<img src="assets/read_from_buttons.gif" width="480" height="360" /><br>

#### Read the value of a button

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  pinMode(2, INPUT); // specify that pin 2 will be used as an entry
}

void loop() {
  int value = digitalRead(2); // read the value on pin 2 and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```


#### Use a click to change a state
The code here is a bit more complex: it uses a custom written function that allows you to change the state of a variable according to the click and the previous value of the variable: it is the defined function at the bottom called **button_change()**. This function expects 3 parameters:
- the pin on which the button is connected.
- a boolean variable (true or false) for storing the current state of the button.
- a boolean variable for storing the previous state of the button.


```c
bool b1pval = false; // previous value of the button
bool b1val = false; // current value of the button

void setup() {
  Serial.begin(9600); // open the serial connection
  pinMode(2, INPUT); // specify that pin 2 will be used as an entry
}

void loop() {
  // call the function on pin 2
  // with as previous value of the button the variable b1pval
  // and as the current value of the button the variable b1val
  button_change(2, &b1pval, &b1val); 
  Serial.println(b1val);
}

void button_change(int pin, bool *pval, bool *val) {
  if (digitalRead(pin) == 1) {
    if (*val == *pval) {
      *val = !*val;
    }
  }
  else {
    *pval = *val;
  }
}
```
In this code you can notice the appearance of the characters * and & that are specific to the languages ​​of the family C and which are used in the manipulation of the pointers.

This is a concept that can be complex to understand, but for simplicity it means that we can directly manipulate the memory space of a computer or an electronic board. Here it is useful to be able to handle dynamic variables within a function by passing as parameter the memory space to handle.

To know more :
- https://www.arduino.cc/reference/en/language/structure/pointer-access-operators/reference/

- https://www.arduino.cc/reference/en/language/structure/pointer-access-operators/dereference/

- https://en.wikipedia.org/wiki/Pointer_%28computer_programming%29

There are also libraries for using the buttons. You can access the arduino library manager by clicking on the menu: *Sketch* -> *Include Library* -> *Manage Libraries*.
You can search for two libraries:
- EasyButton
- OneButton
Once installed, examples of use will be available in the menu: *File* -> *Examples*

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Analog Inputs

Analog inputs and analog sensors unlike digital inputs and logic sensors will provide us with a range of values, these values ​​will be between **0** and **1024** when using a 10 bit DAC (usually the case on most arduino boards).

#### Potentiometer 

The [*potentiometer*](https://en.wikipedia.org/wiki/Potentiometer) is a classic of electronics: depending on its position, its internal resistance vary which will measure a current more or less strong and encoded between 0 and 1024.

<img src="assets/read_from_pot.gif" width="480" height="270" /><br>

The potentiometer has 3 legs: both ends are dedicated to its power supply (one connected to **GND** the other to **5V**, the central leg carries the signal that we want to read and will be connected to an **analog input**.

<img src="read_from_potentiometer/read_from_pot.png" width="480" height="360" /><br>

The code is very similar to the code of logic sensors except : that the analog pins are necessarily inputs and it is therefore not necessary to specify the use with **pinMode()**, and that we read on an analog input using **analogRead()** instead **digitaleRead()**:

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the pin A0 and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### Microphone

The mics most often used in electronics are [electret microphones](https://en.wikipedia.org/wiki/Electret_microphone) in our case the microphone is already mounted on a printed circuit, so we have not much to add and we will be able to recover a value between 0 and 1023 representing the sound level. In this case we will not be able to record a sound to replay it afterwards, the goal is only to measure the sound level.

There are a multitude of mics some have adjustment wheels to calibrate their sensitivity.

<img src="assets/read_from_grove_mic.gif" width="480" height="270" /><br>

We will use only 3 of the 4 pins of the connector: two for the power supply and the third for reading the analog data. The manufacturer's wiki tells us which connections are available on the spindle: http://wiki.seeedstudio.com/Grove-Sound_Sensor/

<img src="read_from_grove_mic/read_from_grove_mic.png" width="480" height="360" /><br>

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the A0 pin and store it in an integer variable
  Serial.println(value); // to print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### Photoresistor

The [*photoresistor*](https://en.wikipedia.org/wiki/Photoresistor) varies its resistance according to the brightness it receives. There are all sizes and sensitivities.

<img src="assets/read_from_photores.gif" width="480" height="270" /><br>

To protect the current reading on our analog input we are going to a resistance of 10 kilo ohms. We find a circuit quite similar to that of a logical tilt sensor.

<img src="read_from_photores/read_from_photores.png" width="480" height="360" /><br>

We read the signal on the analog input A0: 

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the pin A0 and store it in an integer variable
  Serial.println(value); //  print the contents of the variable in the serial monitor
}
```


[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### Piezo sensor

The piezoelectric sensor uses the principle of [*piezoelectricity*](https://en.wikipedia.org/wiki/Piezoelectricity) which causes certain materials to become deformed when they are subjected to an electric current or on the contrary they can also generate electricity when they are deformed.

It can be used as a vibration sensor either as a contact mic, or as a small speaker to vibrate at given frequencies (and therefore also acts as an actuator!)

Here we will detect vibrations and measure their level.

<img src="assets/read_from_piezo.gif" width="480" height="270" /><br>

To protect our input, but also because compared to a resistance of 10kOhms it will give better readings, we will use a resistance of 100kOhms.

<img src="read_from_piezo/read_from_piezo.png" width="480" height="360" /><br>

The code remains the same as long as our sensor is on the same input.
```c
void setup() {
  Serial.begin(9600); //open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the A0 pin and store it in an integer variable
  Serial.println(value); // to print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### FSR 

*FSR* sensor is a force sensor: it will convert the weight applied on its surface into a measurable electric current.

<img src="assets/read_from_fsr.gif" width="480" height="270" /><br>

We find the same type of diagram as for the sensor *tilt* or that for the *piezo* or the *photoresistance*. Here it is mounted with a resistance of 47 kOhms, but you can try to adjust this value to refine the precision.

<img src="read_from_FSR/read_from_FSR.png" width="480" height="360" /><br>

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the A0 pin and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### Flex

The *flex sensor* will convert the curvature that it takes to a value between 0 and 1023. It should be noted that subjected to no constraints the value read must be around 511, it means that our sensor can detect a flexion in both ways.

<img src="assets/read_from_flex.gif" width="480" height="270" /><br>

Here it is mounted with a resistance of 47 kOhms, but you can try to adjust this value to refine the precision.

<img src="read_from_flex/read_from_Flex.png" width="480" height="480" /><br>

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the A0 pin and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


### Distance sensors

There are several methods to calculate distances: infra-red, ultra-sound, laser. Here we will focus on the first two technologies.

#### Infrared

The infrared sensor will allow a system of lenses and trigonometric equations to estimate a distance. The [model we use](https://www.gotronic.fr/art-capteur-de-mesure-sharp-gp2y0a21yk0f-11539.htm) allows to obtain an estimation of the distance for distances between 10 and 80 cm and to read the result on an analog input.

<img src="assets/read_from_irdistance.gif" width="480" height="270" /><br>

<img src="read_from_IRDistance/read_from_irdistance.png" width="480" height="360" /><br>

```c
void setup() {
  Serial.begin(9600); // open the serial connection
  
}

void loop() {
  int value = analogRead(0); // read the value on the A0 pin and store it in an integer variable
  Serial.println(value); // print the contents of the variable in the serial monitor
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


#### Ultrasound

There are different types of ultrasonic sensors to measure distances which is a little more precise and allows to have a greater range (up to a few meters) than the infrared method
- The classic [HC-SR04](https://www.gotronic.fr/art-module-de-detection-us-hc-sr04-20912.htm) which requires a 4-wire connection.
- The [grove module](https://www.gotronic.fr/art-telemetre-a-ultrasons-grove-101020010-18976.htm) which has the grove connectivity and an associated library. It is therefore relatively easier to use.

The measuring principle of these two sensors is the same and the results obtained are therefore very similar:
<img src="assets/read_from_ultrasonic_distance.gif" width="480" height="270" /><br>


#### Grove ultrasound

[*grove module*](https://www.gotronic.fr/art-telemetre-a-ultrasons-grove-101020010-18976.htm)

The circuit looks like a classic circuit with grove components:

<img src="read_from_UltraSonic-Distance-grove/read_from_UltraSonic-Distance-grove.png" width="480" height="480" /><br>

The code requires to install a library. You can access the arduino library manager by clicking on the menu: *Sketch* -> *Include Library* -> *Manage Libraries*. You must then look for and install the **Grove Ultrasonic ranger** library.

This library will ignore all the procedure described below for the Hc-sr04 and allow us to manipulate a minimalist code much like what we have seen before.

```c
#include "Ultrasonic.h" // import the library
Ultrasonic ultrasonic(2); // the "sig" pin of the sensor is connected to "D2" of the arduino

void setup() {
  Serial.begin(9600);
}

void loop() {
  long RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // measure the distance in cm
  Serial.println(RangeInCentimeters);//0~400cm
  delay(100); //wait a little between two measurements.
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


#### Hc-sr04

[*HC-SR04*](https://www.gotronic.fr/art-module-de-detection-us-hc-sr04-20912.htm) 

The hookup is a little different from what we have seen so far. Two legs will be used for **GND** and **5V** or **VDC** power supplies.

The next two **trig** and **echo** at digital inputs 11 and 10 respectively.

<img src="read_from_UltraSonic_Distance/read_from_ultrasonic_distance.png" width="480" height="360" /><br>

This is due to the way the sensor work. We will actually generate a current on the leg **trig** and measure a current on the leg **echo**: we will emit ultrasounds, listen to their echo and according to the time elapsed between the emission and the reception of the echo we can determine a distance (because we know the speed of the sound !).

The code will be significantly more complex. Indeed we need:
- initialize our pin 11 and 10 respectively as an input and an output. [**pinMode()**](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/)
- emit a current / signal on the pin 11. [**digitalWrite()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)
- measure an echo on the pin 10. [**pulseIn()**](https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/)
- transform a value from duration to distance.
- print this value in the console.

By reading the documentation of **pulseIn()**, we will realize that our signal emitted on the trigger pin must also follow a particular form.

We will also have to use the functions:

- [**delay()**](https://www.arduino.cc/reference/en/language/functions/time/delay/)
- and [**delayMicroseconds()**](https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/)

which allow to stop the thread of execution of our program for a given time and thus to create delays.

```c

// for us to remember we will use variables to store the numbers of pins used
int trigPin = 11;    // Trigger
int echoPin = 10;    // Echo

void setup() {
  Serial.begin (9600);
  // we specify that pin 11 is an output (ultrasound emission)
  pinMode(trigPin, OUTPUT); // trigPin est remplacé par sa valeur
  // we specify that the pin 10 is an entry (reception of the echo)
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a signal on the trigger pin (11)
  // alternating LOW and HIGH current values ​​and delay rates
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10); // force the program to stay in its previous state (LOW) for 10 seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // force the program to stay in its previous state (HIGH) for 10 micro seconds
  digitalWrite(trigPin, LOW);
    
 // get the distance by measuring peaks HIGH current on the echo pin
  long duration = pulseIn(echoPin, HIGH);
 // Convert the duration in cm
  long cm = (duration/2) / 29.1;     
    
 // print the result
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
    
 // wait a little before starting the operation again
  delay(250);
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Capteurs numériques - SDA et SCL

Les capteurs que nous allons utiliser maintenant vont pouvoir nous fournir une information plus complexe et moins brute, ils vont nottament nous permettre de récupérer plusieurs valeurs en même temps. 

On parle de capteur [**I2C**](https://fr.wikipedia.org/wiki/I2C), il se branchent habituellement sur les entrée analogiques 4 et 5 d'une carte arduino uno.

Le protocole **I2C** permet de communiquer avec deux fils, l'un portera la **donnée** (**SDA**) et l'autre la **clock** (**SCL**). Le signal porté par la clock permettra de recomposer la donnée faite de bits (suite de 0 et de 1).

Génralement ces capteurs sont déjà montés sur des circuits integrés et ne nécessite le cablage que de 4 cables : GND, VCC pour l'alimentation et SDA et SCL pour les données.

Le code peut s'avérer complexe et fait souvent appel à l'usage de bibliothèques fournies par la communauté ou par le fabricant. Il faut donc souvent se référer à la page du fabricant pour trouver les moyen d'exploiter des capteurs, il faut donc faire attention à choisir des capteurs bien documentés.

Installer une bibliothèque se fait via une interface graphique dans l'IDE arduino. Il faut ouvrir le menu *Croquis* -> *Inclure une bibliothèque* -> *Gérer les bibliothèques*

<img src="assets/arduino_bibliotheques.png" width="680" height="470" /><br>

Qui vous permettra d'ouvrir cette fenêtre : 

<img src="assets/arduino-gestionnaire-bibliotheque.png" width="680" height="370" /><br>

Vous avez alors un champ de recherche vous permettant de chercher et d'installer les bibliothèques dont vous avez besoin.

Généralement chaque bibliothèque vient avec sont lot d'exemples plus ou mois utiles, plus ou moins nombreux et plus ou moins clairs. Vous pouvez y accéder via le menu *Fichier* -> *Exemples* et tout en bas du menu déroulant vous trouverez les exemples relatifs aux bibliothèques.


#### Accéléromètre

L'[*accéléromètre*](https://fr.wikipedia.org/wiki/Acc%C3%A9l%C3%A9rom%C3%A8tre) permet de mesure l'accélération linéaire, soit la projection de la gravité sur chacun de ses trois axes.

<img src="assets/read_fom_accelerometer.gif" width="480" height="270" /><br>

Le montage est tout ce qu'il y a de plus simple :

<img src="read_from_accelerometer/read_from_3axisAccelerometer.png" width="480" height="360" /><br>

Le code est lui assez complexe, il utilise la bibliothèque *ADXL345* spécialement dédiée à ce composant, elle ne sera donc pas utilisable avec tous les accéléromètres.

On en apprend plus sur son utilisation sur la page de référence du fabricant : http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/

Ce qu'il est important de comprendre c'est que l'on stocke les valeurs issues de l'accéléromètre à chaque fois que la boucle s'éxecute. Pour récupérer ces valeurs on est obligé de faire appel aux méthodes écrites et décrites dans la bibliothèque - il n'est pas possible de recomposer simplement la donnée vit les informations mesurées sur les pins.

```c
// prévenir que nous allons avoir besoin de ces bibliothèques
#include <Wire.h>
#include <ADXL345.h>

ADXL345 accel; // on crée un objet qui nous permet de manipuler les données provenant de notre acceleromètre

void setup() {
  Serial.begin(9600);
  accel.powerOn(); // on active notre capteur
}

void loop() {

  // on crée trois variables pour stocker les valeurs brutes de notre acceleromètre.
  int x, y, z;
  accel.readXYZ(&x, &y, &z); //on lit données de l'accéleromètre et on les stockent dans nos variables.
  // on imprimme le résultat dans le moniteur série
  Serial.print("values of X , Y , Z: ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.print(" , ");
  Serial.println(z);

  // on crée un tableau pour stocker les valeurs provenant du calcul effectué par notre bibliothèques quand on appel getAcceleration()
  double xyz[3]; 
  accel.getAcceleration(xyz); //on lit données de l'accéleromètre et on les stockent dans notre tableau
  // on imprimme le résultat
  Serial.print("X=");
  Serial.print(xyz[0]);
  Serial.print(" g , ");
  Serial.print("Y=");
  Serial.print(xyz[1]);
  Serial.print(" g , ");
  Serial.print("Z=");
  Serial.print(xyz[2]);
  Serial.println(" g");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  //delay(500); // if you want to look in the monitor
  delay(10); // if you want to look in the tracer
}
```


[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

#### Gyroscope

Un [*gyroscope*](https://fr.wikipedia.org/wiki/Gyroscope) permet de mesurer la rotation d'un objet dans l'espace et de connaitre sa position angulaire.

Sa mise en oeuvre est assez similaire à la mise en oeuvre de l'accéleromètre.

<img src="assets/read_from_gyroscope.gif" width="480" height="270" /><br>

<img src="read_from_gyroscope/read_from_3axisGyro.png" width="480" height="360" /><br>

La page de documentation du fabricant nous fournit les informations relative à son utilisation en terme de code : http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Gyro/    

Il faudra installer la bibliothèque *ITG3200* - Grove 3-axis-digital-gyro.

```c
// prévenir que nous allons avoir besoin de ces bibliothèques
#include <Wire.h>
#include "ITG3200.h"

ITG3200 gyro;
void setup(){
    Serial.begin(9600);
    // on active notre capteur
    gyro.init();
    gyro.zeroCalibrate(200,10);//sample 200 times to calibrate and it will take 200*10ms
}

void loop(){
    // on crée trois variables pour stocker les valeurs brutes de notre gyro.
    int16_t x,y,z;
    gyro.getXYZ(&x,&y,&z);//on lit les données de l'gyro et on les stockent dans nos variables.
    // on imprimme le résultat dans le moniteur série
    Serial.print("values of X , Y , Z: ");
    Serial.print(x);
    Serial.print(" , ");
    Serial.print(y);
    Serial.print(" , ");
    Serial.println(z);

    // on crée trois variables pour stocker les valeurs provenant du calcul effectué par notre bibliothèques 
    float ax,ay,az;
    gyro.getAngularVelocity(&ax,&ay,&az);
    // on imprimme
    Serial.print("Angular Velocity of X , Y , Z: ");
    Serial.print(ax);
    Serial.print(" , ");
    Serial.print(ay);
    Serial.print(" , ");
    Serial.print(az);
    Serial.println(" degrees per second");
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    //delay(500); // if you want to monitor in the console
    delay(10); // if you want to trace
}

}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


#### Gesture

Le dernier capteur que nous allons voir est un *capteur de gestes*. Il va nous permettre de pouvoi identifier jusqu'à 9 gestes :

<img src="assets/read_from_gesture.gif" width="480" height="270" /><br>

Ce capteur consiste en une série de photorésistances : lorsque l'on bouge devant, la luminosité reçue par chaque photorésistance change et une bibliothèque logicielle nous permettre de reconnaitre des patterns de mesure de courant relatifs à ces gestes.

<img src="read_from_gesture_sensor/read_from_gesture.png" width="480" height="360" /><br>

Selon la page du fabricant : http://wiki.seeedstudio.com/Grove-Gesture_v1.0/
il faut utiliser la bibliothèque *paj7620* - * Gesture PAJ7620*

Pour différencier les différents cas de gestes nous aurons recours à une structure de contrôle de type [**switch()**](https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/).

Ce type de syntaxe de code nous permet de gérer différents cas en fonction de la valeur d'une variable et donc d'éxecuter un code différent pour chaque valeur. Ici nous imprimerons à chaque fois un message différent dans le moniteur série.


```c


#include <Wire.h>
#include "paj7620.h"

// un variable qui représente notre capteur.
uint8_t gesture = 0;

void setup() {
  Serial.begin(9600);
  // initialiser le capteur
  gesture = paj7620Init();			// initialize Paj7620 registers
  Serial.println("Please input your gestures:\n");
}

void loop() {
  // des varaibles pour stocker les valeurs du capteur
  uint8_t data = 0, data1 = 0;
  gesture = paj7620ReadReg(0x43, 1, &data); // lire les valeur du capteur

  switch (data){ 
    case GES_RIGHT_FLAG: // si data correspond à un gesture vers la droite
      Serial.println("Right");
      break;
    case GES_LEFT_FLAG: // si data correspond à un gesture vers la gauche
      Serial.println("Left");
      break;
    case GES_UP_FLAG: // si data correspond à un gesture vers le haut
      Serial.println("Up");
      break;
    case GES_DOWN_FLAG: // si data correspond à un gesture vers le bas
      Serial.println("Down");
      break;
    case GES_FORWARD_FLAG: // si data correspond à un gesture vers l'avant
      Serial.println("Forward");
      break;
    case GES_BACKWARD_FLAG: // si data correspond à un gesture vers l'arrière
      Serial.println("Backward");
      break;
    case GES_CLOCKWISE_FLAG: // si data correspond à un gesture tourner dans le sens des aiguilles d'une montre
      Serial.println("Clockwise");
      break;
    case GES_COUNT_CLOCKWISE_FLAG: // si data correspond à un gesture tourner dans le sens inverse des aiguilles d'une montre
      Serial.println("anti-clockwise");
      break;
    default:
      paj7620ReadReg(0x44, 1, &data1);
      if (data1 == GES_WAVE_FLAG) {
        Serial.println("wave");
      }
      break;
  }

}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


## Connecter des actuateurs et activer des périphériques
Après avoir utilisé les commandes **digitalRead()** et **analogRead()** pour lire des courants sur les broches d'entrée d'une carte arduino, nous allons maintenant voir comment utiliser les fonction **digitalWrite()** et **analogWrite()** pour générer des courants sur les broches de sortie. A noter que les broches digitales peuvent être configurées en tant que sortie ou en tant qu'entrée à l'aide de la fonction [**pinMode()**](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/).

### Leds simples
Ces leds sont les actuateurs les plus simples que l'on puisse trouver, elles sont très peu chères et existent dans une multitude de couleurs et de tailles. Nous allons nous concentrer tout d'abord sur des leds monochromes avant de parler plus loin des leds RGBW en ruban.

Deux modes d'interactions sont possibles avec ce type d'actuateur, on peut :
- soit envoyer un courant binaire 'HIGH' ou 'LOW' à l'aide de **digitalWrite()** pour faire clignoter une led.
- soit envoyer un courant 'analogique' entre 0 et 255 à l'aide de **analogWrite()** pour réaliser une effet de gradation de la lumière.

Dans les deux cas le circuit sera le même :

<img src="set_led_blink/set_led.png" width="480" height="360" /><br>

Il est important de savoir que la [led](https://fr.wikipedia.org/wiki/Diode_%C3%A9lectroluminescente) simple est un composant polarisé - c'est à dire qu'il a un sens. La petite patte correspond au moins et doit donc être reliée à la masse, la patte la plus longue correspond au plus et doit être reliée à une sortie digitale.
Entre la masse et la patte moins de la led on insère une résistance de 220 ohms afin de protéger la led d'une éventuelle surtension qui risquerait de la griller.

#### Faire clignoter une led

<img src="assets/set_led_blink.gif" width="480" height="360" /><br>

Pour faire clignoter une led il suffit d'utiliser la fonction [**digitalWrite()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/). Cette fonction prend deux arguments :
- le premier est le numéro de la pin sur laquelle on doit envoyer un courant.
- le second est la 'valeur' du courant : soit 'HIGH' soit 'LOW'.

```c
void setup() {
  pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  digitalWrite(3, HIGH); // envoyer un courant 'fort' sur la broche 3
  delay(500); // attendre 500 millisecondes
  digitalWrite(3, LOW); // envoyer un courant 'faible' sur la broche 3
  delay(500); // attendre 500 millisecondes
} 
```

#### Faire "pulser" une led

<img src="assets/set_led_pulse.gif" width="480" height="360" /><br>

Pour faire pulse une led il suffit d'utiliser la fonction [**analogWrite()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/). Cette fonction prend deux arguments :
- le premier est le numéro de la pin sur laquelle on doit envoyer un courant.
- le second est la 'valeur' du courant : comprise entre 0 et 255. 0 correspondra à une led éteinte et 255 à une led allumée au maximum de sa luminosité.

Notez bien qu'en utilisant [**analogWrite()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) notre led n'est pas pour autant branchée sur une broche analogique. Les broches analogiques ne sont que des sorties. Il faut donc brancher notre led sur une pin digitale, mais une pin [PWM](https://fr.wikipedia.org/wiki/Modulation_de_largeur_d%27impulsion), la liste des pins pwm est disponible dans la documentation des différentes cartes.

```c
float t = 0; // une variable pour stocker le temps

void setup() {
   pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  t += 0.025; // on augmente la valeur du temps (on peut changer la valeur pour faire pulse + ou - vite)
  double l = ((sin(t) + 1) /2.0)*255; // on calcule une luminosité l doit être compris entre 0 et 255
  analogWrite(3, l); // on allume la led avec la luminosité calculée.
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Moteur vibreur

Pour le vibreur la logique est exactement que pour la led, le montage est très similaire :

<img src="set_vibrator_onoff/set_vibrator.png" width="480" height="360" /><br>

Et le code sera aussi similaire ...

#### Vibreur on off

<img src="assets/set_vibrator_blink.gif" width="480" height="360" /><br>

```c

void setup() {
  pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  digitalWrite(3, HIGH); // envoyer un courant 'fort' sur la broche 3
  delay(500); // attendre 500 millisecondes
  digitalWrite(3, LOW); // envoyer un courant 'faible' sur la broche 3
  delay(500); // attendre 500 millisecondes
} 

```

#### Vibreur pulse

<img src="assets/set_vibrator_pulse.gif" width="480" height="360" /><br>

```c
float t = 0; // une variable pour stocker le temps

void setup() {
   pinMode(3, OUTPUT); // utiliser la broche 3 en mode sortie
}

void loop() {
  t += 0.025; // on augmente la valeur du temps (on peut changer la valeur pour faire pulse + ou - vite)
  double l = ((sin(t) + 1) /2.0)*255; // on calcule une luminosité l doit être compris entre 0 et 255
  analogWrite(3, l); // on allume la led avec la luminosité calculée.
}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Servomoteurs

Nous avons vu que les entrées digitales permettait de mesurer des courants *HIGH* ou *LOW*, elles permettent aussi deux générer ces deux types de courants comme dans le cas de notre capteur de distance à ultra-son. Une autre possibilité est de générer un signal [PWM](https://fr.wikipedia.org/wiki/Modulation_de_largeur_d%27impulsion): en envoyant des impulsions électriques très rapides et dont la durée varie on peut encoder des valeurs plus complexes et donc contrôler l'intensité et la couleur de leds ou la vitesse / sens de rotation de moteurs.

D'une manière générale tous les servomoteurs se branchent de le même façon :

<img src="set_position_servo_classique/set_servo_position.png" width="480" height="360" /><br>

Le cable foncé est la masse (GND), le cable rouge est l'alimentation (5V), le dernier est généralement jaune ou orange on le relie à une sortie digitale d'une carte arduino, mais attention à une sortie PWM.

On utilise la bibliothèque [**Servo**](https://www.arduino.cc/en/Reference/Servo) qui est inclue par défaut dans l'IDE vous n'avez donc rien de particulier à installer logiciellement pour faire fonctionner des servomoteurs.

Le code est aussi le même on envoit une valeur à l'aide de la fonction [**.write()**](https://www.arduino.cc/en/Reference/ServoWrite) :
- 90 pour la position de repos
- 0 pour un des deux comportements / position extême
- 180 pour l'autre

Les servos moteurs existe en une multitude de taille, de vitesse, et de puissance. En fonction de leur caractéristiques ils peuvent nécessiter plus ou moins d'énergie ou couter plus ou moins cher.

#### Servomoteur classique

Un servo classique va accepter comme paramètre un angle, les valeurs maximales et minimum peuvent varier en fonction des moteurs, de même que la vitesse qui leur permettra d'atteindre cet angle.

<img src="assets/set_position_servo_classique.gif" width="480" height="270" /><br>

Notre code va nous permettre de tester simplement le comportement du servomoteur, en le faisant changer d'état toutes les 1.5 secondes.

```c
// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
}

void loop() {
  myservo.write(90); // mettre le servo en position de repos
  delay(1500); // attendre 1.5 sec
  myservo.write(0); // mettre le servo en buté à gauche
  delay(1500);
  myservo.write(90);// mettre le servo en position de repos
  delay(1500);
  myservo.write(180); // mettre le servo en buté à droite
  delay(1500);
}
```
Vous pouvez essayer de changer les valeurs pour voir ce qu'il se passe.



#### Servomoteur à rotation continue

Un servomoteur à rotation continue va accepter comme paramètre dans sa fonction **.write()** une vitesse de rotation comprise entre 0 et 180.

- 0 le fera tourner à vitesse maximum dans le sens des aiguilles d'une montre.
- 180 le fera tourner à vitesse maximum dans le sens inverse des aiguilles d'une montre.
- 90 le fera s'arreter.

Des valeurs autour de 90 le feront donc tourner plus ou moins vite dans un sens ou dans l'autre.

<img src="assets/set_rotation_servo_continu.gif" width="480" height="270" /><br>

```c
// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
}

void loop() {
  myservo.write(90); // mettre le servo en position de repos
  delay(1500); // attendre 1.5 sec
  myservo.write(0); // faire tourner le servo le plus vite possible dans le sens des aiguilles d'une montre
  delay(1500);
  myservo.write(90);// mettre le servo en position de repos
  delay(1500);
  myservo.write(180); // faire tourner le servo le plus vite possible dans le sens inverse des aiguilles d'une montre
  delay(1500);
}
```
Vous pouvez essayer de changer les valeurs pour voir ce qu'il se passe.


#### Servomoteur linéaire

Le servomoteur linéaire va lui effectuer une translation. On précise entre les parenthèse de **write()** sa position.

<img src="assets/set_position_servo_lineaire.gif" width="480" height="270" /><br>

```c
// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
}

void loop() {
  myservo.write(90); // au milieu
  delay(1500); // attendre 1.5 sec
  myservo.write(0); // à l'opposé
  delay(1500);
  myservo.write(90);//au milieu
  delay(1500);
  myservo.write(180); // à l'autre opposé
  delay(1500);
}
```

Vous pouvez essayer de changer les valeurs pour voir ce qu'il se passe.

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


### Alumer des leds (neopixels)

Nous allons utiliser directement des rubans de leds. Ces rubans présentent des séries de leds RGB dont chacune est contrôllable individuellement en couleur et en intensité.

Ils peuvent être découpés à la longueur souhaités et ne nécessitent que trois cables pour les contrôller : deux pour l'alimentation et un pour la donnée. Le schéma de montage sera toujours le même.

<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

En fonction du nombre de leds que vous voulez allumer mais aussi en fonction de la couleur ou de l'intensité, il vous faudra une puissance différente. Il peut parfois être nécessaire de faire appel à des alimentations externes - en dessous d'une dizaine de led par entrée une carte arduino devrait pouvoir alimenter sans recours à une source d'énergie externe. Une led consomera au maximum 60mA (allumée en blanc à l'intensité maximale). A des courants plus importants, il pourra être intéressant d'ajouter un condensateur en parallèle sur l'alimentation.

Pour la partie logicielle nous allons utiliser la bibliothèque Fast-LED. Il faut donc l'installer via **le gestionnaire de bibliothèques** (Menu *Croquis* -> *Inclure une bibliothèque* -> *Gérer les bibliothèques*).

Nous allons voir comment spécifier la couleur de chaque led soit avec une couleur RGB soit avec une couleur HSV.

La bibliothèque fast-led nous offre une syntaxe permettant de définir le nombre de led dont on dispose, le type de led et la pin de contrôle utilisée.

Ensuite on peut afficher des couleurs sur les leds en parcourant chaque led de notre ruban à l'aide d'une [**boucle for()**](https://www.arduino.cc/reference/en/language/structure/control-structure/for/).


#### Spécifier la couleur en RGB

Ici nous allons créer une petite animation en faisant varier les composantes rouge et verte de chaque led.

<img src="assets/set_neopixels_rgb.gif" width="480" height="270" /><br>

```c 
// inclure la bibliothèque fast-led
#include <FastLED.h>
#define NUM_LEDS 5 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.

void setup() {
  // on initialise notre strip de led sur la pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {

  inc +=  0.05; // on augmente la valeur de inc
  // on calcule en fonction de inc un valeur qui va osciller entre 0 et 244.
  int green = (sin(inc) + 1)*122; // cette valeur est stocké dans une variable nommée "green"
     
  // Pour i allant de 0 à 5, on va éxecuter le code entre accolades, 
  // à chaque fois on augmente la valeur de i de 1
  for (int i = 0; i < NUM_LEDS; i++) {
    // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
    leds[i] = CRGB(255-green, green, 0);
  }
  FastLED.show(); // on actualise le ruban de led
}
```

Si vous souhaitez donner une couleur précise à chaque led, il vous suffit d'utiliser des appels directs à chaque led sans boucle for : 

```c
void loop(){
    leds[0] = CRGB(255, 0, 0); //rouge
    leds[1] = CRGB(0, 255, 0); // vert
    leds[2] = CRGB(0, 0, 255); // bleu
    leds[3] = CRGB(255, 255, 255); // blanc
    leds[0] = CRGB(0, 0, 0); // noir
    FastLED.show(); // on actualise le ruban de led
}

```


#### Spécifier la couleur en HSV

Le montage est le même : 
<img src="assets/set_neopixels_hsb.gif" width="480" height="270" /><br>

Le code est quasiment le même sauf que l'on appelle la fonction **CHSV()** de la bibliothèque Fast-led. Même si dans la plupart des logiciels la teinte est représentée par une valeur entre 0 et 360 et la saturation ainsi que le luminosité sont représentées par des valeurs comprises entre 0 et 100, ici chacune des trois valeurs doit être comprise entre 0 et 255.


```c
// inclure la bibliothèque fast-led
#include <FastLED.h>
#define NUM_LEDS 5 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0;

void setup() {
  // on initialise notre strip de led sur la pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {
    
  // on augmente la valeur de inc
  // on calcul en fonction de inc un valeur qui va osciller entre 0 et 244.
  inc +=  0.05;
  int saturation = (sin(inc) + 1)*122; // cette valeur est stocké dans une variable nommée "saturation"
  // Pour i allant de 0 à 5, on va éxecuter le code entre accolades, 
  // à chaque fois on augmente la valeur de i de 1
  for (int i = 0; i < NUM_LEDS; i++) {
    // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
    leds[i] = CHSV(255 - i *50, saturation, 255);
  }
    FastLED.show();// on actualise le ruban de led
}
```

on peut encore une fois appeler directement la fonction **CHSV()**
```c
void loop(){
    leds[0] = CHSV(0, 255, 255); //rouge
    leds[1] = CHSV(90, 255, 255); // vert
    leds[2] = CHSV(180, 255, 255); // bleu
    leds[3] = CHSV(255, 0, 255); // blanc
    leds[0] = CHSV(0, 0, 0); // noir
    FastLED.show(); // on actualise le ruban de led
}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Utiliser un afficheur à 4 digits

Un afficheur à 4 digits permet d'afficher des chiffres et des lettres (de A à F) sur des digits (ensemble de 7 segments). Il y a 4 digits disponnibles pour afficher des chiffres.

<img src="assets/set_four_digit_display.gif" width="480" height="270" /><br>

La page de documentation du fabricant du composant est disponnible ici : http://wiki.seeedstudio.com/Grove-4-Digit_Display/

Le cablage est un cablage classique pour ce genre de périphérique.

<img src="set_four_digit_display/set_four_digit_display.png" width="480" height="270" /><br>

D'un point de vue logiciel il va vous falloir télécharger le bibliothèque **TM1637** /**Grove 4-digit display**.

```c
// inclure la bibliothèque dédiée à l'afficheur 4 digit
#include "TM1637.h"
// définir les pins de connexion pour la clock et la donnée
#define CLK 8
#define DIO 9
TM1637 tm1637(CLK, DIO); // attacher de manière effective nos pin et notre écran

// définir les caractères disponnibles
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F
// définir une variable que l'on va augmenter petit à petit pour calculer en temps
int num = 0;

void setup() {
  // initialiser notre écran et spécifier sa luminosité
  tm1637.init();
  tm1637.set(BRIGHTEST);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop(){

  // calculer le chiffre à afficher pour chaque colone du tableau de numération
  // car même si notre chiffre à moins de 4 valeurs (0 pour les milliers, centaines et dizaines)
  // on veut afficher les zéros précédent notre valeur.
  int milles = int((num /1000)%10);
  int cents = int ((num /100)%10);
  int dizaines = int((num/10)%10);
  int unites = int(num%10);
  
  tm1637.display(0, NumTab[milles]); // afficher le chiffre des milliers sur l'ensemble de segment le plus à gauche
  tm1637.display(1, NumTab[cents]);
  tm1637.display(2, NumTab[dizaines]);
  tm1637.display(3, NumTab[unites]); // afficher le chiffre des unités sur l'ensemble de segment le plus à droite
    
  delay(10); // attendre un peu
  
  num +=1 ; // augmenter la valeur de num de 1
}
```
Remarquez bien qu'ici on mesure des dizaines de millisecondes : le *delay(10)* fait que le programme se met en pause une dizaine de millisecondes avant de boucler.


[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


## Controler un actuateur avec un capteur

Dans cette partie nous allons nous attacher à créer des montages un peu plus complexes, et aussi à écrire du code un peu plus complexe.

L'objectif est de controller un actuateur (par exemple un moteur) avec un capteur (par exemple une photorésistance). L'actuateur a besoin de recevoir certaines valeurs (comprises entre 0 et 180 pour un moteur par exemple) et nos capteurs peuvent fournir tout type de plages de valeurs (entre 0 et 1023 pour une photorésistance).

Il va donc falloir récupérer les valeurs de notre capteur et les transformer dans un intervalle utile pour notre actuateur. Il s'agit en réalité unique de réaliser un produit en croix - mais une fonction dédiée est prévue dans le langage de programation arduino.

### Utiliser la fonction map()

La fonction [**map()**](https://www.arduino.cc/reference/en/language/functions/math/map/) permet de transformer une valeur qui est dans un intervalle que l'on connait vers un nouvel intervalle qui nous sera utile.

Par exemple :
```c
int val = analogRead(0); // lire une valeur sur A0 - celle ci sera comprise entre 0 et 1023
int newval = map(val, 0, 1023, 0, 180); // notre valeur est comprise entre 0 et 1023, on veut une valeur entre 0 et 180
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Potentiomètre vers servo classique

Comment controller un servomoteur avec un potentiomètre ?

<img src="assets/map_potentiometer_to_servo.gif" width="480" height="270" /><br>

Le montage est la réunion de deux montages déjà vu précédement : on branche un potentiomètre sur l'entrée analogique *A0*, et on branche un moteur sur la sortie digitale *D6*.

<img src="map_potentiometer_to_servo/map_potentiometer_to_servo.png" width="480" height="270" /><br>

Le code va aussi réunir deux bouts de code déjà existant, on va juste utiliser la fonction map pour faire le lien entre notre mesure de la valeur du potentiomètre et l'information que l'on va envoyer au servomoteur.

```c
// inclure la bibliothèque pour les servomoteurs
#include <Servo.h>
Servo myservo; // créer un objet permettant de manipuler un servomoteur


void setup() {
  Serial.begin(9600); // ouvrir une connexion série
    
  pinMode(6, OUTPUT);// préciser que l'on va utiliser la pin 6 comme une sortie.
  myservo.attach(6);// attacher notre servomoteur à cette pin 6
    
}

void loop() {

  int potValue = analogRead(0); // on lit notre valeur sur l'entrée analogique 0
  Serial.println(potValue); // on imprimme la valeur de notre potentiomètre dans le moniteur série
  
  // on va calculer une position pour notre servomoteur, une position qui dépendra de la valeur de notre potentiomètre
  int servoPos = map(potValue, 0, 1023, 0, 180); // on map la valeur de notre potentiomètre qui est comprise entre 0 et 1023, vers un intervalle compris entre 0 et 180?.
  myservo.write(servoPos); // écrire la position calculée sur le servomoteur
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Flex vers servo continu

L'objectif ici va être de contrôller la vitesse et le sens de rotation d'un servomoteur à l'aide d'un capteur de flexion :

<img src="assets/map_flex_to_servo_continu.gif" width="480" height="270" /><br>

De la même manière que précédement, ce montage est la combinaison du montage permettant de récupérer l'information d'un capteur de flexion et du montage permettant de controller un servomoteur à rotation continue.

<img src="map_flex_to_servo_continu/map_flex_to_servo_continu.png" width="480" height="560" /><br>

Le code va reprendre le code permettant de mesurer la valeur d'un capteur de flexion et va le combiner avec le code permettant de faire tourner un moteur à rotation continue en mappant les valeur provenant du capteur de flexion vers des valeurs utiles pour faire tourner un moteur à rotation continu.

```c
// inclure la bibliothèque pour controller des servomoteurs
#include <Servo.h>
Servo myservo; // créer un objet qui nous permettra de manipuler notre servomoteur.


void setup() {
  Serial.begin(9600); // ouvrir une connexion série pour pouvoir imprimmer des valeurs dans le moniteur série
  pinMode(6, OUTPUT); // on précise que l'on utilise la pin 6 comme une sortie
  myservo.attach(6); // on précise que notre servo est connecté sur la pin 6


}

void loop() {
  // on lit la valeur provenant de notre capteur de flexion qui est branché sur la pin A0
  int flexion = analogRead(0);
  Serial.println(flexion);// on imprime la valeur dans le moniteur série
  // on va calculer une vitesse de rotation pour notre servomoteur qui dépendera de la valeur mesurée par
  // notre capteur de flexion. En observant les valeurs imprimmées dans le moniteur série, on se rend compte que 
  // les valeurs de notre capteur sont a peu près comprises entre 200 et 700.
  int servoRotation = map(flexion, 200, 700, 0, 180); // on mappe donc notre valeur de flexion qui est comprise entre 200 et 700 vers de valeurs comprises entre 0 et 180
  myservo.write(servoRotation); // on envoit ces nouvelles valeurs vers notre servomoteur pour le faire tourner.
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### FSR vers neopixels HSB

Ici nous allons utiliser un capteur pour fixer la teinte de la lumière produite par un strip de leds rgb.

<img src="assets/map_fsr_to_neopixels.gif" width="480" height="270" /><br>

Le cablage comporte un capteur de force avec un résistance 47kOhms branché sur l'entrée analogique A0, et un strip de led branché sur la pin digitale D6.

<img src="map_fsr_to_neopixels/map_fsr_to_neopixels.png" width="480" height="270" /><br>

Comme d'habitude nous allons récupérer une valeur analogique comprise entre 0 et 1023 et nous allons transformer les valeurs obtenues en valeurs comprises entre 0 et 255 pour pouvoir controller la teinte de nos leds.

 ```c
// bibliothèque pour les leds
#include <FastLED.h>
#define NUM_LEDS 5 // préciser le nombre de leds

CRGBArray<NUM_LEDS> leds; //créer un tableau pour adresser chaque led individuellemtn


void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS); // initialiser le ruban sur la pin 6
}

void loop() {
  int fsrValue = analogRead(0); // lire la valeur analogique
  int hueValue = map(fsrValue, 0, 1023, 0, 200); // transformer notre valeur provenant du capteur en une valeur comprise entre 0 et 200.
    
  // on parcourt toutes les leds de notre rubant à l'aide d'une boucle fort
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hueValue, 255, 255); // on applique la teinte en utilisant le mode HSV 
  }
  FastLED.show();// on actualise le ruban de led
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

## Utiliser des capteurs pour contrôler du code processing

Dans cette partie nous allons nous concenter sur l'utilisation du port série et nous allons depuis un programme arduino écrire des valeurs de capteurs dans un port série que nous pourrons alors récupérer dans un programme processing.

Nous pourrons faire de même dans l'autre sens : c'est à dire envoyer des informations de processing vers arduino.

Pour info USB signifie Universal Serial Bus, le port série est donc bien le port usb on programme donc une manière de faire transiter d'un appareil à l'autre des information via une connexion usb.

### Controler le playback d'une vidéo avec un capteur de distance

Le premier programme va utiliser un capteur de distance et la distance détectée par notre capteur servira à régler la vitesse de défilement d'une vidéo lue par un programme processing : 

<img src="assets/serial_distance_to_movie_speed.gif" width="480" height="270" /><br>

Pour rappel le cablage du capteur de distance ce fait comme ceci :

<img src="read_from_IRDistance/read_from_irdistance.png" width="480" height="270" /><br>

Nous allons utiliser l'exemple de code fournit dans la bibliothèque vidéo de processing. Disponible dans le navigateur d'exemples : *Exemples* -> *Libraries* -> *Video* -> *Movie* -> *Speed*

Je vous conseille de l'ouvrir depuis processing (comme ça vous aurez déjà la vidéo et le code), mais le code ressemble à cela avec quelques commentaires en français.

```java
/**
 * Speed. 
 * Use the Movie.speed() method to change
 * the playback speed.
 */

import processing.video.*; // importer la bibliothèqe video
Movie mov; // créer un objet Movie appelé mov afin de pouvoir charger un film et le lire.

void setup() {
  size(640, 360);
  background(0);
  mov = new Movie(this, "transit.mov"); // charger le film "transit.mov" qui se trouve dans le dossier data de votre sketch
  mov.loop(); //lancer la lecture du film en boucle
}

void draw() {    
  image(mov, 0, 0); // afficher une frame du film
             
  // calculer une variable que l'on utilisera pour controller la vitesse de défilement du film
  // cette variable dépendera de la souris dont la position horizontale est comprise entre 0 et 'width'
  // et nous voulons obtenir des valeurs entre 0.1 et 2
  float newSpeed = map(mouseX, 0, width, 0.1, 2);
  mov.speed(newSpeed); // utiliser notre variable pour chager la vitesse de lecture du film
  
  // afficher la valeur de la vitesse en haut à gauche
  fill(255);
  text(nfc(newSpeed, 2) + "X", 10, 30); 
}  

// fonction nécessaire pour déclencher la lecture du film
void movieEvent(Movie movie) {
  mov.read();  
}

```

Dans ce code on fait dépendre la vitesse de la position de la souris, nous allons donc remplacer la variable *mouseX* à la ligne :

```java
float newSpeed = map(mouseX, 0, width, 0.1, 2);
```
par la valeur que nous allons capter via notre capteur de distance et notre carte arduino. Pour cela dans notre code arduino nous allons écrire une chaîne de caractère au format [**JSON**](https://fr.wikipedia.org/wiki/JavaScript_Object_Notation) dans laquelle nous allons insérer une valeur lue sur notre entrée analogique.

Notre chaîne de caractère devra ressembler à cela
```json
{
    "distance" : valeur_actuelle_de_la_distance
}
```

Ce code arduino permet de faire cela avec la concaténation de chaîne de caractères.

```c
String json;
  json = "{\"distance\":";
  json = json + analogRead(0);
  json = json + "}";
```

Il ne nous reste plus qu'à poster cette chaîne de caractère sur le port série à l'aide de **Serial.println()** comme d'habitude. Voici donc l'ensemble du code arduino :

```c

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int value = analogRead(00);

  String json;
  json = "{\"distance\":";
  json = json + value;
  json = json + "}";

  Serial.println(json);
}
```

Du côté processing il faut maintenant s'atteler à recevoir cette chaîne de caractères, extraire la donnée de distance et l'utiliser.

Il va nous falloir utiliser la bibliothèque [**Serial**](https://processing.org/reference/libraries/serial/index.html), il n'est pas nécessaire de l'installer car elle est integrée par défaut dans processing.

Il faut donc commencer par importer la bibliothèqe en tapant tout en haut du sketch que nous utilisons pour lire notre film :
```java
import processing.serial.*;
Serial myPort;  // Créer un objet serial pour pouvoir lire les information postées sur le port série
```
nous en profiterons créer une variable destinée à stocker l'information reçue par arduino

```java
int valueFromArduino = 50;
int movieSpeed = 0;
```

Ensuite nous devons ajouter quelques lignes au **setup()** : il faut au démarrage du programme initialiser la connexion série avec notre carte arduino.

```java
// initialisation de la communication via usb depuis arduino
// ATTENTION à bien utiliser le port adapté
printArray(Serial.list()); // imprimmer la liste des appreils connectés au port série
String portName = Serial.list()[3]; // ma carte arduino est la troisième dans la liste imprimmée dans la console
myPort = new Serial(this, portName, 9600); // on ouvre la communication
myPort.bufferUntil('\n');
```

Maitenant il nous faut exécuter du code à chaque fois qu'une information est postée sur le port série, cela se fait en l'écrivant dans une fonction : 
```java
void serialEvent (Serial myPort) {
  
}
```

Le code ci-dessous est un peu barbare, mais il n'est pas nécessaire de tout comprendre. En gros on va essayer de lire les données arrivant sur le port série, si celui-ci est ouvert, puis on va décrotiquer la chaine de caractère :

```java
void serialEvent (Serial myPort) {
  try { // on essaye de faire qqchose mais on ne plante pas si on y arrive pas
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n'); // lire la chaine de caractère du port série jusqu'au retour charriot
      if (inBuffer != null) { // si ce n'est pas nul
        if (inBuffer.substring(0, 1).equals("{")) { // et si ça ressemble à du json
          JSONObject json = parseJSONObject(inBuffer); // on essaye de le lire comme du json
          // C'est à partir de là qu'il faut comprendre !!
          if (json == null) { // si ce n'est pas du json on fait rien
            
          }
          else { // sinon on récupère la valeur portant le nom 'distance' et on la stocke dans une variable !
            if (abs(json.getInt("distance")-valueFromArduino)> 50) { // vérifier que la valeur a suffisament changé
              valueFromArduino    = json.getInt("distance");
              // on map la valeur et on la stocke dans notre variable movie speed créée tout au début
              movieSpeed = map(valueFromArduino, 50, 650, 2, 0);
              movieSpeed = constrain(movieSpeed, 0, 2); // on maintient cette valeur dans un intervalle cohérent des fois que notre capteur renvoit des valeurs trop grandes ou trop petites
            }
          }
        // il ne nous reste plus qu'à fermer toutes nos accolades ^^
        } 
        else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}
```
Il y a pas mal de tests de sécurité pour éviter que notre programme plante si notre chaîne est nulle ou si la donnée que l'on cherche n'est pas disponible.

Mais il ne nous reste plus qu'à utiliser *movieSpeed* pour réellement controller la vitesse de lecture du film.

```java
mov.speed(movieSpeed);
```

Voici donc le code processing permettant de récupérer la valeur de distance depuis arduino et l'utiliser pour controller la vitesser de lecture d'un film :

```java

import processing.video.*;
Movie mov;


import processing.serial.*;
Serial myPort;  

int valueFromArduino = 50;
float movieSpeed = 2;

void setup() {
  size(800, 500);
  background(0);

  mov = new Movie(this, "transit.mov");
  mov.loop();

  // initialisation de la communication via usb depuis arduino
  // ATTENTION à bien utiliser le port adapté
  printArray(Serial.list());
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void movieEvent(Movie movie) {
  mov.read();
}

void draw() {    
  image(mov, 0, 0,width,height);

  
  mov.speed(movieSpeed);

  fill(255);
  text(nfc(movieSpeed, 2) + "X", 10, 30);
}  

void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            if (abs(json.getInt("distance")-valueFromArduino)> 50) {
              valueFromArduino    = json.getInt("distance");
              movieSpeed = map(valueFromArduino, 50, 650, 2, 0);
              movieSpeed = constrain(movieSpeed, 0, 2);
            }
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Controler une animation avec une photoresistance

La logique de cette animation est très similaire à la précédente. Nous allons remplacer le capteur de distance par une photorésistance et nous allons utiliser un exemple différent :

<img src="assets/serial_photores_to_animation.gif" width="480" height="270" /><br>

Le cablage est celui d'une photorésistance classique branchée sur A0.
<img src="read_from_photores/read_from_photores.png" width="480" height="270" /><br>

Le code arduino est quasiment le même, on va juste adapter l'identifiant dans notre json qui va stocker notre valeur :

```c
void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  String json;
  json = "{\"photores\":";
  json = json + value;
  json = json + "}";

  Serial.println(json);
}
```

D'un point de vue processing nous allons encore une fois utiliser un exemple disponible avec le logiciel : *Exemples* -> *Topics* -> *Fractals and L-Systems* -> *Tree*

```java
/**
 * Recursive Tree
 * by Daniel Shiffman.  
 * 
 * Renders a simple tree-like structure via recursion. 
 * The branching angle is calculated as a function of 
 * the horizontal mouse location. Move the mouse left
 * and right to change the angle.
 */
 
float theta;   

void setup() {
  size(640, 360);
}

void draw() {
  background(0);
  frameRate(30);
  stroke(255);
  // Let's pick an angle 0 to 90 degrees based on the mouse position
  float a = (mouseX / (float) width) * 90f;
  // Convert it to radians
  theta = radians(a);
  // Start the tree from the bottom of the screen
  translate(width/2,height);
  // Draw a line 120 pixels
  line(0,0,0,-120);
  // Move to the end of that line
  translate(0,-120);
  // Start the recursive branching!
  branch(120);

}

void branch(float h) {
  // Each branch will be 2/3rds the size of the previous one
  h *= 0.66;
  
  // All recursive functions must have an exit condition!!!!
  // Here, ours is when the length of the branch is 2 pixels or less
  if (h > 2) {
    pushMatrix();    // Save the current state of transformation (i.e. where are we now)
    rotate(theta);   // Rotate by theta
    line(0, 0, 0, -h);  // Draw the branch
    translate(0, -h); // Move to the end of the branch
    branch(h);       // Ok, now call myself to draw two new branches!!
    popMatrix();     // Whenever we get back here, we "pop" in order to restore the previous matrix state
    
    // Repeat the same thing, only branch off to the "left" this time!
    pushMatrix();
    rotate(-theta);
    line(0, 0, 0, -h);
    translate(0, -h);
    branch(h);
    popMatrix();
  }
}
```

D'une manière assez similaire à précédement, on peut identifier la ligne pertinente pour l'interaction :
```java
// Let's pick an angle 0 to 90 degrees based on the mouse position
  float a = (mouseX / (float) width) * 90f;
```

On va donc supprimer cett ligne et 'remplacer' *mouseX* par une valeur provenant de la photorésistance... D'abord adaptons la fonction *serialEvent()* utilisé précédement pour récupérer la valeur provenant de notre programme arduino :

- Définissons d'abord une variable globale qui permettera de stocker notre valeur :
```java
float valueFromArduino = 0;
```

- Puis adaptons la fonction *serialEvent()* pour ranger dans *valueFromArduino* la valeur de la photorésistance en utilisant la bonne clé, soit celle que nous avons définit dans notre programme arduino (ie 'photores') :
```java
void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            valueFromArduino    = json.getInt("photores");
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}
```
Il ne nous reste plus qu'à utiliser cette valeur en la mappant à un intervalle de valeur visuellement pertinent
```java
theta = map(valueFromArduino, 15, 250, 0, PI);
```
Voici donc finalement le programme processing en integralité :

```java
/**
 * hacked from
 * Recursive Tree
 * by Daniel Shiffman.  
 * 
 * and acousteauphone-prototype from lesporteslogiques
 * by Pierre Commenge
 */

import processing.serial.*;
Serial myPort;  // Create object from Serial class

float valueFromArduino = 0;
float theta;   

void setup() {
  size(640, 360);

  // initialisation de la communication via usb depuis arduino
  // ATTENTION à bien utiliser le port adapté
  printArray(Serial.list());
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(0);
  frameRate(30);
  stroke(255);


  // Convert it to radians
  theta = map(valueFromArduino, 15, 250, 0, PI);
  // Start the tree from the bottom of the screen
  translate(width/2, height);
  // Draw a line 120 pixels
  line(0, 0, 0, -120);
  // Move to the end of that line
  translate(0, -120);
  // Start the recursive branching!
  branch(120);
}

void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            valueFromArduino    = json.getInt("photores");
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}

void branch(float h) {
  // Each branch will be 2/3rds the size of the previous one
  h *= 0.66;

  // All recursive functions must have an exit condition!!!!
  // Here, ours is when the length of the branch is 2 pixels or less
  if (h > 2) {
    pushMatrix();    // Save the current state of transformation (i.e. where are we now)
    rotate(theta);   // Rotate by theta
    line(0, 0, 0, -h);  // Draw the branch
    translate(0, -h); // Move to the end of the branch
    branch(h);       // Ok, now call myself to draw two new branches!!
    popMatrix();     // Whenever we get back here, we "pop" in order to restore the previous matrix state

    // Repeat the same thing, only branch off to the "left" this time!
    pushMatrix();
    rotate(-theta);
    line(0, 0, 0, -h);
    translate(0, -h);
    branch(h);
    popMatrix();
  }
}
```
[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Controler des leds neopixels avec la souris

Ce troisième exemple va illustrer la communication inverse : nous allons envoyer des données de processing à arduino. En fonction de la position de la souris la couleur de la fenêtre sera affectée et ces positions de souris seront aussi envoyées à arduino pour controller l'allumage de leds.

<img src="assets/serial_mouse_to_neopixels.gif" width="480" height="270" /><br>

Le schéma électrique est simple : il s'agit de brancher un ruban de leds sur une carte arduino :

<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

Le programme processing va utiliser le mode HSB pour ajuster le teinte en fonction de la position en abscisses de la souris, la saturation en fonction de la position en ordonnées de la souris et la luminosité en fonction de l'état de la souris (est-ce qu'on appuie sur le bouton ou non ?) Ces données seront mappées dans processing puis écrites sur le port série pour pouvoir les réutiliser dans arduino. Nous allons donc envoyer 3 valeurs, ces valeurs seront séparées par des virgules et nous utiliserons un point virgule pour marquer la fin d'un paquet de données.

```java
import processing.serial.*;

Serial myPort;  

void setup() {
  size(600, 600); 
  colorMode(HSB,255,255,255);
  //initialisation de la bibliothèque série
  println(Serial.list());
  String portName = Serial.list()[3]; //attention à bien utiliser le bon port
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  int pressed = 0;
  if (mousePressed == true) {    
    pressed = 1;         
  } else {                         
    pressed = 0; 
  }  
  int x =int( map(mouseX, 0, width, 0, 255));
  int y =int( map(mouseY, 0, height, 0, 255));
             
  background(x, y, pressed*255);
             
  String s = pressed+","+x+","+y+";";
  println(s);
  myPort.write(s);
}
```

Le code arduino lui va être nettement plus complexe que d'habitude, mais il n'est pas nécessaire de tout comprendre. Vous pouvez vous référer au [post original](http://www.esologic.com/parsing-serial-data-sent-to-arduino/) si vous le souhaitez.

La partie que nous allons manipuler est située à l'intérieur du *else* dans la fonction loop

```c
// from http://www.esologic.com/parsing-serial-data-sent-to-arduino/

// code nécessaire à la réception et à l'extraction de données provenant de processing
const char EOPmarker = ';'; //This is the end of packet marker
char serialbuf[32]; //This gives the incoming serial some room. Change it if you want a longer incoming.
#include <string.h> // we'll need this for subString
#define MAX_STRING_LEN 20 // like 3 lines above, change as needed.

// code nécessaire au fonctionne ment des leds
#include <FastLED.h>
#define NUM_LEDS 5
CRGBArray<NUM_LEDS> leds;

void setup() {
 
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {
    
  if (Serial.available() > 0) { //makes sure something is ready to be read
    // cette partie de code permet de recomposer le message provenant de processing
    static int bufpos = 0; //starts the buffer back at the first position in the incoming serial.read
    char inchar = Serial.read(); //assigns one byte (as serial.read()'s only input one byte at a time
    if (inchar != EOPmarker) { //if the incoming character is not the byte that is the incoming package ender
      serialbuf[bufpos] = inchar; //the buffer position in the array get assigned to the current read
      bufpos++; //once that has happend the buffer advances, doing this over and over again until the end of package marker is read.
    }
    
    // à l'intérieur de ce else nous pouvons récupérer nos valeurs et les utiliser
    else { //once the end of package marker has been read
      serialbuf[bufpos] = 0; //restart the buff
      bufpos = 0; //restart the position of the buff

      int pressed = atoi(subStr(serialbuf, ",", 1)); // récupérer la première valeur et la stocker dans une variable
      int x = atoi(subStr(serialbuf, ",", 2)); // récupérer la deuxième ...
      int y = atoi(subStr(serialbuf, ",", 3)); // récupérer la troisième...
        
      // allumer les leds en fonction de nos valeurs
      for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(x, y, pressed *255);
      }
      FastLED.show();

    }
  }
}

// cette fonction est nécessaire pour permettre de découper la chaine de caractère provenant de processing
char* subStr (char* input_string, char *separator, int segment_number) {
  char *act, *sub, *ptr;
  static char copy[MAX_STRING_LEN];
  int i;
  strcpy(copy, input_string);
  for (i = 1, act = copy; i <= segment_number; i++, act = NULL) {
    sub = strtok_r(act, separator, &ptr);
    if (sub == NULL) break;
  }
  return sub;
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Enregistrer des données dans un fichier

Dans cet exemple nous allons nous attacher à lire des données provenant de plusieurs capteurs et nous allons les transmettre à processing afin de pouvoir les enregistrer dans un fichier sur notre disque dur.

Cela peut-être utile afin de pouvoir réaliser des représentation de données basées sur des enregistrement de capteurs.

Dans notre cas nous allons enregistrer les données analogiques provenant de deux photorésistances, elles seront côte à côte sur une planche de prototypage, ce qui n'est pas idéal; mais il est facile d'imaginer des situation où les capteurs pourront être positionnés à différents endroits et il serait donc possible de mesurer l'ensoleillement à différents endroits.

#### Circuit

Le circuit est un circuit assez classique :

<img src="serial_enregistrer_des_donnees_dans_un_fichier/read_from_photores_x2.png" width="480" height="360" /><br>

#### Code arduino

Du point de vue du code arduino, il n'y a pas grand chose de nouveau. Comme précédement nous allons écrire une chaîne de caractère au format [**JSON**](https://fr.wikipedia.org/wiki/JavaScript_Object_Notation) dans laquelle nous allons insérer une valeur lue sur notre entrée analogique.

Notre chaîne de caractère devra ressembler à cela
```json
{
    "luminosite" : valeur_de_la_photorésistance
}
```

Ce code arduino permet de faire cela avec la concaténation de chaîne de caractères.

```c
String json;
  json = "{\"luminosite\":";
  json = json + analogRead(0);
  json = json + "}";
```

Dans notre cas nous aurons deux valeurs à enregistrer,  puis il faudra imprimer le résultat dans le port Serial.

```c
void setup() {
  Serial.begin(9600); // ouvrir une connection via le cable série
}

void loop() {
  int photor1 = analogRead(A0); // lire les données sur A0 et les stocker dans une variable
  int photor2 = analogRead(A1);// lire les données sur A1 et les stocker dans une variable

  delay(1000); // attendre 1 seconde
 
  // construire une chaine de caractère par concatenation
  String json;
  json = "{\"photor1\":"; // on ajoute la première clé "photor1"
  json = json + photor1; // on ajoute la première valeur  
  json = json +";\"photor2\":"; // on ajoute la seconde clé "photor2"
  json = json +  photor2;// on ajoute la seconde valeur  
  json = json + "}";

  Serial.println(json); // on écrit notre fichier sur le port série
  // nous allons donc pouvoir récupérer ces valeurs avec processing
}
```

#### Code processing

Encore une fois le code processing va être assez similaire à ce que nous avons fait jusqu'à présent notament dans les exemples précédents.

La seule différence est que nous allons utiliser différentes fonctions pour charger un fichier depuis le disque dur, manipuler des objets json et enregistrer un fichier sur le disque dur.

Dans un premier temps voici, un sketch classique qui permet de récupérer les valeurs et les visualiser au rythme auquel elles arrivent.

```java

import processing.serial.*;
Serial myPort;  

int photor1 =0;
int photor2 =0;


void setup() {
  size(800, 500);
  // initialisation de la communication via usb depuis arduino
  // ATTENTION à bien utiliser le port adapté
  printArray(Serial.list());
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {    
  background(0);
  fill(255);

  ellipse(width*0.25, height*0.5, photor1, photor1);
  ellipse(width*0.75, height*0.5, photor2, photor2);
}  

void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            // récupérer les données stockée dans le format json transmis via usb
            photor1    = json.getInt("photor1"); // on récupère la valeur correspondant à la clé "photor1"
            photor2    = json.getInt("photor2");
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}
```

Il nous faut maintenant nous occuper de l'enregistrement sur le disque dur.

Tout d'abord il nous faut un fichier texte vide appelé **data.json** dans un dossier /data situé à l'endroit ou votre programme processing est sauvegardé. En réalité il ne doit pas être complétement vide mais juste contenir une accolade ouvrante et une accolade fermante :

```json
{}
```
cela correspond à la structure de base d'un fichier json.

Après avoir récupéré les données depuis la chaîne de caractère au format json depuis l'arduino et ce toujours dans la fonction *void serialEvent(Serial myPort)*

```java
// récupérer les données stockée dans le format json transmis via usb
photor1    = json.getInt("photor1"); // on récupère la valeur correspondant à la clé "photor1"
photor2    = json.getInt("photor2");
```

Nous allons pouvoir procéder à l'enregistrement :
- d'abord nous devons charger notre fichier json (pour l'instant vide)
  ```java
  JSONArray js  = loadJSONArray("data.json"); // on charge le fichier data.json - dans lequel on va ajouter une entrée
  ```

- ensuite nous allons créer un nouvel objet json que nous allons renseigner avec de nouvelles données
  ```java
  JSONObject njs = new JSONObject(); // on crée un nouvel objet json
            // on ajoute un timestamp avec date et heure
  njs.setString("timestamp", year()+"-"+month()+"-"+day()+"-"+hour()+"-"+minute()+"-"+second());
  njs.setInt("luminosity1", photor1); // on ajoute la première valeur
  njs.setInt("luminosity2", photor2); // on ajoute la seconde valeur
  ```

- puis nous allons ajouter ce nouvel objet à notre fichier chargé à l'étape 1.
  ```java
  js.append(njs); // on ajoute ce nouvel objet à l'objet chargé précédement
  ```

- enfin nous sauvegardons le tout sur notre disque dur
  ```java
  saveJSONArray(js, "data/data.json"); // on sauvegarde le tout en écrasant le fichier précédent.
  ```
A chaque fois que des données sont reçues nous rechargeons le fichier, ajoutons des données et écrasons le fichier précédent : au fur et à mesure nous stockons donc toutes les données envoyées par arduino.

Après avoir réalisé un enregistrement, il faut bien penser à renommer le fichier *data.json* avec un nom équivoque et à recréer un fichier vide si l'on veut relancer un enregistrement.

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>
