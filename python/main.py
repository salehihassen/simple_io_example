import os

PORT_ADDR = 0x61

def main():
    try:
        # We must open in binary mode and disable buffering
        with open("/dev/port", "rb+", buffering=0) as f:
            # Seek to the specific port address
            f.seek(PORT_ADDR)

            # Read 1 byte
            raw_val = f.read(1)

            if raw_val:
                value = ord(raw_val)
                print(f"Read from I/O Port {hex(PORT_ADDR)}: {hex(value)}")

                # To write, you would seek and write a byte string:
                # f.seek(PORT_ADDR)
                # f.write(bytes([value]))
                # f.write(bytes([0x2d]))
            else:
                print("Could not read value.")

    except PermissionError:
        print("Error: You must run this script with sudo.")
    except FileNotFoundError:
        print("Error: /dev/port not found. Your kernel might have CONFIG_DEVPORT disabled.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == '__main__':
    main()
