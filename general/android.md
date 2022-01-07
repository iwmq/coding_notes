Install adb
----
Android debug bridge is included in Android SDK Platform-Tools which
is a collection of command line tools. It can be downloaded and installed
without involving the huge Android IDE.

See https://developer.android.com/studio/releases/platform-tools.

Fuck H-Company Services
----
Android phones from H company come with many annonying pre-installed
useless services, some of which will prompt when the user touchs bottom
corners of the screen. So fucking disable them.

After connecting the phone in USB debug mode, run the following commands:
```
adb shell pm disable-user com.huawei.search
adb shell pm disable-user com.huawei.ohos.famanager
```

To see what are disabled:
```
adb shell pm list packages -s -d
```