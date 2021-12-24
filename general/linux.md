
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