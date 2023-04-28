
Politechnika Śląska
Wydział Informatyki, Elektroniki i Informatyki
Programowanie Komputerów
Gra Arkanoid
autor Marta Wichłacz
rok akademicki 2021/2022
kierunek informatyka
rodzaj studiów SSI
semestr 4
Temat
Program jest prostą, zręcznościową grą 2D wzorowaną na Arkanoid.
Rozgrywka polega na manipulowaniu za pomocą strzałek platformą w taki sposób, aby
odbijać piłkę i trafiać kolorowe bloki wiszące w górnej części ekranu. Aby zniszczyć blok
koloru zielonego wystarczy jedno trafienie. Blok żółty po trafieniu zmienia kolor na zielony, a
blok czerwony na żółty – zniszczenie żółtego bloku wymaga w sumie dwóch trafień, a
czerwonego – trzech. Punktowane jest każde trafienie, więc za strącenie czerwonego bloku
otrzymamy w sumie trzy punkty.
Gra może się zakończyć na dwa sposoby: wygraną – gdy wszystkie bloki zostaną
zniszczone, lub przegraną w przypadku utraty piłki.
Analiza tematu
Gra została napisana przy użyciu biblioteki graficznej SFML (Simple and Fast
Multimedia Library). Wybór padł na tę bibliotekę ze względu na brak uprzednich
doświadczeń z tworzeniem programów okienkowych i dużą liczbę materiałów do
samokształcenia w zakresie SFML’a. Prawdopodobnie przy kolejnym podejściu zostałaby
podjęta inna decyzja. Aby uruchomić program z poziomu środowiska Visual Studio należało
odpowiednio skonfigurować projekt:
W programie jest wykorzystywana biblioteka standardowa, w tym algorytm sortujący
z zastosowaniem funkcji porównującej w wyrażeniu lambda, tak aby były porównywane
tylko drugie wartości pary w wektorze.
Klasy zostały dobrane do pewnego stopnia intuicyjnie – rzeczywiste elementy gry
stanowią odrębne klasy np. BlockField, Ball, Paddle. Występują również klasy
odpowiedzialne za poszczególne okna i sterowanie dostępnymi w nich funkcjonalnościami,
np. Menu, Arkanoid, Ranking. Klasa Game jest klasą, która steruje całym programem i
przełączaniem okienek.
Specyfikacja zewnętrzna
Program może ustać uruchomiony zarówno z wiersza poleceń, po podaniu ścieżki do
pliku, jak i poprzez bezpośrednie uruchomienie pliku wykonywalnego z rozszerzeniem .exe
ze względu na brak używania przełączników.
Po uruchomieniu gry wyświetli się menu z opcjami: PLAY, RANKING oraz EXIT. Domyślnie
zaznaczonym polem jest ‘PLAY’. Między polami można się poruszać za pomocą strzałek w
górę oraz w dół. Wybrane pole zatwierdza się klawiszem ‘Enter’.
Zatwierdzenie powoduje następujące akcje:
• PLAY – przejście do okienka, w którym należy wpisać swoje imię lub nick.
• RANKING – przejście do okna, w którym są wyświetlane trzy pierwsze miejsca w
rankingu zawierające nick gracza oraz ilość zdobytych przez niego punktów. Z
tego okna do menu można wyjść poprzez wciśnięcie klawisza Escape na
klawiaturze.
