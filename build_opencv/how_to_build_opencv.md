The following are steps for building and isntalling OpenCV on Linux, tested on Debian/Ubuntu.

1. Install system dependencies
```
sudo apt-get install build-essential cmake unzip pkg-config
sudo apt-get install libqt5x11extras5-dev libeigen3-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libavresample-dev libjpeg-dev libpng-dev libtiff-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libgtk-3-dev libcanberra-gtk* libatlas-base-dev gfortran python3-dev
```
2. Install Python dependencies
Create a virtual environment, activate it, then install `numpy`.
The following build step needs the virtual environment be activated.

3. Download
Down load opencv and opencv_contrib, unzip them to a directory, say `~/vendors/opencv`.

4. Build
```
mkdir opencv-x.x.x/build
cd opencv-x.x.x/build
cmake ../../build_opencv_for_<device_type>.sh
make
```

5. Install
If old version of OpenCV is installed, remove it before installing new one.
Then install OpenCV to system:
```
sudo make install
```

Go to a virtual environment for OpenCV-Python:
```
cd ~/vendors/py3cv4/lib/python3.9/site-packages
```

Make a soft link to the OpenCV library that is installed. 
(Note: the path is different for other systems and Python versions).
```
ln -s /usr/local/lib/python3.10/site-packages/cv2/python-3.10/cv2.cpython-310-x86_64-linux-gnu.so cv2.so
```

Appendices
---
A1. Adjust swap size for raspberry Pi
```
sudo /etc/init.d/dphys-swapfile stop
sudo vim /etc/dphys-swapfile
# then change swap size to 2048M
sudo /etc/init.d/dphys-swapfile start
```

A2. Downloaded files during build
In the `build` directory, cmake will download soem 3party files, putting them in `downloads` and `3rdparty` directories.

These files can be saved for buiding in other computers, to accelerate the build process.

A3. Uninstall
To uninstall OpenCV which is built by ourself, go to the `build` directory, run:
```
make uninstall
```

A4. Compiling time
For desktop PC with i5-8250 CPU, it takes about 1 hours to compile OpenCV.
For Raspberry Pi 4B, the time is about 1.5 hours.
For board with RK3399 SoC, the time is about 2 hours.