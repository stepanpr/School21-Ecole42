# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s       	                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 21:55:04 by emabel            #+#    #+#              #
#    Updated: 2020/10/20 21:55:04 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; char	*ft_strcpy(char *dst, char *src);
; rdi = *dst
; rsi = *src

				section .text 
				global ft_strcpy

ft_strcpy:		mov rax, 0					; i = 0
loop:			mov dl, byte [rsi + rax]	; dl - однобайтовый регистр (tmp)
											; записываем данные из источника rsi (src)
											; dl = src[i];
				cmp dl, 0					; if (dl == '\0')
				je end						; jump to end
				mov byte [rdi + rax], dl	; в указатель назначения rdi (dest) записываем данные из dl
											; dest[i] = dl
				inc rax						; rax++;
				jmp loop					; jump на следующую итерацию
end: 			mov dl, 0					; *tmp = '\0'
				mov byte [rdi + rax], dl	; dest[i] = *tmp
				mov rax, rdi				; return (dst);
				ret							

