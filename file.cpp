#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class ParkingSlot {
private:
    int slotNumber;
    string vehicleNumber;
    int hoursParked;
    time_t entryTime;
    bool isOccupied;

public:
    ParkingSlot(int number = 0) {
        slotNumber = number;
        vehicleNumber = "";
        hoursParked = 0;
        entryTime = 0;
        isOccupied = false;
    }

    ~ParkingSlot() {}

    void allocateSlot(string vNumber, int hours) {
        vehicleNumber = vNumber;
        hoursParked = hours;
        entryTime = time(0);
        isOccupied = true;
    }

    int releaseSlot() {
        int fee = hoursParked * 80; // 80 per hour
        vehicleNumber = "";
        hoursParked = 0;
        entryTime = 0;
        isOccupied = false;
        return fee;
    }

    void displaySlot() {
        cout << "Slot " << slotNumber << " : ";
        if (isOccupied)
            cout << "[X] Occupied (Vehicle: " << vehicleNumber << ")\n";
        else
            cout << "[ ] Available\n";
    }

    bool getStatus() { return isOccupied; }
    int getSlotNumber() { return slotNumber; }
    string getVehicleNumber() { return vehicleNumber; }
    int getHours() { return hoursParked; }
    time_t getEntryTime() { return entryTime; }
};

class ParkingSystem {
private:
    ParkingSlot* slots;
    int totalSlots;
    int totalEarnings;

    int countFreeSlots() {
        int freeCount = 0;
        for (int i = 0; i < totalSlots; i++)
            if (!slots[i].getStatus()) freeCount++;
        return freeCount;
    }

    void displayDateTime(time_t t, string label) {
        struct tm *tm_info = localtime(&t);
        char dateBuffer[20], timeBuffer[10];
        strftime(dateBuffer, 20, "%d-%m-%Y", tm_info); // DD-MM-YYYY
        strftime(timeBuffer, 10, "%H:%M:%S", tm_info); // 24-hour format
        cout << label << " : " << dateBuffer << endl;
        cout << timeBuffer << endl;
    }

public:
    ParkingSystem(int n) {
        totalSlots = n;
        slots = new ParkingSlot[totalSlots];
        totalEarnings = 0;
        for (int i = 0; i < totalSlots; i++) slots[i] = ParkingSlot(i + 1);
    }

    ~ParkingSystem() { delete[] slots; }

    void parkVehicle() {
        string vNumber;
        int hours;
        cout << "\n--- Park Vehicle ---\nEnter Vehicle Number: ";
        cin >> vNumber;

        cout << "Enter Hours Parked: ";
        cin >> hours;
        if(hours <= 0) hours = 1;

        int availableSlot = -1;
        for (int i = 0; i < totalSlots; i++)
            if (!slots[i].getStatus() && availableSlot == -1) availableSlot = i;

        if (availableSlot != -1) {
            slots[availableSlot].allocateSlot(vNumber, hours);
            cout << "Parking Slot Allocated: " << slots[availableSlot].getSlotNumber() << endl;

            int fare = hours * 80; // 80 per hour
            cout << "Expected Parking Fee: ₹" << fare << endl;

            int freeSlots = countFreeSlots();
            cout << "Available Slots: " << freeSlots << endl;
            if(freeSlots <= 2 && freeSlots > 0)
                cout << "Warning: Only " << freeSlots << " slots left!\n";

            displayDateTime(slots[availableSlot].getEntryTime(), "Entry Time");

            ofstream file("parking_records.txt", ios::app);
            file << "Parked -> Vehicle: " << vNumber 
                 << " | Slot: " << slots[availableSlot].getSlotNumber() 
                 << " | Hours: " << hours 
                 << " | Entry Time: " << slots[availableSlot].getEntryTime() << endl;
            file.close();
        } else {
            cout << "Parking Full!\n";
        }
    }

    void removeVehicle() {
        string vNumber;
        cout << "\n--- Remove Vehicle ---\nEnter Vehicle Number: ";
        cin >> vNumber;

        bool found = false;
        for (int i = 0; i < totalSlots; i++) {
            if (slots[i].getStatus() && slots[i].getVehicleNumber() == vNumber) {
                time_t entryTime = slots[i].getEntryTime();
                int hours = slots[i].getHours();
                int fee = slots[i].releaseSlot();
                totalEarnings += fee;

                time_t exitTime = time(0);

                cout << "\nVehicle Removed from Slot " << i + 1 << endl;
                displayDateTime(entryTime, "Entry Time");
                displayDateTime(exitTime, "Exit Time");
                cout << "Parking Fee: ₹" << fee << endl;

                ofstream file("parking_records.txt", ios::app);
                file << "Removed -> Vehicle: " << vNumber 
                     << " | Slot: " << i + 1 
                     << " | Fee: ₹" << fee
                     << " | Entry Time: " << entryTime
                     << " | Exit Time: " << exitTime << endl;
                file.close();

                found = true;
                break;
            }
        }
        if (!found) cout << "Vehicle Not Found!\n";
    }

    void viewSlots() {
        cout << "\n--- Parking Slot Status ---\n";
        for (int i = 0; i < totalSlots; i++) slots[i].displaySlot();

        int freeSlots = countFreeSlots();
        cout << "Total Slots: " << totalSlots << ", Available Slots: " << freeSlots << endl;
        if(freeSlots <= 2 && freeSlots > 0)
            cout << "Warning: Only " << freeSlots << " slots left!\n";
    }

    void parkingSummary() {
        int occupied = 0;
        int totalEarningsSum = totalEarnings; // earnings from removed vehicles

        cout << "\n--- Parking Summary ---\n";
        for (int i = 0; i < totalSlots; i++) {
            slots[i].displaySlot();
            if (slots[i].getStatus()) {
                occupied++;
                totalEarningsSum += slots[i].getHours() * 80; // earnings from currently parked cars
            }
        }

        cout << "Total Slots: " << totalSlots << endl;
        cout << "Occupied Slots: " << occupied << endl;
        cout << "Available Slots: " << totalSlots - occupied << endl;
        cout << "Total Earnings: ₹" << totalEarningsSum << endl;
    }

    void searchVehicle() {
        string vNumber;
        cout << "\n--- Search Vehicle ---\nEnter Vehicle Number: ";
        cin >> vNumber;
        bool found = false;
        for (int i = 0; i < totalSlots; i++) {
            if (slots[i].getStatus() && slots[i].getVehicleNumber() == vNumber) {
                cout << "Vehicle found in Slot " << slots[i].getSlotNumber() << endl;
                displayDateTime(slots[i].getEntryTime(), "Entry Time");
                found = true;
                break;
            }
        }
        if (!found) cout << "Vehicle Not Found!\n";
    }

    void displayMenu() {
        cout << "\n==============================\n";
        cout << "   CAR PARKING MANAGEMENT SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. View Slots\n";
        cout << "4. Parking Summary\n";
        cout << "5. Search Vehicle\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }
};

int main() {
    ParkingSystem system(15); // total slots = 15
    int choice;
    do {
        system.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: system.parkVehicle(); break;
            case 2: system.removeVehicle(); break;
            case 3: system.viewSlots(); break;
            case 4: system.parkingSummary(); break;
            case 5: system.searchVehicle(); break;
            case 6: cout << "Exiting Program...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}