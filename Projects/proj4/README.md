# Project 4: Space Exploration Game

A space exploration and resource management game. Players pilot a spaceship across planets, battle enemies, collect items (armor, weapons, engines), manage fuel, and attempt to reach the planet "Utopia" with a sufficiently upgraded engine.

## How It Works

1. The player names their ship and begins exploring space.
2. Moving to a new planet costs fuel. Planets can be gas, mining, or enemy type.
3. Defeating a planet rewards the player with a random item (armor, weapon, engine, gas, or mining equipment).
4. The win condition is reaching Utopia with an engine power level between 30 and 50.

## Source Files

- `proj4.cpp` — Main entry point
- `Game.h` / `Game.cpp` — Game logic (movement, combat, win condition)
- `Ship.h` / `Ship.cpp` — Ship class (inventory, fuel, equipment)
- `Planet.h` / `Planet.cpp` — Planet class (type, level, battle)
- `Item.h` / `Item.cpp` — Base item class
- `Armor.h` / `Armor.cpp` — Armor subclass
- `Weapon.h` / `Weapon.cpp` — Weapon subclass
- `Engine.h` / `Engine.cpp` — Engine subclass
- `Gas.h` / `Gas.cpp` — Gas subclass
- `Mining.h` / `Mining.cpp` — Mining subclass
- `Enemy.h` / `Enemy.cpp` — Enemy subclass

## Data Files

- `proj4_items.txt` — Item catalog (name, type, level)
- `proj4_planets.txt` — Planet database (name, type, level)
- `proj4_sample1.txt` — Sample gameplay output

## Building and Running

```bash
make
./proj4 proj4_items.txt proj4_planets.txt
```
