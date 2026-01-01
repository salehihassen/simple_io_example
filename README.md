# Simple io example

Simple examples in Python and C for interacting with direct I/O on x86_64 arch. Port 0x61 (the System Control Port B) or reading the CMOS RTC (Real-Time Clock).

## Safety warning

Directly writing to I/O ports can cause system instability, hardware damage, or immediate kernel panics.
