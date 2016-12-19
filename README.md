Object-tracking
Generare de semnale PWM pe baza datelor citite serial. Acest proiect poate fi parte a unor aplicatii ce au la baza detectie de obiecte, urmarire de obiecte in timp real si control de servomotoare.

Aceasta aplicatie cuprinde : 
  - Receptie de date serial , stocare intr-un buffer , utilizarea datelor pentru generare de semnale PWM
  - Functii care genereaza semnale PWM de 50Hz pentru controlul unor servomotoare.
  - Semnalele sunt generate pe baza datelor primite ce reprezinta coordonate in plan ale obiectelor detectate.
  - 2 Taskuri - unul pentru receptie de date si celalalt pentru generare de semnale. 
  
Se foloseste microcontrollerul ATMega128 .

Structura folderelor :  Drivers - modulele ce contin task-urile 
                        Sourcers - fisierele FreeRtos (OS)
                        main.c - initializare task-uri
