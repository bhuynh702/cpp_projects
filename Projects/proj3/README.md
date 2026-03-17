# Project 3: Flight Route Navigator

A route planning system for airports. Users create flight routes between airports, view route distances, remove stops, and reverse routes. Distances are calculated using the Haversine formula with real latitude/longitude coordinates.

## How It Works

1. A database of 40 real-world airports is loaded from a data file.
2. Users build routes by selecting airports from the list (minimum 2 per route).
3. The system calculates total route distance using geographic coordinates.
4. Routes can be displayed, modified (remove airports), or reversed.

## Source Files

- `proj3.cpp` — Main entry point
- `Airport.h` / `Airport.cpp` — Airport class (code, name, city, country, coordinates)
- `Route.h` / `Route.cpp` — Route class (linked list of airports)
- `Navigator.h` / `Navigator.cpp` — Navigator class (file loading, route management, distance calculation)

## Data Files

- `proj3_data.txt` — 40 airports (code, name, city, country, latitude, longitude)
- `proj3_sample.txt` — Sample output

## Building and Running

```bash
make
./proj3 proj3_data.txt
```
