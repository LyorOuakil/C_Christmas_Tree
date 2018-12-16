#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	affiche_first_bloc(int last)
{
		int firstline = 1;
		int espace = (last - firstline) / 2;
		int k;

		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < espace; j ++)
			{
				my_putchar(' ');
			}
				espace--;
				k = 0;
				while (k < firstline)
				{
					my_putchar('*');
					k++;
				}
				firstline += 2;
			my_putchar('\n');
		}
}

void	algo_tronc(int nb, int last)
{
	int i = 0;
	int j = 0;
	int k;
	int width;
	int espace;

	if (nb % 2 == 0)
		width = nb + 1;
	else
		width = nb;
	
	espace = last / 2 - width / 2;
	while(i < nb)
		{
			k = 0;
			while(k < espace)
			{
				my_putchar(' ');
				k++;
			}	
			j = 0;
			while(j < width)
			{
			my_putchar('|');
			j++;
			}
			my_putchar('\n');
			i++;	
		}
}

void affichage_blocs(int nb, int last, int firstline, int nbline)
{
	int espace;
	for(int k = 2; k <= nb; k++) 
	{
		nbline++;
		if (k % 2 == 0)
		{
						firstline -= k; //La premiere ligne d'un bloc --> toujours 2 etoiles en moins si pair
		}
		else
		{
						firstline = firstline - (k - 1);// si impair --> toujours 1 etoile en moins
		}
		espace = (last - firstline) / 2;
		for(int h = 0; h < nbline; h++)
		{
			for(int i = 0; i < espace; i++)
			{
					my_putchar(' ');
			}
				espace--;
				for(int j = 0; j < firstline; j++)
				{
					my_putchar('*');
				}
			my_putchar('\n');
			firstline = firstline + 2; //deux etoiles supplémentaires apres chaque ligne
		}
		firstline -= 2;
	}	
algo_tronc(nb, last);
}

void	display(int nb)
{
	int nbline = 4; // reference au premier bloc inchangé du sapin
	int first = 7; // idem
	int countStars;
	int last;

	if(nb == 1)
	{
		affiche_first_bloc(7);
		algo_tronc(nb, 7);
		return;
	}	
	//calcul le nombre d'étoiles de la derniere ligne
	for (int i = 2; i <= nb; i++) //variable i commence à 2 sinon espace trop important
	{
			if(i % 2 == 0)
			{	
				countStars = i;
			}
			else
			{
					countStars = i - 1;
			}
		last = (first - countStars) + (nbline) * 2;// calcul pour avoir le nombre d'étoile
		first = last; //modifie valeur de first en fct de la valeur de l'argument donné
		nbline++;//toujours augmente de 1 apres chaque ligne
	}
	affiche_first_bloc(last);
	
	int firstline = 7;
	nbline = 4;
	affichage_blocs(nb, last, firstline, nbline);
}

void	sapin(int size)
{
	display(size);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
			write(2, "Sapin takes its size as its first argument\n", 43);
				return 0;
	}

	if (atoi(argv[1]) < 1)
	{
	write(2, "The argument must be positive\n", 31);
					return 0;
	}
	sapin(atoi(argv[1]));
}
