# RatInject
Rat Inject is C++ Executable to gain Undetectable Persistence in Windows via 4 Registry Keys 

# How Works?

This tool gains persistence of an executable in Windows by exploiting 4 different internal Windows registries:

- RunKey
- WinLogon
- Image File Execution Options (Open)
- Image File Execution Options (Close)

**Runkey:**

**WinLogon:**

**Image File Execution Options (Open):**

**Image File Execution Options (Close):**

# Compile

To compile this you need to execute this command in Linux machine:

x86_64-w64-mingw32-g++ persistence.cpp -o ratinject.exe -static-libstdc++ -static-libgcc -fpermissive

![image](https://user-images.githubusercontent.com/79543461/204348350-3f271288-daea-4dc5-aee4-882e143802b4.png)

# Use
