Trouble Shooting
----

After upgrading kernel of Ubuntu 22.04 from 5.15 to 5.19, my computer failed
to boot into desktop, showing `Failed to start nvida persistence daemon`.
I fixed this error by going to another tty (Ctrl + Alt + F2), reinstalling the
CUDA toolkit.


Install CUDA On Manjaro
---
On Manjaro, it is very easy to install CUDA for deep learning.
```
sudo pacman -S cuda cudnn
```