
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int check_spaces(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return 1;
    return 0;
}


int     word_counts(char *str)
{
	int space_count;
	int i;

	space_count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if(check_spaces(str[i]))
        {
			if(check_spaces(str[i]))
                space_count++;
		}
		i++;
	}
	return (space_count);
}

int     count_characters(char *str, int i)
{
	int char_count;

	char_count = 0;
	while(str[i])
	{
		if(!check_spaces(str[i+1]))
			char_count++;
		else
			break;
		i++;
	}
	return (char_count);
}

char	**ft_split_whitespaces(char *str)
{
	int     i;
	int     j;
	int     k;
	char    **array;
	char    *sub_array;
	int     space;

	i = 0;
	j = 0;
	k = 0;

	array = (char**)malloc(sizeof(char*)*(word_counts(str) + 2));
	while(str[i] != '\0')
	{
		if(check_spaces(str[i]))
			i++;
		else
		{           
			sub_array = malloc(sizeof(char) * (count_characters(str, i) + 1));
			k = 0;
			while(!check_spaces(str[i]) && str[i] != '\0')
			{
				sub_array[k] = str[i];
				i++;
				k++;
			}
			sub_array[k] = '\0';
            array[j] = sub_array;
			j++;
		}
	}

//	for(i = 0;i<j;i++)
//		printf("%s\n",array[i]);


return array;
}
//--------------
void    ft_print_words_tables(char **tab)
{
    int i;
    int j;
    
    i = 0;
    while (tab[i] != '\0')
    {
        j = 0;
        while (tab[i][j] != '\0')
        {
            ft_putchar(tab[i][j]);
            j++;
        }
        i++;
        ft_putchar('\n');
    }
}
//--------------
int main() 
{

	   char    **tab;
       char    tableau[] = "bac bac abcd  cdghg jhdh 12 abcd sa bc st 12 ll";
	//        //   int        i;
	//            
	 tab = ft_split_whitespaces(tableau);
//                   ft_split_whitespaces(tableau);
    ft_print_words_tables(tab);
	//                   //    i = 0;
	//                       
	//                         //  for(i = 0;i<8;i++)
	//                            //     printf("%c", *tab[i]);
	//                                
                                   return 0;
}
