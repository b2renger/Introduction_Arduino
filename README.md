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

### Digital sensors - SDA and SCL

The sensors we will use now will be able to provide us more complex and less raw information, and they will allow us to recover several values ​​at the same time. 

We speak of [**I2C**](https://en.wikipedia.org/wiki/I%C2%B2C) sensors, they usually plug into analog inputs 4 and 5 of an arduino uno card, or in the dedicated pins.

The **I2C** protocol allows you to communicate with two wires, one will carry the **data** (**SDA**) and the other the **clock** (**SCL**). The signal carried by the clock will recompose the data made of bits (stream of 0 and 1).

Generally these sensors are already mounted on integrated circuits and require the wiring of only 4 cables: GND, VCC for power supply, and SDA and SCL for data.

The code can be complex and often involves the use of libraries provided by the community or by the manufacturer. So you often have to refer to the manufacturer's page to find the way to operate sensors, so be careful to choose well-documented sensors.

Installing a library is done via a GUI in the arduino IDE. You have to open the menu *Sketch* -> *Include a library* -> *Manage libraries*

<img src="assets/arduino_bibliotheques.png" width="680" height="470" /><br>

Which will allow you to open this window:

<img src="assets/arduino-gestionnaire-bibliotheque.png" width="680" height="370" /><br>

You then have a search box that allows you to search and install the libraries you need.

Generally each library comes with more or less useful examples, at least one and more or less clear. You can access it via the *File* -> *Examples* menu and at the very bottom of the drop-down menu you will find your custom library examples.


#### accelerometer

The [*accelerometer*](https://en.wikipedia.org/wiki/Accelerometer) allows measurement of linear acceleration, ie the projection of gravity on each of its three axes.

<img src="assets/read_fom_accelerometer.gif" width="480" height="270" /><br>

The circuit is quite simple:

<img src="read_from_accelerometer/read_from_3axisAccelerometer.png" width="480" height="360" /><br>

The code is quite complex, it uses the library *ADXL345* dedicated to this component, it will not be used with all accelerometers.

We can learn more about its use on the manufacturer's reference page: http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/

What is important that we store the values ​​from the accelerometer each time the loop is executed. To recover these values ​​one has to resort to the methods written and described in the library - it is not possible to simply recompose the data through the information measured on the pins.

```c
// we are going to need these libraries
#include <Wire.h>
#include <ADXL345.h>

ADXL345 accel; // create an object that allows us to manipulate data from our accelerometer

void setup() {
  Serial.begin(9600);
  accel.powerOn(); // we activate our sensor
}

void loop() {

  // we create three variables to store the raw values ​​of our accelerometer.
  int x, y, z;
  accel.readXYZ(&x, &y, &z); // read data from the accelerometer and store them in our variables.
  // we print the result in the serial monitor
  Serial.print("values of X , Y , Z: ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print(y);
  Serial.print(" , ");
  Serial.println(z);

  // we create a table to store the values ​​coming from the computation done by our library when we call getAcceleration ()
  double xyz[3]; 
  accel.getAcceleration(xyz); // read data from the accelerometer and store it in our table
 // print the result
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

A [*gyroscope*](https://en.wikipedia.org/wiki/Gyroscope) allows to measure the rotation of an object in space and to know its angular position.

Its use is quite similar to the use of an accelerometer.

<img src="assets/read_from_gyroscope.gif" width="480" height="270" /><br>

<img src="read_from_gyroscope/read_from_3axisGyro.png" width="480" height="360" /><br>

The manufacturer's documentation page provides us with information about its use in terms of code:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Gyro/    

It will be necessary to install the library *ITG3200* - Grove 3-axis-digital-gyro.

```c
//we are going to need these libraries
#include <Wire.h>
#include "ITG3200.h"

ITG3200 gyro;
void setup(){
    Serial.begin(9600);
    // activate our sensor
    gyro.init();
    gyro.zeroCalibrate(200,10);//sample 200 times to calibrate and it will take 200*10ms - don't move
}

void loop(){
    // we create three variables to store the raw values ​​of our gyro.
    int16_t x,y,z;
    gyro.getXYZ(&x,&y,&z);// we read the data of the gyro and we store them in our variables.
    // print the result in the serial monitor
    Serial.print("values of X , Y , Z: ");
    Serial.print(x);
    Serial.print(" , ");
    Serial.print(y);
    Serial.print(" , ");
    Serial.println(z);

   // we create three variables to store the values ​​coming from the calculation made by our library
    float ax,ay,az;
    gyro.getAngularVelocity(&ax,&ay,&az);
    // we print
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

The last sensor we will see is a *gesture sensor*. It will allow us to identify up to 9 gestures:

<img src="assets/read_from_gesture.gif" width="480" height="270" /><br>

This sensor consists of a series of photoresistors: when moving in front, the brightness received by each photoresistor changes and a software library allow us to recognize patterns of current measurement related to these gestures.

<img src="read_from_gesture_sensor/read_from_gesture.png" width="480" height="360" /><br>

According to the manufacturer's page: http://wiki.seeedstudio.com/Grove-Gesture_v1.0/
use the library *paj7620* - *Gesture PAJ7620*

To identify the different cases of gestures we will use a [**switch()**](https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/). control structure

This type of code syntax allows us to handle different cases depending on the value of a variable and thus execute a different code for each value (similar to a if statement). Here we will print each time a different message in the serial monitor.


```c
// libraries
#include <Wire.h>
#include "paj7620.h"

// a variable to hold the id of a gesture
uint8_t gesture = 0;

void setup() {
  Serial.begin(9600);
  // initialize the sensor
  gesture = paj7620Init();			// initialize Paj7620 registers
  Serial.println("Please input your gestures:\n");
}

void loop() {
  // Variables to store sensor values
  uint8_t data = 0, data1 = 0;
  gesture = paj7620ReadReg(0x43, 1, &data); // read the value of the sensor

  switch (data){ 
    case GES_RIGHT_FLAG: // if data is a gesture to the right
      Serial.println("Right");
      break;
    case GES_LEFT_FLAG: // if data is a gesture to the left
      Serial.println("Left");
      break;
    case GES_UP_FLAG:// if data corresponds to a gesture upwards
      Serial.println("Up");
      break;
    case GES_DOWN_FLAG:// if data is a down gesture
      Serial.println("Down");
      break;
    case GES_FORWARD_FLAG: // if data is a forward gesture
      Serial.println("Forward");
      break;
    case GES_BACKWARD_FLAG: // if data is a backward gesture
      Serial.println("Backward");
      break;
    case GES_CLOCKWISE_FLAG: // if data corresponds to a gesture turn  clockwise
      Serial.println("Clockwise");
      break;
    case GES_COUNT_CLOCKWISE_FLAG:// if data is a gesture turn counterclockwise
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


## Connect actuators and activate devices
After having used **digitalRead()** and **analogRead()** commands to read currents on the input pins of an arduino card, we will now see how to use **digitalWrite()** functions and **analogWrite()** to generate currents on the output pins. Note that the digital pins can be configured as an output or as input using the [**pinMode()**](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/) function.

### Classic led
These leds are the simplest actuators that can be found, they are very inexpensive and exist in a multitude of colors and sizes. We will first focus on monochrome LEDs before talking further about RGBW leds in ribbon.

Two interaction modes are possible with this type of actuator, one can:
- either send a 'HIGH' or 'LOW' bit stream using **digitalWrite()** to blink a led.
- either send an 'analog' current between 0 and 255 using **analogWrite()** to dim.

In both cases the circuit will be the same:

<img src="set_led_blink/set_led.png" width="480" height="360" /><br>

It is worth knowing that the [led](https://en.wikipedia.org/wiki/Light-emitting_diode) is polarized - that means it should be plugged considering the current flow in the component. The small led corresponds to the 'minus' and must be connected to the ground, the longest leg corresponds to the 'plus' and must be connected to a digital output.
Between the ground leg we use a resistance of 220 ohms to protect the led from a possible surge.

#### Blink a led

<img src="assets/set_led_blink.gif" width="480" height="360" /><br>

To flash a led simply use the[**digitalWrite()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/) function. It uses two arguments :
- the first is the number of the pin on which a current must be sent.
- the second is the 'value' of the current: either 'HIGH' or 'LOW'.

```c
void setup() {
  pinMode(3, OUTPUT); // use pin 3 in output mode
}

void loop() {
  digitalWrite(3, HIGH); // send a 'strong' current on pin 3
  delay(500); // wait 500 milliseconds
  digitalWrite(3, LOW); // send a 'weak' current on pin 3
  delay(500); //wait 500 milliseconds
} 
```

#### Pulse a led

<img src="assets/set_led_pulse.gif" width="480" height="360" /><br>

To pulse an LED just use the [**analogWrite()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) function. This function uses two arguments:
- the first is the number of the pin on which a current must be sent.
- the second is the 'value' of the current: between 0 and 255. 0 will correspond to the led being off and 255 to a led lit at the maximum of its brightness.

Note that using[**analogWrite()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) our LED is not connected to an analog pin. Analog pins are just inputs. We must connect our LED on a digital pin, but a [PWM](https://fr.wikipedia.org/wiki/Modulation_de_largeur_d%27impulsion) pin, the list of pwm pins is available in each board documentation.

```c
float t = 0; // a variable to store time

void setup() {
   pinMode(3, OUTPUT); // use pin 3 in output mode
}

void loop() {
  t += 0.025; // we increase the value of the time (we can change the value to make pulse + or - fast)
  double l = ((sin(t) + 1) /2.0)*255; // we calculate a brightness l must be between 0 and 255
  analogWrite(3, l); // turn on the led with calculated brightness.
}
```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Vibrator motor

For the vibrator the logic is exactly that for the led, the assembly is very similar:

<img src="set_vibrator_onoff/set_vibrator.png" width="480" height="360" /><br>

And the code will be similar ...

#### Vibrator motor on off

<img src="assets/set_vibrator_blink.gif" width="480" height="360" /><br>

```c

void setup() {
  pinMode(3, OUTPUT); // use pin 3 in output mode
}

void loop() {
  digitalWrite(3, HIGH); // send a 'strong' current on pin 3
  delay(500); // wait 500 milliseconds
  digitalWrite(3, LOW); // send a 'weak' current on pin 3
  delay(500); // wait 500 milliseconds
} 

```

#### Vibrator on off pulse

<img src="assets/set_vibrator_pulse.gif" width="480" height="360" /><br>

```c
float t = 0; // a variable to store time

void setup() {
   pinMode(3, OUTPUT); // use pin 3 in output mode
}

void loop() {
  t += 0.025; // we increase the value of the time (we can change the value to make pulse + or - fast)
  double l = ((sin(t) + 1) /2.0)*255; // we calculate a brightness l must be between 0 and 255
  analogWrite(3, l); // the led is lit with the calculated brightness.
}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Servomoteurs

We have seen that digital inputs made it possible to measure currents *HIGH* or *LOW*, they also allow two generate these two types of currents as in the case of our ultrasonic distance sensor. Another possibility is to generate a [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) signal : by sending very fast electric pulses which duration varies, one can encode more complex data ​​and thus control the intensity and the color of leds or a motor's speed or rotation direction.

In a general way all the servomotors connect in the same way :

<img src="set_position_servo_classique/set_servo_position.png" width="480" height="360" /><br>

The dark cable is the ground (GND), the red cable is the power supply (5V), the last is generally yellow or orange it is connected to a digital output of an arduino card, but beware of a **PWM** output.

We use the [**Servo**](https://www.arduino.cc/en/Reference/Servo) library which is included by default in the IDE so you have nothing special to install to operate servomotors.

The code is also the same one sends a value using the function [**.write()**](https://www.arduino.cc/en/Reference/ServoWrite), beware those values are not angles :
- 90 for the rest position
- 0 for one of the two behaviors /  exteme position
- 180 for the other

Servo Motors exist in a multitude of sizes, speeds, and power. Depending on their characteristics they may require more or less energy or cost more or less.

#### Classic servo

A conventional servo will accept a parameter as an angle, the maximum and minimum values ​​may vary depending on the engines, as well as the speed that will allow them to reach this angle.

<img src="assets/set_position_servo_classique.gif" width="480" height="270" /><br>

Our code will allow us to simply test the behavior of the servomotor, making it change state every 1.5 seconds.

```c
// include the servo library
#include <Servo.h>

// create an object called myservo that can be manipulated to send
// information to our servo motor
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // specify that we want to use pin 6 as an output
  myservo.attach(6);  // tell our library that a servo is connected to pin 6
}

void loop() {
  myservo.write(90); // put servo in  rest position
  delay(1500); // wait 1.5 sec
  myservo.write(0); // put the servo on the left
  delay(1500);
  myservo.write(90);// put the servo in the rest position
  delay(1500);
  myservo.write(180); // put the servo on the right
  delay(1500);
}
```
You can try changing the values ​​to see what happens.


#### continuous rotation servo

This type of servo will accept as parameter a speed of rotation between 0 and 180.
- 0 will rotate at maximum speed clockwise.
- 180 will rotate it at maximum speed counterclockwise.
- 90 will stop it.

Values ​​around 90 will make it turn more or less quickly in one direction or the other.

<img src="assets/set_rotation_servo_continu.gif" width="480" height="270" /><br>

```c
// include the servo library
#include <Servo.h>

// create an object called myservo that can be manipulated to send
// information to our servo motor
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // specify that we want to use the pin 6 as an output
  myservo.attach(6);  // specify that a servo is connected to the pin 6
}

void loop() {
  myservo.write(90); // put the servo in the rest position
  delay(1500); // wait 1.5 sec
  myservo.write(0); // rotate the servo as fast as possible clockwise
  delay(1500);
  myservo.write(90);// put the servo in the rest position
  delay(1500);
  myservo.write(180); // turn the servo as fast as possible counterclockwise
  delay(1500);
}
```
You can try changing the values ​​to see what happens.


#### Linear servo

The linear servomotor will perform a translation. We specify its position between the parentheses of **write()** .

<img src="assets/set_position_servo_lineaire.gif" width="480" height="270" /><br>

```c
// include the servo library
#include <Servo.h>

// create an object that will be called myservo that can be manipulated to send
// information to our servo motor
Servo myservo;

void setup() {
  pinMode(6, OUTPUT); // specify that we want to use pin 6 as an output
  myservo.attach(6);  // tell our library that a servo is connected to pin 6
}

void loop() {
  myservo.write(90); // center
  delay(1500); // wait 1.5 sec
  myservo.write(0); // on the left
  delay(1500);
  myservo.write(90);//center
  delay(1500);
  myservo.write(180); // on the right
  delay(1500);
}
```
You can try changing the values ​​to see what happens.

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


### Playing with leds (neopixels)

We will directly use LED ribbons. These ribbons feature a series of RGB LEDs, each of which is individually controllable in color and intensity.

They can be cut to the desired length and require only three cables to control them: two for the power supply and one for the data. The assembly scheme will always be the same.

<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

Depending on the number of leds you want to light but also depending on the color or intensity, you will need a certain amount of power. It may sometimes be necessary to use external power supplies - below a dozen of leds an arduino card should be able to power without needing an external power source. A led consumes at most 60mA (lit in white at the maximum intensity). At larger currents, it may be interesting to add a capacitor in parallel on the power supply.

For the software part we will use the Fast-LED library. It must therefore be installed via **the library manager** (Menu *Sketch* -> *Include a library* -> *Manage libraries*).

We will see how to specify the color of each led either with a RGB color or with an HSV color.

The fast-led library gives us a syntax to define the number of LEDs available, the type of led and the control pin used.

Then we can display colors on the LEDs by scanning each led of our ribbon using a [**for() loop**](https://www.arduino.cc/reference/en/language/structure/control-structure/for/).


#### Use RGB color scheme

Here we will create a small animation by varying the red and green components of each led.

<img src="assets/set_neopixels_rgb.gif" width="480" height="270" /><br>

```c 
// include fast-led library
#include <FastLED.h>
#define NUM_LEDS 5 // define the number of leds eg 5

CRGBArray<NUM_LEDS> leds; // define a table of data each entry of the table will represent a led.
float  inc = 0; // a variable that we will use to create an animation (simulate time)

void setup() {
  // we initialize our strip of led on the pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {

  inc +=  0.05; // increase the value of inc
  // we calculate in from inc a value that will oscillate between 0 and 244.
  double green = (sin(inc) + 1)*122; // this value is stored in a variable named "green"
     
  // For i ranging from 0 to 5, we will execute the code between braces,
  // each time it's done we increase the value of i of 1
  for (int i = 0; i < NUM_LEDS; i++) {
    // change the value of the led 'i' of the array named 'leds' giving it a new RGB value
    leds[i] = CRGB(255-green, green, 0);
  }
  FastLED.show(); // we update the LED ribbon
}
```

If you want to give a precise color to each led, you can use direct calls to each led without for loop:

```c
void loop(){
    leds[0] = CRGB(255, 0, 0); //red
    leds[1] = CRGB(0, 255, 0); // green
    leds[2] = CRGB(0, 0, 255); // blue
    leds[3] = CRGB(255, 255, 255); // White
    leds[0] = CRGB(0, 0, 0); // black
    FastLED.show(); // we update the LED ribbon
}

```

#### Use HSV color scheme

The cicuit is the same: 
<img src="assets/set_neopixels_hsb.gif" width="480" height="270" /><br>

The code is almost the same except that we call the **CHSV()** function of the Fast-led library. Even if in most software the hue is represented by a value between 0 and 360 and the saturation and the brightness are represented by values ​​between 0 and 100, in this case each of the three values ​​must be between 0 and 255.


```c
// include the fast-led library
#include <FastLED.h>
#define NUM_LEDS 5 // define the number of leds eg 5

CRGBArray<NUM_LEDS> leds; // define a table of data each entry of the table will represent a led.
float  inc = 0;

void setup() {
  // we initialize our strip of led on the pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
}

void loop() {
    
  // increase the value of inc
  // we calculate according to inc a value that will oscillate between 0 and 244.
  inc +=  0.05;
  double saturation = (sin(inc) + 1)*122; // this value is stored in a variable named "saturation"
  // For i ranging from 0 to 5, we will execute the code between braces,
  // each time we increase the value of i of 1
  for (int i = 0; i < NUM_LEDS; i++) {
    // change the value of the led 'i' of the array named 'leds' giving it a new HSV value
    leds[i] = CHSV(255 - i *50, saturation, 255);
  }
    FastLED.show();// we update the LED ribbon
}
```

we can once again directly call the function **CHSV()**
```c
void loop(){
    leds[0] = CHSV(0, 255, 255); //red
    leds[1] = CHSV(90, 255, 255); // green
    leds[2] = CHSV(180, 255, 255); // blue
    leds[3] = CHSV(255, 0, 255); // White
    leds[0] = CHSV(0, 0, 0); // black
    FastLED.show(); // we update the LED ribbon
}

```

[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>

### Use a 4-digit display

A 4-digit display allows to display numbers and letters (from A to F) on digits (set of 7 segments). There are 4 digits available to display numbers.

<img src="assets/set_four_digit_display.gif" width="480" height="270" /><br>

The component manufacturer's documentation page is available here : http://wiki.seeedstudio.com/Grove-4-Digit_Display/

Cabling is as follows :

<img src="set_four_digit_display/set_four_digit_display.png" width="480" height="270" /><br>

From a software point of view you will need to download the library **TM1637** /**Grove 4-digit display**.

```c
// include the library dedicated to the 4 digit display
#include "TM1637.h"
// define the connection pins for the clock and the data
#define CLK 8 // eg D8
#define DIO 9 // eg D9
TM1637 tm1637(CLK, DIO); //  attach our pins to the object used to manipulate our screen

// define the available characters
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F
// define a variable that we will increase little by little to calculate the time
int num = 0;

void setup() {
  // initialize our screen and specify its brightness
  tm1637.init();
  tm1637.set(BRIGHTEST);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop(){

  // calculate the number to be displayed for each column of the counting table
  // because even if our number is less than 4 values ​​(0 for thousands, hundreds and tens)
  // we want to display the zeros before our value.
  int milles = int((num /1000)%10);
  int cents = int ((num /100)%10);
  int dizaines = int((num/10)%10);
  int unites = int(num%10);
  
  tm1637.display(0, NumTab[milles]); // show the thousands digit on the leftmost segment 
  tm1637.display(1, NumTab[cents]);
  tm1637.display(2, NumTab[dizaines]);
  tm1637.display(3, NumTab[unites]); // display the units digit on the rightmost segment 
    
  delay(10); //  wait a little
  
  num +=1 ; // increase the num value of 1
}
```
Note that here we measure tens of milliseconds: the *delay(10)* makes the program pauses about ten milliseconds before looping.


[^home](https://github.com/b2renger/Introduction_arduino#contents)<br>


## Control an actuator with a sensor

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
