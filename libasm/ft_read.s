# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 15:05:23 by emabel            #+#    #+#              #
#    Updated: 2020/10/18 15:05:23 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; ssize_t ft_read(int fd, void *buf, size_t count);

				section .text
				global	ft_read
				extern __errno_location

ft_read:		mov rax, 0x00			; записываем в rax код вызова read
				syscall					; вызываем syscall
				cmp rax, 0				; if (rax < 0)
				jl error				; "Jump if less" to error
				ret					
error: 			neg rax					; меняем знак rax на положительный
				mov rdi, rax 				; записываем rax в стек
				call __errno_location 	; rax = &errno
				mov [rax], rdi	 		; 
				mov rax, -1 			; записываем в аккумулятор -1
				ret
