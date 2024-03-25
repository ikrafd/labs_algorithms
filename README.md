# pa-ishchenko-kir

## For work with program:
 1) To clone a repo
 2) To open a developer command prompt for VS 2022 (or your version of VS)
 3) To go to a project directory using cd command. For example, 
```{}
cd D:\cpp\pa-ishchenko-kir\src
```
  3.5. If you should change a directory like C to D use 
```{}
cd /d D:\cpp\pa-ishchenko-kir\src
```
 4) To build a project using msbuild command. For example, 
```{}
msbuild Labs.sln /p:Configuration=Debug
```
 5) To go to the directory with .exe file using cd command. For example,
```{}
 cd LabX\scr\x64\Debug
```
where X - number of lab

8) To run .exe file by typing its name. For example, ```FirstLab.exe```

## For running unit tests:
 1) To do first four steps from the previous section
 2) To go to the directory with .exe file using cd command. For example,
```{}
 cd LabX\tests\LabX.Tests\x64\Debug
```
where X - number of lab

3) To run unit tests using FirstLabTest.exe command followed by typing their name.  For example, 
```{}
vstest.console.exe Lab1.Tests.dll
```
