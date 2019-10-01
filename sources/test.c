/******************************************************************************/
/*                          ПЕРЕД СДАЧЕЙ УДАЛИТЬ                              */
/******************************************************************************/
#include <filler.h>

void test_input(t_elem *elem)
{
	char **tmp;
	FILE *f = fopen("../log.txt", "a+");

	fprintf(f, "\n---MAP (from input)---\n");
	tmp = (char**)elem->data;
	if (*tmp == NULL)
		fprintf(f, "NULL\n");
	while (*tmp)
		fprintf(f, "%s\n", *tmp++);
	fclose(f);
}

int test(t_filler *test)
{
	FILE *f = fopen("../log.txt", "a+");
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

void test_trace(t_filler *filler, t_pos map, t_pos token, int score)
{
	fprintf(stderr, "this score\t%d\n", score);
	fprintf(stderr, "filler->score\t%d\nfiller->result.y\t%d\nfiller->result.x\t%d\n",
		filler->score, filler->result.y, filler->result.x);
	fprintf(stderr, "map.y\t%d\nmap.x\t%d\n", map.y, map.x);
	fprintf(stderr, "token.y\t%d\ntoken.x\t%d\n", token.y, token.x);
	fprintf(stderr, "\t---\t\n");
}

void test_imap(t_elem *elem)
{
	FILE *f = fopen("../log.txt", "a+");
	fprintf(f, "\nMAP\n");

	int **itmp = (int**)elem->data;
	int i = 0;
	int j;
	while (i < elem->y)
	{
		j = 0;
		fprintf(f, "[%03d] : ", i);
		while (j < elem->x)
			fprintf(f, "%d", itmp[i][j++]);
		i++;
		fprintf(f, "\n");
	}
	fclose(f);
}
