# Magic 8 Ball Project
## Overview
This project implements a simple Magic 8 Ball game, which randomly provides a response to user questions. The responses are divided into two categories: positive and negative, each with predefined answers.

The project consists of the following files:

- driver.cpp: The main code that runs the Magic 8 Ball simulation.
- Magic8Ball.h: A header file defining the core structure and functionality of the Magic 8 Ball.
- positive.txt: Contains positive responses.
- negative.txt: Contains negative responses.
## How the Code Works
### Data Input:

- The program reads positive responses from positive.txt and negative responses from negative.txt.
- Positive and negative responses are stored in separate lists or arrays.
### Main Operation:

- The user asks a yes/no question.
- The Magic 8 Ball randomly selects either a positive or negative response and outputs it.
- Responses are chosen randomly from the respective lists of responses.
### Response Categories:

- Positive Responses: Stored in positive.txt and include answers like "Yes, definitely" and "Outlook good"​(positive).
- Negative Responses: Stored in negative.txt and include answers like "Don't count on it" and "My reply is no"​(negative).
## Example Output
### Example Test Case 1: Positive Response
**Input**: "Will I get a promotion?"

**Random Output**: `It is certain`

### Example Test Case 2: Negative Response
**Input**: "Is it going to rain tomorrow?"

**Random Output**: `Outlook not so good`

### Example Test Case 3: Uncertain Response
**Input**: "Should I invest in stocks?"

**Random Outpu**t: `Reply hazy, try again`
