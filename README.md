CONNECT FOUR VS AI BOT (C++)
----------------------------

A console-based Connect Four game written in C++, featuring a human player
competing against an AI bot with scalable difficulty. The bot uses heuristic-
based offensive and defensive strategies to block opponent wins and build its
own Connect Four sequences.

This project demonstrates object-oriented design, algorithmic reasoning,
and practical debugging workflows.


FEATURES
--------
- Classic 6×7 Connect Four gameplay
- Human vs. AI
- Player color selection (Red or Yellow)
- Full win detection:
  - Vertical
  - Horizontal
  - Diagonal (\ and /)
- AI bot with 20 difficulty levels
- Lives-based progression system
- Deterministic, gravity-aware move validation


PROJECT STRUCTURE
-----------------
main.cpp
ConnectFour.h
ConnectFour.cpp
BotLogic.cpp


AI DESIGN
---------
The bot uses rule-based heuristics rather than brute-force search. As the
difficulty increases, additional strategies are enabled and prioritized.

Defensive Strategies:
- Blocks imminent wins vertically, horizontally, and diagonally

Offensive Strategies:
- Builds potential winning sequences in all directions


DIFFICULTY SCALING
------------------
Level 1–2:
- Random legal moves

Level 3–4:
- Vertical blocking

Level 5–6:
- Vertical and horizontal blocking

Level 7–8:
- Full blocking (including diagonals)

Level 9–12:
- Blocking with offensive building

Level 13–20:
- Optimized ordering of full blocking and offensive strategies


COMPILATION INSTRUCTIONS
---------------
Using a standard g++ compiler and enter the command: 
g++ main.cpp ConnectFour.cpp BotLogic.cpp -o connectfour
Then run the program by entering: 
./connectfour


DESIGN HIGHLIGHTS
-----------------
- Clean separation of game logic and AI logic
- Gravity-aware move validation
- Boundary-safe board traversal
- Readable and maintainable C++ codebase
- Deterministic AI suitable for debugging and extension
  

AUTHOR
------
Nephele Kay

