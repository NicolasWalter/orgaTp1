; FUNCIONES de C
  extern malloc
  extern free
  extern strcpy
  extern tdt_agregar
  extern tdt_borrar

  
; FUNCIONES
  global tdt_crear
  global tdt_recrear
  global tdt_cantidad
  global tdt_agregarBloque
  global tdt_agregarBloques
  global tdt_borrarBloque
  global tdt_borrarBloques
  global tdt_traducir
  global tdt_traducirBloque
  global tdt_traducirBloques
  global tdt_destruir

; /** defines offsets y size **/
  %define TDT_OFFSET_IDENTIFICACION   0
  %define TDT_OFFSET_PRIMERA          8
  %define TDT_OFFSET_CANTIDAD        16
  %define TDT_SIZE                   20
  %define NULL                        0
  %define CLA_OFFSET_0                0
  %define CLA_OFFSET_1                1
  %define CLA_OFFSET_2                2

section .text

; =====================================
; tdt* tdt_crear(char* identificacion)
tdt_crear:
push rbp ;armo stack frame
mov rbp, rsp
push rbx
push r12


mov rbx, rdi ; pongo en rbx ID para preservar
xor rax, rax
xor rcx, rcx

.largoString:
cmp byte [rdi+rcx], 0
je .sigo
inc rcx
jmp .largoString

.sigo:
inc rcx
mov rdi, rcx
call malloc
cmp qword rax,0
je .fin_crear

mov rdi, rax ;pos de memoria
mov rsi, rbx ; pongo en rsi la ID 

call strcpy


mov r12, rax ; muevo identificacion para no perderlo despues del call
xor rdi,rdi
mov rdi, TDT_SIZE ;voy a pedir memoria para una tabla

call malloc
cmp qword rax, 0
je .fin_crear ; chequeo si me dieron memoria, en caso negativo termine


mov [rax+TDT_OFFSET_IDENTIFICACION], r12
mov qword [rax+TDT_OFFSET_PRIMERA], NULL
mov dword [rax+TDT_OFFSET_CANTIDAD], 0

.fin_crear:
pop r12
pop rbx
pop rbp
ret


; =====================================
; void tdt_recrear(tdt** tabla, char* identificacion)
                          ;rdi     rsi
tdt_recrear:
push rbp
mov rbp, rsp
push rbx
push r12
push r14
push r13
;mov r12, rdi ; **tabla
mov r14, rdi
mov r13, rsi ; char*
mov rbx, [rdi] ; *tabla
mov rbx, [rbx+TDT_OFFSET_IDENTIFICACION] ; ID original

mov rdi, r13 
cmp qword rdi, NULL
jne .cambioID
mov rdi,rbx; si es null le deoj la id original

.cambioID:
call tdt_crear 
mov r12, rax

mov rdi, r14
call tdt_destruir
mov [r14], r12
.fin_destruir: 
pop r14
pop r13
pop r12
pop rbx
pop rbp
ret


; =====================================
; uint32_t tdt_cantidad(tdt* tabla)
tdt_cantidad:
xor rax,rax
mov eax, [rdi+TDT_OFFSET_CANTIDAD]
ret

; =====================================
; void tdt_agregarBloque(tdt* tabla, bloque* b)
;                             rdi   , rsi
tdt_agregarBloque:
lea rdx, [rsi+3]
jmp tdt_agregar


; =====================================
; void tdt_agregarBloques(tdt* tabla, bloque** b)
tdt_agregarBloques:
push rbp
mov rbp, rsp
push r12
push r13
push r14
sub rsp,8


mov r13, rsi ; estoy en el primer bloque 
xor r14, r14
.ciclo:
cmp qword [r13+r14*8], NULL
je .fin_agregarBloques
mov r12, [r13+r14*8] ; 
inc r14  
mov rsi, r12
call tdt_agregarBloque
jmp .ciclo
.fin_agregarBloques:
add rsp,8
pop r14
pop r13
pop r12
pop rbp
ret
        
; =====================================
; void tdt_borrarBloque(tdt* tabla, bloque* b)
tdt_borrarBloque:
      jmp tdt_borrar
; =====================================
; void tdt_borrarBloques(tdt* tabla, bloque** b)
tdt_borrarBloques:
 push rbp
mov rbp, rsp
push r12
push r13
push r14
sub rsp,8


mov r13, rsi ; estoy en el primer bloque 
xor r14, r14
.ciclo:
cmp qword [r13+r14*8], NULL
je .fin_borrarBloques
mov r12, [r13+r14*8] ; 
inc r14  
mov rsi, r12
call tdt_borrarBloque
jmp .ciclo
.fin_borrarBloques:
add rsp,8
pop r14
pop r13
pop r12
pop rbp
ret
; =====================================
; void tdt_traducir(tdt* tabla, uint8_t* clave, uint8_t* valor)
;                         rdi             rsi        rdx
tdt_traducir:
  push rbp
  mov rbp, rsp

  xor rcx, rcx
  mov cl , [rsi+CLA_OFFSET_0] ; pongo clave[0] MODIFICAR TAMAÑO TIENE QUE SER 1 BYTE
  mov r10, [rdi+TDT_OFFSET_PRIMERA]
  ;mov r10, rdi ;estoy en tabla->primera
  cmp r10, NULL
  je .fin_traducir

  mov r10, [r10+rcx*8]; me muevo a tabla->primera->entradas[clave[0]]
  cmp r10, NULL
  je .fin_traducir

  xor rcx, rcx
  mov cl, [rsi+CLA_OFFSET_1] ; clave[1]

  mov r10, [r10+rcx*8] ; tabla->prim->ent[cla[0]]->ent[cla[1]]
  cmp r10, NULL
  je .fin_traducir

  xor rcx, rcx
  mov cl, [rsi+CLA_OFFSET_2]

add rcx, rcx
  lea r10, [r10+rcx*8]	; tengo la pos de memoria del valor
  ;cmp byte [r10+15], NULL
  ;je .fin_traducir
xor r8,r8
xor r9,r9
mov r9, rdx
mov r8, r10
xor r10,r10
xor rcx, rcx
cmp byte [r8+15], 0
je .fin_traducir

.ciclo:
 cmp qword rcx, 15
je .fin_traducir
 mov r10b, [r8+rcx]
mov byte [rdx+rcx] , r10b
;mov dl, [r9+rcx]
  add rcx, 1 
   jmp .ciclo

  .fin_traducir:
 
  pop rbp
  ret

; =====================================
; void tdt_traducirBloque(tdt* tabla, bloque* b)
tdt_traducirBloque:
lea rdx, [rsi+3]
jmp tdt_traducir

; =====================================
; void tdt_traducirBloques(tdt* tabla, bloque** b)
tdt_traducirBloques:
 push rbp
mov rbp, rsp
push r12
push r13
push r14
sub rsp,8


mov r13, rsi ; estoy en el primer bloque 
xor r14, r14
.ciclo:
cmp qword [r13+r14*8], NULL
je .fin_traducirBloques
mov r12, [r13+r14*8] ; 
inc r14  
mov rsi, r12
call tdt_traducirBloque
jmp .ciclo
.fin_traducirBloques:
add rsp,8
pop r14
pop r13
pop r12
pop rbp
ret
; =====================================
; void tdt_destruir(tdt** tabla)
;                       rdi
tdt_destruir:

push rbp
mov rbp,rsp
push r12
push r13
push r14
push r15
push rbx
sub rsp, 8

mov rbx, rdi ;preservo para que no se pierda
mov r12, [rdi] ; tdt* tabla
mov r12, [r12+TDT_OFFSET_PRIMERA]; tabla->primera
xor r13,r13  ;puntero a segunda
xor r14, r14 ; contador tabla->entradas[i]
xor r15,r15 ; contador prim->entradas[j]
xor r11,r11 ; puntero a tercera

cmp qword r12, NULL
je .libera 

.ciclo: 
cmp qword r14, 256
je .libera

mov r13, [r12+r14*8] ; recorro toda la primer tabla
inc r14
cmp r13, NULL
je .ciclo

.ciclo2: 
cmp qword r15, 256
je .libera2

mov r11, [r13+r15*8] ; recorro la segunda
inc r15
cmp r11, NULL
je .ciclo2

mov rdi, r11
call free ; borro la tabla 3
je .ciclo2

.libera2:
mov rdi, r13
call free   ; borro la tabla 2
xor r15, r15
jmp .ciclo


.libera:
cmp qword r12, NULL
je .fin_destruir
mov rdi, r12
call free; borro la primera

.fin_destruir:
mov rbx, [rbx]
mov rdi, [rbx+TDT_OFFSET_IDENTIFICACION]
call free
mov rdi, rbx
call free

; mov rdi, [rbx+TDT_OFFSET_IDENTIFICACION]
; mov rdi, [rdi]
; call free 
; mov rdi, [rbx]
; call free ; borro todo

add rsp,8
pop rbx
pop r15
pop r14
pop r13
pop r12
pop rbp
ret

; void tdt_destruir(tdt** tabla)
;                       rdi
; tdt_destruir:
; push rbp
; mov rbp, rsp
; push rbx
; push r12
; push r13
; push r14
; push r15
; sub rsp,8

; mov rbx, rdi ; preservo rdi
; xor r11, r11 ;puntero a la tercera 
; mov r13, [rdi] ;tdt* tabla
; mov r13, [r13+TDT_OFFSET_PRIMERA] ;Tabla primera
; xor r12,r12 ;puntero a la segunda
; xor r14,r14 ; contador segunda
; xor r15,r15  ; contador primera


; cmp r13, NULL
; je .fin_destruir

; .ciclo: 
; cmp qword r15, 256
; je .libera
; mov r12, [r13+r15*8]
; inc r15
; cmp qword r12, NULL
; je .ciclo

; .ciclo2:
; cmp qword r14, 256
; je .libera2
; mov r11, [r12+r15*8]
; inc r14
; cmp qword r11, NULL
; je .ciclo2
; mov rdi, r11
; call free
; jmp .ciclo2 


; .libera2:
; mov rdi, r12
; call free
; xor r14,r14
; jmp .ciclo

; .libera:
; mov rdi, r13
; call free
; xor r15,r15
; jmp .fin_destruir
; ; ; if(tabla->primera!=NULL){ listo
; ; ;   aux =tabla->primera
; ; ;   for(int i=0 ;i<256; i++){
; ; ;       if(aux->entradas[i]!=NULL){
; ; ;         for(int j=0, j<256, i++){
; ; ;           if( aux->entradas[i]->entradas[j]!=NULL){
; ; ;           free(aux->entradas[i]->entradas[j])
; ; ;           }
; ; ;           free(aux->entradas[i])
; ; ;         }
; ; ;       }
; ; ;     }
; ; ; }

; .fin_destruir:
; mov rbx, [rbx]
; mov rdi, [rbx+TDT_OFFSET_IDENTIFICACION]
; call free
; mov rdi, rbx
; call free

; add rsp,8
; pop r15
; pop r14
; pop r13
; pop r12
; pop rbx
; pop rbp
; ret

; cmp qword r13, NULL ; if(tabla->primera!=NULL)
; jne .primera
; jmp .fin_destruir

; .primera: 
; cmp qword r15, 256        ;for(int i=0 ;i<256; i++)
; jne .sigo
; mov rdi ,r13
; call free
; .sigo:
; cmp qword [r13+r15*8], NULL ;if(aux->entradas[i]!=NULL)
; jne .segunda 
; inc r15
; jmp .primera
; .segunda:
; mov r12, [r13+r15*8]
; inc r15
; cmp qword r14, 256  ; for(int j=0, j<256, i++)
; jne .tercera