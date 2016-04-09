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
sub rsp,8

mov rbx, rdi ; pongo en rbx ID para preservar
xor rax, rax

.ciclo:
cmp byte [rdi], 0
je .sigo
inc rdi
inc rax
jmp .ciclo

.sigo:
mov rdi, rax
call malloc
cmp rax,0
je .fin_crear

mov rdi, rax ;pos de memoria
mov rsi, rbx ; pongo en rsi la ID 

call strcpy


mov rbx, rax ; muevo identificacion para no perderlo despues del call
xor rdi,rdi
mov rdi, TDT_SIZE ;voy a pedir memoria para una tabla

call malloc
cmp rax, 0
je .fin_crear ; chequeo si me dieron memoria, en caso negativo termine


mov [rax+TDT_OFFSET_IDENTIFICACION], rbx
mov qword [rax+TDT_OFFSET_PRIMERA], NULL
mov dword [rax+TDT_OFFSET_CANTIDAD], 0

.fin_crear:
add rsp,8
pop rbx
pop rbp
ret


; =====================================
; void tdt_recrear(tdt** tabla, char* identificacion)
tdt_recrear:

; =====================================
; uint32_t tdt_cantidad(tdt* tabla)
tdt_cantidad:
xor rax,rax
mov eax, [rdi+TDT_OFFSET_CANTIDAD]
ret

; =====================================
; void tdt_agregarBloque(tdt* tabla, bloque* b)
tdt_agregarBloque:

; =====================================
; void tdt_agregarBloques(tdt* tabla, bloque** b)
tdt_agregarBloques:
        
; =====================================
; void tdt_borrarBloque(tdt* tabla, bloque* b)
tdt_borrarBloque:
        
; =====================================
; void tdt_borrarBloques(tdt* tabla, bloque** b)
tdt_borrarBloques:
        
; =====================================
; void tdt_traducir(tdt* tabla, uint8_t* clave, uint8_t* valor)
;                         rdi             rsi        rdx
tdt_traducir:
  push rbp
  mov rbp, rsp

  xor rcx, rcx
  mov cl , [rsi+CLA_OFFSET_0] ; pongo clave[0] MODIFICAR TAMAÑO TIENE QUE SER 1 BYTE
  mov rdi, [rdi+TDT_OFFSET_PRIMERA]
  mov r10, rdi ;estoy en tabla->primera
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
;xor rdx, rdx


mov r8, r10
xor r10,r10
xor rcx, rcx
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

; string_copiar_loop:
;     mov bl, [r12 + rcx]        ; bl <- *(s+i) = s[i]
;     cmp bl, 0                  ; if s[i] == '\0': return
;     je string_copiar_fin
;     mov byte [rax + rcx], bl   ; *(p+i) <- s[i] ~ p[i] <- s[i] 
;     inc rcx                    ; i++
;     jmp string_copiar_loop
;   string_copiar_fin:
;     mov byte [rax + rcx], bl   ; *(p+i) <- s[i] = '\0'
    






; =====================================
; void tdt_traducirBloque(tdt* tabla, bloque* b)
tdt_traducirBloque:

; =====================================
; void tdt_traducirBloques(tdt* tabla, bloque** b)
tdt_traducirBloques:
        
; =====================================
; void tdt_destruir(tdt** tabla)
tdt_destruir:

