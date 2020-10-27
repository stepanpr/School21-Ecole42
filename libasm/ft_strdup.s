# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 22:58:40 by emabel            #+#    #+#              #
#    Updated: 2020/10/20 22:58:40 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; char 	*ft_strdup(const char *s);

				section .text
				global ft_strdup
				extern ft_strlen
				extern ft_strcpy
				extern malloc

ft_strdup:		push rdi			; rdi записываем в стек (значение аргумента)
				call ft_strlen		; считаем длину rdi
				mov rdi, rax		; в rdi записываем длину строки
				inc rdi				; и инкрементируем для знака '\0'
				call malloc			; выделяем память (динной rdi) в rax
				cmp rax, 0			; сравниваем rax с 0
				je end				; jump если выделения памяти не произошло
				mov rdi, rax		; записываем rax (с выделенной памятью) в rdi
				pop rsi				; записываем в rsi значение rdi из стека в качестве указателя (для str_scpy)
				call ft_strcpy		; вызываем ft_strcpy(rdi, rsi)
end:			ret
