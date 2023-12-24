# Quatum-Tic-Tac-Toe

## Krótki opis szkieletu aplikacji
Mój szkielet apliakcji opiera sie na dwóch oddzielnie działajcych programach.
Jeden to frontend napisany w JS i w react'cie, udostępniony w formie serwera na localhost:3000.
Druga część tego projektu to backend napisany w C++ w formie API z użyciem biblioteki restbed z którym łączy się frontendowy serwer.

Aktualnie system pozwala:
- stworzyć nową grę
- wczytać zawartość gry
- wykonać ruch w grze 

UWAGI:
- Ruchy nie są sprawdzane czy są prawidłowe oraz nie jest w żaden sposób walidowany stan planszy. 
- Nie ma algorytmu szukającego cykli, więc jedynie można dodać stan splątany (wykonując ruch), daltego też nie ma sprawdzania czy jakiś gracz nie zwyciężył
- Nie ma sztucznego gracza.
- Nie ma obsługi większości wyjątków i sytuacji poza standardowymi.
- Struktura części API jest jeszcze do przemodelowania.
- Projekt ma trochę niespójności w postaci formatu danych itd.

Szkielet aplikacji jest bardzo wstępnym projektem gdzie wiele rzeczy jest do poprawienia.
Podstawowym moim celem było napisanie aplikacji, którą będzie miała już nakreśloną swoją architekture i większe decyzje projektowe za sobą, aby móc się skupić w późniejszej części jedynie na impelementacji.

Jestem świadomy braku testów jednostkwoych. Niestety nie zdążyłem ich zrobić już w sensownym terminie. Postaram sie je przygotować do ostatecznego projektu.


*Użyłem proxy aby ominąć zabezpieczenie CORS czyli łącząc się z serwerem na porcie 3000, dostaniemy również odpowiedź od serwera na porcie 8080.

## Requirements
### Front-End:
JavaScript Engine
- Node.js (installed - latest version)
- npm
- nvm (optional)

 Packages
- react
- react-router-dom

*Stworzone przez: `npm create-react-app \<folder name\>`

Before start:
- `npm install react-scripts`
- `npm install anxios`
- `npm install bootstrap`
- `npm install sass`

How to start: `npm start`


Back-End:
- restbed [https://github.com/Corvusoft/restbed/tree/master] -> headery dodać do includePath'a g++ oraz zbudowane pliki .so do liblaryPath'a g++'a.
- C++14 or higher


## Server-side README

###Konfiguracja 
Serwer jest skonfigurowany na localhost:8080
Jego finalne end poity to:
- [ POST ] /games => creating new game
- [ GET ] /get_game/{id} => geting game ifo
- [ POST ] /games/{id}/MakeMove => making move to game with {id}


### Realizacja planszy
Za pomocą jednowymiarowej tabeli o długości n^2.


### Kodowanie tablicy
Signs
0 -> None
1 -> X
2 -> Y

{
    "board" : {
    "$tile_idx" : tile,
    "$tile_idx" : tile,
    "$tile_idx" : tile,
    ...
    }
}

tile = {
    "ConstSign" : sign,
    "Entaglments" : {
        "entaglment_number" : sing,
        "entaglment_number" : sing
        ...
    }
}

### TODO
Ogólne
- [ ] rozważyć dodanie klasy player
- [ ] może dodac typedef?
- [ ] może dodać using?
- [ ] dodać metody to_json.
- [ ] sprawdzac czy id gry jest prawidłowe

Tile
- [ ] zaimplementować get_signs
- [ ] zastanowić się czy potrzebna jest klasa entanglement? tak... -> dodać int - nr tury, zastnaowic się czy przechowywać shared_ptr na Tile czy robić to po indexie w boardzie
- [ ] czy vector jest ok w przechowaniu entanglements w klasie Tile?

Board
- [ ] zaimplementować make_entanglements
- [ ] zaimplementować check_for_cycles
- [ ] zaimplementować check_for_winner
- [ ] Zastanowić sie czy nie dodać pochodnej klasy implementującej rzeczy potrzebne do API

GamesContainer
- [ ] zaimpelemtnować get_game
