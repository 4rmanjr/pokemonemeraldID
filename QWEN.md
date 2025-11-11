# pokeemerald-expansion Project Context

## Project Overview
pokeemerald-expansion is a comprehensive GBA ROM hack base that provides developers with a toolkit for creating Pokémon ROM hacks. It's built on top of pret's pokeemerald decompilation project and is not a playable Pokémon game on its own, but rather a development framework. The project includes hundreds of features from various core series Pokémon games and quality-of-life enhancements.

## Architecture & Technologies
- **Base**: Built on the `pret/pokeemerald` decompilation
- **Target Platform**: Game Boy Advance (GBA)
- **Language**: C (for game logic), Assembly (for low-level operations)
- **Build System**: GNU Make with custom toolchain requirements
- **Toolchain**: Requires arm-none-eabi-gcc for compilation

## Key Features
- **Upgraded Battle Engine**: Supports modern Pokémon mechanics including Mega Evolution, Z-Moves, Dynamax, Gigantamax, Terastallization, critical captures, and more
- **Full Trainer Customization**: Compatible with Pokémon Showdown's team syntax, with support for custom Pokémon data, moves, abilities, etc.
- **Updated Pokémon Data**: Includes DS-style sprites, updated breeding mechanics, expanded species data
- **Interface Improvements**: Enhanced party menu, HGSS-style Pokédex, summary screen improvements
- **Overworld Improvements**: Day/Night system, overworld followers, NPC followers, BW map pop-ups
- **Developer Tools**: Integrated testing system, debug menus, battle debug tools, sprite visualizer

## Directory Structure
```
├── asm/           # Assembly source files
├── constants/     # Constant definitions 
├── data/          # Game data files
├── docs/          # Documentation
├── graphics/      # Graphic assets
├── include/       # Header files
├── libagbsyscall/ # AGB system call library
├── sound/         # Audio assets
├── src/           # C source files
├── test/          # Test files
├── tools/         # Build tools and utilities
└── ...
```

## Building and Running

### Prerequisites
- Linux, macOS, or WSL2 (recommended) for building
- ARM cross-compiler toolchain (arm-none-eabi-gcc, ld, objcopy)
- Python 3 for various scripts
- Various build tools (make, bash, etc.)

### Build Commands
```bash
# Clone the repository (do NOT use GitHub's download zip option)
git clone https://github.com/rh-hideout/pokeemerald-expansion
cd pokeemerald-expansion

# Build the project
make

# Build with parallel jobs for faster compilation
make -j$(nproc)  # On Linux
make -j$(sysctl -n hw.ncpu)  # On macOS

# Build with debug information
make debug

# Run tests
make check
```

### Output
- `pokeemerald.gba` - The compiled GBA ROM
- `pokeemerald.elf` - The linked executable (for debugging)

## Development Conventions

### Code Structure
- **C files**: Located in `src/` directory
- **Header files**: Located in `include/` directory
- **Assembly files**: Located in `asm/` directory
- **Data files**: Located in `data/` directory

### Configuration System
The project uses an extensive configuration system with header files in `include/config/`:
- `ai.h` - AI configuration
- `battle.h` - Battle engine configuration
- `general.h` - General project settings
- `pokemon.h` - Pokémon data configuration
- `overworld.h` - Overworld features configuration
- And many more specific configuration files

### Project-Specific Defines
- `MODERN=1` - Indicates modern build target
- `TESTING=$(TEST)` - Indicates test build mode

### Testing
The project includes an integrated testing system that can be run with `make check`. The testing system uses the `mgba` emulator to validate functionality.

## Key Source Files
- `src/main.c` - Main entry point
- `src/overworld.c` - Overworld game logic
- `src/battle_main.c` - Battle system implementation
- `src/pokemon.c` - Pokémon data handling
- `src/field_player_avatar.c` - Player movement and interaction
- `include/global.h` - Main game data structures
- `include/constants/` - Various constant definitions

## Contributing Guidelines
- Pull requests should target either `master` (for bug fixes) or `upcoming` (for new features)
- Contributions must be in scope as defined in the documentation
- Code should follow existing project patterns and style
- Changes must pass the build and test system
- Feature requests and bug reports should be made through GitHub Issues

## Community
- Discord server: ROM Hacking Hideout (RHH)
- Official documentation: https://rh-hideout.github.io/pokeemerald-expansion/