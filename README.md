# Plug and Play wechat QRcode module

A plug and play wechat QRcode opencv_contrib module

## Run the example

1. modify the OpenCV_DIR if you want to use opencv as 3rdparty

```cmake
set(OpenCV_DIR "/home/lyxichigoichie/3rdparty/opencv3/build")  #directory of OpenCVConfig.cmake
```

2. build and run

```bash
git clone https://github.com/lyxichigoichie/Plug_and_Play_wechatQRcode_module.git
mkdir build
cd build
cmake ..
make
./main
```

## How to use the module plug and play

1. clone repo and copy the `wechat_qrcode` folder to your project folder as a subdirectory

   ```bash
   git clone https://github.com/lyxichigoichie/Plug_and_Play_wechatQRcode_module.git
   cp wechat_qrcode {your_folder}
   ```

2. add the following code to your `CMakeLists.txt`

   ```cmake
   # set(OpenCV_DIR "/home/lyxichigoichie/3rdparty/opencv3/build")  #directory of OpenCVConfig.cmake
   find_package(OpenCV REQUIRED QUIET)
   
   add_subdirectory(wechat_qrcode)
   
   # include directories
   include_directories(
   	wechat_qrcode/include
   )
   ```

3. link the library `libwechat_qrcode.so` to your executable program

   ```cmake
   target_link_libraries(main ${OpenCV_LIBS} wechat_qrcode)
   ```

4. build and run
