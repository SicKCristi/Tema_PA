# Checker Tema 1 - 2021
Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului
Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:
```shell
./checker.sh
````
Am lăsat pentru final si fișierul README, incluzând și chestiile inițiale din README.

Din punctul meu de vedere, tema a fost foarte utilă pentru mine. M-a ajutat mult pentru fixarea cunoștințelor mele legate de folosirea listelor, a stivelor și cozilor implementate cu liste, dar și lucrurl cu arborii binari precum BST si AVL. 

M-a forțat ies din spatțiul de confort și să folosesc pentru prima dată să folosesc argumente din linia de comandă și argumente pentru funcția main a fișierul LanParty.c (punctul de plecare al întregului program), dar și cum să folosesc un checker, fiind prima dată când l-am folosit și multe alte lucruri de finețe pe care  m-i le-am însușit realizând cerințele acestei teme.

Legat de implementarea temei mele, consider întotdeauna că se putea mai bine, deși consider că implementarea mea este departe de a fi un naivă sau care să nu se ridice la  standardele pe care încerc să m-i le setez, dar consider că anumite instrucțiuni sau idei puteau fi executate mult mai bine, ceea ce nu o face în opinia mea o tema 100% eficientă, dar care se aproprie destul de mult.

Privind conținutul temei, am realizat toate cele 5 taskuri necesare, doar că taskul 5, specific testelor 13, 14 și 15 nu duce la rezultatul specificat de checker.
	
Pentru a explica funționalitățile extra implementate pentru realizarea completă a temei, va trebui să specificăm acest lucru pentru fiecare task:

	- Pentru taskul 1 nu am folosit alte functii suplimentare pentru realizarea acestuia, doar de funcțiile care se deduceau direct din enunțul problemei, precum adaugarea în stivă, citirea datelor din fișier și alocarea spațiului necesar stringurilor și a nodurilor care alcătuiau stiva de echipe și cea de jucători.

	- Pentru taskul 2 nu am folosit decât funcțiile de ștergere a unui element din stiva de echipe și cea pentru eliberarea memoriei pentru lista de jucători, pe care am modificat-o conform enunțului problemei

	- Pentru taskul 3 nu am folosit alte funcții decât decât cele specificate mai sus, cu excepția celei care adaugă un meci în coadă și șterge coada la finalul fiecărei runde, dar care erau necesare din start, lucru care reiese din enunțul cerinței.

	- Pentru taskul 4 s-a folosit funcții suplimentare înafară de cele de bază pentru crearea, adăugarea unui nod în BST, ci mai exact o funcție care reține stiva cu echipe de finalul taskului 3, dar în ordinea descrescătoare a reprezentării acesteia în BST( practic se adaugă în ordinea crescătoare, ceea ce înseamană parcurgere în iordine) și o funcție care eliberează memoria necesară acestui BST, arborele AVL de la taskul 5 fiind construit de la 0 cu stiva specificată mai sus.

	- Pentru taskul 5 nu s-a folosit funcții suplimentare, toate funcțiile strict necesare pentru realizarea acestui task se deduceau direct din enunțul problemei. Singura execpeție este că la acest task se elibereaza ultimele spații de memorie ocupate de stiva inițială de echipe, informațiile reținute fiind necesare pe parcursul întregului program, de aceea eliberarea acestuia se face atât de târziu ăn program.

Pentru că nu sunt o execpeție, am avut și eu dificutăți în realizarea acestei teme, iar acum o să prezint 4 dintre dificutățile întâmpinate:

	- Alocarea memoriei pentru taskul 1. Da, deși este primul task, și teoretic ar trebui să fie cel mai simplu, am avut destul de multe probleme cu acesta, pentru că aveam un segmentation fault pe care a durat ceva până când am găsit unde era. Inițial am crezut că era o problemă cu funțiile de inserare, dar după testarea individuală a acestora am realizat că ele funcționau corect. După realizarea acestei probleme, totul a mers conform așteptărilor.

	- Caracterul /r de finalul fisierelor de intrare. Practic, din cauza acestui caracter, exista un spațiu pe care nu îl specificam în afișarea pe ecran sau în fișier. În comparație cu prima problemă, acesta a fost soluționată prin funcția care ia toate numele de echipă din stiva de echipe și îl înlocuiește cu '/0', caracterul care trebuia să fie de drept acolo.

	- Realizarea unui blueprint pentru taskul3. Având un enunț destul de lung, cu multe cerințe și folosind foarte multe structuri de date, a trebuit să stau să-mi fac un model despre cum ar trebui să arate rezolvarea în program, dar această problemă a fost doar în implementarea rezolvării, pentru că după totul a mers perfect după punerea în practică a acestui model.

	- Afișarea echipelor de pe nivelul 2 din AVL în fișier. Această problemă a rămas singura problemă nesoluționată din toate problemele, mai mici sau mai mari care au apărut de-a lungul implementării. Funcția pentru inserarea elementelor în AVL este bazată pe funcția prezentată la curs, dar din păcate, afișarea nodurile de pe nivelul 2 nu se realiza, considerând că nu funcția de afișare nu are probleme.

în realizarea acestei teme, am descoperit foarte multe chestii noi și interesante pe care știam până acum:

	- Prima descoperire este diferența dintre specificarea sfârșitului de linie dintre Unix si Windows. În Unix, sfârșitul de linie se specifică doar cu /n, iar în Windows cu /n/r. Deoarece fișierele de intrare au fost create pe Windows, iar tema a fost realizată pe o mașină virtuală cu Linux, caracterul /r nu mai considerat un caracter specific pentru finalul de linie în Linux, și de aceea în afișările de la taskul 3, apărea un sfârșit de linie nespecificat de către mine. Acest lucru a dus la crearea funcției de ștergere a acestui caracter pentru toate numele de echipe din stivă, și de asemenea a reprezentat o informație pe care abia acum am aflat-o.

	- Cum să folosesc argumentele din lina de comandă. Până acum am fost obișnuiți să folosim un IDE care să facă toate lucrile acestea pentru noi. Acum, în Visual Studio Code lucrurile au stat diferit. Acesta seamănă foarte mult cu o linie de comandă, iar pentru construirea corespunzătoare a unui fișier de output pe care să-l compare checkerul, aveam nevoie de 4 argumente din linia de comandă, lucru pe care noi în CodeBlocks niciodată nu l-am făcut.

	- Cum funcționează și cum se lucrează cu un checker. Acum a fost prima dată când a trebuit să lucrez cu un checker, si a durat puțin până am înțeles ce face și cum să îl folosesc, și abia acum înțeleg cât de multă obictivitate poate să aducă la corectarea unui teme și cât timp poate să scutească în corectarea acesteia.


		


		
		



 



