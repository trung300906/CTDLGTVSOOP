# this is module for using SIMD for parallelism multiple data(used AVX)

for more please follow:
https://en.wikipedia.org/wiki/Single_instruction,_multiple_data

check compatible using avx:

## linux platform:

```bash
grep -m1 'flags' /proc/cpuinfo | grep -o 'avx[^ ]*'
```

or:

```bash
lscpu | grep -i avx
```

## windows platform:

```shell-bash
wmic cpu get Caption, DeviceID, Manufacturer, Name, NumberOfCores, MaxClockSpeed, Description
```

## Macos platform

```bash
sysctl -a | grep machdep.cpu
```
