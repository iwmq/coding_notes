Arduino IDE 2.0 (until RC3) has a bug on Linux, which causes a `undefined` directory in the launch directory.

This annoying directory is created for logging, and the Arduino team has not offered a real fix for this.

If such logs are not important, they can be put into `/tmp` directory by the following steps.

First, go to `Arduino IDE 2 install directory`, then open the file
`resources/app/node_modules/node-log-rotate/lib/utils/find-log-path.js`.

Then, find the following lines:

```javascript
case 'linux':
	dir = prepareDir(process.env['XDG_CONFIG_HOME'] + '', appName)
		.or(process.env['HOME'] + '/.config', appName)
		.or(process.env['XDG_DATA_HOME'] + '', appName)
		.or(process.env['HOME'] + '/.local/share', appName).result;
	break;
```

And change them to:

```javascript
case 'linux':
	dir = prepareDir("/tmp", "arduino_ide_2").result;
	break;
```
