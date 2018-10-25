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
    
* [Connecter des actuateurs et activer des périphériques](https://github.com/b2renger/Introduction_arduino#connecter-des-actuateurs-et-activer-des-p%C3%A9riph%C3%A9riques)<br>
	* [faire tourner servomoteur](https://github.com/b2renger/Introduction_arduino#servomoteurs)<br>
        * [sevomoteur classique](https://github.com/b2renger/Introduction_arduino#servomoteur-classique)<br>
        * [servomoteur à rotation continue](https://github.com/b2renger/Introduction_arduino#servomoteur-%C3%A0-rotatoin-continue)<br>
        * [servomoteur linéaire](https://github.com/b2renger/Introduction_arduino#servomoteur-lin%C3%A9aire)<br>
	* [allumer des leds (neopixels)](https://github.com/b2renger/Introduction_arduino#alumer-des-leds-neopixels)<br>
        * [RGB](https://github.com/b2renger/Introduction_arduino#sp%C3%A9cifier-la-couleur-en-rgb)<br>
        * [HSB](https://github.com/b2renger/Introduction_arduino#sp%C3%A9cifier-la-couleur-en-hsv)<br>
    * [utiliser un afficheur à digits](https://github.com/b2renger/Introduction_arduino#utiliser-un-afficheur-%C3%A0-4-digits)<br>
	
* [Controler un actuateur avec un capteur](https://github.com/b2renger/Introduction_arduino#controler-un-actuateur-avec-un-capteur)<br>
    * [Utiliser la fonction map()]<br>
    * [Potentiomètre vers servo classique](https://github.com/b2renger/Introduction_arduino#potentiom%C3%A8tre-vers-servo-classique)<br>
    * [Flex vers servo continu](https://github.com/b2renger/Introduction_arduino#flex-vers-servo-continu)<br>
    * [FSR vers neopixels HSB](https://github.com/b2renger/Introduction_arduino#fsr-vers-neopixels-hsb)<br>

* [Utiliser des capteurs pour contrôler du code processing](https://github.com/b2renger/Introduction_arduino#utiliser-des-capteurs-pour-contr%C3%B4ler-du-code-processing)<br>
    * [Controler le playback d'une vidéo avec un capteur de distance](https://github.com/b2renger/Introduction_arduino#controler-le-playback-dune-vid%C3%A9o-avec-un-capteur-de-distance)<br>
    * [Controler une animation avec une photoresistance](https://github.com/b2renger/Introduction_arduino#controler-une-animation-avec-une-photoresistance)<br>
    * [Controler des leds neopixels avec la souris](https://github.com/b2renger/Introduction_arduino#controler-des-leds-neopixels-avec-la-souris)<br>

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
<img src="assets/set_position_servo_classique.gif" width="480" height="270" /><br>

#### Servomoteur à rotatoin continue
<img src="assets/set_rotation_servo_continu.gif" width="480" height="270" /><br>

#### Servomoteur linéaire
<img src="assets/set_position_servo_lineaire.gif" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>


### Alumer des leds (neopixels)

<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

Nous allons utiliser la bibliothèque Fast-LED.

#### Spécifier la couleur en RGB

<img src="assets/set_neopixels_rgb.gif" width="480" height="270" /><br>


#### Spécifier la couleur en HSV

<img src="assets/set_neopixels_hsb.gif" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Utiliser un afficheur à 4 digits

<img src="assets/set_four_digit_display.gif" width="480" height="270" /><br>
<img src="set_four_digit_display/set_four_digit_display.png" width="480" height="270" /><br>


[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>


## Controler un actuateur avec un capteur

### Utiliser la fonction map()


[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Potentiomètre vers servo classique

<img src="assets/map_potentiometer_to_servo.gif" width="480" height="270" /><br>
<img src="map_potentiometer_to_servo/map_potentiometer_to_servo.png" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Flex vers servo continu

<img src="assets/map_flex_to_servo_continu.gif" width="480" height="270" /><br>
<img src="map_flex_to_servo_continu/map_flex_to_servo_continu.png" width="480" height="560" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### FSR vers neopixels HSB

<img src="assets/map_fsr_to_neopixels.gif" width="480" height="270" /><br>
<img src="map_fsr_to_neopixels/map_fsr_to_neopixels.png" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

## Utiliser des capteurs pour contrôler du code processing

### Controler le playback d'une vidéo avec un capteur de distance

<img src="assets/serial_distance_to_movie_speed.gif" width="480" height="270" /><br>
<img src="read_from_IRDistance/read_from_irdistance.png" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Controler une animation avec une photoresistance

<img src="assets/serial_photores_to_animation.gif" width="480" height="270" /><br>
<img src="read_from_photores/read_from_photores.png" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>

### Controler des leds neopixels avec la souris

<img src="assets/serial_mouse_to_neopixels.gif" width="480" height="270" /><br>
<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

[^home](https://github.com/b2renger/Introduction_arduino#contenu)<br>