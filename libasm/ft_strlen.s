# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 22:30:38 by emabel            #+#    #+#              #
#    Updated: 2020/10/20 22:30:38 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; size_t	ft_strlen(char *str);

				section .text
				global ft_strlen

ft_strlen:		mov rax, 0              ; i = 0
loop:			cmp byte [rdi + rax], 0 ; начинаем сравнивать указатель с 0 (конец строки '\0')
				je   end				; если равно '\0', то идем на end
				inc  rax 				; увеличиваем rax на 1
				jmp loop				; снова переходим к loop
end:			ret						; return (возвращаем rax)
 