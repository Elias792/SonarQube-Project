; Fichier plus complexe, simule un second blink modifié
        .section .text
        .global advanced_blink

advanced_blink:
        mov x1, #3        ; On va clignoter 3 fois
blink_loop:
        bl blink_led      ; Appel de la fonction blink_led (déjà définie)
        subs x1, x1, #1
        bne blink_loop
        ret

