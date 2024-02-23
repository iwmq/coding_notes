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


Rust Libraries
---

Bevy engine: https://bevyengine.org


Tools written in Rust
---

- Code editors: `lapce` and `zed`.

- For Python: package management tool `uv` and formatter `ruff`, both from
  `https://github.com/astral-sh`.

- For frontend: `farm`.