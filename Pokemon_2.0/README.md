## PROBLEM:  
We are tasked with building a simple text-based game based on the Pokemon Universe, called PokemonLite.  In PokemonLite, the user/player starts off with a team of 6 Pokemon.  Likewise, there are six “wild” Pokemon in the environment that the player will have to (sometimes repeatedly) battle.  The game will be over once the player defeats (exhausts) all six(6) wild Pokemon.    
I. Game Play:  The player has three(3) main options.  
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
4.Bug Normal (BN)
5. Bug Poison (BP)
   
## III. PokemonLite Battle System:
The following rules dictate who wins a battle between two Pokemon.  The rules are applied in numerical order until a clear winner is identified.
1. If one Pokemon is exhausted, it always loses the battle. (NOTE: only the wild Pokemon ever become exhausted in PokemonLite)
2. If one Pokemon is a higher level than the other, it will win.
3. If both Pokemon are the same level and neither is exhausted, then the type of Pokemon in the battle alone will determine which Pokemon wins.  See the chart below to see how outcomes are decided based on Pokemon type.  (For instance, Water defeats Fire, Fire defeats Grass Poison, Grass Poison defeats Water, etc.)

