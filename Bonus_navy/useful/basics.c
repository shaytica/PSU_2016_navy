/*
** basics.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy/useful
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Thu Feb  2 16:41:17 2017 benoit pingris
** Last update Sat Feb  4 22:17:41 2017 Benjamin GAYMAY
*/

#include "my.h"
#include "my_printf.h"

int	my_power_rec(int nb, int p)
{
  int	nbr;

  if (p < 0)
    nbr = 0;
  else
    {
      nbr = 1;
      if (p > 0)
	nbr = my_power_rec(nb, p - 1) * nb;
    }
  return (nbr);
}

void	my_putstr_tab(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 'x')
	my_printf(RED"%c"WHITE, str[i]);
      else if (str[i] == 'o')
	my_printf(BLUE"%c"WHITE, str[i]);
      else if (str[i] == '.')
	my_printf(CYAN"%c"WHITE, str[i]);
      else
	my_putchar(str[i]);
      if (str[i] != '\0')
	my_putchar(' ');
      i++;
    }
}

void	my_showtab(char **tab, char **tab2)
{
  int	i;

  i = 0;
  my_putstr(GREEN);
  my_putstr("\n |");
  my_putstr(WHITE);
  my_putstr("A B C D E F G H\t\t");
  my_putstr(GREEN);
  my_putstr(" |");
  my_putstr(WHITE);
  my_putstr("A B C D E F G H\n");
  my_putstr(GREEN);
  my_putstr("-+---------------\t\t-+---------------\n");
  my_putstr(WHITE);
  while (tab[i])
    {
      my_putchar(i + 49);
      my_putstr(GREEN);
      my_putchar('|');
      my_putstr(WHITE);
      my_putstr_tab(tab[i]);
      my_putstr("\t\t");
      my_putchar(i + 49);
      my_putstr(GREEN);
      my_putchar('|');
      my_putstr(WHITE);
      my_putstr_tab(tab2[i++]);
      my_putchar('\n');
    }
}

/* void	my_showtab(char **tab) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   my_putstr(" |A B C D E F G H\n"); */
/*   my_putstr("-+---------------\n"); */
/*   while (tab[i]) */
/*     { */
/*       my_putchar(i + 49); */
/*       my_putchar('|'); */
/*       my_putstr_tab(tab[i++]); */
/*       my_putchar('\n'); */
/*     } */
/* } */

int	check_neg(int i, int my_neg, char *str_nbr)
{
  int	a;

  a = 1;
  while (i - a >= 0 && str_nbr[i - a] == '-')
    {
      my_neg = my_neg * (-1);
      a = a + 1;
    }
  return (my_neg);
}

int	my_getnbr(char *str_nbr)
{
  int	i;
  int	my_nbr;
  int	my_neg;

  i = 0;
  my_nbr = 0;
  my_neg = 1;
  while ((str_nbr[i] < '0') || (str_nbr[i] > '9'))
    i++;
  while (('0' <= str_nbr[i]) && (str_nbr[i] <= '9'))
    {
      my_neg = check_neg(i, my_neg, str_nbr);
      my_nbr = my_nbr * 10;
      my_nbr = my_nbr + (str_nbr[i] - 48);
      i++;
    }
  my_nbr = my_nbr * my_neg;
  if ((my_nbr < -2147483637) || (my_nbr > 2147483637))
    return (0);
  return (my_nbr);
}
