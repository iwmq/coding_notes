#!/usr/bin/env python3
"""
OpenCV's highgui comes with some advanced GUI features,
some of which requires QT as backend.

Alternative GUI is matplotlib which is more powerful.
Matplotlib support many GUI backends, including TK.

For this script to work, the OpenCV-Python and matplotlib
are needed. Additional, python3-tk must be installed via
apt on Ubuntu (in my case, python3.10-tk).
"""
import sys

import cv2
from matplotlib import pyplot as plt

def main(fpath):
    im = cv2.imread(fpath, cv2.IMREAD_COLOR)

    # To show via Matplotlib, channels need to be swapped
    # from BGR to RGB.
    im = im[: ,:, ::-1]

    plt.imshow(im)
    plt.xticks([])
    plt.yticks([])
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        print("Please specify an image to show")
