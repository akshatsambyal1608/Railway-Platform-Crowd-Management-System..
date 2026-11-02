# 🚆 Railway Platform Crowd Management System
AKSHAT SINGH SAMBYAL
UID: 26BAI0096
Chandigarh University
B.Tech CSE (AI)

## 📌 Project Overview

The **Railway Platform Crowd Management System** is a menu-driven, command-line application developed using the C programming language. The main objective of this project is to monitor passenger density on railway platforms, manage passenger counts, identify crowded platforms, and provide useful information to improve passenger distribution and platform management.

Railway stations often experience heavy passenger traffic, especially during peak hours, holidays, and train arrival or departure times. Managing passenger movement and platform capacity is important for maintaining safety and reducing overcrowding.

This project provides a simple computerized solution that allows railway staff or administrators to monitor platform occupancy, update passenger counts, view train information, identify the least crowded platform, and generate crowd reports.

The system uses file handling to save platform information so that previously stored data can be loaded when the application starts again.

---

## 🎯 Project Objectives

The main objectives of this project are:

- To monitor passenger counts across multiple railway platforms.
- To classify platform crowd levels based on passenger capacity.
- To update passenger counts whenever the number of passengers changes.
- To display train information such as train number, destination, and arrival time.
- To identify the least crowded platform.
- To generate reports showing total passengers and overcrowded platforms.
- To provide alerts when a platform reaches or exceeds its capacity.
- To store and retrieve platform data using file handling.
- To demonstrate practical applications of C programming concepts.

---

## ✨ Features

### 1. Platform Status Monitoring
Displays the current passenger count, maximum capacity, and crowd level of all five platforms.

### 2. Passenger Count Management
Allows the user to update the passenger count of a selected platform.

The system checks whether the entered platform number and passenger count are valid.

### 3. Crowd Level Classification
The system automatically calculates crowd density based on passenger count and platform capacity.

| Occupancy | Crowd Level |
|---|---|
| Below 30% | LOW |
| 30% to below 60% | MODERATE |
| 60% to below 90% | HIGH |
| 90% or above | OVER-CAPACITY |

### 4. Train Information
Displays the following information:

- Platform number
- Train number
- Destination
- Arrival time

**Note:** The train information included in this version is demonstration data and is not connected to live railway databases.

### 5. Least Crowded Platform
Identifies the platform with the lowest passenger count and displays its crowd level.

### 6. Crowd Report Generation
Generates a summary containing:

- Total number of platforms.
- Total number of passengers.
- Most crowded platform.
- Passenger count on the most crowded platform.
- Number of platforms at or above capacity.
- Alerts identifying platforms that have reached or exceeded capacity.

### 7. File Handling and Data Persistence
The project uses a text file named `platform_data.txt` to save platform information.

- Saves passenger and train information.
- Loads previously saved information when the program starts.
- Uses sample data if no saved file is available.
- Checks for incomplete or invalid saved records.

### 8. Input Validation
The program handles invalid menu choices, invalid platform numbers, and negative or non-numeric passenger counts.

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Main programming language |
| GCC Compiler | Compiling the source code |
| Standard C Libraries | Input/output and utility operations |
| File Handling | Saving and loading platform information |
| Structures | Organizing platform records |
| Git | Version control |
| GitHub | Project hosting and code management |

### C Libraries Used

- `stdio.h` – Input/output operations and file handling.
- `stdlib.h` – Standard utility functions.
- `string.h` – String handling operations.

---

## 🧠 Concepts of C Programming Used

This project demonstrates the following C programming concepts:

1. **Structures (`struct`)** – To store platform number, passenger count, capacity, train number, destination, and arrival time.
2. **Arrays** – To manage information for five railway platforms.
3. **Functions** – To divide the program into smaller and reusable operations.
4. **Conditional Statements** – To classify crowd levels and validate user input.
5. **Loops** – To display menus and process platform records.
6. **Switch Statements** – To handle menu-driven operations.
7. **Pointers** – To pass arrays and access data through function parameters.
8. **File Handling** – To save and retrieve platform information.
9. **String Handling** – To manage destination and arrival-time information.
10. **Input Validation** – To prevent invalid user entries.

---

## ⚙️ System Requirements

### Hardware Requirements
- Computer or laptop.
- Minimum 2 GB RAM.
- Basic storage space.

### Software Requirements
- macOS, Windows, or Linux.
- GCC compiler or another compatible C compiler.
- Terminal or command prompt.
- Git (for uploading the project to GitHub).

---

## 🚀 Installation and Execution

### Step 1: Clone the Repository

Open your terminal and execute:

```bash
git clone https://github.com/YOUR_USERNAME/railway-platform-crowd-management.git
```

### Step 2: Navigate to the Project Folder

```bash
cd railway-platform-crowd-management
```

### Step 3: Compile the Program

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o railway
```

### Step 4: Run the Program

On macOS or Linux:

```bash
./railway
```

On Windows:

```bash
railway.exe
```

---

## 📋 Program Menu

When the program starts, the following menu is displayed:

```text
========================================
     RAILWAY PLATFORM CROWD MANAGEMENT
========================================
1. View Platform Status
2. Update Passenger Count
3. View Train Information
4. Find Least Crowded Platform
5. Generate Crowd Report
6. Save Data
0. Save and Exit
----------------------------------------
Enter your choice:
```

### Menu Options Explained

| Option | Function |
|---|---|
| 1 | Displays the passenger count and crowd level of all platforms. |
| 2 | Updates the passenger count of a selected platform. |
| 3 | Displays train numbers, destinations, and arrival times. |
| 4 | Finds the platform with the lowest passenger count. |
| 5 | Generates a complete crowd report. |
| 6 | Saves the current platform information. |
| 0 | Saves data and exits the program. |

---

## 📊 Sample Platform Data

The application initially uses the following demonstration data if no valid saved data file is found.

| Platform | Passengers | Capacity | Destination | Train Number |
|---|---:|---:|---|---:|
| 1 | 100 | 1000 | Delhi | 12001 |
| 2 | 250 | 1000 | Chandigarh | 12002 |
| 3 | 400 | 1000 | Jammu | 12003 |
| 4 | 550 | 1000 | Amritsar | 12004 |
| 5 | 700 | 1000 | Srinagar | 12005 |

---

## 📁 Project Structure

```text
railway-platform-crowd-management/
│
├── main.c
│   └── Main source code of the application
│
├── platform_data.txt
│   └── Stores saved platform information
│
├── README.md
│   └── Project documentation
│
└── .gitignore
    └── Specifies files excluded from Git tracking
```

*The above structure describes the single-file version of the project. Update it if your repository contains additional source modules.*

---

## 🔒 Data Storage

The application uses basic text-file storage.

The file `platform_data.txt` stores records in the following format:

```text
PlatformNumber PassengerCount Capacity TrainNumber Destination ArrivalTime
```

Example:

```text
1 100 1000 12001 Delhi 10:30
2 250 1000 12002 Chandigarh 10:30
```

When the application starts, it attempts to load saved records. If the file does not exist, the program continues with its predefined sample data.

---

## ⚠️ Limitations

The current version of the project has the following limitations:

- It supports five predefined platforms.
- Train information is static demonstration data.
- It does not connect to live railway databases or APIs.
- Passenger counts must be entered manually.
- It does not use real-time cameras or sensors.
- Data is stored in a local text file rather than a centralized database.
- It does not provide a graphical user interface.

---

## 🔮 Future Scope

The project can be improved by adding:

1. **Real-Time Passenger Counting:** Integration with sensors or cameras to estimate passenger density automatically.
2. **Live Train Information:** Integration with railway APIs to obtain updated train schedules and delays.
3. **Graphical User Interface:** Development of a user-friendly dashboard.
4. **More Railway Platforms:** Support for a larger number of platforms.
5. **Automated Alerts:** Notifications when passenger density reaches dangerous levels.
6. **Database Integration:** Use of MySQL or SQLite for better data management.
7. **Crowd Prediction:** Use of historical passenger data to estimate future crowd levels.
8. **Web-Based Dashboard:** Allow administrators to monitor railway platforms remotely.

---

## 🎓 Learning Outcomes

Through this project, we learned how to:

- Develop a menu-driven application in C.
- Implement structures and arrays.
- Divide a program into multiple functions.
- Perform file operations.
- Validate user input.
- Apply conditional logic and loops.
- Manage and analyze structured data.
- Use Git and GitHub for project version control.

---

## 👨‍💻 Contributors

**Project Name:** Railway Platform Crowd Management System

**Programming Language:** C

**Project Type:** Academic / Mini Project

**Repository:** [Railway Platform Crowd Management](https://github.com/YOUR_USERNAME/railway-platform-crowd-management)

---

## 📜 License

This project is available for educational and learning purposes. You may use, study, and modify the source code with appropriate credit to the original contributors.

---

## ⭐ Acknowledgement

This project was developed as an academic programming project to understand the practical implementation of C programming concepts, data management, file handling, and problem-solving techniques.

Thank you for visiting this repository! 🚆
