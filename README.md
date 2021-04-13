# Introducere

Criptarea este procesul de ascundere a informației pentru a o face ilizibilă fără cunoștințe speciale. Una dintre cele mai simple metode de criptare este criptarea prin deplasare. Astfel, având un alfabet și o cheie k, definim criptare prin deplasare ca înlocuirea fiecărei litere din textul inițial cu o literă care se află în alfabet la distanță k față de cea înlocuită (alfabetul este circular, dupa z urmează a).

# Cerința problemei

Subpunct a

Dându-se o cheie și un un text criptat (format din litere mari, litere mici și semne de punctuație), se dorește decriptarea acestuia folosind metoda prezentată anterior.

Exemplu: Textul “Fsf fwj rjwj.” cu o cheie de 5 devine “Ana are mere.”.

Subpunct b

După realizarea decriptării de la punctul a), se dorește eliminarea tuturor prefixelor cuvintelor din text. Astfel, având un șir de prefixe introdus de la tastatură, pentru fiecare cuvânt din text căutam prefixul de lungime maximă (dacă există) și îl eliminăm. De asemenea, cuvintele nou formate trebuie să conțină minim 2 caractere (cuvântul “prea” nu va deveni “a” dacă avem “pre” în lista de prefixe).

Exemplu: Cuvântul “interschimbare” devine “schimbare” dacă prefixul “inter” se află în listă. Dacă în listă s-ar afla și prefixul “in”, cuvântul ar fi fost transformat tot în “schimbare” deoarece se ia în calcul prefixul cu lungime mai mare.

Subpunct c

După realizarea modificărilor de la punctul b), se dorește aflarea celui mai frecvent cuvânt din text și numărul de apariții ale acestuia, fără a se face diferența între litere mici și litere mari. În cazul în care avem mai multe cuvinte cu același număr de apariții, se va afișa primul din punct de vedere lexicografic. Cuvântul găsit va fi scris doar cu litere mici.

Exemplu: Textul “Schimbare,Prefacut. nefacut interschimbare REFACUT,,prea” se transformă în “Schimbare,facut. facut schimbare FACUT,,ea” daca avem prefixele “pr re in inter ne p pre”, iar cel mai frecvent cuvânt este “facut”, care apare de 3 ori.

# Mențiuni
-Memoria folosită pentru rezolvarea acestei probleme trebuie alocată dinamic;\
-Caracterele ce apar în text sunt litere mici, litere mari ale alfabetului englez și semne de punctuație: ” ,.;!?-:”; Doar literele își vor schimba valoarea în urma
decriptării, semnele de punctuație rămânând neschimbate;\
-Definim cuvânt o succesiune de litere mici sau mari ale alfabetului englez, separate de unul sau mai multe semne de punctuație;\
-În urma decriptării, literele mici vor rămane mici, iar cele mari tot mari. Ex: “FSF” cu cheie de 5 devine “ANA” și “fsf” tot cu cheie de 5 devine “ana”;\
-Cuvintele pot fi separate de orice semn de punctuație. Ex: textul “Ana n-are mere,pere,prune.” conține 6 cuvinte;\
-Cuvintele pot fi separate, de asemenea, de mai multe semne de punctuație. Ex: textul “Ana ? n-are !., mere” conține 4 cuvinte;\
-Prefixele conțin doar litere mici ale alfabetului englez.\

# Checker local
 Checkerul poate fi rulat folosind comanda “bash checker.sh” pentru a verifica toate testele sau “bash checker.sh numarTest” pentru verificarea corectitudinii unui singur test.

ATENȚIE: Checker-ul, fișierele de input și cele de referință trebuie să se afle în același folder cu sursa. 
