<h1 align="center">
  <br>
  <a href="https://bloc.money" target="_blank"><img src="https://user-images.githubusercontent.com/1941393/40306571-73d3c700-5cff-11e8-8a75-9f1498106e27.png" alt="BLOC" width="350"></a>
  <br>
  BLOC
  <br>
</h1>

<h4 align="center">A secure, private, decentralized, egalitarian, fungible, fast <a href="https://bloc.money" target="_blank">cryptocurrency</a>.</h4>

<p align="center">
  <a href="https://www.gnu.org/licenses/gpl-3.0">
    <img src="https://img.shields.io/badge/License-GPL%20v3-blue.svg"
         alt="License: GPL v3">
  </a>
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#download">Download</a> •
  <a href="#related">Related</a> •
  <a href="#license">License</a>
</p>

![capture d ecran 2018-05-21 a 20 31 32](https://user-images.githubusercontent.com/1941393/40323555-fbfe5e48-5d35-11e8-9c6f-ea68c1b314bb.png)

## Key Features

* Decentralized
* True egalitarian Proof of Work
* Secure
* Private
* Untraceable
* Transparent
* Fast transactions speeds
* Fungible
* Double spending protection

The [BLOC.money](https://bloc.money) is the new digital cash powered by an open-source blockchain with anonymous transactions including exclusive mining tools which provide a true egalitarian money distribution. Everybody can earn passive income while sleeping or just anywhere, anytime by simply using a mobile phone.

Our Proof Of Work algorithm is designed to make low end and high end hardware mining roughly equally efficient and restrict ASIC mining.

## How to Use

To clone and build the BLOC core, you'll need Git installed on your computer. From your command line:

```
# Clone this repository
$ git clone https://github.com/furiousteam/bloc-wallet.git

# Go into the repository
$ cd bloc-wallet

# Update submodules
git submodule update --init --recursive
git submodule foreach git pull origin master
```

### macOS instructions

After installing [Xcode](https://developer.apple.com), make sure the Command Line Tools are installed as well:

```
xcode-select --install
```

BLOC also needs [CMake](https://cmake.org/) 2.8.6 or later as well as [Boost](https://www.boost.org/) 1.55 (make sure [Homebrew](https://brew.sh) is also installed):

```
brew install cmake
brew install boost
```

Build the app:

```
rm -Rf build && mkdir build && cd build
cmake -DSTATIC=1 \
-DBOOST_ROOT=/usr/local/Cellar/boost/1.66.0 \
-DBOOST_LIBRARYDIR=/usr/local/Cellar/boost/1.66.0/lib \
-DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/5.10.1 .. && make
```

### Windows instructions

Make sure to install the following dependencies:

* [MS Visual Studio](https://www.visualstudio.com) 2013 or later
* [Boost for Visual Studio](https://dl.bintray.com/boostorg/release/1.64.0/binaries/boost_1_64_0-msvc-14.1-64.exe)
* [QT for Visual Studio](http://download.qt.io/official_releases/qt/5.10/5.10.0/qt-opensource-windows-x86-5.10.0.exe)
* [MSBuild](https://www.microsoft.com/en-us/download/details.aspx?id=48159)
* [CMake](https://cmake.org/install/)

To build the app, inside the project folder:

```
mkdir build
cd build
cmake -DPORTABLE=1 -Wno-dev ^
-DCMAKE_PREFIX_PATH="C:\Qt\Qt5.10.0\5.10.0\msvc2015_64" ^
-DBOOST_ROOT="C:\local\boost_1_64_0_64" ^
-DBOOST_INCLUDEDIR="C:\local\boost_1_64_0_64\lib64-msvc-14.1" ^
-DBOOST_LIBRARYDIR="C:\local\boost_1_64_0_64\libs" ^
-G "Visual Studio 15 Win64" ..
```

Open Solution file in Build folder and Build Release. Change Debug to Release from the dropdown below the Team-Tools menu.

Open project in Visual Studio, Right Click on Rocksdb -> Properties->C/C++->Code Generation->Runtime Library to /MT — APPLY & SAVE.

Build External or RocksDB and then Build `ALL_BUILD`.

If you are building on an older processor without AVX support, add the following options to cmake:

```
-DPORTABLE=1 -DWITH_AVX2=0
```

### *nix instructions

BLOC needs [CMake](https://cmake.org/) 2.8.6 or later as well as [Boost](https://www.boost.org/) 1.55 and Qt:

```
sudo apt install cmake
sudo apt install qt-sdk
sudo apt install libboost-all-dev
```

```
rm -Rf build && mkdir build && cd build
cmake -DSTATIC=1 \
-DBOOST_ROOT=/usr/include/boost \
-DBOOST_LIBRARYDIR=/usr/lib/x86_64-linux-gnu \
-DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake .. && make
```

To create a portable build (AppImage), use `linuxdeployqt`:

```
cp src/blocwallet.desktop build/
cp src/images/bloc.png build/
cd build
linuxdeployqt.AppImage blocwallet.desktop -appimage -verbose=2 -no-translations
```

## Download

You can [download](https://bloc.money/download) latest stable version of the BLOC software for Windows, macOS and Linux.

## Related

* [BLOC.money](https://bloc.money/) - Official website of the BLOC cryptocurrency
* [BLOC Explorer](https://bloc-explorer.com) - Blockchain Explorer for BLOC
* [BLOC Mining](https://bloc-mining.com/) - In-browser Javascript miner for BLOC
* [BLOC Developer](https://bloc-developer.com) - In-depth documentation for all APIs related to BLOC

## License

GPL v3
