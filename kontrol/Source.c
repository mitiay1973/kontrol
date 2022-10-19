#include <stdio.h>
#include <malloc.h>

int pribav1(int a)
{
	return a + 1;
}
int ostatok(int a)
{
	return a % 5;
}
int (*f[2])(int);
int* func(int(*f)(int), int* first, int* dlina)
{
	for (size_t i = 0; i < dlina; i++)
	{
		*first = f(i);
		printf("%d ", *first);
		first++;
	}
	printf("\n");
	return first;
}
int matrica(int razm)
{
	int chislo = 0;
	int** massiv = malloc(razm * sizeof(int));
	for (int i = razm; i >= 0; i--)
	{
		massiv[i] = malloc((i + 1) * sizeof(int));
		for (int j = 0; j <= i*2; j++)
		{
			massiv[i][j] = chislo;
			chislo++;
		}
		chislo = 0;
	}
	for (int i = razm; i  >= 0 ; i--)
	{
		for (int j = 0; j <= i*2 ; j++)
		{
			printf("%d ", massiv[i][j]);
		}
		printf("\n");
	}
	return 0;
}
struct list
{
	int a;
	struct list* next;
};
typedef struct list* LOS;
LOS spisok(int razm)
{
	LOS los = calloc(1, sizeof(struct list));
	LOS p = los;
	LOS pp;
	p->a = 0;
	for (size_t i = 0; i < razm; i++)
	{
		pp= calloc(1, sizeof(struct list));
		p->next = pp;
		pp->a = p->a + 1;
		p = pp;
	}
	p->next = NULL;
	return los;
}
LOS print(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}
LOS del(LOS los)
{
	LOS p = los;
	while (p)
	{
		p = los->next;
		free(los);
		los = p;
	}
	printf("Список удален");
}

int main()
{
	system("chcp 1251>nul");
	int vibor = 0;
	printf("Выберите задание ");
	scanf_s("%d", &vibor);
	int razmer;
		if (vibor == 1)
		{
			printf("Введите размерность массива ");
			scanf_s("%d", &razmer);
			f[0] = pribav1;
			f[1] = ostatok;
			int* mass = calloc(razmer, sizeof(int));
			printf("\nИзначальный массив\n");
			for (size_t i = 0; i < razmer; i++)
			{
				printf("%d ", *mass + i);
			}
			printf("\nПрибавление единицы\n");
			func(f[0], mass, razmer);
			printf("Остаток от деления на 5\n");
			func(f[1], mass, razmer);
		}
		if (vibor == 2)
		{
			printf("Введите размерность массива ");
			scanf_s("%d", &razmer);
			matrica(razmer);
		}
		if (vibor == 3)
		{
			printf("Введите размерность массива ");
			scanf_s("%d", &razmer);
			print(spisok(razmer));	
			del(spisok(razmer));
		}
	return 0;
}