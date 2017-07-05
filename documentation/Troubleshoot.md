Ein paar Überlegungen die ich nachts über hatte:

* Überprüfe mit dem Multimeter (Verbindungstester) jeden Pin vom Pogo-Adapter bis hin zum Kabel das ins Arduino eingesteckt ist. Evtl. gibts irgendwo ein Übertragungsproblem.

* Vom Arduino Board entferne den Atmega Chip (mit einem flachen Schraubenzieher vorsichtig rausheben). Versuche nochmal das Programm hochzuladen (richtiger USB Port, Arduino as ISP, Attiny, 1mhz, etc. alle Einstellungen nochmals prüfen)

* öffne einen osx terminal dann probiere folgendes:

```
cd /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/
```

das sollte klappen und schau mal ob avrdude dir einen output anzeigt

```
./avrdude -v
```

Mit avrdude lädt man die kompilierten hex Files vom Arduino auf den Chip. Das Arduino macht das automatisch. Mit avrdude können wir uns aber auch direkt in den Chip einloggen.

Pogo Pin draufhalten und folgendes im Terminal ausführen lassen:

```
./avrdude -c stk500v1 -P /dev/ttyUSB0 -p t84 -t
```

(Achtung: der Port muss übereinstimmen -> /dev/ttyUSB0. in deinem Fall könnte es auch der Port /dev/ttyACM0 sein bzw. /dev/ttyUSB1. bitte unbedingt überprüfen mit `ls /dev/tty` und dann TABULATOR Taste oder `ls /dev/ttyACM` und dann TABULATOR im Terminal). Der Terminal sollte dir anzeigen welcher Port existiert.

Kann sich avrdude mit dem Chip verbinden? Terminal mode sollte ungefähr so aussehen: http://www.nongnu.org/avrdude/user-manual/avrdude_9.html

Wenn ja, hurray!

Sobald du im Arduino auf Compile klickst wird ein Hex File erstellt. Das passiert aber in einem temp. Folder. Um das hex File zu bekommen, musst du oben im Menü Export
compiled binary anklicken. Wenn du jetzt in deinen Ordner schaust, solltest du ein hex file haben. z.B.

```
TestOutputs.ino.standard.hex
oder
SimpleMorse.ino.standard.hex
```

Jetzt können wir über avrdude direkt das hex File auf den Chip spielen. Dazu brauchen wir aber den absoluten Pfad vom hex File. Bei mir sieht der so aus (einfach vom Finder in den Terminal ziehen):

```
/Users/gordan.savicic/Documents/gordo/PROJEKTA/workshop/2016_2017_HSLU/PCB140JahreHSLU/hsluboard/firmware/SimpleMorse/SimpleMorse.ino.standard.hex
```

Im Terminal musst du nun aber im avrdude Folder sein. Also wieder:

```
cd /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/
```

Jetzt kannst du es flashen. (Achtung: der Port muss übereinstimmen. /dev/ttyUSB0. in deinem Fall könnte es auch der Port /dev/ttyACM0 sein. bitte überprüfen mit `ls /dev/tty` und dann TABULATOR Taste oder `ls /dev/ttyACM` und dann TABULATOR im Terminal).

Copy/paste diese Zeile, achtung pfade ändern

```
stty -F /dev/ttyUSB0 hupcl && avrdude -c stk500v1 -b57600 -P /dev/ttyUSB0 -p t84 -u -U flash:w:/Users/gordan.savicic/Documents/gordo/PROJEKTA/workshop/2016_2017_HSLU/PCB140JahreHSLU/hsluboard/firmware/SimpleMorse/SimpleMorse.ino.standard.hex
```
Pogo-Pin draufhalten. Und Befehl ausführen (ENTER)

Soviel mal von meiner Seite!
