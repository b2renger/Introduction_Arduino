# Introduction Arduino

Code for a creative coding class with arduino for designers.



## CONTENU

* [Connecter des capteurs et récupérer les valeurs](https://github.com/b2renger/Introduction_arduino#connecter-des-capteurs-et-r%C3%A9cup%C3%A9rer-les-valeurs)<br>
    * [Potentiomètre](https://github.com/b2renger/Introduction_arduino#potentiom%C3%A8tre)<br> 
    * [Micro](https://github.com/b2renger/Introduction_arduino#micro)<br>
    * [Photo-résistance](https://github.com/b2renger/Introduction_arduino#photo-r%C3%A9sistance)<br>
    * [Tilt](https://github.com/b2renger/Introduction_arduino#tilt)<br>
    * [FSR](https://github.com/b2renger/Introduction_arduino#fsr)<br> 
    * [Flex](https://github.com/b2renger/Introduction_arduino#flex)<br>
    * [PIR](https://github.com/b2renger/Introduction_arduino#pir)<br>
    * [Capteur de distance](https://github.com/b2renger/Introduction_arduino#capteur-de-distance)<br>
        * [Infra-rouge](https://github.com/b2renger/Introduction_arduino#infra-rouge)<br>
        * [Ultra-son](https://github.com/b2renger/Introduction_arduino#ultra-son)<br>
    * [Microswitch](https://github.com/b2renger/Introduction_arduino#microswitch)<br>
    * [Accéléromètre](https://github.com/b2renger/Introduction_arduino#acc%C3%A9l%C3%A9rom%C3%A8tre)<br>
    * [Gyroscope](https://github.com/b2renger/Introduction_arduino#gyroscope)<br>
    
* [Connecter des actuateurs et activer des périphériques]()<br>
	* [faire tourner servomoteur]<br>
        * [sevomoteur classique]<br>
        * [servomoteur à rotation continue]<br>
        * [servomoteur linéaire]<br>
	* [allumer des leds (neopixels)]<br>
        * [RGB]<br>
        * [HSB]<br>
    * [utiliser un afficheur à digits]<br>
	* [produire du son avec un buzzer]<br>
    * [produire du son en lisant un mp3]<br>

* [Controler un actuateur avec un capteur]()<br>
    * [Utiliser la fonction map()]<br>
    * [Microswitch vers servo classique]<br>
    * [Micro vers servo continu]<br>
    * [Gyro ver neopixels RGB]<br>
    * [Flex vers neopixels HSB]<br>
    * [Distance vers buzzer]<br>
	

## Connecter des capteurs et récupérer les valeurs

### Potentiomètre 
<img src="assets/read_from_pot.gif" width="480" height="270" /><br>
<img src="read_from_potentiometer/read_from_pot.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Micro
<img src="assets/read_from_grove_mic.gif" width="480" height="270" /><br>
<img src="read_from_grove_mic/read_from_grove_mic.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Photo-résistance
<img src="assets/read_from_photores.gif" width="480" height="270" /><br>
<img src="read_from_photores/read_from_photores.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Tilt
<img src="assets/read_from_tilt.gif" width="480" height="270" /><br>
<img src="read_from_tilt/read_from_tilt.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### FSR 
<img src="assets/read_from_fsr.gif" width="480" height="270" /><br>
<img src="read_from_FSR/read_from_FSR.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Flex
<img src="assets/read_from_flex.gif" width="480" height="270" /><br>
<img src="read_from_flex/read_from_Flex.png" width="480" height="480" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### PIR
<img src="assets/read_from_pir.gif" width="480" height="270" /><br>
<img src="read_from_PIR/read_from_pir.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Capteur de distance

#### Infra-rouge
<img src="assets/read_from_irdistance.gif" width="480" height="270" /><br>
<img src="read_from_IRDistance/read_from_irdistance.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

#### Ultra-son
<img src="assets/read_from_ultrasonic_distance.gif" width="480" height="270" /><br>
<img src="read_from_UltraSonic_Distance/read_from_ultrasonic_distance.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Microswitch
<img src="assets/read_from_microswitch.gif" width="480" height="270" /><br>
<img src="read_from_microswitch/read_from_microswitch.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Accéléromètre
<img src="assets/read_fom_accelerometer.gif" width="480" height="270" /><br>
<img src="read_from_accelerometer/read_from_3axisAccelerometer.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Gyroscope
<img src="assets/read_from_gyroscope.gif" width="480" height="270" /><br>
<img src="read_from_gyroscope/read_from_3axisGyro.png" width="480" height="360" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

## Connecter des actuateurs et activer des périphériques

### Servomoteurs
D'une manière générale tous les servomoteurs se branchent de le même façon :

<img src="set_position_servo_classique/set_servo_position.png" width="480" height="360" /><br>

Le code est aussi le même on envoit une valeur :
- 90 pour la position de repos
- 0 pour un des deux comportements / position extême
- 180 pour l'autre

#### Servomoteur classique
<img src="assets/set_servo_position.gif" width="480" height="270" /><br>

#### Servomoteur à rotatoin continue
<img src="assets/set_servo_rotation.gif" width="480" height="270" /><br>

#### Servomoteur linéaire
<img src="assets/set_servo_linear_position.gif" width="480" height="270" /><br>


[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

