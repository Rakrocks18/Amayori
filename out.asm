global _start
_start:
    ;; let
    mov rax, 2
    push rax
    mov rax, 4
    push rax
    mov rax, 2
    push rax
    mov rax, 10
    push rax
    pop rax
    pop rbx
    sub rax, rbx
    push rax
    pop rax
    pop rbx
    mul rbx
    push rax
    pop rax
    pop rbx
    div rbx
    push rax
    ;; /let
    ;; let
    mov rax, 71
    push rax
    ;; /let
    ;; let
    mov rax, 0
    push rax
    ;; /let
    ;; if
    mov rax, 0
    push rax
    pop rax
    test rax, rax
    jz label0
    mov rax, 1
    push rax
    pop rax
    mov [rsp + 8], rax
    jmp label1
label0:
    ;; elif
    mov rax, 0
    push rax
    pop rax
    test rax, rax
    jz label2
    mov rax, 2
    push rax
    pop rax
    mov [rsp + 8], rax
    jmp label1
label2:
    ;; else
    push QWORD [rsp + 16]
    pop rax
    mov [rsp + 8], rax
label1:
    ;; /if
    ;; let
    mov rax, 2
    push rax
    push QWORD [rsp + 16]
    pop rax
    pop rbx
    div rbx
    push rax
    ;; /let
    ;; exit
    mov rax, 5
    push rax
    push QWORD [rsp + 24]
    pop rax
    pop rbx
    add rax, rbx
    push rax
    mov rax, 60
    pop rdi
    syscall
    ;; /exit
    mov rax, 60
    mov rdi, 0
    syscall
