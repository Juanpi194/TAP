```
Player Nublax created
Player Nublax destroyed          ← delete(p3), manual y explícito

Destroying room Entrance         ← room se destruye (fin de scope)
  Player Juanpi destroyed        ← la COPIA de p1 dentro de room.player_list
    Destroying Sword             ←   Items de esa copia
    Destroying Potion            ←

Destroying Potion                ← item1 (el original, movido a p1.bag)

Player Coco destroyed            ← p2 (sin items)

Player Juanpi destroyed          ← p1 original, el último en destruirse
  Destroying Sword               ←   sus items
  Destroying Potion              ←
```