cat /etc/passwd | grep -v "#" | cut -d ":" -f 1 | AWK 'NR%2==1' | rev | sort -r | sed -n ${FT_LINE1},${FT_LINE2}p | awk 1 ORS=", " | sed s/..$/./ | cat -e
