# Railway Platform Crowd Management System

A beginner-friendly, menu-driven C project for managing passenger counts across railway platforms. It stores platform information in a local text file so updated passenger counts are available the next time the program runs.

> **Important:** This is an educational/demo project. Train details and passenger counts are sample data. It does not connect to Indian Railways or provide live train information.

## Features

1. View passenger count, capacity, and crowd level for each platform.
2. Update the passenger count for a selected platform.
3. View sample train number, destination, and arrival time.
4. Find the least crowded platform.
5. Generate a crowd report and identify platforms at/above capacity.
6. Save and load platform data using `platform_data.txt`.

## Project files

```text
railway-management-system/
├── main.c
├── platform_data.txt
├── Makefile
├── README.md
└── .gitignore
```

## Requirements

- GCC or another C compiler
- Terminal / Command Prompt

## Compile and run

### Linux

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o railway
./railway
```

### Windows (MinGW)

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o railway.exe
railway.exe
```

### Using Make

If `make` is installed:

```bash
make
make run
```

To remove the compiled program:

```bash
make clean
```

## Data storage

The program reads from and writes to `platform_data.txt` in its current working directory. If the file is missing, built-in sample data is used. Choose **Save Data** or **Save and Exit** after making changes.

Each line contains:

```text
platform_number passenger_count capacity train_number destination arrival_time
```

## Example workflow

1. Run the program.
2. Choose `1` to view platform status.
3. Choose `2` to update a platform's passenger count.
4. Choose `5` to view the crowd report.
5. Choose `0` to save and exit.

## Possible future improvements

- Add, edit, and delete train records.
- Search trains by train number or destination.
- Add date-wise train schedules.
- Store data in CSV or SQLite instead of a text file.
- Add user login and administrator roles.
- Build a graphical interface or web dashboard.
- Connect to an official railway data source, if an authorized API is available.

## Learning concepts used

- Structures (`struct`)
- Arrays
- Functions
- Conditional statements and loops
- File handling (`fopen`, `fscanf`, `fprintf`, `fclose`)
- Input validation

## License

This project is provided for learning and educational use. You may adapt it for your coursework; check your institution's rules before submitting it.
