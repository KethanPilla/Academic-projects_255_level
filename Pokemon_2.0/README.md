# Pokémon Battle Simulation
## PROBLEM:  
We are tasked with building a simple text-based game based on the Pokemon Universe, called PokemonLite.  In PokemonLite, the user/player starts off with a team of 6 Pokemon.  Likewise, there are six “wild” Pokemon in the environment that the player will have to (sometimes repeatedly) battle.  The game will be over once the player defeats (exhausts) all six(6) wild Pokemon. 

Game Play:  The player has three(3) main options.  
1. Battle!
2. Evolve
3. Quit

If the player selects Battle! he/she immediately enters into the battle arena.  More on the battle system for PokemonLite below.
If the player selects Evolve he/she will have the option to evolve one of their Pokemon.  Evolving a Pokemon costs three(3) coins.  Coins are gained by winning Pokemon battles.  If three coins are available, the player can select a Pokemon to evolve (increase level by one).  IMPORTANT: Pokemon can not increase beyond level 2 (level 0 is the lowest level).
If the player selects Quit, the game ends.

## Pokemon Types:
All Pokemon have one of five(5) types.  The following is a numbered list that details the types that are available in PokemonLite (incidentally, the internal system for keeping track of the various types uses integer values based on this numbered list).
1. Grass Poison (GP)
2. Fire (F)
3. Water (W)
4. Bug Normal (BN)
5. Bug Poison (BP)
   
## PokemonLite Battle System:
The following rules dictate who wins a battle between two Pokemon.  The rules are applied in numerical order until a clear winner is identified.
1. If one Pokemon is exhausted, it always loses the battle. (NOTE: only the wild Pokemon ever become exhausted in PokemonLite)
2. If one Pokemon is a higher level than the other, it will win.
3. If both Pokemon are the same level and neither is exhausted, then the type of Pokemon in the battle alone will determine which Pokemon wins.  See the chart below to see how outcomes are decided based on Pokemon type.  (For instance, Water defeats Fire, Fire defeats Grass Poison, Grass Poison defeats Water, etc.)

![pokemon](https://github.com/user-attachments/assets/016896ed-08f6-44b1-97af-37e6ecd6d350)

When a battle begins, a random Pokemon out of the six(6) wild Pokemon will be selected.  The player/user’s active Pokemon will remain from the last fight (or be the first Pokemon if no fight has yet occurred).  The specific Pokemon in play (by name) as well as their levels will be presented to the user.  The player/user has three(3) options: 
1. Fight! – the fight will be determined by the battle system described above.  If the user wins then he/she receives a coin and the wild Pokemon is exhausted.
2. Flee! - the player/user may choose not to fight and the gameplay continues.
3. Swap Pokemon - the player/user can choose to deactivate the current Pokemon and activate another one from their team.

These three options are repeated until the player either fights or flees.

## Overview
The Pokémon Battle Simulation project is a C++ application that simulates battles between Pokémon. It provides functionality to define different Pokémon, their stats (such as health, attack, and defense), and allows for turn-based combat between Pokémon. Players can choose Pokémon to battle and see the outcomes based on the stats and battle logic implemented in the program.

## Purpose
The purpose of this project is to:

- Create an interactive simulation where Pokémon can battle each other.
- Provide a detailed structure for defining Pokémon stats and abilities.
- Implement turn-based combat logic that determines the winner based on Pokémon attributes such as health, attack, and defense.
  
## Underlying Data Structures & Principles
1. Object-Oriented Programming (OOP):
Each Pokémon is represented as an object with attributes such as health, attack power, and defense. The Pokémon class encapsulates all related behaviors and properties.
2. Battle Logic:
The project implements turn-based combat where two Pokémon alternate attacks. The health of each Pokémon is reduced based on the attack and defense values, and the battle continues until one Pokémon's health reaches zero.

## Implementation
- Pokémon Class (Pokemon.h):
   - Represents individual Pokémon with attributes like health, attack power, defense, and name.
   - Contains methods to attack other Pokémon, reduce health based on incoming attacks, and check if a Pokémon has fainted.
     
- Methods Implementation (methods.cpp):
   - Implements the various functions and logic for the Pokémon battle, including attack resolution, health updates, and status checks.
     
- Main Program (main.cpp):
   - The main entry point of the program where the user can choose Pokémon, initiate battles, and view the battle outcomes.
     
## Files
- `Pokemon.h`: Defines the Pokémon class with its attributes (health, attack, defense) and methods (attack other Pokémon, reduce health).
- `methods.cpp`: Implements the battle logic between two Pokémon.
- `main.cpp`: Controls the flow of the program, including user input, battle initialization, and displaying results.
  
## Example Test Cases
### Test Case 1: Basic Pokémon Battle
**Operation**:
- Pokémon A (Health: 100, Attack: 25, Defense: 10) vs. Pokémon B (Health: 80, Attack: 20, Defense: 15).
  
**Expected Outcome**:
```
- Pokémon A attacks Pokémon B and reduces its health.
- Pokémon B attacks Pokémon A and reduces its health.
- The battle continues until one Pokémon faints (i.e., health reaches 0).
- The Pokémon with better stats will likely win the battle.
  ```
### Test Case 2: Pokémon with Higher Defense Wins
**Operation**:
- Pokémon A (Health: 100, Attack: 20, Defense: 30) vs. Pokémon B (Health: 100, Attack: 25, Defense: 10).
  
**Expected Outcome**:
```
- Pokémon A's higher defense helps it take less damage, leading to a win despite Pokémon B's higher attack.
  ```
### Test Case 3: One-Hit Knockout
**Operation**:
- Pokémon A (Health: 50, Attack: 50, Defense: 5) vs. Pokémon B (Health: 50, Attack: 5, Defense: 5).
  
**Expected Outcome**:
```
- Pokémon A defeats Pokémon B in a single hit due to the large difference in attack power.
  ```
### Test Case 4: Pokémon with Equal Stats
**Operation**:
- Pokémon A (Health: 100, Attack: 20, Defense: 20) vs. Pokémon B (Health: 100, Attack: 20, Defense: 20).
  
**Expected Outcome**:
```
- The battle is closely matched and could go either way, depending on the order of attacks.
```
## Use Case
### Use Case: Pokémon Battle Simulator for Training
This project can be used as a simple Pokémon battle simulator to test different battle outcomes based on Pokémon stats. Players or developers could:

- Simulate battles between Pokémon with different stat combinations to study how attack, defense, and health interact during battles.
- Create new Pokémon with custom stats and abilities to add more variety to the battle simulation.
- Use the simulator as a tool for learning about turn-based combat mechanics and balancing strategies in game development.
