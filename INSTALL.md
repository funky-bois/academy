Install Make && GCC on Windows

Overview
- Install MSYS2 via winget
- Update MSYS2 and install the MinGW-w64 64-bit toolchain (GCC)
- Add MinGW64 bin to PATH
- Install GNU Make (recommended: MSYS2’s make) or GnuWin32 Make via winget
- Verify installation

Steps

1) Install MSYS2
- In PowerShell (Run as Administrator):
```bash
winget install --id MSYS2.MSYS2 -e
```
- Launch MinGW64 shell:
```bash
C:\msys64\mingw64.exe
```

2) Update MSYS2 and install GCC (inside the Mingw64 shell)
- First full system update:
```bash
pacman -Syu
```
- If it asks to close the terminal after core updates, close the window, then reopen:
```bash
C:\msys64\mingw64.exe
```
- Update again to finish:
```bash
pacman -Syu
```
- Install the 64-bit GCC toolchain:
```bash
pacman -S --needed mingw-w64-x86_64-gcc
```
(Optional but recommended)
- Basic build tools:
```bash
pacman -S --needed mingw-w64-x86_64-make mingw-w64-x86_64-gdb mingw-w64-x86_64-pkg-config
```

3) Add MinGW64 to PATH (so gcc/make work in any Windows shell)
- Add the MinGW64 bin directory:
  - Path: C:\msys64\mingw64\bin
- PowerShell (current session):
```bash
$env:Path = "C:\msys64\mingw64\bin;$env:Path"
```
- Permanent (per-user):
```bash
[Environment]::SetEnvironmentVariable(
  "Path",
  "C:\msys64\mingw64\bin;" + [Environment]::GetEnvironmentVariable("Path", "User"),
  "User"
)
```
- Restart terminals/editors to pick up the change.

4) Install Make
Option A (recommended): MSYS2 MinGW Make
- Already installed if you ran the optional tools above:
  - Package: mingw-w64-x86_64-make
  - Command name: mingw32-make (you can alias to make if you want)

Option B: GnuWin32 Make via winget (command name: make)
- In PowerShell:
```bash
winget install GnuWin32.Make
```
Note: Prefer Option A to ensure Make uses the same environment as GCC. If you use GnuWin32 Make, ensure it appears after C:\msys64\mingw64\bin in PATH to avoid toolchain mismatches.

5) Verify
- In a new PowerShell or cmd:
```bash
gcc --version
g++ --version
mingw32-make --version
```
- If you installed GnuWin32 Make:
```bash
make --version
```

Tips
- Use C:\msys64\mingw64.exe for a consistent MinGW64 environment.
- For CMake-based projects, also install:
```bash
pacman -S --needed mingw-w64-x86_64-cmake ninja
```
- If pacman warns about keyrings, run:
```bash
pacman-key --init
pacman-key --populate msys2
pacman -Syu
```
