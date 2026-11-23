# rf-event-analyzer

**Work in progress — personal learning project.**

A C project exploring RF event analysis with bladeRF and Raspberry Pi 5.
The published prototype focuses on opening a device and checking its FPGA.
It is not yet a complete RF event analyzer.

## Current implementation

- CMake project linked against libbladeRF.
- Opens the first available bladeRF device.
- Queries the FPGA variant and checks whether the FPGA is configured.
- Reports device/API errors and closes the device.

The author has performed hardware testing during local development. The exact
test coverage and its correspondence to this published snapshot are not
documented here; no specific RX test results are claimed in this README.

An interactive command interface exists as unfinished local development and is
not included in this published snapshot.

## Planned

- Complete and validate an interactive RX configuration interface.
- Implement IQ acquisition.
- Explore DSP and RF event detection.
- Add reproducible build, runtime, and hardware checks.

IQ capture, DSP, and end-to-end event detection are not implemented in this
published snapshot.

## Development and build

The development source tree is maintained on Arch Linux. Raspberry Pi 5 is used
as the remote build/run host in the development workflow.

A retained local remote-toolchain log shows successful CMake configuration and
libbladeRF discovery. Machine-specific IDE settings and build logs are not
published.

Requirements on the build host:

- C and C++ compilers (both languages are enabled by the existing CMake project)
- CMake 3.10 or newer
- pkg-config
- libbladeRF development headers and library

The existing CMake target is `BladerRFMain`, built from `src/main.c`.

Example procedure on the Raspberry Pi, assuming the source tree is already
available at `/tmp/rf-event-analyzer`:

```sh
cmake -S /tmp/rf-event-analyzer -B /tmp/rf-event-analyzer/build
cmake --build /tmp/rf-event-analyzer/build --target BladerRFMain
```

The first command configures the project; the second compiles and links it.
For a different checkout location, replace both absolute paths accordingly.

## Runtime limitations

The device selector opens the first discovered device rather than a specific
serial number. With multiple devices connected, selection is not explicit.
Device permissions, firmware/FPGA setup, and hardware availability must be
checked on the execution host. Running the program accesses hardware.

## Publication history

This public copy preserves the order, messages, and dates of three original
development commits. Their hashes changed during an explicitly approved privacy
cleanup: a device-specific serial selector was replaced with `NULL`, and author
metadata was replaced with a public GitHub identity and noreply email.
The original local repository was left unchanged. This copy does not include
local assistant checkpoints, IDE configuration, captures, or build artifacts.
