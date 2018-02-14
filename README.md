Dependencies: boost >= 1.58, CMake >= 2.8.6, GCC >=4.7.3, Qt >=5.0

**1. Clone wallet sources**

```
git clone https://github.com/furiousteam/blockchain-coin-wallet.git
```

**2. Update git submodule:**

```
git submodule update --init --recursive
git submodule foreach git pull origin zvetachanges
```

**3. Build**

#### Windows build
* VISUAL STUDIO 2017
* BOOST for Visual Studio: https://dl.bintray.com/boostorg/release/1.64.0/binaries/boost_1_64_0-msvc-14.1-64.exe
* QT for Visual Studio:http://download.qt.io/official_releases/qt/5.10/5.10.0/qt-opensource-windows-x86-5.10.0.exe
* MSBuild https://www.microsoft.com/en-us/download/details.aspx?id=48159
* CMake https://cmake.org/install/

```
—-----
STEPS:
—-----
0: Open /CmakeList.txt and comment -- ALREADY DONE IN THIS REPO
#add_subdirectory(cryptonote/src)
#add_subdirectory(tests)


1: Run This Command 
mkdir build
cd build
cmake -DPORTABLE=1 -Wno-dev ^
-DCMAKE_PREFIX_PATH="C:\Qt\Qt5.10.0\5.10.0\msvc2015_64" ^
-DBOOST_ROOT="C:\local\boost_1_64_0_64" ^
-DBOOST_INCLUDEDIR="C:\local\boost_1_64_0_64\lib64-msvc-14.1" ^
-DBOOST_LIBRARYDIR="C:\local\boost_1_64_0_64\libs" ^
-G "Visual Studio 15 Win64" ..


# Open Solution file in Build folder and Build Release.


*: Change Debug to Release from the dropdown below the Team-Tools menu
2: Open project in Visual Studio
    A: Right Click on Rocksdb -> Properties->C/C++->Code Generation->Runtime Library to /MT — APPLY & SAVE
3: Build External or RocksDB
4: Build ALL_BUILD
5: C:\Qt\Qt5.10.0\5.10.0\msvc2015_64\bin\windeployqt yourcoin.exe 
```

If you are building on an older processor without AVX support, add the following options to cmake:

```
-DPORTABLE=1 -DWITH_AVX2=0
```

#### macOS build
```
# install & update xcode
xcode-select --install
# install brew
brew install cmake
brew install boost


rm -Rf build && mkdir build && cd build
cmake -DSTATIC=1 \
-DBOOST_ROOT=/usr/local/Cellar/boost/1.66.0 \
-DBOOST_LIBRARYDIR=/usr/local/Cellar/boost/1.66.0/lib \
-DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/5.10.0_1 .. && make
```

```
/usr/local/Cellar/qt/5.10.0_1/macdeployqt yourcoin.app
```

#### *nix build
```
mkdir build && cd build && cmake -DSTATIC=1 .. && make
```

To create a portable build (AppImage), use linuxdeployqt:
```
cp src/intensecoinwallet.desktop build/
cp src/images/intensecoin.png build/
cd build
linuxdeployqt.AppImage intensecoinwallet.desktop -appimage -verbose=2 -always-overwrite -no-translations
```
