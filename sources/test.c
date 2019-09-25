#include <filler.h>

int test(t_filler *test)
{
	// char **tmp;

	FILE *f = fopen("../log.txt", "a+");
	// fprintf(f, "MAP\n");
	// fprintf(f, "\tx(col) = %d\n\ty(row) = %d\n\n", test->map->x, test->map->y);
	// fprintf(f, "map:\n");

	// tmp = (char**)test->map->data;
	// int i = 0;
	// while (*tmp)
	// {
	// 	fprintf(f, "[%03d] : %s\n", i++, *tmp);
	// 	tmp++;
	// }


	// fprintf(f, "TOKEN\n");
	// fprintf(f, "\tx(col) = %d\n\ty(row) = %d\n\n", test->token->x, test->token->y);
	// fprintf(f, "token:\n");

	// tmp = (char**)test->token->data;
	// int i = 0;
	// while (*tmp)
	// {
	// 	fprintf(f, "[%03d] : %s\n", i++, *tmp);
	// 	tmp++;
	// }

	fprintf(f, "\nMAP\n");

	int **itmp = (int**)test->map->data;
	int i = 0;
	int j;
	while (i < test->map->y)
	{
		j = 0;
		fprintf(f, "[%03d] : ", i);
		while (j < test->map->x)
			fprintf(f, "%d", itmp[i][j++]);
		i++;
		fprintf(f, "\n");
	}

	fprintf(f, "\nTOKEN\n");

	int **itok = (int**)test->token->data;
	i = 0;
	j = 0;
	while (i < test->token->y)
	{
		j = 0;
		fprintf(f, "[%03d] : ", i);
		while (j < test->token->x)
			fprintf(f, "%d", itok[i][j++]);
		i++;
		fprintf(f, "\n");
	}
	fclose(f);
	return (0);
}
