#include <filler.h>

int test(t_filler *test)
{
	char **tmp;

	FILE *f = fopen("../log.txt", "a+");
	fprintf(f, "MAP\n");
	fprintf(f, "\tx(col) = %d\n\ty(row) = %d\n\n", test->x, test->y);
	fprintf(f, "map:\n");

	tmp = test->map;
	int i = 0;
	while (*tmp)
	{
		fprintf(f, "[%03d] : %s\n", i++, *tmp);
		tmp++;
	}


	fprintf(f, "TOKEN\n");
	fprintf(f, "\tx(col) = %d\n\ty(row) = %d\n\n", test->token->x, test->token->y);
	fprintf(f, "token:\n");

	tmp = test->token->token;
	i = 0;
	while (*tmp)
	{
		fprintf(f, "[%03d] : %s\n", i++, *tmp);
		tmp++;
	}

	fprintf(f, "\nIMAP\n");

	int **itmp = test->imap;
	i = 0;
	int j;
	while (i < test->y)
	{
		j = 0;
		fprintf(f, "[%03d] : ", i);
		while (j < test->x)
			fprintf(f, "%d", itmp[i][j++]);
		i++;
		fprintf(f, "\n");
	}
	fclose(f);
	return (0);
}
