# Project 5: Movie Player Queue System

A movie catalog and playlist management system. Users browse a database of 800+ movies, filter by year and genre, build a playlist queue, and sort it by release year. Demonstrates generic programming with a templated linked-list queue.

## How It Works

1. A catalog of 800+ movies (1980–2020) is loaded from a data file.
2. Users filter movies by release year and genre.
3. Selected movies are added to a playlist implemented as a templated queue.
4. The playlist can be displayed or sorted by year.

## Source Files

- `proj5.cpp` — Main entry point
- `Movie.h` / `Movie.cpp` — Movie class (title, rating, genre, year, director, etc.)
- `MoviePlayer.h` / `MoviePlayer.cpp` — MoviePlayer class (catalog loading, filtering, playlist management)
- `Queue.cpp` — Templated queue and node classes (linked-list based)
- `queue_test.cpp` — Queue unit tests

## Data Files

- `proj5_movies.txt` — 800+ movies (title, rating, genre, year, director, star, budget, gross, studio, runtime)
- `proj5_sample.txt` — Sample output

## Building and Running

```bash
make
./proj5 proj5_movies.txt
```

To run queue tests:

```bash
make qtest
./qtest
```
