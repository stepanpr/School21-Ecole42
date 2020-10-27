# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 23:06:08 by emabel            #+#    #+#              #
#    Updated: 2020/10/20 23:06:08 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; ssize_t	ft_write(int fd, const void *buf, size_t count);

				section .text 
				global ft_write
				extern __errno_location

ft_write:		mov rax, 0x01 			; записываем в rax код вызова write
				syscall					; вызываем syscall
				cmp rax, 0				; if (rax < 0)
				jl error				; "Jump if less" to error
				ret
error: 			neg rax					; меняем знак rax на положительный
				mov rdx, rax			; save value returned by syscall
				call __errno_location 	; call error; rax = &errno
				mov [rax], rdx			; *[errno] = error value
				mov rax, -1				; записываем в аккумулятор -1
				ret


