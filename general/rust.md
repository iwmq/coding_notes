Rust on Windows
----
To upgrade rust:
```
	rustup update stable-x86_64-pc-windows-gnu
```

To install rust language server:
```
	rustup component add rls --toolchain stable-x86_64-pc-windows-gnu
```

To list all installed rust components:
```
	rustup component list --installed
```

Installed components are located at:
`C:\Users\<username>\.rustup\toolchains\stable-x86_64-pc-windows-gnu`.