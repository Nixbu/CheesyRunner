	                          	Exercise 2 - Mouse and Cheese Game
***********************************************************************
Written by: Itay Mijan 322295460
			Nir Busheri 206502569
**********************************************************************

This program is a level designer for a cat and mouse game.
It allows users to create custom game levels by placing different objects
on the board, such as the cat, mouse, walls, cheese, and more.

***********************************************************************
								FILES
***********************************************************************
		Header Files:
			- Board.h: Defines the Board class, representing the drawing board.
			- Button.h: Defines the Button class, representing a clickable button.
			- LevelDesigner.h: Defines the LevelDesigner class, representing
			the entire level designer program.
			- Location.h: Defines the Location struct, representing a location on the board.
			- Menu.h: Defines the Menu class, representing the menu of the level designer.
			- Rectangle.h: Defines the Rectangle class, representing a rectangle.
			- Row.h: Defines the Row class, representing the data structure vector.
			- Settings.h: Contains global variables of the program.
			- TextureManager.h: Defines the TextureManager class, containing loaded textures.
			- Tile.h: Defines the Tile class, representing a tile on the drawing board.

		CPP Files:
			- Board.cpp: Implements functions for the Board class.
			- Button.cpp: Implements functions for the Button class.
			- LevelDesigner.cpp: Implements functions for the LevelDesigner class.
			- main.cpp: Main program file for running the level designer.
			- Menu.cpp: Implements functions for the Menu class.
			- Rectangle.cpp: Implements functions for the Rectangle class.
			- Row.cpp: Implements functions for the Row class.
			- Tile.cpp: Implements functions for the Tile class.
			- Settings.cpp: Contains global variables implementation.
			- TextureManager.cpp: Implements functions for the TextureManager class.

***********************************************************************
							Data Structures
***********************************************************************
- Location: Represents a location on the board.
- Rectangle: Represents a rectangle.
- Row: Represents a vector of tiles.
- Tile: Represents a tile on the drawing board.

***********************************************************************
							Algorithms
***********************************************************************
- Board::act(): Places the selected tile on the board at the mouse's position.
- Board::floating(): Handles the floating effect of a selected tile on the board.

***********************************************************************
							Design
***********************************************************************
The program follows an object-oriented design with classes representing
different components of the game. The main classes include Board, Button,
LevelDesigner, Menu, Rectangle, Row, Settings, TextureManager, and Tile.

The format of the created board is as follows:
% - mouse
^ - cat
# - wall
* - cheese
$ - gift
D - door
F - key
'space' - empty 

The level will be rectangle shaped, meaning all the rows will be the 
same length and all the coloumns will be the same height.
***********************************************************************
							Known Bugs
***********************************************************************
None

***********************************************************************
							Other Comments
***********************************************************************
It is best to choose a size up to 22X22 because more than that will 
be bigger than the screen (in our screen), but it will still work 
otherwise.

Enjoy :)
