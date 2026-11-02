#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_PLATFORMS 5
#define DATA_FILE "platform_data.txt"

typedef struct {
    int platformNumber;
    int passengerCount;
    int capacity;
    int trainNumber;
    char destination[50];
    char arrivalTime[10];
} Platform;

/* Function declarations */
void initializePlatforms(Platform platforms[]);
void loadData(Platform platforms[]);
void saveData(const Platform platforms[]);
void viewPlatformStatus(const Platform platforms[]);
void updatePassengerCount(Platform platforms[]);
void viewTrainInformation(const Platform platforms[]);
void findLeastCrowdedPlatform(const Platform platforms[]);
void generateCrowdReport(const Platform platforms[]);
const char *getCrowdLevel(int passengers, int capacity);
void clearInputBuffer(void);

/* Main function */
int main(void) {
    Platform platforms[TOTAL_PLATFORMS];
    int choice;

    initializePlatforms(platforms);
    loadData(platforms);

    do {
        printf("\n========================================\n");
        printf("     RAILWAY PLATFORM CROWD MANAGEMENT\n");
        printf("========================================\n");
        printf("1. View Platform Status\n");
        printf("2. Update Passenger Count\n");
        printf("3. View Train Information\n");
        printf("4. Find Least Crowded Platform\n");
        printf("5. Generate Crowd Report\n");
        printf("6. Save Data\n");
        printf("0. Save and Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                viewPlatformStatus(platforms);
                break;
            case 2:
                updatePassengerCount(platforms);
                break;
            case 3:
                viewTrainInformation(platforms);
                break;
            case 4:
                findLeastCrowdedPlatform(platforms);
                break;
            case 5:
                generateCrowdReport(platforms);
                break;
            case 6:
                saveData(platforms);
                break;
            case 0:
                saveData(platforms);
                printf("Data saved. Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice. Please select an option from the menu.\n");
        }
    } while (choice != 0);

    return 0;
}

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Discard invalid input */
    }
}

/* Set up sample data. This is used if no saved data file exists. */
void initializePlatforms(Platform platforms[]) {
    const char *destinations[TOTAL_PLATFORMS] = {
        "Delhi", "Chandigarh", "Jammu", "Amritsar", "Srinagar"
    };
    int i;

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        platforms[i].platformNumber = i + 1;
        platforms[i].passengerCount = 100 + (i * 150);
        platforms[i].capacity = 1000;
        platforms[i].trainNumber = 12001 + i;
        snprintf(platforms[i].destination,
                 sizeof(platforms[i].destination), "%s", destinations[i]);
        snprintf(platforms[i].arrivalTime,
                 sizeof(platforms[i].arrivalTime), "%s", "10:30");
    }
}

/* Return a crowd label based on the platform's capacity. */
const char *getCrowdLevel(int passengers, int capacity) {
    double percentage;

    if (capacity <= 0) {
        return "UNKNOWN";
    }

    percentage = (double)passengers / capacity * 100.0;

    if (percentage < 30.0) return "LOW";
    if (percentage < 60.0) return "MODERATE";
    if (percentage < 90.0) return "HIGH";
    return "OVER-CAPACITY";
}

void viewPlatformStatus(const Platform platforms[]) {
    int i;

    printf("\n---------------- PLATFORM STATUS ----------------\n");
    printf("%-10s %-12s %-12s %-15s\n",
           "Platform", "Passengers", "Capacity", "Crowd Level");

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        printf("%-10d %-12d %-12d %-15s\n",
               platforms[i].platformNumber,
               platforms[i].passengerCount,
               platforms[i].capacity,
               getCrowdLevel(platforms[i].passengerCount,
                             platforms[i].capacity));
    }
}

void updatePassengerCount(Platform platforms[]) {
    int platformNumber, count;

    printf("Enter platform number (1-%d): ", TOTAL_PLATFORMS);
    if (scanf("%d", &platformNumber) != 1) {
        printf("Invalid platform number.\n");
        clearInputBuffer();
        return;
    }

    if (platformNumber < 1 || platformNumber > TOTAL_PLATFORMS) {
        printf("That platform does not exist.\n");
        return;
    }

    printf("Enter current passenger count: ");
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid passenger count. Enter a non-negative whole number.\n");
        clearInputBuffer();
        return;
    }

    platforms[platformNumber - 1].passengerCount = count;

    printf("Passenger count updated successfully.\n");
    printf("Current crowd level: %s\n",
           getCrowdLevel(count, platforms[platformNumber - 1].capacity));

    if (count >= platforms[platformNumber - 1].capacity) {
        printf("ALERT: Platform %d has reached or exceeded capacity!\n",
               platformNumber);
    }
}

void viewTrainInformation(const Platform platforms[]) {
    int i;

    printf("\n---------------- TRAIN INFORMATION ----------------\n");
    printf("%-10s %-12s %-20s %-12s\n",
           "Platform", "Train No.", "Destination", "Arrival");

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        printf("%-10d %-12d %-20s %-12s\n",
               platforms[i].platformNumber,
               platforms[i].trainNumber,
               platforms[i].destination,
               platforms[i].arrivalTime);
    }

    printf("\nNote: The train details are demonstration data, not live railway data.\n");
}

void findLeastCrowdedPlatform(const Platform platforms[]) {
    int i, leastIndex = 0;

    for (i = 1; i < TOTAL_PLATFORMS; i++) {
        if (platforms[i].passengerCount <
            platforms[leastIndex].passengerCount) {
            leastIndex = i;
        }
    }

    printf("\nLeast crowded platform: Platform %d\n",
           platforms[leastIndex].platformNumber);
    printf("Passenger count: %d\n", platforms[leastIndex].passengerCount);
    printf("Crowd level: %s\n",
           getCrowdLevel(platforms[leastIndex].passengerCount,
                         platforms[leastIndex].capacity));
}

void generateCrowdReport(const Platform platforms[]) {
    int i;
    int totalPassengers = 0;
    int highestIndex = 0;
    int overcrowdedCount = 0;

    printf("\n================ CROWD REPORT ================\n");

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        totalPassengers += platforms[i].passengerCount;

        if (platforms[i].passengerCount >
            platforms[highestIndex].passengerCount) {
            highestIndex = i;
        }

        if (platforms[i].passengerCount >= platforms[i].capacity) {
            overcrowdedCount++;
        }
    }

    printf("Total platforms: %d\n", TOTAL_PLATFORMS);
    printf("Total passengers: %d\n", totalPassengers);
    printf("Most crowded platform: Platform %d\n",
           platforms[highestIndex].platformNumber);
    printf("Passengers on most crowded platform: %d\n",
           platforms[highestIndex].passengerCount);
    printf("Platforms at or above capacity: %d\n", overcrowdedCount);

    if (overcrowdedCount > 0) {
        printf("\nALERT: Check these platforms:\n");
        for (i = 0; i < TOTAL_PLATFORMS; i++) {
            if (platforms[i].passengerCount >= platforms[i].capacity) {
                printf("Platform %d - %d passengers\n",
                       platforms[i].platformNumber,
                       platforms[i].passengerCount);
            }
        }
    } else {
        printf("No platforms are at or above capacity.\n");
    }
}

/* Save all platform records in a simple text file. */
void saveData(const Platform platforms[]) {
    FILE *file = fopen(DATA_FILE, "w");
    int i;

    if (file == NULL) {
        printf("Error: Could not open %s for writing.\n", DATA_FILE);
        return;
    }

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        fprintf(file, "%d %d %d %d %s %s\n",
                platforms[i].platformNumber,
                platforms[i].passengerCount,
                platforms[i].capacity,
                platforms[i].trainNumber,
                platforms[i].destination,
                platforms[i].arrivalTime);
    }

    if (fclose(file) == 0) {
        printf("Data saved successfully to %s.\n", DATA_FILE);
    } else {
        printf("Error: A problem occurred while closing the data file.\n");
    }
}

/* Load saved records. If the file is missing or invalid, defaults remain. */
void loadData(Platform platforms[]) {
    FILE *file = fopen(DATA_FILE, "r");
    Platform loaded[TOTAL_PLATFORMS];
    int i;

    if (file == NULL) {
        printf("No saved data found. Loading sample platform data.\n");
        return;
    }

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        if (fscanf(file, "%d %d %d %d %49s %9s",
                   &loaded[i].platformNumber,
                   &loaded[i].passengerCount,
                   &loaded[i].capacity,
                   &loaded[i].trainNumber,
                   loaded[i].destination,
                   loaded[i].arrivalTime) != 6) {
            printf("Warning: Data file is incomplete or invalid. Using sample data.\n");
            fclose(file);
            return;
        }

        if (loaded[i].platformNumber < 1 ||
            loaded[i].platformNumber > TOTAL_PLATFORMS ||
            loaded[i].passengerCount < 0 ||
            loaded[i].capacity <= 0) {
            printf("Warning: Data file contains invalid values. Using sample data.\n");
            fclose(file);
            return;
        }
    }

    for (i = 0; i < TOTAL_PLATFORMS; i++) {
        platforms[i] = loaded[i];
    }

    fclose(file);
    printf("Saved platform data loaded successfully.\n");
}
