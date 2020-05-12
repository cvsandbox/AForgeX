@echo off

set OUT_FOLDER=..\..\..\..\..\build\msvc
set SRC_FOLDER=..\..\..\libjpeg-turbo
set BUILD_FOLDER=build

if "%1"=="clean" (
    rd /S /Q %BUILD_FOLDER%
) else (
    set MY_PATH=%cd%

    mkdir %BUILD_FOLDER%
    pushd %BUILD_FOLDER%

    cmake -G "Visual Studio 14 2015" -D ENABLE_SHARED:BOOL=OFF ^
        -D WITH_ARITH_DEC:BOOL=ON ^
        -D WITH_ARITH_ENC:BOOL=ON ^
        -D WITH_JPEG7:BOOL=ON ^
        -D WITH_JPEG8:BOOL=ON ^
        -D WITH_MEM_SRCDST:BOOL=ON ^
        -D WITH_SIMD:BOOL=ON ^
        -D WITH_TURBOJPEG:BOOL=ON ^
        %MY_PATH%\%SRC_FOLDER%

    msbuild libjpeg-turbo.sln /p:Configuration=Debug
    msbuild libjpeg-turbo.sln /p:Configuration=Release

    popd

    set OUT_REL=%OUT_FOLDER%\release
    set OUT_DBG=%OUT_FOLDER%\debug

    xcopy /Y "%BUILD_FOLDER%\Release\turbojpeg-static.lib" "%OUT_REL%\lib\"
    xcopy /Y "%BUILD_FOLDER%\Debug\turbojpeg-static.lib" "%OUT_DBG%\lib\"

    xcopy /Y "%BUILD_FOLDER%\jconfig.h" "%OUT_REL%\include\"
    xcopy /Y "%SRC_FOLDER%\jpeglib.h" "%OUT_REL%\include\"
    xcopy /Y "%SRC_FOLDER%\jmorecfg.h" "%OUT_REL%\include\"
    xcopy /Y "%SRC_FOLDER%\jerror.h" "%OUT_REL%\include\"

    xcopy /Y "%BUILD_FOLDER%\jconfig.h" "%OUT_DBG%\include\"
    xcopy /Y "%SRC_FOLDER%\jpeglib.h" "%OUT_DBG%\include\"
    xcopy /Y "%SRC_FOLDER%\jmorecfg.h" "%OUT_DBG%\include\"
    xcopy /Y "%SRC_FOLDER%\jerror.h" "%OUT_DBG%\include\"
)

:EOF
