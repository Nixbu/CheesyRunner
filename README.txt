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
distacneMatrix - The matrix of positions in the board, used in the
				 cat movement algorithm

***********************************************************************
							Algorithms
***********************************************************************
Cat Movement - The cat's movement is determined from this algortihm:
				We implemented a dynamic programming solution,
				calaulating the distance matrix from the mouse using
				the BFS graph algorithm to move breadth-wise on the board
				from the source - the player.
				Then, each cat chooses his wanted direction based on
				choosing the minimal distance to the player from his
				surrounding up, down, left and right tiles in the matrix.
				This allows for a quick and efficient movment,
				while also calculating the distance matrix once every
				loop.
Background Tiles - The background of the level is chosen randomly
					from a given set of tiles, to create a more
					diverse background.
Gifts - The gifts in the game are chosen randomly while also maintaining
		the condition that an "Eliminate cat gift" is only one in a level,
		and also if there is no time limit in the level, there won't be 
		"Time gifts".

***********************************************************************
							Design
***********************************************************************
- Board: Represents the game board, containing the static game objects.
- Button: Represents a button in the main UI, abstract class.
- Cat: Represents a cat enemy, inherits from MovingObject.
- Cheese: A static object representing a cheese in the game,
			the mouse eats it.
- Door: A static object representing a door in the game - the mouse can open it
		if he has keys.
- ExitButton: A button for exiting the game, inherits from Button.
- FreezeGift: A gift that freezes the cats for a period of time, inherits from Gift.
			The mouse can take it.
- Game: Controls the overall game flow, including level loading and player.
- GameManager: The class that represents the whole program, including the UI menu,
				and the ability to start the game, provide textures and sounds,
				and interact with the buttons.
- Gift: An abstract class that represents a gift in the game. All gifts inherit
		from it.
- Heart: A class for the heart sprite shown in the status bar.
- HelpButton: A button to get the instructions of the game, inherits from Button.
- Key: A static object representing a key in the game - the mouse can take it
		to open doors.
- KillCatGift: A gift that eliminates one of the cats in the game, the
				mouse can take it, inherits from Gift.
- Level: A class that represents level in the game, loading the board, the states,
		and the cats.
- LifeGift: A gift that gives the mouse 1 more life. Only up to 3 lives.
			Inherits from Gift. The player can take it.
- Menu: The menu containing all the buttons. The user can interact with it.
- Mouse: Represents the player's mouse with movement, scoring, 
		and life management.
- MovingObject: The abstract class represents a moving object, the
				mouse and the can inherit from it. Inherits from GameObject.
- PlayButton: A button that by clicking on it initiates the game,
			 inherits from Button.
- SoundManager: A class containing the sound assets of the game.
- States: A class that represents the status bar of the level.
- StaticObject: An abstract class representing a static object in the game,
				inherits from GameObject.
- TextureManager: A class containing the texture assets for the game.
- TimeGift: A gift that gives the player more time in time limited levels.
- Wall: A static object in the game representing a wall, the cat and mouse 
		interact with it.

***********************************************************************
							Known Bugs
***********************************************************************
In some occasions the cat is drawn on a wall or moves in a digaonal on
the wall, we don't know why.

***********************************************************************
							Other Comments
***********************************************************************
All the levels we created are able to run in fullscreen,
but can also be run not as full screen. If you want to create a new
level we can not gurantee that it will look good in full screen.
Enjoy playing!
