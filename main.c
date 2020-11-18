#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIN 66
#define RMAX 6
#define RMIN 1
#define DOUBLE 63
#define T_MORT 58
#define D_MAX 12
#define D_MIN 2

//PROTOTYPES_____________________
int lance_des();
void Quel_Case(int);
void dessin_oie();
void message_victoire();


//PROGRAMME PRINCIPAL__________________________________________
int main()
{

    int nb_case;
    int lance_complet;
    int nb_tour;

    //Dessin pour rendre le jeu plus visuel et plus sympa
    dessin_oie();

    //initialisation du timer pour le random
    srand(time(0));

    //Affichage message d'accueil
    printf("Bienvenue dans cette edition du jeu de l'oie en C.\n");
    printf("Pour lancer un des, appuyez sur la touche Entrez.\n");
    //initialisation de l'etat du nombre de tour de jeu
    nb_tour = 1;

    //Boucle principale du jeu qui itere jusqu'a ce que le joueur atteinge la case de fin (66)
    while (nb_case != FIN)
    {
        printf("____________________________\n");
        printf("Tour Numero : %d\n", nb_tour);
        printf("____________________________\n\n");

        //appel de la fonction qui lance les dés
        lance_complet=lance_des();
            nb_case = nb_case + lance_complet;

            if (lance_complet<=D_MAX && lance_complet>=D_MIN)
                {

                    Quel_Case(nb_case);
                }
                else
                {
                    printf("Votre lance n'est pas valide !\n");
                }

                nb_tour++;



    }
    //Message de victoire en ASCII Art
   message_victoire();

    return 0;
}

//FONCTION_____________________________________________________

//Cette fonction genere et affiche les deux lancements de DES
int lance_des()
{
    int pr_lance;
    int dx_lance;
    int lance_complet;


    printf("Lancez le premier des :\n");
    //Recupere une entree clavier pour valider le lancement
    getchar();

    //genere une valeure de façon aleatoire
    pr_lance = (rand()%(RMAX)+1);

    //Et enfin affiche cette valeur
    printf("Votre premier lance est %d\n\n", pr_lance);

    //On reitaire l'operation pour le second lance
    printf("Faites votre deuxieme lance en appuyant sur Entrez :\n");
    getchar();
    dx_lance = (rand()%(RMAX)+1);
    printf("Votre second lance est %d\n\n", dx_lance);

    //Calcul la valeur du lance complet
    lance_complet = (pr_lance + dx_lance);

    //Affiche le lance complet
    printf("Votre lance complet est %d\n\n", lance_complet);

    //Renvoie la valeur "lance_complet" dans le main
    return lance_complet;

}

//PROCEDURES_______________________________________________________

void Quel_Case(nb_case)
{
            printf("Vous allez en case || %d ||\n", nb_case);

                //ICI on verifie si le numero de case est un multiple de 9 et est different de la case 63
                if(nb_case%9==0 && nb_case != DOUBLE )
                    {
                      printf("Vous tombez sur une oie, vous avancez du double de votre lance\n");
                    nb_case = nb_case*2;
                    printf("vous allez donc a la case || %d ||\n\n",nb_case);
                    printf("               __\n");
                    printf("             <(o )___\n");
                    printf("              ( ._> /\n");
                    printf("               `---' \n");
                    }




                //ICI on verifie si on est sur la case tete de mort (58)
                if(nb_case == T_MORT)
                    {
                  printf("Vous êtes tombe sur la tete de mort !!\n");
                    nb_case = 0;
                    printf("Vous retournez donc a la case depart :(\n");
                    printf("  _____\n");
                    printf(" /     \\\n");
                    printf("| () () |\n");
                    printf(" \\  ^  / \n");
                    printf("  |||||\n");
                    printf("  |||||\n");


                    }

                //ICI on verifie si le lance de DES emmène l'utilisateur après la case 66
                if(nb_case > FIN )
                    {
                   printf("Vous etes arrive plus loin que 66, vous retounez donc en arriere de %d\n", (FIN-nb_case));
                    nb_case = 66 + (FIN-nb_case);
                    printf("vous retournez donc en case || %d ||\n", nb_case);
                    }

        //VERSION PLUS OPTIMALE (NE FONCTIONNE PAS POUR LE MOMENT)
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
}


// Procedure qui dessine une oie
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

//procedure qui affiche le message de victoire
void message_victoire()
{
printf("######                                 #     # \n");
printf("#     # #####    ##   #    #  ####     #     #  ####  #    #  #### \n");
printf("#     # #    #  #  #  #    # #    #    #     # #    # #    # #  \n");
printf("#     # #    #  #  #  #    # #    #    #     # #    # #    # #  \n");
printf("######  #    # #    # #    # #    #    #     # #    # #    #  ####  \n");
printf("#     # #####  ###### #    # #    #     #   #  #    # #    #      # \n");
printf("#     # #   #  #    #  #  #  #    #      # #   #    # #    # #    # \n");
printf("######  #    # #    #   ##    ####        #     ####   ####   ####  \n\n");

printf(" #####                                        ### \n");
printf("#     #   ##    ####  #    # ###### ######    ### \n");
printf("#        #  #  #    # ##   # #          #     ### \n");
printf("#  #### #    # #      # #  # #####     #       # \n");
printf("#     # ###### #  ### #  # # #        #          \n");
printf("#     # #    # #    # #   ## #       #        ### \n");
printf(" #####  #    #  ####  #    # ###### ######    ### \n");


}




















