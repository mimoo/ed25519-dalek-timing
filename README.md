# Ed25519-dalek constant-time analysis

Using [dudect](https://github.com/oreparaz/dudect) to figure out if [ed25519-dalek](https://github.com/dalek-cryptography/ed25519-dalek) is constant-time.

Dudect is not the only tool that exist to assess constant-time code, here is [a slide deck](https://sbseg2017.redes.unb.br/wp-content/uploads/2017/11/sbseg2017_wticg_benchmarking-tools-verification.pdf) on the different tools and how they compare.

After writing this, I also realized that there is a rust crate to use dudect directly in rust: https://docs.rs/dudect-bencher/0.4.1/dudect_bencher/index.html

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
meas:    0.20 M, max t:   +2.08, max tau: 4.66e-03, (5/tau)^2: 1.15e+06. For the moment, maybe constant time.
meas:    0.16 M, max t:   +2.72, max tau: 6.90e-03, (5/tau)^2: 5.25e+05. For the moment, maybe constant time.
```

on a dev server:

```
TODO
```
