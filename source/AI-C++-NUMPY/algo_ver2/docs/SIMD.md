# this is module for using SIMD for parallelism multiple data(used AVX)

for more please follow:

[SIMD](https://en.wikipedia.org/wiki/Single_instruction,_multiple_data)
and:
[AVX](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions)

## check compatible using avx:

### linux platform:

```bash
grep -m1 'flags' /proc/cpuinfo | grep -o 'avx[^ ]*'
```

or:

```bash
lscpu | grep -i avx
```

for the first command, it should be reported like:

```bash
grep -m1 'flags' /proc/cpuinfo | grep -o 'avx[^ ]*'
avx
avx2
avx512f
avx512dq
avx512ifma
avx512cd
avx512bw
avx512vl
avx512vbmi
avx512_vbmi2
avx512_vnni
avx512_bitalg
avx512_vpopcntdq
avx512_vp2intersect
```

### windows platform:

```shell
wmic cpu get Caption, DeviceID, Manufacturer, Name, NumberOfCores, MaxClockSpeed, Description
```

### Macos platform

```bash
sysctl -a | grep machdep.cpu
```
