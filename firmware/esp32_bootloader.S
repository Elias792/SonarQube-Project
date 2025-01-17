        .section .text.boot
        .global _start

        .set INIT_VALUE, 0x40000000

_start:
        movi a0, INIT_VALUE
        // Initialisation fictive un peu plus longue
        movi a1, 0x12345678
        // ...

        j main_firmware
