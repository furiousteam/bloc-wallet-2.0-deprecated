Dependencies: boost >= 1.58, CMake >= 2.8.6, GCC >=4.7.3, Qt >=5.0

* VISUAL STUDIO 2015
* BOOST for Visual Studio: https://dl.bintray.com/boostorg/release/1.64.0/binaries/boost_1_64_0-msvc-14.1-64.exe
* QT for Visual Studio:http://download.qt.io/official_releases/qt/5.10/5.10.0/qt-opensource-windows-x86-5.10.0.exe
* MSBuild https://www.microsoft.com/en-us/download/details.aspx?id=48159
* CMake https://cmake.org/install/

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
```
mkdir build
cd build
cmake -DSTATIC=1 -Wno-dev ^
-DCMAKE_PREFIX_PATH="C:\Qt\Qt5.10.0\5.10.0\msvc2015_64" ^
-DBOOST_ROOT="C:\local\boost_1_64_0_64" ^
-DBOOST_INCLUDEDIR="C:\local\boost_1_64_0_64\lib64-msvc-14.1" ^
-DBOOST_LIBRARYDIR="C:\local\boost_1_64_0_64\libs" ^
-G "Visual Studio 15 Win64" ..


—-----
STEPS:
—-----
1: Run the below cmake build command
*: Change Debug to Release from the dropdown below the Team-Tools menu
2: Open project in Visual Studio
    A: Right Click on Rocksdb -> Properties->C/C++->Code Generation->Runtime Library to /MT — APPLY & SAVE
3: Build External or RocksDB
4: Build ALL_BUILD
```

If you are building on an older processor without AVX support, add the following options to cmake:

```
-DPORTABLE=1 -DWITH_AVX2=0
```

On windows, you may find it helpful to explicitly include Boost and Qt library paths:

```
cmake -G "Visual Studio 15 Win64" -DCMAKE_PREFIX_PATH="C:\Qt2\5.9.1\msvc2015" -DBOOST_ROOT="C:\boost_1_64_0_built" -DBOOST_INCLUDEDIR="C:/boost_1_64_0_built/lib32-msvc-14.1" -DBOOST_LIBRARYDIR="C:\boost_1_64_0_built\libs"
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
