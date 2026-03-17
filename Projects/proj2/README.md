# Project 2: Pokemon Game

A C++ Pokemon game where players catch, train, and battle Pokemon. Build a team of up to 4 Pokemon by searching different rarity levels, train them to increase their combat power (CP), and battle enemy Pokemon.

## How It Works

1. A PokeDex of 151 Pokemon is loaded from a data file.
2. Players search for Pokemon by rarity: Common (45% spawn), Uncommon (25% spawn), or Ultra Rare (1% spawn).
3. Caught Pokemon are added to the team (max 4). If the team is full, a weaker Pokemon can be replaced.
4. Players can train Pokemon to increase CP or battle randomly selected enemies.

## Source Files

- `proj2.cpp` — Main entry point
- `Pokemon.h` / `Pokemon.cpp` — Pokemon class (name, CP, rarity, training)
- `Game.h` / `Game.cpp` — Game logic (catching, battling, team management)

## Data Files

- `proj2_pokeDex.txt` — 151 Pokemon entries (number, name, CP, rarity)
- `proj2_sample1.txt` — Sample game output

## Building and Running

```bash
make
./proj2 proj2_pokeDex.txt
```
