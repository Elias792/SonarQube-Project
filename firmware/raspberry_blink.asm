        .section .text
        .global blink_led

blink_led:
        mov x0, #5000000
wait_loop:
        subs x0, x0, #1
        bne wait_loop

        // Toggle LED
        ret

