# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 22:30:38 by emabel            #+#    #+#              #
#    Updated: 2020/10/20 22:30:38 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; int 	ft_strcmp(const char *s1, const char *s2);
; rdi = *s1
; rsi = *s2

				section .text 
				global  ft_strcmp

ft_strcmp:		mov	r10, -1			; i = -1
				mov rax, 0 			; tmp1 = '\0'
				mov rcx, 0			; tmp2 = '\0'
loop:			inc r10				; ++i
				mov al, [rdi + r10]	; tmp1 = s[i];
				mov cl, [rsi + r10]	; tmp2 = s[i];
				cmp al, byte 0		; if (a == '\0')
				je end				; return
				cmp al, cl			; if (tmp1 == tmp2)
				je loop				; continue
end: 			sub rax, rcx		; return (tmp1 - tmp2)
				ret
				
