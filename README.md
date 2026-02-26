# C++ Task & Organization Management System

A high-performance console-based application designed for organizational workflow automation, task distribution, and employee scheduling using **C++** and **Object-Oriented Programming (OOP)**.

## 📌 Project Overview
The purpose of this system is to manage and divide an organization's workload among its employees efficiently. It features a persistent database (via file handling) and intelligent scheduling algorithms to optimize daily operations.

## 🚀 Key Features

### 📅 Advanced Scheduling & Calendar
* **`now` / `today` / `month`**: Real-time display of current date, daily tasks, and monthly schedules.
* **`add task`**: Registers new tasks with specific durations.
    * *Input Format:* `dd-mm hh:mm` (Numeric representation).
* **`find time`**: An intelligent search tool that finds the nearest empty interval for a given duration (`hh:mm`). If the schedule is full, it suggests a slot with **minimal overlap**.
* **`free`**: Deletes all tasks for a specific date/time entry.

### 👥 Human Resources & Task Allocation
* **`add employee`**: Registers staff members with `Name`, `National Code`, and `Daily Working Hours`.
* **`assign task`**: Connects a specific job to an employee using their unique `National Code`.
* **`show employee task`**: Filters and displays the workload for a specific individual.
* **`schedule`**: Optimizes an employee's day by clearing previous entries and assigning the **largest possible subset of tasks** for maximum productivity.

### 💾 Data Persistence
* **`exit`**: Automatically triggers a data-save sequence to external files before terminating the program, ensuring no data loss.

## 🔑 System Logic & Mapping
* **`sal99`**: An instance of the `year` class, acting as the main organizational database.
* **`National Code`**: The primary key (unique identifier) for all employee-related queries.
* **`dd-mm hh:mm`**: The standardized numerical time format used throughout the system.
* **`Largest Subset`**: A greedy-based optimization logic used in the `schedule` command.

## 🛠️ Technologies Used
* **Language:** C++
* **Concepts:** Object-Oriented Programming (Classes, Encapsulation), File I/O, Data Structures (Linked Lists/Arrays).
* **Environment:** Console-based CLI.

