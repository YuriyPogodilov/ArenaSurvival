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

## Tests

Tests use doctest v2.4.11, downloaded by CMake during the first configure
(requires Git and network access). Testing is enabled by default.

```powershell
cmake -S . -B build
cmake --build build --config Debug --target ArenaSurvivalTests
ctest --test-dir build -C Debug --output-on-failure
```

Add test sources to `ArenaSurvivalTests` in `tests/CMakeLists.txt`.
Each doctest test case is registered automatically with CTest.
To configure without tests or downloading doctest, use
`cmake -S . -B build -DBUILD_TESTING=OFF`.

## Code style

Open `ArenaSurvival.code-workspace` with the Microsoft C/C++ extension installed.
C++ files format on save using `.clang-format`: tabs with a width of four,
attached braces, and a 100-column limit. Short inline member functions may remain
on one line. Adjust `.clang-format` to define further brace exceptions.

Enable the version-controlled pre-commit hook once per clone:

```powershell
git config --local core.hooksPath .githooks
```

The hook checks staged `.cpp`, `.h`, and `.hpp` files under `src`, including
subdirectories. It checks formatting without changing files or staging changes.
After a failure, format the file and stage the intended changes again.
Third-party libraries are excluded.

The hook requires `clang-format` on PATH or Visual Studio's bundled LLVM.
Set the `CLANG_FORMAT` environment variable to an executable path to override
discovery. The initial formatting was generated with clang-format 19.1.5;
use the same version for consistent results. VS Code uses the C/C++ extension's
formatter by default; set `C_Cpp.clang_format_path` to the same executable if
its bundled version produces different formatting.

Formatting rules do not check naming conventions or program correctness.
