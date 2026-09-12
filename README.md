# gbdk-parallax-backgrounds
GBDK Parallax Backgrounds

## Requirements
- Windows 11 or Ubuntu 24.04
- GBDK-2020 >= 4.5.0
- CMake >= 4.2.1
- Ninja >= 1.13.2

**TIPS:**
- **Windows:** Use `winget` to install dependencies: `winget install cmake Ninja-build.Ninja`
- **Ubuntu:** Use apt to install dependencies: `sudo apt install cmake ninja-build`

## Build Instructions

### Prerequisites
Edit `CMakeLists.txt` and set `GBDK_HOME` to point to your extracted GBDK path.

Examples:
- **Windows:** Extract GBDK-2020 to `C:\gbdk` and set `set(GBDK_HOME "C:/gbdk")`
- **Ubuntu:** Extract GBDK-2020 to `~/gbdk` and set `set(GBDK_HOME "~/gbdk")`

### Quick Build

**Windows (PowerShell):**
```powershell
.\build.ps1
```

Optional flags:
- `-clean` - Clean build artifacts before building
- `-debug` - Build in debug mode

Example:
```powershell
.\build.ps1 -clean -debug
```

**Ubuntu (Bash):**
```bash
./build.sh
```

Optional flags:
- `--clean` - Clean build artifacts before building
- `--debug` - Build in debug mode

Example:
```bash
./build.sh --clean --debug
```

This will generate `rom.gb` in the `build` directory, which can be loaded into an emulator or flashcart.

### Manual Build
To build manually using CMake (works on both Windows and Ubuntu):

```bash
mkdir build
cd build
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release
ninja
cd ..
```

Use `-DCMAKE_BUILD_TYPE=Debug` for debug build.

## Generate Graphics Assets

To generate assets file from png we use png2asset, here are the commands we use:

```
C:\gbdk\bin\png2asset.exe FlappyBirdBackground.png -map -use_map_attributes
```

## Resources
- GBDK: https://github.com/gbdk-2020/gbdk-2020
- Aseprite: https://www.aseprite.org/
- png2asset Tutorial: https://laroldsretrogameyard.com/tutorials/gb/png2asset-graphics-creation-for-gbdk-2020
- Parallax Backgrounds Tutorial: https://laroldsretrogameyard.com/tutorials/gb/parallax-backgrounds-with-gbdk-2020/
