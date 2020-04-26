# ed25519-dalek-timing

Using [dudect](https://github.com/oreparaz/dudect) to figure out if [ed25519-dalek](https://github.com/dalek-cryptography/ed25519-dalek) is constant-time.

Dudect is not the only tool that exist to assess constant-time code, here is [a slide deck](https://sbseg2017.redes.unb.br/wp-content/uploads/2017/11/sbseg2017_wticg_benchmarking-tools-verification.pdf) on the different tools and how they compare.

## What was done?

* I added the `./dudect/dut/dalek` C wrapper and the target to the `./dudect/Makefile`
* I exported the rust ed25519 library to C in `./ed25519_c_wrappers`

## How to run it yourself?

Clone this repo and run:

```
cd ed25519_c_wrappers && cargo build && cd ..
cd dudect && make dut_dalek && ./dudect_dalek_-O2
```

## Results

on a macbook air I get:

```
meas:    0.07 M, max t:   +1.52, max tau: 5.87e-03, (5/tau)^2: 7.26e+05. For the moment, maybe constant time.
```

on a dev server:

```
TODO
```
