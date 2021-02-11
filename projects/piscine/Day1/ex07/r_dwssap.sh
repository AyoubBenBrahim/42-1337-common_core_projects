cat /etc/passwd | sed '/^#/d' |awk "NR%2==0"| cut -d : -f1  | rev |sort -r | awk 'NR>= ENVIRON["FT_LINE1"] && NR<= ENVIRON["FT_LINE2"]' | sed 's/$/,/' | tr '\n' ' '  | sed 's/, $/./' | tr -d '\n'	  
