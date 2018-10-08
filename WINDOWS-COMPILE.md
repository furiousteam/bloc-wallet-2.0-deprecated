#Windows compiling of BLOC wallet

This is a tested compilation process that you can run yourself. In the end you will have the Windows [BLOC wallet](https://bloc.money) updated to the latest version.

## Requirements

In the parenthesis are each program version I was using for a successful compilation.

* Windows 7 x64 with SP1
* [GIT Installed](https://git-scm.com/download/win) (2.13.0)
* [QT Installed](https://download.qt.io/archive/qt/) (5.9.1)
* [libBoost](https://www.boost.org/users/download/) (1.64.0 msvc-14.1 x64)
* [cmake](https://cmake.org/download/) (3.10.2 x64)
* [Microsoft Visual Studio](https://visualstudio.microsoft.com/downloads/) (Community 2017)
* [Visual C++ Redistributable for Visual Studio](https://www.microsoft.com/en-us/download/details.aspx?id=48145) (2015)

## Notes

In my build, I was using the following paths:

* to download the BLOC wallet `d:\bloc.money`.
* QT installation directory `d:\Qt5.9.1`
* libBoost installation directory `d:\boost_1_64_0`

Correct these according to your programs folder path.

## Create the solution

Open a command line (CMD) and run

```
d:
mkdir d:\bloc.money
cd d:\bloc.money
git clone https://github.com/furiousteam/bloc-wallet.git bloc-wallet
cd bloc-wallet
```

This will clone the BLOC wallet into `d:\bloc.money\bloc-wallet` folder

```
mkdir cryptonote
git clone -b master --single-branch https://github.com/furiousteam/BLOC.git cryptonote
```

This will clone the BLOC core into `d:\bloc.money\bloc-wallet\cryptonote` folder. The compilation process will need the core files from [BLOC core](https://github.com/furiousteam/BLOC.git)

```
mkdir build
cd build
cmake -DPORTABLE=1 -Wno-dev -DCMAKE_PREFIX_PATH="d:\Qt5.9.1\5.9.1\msvc2015_64" -DBOOST_ROOT="d:\boost_1_64_0" -DBOOST_INCLUDEDIR="d:\boost_1_64_0\lib64-msvc-14.1" -DBOOST_LIBRARYDIR="d:\boost_1_64_0\libs" -G "Visual Studio 15 Win64" ..
```

## Build the solution

* Open project (.sln file) in Visual Studio from `d:\bloc.money\bloc-wallet\build`
* Change Debug to Release from the dropdown below the Team-Tools menu
* Right click on Rocksdb -> Properties-> C/C++ -> Code Generation -> Runtime Library to /MD — APPLY & SAVE
* Right click on Rocksdb -> Build (~12 min)
* Right click on ALL_BUILD -> Build (~40 min)

The build solution needs to work without any error. If you are getting errors, the build will NOT work for you. Correct these errors, and rebuild before moving onto the next step.

## Deploy the binaries

This will add all the necessary libraries for BLOC wallet to make it distributable. Of course, you are still going to need the "Visual C++ Redistributable for Visual Studio" installed.

```
cd d:\Qt5.9.1\5.9.1\msvc2015_64\bin
windeployqt.exe d:\bloc.money\bloc-wallet\build\Release\
```

Now you can zip the folder `d:\bloc.money\bloc-wallet\build\Release\`. These are the compiled binaries.

## Re-building the solution after a BLOC wallet update

```
cd d:\bloc.money\bloc-wallet
d:
git pull origin master

cd cryptonote
git pull origin master

cd build
cmake -DPORTABLE=1 -Wno-dev -DCMAKE_PREFIX_PATH="d:\Qt5.9.1\5.9.1\msvc2015_64" -DBOOST_ROOT="d:\boost_1_64_0" -DBOOST_INCLUDEDIR="d:\boost_1_64_0\lib64-msvc-14.1" -DBOOST_LIBRARYDIR="d:\boost_1_64_0\libs" -G "Visual Studio 15 Win64" ..
```

Now run the steps from **Build the solution**.
