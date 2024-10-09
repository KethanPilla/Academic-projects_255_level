# Tornado Data Analysis Project
## Overview
This project processes and analyzes tornado data from a file. The goal is to provide meaningful insights such as tornado occurrences, wind speeds, and fatalities by year and location. It implements data filtering and statistical operations on tornado records for efficient querying.

## Files
- **tornado.txt**: Contains tornado data in the format:
  `Year, Location, Fujita Rating, Wind Speed (mph), Fatalities`

- **main.cpp.cpp**: The main driver program that handles user input and output, allowing the user to interact with the tornado data.

- **tornInfo.h**: Header file defining the structure and methods used for managing and analyzing the tornado data.

# Underlying Data Structure & Principles
### 1. Data Structure:
- Array/List: The tornado data is stored in an array or list-like structure where each element represents a tornado record. This allows for efficient iteration, filtering, and manipulation of the data.
- Class-Based Design: The data is encapsulated in a class (defined in tornInfo.h). Each tornado record is an object of this class, containing fields for the year, location, Fujita rating, wind speed, and fatalities. This makes the code modular and extendable.

### 2. Principles Used:
- Object-Oriented Programming (OOP): The project follows OOP principles by using classes to model tornado data and perform operations. This improves code organization, reusability, and scalability.
- Abstraction: The details of how data is processed and stored are abstracted from the user. The user interacts with high-level methods to query and analyze data without worrying about the internal implementation.
- Separation of Concerns: The project separates data storage (handled by tornInfo.h) and user interaction logic (handled by main.cpp.cpp). This modularity improves maintainability.

## Operations Supported:
- Insert Tornado Records: Data is loaded from the file and stored in the program.
- Filter by Year or Location: The program filters tornado records based on year or location.
- Statistical Calculations: Functions to compute total fatalities, average wind speed, and tornado frequency.

## How the Code Works
- Data Input: Reads tornado data from the tornado.txt file, which contains tornado records.
- Main Operations:
  - Display Tornadoes by Year: Shows all tornado events for a specific year.
  - Display Tornadoes by Location: Shows all tornadoes that occurred in a specified location.
  - Statistics: Computes important statistics like average wind speed, total fatalities, and number of tornadoes by Fujita scale.
## Example Output
### Example Test Case 1: Display Tornadoes in 2022
**Input:**
`2022`

**Expected Output:**
`Year: 2022, Location: Morgan, Fujita Rating: F3, Wind Speed: 142.36 mph, Fatalities: 7
Year: 2022, Location: Lauderdale, Fujita Rating: F1, Wind Speed: 87.6 mph, Fatalities: 5
...`

### Example Test Case 2: Total Fatalities by Location
- Input: "Total fatalities in Lauderdale"
- Expected Output:
  `Total fatalities in Lauderdale: 16`

### Example Test Case 3: Average Wind Speed
- Input: "Average wind speed of all tornadoes"
- Expected Output:
`Average Wind Speed: 129.87 mph`

## Use Case
### Use Case: Tornado Risk Assessment
A local government wants to assess tornado risk and prepare emergency response plans. They need to know:
- The locations most affected by tornadoes.
- The average wind speeds to plan structural reinforcements.
- The total fatalities over the years to estimate potential future risks.

### Steps:
- The user can input a specific location (e.g., Lauderdale) and view the number of tornadoes, wind speeds, and total fatalities to assess the risk.
- By calculating average wind speeds, the government can plan for stronger building codes in high-risk areas.
- Historical fatality data can help allocate medical resources and establish evacuation protocols in regions with higher casualty rates.


