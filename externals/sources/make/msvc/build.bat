@echo off

if "%1"=="clean" (
    msbuild build.sln /t:Clean /p:Configuration=Debug /p:Platform=Win32
    msbuild build.sln /t:Clean /p:Configuration=Release /p:Platform=Win32

    RD /Q /S Debug
    RD /Q /S Release

    pushd libjpeg-turbo
    call build clean
    popd

) else (
    msbuild build.sln /p:Configuration=Debug /p:Platform=Win32
    msbuild build.sln /p:Configuration=Release /p:Platform=Win32

    pushd libjpeg-turbo
    call build
    popd

)
