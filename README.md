# ed25519-dalek-timing

Using [dudect](https://github.com/oreparaz/dudect) to figure out if [ed25519-dalek](https://github.com/dalek-cryptography/ed25519-dalek) is constant-time.

* I added the `./dudect/dut/dalek` C wrapper and the target to the `./dudect/Makefile`
* I exported the rust ed25519 library to C in `./ed25519_c_wrappers`

```
cd ed25519_c_wrappers && cargo build && cd ..
cd dudect && make dut_dalek && ./dudect_dalek_-O2
```
