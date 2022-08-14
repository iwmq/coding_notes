GO proxy
----
To install go modules, a valid proxy is needed in some nations.

```
$ go env -w GO111MODULE=on
$ go env -w GOPROXY=https://goproxy.cn,direct
```

See https://goproxy.cn/