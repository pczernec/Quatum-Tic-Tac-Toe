# Server-side README

## Realizacja planszy
Za pomocą jednowymiarowej tabeli o długości n^2.


## Kodowanie tablicy
Signs
0 -> None
1 -> X
2 -> Y

{
    "Board" : {
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

