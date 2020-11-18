#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{

    int nb_case;
    int lance_complet;
    int nb_tour;

    dessin_oie();
    printf("Bienvenue dans cette edition du jeu de l'oie en C.\n");
    printf("Pour lancer un des, appuyez sur la touche Entrez.\n");
    nb_tour = 1;
    while (nb_case != 66)
    {
        printf("____________________________\n");
        printf("Tour Numero : %d\n", nb_tour);
        printf("____________________________\n\n");

        //appel de la fonction qui lance les dés
        lance_complet=lance_des();
            nb_case = nb_case + lance_complet;

        printf("Vous allez en case %d\n", nb_case);

                if(nb_case%9==0 && nb_case != 63 )
                    {
                      printf("Vous tombez sur une oie, vous avancez de 8 cases supplémentaires\n");
                    nb_case = nb_case + 8;
                    printf("vous allez donc a la case %d\n\n",nb_case);
                    }

                if(nb_case == 63 )
                    {
                  printf("Vous êtes en case 63, cela veut dire que votre lance est double\n");
                    nb_case = nb_case*2;
                    printf("Vous allez donc a la case %d\n", nb_case);
                    }



                if(nb_case == 58)
                    {
                  printf("Vous êtes tombe sur la tete de mort !!\n");
                    nb_case = 0;
                    printf("Vous retournez donc a la case depart :(\n");
                    }

                if(nb_case > 66 )
                    {
                   printf("Vous etes arrive plus loin que 66, vous retounez donc en arriere de %d\n", (66-nb_case));
                    nb_case = nb_case - (66-nb_case);
                    }


        /*switch (nb_case)
                {
                case nb_case%9==0 && nb_case != 63 :
                    printf("Vous tombez sur une oie, vous avancez de 8 cases supplémentaires\n");
                    nb_case = nb_case + 8;
                    printf("vous allez donc a la case %d\n",nb_case);
                    break;

                case nb_case == 63 :
                    printf("Vous êtes en case 63, cela veut dire que votre lance est double\n");
                    nb_case = nb_case*2;
                    printf("Vous allez donc a la case %d\n", nb_case);
                    break;

                case nb_case == 58 :
                    printf("Vous êtes tombe sur la tete de mort !!\n");
                    nb_case = 0;
                    printf("Vous retournez donc a la case depart :(\n");
                    break;
                case nb_case > 66 :
                    printf("Vous etes arrive plus loin que 66, vous retounez donc en arriere de %d\n", (66-nb_case));
                    nb_case = nb_case - (66-nb_case);
                    break;
                }*/

                nb_tour++;


    }
    printf("Bravo !!!! Vous avez gagné !\n");

    return 0;
}

int lance_des()
{
    int pr_lance;
    int dx_lance;
    int lance_complet;


    printf("Lancez le premier des :\n");
    getchar();
    pr_lance = (rand()%(6)+1);
    printf("Votre premier lance est %d\n\n", pr_lance);

    printf("Faites votre deuxieme lance en appuyant sur Entrez :\n");
    getchar();
    dx_lance = (rand()%(6)+1);
    printf("Votre second lance est %d\n\n", dx_lance);

    lance_complet = (pr_lance + dx_lance);
    printf("Votre lance complet est %d\n\n", lance_complet);

    return lance_complet;

}

void dessin_oie()
{
    printf("                               ,-""   `.\n");
    printf("                             ,'  _   e )`-._\n");
    printf("                            /  ,' `-._<.===-'\n");
    printf("                           /  /\n");
    printf("                          /  ;\n");
    printf("              _.--.__    /   ;\n");
    printf(" (`._    _.-''       '--'    '\n");
    printf(" <_  `-''                     \\ \n");
    printf("  <`-                          :\n");
    printf("   (__   <__.                  ;\n");
    printf("     `-.   '-.__.      _.'    /\n");
    printf("        \      `-.__,-'    _,'\n");
    printf("         `._    ,    /__,-'\n");
    printf("            ""._\__,'< <____\n");
    printf("                 | |  `----.`.\n");
    printf("                 | |        \ `.\n");
    printf("                 ; |___      \-``\n");
    printf("                 \   --<\n");
    printf("                  `.`.<\n");
    printf("                    `-'\n");
}




















