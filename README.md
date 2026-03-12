🚗 Car Parking Management System (C++)

A console-based Car Parking Management System developed using C++ to simulate how parking areas are managed in places like malls, offices, and residential complexes.

The system helps organize parking spaces efficiently by automatically allocating slots, recording vehicle entry and exit times, calculating parking fees, and maintaining parking records.

This project demonstrates practical programming concepts such as object-oriented programming, file handling, and algorithm-based slot allocation.

✨ Features

🚗 Vehicle Parking System

Automatically assigns the first available parking slot

Records vehicle number and entry time

Displays estimated parking fee

🚪 Vehicle Removal

Search and remove parked vehicles

Displays entry time, exit time, and parking fee

Frees the slot for future vehicles

📊 Parking Slot Management

Manages 15 parking slots

Shows which slots are occupied or available

🔍 Vehicle Search

Allows users to search for vehicles by vehicle number

Displays slot number and entry time if found

📈 Parking Summary

Total number of parking slots

Number of occupied slots

Number of available slots

Total parking earnings

💾 Parking Record Storage

Stores parking data in a file:

parking_records.txt

This ensures that parking activities are properly recorded.

🧰 Technology Stack

Technology	Purpose

C++	Core programming language

Object-Oriented Programming	Organizing system modules

File Handling	Storing parking records

Time Functions	Recording entry and exit time


🧠 How the System Works

The program manages 15 parking slots using a menu-driven console interface.

When a vehicle enters:

1️⃣ The user enters the vehicle number and parking hours

2️⃣ The system searches for the first available slot

3️⃣ The slot is allocated automatically

4️⃣ Entry time is recorded

5️⃣ Parking details are saved in parking_records.txt


When the vehicle leaves:

1️⃣ The user enters the vehicle number

2️⃣ The system searches the parking slots

3️⃣ Entry and exit times are displayed

4️⃣ Parking fee is calculated using:

Parking Fee = Hours Parked × ₹80

5️⃣ The slot becomes available again.

📷 Program Screenshots

<img width="630" height="374" alt="B9062565-22D8-4770-8312-F1B06F4B349B" src="https://github.com/user-attachments/assets/fb9a3a30-9de7-4a77-af19-bab64ac38426" />

![A24AED96-38E5-4A6E-A7B3-CC8E17895D5C_4_5005_c](https://github.com/user-attachments/assets/d3a59387-8d7d-4a0e-b221-ab56f22cb7b0)

![64B304CA-D812-4D72-802F-79B06F4F6A1E_4_5005_c](https://github.com/user-attachments/assets/cb5a7204-2ef6-4065-af79-81628b9a618f)

<img width="676" height="790" alt="743EEBF2-9926-4BED-AE08-21D397EDF2A2" src="https://github.com/user-attachments/assets/a7f113d4-18c9-4cc1-b23e-c53868a47b18" />


📂 Project Structure

<img width="1430" height="596" alt="image" src="https://github.com/user-attachments/assets/5bd5f4d4-9e32-43c4-9a31-a69aa2ed935a" />




▶️ How to Run the Program

1️⃣ Download or clone the repository

git clone https://github.com/bhuvishag07/CAR-PARKING-MANAGEMENT-SYSTEM.git

2️⃣ Open the project folder

3️⃣ Compile the program

g++ parking.cpp -o parking

4️⃣ Run the program

./parking

The program will start with the menu-driven interface.

🎓 Academic Documentation

This project was developed as part of an academic case study. Along with the source code, the project also includes supporting academic documents:

📊 Project Presentation (PPT) – Explains the project concept, design, algorithms, and working of the system.

📑 Project Report – Contains the detailed case study including problem statement, system design, implementation details, results, and conclusion.

These documents provide a complete explanation of the project development and methodology used in building the Car Parking Management System.


👩‍🎓 Student Information

 Bhuvisha Gohil
 B.Tech – Computer Science & Engineering
 ITM Skills University

This project was developed as part of an academic case study to demonstrate the practical implementation of C++ programming concepts such as object-oriented programming, file handling, and algorithm-based system design.

The project focuses on solving a real-world problem by building a simple and efficient parking management system using C++.
