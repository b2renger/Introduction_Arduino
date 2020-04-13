# Introduction Arduino

Code for a creative coding class with arduino for designers. English wip : [here](https://github.com/b2renger/Introduction_Arduino/blob/english/README.md)

[Arduino](https://www.arduino.cc/) est une marque de cartes électroniques open hardware : c'est à dire des cartes dont les schémas sont disponibles librement et gratuitement.

Arduino est un projet qui a commencé en 2003 à l'Interaction Design Institute Ivrea (maintenant intégré à la Domus Academy - un école privé de design basée à Milan en Italie) comme un projet pédagogique pour les étudiants cherchant à permettre à coût réduit et d'une manière la plus simple possible de créer des objets interagissant avec leur environnement par le biais de capteurs et d'actuateurs.

Une carte arduino consiste en une plateforme d'entrées / sorties dirigées par un microcontrolleur pouvant être programmé via le logiciel éponyme. Le projet arduino a été est reste très utilisé dans les domaines du prototypage rapide, lié à la programmation multimédia interactive liée à la création de spectacles ou d'installations artistiques numériques.

Les projets réalisés avec ce type de cartes peuvent ensuite être autonomes, connectés à internet (IOT), ou peuvent communiquer directement avec un ou plusieurs ordinateurs.

Ces cartes disposent d'une multitude de composants d'entrées et de sorties, de cartes d'extensions et d'une communauté très active. Arduino est une marque cela signifie qu'il existe des clones de cartes arduino qui ont des caractéristiques très similaires. Nous utiliserons par abus le terme arduino pour définir toute l'activité de créer des circuit et programmer les cartes.

Il existe différent modèles de cartes comportant plus ou moins d'entrées / sorties, qui nécessitent plus ou moins d'énergie pour fonctionner et dont les processeurs (ou micro-controlleurs) sont plus ou moins rapides. (Mega, Leonardo, Uno etc.)

Ici nous allons nous concentrer sur comment récupérer des valeurs de différents capteurs, comment activer des actuateurs et comment faire communiquer une carte arduino et un programme [processing](https://processing.org/).

Chaque exemple comportera un schéma électrique à réaliser et du code à écrire et téléverser sur une carte. La première partie consiste en un petit inventaire de capteurs, la deuxième présentera quelques actuateurs (moteurs , leds et afficheur à digits), la troisième partie elle consistera à récupérer l'information d'un capteurs pour la transmettre à un actuateur, et finalement la quatrième partie nous amenera à faire communiquer notre ordinateur avec notre carte arduino.

Vous pourrez retrouver l'ensemble des explications ainsi que les code d'exemples prêt à télécharger sur ce dépôt [github](https://github.com/b2renger/Introduction_Arduino/)

## Contenu
* [Introduction](#Introduction)<br>

* [Connecter des capteurs et mesurer des valeurs](#Connecter-des-capteurs-et-mesurer-des-valeurs)<br>

    * [Les broches Digitales et capteurs logiques](#Les-broches-Digitales-et-capteurs-logiques)<br>
        * [Tilt](#Tilt)<br>   
        * [PIR](#PIR)<br>  
        * [Microswitch](#Microswitch)<br>
        * [Bouton](#Bouton)<br>

    * [Les broches analogiques](#Les-broches-analogiques)<br>
        * [Potentiometre](#Potentiometre)<br> 
        * [Microphone](#Microphone)<br>
        * [Photo-resistance](#Photo-resistance)<br>
        * [Capteur piezo](#Capteur-piezo)<br>
        * [Flex](#Flex)<br>    
        * [FSR](#FSR)<br>

    * [Capteurs de distance](#Capteurs-de-distance)<br>
        * [Infra-rouge](#Infra-rouge)<br>
        * [Ultra-son](#Ultra-son)<br>
          * [Ultra-son grove](#Ultra-son-grove)<br>
          * [Ultra-son hc sr04](#Ultra-son-hc-sr04)<br>

    * [Capteurs digitaux et broches SDA-SCL](#Capteurs-digitaux-et-broches-SDA-SCL)<br>
        * [Accelerometre](#Accelerometre)<br>
        * [Gyroscope](#Gyroscope)<br>
        * [Gesture](#Gesture)<br>
    
* [Connecter des actuateurs et agir sur le monde](#Connecter-des-actuateurs-et-agir-sur-le-monde)<br>

  * [Allumer des leds](#Allumer-des-leds)<br>
    * [Faire clignoter des leds](#Faire-clignoter-des-leds)<br>
    * [Faire varier des leds](#Faire-varier-des-leds)<br>

  * [Activer un vibreur](#Activer-un-vibreur)<br>
    * [Vibreur on-off](#Vibreur-on-off)<br>
    * [Vibreur variation](#Vibreur-variation)<br>

  * [Faire tourner un servomoteur](#Faire-tourner-un-servomoteur)<br>
      * [Servomoteur classique](#Servomoteur-classique)<br>
      * [Servomoteur rotation continue](#Servomoteur-rotation-continue)<br>
      * [Servomoteur lineaire](#Servomoteur-lineaire)<br>

  * [Allumer des leds neopixel](#Allumer-des-leds-neopixel)<br>
      * [RGB](#RGB)<br>
      * [HSB](#HSB)<br>
  * [Utiliser un afficheur 7 segments](#Utiliser-un-afficheur-7-segments)<br>
	
* [Controler un actuateur avec un capteur](#Controler-un-actuateur-avec-un-capteur)<br>
    * [Utiliser la fonction map()](#Utiliser-la-fonction-map())<br>
    * [Potentiometre et servo classique](#Potentiometre-et-servo-classique)<br>
    * [Flex et servo continu](#Flex-et-servo-continu)<br>
    * [FSR et neopixels](#FSR-et-neopixels)<br>

* [Utiliser des capteurs pour interagir avec code processing](#Utiliser-des-capteurs-pour-interagir-avec-du-code-processing)<br>
    * [Controller un playback video avec un capteur de distance](#Controller-un-playback-video-avec-un-capteur-de-distance)<br>
    * [Controller une animation avec une photoresistance](#Controller-une-animation-avec-une-photoresistance)<br>
    * [Controller des leds avec la souris](#Controller-des-leds-avec-la-souris)<br>
    * [Enregistrer des mesures dans un fichier sur votre ordinateur](#Enregistrer-des-mesures-dans-un-fichier-sur-votre-ordinateur)<br>


## Introduction

Lorsque l'on dit qu'une carte arduino est une carte d'entrée / sortie cela signifie que cette carte peut mesurer des courants électriques (entrée) ou générer des courants électrique (sortie).

Mesurer des courants permet de brancher des capteurs et de vérifier leur état : par exemple mesurer le courant en sortie d'un capteur de luminosité nous permet d'avoir une estimation de la luminosité ambiante.

Générer des courants permet de brancher des actuateurs et donc de faire tourner un moteur plus ou moins vite ou d'allumer des leds plus ou moins fort. C'est l'écriture de code qui va permettre de prévoir l'interaction et les lien entres nos différents éléments.

Une carte arduino ressemble à ceci :

<img src="assets/carte_arduino_uno.png" width="360" height="480" /><br>

Essayez de répérer sur la partie de gauche les **entrées analogiques** numérotées de **A0** jusqu'à **A5**, sur la droite vous pourrez trouver les **pins digitales** numérotées de 0 à 13.

Remarquez que nous parlons d'*entrées* analogiques et de *pins* digitales. Pour résumer A0 jusqu'à A5 sont des entrées et uniquement des entrées; de plus elles sont *analogiques* ce qui signifie que vous pourront y mesurer des valeurs comprises entre 0 et 1023.

Les *pins* digitales peuvent elles être utilisées soit en tant qu'entrées ou en tant que sorties (cela se précise dans le code que nous écrirons) et ne manipulent que des 0 et des 1 (un signal numérique ou digital) - même si cela n'est pas tout à fait vrai car certaines on un petit tilde **~** représenté avant leur numéro, cela signifie que ces *pins* peuvent générer un signal PWM (pulse width modulation) mais c'est une autre histoire et nous en reparlerons ultérieurement.

Il est important de répérer aussi les pins notées **5V** et **GND** celles-ci correspondent au pins d'alimentation. Chaque composant doit être alimenté en électricité et nous les utiliserons donc systématiquement.

Pour simplifier les choses éviter des connecter des capteurs sur les pins digitales D0 et D1 au début.

Lorsque l'on a pu brancher des composants sur notre carte, nous allons utiliser du code pour mesurer des courants : **lire** sur une entrée **digitale** ou sur en entrée **analogique**, ou **écrire** sur une sortie **digitale**.

Le code s'écrit dans l'IDE (Integrated Development Environment) arduino, que vous pourrez trouver et télécharger à cette adresse : https://www.arduino.cc/en/Main/Software

Il faut prendre la version *Desktop* :

<img src="assets/download_arduino.png" width="480" height="240" /><br>

Un fois téléchargé, installé et ouvert vous devrier vous retrouver devant une fenêtre ressemblant à cela :

<img src="assets/arduino_ide.png" width="600" height="740" /><br>

Nous allons donc taper du texte dans cette page pour programmer notre carte électronique.

Les deux premiers boutons en haut à gauche permettent de **vérifier** et de **téléverser** votre code vers la carte, les boutons suivant servent à créer un nouveau programme, ouvrir un programme ou enregistrer un programme, et le bouton tout à droite sert à ouvrir le **moniteur série** (c'est ici que notre programme pourra écrire des informations pour nous informer sur le bon déroulement de la tâche ou pou observer des valeurs brutes de capteurs).

La zone noire correspond à la **console d'erreurs** : le logiciel nous indiquera ici (et souvent en rouge) lorsqu'il y a des erreurs dans le programme que nous avons écrit, ou des problèmes de communication avec la carte.

Finalement la zone blanche est la zone de code. Vous pouvez y voir deux fonctions déjà tappées **setup()** et **loop()**. Ceci est la structure basique de n'importe quel programme arduino. 

Entre les accolades qui délimitent la fonction **setup()** vous écrirez du code qui ne sera exécuté qu'une seul fois au début de votre programme. Par exemple ouvrir une communication série avec notre ordinateur :

```c
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
```

Et entre les accolades qui délimitent la fonction **loop()** vous écrirez du code qui sera exécuté en boucle une fois le programme démarré. Par exemple imprimmer dans le moniteur série la valeur lue sur l'entrée analogique 0 :

```c
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(0));
}
```
Pensez bien que qu'il faut tapper les instructions exactement comme la carte arduino les attend, la moindre faute de frappe (sur une majuscule, un point virgule ou une parenthèse manquante) fera que votre programme ne fonctionnera pas, car la carte ne sera pas capable de comprendre les instructions qu'elle doit exécuter.

Remarquez qu'il est possible d'écrire des commentaires en langage pour humain : en plaçant **//** devant une ligne celle-ci ne sera pas lue / exécutée par la carte.

Une fois le programme écrit il faut le **téléverser** sur la carte mais avant il faut préciser sur quelle **type de carte** on veut téléverser le programme et dire précisément la carte ou le **port** sur laquelle on veut téléverser - car on pourrait très bien avoir plusieurs cartes connectées à notre ordinateur.

Pour cela il faut aller dans le menu *Outils* puis sélectionner *Arduino / Genuino Uno* pour le **type de carte** et choisir la bonne carte dans le menu **Port** (il faut bien sûr à ce stade que votre carte soit branchée à un port usb de votre ordinateur) :

<img src="assets/arduino_ide_selection_carte.png" width="900" height="640" /><br>

Une fois cela fait vous pouvez **vérifier** votre programme puis le **téléverser**.

Lorsque l'on réalise un circuit notre carte doit être déconnectée de notre ordinateur, au moment où l'on code il est préférable de la garder connectée.

[**home**](#Contenu)<br>


## Connecter des capteurs et mesurer des valeurs 

Cette première partie consiste en un petit inventaire de capteurs. Vous disposerez à chaque fois d'un montage et de code pour lire la valeur du capteurs et l'imprimer dans le moniteur série.

En terme de code nous utiliserons principalement deux fonctions : 
- [**digitalRead()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) permettant de **lire** une valeur d'une entrée **digitale**.
- [**analogRead()**](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) permettant de **lire** une valeur d'une entrée **analogique**.

Plus les commandes liées au moniteur série :    
- [**Serial.begin()**](https://www.arduino.cc/en/Serial/Begin) qui permet d'ouvrir une connexion série via le cable USB (pour rappel le sigle usb signifie Universal Serial Bus) pour récuperer des valeurs dans notre ordinateur.
- [**Serial.println()**](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/) qui permet d'inscrire des valeurs dans le port série.

D'une manière générale le code sera toujours le même et il consistera en :

- ouvrir une connexion série pour pouvoir écrire les valeurs du capteurs sur notre ordinateur.
- lire la valeur reçue depuis une pin précise.
- l'écrire dans le moniteur série.

D'un point de vue électronique, parfois nous allons utiliser des résistances et des fois non. Le principe d'une résistance est de permettre de dissiper un peu le courant qui parcourt notre montage. Il en existe de différentes valeurs de quelques ohms à plusieurs million d'ohms, plus la valeur est grande plus elles vont dissiper le courant car à tension constante : **U = R * I**, il s'agit de la **loi d'ohms**; soit la tension est égale à la résistance fois l'intensité - par conséquent l'intensité est égale à la tension divisée par la résistance.

En fonction du courant requis pour un fonctionnement optimal de nos capteurs, nous deverons choisir une résistance adaptée.

[**home**](#Contenu)<br>

### Les broches Digitales et capteurs logiques

Les entrées digitales sont au nombre de 13. Typiquement une pin digitale ne va mesurer que deux type de courant : soit il y a du courant, soit il n'y en a pas / *HIGH* ou *LOW* / 1 ou 0 / *True* ou *False*.

#### Tilt

Le capteur *tilt* permet de détecter des changement brusques de mouvement ou des changments d'orientation. D'une manière une petite bille va rentrer en contact avec la paroi et ainsi fermer un ciruit et ainsi laisser passer le courant. 

Voici à quoi il ressemble : 

<img src="assets/capteurs/tilt.jpg" width="270" height="270" /><br>

Une patte reliée à la masse l'autre va être relié à du courant, si la bille et le corps du capteur rentrent en contact le courant passe et on peut donc le mesurer; on obtient donc soit un 1 soit un 0 en fonction de l'état du capteur.

Exemple d'utilisation :

<img src="assets/read_from_tilt.gif" width="480" height="270" /><br>


Le circuit à réaliser :

<img src="read_from_tilt/read_from_tilt.png" width="480" height="360" /><br>

Ici nous utilisons un résistance de 10 kilo ohms, pour protéger notre capteur et notre carte : cela nous permet d'abaisser le courant circulant dans nos fils avant de le mesurer. 

Le code est très simple, nous devons : 

- ouvrir une connexion série pour pouvoir écrire les valeurs du capteurs.
- préciser à notre programme que nous utilisons la pin 7 comme une entrée.
- lire la valeur reçue sur la pin 7.
- l'écrire dans le moniteur série.

Les deux premières étapes ne peuvent être effectuées qu'une seule fois à la mise sous tension de la carte : elles iront donc dans le **setup()**; les deux étapes suivante doivent être effectuées en boucle pour toujours actualiser la valeur lue sur le capteur  elles iront donc dans le **loop()**.


```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  pinMode(7, INPUT); // préciser que la pin 7 va être utilisée comme une entrée
}

void loop() {
  int value = digitalRead(7); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>

#### PIR

Le capteur [*PIR*](https://en.wikipedia.org/wiki/Passive_infrared_sensor) est un capteur de Présence à Infra Rouge, il permet de détecter la présence de quelque'un avec un champ de vision qui lui est propre. Ce sont typiquement des capteurs dans tous les lieux publiques dont les lumières s'allument automatiquement.

Ces capteurs renvoient un 1 pendant un temps déterminé (ici 3 secondes) lorsqu'ils détectent une présence et 0 sinon. 

<img src="assets/read_from_pir.gif" width="480" height="270" /><br>

Ici au lieu d'ouvir le **moniteur série**, le résultat est affiché dans le **traceur série** disponible via le menu *Outils* -> *Traceur série*.

Le *PIR* est souvent accompagné d'un petit circuit imprimmé et il n'est donc pas nécessaire d'ajouter de résistance car cela a souvent déjà été fait sur la carte accompagnant le capteur.

<img src="read_from_PIR/read_from_pir.png" width="480" height="360" /><br>

Le code est identique au code précédent si nous avons bien aussi branché le capteur *PIR* sur l'entrée 7 : 

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  pinMode(7, INPUT); // préciser que la pin 7 va être utilisée comme une entrée
}

void loop() {
  int value = digitalRead(7); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>

#### Microswitch

Le microswitch est de la même famille que les interupteurs ou les boutons. Lorsque l'on appuie dessus le circuit est fermé, on peut alors mesurer un 1 - sinon le circuit est ouvert et il n'y a pas de courant qui passe on mesure alors un 0.

<img src="assets/read_from_microswitch.gif" width="480" height="270" /><br>

<img src="read_from_microswitch/read_from_microswitch.png" width="480" height="360" /><br>

Encore une fois le code est identique sauf que notre composant est branché pour sur l'entrée digitale 2
```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  pinMode(2, INPUT); // préciser que la pin 2 va être utilisée comme une entrée
}

void loop() {
  int value = digitalRead(2); // lire la valeur sur la pin 2 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>

#### Bouton

Les boutons peuvent apparaitrent aux premiers abords comme le composant le plus simple à utiliser, mais ce n'est pas réellement le cas - il est conseillé de commencer par utiliser le microswitch avant de passer au bouton. Le montage peut s'avérer compliqué (surtout lorsque l'on souhaite en avoir plusieurs) et le code n'est pas forcément le plus simple - nous sommes habitués naturellement à avoir différents types d'interactions avec un bouton qui demandent parfois un peu d'expertise.

Les boutons existent de différentes tailles et de différentes formes, ils peuvent avoir 2, 3 ou 4 pattes mais le principe est toujours le même : lorsque l'on appuie sur le bouton, le circuit se ferme et donc le courant peut passer. En mesurant ce courant sur une broche digitale on obtient soit un 0 (circuit ouvert = pas de courant) ou un 1 (circuit fermé = le courant passe). Il est possible d'obtenir des comportement plus complexes que cette simple lecture et de "reconnaitre" des doubles clicks, appuis longs etc. à l'aide d'une bibliothèque.

<img src="assets/differents_boutons.jpg" width="480" height="360" /><br>

Le bouton d'arcade dispose de 3 broches, le petit bouton en bas à droite de 4 et le bouton en bas à gauche dispose de 3 broches aussi (il s'agit d'un bouton capacitif). 

Le circuit électronique est sensiblement le même pour tous les boutons : il est préférable de faire un montage en branchant le bouton avec 3 fils : 2 pour l'alimentation (noir et rouge) avec une résistance de 10kohms sur la masse, et un fil (jaune) pour la lecture de la valeur. Le bouton capacitif grove est déjà monté sur une petite carte disposant d'une résistance intégrée.

[**home**](#Contenu)<br>

#### Circuits

##### Le bouton capacitif

<img src="read_from_button/read_from_button_grove.png" width="480" height="360" /><br>

##### Le bouton "classique"

<img src="read_from_button/read_from_button_classic.png" width="480" height="360" /><br>

##### Le bouton d'arcade

<img src="read_from_button/read_from_button_arcade.png" width="480" height="360" /><br>


#### Code
Contrairement aux composants précédents il y aura deux exemples de code pour deux comportements distincts. 
- Le premier se contentera de lire les données sur la broche 2. La valeur lue vaudra donc 0 si le bouton n'est pas appuyé et 1 s'il l'est.
- Le second manipulera une variable afin de la faire changer d'état. Ainsi à chaque fois que nous cliquerons sur le bouton (cela signifie ici appuyer et relacher), une variable changera d'état pour valoir soit 0 soit 1.

<img src="assets/read_from_buttons.gif" width="480" height="360" /><br>

#### Lire la valeur d'un bouton

```c
void setup() {
  Serial.begin(9600); // ouvrir la connection série
  pinMode(2, INPUT); // préciser que la pin 2 va être utilisée comme une entrée
}

void loop() {
  int value = digitalRead(2); // lire la valeur sur la pin 2 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>


#### Utiliser le click pour changer un état
Le code ici est un peu plus complexe : il fait appel à une fonction écrite sur mesure qui permet de changer l'état d'une variable en fonction du click et de la valeur précédente de la variable : il s'agit de la fonction définie en bas appelée **button_change()**.  Cette fonction attend 3 paramètres :
- la broche sur laquelle le bouton est branché.
- une variable booléenne (vrai ou faux) permettant de stocker l'état actuel du bouton.
- une variable booléenne permettant de stocker l'état précédent du bouton.


```c
bool b1pval = false; // valeur prédente du bouton
bool b1val = false; // valeur actuelle du bouton

void setup() {
  Serial.begin(9600); // ouvrir la connection série
  pinMode(2, INPUT); // préciser que la pin 2 va être utilisée comme une entrée
}

void loop() {
  // appeler la fonction sur la pin 2
  // avec comme valeur précédente du bouton la variable b1pval
  // et comme valeur courante du bouton la variable b1val
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
Dans ce code vous pouvez remarquer l'apparition des caractères * et & qui sont propres au langages de la famille C et qui sont utilisés dans la manipulation des pointeurs.

C'est une notion qui peut s'avérer complexe à comprendre, mais pour simplifier cela signifie que nous pouvons manipuler directement les espaces mémoire d'un ordinateur ou d'une carte électronique. Ici cela est utile pour pouvoir manipuler des variables dynamique à l'intérieur d'une fonction en passant comme paramètre l'espace mémoire à manipuler.

Pour en savoir plus :
- https://www.arduino.cc/reference/en/language/structure/pointer-access-operators/reference/

- https://www.arduino.cc/reference/en/language/structure/pointer-access-operators/dereference/

- https://en.wikipedia.org/wiki/Pointer_%28computer_programming%29

Il existe aussi des bibliothèques pour utiliser les boutons. Vous pouvez avoir accès au gestionnaire de bibliothèques d'arduino en cliquant sur le menu : *Croquis* -> *Inclure une bibliothèque* -> *Gérer les bibliothèques*.
Vous pouvez rechercher deux bibliothèques :
- EasyButton
- OneButton
Une fois installées, des exemples d'utilisation seront disponibles dans le menu : *Fichier* -> *Exemples*


[**home**](#Contenu)<br>

### Entrées Analogiques

Les entrées analogiques et capteurs analogiques contrairement aux entrée digitale et aux capteurs logiques vont elles nous fournir une plage de valeurs, ces valeurs seront comprises entre **0** et **1024**.

#### Potentiomètre 

Le [*potentionmètre*](https://fr.wikipedia.org/wiki/Potentiom%C3%A8tre) est le grand classique de l'électronique : en fonction de sa position, sa résistance interne varier ce qui va permettre de mesurer un courant plus ou moins fort et encodé entre 0 et 1024.

<img src="assets/read_from_pot.gif" width="480" height="270" /><br>

Le potentiomètre dispose de 3 pattes : les deux aux extrémités sont dédiées à son alimentation (une reliée à **GND** l'autre au **5V**, la patte centrale porte le signal que nous souhaitons lire et sera donc reliée à une **entrée analogique**.

<img src="read_from_potentiometer/read_from_pot.png" width="480" height="360" /><br>

Le code est très similaire au code des capteurs logiques excepté que les pins analogiques sont forcément des entrées et il n'est donc pas nécessaire d'en préciser l'usage avec **pinMode()** et que nous lisons sur une entrée analogique en utilisant **analogRead()** à la place **digitaleRead()** :

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```
[**home**](#Contenu)<br>

#### Micro

Les micro le plus souvent utilisé en électronique sont des [microphones électrostatiques](https://fr.wikipedia.org/wiki/Microphone#Microphone_%C3%A9lectrostatique) dans notre cas le micro est déjà monté sur un ciruit imprimé, nous n'avons donc pas grand choses à ajouter et nous allons pouvoir récupérer une valeur entre 0 et 1023 représentant le niveau sonore. Dans ce cas de figure nous ne pourrons pas enregistrer un son pour le rejouer par la suite, le but est uniquement de mesurer le niveau sonore.

Il existe une multitude de micro certains possèdent des molettes de réglage pour calibrer leur sensibilité.

<img src="assets/read_from_grove_mic.gif" width="480" height="270" /><br>

Nous n'utiliserons que 3 des 4 broches du connecteur : deux pour l'alimentation et la troisième pour lire les données analogiques. Le wiki du fabricant nous précise les connexions disponnibles sur la broche : http://wiki.seeedstudio.com/Grove-Sound_Sensor/

<img src="read_from_grove_mic/read_from_grove_mic.png" width="480" height="360" /><br>

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>

#### Photo-résistance

La [*photorésistance*](https://fr.wikipedia.org/wiki/Photor%C3%A9sistance) fait varier sa résistance en fonction de la luminosité qu'elle reçoit. Il en existe de toutes tailles et de toutes sensibilités.

<img src="assets/read_from_photores.gif" width="480" height="270" /><br>

Pour protéger la lecture du courant sur notre entrée analogique nous allons une résistance de 10 kilo ohms. Nous retrouvons un montage assez similaire à celui d'un capteur logique tilt.

<img src="read_from_photores/read_from_photores.png" width="480" height="360" /><br>

Nous lisons le signal sur l'entrée analogique A0 : 

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```


[**home**](#Contenu)<br>

#### Capteur Piezo

Le capteur *piezoélectrique* fait appel au principe de [*piezoélectricité](https://fr.wikipedia.org/wiki/Pi%C3%A9zo%C3%A9lectricit%C3%A9) qui fait en sorte que certains matériaux peuvent se déformer quand ils sont soumis à un courant électrique ou au contraire qu'ils puissent aussi générer de l'électricité quand ils sont déformés.

On peut donc s'en servir comme capteur de vibrations soit comme micro-contact, ou comme petit haut-parleur permettant de vibrer à des fréquences données (et donc aussi agir en tant qu'actuateur !)

Ici nous allons nous contenter de détecter des vibrations et d'en mesurer l'importance.

<img src="assets/read_from_piezo.gif" width="480" height="270" /><br>

Pour protéger notre entrée mais aussi parce que par rapport à une résistance de 10kOhms elle nous permettra d'avoir de meilleures valeurs en sortie, nous allons utiliser un résistance de 100kOhms.

<img src="read_from_piezo/read_from_piezo.png" width="480" height="360" /><br>

Le code lui reste le même tant que notre capteur est sur la même entrée.
```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```


[**home**](#Contenu)<br>
#### FSR 

Le *FSR* est un capteur de force : il va convertir le poids appliqué sur sa surface en un courant électrique mesurable.

<img src="assets/read_from_fsr.gif" width="480" height="270" /><br>

On retouve le même type de schéma que pour le capteur *tilt* ou que pour le *piezo* ou encore la *photorésistance*. Ici il est monté avec une résistance de 47 kOhms, mais vous pouvez essayer d'ajuster cette valeur pour affiner la précision utile.

<img src="read_from_FSR/read_from_FSR.png" width="480" height="360" /><br>


```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```
[**home**](#Contenu)<br>

#### Flex

Le *flex sensor* va convertir la courbure qu'il prend en valeur comprises entre 0 et 1023. Il faut noter que soumis à aucune contrainte la valeur lue doit être de l'ordre de 511, cela signifie que notre capteur peut détecter une torsion dans les deux sens.

<img src="assets/read_from_flex.gif" width="480" height="270" /><br>

Ici il est monté avec une résistance de 47 kOhms, mais vous pouvez essayer d'ajuster cette valeur pour affiner la précision utile.

<img src="read_from_flex/read_from_Flex.png" width="480" height="480" /><br>

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>


### Capteurs de distance

Il existe plusieurs méthodes pour calculer des distances : infra-rouge, ultra-son, laser. Ici nous allons nous intéresser aux deux premières technologies.

#### Infra-rouge

Le capteur infra-rouge va permettre avec un système de lentilles et d'équations trigonométrique d'estimer une distance. Le [modèle que nous utilisons](https://www.gotronic.fr/art-capteur-de-mesure-sharp-gp2y0a21yk0f-11539.htm) permet d'obtenir un estimation de la distance pour des distances comprises entre 10 et 80 cm et lire le résultat sur une entrée analogique.

<img src="assets/read_from_irdistance.gif" width="480" height="270" /><br>

<img src="read_from_IRDistance/read_from_irdistance.png" width="480" height="360" /><br>

```c
void setup() {
  Serial.begin(9600); // ouvrir la connexion série
  
}

void loop() {
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
}
```

[**home**](#Contenu)<br>


#### Ultra-son

Il existe différents types de capteurs à ultra-son pour mesurer les distances qui est un peu plus précis et permet d'avoir une portée plus importante (jusqu'à quelques mètres)
- le classique [HC-SR04](https://www.gotronic.fr/art-module-de-detection-us-hc-sr04-20912.htm) qui nécessite un branchement à 4 fils.
- le [module grove](https://www.gotronic.fr/art-telemetre-a-ultrasons-grove-101020010-18976.htm) qui dispose de la connectique grove est d'une bibliothèque associée. Il est donc relativement plus simple à utiliser.

Le principe de mesure de ces deux capteurs est le même et les résultats obtenus sont donc très similaires :
<img src="assets/read_from_ultrasonic_distance.gif" width="480" height="270" /><br>


#### Ultra-son-grove

[*module grove*](https://www.gotronic.fr/art-telemetre-a-ultrasons-grove-101020010-18976.htm)

Le circuit ressemble à un circuit classique avec les composants grove :

<img src="read_from_UltraSonic-Distance-grove/read_from_UltraSonic-Distance-grove.png" width="480" height="480" /><br>

Le code nécessite d'installer une bibliothèque. Vous pouvez avoir accès au gestionnaire de bibliothèques d'arduino en cliquant sur le menu : *Croquis* -> *Inclure une bibliothèque* -> *Gérer les bibliothèques*. Il faut alors rechercher et installer la bibliothèque **Grove Ultrasonic ranger**.

Cette bibliothèque va faire abstraction de toute la procédure qui est décrite plus bas pour le Hc-sr04 et nous permettre donc de manipuler un code minimaliste ressemblant beaucoup à ce que nous avons déjà vu jusqu'à présent.

```c
#include "Ultrasonic.h" // importer la bibliothèque
Ultrasonic ultrasonic(2); // la broche "sig" du capteur est branchée sur "D2" de l'arduino

void setup() {
  Serial.begin(9600);
}

void loop() {
  long RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // mesurer la distance en cm
  Serial.println(RangeInCentimeters);//0~400cm
  delay(100); // attendre un peu entre deux mesures.
}
```

[**home**](#Contenu)<br>


#### Ultra-son Hc sr04

[*HC-SR04*](https://www.gotronic.fr/art-module-de-detection-us-hc-sr04-20912.htm) 

Le branchement est un peu différent de ce que nous avons vu jusqu'à présent. Deux pattes vont servir à l'alimentation **GND** et **5V** ou **VCC**.

Les deux suivantes **trig** et **echo** aux entrées digitales 11 et 10 respectivement.

<img src="read_from_UltraSonic_Distance/read_from_ultrasonic_distance.png" width="480" height="360" /><br>

Cela est du au fonctionnement intrinsèque du capteur. Nous allons en fait générer un courant sur la patte **trig** et mesurer un courant sur la patte **echo** : nous allons émettre des ultra-sons et écouter leur écho et en fonction du temps écoulé entre l'émission et la réception de l'écho nous pourrons déterminer une distance (car nous connaissons la vitesse du son).

Le code s'en ressent car il sera nettement plus complexe. En effet il nous faut :

- initialiser nos pin 11 et 10 respectivement comme une entrée et une sortie. [**pinMode()**](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/)
- émettre un courant / signal sur la pin 11. [**digitalWrite()**](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)
- mesurer un écho sur la pin 10. [**pulseIn()**](https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/)
- transformer une valeur de durée en distance.
- imprimmer cette valeur dans la console.

En lisant la documentation de **pulseIn()**, on se rendra compte que notre signal émit sur la pin de trigger doit d'ailleurs suivre une forme particulière.

Nous devrons donc aussi utiliser les fonctions :

- [**delay()**](https://www.arduino.cc/reference/en/language/functions/time/delay/)
- et [**delayMicroseconds()**](https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/)

qui permettent de stopper le fil d'éxecution de notre programme pour un instant déterminé et donc de créer des temporisations.

```c

// pour nous en souvenir nous allons utiliser des variables pour stocker les numéros des pins utilisées
int trigPin = 11;    // Trigger
int echoPin = 10;    // Echo

void setup() {
  Serial.begin (9600);
  // nous précisons que la pin 11 est une sortie (émission d'ultra-sons)
  pinMode(trigPin, OUTPUT); // trigPin est remplacé par sa valeur
  // nous précisons que la pin 10 est une entrée (réception de l'écho)
  pinMode(echoPin, INPUT);
}

void loop() {
  // On envoit un signal écrivant sur la pin de trigger (11)
  // En alternant les valeurs de courant LOW et HIGH et de cours délais
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10); // forcer le programme à rester dans son état précédent(LOW) pendant 10 micro secondes
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // forcer le programme à rester dans son état précédent(HIGH) pendant 10 micro secondes
  digitalWrite(trigPin, LOW);
    
  // récuperer la distance en mesurant les pics en courant HIGH sur la pin d'écho    
  long duration = pulseIn(echoPin, HIGH);
  // Convertir la durée en cm
  long cm = (duration/2) / 29.1;     
    
  // imprimer le réulstat
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
    
  // attendre un peu avant de recommencer l'opération
  delay(250);
}
```
[**home**](#Contenu)<br>

### Capteurs digitaux et broches SDA-SCL

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

[**home**](#Contenu)<br>


#### Accelerometre

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

[**home**](#Contenu)<br>

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

[**home**](#Contenu)<br>

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
[**home**](#Contenu)<br>

## Connecter des actuateurs et agir sur le monde
Après avoir utilisé les commandes **digitalRead()** et **analogRead()** pour lire des courants sur les broches d'entrée d'une carte arduino, nous allons maintenant voir comment utiliser les fonction **digitalWrite()** et **analogWrite()** pour générer des courants sur les broches de sortie. A noter que les broches digitales peuvent être configurées en tant que sortie ou en tant qu'entrée à l'aide de la fonction [**pinMode()**](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/).

[**home**](#Contenu)<br>

### Allumer des leds
Ces leds sont les actuateurs les plus simples que l'on puisse trouver, elles sont très peu chères et existent dans une multitude de couleurs et de tailles. Nous allons nous concentrer tout d'abord sur des leds monochromes avant de parler plus loin des leds RGBW en ruban.

Deux modes d'interactions sont possibles avec ce type d'actuateur, on peut :
- soit envoyer un courant binaire 'HIGH' ou 'LOW' à l'aide de **digitalWrite()** pour faire clignoter une led.
- soit envoyer un courant 'analogique' entre 0 et 255 à l'aide de **analogWrite()** pour réaliser une effet de gradation de la lumière.

Dans les deux cas le circuit sera le même :

<img src="set_led_blink/set_led.png" width="480" height="360" /><br>

Il est important de savoir que la [led](https://fr.wikipedia.org/wiki/Diode_%C3%A9lectroluminescente) simple est un composant polarisé - c'est à dire qu'il a un sens. La petite patte correspond au moins et doit donc être reliée à la masse, la patte la plus longue correspond au plus et doit être reliée à une sortie digitale.
Entre la masse et la patte moins de la led on insère une résistance de 220 ohms afin de protéger la led d'une éventuelle surtension qui risquerait de la griller.

[**home**](#Contenu)<br>

#### Faire clignoter des leds

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
[**home**](#Contenu)<br>

#### Faire varier des leds

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

[**home**](#Contenu)<br>

### Activer un vibreur

Pour le vibreur la logique est exactement que pour la led, le montage est très similaire :

<img src="set_vibrator_onoff/set_vibrator.png" width="480" height="360" /><br>

Et le code sera aussi similaire ...

#### Vibreur on-off

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
[**home**](#Contenu)<br>


#### Vibreur variation

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

[**home**](#Contenu)<br>


### Faire tourner un ervomoteurs

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

[**home**](#Contenu)<br>

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

[**home**](#Contenu)<br>


#### Servomoteur rotation continue

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

[**home**](#Contenu)<br>


#### Servomoteur lineaire

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

[**home**](#Contenu)<br>


### Allumer des leds neopixel

Nous allons utiliser directement des rubans de leds. Ces rubans présentent des séries de leds RGB dont chacune est contrôllable individuellement en couleur et en intensité.

Ils peuvent être découpés à la longueur souhaités et ne nécessitent que trois cables pour les contrôller : deux pour l'alimentation et un pour la donnée. Le schéma de montage sera toujours le même.

<img src="set_neopixel_rgb/set_neopixels.png" width="480" height="270" /><br>

En fonction du nombre de leds que vous voulez allumer mais aussi en fonction de la couleur ou de l'intensité, il vous faudra une puissance différente. Il peut parfois être nécessaire de faire appel à des alimentations externes - en dessous d'une dizaine de led par entrée une carte arduino devrait pouvoir alimenter sans recours à une source d'énergie externe. Une led consomera au maximum 60mA (allumée en blanc à l'intensité maximale). A des courants plus importants, il pourra être intéressant d'ajouter un condensateur en parallèle sur l'alimentation.

Pour la partie logicielle nous allons utiliser la bibliothèque Fast-LED. Il faut donc l'installer via **le gestionnaire de bibliothèques** (Menu *Croquis* -> *Inclure une bibliothèque* -> *Gérer les bibliothèques*).

Nous allons voir comment spécifier la couleur de chaque led soit avec une couleur RGB soit avec une couleur HSV.

La bibliothèque fast-led nous offre une syntaxe permettant de définir le nombre de led dont on dispose, le type de led et la pin de contrôle utilisée.

Ensuite on peut afficher des couleurs sur les leds en parcourant chaque led de notre ruban à l'aide d'une [**boucle for()**](https://www.arduino.cc/reference/en/language/structure/control-structure/for/).

[**home**](#Contenu)<br>


#### RGB

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
[**home**](#Contenu)<br>

#### HSB

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

[**home**](#Contenu)<br>

### Utiliser un afficheur 7 segments

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


[**home**](#Contenu)<br>


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

[**home**](#Contenu)<br>

### Potentiometre et servo classique

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

[**home**](#Contenu)<br>

### Flex et servo continu

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

[**home**](#Contenu)<br>

### FSR et neopixels

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

[**home**](#Contenu)<br>

## Utiliser des capteurs pour interagir avec du code processing

Dans cette partie nous allons nous concenter sur l'utilisation du port série et nous allons depuis un programme arduino écrire des valeurs de capteurs dans un port série que nous pourrons alors récupérer dans un programme processing.

Nous pourrons faire de même dans l'autre sens : c'est à dire envoyer des informations de processing vers arduino.

Pour info USB signifie Universal Serial Bus, le port série est donc bien le port usb on programme donc une manière de faire transiter d'un appareil à l'autre des information via une connexion usb.

[**home**](#Contenu)<br>

### Controller un playback video avec un capteur de distance

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

[**home**](#Contenu)<br>


### Controller une animation avec une photoresistance

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
[**home**](#Contenu)<br>


### Controller des leds avec la souris

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

[**home**](#Contenu)<br>


### Enregistrer des mesures dans un fichier sur votre ordinateur

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

[**home**](#Contenu)<br>
