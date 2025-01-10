# cub3D

## Overview
cub3D is a graphical project aimed at implementing a first-person 3D maze exploration game using ray-casting principles. Inspired by classic games like Wolfenstein 3D, this project offers a hands-on opportunity to explore and apply mathematics, system-level programming, and graphics handling in C.

By adhering to the constraints of the miniLibX library and other guidelines, the project emphasizes rigorous programming, clean code practices, and efficient algorithm design.

## Features
### Mandatory Part
- **3D Rendering**: Implements ray-casting to create a realistic 3D visualization of a maze.
- **Textures**: Supports wall textures for different sides (North, South, East, West).
- **Colors**: Configurable floor and ceiling colors.
- **Keyboard Controls**:
  - `W`, `A`, `S`, `D`: Move the player's point of view.
  - Left/Right Arrow Keys: Rotate the player's view.
  - `ESC`: Exit the program.
- **Window Management**: Smoothly handles window minimization, resizing, and switching.
- **Error Handling**: Properly handles errors like map misconfigurations or invalid inputs.
- **Configurable Scenes**:
  - Accepts a `.cub` file containing the maze layout and texture/color configurations.
  - Validates maps to ensure they are closed and adhere to the required format.

### Bonus Part
- **Wall Collisions**: Prevents the player from moving through walls.
- **Minimap**: Displays a top-down view of the maze.
- **Doors**: Adds doors that can open and close within the maze.
- **Animated Sprites**: Supports animated elements in the environment.
- **Mouse Control**: Allows point-of-view rotation using the mouse.

## Getting Started

### Prerequisites
- A Linux-based environment.
- The miniLibX library.
- A C compiler supporting `-Wall`, `-Wextra`, and `-Werror` flags.

### Installation
1. **Extract miniLibX**:
   ```bash
   tar -xzf minilibx-linux.tgz
   ```
2. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   cd cub3D
   ```

### Running the Project
#### Mandatory Part
1. Compile the mandatory part:
   ```bash
   make
   ```
2. Run the program with a valid `.cub` file:
   ```bash
   ./cub3D maps/valid.cub
   ```

#### Bonus Part
1. Navigate to the bonus directory:
   ```bash
   cd bonus
   ```
2. Compile the bonus part:
   ```bash
   make
   ```
3. Run the program with a valid `.cub` file:
   ```bash
   ./cub3D maps/map.cub
   ```

### Map File Format
- **Allowed Characters**:
  - `0`: Empty space
  - `1`: Wall
  - `N`, `S`, `E`, `W`: Player's starting position and orientation
- **Configuration Elements**:
  - `NO`: Path to the north wall texture
  - `SO`: Path to the south wall texture
  - `WE`: Path to the west wall texture
  - `EA`: Path to the east wall texture
  - `F`: Floor color in `R,G,B` format
  - `C`: Ceiling color in `R,G,B` format

#### Example Map File
```txt
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
111111
100001
1010N1
100001
111111
```

## What I Learned
1. **Ray-Casting**: Implementing the core logic for rendering a 3D scene from a 2D map.
2. **Graphics Programming**: Handling windows, events, and image rendering with miniLibX.
3. **Mathematics**: Applying trigonometry and linear algebra to calculate distances and angles.
4. **Error Handling**: Designing robust input parsing and validation for `.cub` files.
5. **Memory Management**: Avoiding leaks and ensuring all dynamically allocated memory is freed.

## Challenges Overcome
- **Map Parsing**: Validating and parsing maps with spaces and ensuring they are closed.
- **Wall Textures**: Ensuring proper alignment and scaling of textures based on the player's view.
- **Performance Optimization**: Maintaining smooth rendering even with complex maps.

## Common Issues
If the program fails to run, check:
- That miniLibX is correctly installed.
- That the `.cub` file is properly formatted.
- For errors during compilation (ensure all prerequisites are met).

## Resources
- [Wolfenstein 3D](http://users.atw.hu/wolf3d/) for inspiration.
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Ray-Casting Tutorial](https://lodev.org/cgtutor/raycasting.html)

---

Thank you for checking out this project! Feel free to contribute or report any issues via GitHub.
