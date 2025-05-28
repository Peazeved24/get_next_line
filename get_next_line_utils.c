#include "get_next_line.h"

size_t ft_linelen(char *str) // ft exclusiva para leitura de txt.
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i + 1);   
        i++;
    }     
    return(i);
}

char *strjoin_line(char *s1, char *s2)
{
    size_t i;
    size_t j;
    size_t len1;    
    size_t len2;
    char *s3;

    i = 0;
    j = 0;
    len1 = 0;
    len2 = 0;
    if (s1)
        while (s1[len1])
            len1++;
    len2 = ft_linelen(s2);
    s3 = malloc(len1 + len2 + 1);
    if (!s3)
        return (NULL);
    while(i < len1)
        s3[j++] = s1[i++];
    i = 0;
    while(i < len2)
         s3[j++] = s2[i++];
    s3[j] = '\0';
    free(s1);
    return (s3);
}

int	findnextline(char *buffer)
{
	size_t	i = 0;

	while (buffer[i])
	{
        if (buffer[i] == '\n')
			return 1;   
        i++;
	}
	return 0;
}

void shift_buffer(char *buffer)
{
    size_t i = 0;
    size_t j = 0;

    // 1. Avança até o final da primeira linha (até encontrar '\n' ou fim da string)
    while (buffer[i] && buffer[i] != '\n')
        i++;
    // 2. Se encontrou '\n', pula ele também (começa após a quebra de linha)
    if (buffer[i] == '\n')
        i++;
    // 3. Copia o restante do buffer para o início, sobrescrevendo a linha removida
    while (buffer[i])
        buffer[j++] = buffer[i++];
    // 4. Preenche o resto do buffer com '\0' para garantir que não sobra lixo
    while (j < BUFFER_SIZE)
        buffer[j++] = '\0';
}
