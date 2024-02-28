					Project - Mouse and Cheese Game
***********************************************************************
Written by: Itay Mijan 322295460
			Nir Busheri 206502569
***********************************************************************
This project implements a game where the player controls a mouse
trying to collect cheese while avoiding cats. The player wins by collecting
all the cheese and loses if the mouse collides with a cat and runs out of lives
or runs out of time.
The game is played on different levels loaded from a playlist file.

***********************************************************************
							Level Format
***********************************************************************
To create a new level:
	1. Add the name of the level to the file LevelPlaylist.txt.
	2. Create the level file with the same name in "resources".
	3. Create the level in the file:
		If you want time limit, put it in the first line, else put -2
		Then in the next line:
		The size can be whatever you'd like, but each row and col should be
		the same size, meaning:
		if we have a wall, we need to add spaces to the end of this line
		until all lines are of equal size, or add spaces below the wall,
		so all cols are the same size.
		You can also not put walls in the level and it will still work.
		We recommend the level size to be up to 25 rows and 40 cols.
	4. Add the level file to the CMakeLists.txt file like that:
	configure_file ("resources/<file_name>.txt" ${CMAKE_BINARY_DIR} COPYONLY)		


***********************************************************************
								FILES
***********************************************************************
		Header Files:
BackgroundTile.h - Header file for the background tile object
Board.h - Header file for the Board class that represents the game board
Button.h - Header file for the abstract class button that represents a clickable button
Cat.h - Header file for the Cat class representing the cat enemies
Cheese.h - Header file for the cheese object
Door.h - Header file for the door object
ExitButton.h - Header file for the exit button object
FreezeGift - Header file the gift that freezes cats
Game.h - Header file for the Game class controlling the game flow
GameManager.h - Header file for the class that runs the main window,
				UI, and the game
GameObject.h - Header file for the abstract class that represents an object in the game
Gift.h - Header file for the abstract class gift
Heart.h - Header file for the class that represents the sprite of a heart
HelpButton.h - Header file for the class that represents the help button in the UI
Key.h - Header file for the class that represents a key in the game
KillCatGift.h - Header file for the class that represents a gift to eliminate one cat
Level.h - Header file for the class that represents a level in the game
LifeGift.h - Header file for the class that represents a gift that gives more life
Menu.h - Header file for the class that represents a menu with buttons in the main window
Mouse.h - Header file for the Mouse class representing the player's mouse
MovingObject.h - Header file for the abstract class that represents a moving object in the game
PlayButton.h - Header file for the class play button that pressing on will start the game
SoundManager.h -Header file for the class that manages sound assets
States.h - Header file for the class that shows the status of the player and the level
StaticObject.h - Header file for the abstract class that represents a static game object
TexturManager.h - Header file for the class that manages texture assets
TimeGift.h -Header file for the class that represent a gift that gives more time
Utilities.h - Header file for the utility functions
Wall.h - Header file for the wall object in the game


		CPP Files:
Source Files:
BackgroundTile.cpp - Implementation file for the background tile object
Board.cpp - Implementation file for the Board class that represents the game board
Button.cpp - Implementation file for the abstract class button that represents a clickable button
Cat.cpp - Implementation file for the Cat class representing the cat enemies
Cheese.cpp - Implementation file for the cheese object
Door.cpp - Implementation file for the door object
ExitButton.cpp - Implementation file for the exit button object
FreezeGift.cpp - Implementation file for the gift that freezes cats
Game.cpp - Implementation file for the Game class controlling the game flow
GameManager.cpp - Implementation file for the class that runs the main window, UI, and the game
GameObject.cpp - Implementation file for the abstract class that represents an object in the game
Gift.cpp - Implementation file for the abstract class gift
Heart.cpp - Implementation file for the class that represents the sprite of a heart
HelpButton.cpp - Implementation file for the class that represents the help button in the UI
Key.cpp - Implementation file for the class that represents a key in the game
KillCatGift.cpp - Implementation file for the class that represents a gift to eliminate one cat
Level.cpp - Implementation file for the class that represents a level in the game
LifeGift.cpp - Implementation file for the class that represents a gift that gives more life
Menu.cpp - Implementation file for the class that represents a menu with buttons in the main window
Mouse.cpp - Implementation file for the Mouse class representing the player's mouse
MovingObject.cpp - Implementation file for the abstract class that represents a moving object in the game
PlayButton.cpp - Implementation file for the class play button that pressing on will start the game
SoundManager.cpp - Implementation file for the class that manages sound assets
States.cpp - Implementation file for the class that shows the status of the player and the level
StaticObject.cpp - Implementation file for the abstract class that represents a static game object
TextureManager.cpp - Implementation file for the class that manages texture assets
TimeGift.cpp - Implementation file for the class that represents a gift that gives more time
Utilities.cpp - Implementation file for the utility functions
Wall.cpp - Implementation file for the wall object in the game
main.cpp - Main function of the program

***********************************************************************
							Data Structures
***********************************************************************
distacneMatrix - The matrix of positions in the board 

***********************************************************************
							Algorithms
***********************************************************************


***********************************************************************
							Design
***********************************************************************
- Board: Represents the game board, including the mouse, cats, and cheese.
- Cat: Represents a cat enemy with movement and drawing capabilities.
- Game: Controls the overall game flow, including level loading and player input.
- Location: Simple struct representing a position on the game board.
- Mouse: Represents the player's mouse with movement, scoring, and life management.

***********************************************************************
							Known Bugs
***********************************************************************
None

***********************************************************************
							Other Comments
***********************************************************************
The game has been tested and is working correctly. Enjoy playing!
