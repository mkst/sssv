#ifndef FUNCTIONS_H
#define FUNCTIONS_H


unsigned long long __ull_rshift(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_rem(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_div(unsigned long long a0, unsigned long long a1);
unsigned long long __ll_lshift(unsigned long long a0, unsigned long long a1);
long long __ll_rem(unsigned long long a0, long long a1);
long long __ll_div(long long a0, long long a1);
unsigned long long __ll_mul(unsigned long long a0, unsigned long long a1);
void __ull_divremi(unsigned long long *div, unsigned long long *rem, unsigned long long a2, unsigned short a3);
long long __ll_mod(long long a0, long long a1);

// main_51D0
void init(void);
void clear_framebuffer(void);
void end_display_lists(void);

// main_10CB0
void init2(void);

#endif
