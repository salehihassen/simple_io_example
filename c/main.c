#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>

#define PORT_ADDR 0x61 // System Control Port B

int main() {
    // 1. Get permission to access the port
    // ioperm(from, num_ports, turn_on_flag)
    if (ioperm(PORT_ADDR, 1, 1) < 0) {
        perror("ioperm");
        fprintf(stderr, "Note: This program must be run as root (sudo).\n");
        return 1;
    }

    // 2. Read a byte from the port
    unsigned char value = inb(PORT_ADDR);
    printf("Successfully read from I/O Port 0x%02X: 0x%02X\n", PORT_ADDR, value);

    // 3. (Optional) Example of a safe write: toggling the speaker bit
    // is often ignored by modern hardware but demonstrates the syntax:
    // unsigned char tmp_value = 0x2D;
    // outb(tmp_value, PORT_ADDR);

    // 4. Release permission
    ioperm(PORT_ADDR, 1, 0);

    return 0;
}
