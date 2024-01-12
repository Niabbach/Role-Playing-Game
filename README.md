# Adventure Game

## Introduction
This project implements a simple text-based adventure game in C++. The game includes characters like the player's hero, friendly NPCs (Lambda), and various monsters (Serpent, Renard, Fee, Centaurus). The player can explore different environments, engage in combat, and make decisions to progress through the game.

## File Structure
- **main.cpp:** The main entry point of the program. It orchestrates the game loop, character interactions, and combat sequences.
- **fonction.h:** Header file containing function declarations for various game-related functions.
- **ElementDecor.h:** Header file defining decorative elements used in the game world (Maison, Arbre, Escargot, Pierre).
- **Personnage.h:** Header file defining the base class `Personnage` and its derived classes representing characters in the game (Hero, Lambda, Serpent, Renard, Fee, Centaurus).

## Classes
### Personnage Class
- Base class for all characters in the game.
- Attributes: PV (Health Points), Force (Strength), VIT (Vitality), nb_potion (Number of Health Potions), message (Action messages), nom (Name).
- Member Functions: Affiche (display character visuals), donner_coup (attack), prendre_coup (receive damage), win (update attributes after winning), fuite (attempt to flee), soin (use a health potion).

### Derived Classes
1. **Hero Class**
   - Represents the player's character.
   - Inherits from Personnage.
   - Custom attributes and visuals.

2. **Lambda Class**
   - Represents a friendly NPC providing guidance.
   - Inherits from Personnage.
   - Custom attributes and visuals.

3. **Monstre Class**
   - Abstract base class for monsters.
   - Inherits from Personnage.
   - Declares the autocombat function for automatic combat behavior.

4. **Serpent, Renard, Fee, Centaurus Classes**
   - Derived from Monstre.
   - Specific implementations for each monster type, including visuals and autocombat behavior.

## How to Play
1. Compile the code using a C++ compiler (e.g., g++).
2. Run the executable.
3. Follow on-screen prompts and instructions to navigate through the game.
4. Engage in combat, make decisions, and explore the game world.

## Contributing
Feel free to contribute to the project by suggesting improvements, fixing bugs, or adding new features. Create a pull request with your changes.
