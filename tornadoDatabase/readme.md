# tornadoDatabase
## Purpose
This project processes tornado data from a file and provides statistics on tornado occurrences. The data includes year, location, Fujita 
scale rating, wind speed, and fatalities. The program allows users to analyze and extract useful information from the data, such as sorting 
and filtering based on different parameters.
## How the Code Works
### Data Input:
- The program reads tornado data from a file (tornado.txt). Each line in the file contains:`Year, Location, Fujita Rating, Wind Speed (mph), Fatalities`
### Data Processing:

The data is loaded into objects, each representing a tornado record. The program uses a class defined in Tornado.h to structure this data.
Core Operations:

- Sorting: Sorts tornado data by year, Fujita rating, wind speed, or number of fatalities.
- Filtering: Filters tornadoes by specific criteria, such as a given year or Fujita rating.
- Statistics: Computes statistics like total fatalities in a specific location, average wind speed, etc.
## Example Output
### Sample Data (tornado.txt):
``2022, Morgan, F3, 142.36, 7
2022, Lauderdale, F1, 87.6, 5
2021, Madison, F4, 178.29, 6``

### Example Test Case 1: Average Wind Speed Calculation
- Input: Tornadoes from tornado.txt are loaded.
- Operation: Calculate the average wind speed of all tornadoes.
- Output: ```Average Wind Speed: 135.42 mph```
### Example Test Case 2: Filter by Fujita Rating F4
- Input: Filter tornadoes with Fujita rating F4 from the tornado.txt data.
- Output: ```Year: 2021, Location: Madison, Wind Speed: 178.29 mph, Fatalities: 6```
### Example Test Case 3: Total Fatalities in Lauderdale
- Input: Compute the total number of fatalities for all tornadoes in Lauderdale.
- Output: ```Total Fatalities in Lauderdale: 16```
