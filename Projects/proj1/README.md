# Project 1: Wheel of Fortune

A C++ implementation of the classic game show "Wheel of Fortune." Players guess letters one at a time to reveal a hidden word puzzle.

## How It Works

1. The game loads 24 puzzles and their categories from a data file.
2. A puzzle is randomly selected and displayed as blanks.
3. The player guesses letters (A–Z) to reveal the hidden phrase.
4. The game continues until the entire puzzle is solved.

## Source Files

- `proj1.cpp` — Main game logic (loading puzzles, handling input, checking guesses)
- `tester.cpp` — Test/alternate version

## Data Files

- `proj1_data.txt` — Contains 24 puzzle entries (alternating lines of category and puzzle text)
- `proj1_sample.txt` — Sample puzzle file

## Building and Running

```bash
g++ proj1.cpp -o proj1
./proj1
```
