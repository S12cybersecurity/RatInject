# RatInject
Rat Inject is C++ Executable to gain Undetectable Persistence in Windows via 4 Registry Keys 

# How Works?

This tool gains persistence of an executable in Windows by exploiting 4 different internal Windows registries:

- RunKey
- WinLogon
- Image File Execution Options (Open)
- Image File Execution Options (Close)

**Runkey:**

Run Register, this register are one of the most important in Windows system, this register is execute many times during operation, but especially when you start the machine.

**WinLogon:**

Winlogon is a Windows component which handles various activities such as the Logon, Logoff, loading user profile, shutdown, lock screen... This execute your exe every time than user Logon, Logoff, loading user profile during authentication, shutdown, lock screen and more...

**Image File Execution Options (Open):**

This way allow you to execute your binary when user open any defined process or binary. In this case i cexecute exe when user open calc.exe process.

**Image File Execution Options (Close):**

This way allow you to execute your binary when user close any defined process or binary. In this case i execute exe when user finish explorer.exe process.

# Compile

To compile this you need to execute this command in Linux machine:

x86_64-w64-mingw32-g++ persistence.cpp -o ratinject.exe -static-libstdc++ -static-libgcc -fpermissive

![image](https://user-images.githubusercontent.com/79543461/204348350-3f271288-daea-4dc5-aee4-882e143802b4.png)

# Use

To use this tool you have to execute the command with its parameters as follows:

Ways:

- Winlogon
- Run
- Open
- Close



Recommended:

**ratinject.exe C:\temp\shell.exe Run Open Close**

Winlogon can create bugs in OS.



All Ways (shell.exe is evil file to execute with persistence (absolut path)):

**ratinject.exe C:\temp\shell.exe All**



Only One:

**ratinject.exe C:\temp\shell.exe Winlogon/Run/Open/Close**



Or mix (example, you can use all possible mixes):

**ratinject.exe C:\temp\shell.exe Run Open Close**

