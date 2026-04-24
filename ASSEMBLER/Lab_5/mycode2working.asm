.stack 100h

.data
    array dw 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
    msg db 'Multiple: $'          ; выводитс€ один раз
    space db ' $'                 ; пробел между числами
    newline db 13,10,'$'          ; перевод строки в конце

.code

; ѕодпрограмма печати числа из AX (без изменени€ регистров кроме AX?)
print_num proc
    push ax
    push bx
    push cx
    push dx
    mov cx, 0          ; счетчик цифр
    mov bx, 10         ; делитель
convert:
    xor dx, dx
    div bx             ; ax = частное, dx = остаток (цифра)
    add dl, '0'
    push dx
    inc cx
    test ax, ax
    jnz convert
print_digits:
    pop dx
    mov ah, 02h
    int 21h
    loop print_digits
    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_num endp

start:
    mov ax, @data
    mov ds, ax

    ; ¬ывести "Multiple: " один раз
    mov ah, 09h
    lea dx, msg
    int 21h

    lea si, array       ; указатель на массив
    mov cx, 20          ; количество элементов

check_next:
    lodsw               ; загружаем слово в ax, si += 2
    push ax             ; сохран€ем оригинал числа
    mov bl, 5
    div bl              ; ah = остаток, al = частное
    cmp ah, 0
    jne not_multiple

    ; число кратно 5 Ц восстанавливаем и печатаем
    pop ax              ; восстанавливаем число
    call print_num

    ; печатаем пробел (или можно зап€тую, но дл€ простоты пробел)
    mov ah, 09h
    lea dx, space
    int 21h

    jmp next_element

not_multiple:
    pop ax              ; убираем сохранЄнное число (оно не нужно)
next_element:
    loop check_next

    ; печатаем перевод строки в конце
    mov ah, 09h
    lea dx, newline
    int 21h

    mov ah, 4ch
    int 21h

end start