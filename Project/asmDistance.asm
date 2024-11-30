section .text
bits 64
default rel
global testing
testing:
    
    ;sqrt(pow(x2 - x1, 2) + pow(y2 - y1,2));
    ;XMM0 = x1
    ;XMM1 = y1
    ;XMM2 = x2
    ;XMM3 = y2
    
    ; XMM2 = (x2 - x1)^2
    SUBSD XMM2, XMM0
    MULSD XMM2, XMM2
    
    ; XMM3 = (y2 - y1)^2
    SUBSD XMM3, XMM1
    MULSD XMM3, XMM3
    
    ; XMM2 = XMM2 + XMM3
    ADDSD XMM2, XMM3
    
    ; XMM0 = Square root(XMM2)
    SQRTSD XMM0, XMM2
    
    xor rax, rax
    ret