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
  
section .text

; =====================================
; tdt* tdt_crear(char* identificacion)
tdt_crear:
push rbp ;armo stack frame
mov rbp, rsp
push rbx
sub rsp,8

mov rbx, rdi ; pongo en rbx ID para preservar

.ciclo:
cmp byte [rdi], 0
je .sigo
add rdi, 1
jmp .ciclo

.sigo:
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
  push r12
  push r13
  

  mov rcx , [rsi] ; pongo clave[0]
  imul rcx,8
  cmp qword [rdi+TDT_OFFSET_PRIMERA+rcx], 0 ;multiplico por 8 para moverme de a bytes?
  je .fin_traducir  

  lea r8, [rdi+TDT_OFFSET_PRIMERA+rcx]  ;pongo en r8 el valor de prim->entradas[clave[0]]
  inc rsi
  mov r12,rsi
  mov r13, [r12]
  imul r13,8 
  cmp qword [r8+r13], 0  ;
  je .fin_traducir
 
  lea r9, [r8+r13] ; en r9 el valor de prim->entradas[clave[0]]->entradas[clave[1]]
   inc rsi
   mov r12, rsi
  mov r13, [r12]
  imul r13,8 
  cmp qword [r9+r13], 0
  je .fin_traducir
  mov rdx, [r9+r13]





  .fin_traducir:
  pop r13
  pop r12
  pop rbp
  ret
; =====================================
; void tdt_traducirBloque(tdt* tabla, bloque* b)
tdt_traducirBloque:

; =====================================
; void tdt_traducirBloques(tdt* tabla, bloque** b)
tdt_traducirBloques:
        
; =====================================
; void tdt_destruir(tdt** tabla)
tdt_destruir:

