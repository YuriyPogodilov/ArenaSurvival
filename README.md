# Arena Survival Game

## Build

Raylib is built from source as a Git submodule. After cloning this repository, initialize it:

```powershell
git submodule update --init --recursive
```

Then configure and build with Visual Studio 2022:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
```

Run `build/Debug/ArenaSurvival.exe`, or use the build and debug tasks in `ArenaSurvival.code-workspace`.
