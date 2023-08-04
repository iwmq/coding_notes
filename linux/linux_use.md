Multiboot Flash Drive
----
It is very common that some people need to install different operating systems.
For example, a robot engineer may maintain computers with more than one ROS
distributions which run on Ubuntu 16.04/18.04/20.04. Nowadays, large capacity
flash drives are cheap, so put multiple boot ISO images in one flash drive is
possible and handy. Of course, tools are needed to do multibooting.

One popular multibooting tool is YUMI, which is good but run only on Windows.
See https://www.pendrivelinux.com/yumi-multiboot-usb-creator/.

Another multibooting tool which run both on Windows and Linux is Ventoy. It provides
command line, GTK/Qt GUI and Web-based GUI on Linux. See https://ventoy.net/en/index.html.

For both above-mentioned tools, after creating the boot drive, ISO images files
can be directly put in the drive and appear in the boot menu.

Create A Desktop Application
----
To enable launch a program via Ubuntu's desktop environment, create an
file with `.desktop` extension, and put it in the `/usr/share/applications`
directory.

Here is an example for Arduino IDE which is still in RC stage and has no
desktop launch entry on Linux. I name this launch entry file `arduino_ide_2`.

```
[Desktop Entry]
Type=Application
Name=Arduino IDE 2
GenericName=Arduino IDE 2
Comment=Open-source electronics prototyping platform
Exec="/opt/arduino-ide_2.0.0-rc3_Linux_64bit/arduino-ide"
Icon=arduino-arduinoide
Terminal=false
Categories=Development;IDE;Electronics;
MimeType=text/x-arduino;
Keywords=embedded electronics;electronics;avr;microcontroller;
StartupWMClass=processing-app-Base
```

Note:
- `Name` will appears on Ubuntu's activities list.
- `Exec` is the program's executable.
- `Icon` is the one found in `/usr/share/icons/hicolor`. I just
  pick the icon left by Arduino IDE (version 1.x).

Create An Autostart Application
----
For a program to automatically start when the user logs in desktop environment,
a `.desktop` launch entry can be created in the `~/.lonfig/autostart` directory
with a field `X-GNOME-Autostart-enabled=true`.

An easy way to do this is via `Startup Applications Preferences`.


Navigate Diretories With z.sh
----
`z.sh` is a bash script which remembers visited directories and jump between them
with a very easy way.

See https://github.com/rupa/z/.


Neovim Customization
----
A very powerful and easy tool for customizing neovim, making it like an IDE.

If installation fails, remove `~/.local/share/nvim/site/pack/packer`, then
re-open nvim to re-start installation.

See https://github.com/yetone/cosmos-nvim.


Install Fonts
----
On Linux (in my case, Ubuntu), fonts can be installed locally by copying font files into `~./fonts`.

`Nerd Fonts` is a collection of free iconic font families. To install `UbuntuMono Nerd Font`,
download it from its website (https://www.nerdfonts.com/font-downloads), extract font files by running
`unzip UbuntuMono.zip -d ~/.fonts`, then running `sudo fc-cache -f -v`. Open any application (say Terminal),
set font to any of the newly-installed font. These fonts are crucial for the `cosmos-nvim` tool, for
displaying its rich set of icons on UI.


Utils
----
Here are some simple command line utils to make life easier.
- Show network traffic: `slurm`
- Show operating system logo in As and common system information: `screenfetch`
- Take and edit screenshots: `flameshot`
- Record screen as `mp4` videos or `git` animations: `peek`
- Show device information in a concise and accurate way: `inxi`
- Send custom ICMP/UDP/TCP packets packets: `hping3`


Erase A Disk Securely
----
Among GNU core utils is `shred` that can erase files or an entire disk.

To erase a disk /dev/sdX:
```
sudo shred -vzf /dev/sdX
```

This is a very time-consuming command. For a 500 GB HDD disk, it took nearly
16 hours to finish erasing.


Ubutun/Debian Package
----
To solve the following error during `sudo apt-get update`:
```
The following signatures couldn't be verified because the public key is not available: NO_PUBKEY XXXXXXXXXXXXXXXX
```
run:
```
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys XXXXXXXXXXXXXXXX
```


Creat System Images
----
It is very handy to create a bootable USB driver from a system image using `dd`:
```
dd if=xxx.iso of=/dev/sdax oflag=direct bs=4M status=progress
```


Terminal Emulators
----
There is always a default terminal emulators for each desktop environment:
konsole for KDE plasma, GNOME terminal for GNOME.

The useful multi-panel feature is available in KDE kosole, while absent in
GNOME terminal (and its replacement, GNOME console). If we do not want to use
terminal multiplexers (tmux, GNU screen, etc.), to obtain this feature, a nice
alternative is needed. By now, prefer `Terminator`.