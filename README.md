![Score](https://img.shields.io/badge/Score-93.1%25_C-lightgrey) ![Makefile](https://img.shields.io/badge/Makefile-6.9%25-lightgrey)

# so_long

> *A tiny 2D game project with MiniLibX*  
> *Escape the map after collecting all items*

---

## Table of Contents

* [About 📌](#about)
* [Setup 🛠️](#setup)
* [Rules 📖](#rules)
* [Game 🎮](#game)
* [Graphics 🖼️](#graphics)
* [Map 🗺️](#map)
* [Bonus 🏆](#bonus)
* [Example 📸](#example)

---

## About 📌

**so_long** is a small 2D game built with **MiniLibX** where you create a map, place a player, collectibles, and an exit.  
The goal: **collect all items and reach the exit** while respecting strict parsing and rendering rules.  

This project improves skills in:  
* Window management and event handling  
* Parsing map files  
* Graphics rendering with MiniLibX  
* Clean code, memory handling, and C rigor  

---

## Setup 🛠️

1. **Language**: C (no globals, respect the 42 Norm).  
2. **Makefile**: Must include rules `$(NAME)`, `all`, `clean`, `fclean`, `re` (and `bonus` if implemented).  
3. **Compiler flags**: `-Wall -Wextra -Werror`, compiler `cc`.  
4. **Libft**: Allowed — copy sources into `libft/` and compile from your project’s Makefile.  
5. **Libraries**: MiniLibX (mandatory), `math` (`-lm`), `gettimeofday()`, and your own `ft_printf`.  

---

## Rules 📖

* The game must open a window and display the map.  
* Player moves with **WASD** (or arrows).  
* Player **cannot walk through walls**.  
* Each move increments a counter displayed in the shell.  
* The game must close cleanly on:  
  - Pressing `ESC`  
  - Clicking the window close button  

---

## Game 🎮

* **Goal**: Collect all collectibles (`C`) then escape through the exit (`E`).  
* **Controls**:  
  - `W` → up  
  - `A` → left  
  - `S` → down  
  - `D` → right  
* Must use a **2D view** (top-down or profile).  
* Not required to run in real-time.  

---

## Graphics 🖼️

* Display must use MiniLibX images.  
* Window must behave normally (minimize, switch focus).  
* Proper exit handling when closing the window or pressing `ESC`.  

---

## Map 🗺️

* Maps use the `.ber` extension.  
* Valid characters:  
  - `0` → empty space  
  - `1` → wall  
  - `C` → collectible  
  - `E` → exit  
  - `P` → player start  
* **Rules**:  
  - 1 exit (`E`)  
  - 1 start position (`P`)  
  - ≥ 1 collectible (`C`)  
  - Must be rectangular and fully surrounded by walls  
  - Must have a valid path from `P` → all `C` → `E`  
* Errors: Print `"Error\n"` followed by a message.  

**Example map**:  

