
#!/bin/bash

if [ -z "${ANDROID_HOME}" ]; then
    echo "ANDROID_HOME is not set" && exit -1
fi

if [ -z "${ANDROID_NDK_HOME}" ]; then
    echo "ANDROID_NDK_HOME is not set" && exit -1
fi

CMAKE=`find $ANDROID_HOME -name cmake | grep bin`
TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake
BUILD_DIR=./build/android

echo "build android with ${CMAKE}"

ABI="arm64-v8a armeabi-v7a"

for abi in $ABI
do
    echo "**********************"
    echo "  ${abi} shared  "
    echo "**********************"

    if [ ! -d ${BUILD_DIR}/${abi} ]; then
        mkdir -p $BUILD_DIR/${abi} || exit -1
    fi
    cd $BUILD_DIR/${abi}

    ${CMAKE} \
        -DBUILD_SHARED_LIBS=ON                                      \
        -DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN_FILE}                    \
        -DANDROID_ABI="$abi"                                        \
        -DANDROID_NATIVE_API_LEVEL="android-19"                     \
        -DANDROID_STL="c++_shared"                                  \
        -DANDROID_CPP_FEATURES="rtti exceptions"                    \
        -DCMAKE_BUILD_TYPE=Release                                  \
        ../../..

    if [ $? -ne 0 ]; then
        exit -1
    fi

    make -j4 && make install/strip  || exit -1
    cd -

done

