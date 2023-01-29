#include "header.h"

/***************************** Grammaire **************************************/
/**
 * Lecture de la grammaires
 * grammaire donner par l'utilisateur Ou
 * grammaire donner par défaut
 */
void readProduction()
{
    // nombre de production
    int num;
    //réponse
    int rep;
    //
    int regleI = 0;
    // //menu

    printf("\033[1;34m");
    printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤                      \n");
    printf("\t ¤                                                                     ¤\n");
    printf("\033[0m");
    printf("\033[1;32m");
    system("setterm -bold on");
    printf("\033[1;35m");
    printf("\t ¤              Bienvenue dans Notre Analyseur syntaxique              ¤                       \n");
    printf("\033[0m");
    system("setterm -bold off");
    printf("\033[1;34m");
    printf("\t ¤                                                                     ¤\n");
    printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤                      \n");
    printf("\n\n");
    do
    {
        printf("\n \n");
        system("setterm -bold on");
        printf("\033[1;34m");
        printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤");
        system("setterm -bold on");
        printf("\033[1;35m");
        printf(" Analyseur syntaxique déscendant ");
        printf("\033[0m");
        system("setterm -bold off");
        printf("\033[1;34m");

        printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n \n");
        printf("\033[0m");
        printf("\033[1;35m");
        printf("\t                     1- ");
        printf("\033[0m");
        system("setterm -bold on");
        printf("Saisir votre grammaire            \n");
        system("setterm -bold off");
        printf("\033[1;35m");
        printf("\t                     2- ");
        printf("\033[0m");
        system("setterm -bold on");
        printf("Utiliser un exemple          \n \n");
        system("setterm -bold off");
        printf("\033[1;34m");
        printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n \n");
        printf("\033[0m");
        system("setterm -bold off");
        system("setterm -bold on");
        printf(" Option : ");
        system("setterm -bold off");
        scanf("%d", &rep);

    } while (rep != 1 && rep != 2);
    char stringValue[10] = "";
    if (rep == 1)
    {
        do
        {
            printf("Entrer le nombre de régles : ");
            scanf("%d", &nbLigneProdWR);
        } while (nbLigneProdWR <= 0 || nbLigneProdWR > 30);
        printf("Entrer le nombre maximale des sous régles : ");
        scanf("%d", &nbColProdWR);

        nbColProdWR += 1;
        for (int i = 0; i < nbLigneProdWR; i++)
        {
            printf("Entrer l'axiome de la %d régle : ", i + 1);
            scanf("%s", stringValue);
            strcpy(productionWR[i][0], stringValue);
            printf("Entrer le nombre de sous régles de la régle d'axiome (%s) : ", productionWR[i][0]);
            scanf("%d", &regleI);
            for (int j = 1; j < nbColProdWR; j++)
            {
                if (j <= regleI)
                {
                    printf("Entrer la %d sous régles de la régle d'axiome (%s) : ", j, productionWR[i][0]);
                    scanf("%s", &stringValue);
                    strcpy(productionWR[i][j], stringValue);
                }
            }
        }
    }
    else
    {
        //Option 2 - Grammaire par défaut
        // nbLigneProdWR = 3;
        // nbColProdWR = 3;
        // // La grammaire
        // strcpy(productionWR[0][0], "A");
        // strcpy(productionWR[0][1], "A+B");
        // strcpy(productionWR[0][2], "B");
        // strcpy(productionWR[1][0], "B");
        // strcpy(productionWR[1][1], "B*C");
        // strcpy(productionWR[1][2], "C");
        // strcpy(productionWR[2][0], "C");
        // strcpy(productionWR[2][1], "(A)");
        // strcpy(productionWR[2][2], "a");

        // nbLigneProdWR = 4;
        // nbColProdWR = 3;
        // // La grammaire
        // strcpy(productionWR[0][0], "D");
        // strcpy(productionWR[0][1], "ABC");
        // strcpy(productionWR[1][0], "A");
        // strcpy(productionWR[1][1], "a");
        // strcpy(productionWR[1][2], "#");
        // strcpy(productionWR[2][0], "B");
        // strcpy(productionWR[2][1], "b");
        // strcpy(productionWR[2][2], "#");
        // strcpy(productionWR[3][0], "C");
        // strcpy(productionWR[3][1], "c");
        // strcpy(productionWR[3][2], "#");

        nbLigneProdWR = 2;
        nbColProdWR = 5;
        // La grammaire
        strcpy(productionWR[0][0], "A");
        strcpy(productionWR[0][1], "c");
        strcpy(productionWR[0][2], "BA");
        strcpy(productionWR[0][3], "a");
        strcpy(productionWR[0][4], "b");
        strcpy(productionWR[1][0], "B");
        strcpy(productionWR[1][1], "dA");
    }
}
/**
 * Affichage de la grammaires avant l'élimination de la récursivité
 */
void PrintProductionWR()
{
    printf("\n");

    system("setterm -bold on");
    printf(" ¤ La grammaire : \n ");
    system("setterm -bold off");
    for (int i = 0; i < nbLigneProdWR; i++)
    {
        // Affichage du non terminale
        printf("  %s -> ", productionWR[i][0]);
        int j = 1;
        while (strlen(productionWR[i][j]) > 0)
        {
            // Affichage des régles
            if (strlen(productionWR[i][j + 1]) > 0)
                printf("%s | ", productionWR[i][j]);
            else
            {
                printf("%s ", productionWR[i][j]);
            }
            j++;
        }
        printf("\n ");
    }
    printf("\n ");
}
/**
 * Affichage de la grammaires aprés l'élimination de la récursivité
 */
void PrintProduction()
{
    printf("\n");
    system("setterm -bold on");
    printf(" ¤ La grammaire sans récursivité à gauche : \n ");
    system("setterm -bold off");
    for (int i = 0; i < nbLigneProd; i++)
    {
        // Affichage du non terminale
        printf("  %s -> ", production[i][0]);
        int j = 1;
        while (strlen(production[i][j]) > 0)
        {
            // Affichage des régles
            if (strlen(production[i][j + 1]) > 0)
                printf("%s | ", production[i][j]);
            else
            {
                printf("%s ", production[i][j]);
            }
            j++;
        }
        printf("\n ");
    }
    printf("\n");
}

/***************************** Les non terminaux **************************************/
/**
 * Verifier un caractére existe dans un tableau ou non
 * @param char[] //table des caractéres
 * @param int // Taille du table
 * @param char // Le caractére à chercher
 * @return int // 0 si le cartére n'existe pas sinon 1
 */
int exist(char *t, int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        if (t[i] == c)
            return 1;
    }
    return 0;
}
/**
 * Stocker les non terminaux dans la table "NT"
 * et les terminaux dans la table "terminal"
 */
void save_NT_Terminal()
{
    // parcourir les lignes de la table de production
    for (int i = 0; i < nbLigneProd; i++)
    {
        // parcourir les colonnes de la table de production
        for (int j = 0; j < nbColProd; j++)
        {
            // parcourir les caractéres de chaque régle
            for (int k = 0; k < strlen(production[i][j]); k++)
            {
                // Verifier le caractére est un terminale ou non
                // Si le caractére est majuscule (sig de 'A' à 'Z') c'est un non terminale
                if (!(isupper(production[i][j][k])))
                {
                    // Verifier le caractére est un epsilone ou non
                    // '#' signifie un epsilone
                    if (production[i][j][k] != '#')
                    {
                        // Verifier le caractére est déjà stocker dans la table des terminaux ou non
                        // s'il n'est pas stocker (existe retourne 0) il sera ajouter
                        if (!exist(terminal, ptrTerminal, production[i][j][k]))
                        {
                            terminal[ptrTerminal] = production[i][j][k];
                            // incrémenter la taille du pointeur
                            ptrTerminal++;
                        }
                    }
                }
                else
                {
                    // Le caractére est un non terminale. Alors il sera stocker dans la table NT
                    if (!exist(NT, ptrNT, production[i][j][k]))
                    {
                        NT[ptrNT] = production[i][j][k];
                        // incrémenter la taille du pointeur
                        ptrNT++;
                    }
                }
            }
        }
    }
    // Ajouter le caractére de fin chaine dans la table des terminaux
    terminal[ptrTerminal] = '$';
    ptrTerminal++;
    // Trier les table des terminaux
    Sort(terminal, ptrTerminal, 0);
}
/***************************** Tri des tables **************************************/
/**
 * Permuter deux caractéres
 * retourne les deux caracteres permuter
 * @param char
 * @param char
 */
void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * Trier une table par la méthode tri par sélection
 * Retourne le tableau trier
 * @param char[] // Le tableau à trier
 * @param int   // Taille du tableau à trier
 * @param int   // Indice de début du tableau
 */
void Sort(char arr[], int n, int x)
{
    int i, j, min_idx;

    // Déplacement un par un de la limite du sous-réseau non trié
    for (i = 0 + x; i < n - 1; i++)
    {

        // Trouver l'élément minimum dans un tableau non trié
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Echanger l'élément minimum trouvé
        // avec le premier élément
        swap(&arr[min_idx], &arr[i]);
    }
}

/******************* Elimination de la récursivité *****************************/
/**
 * Vérifier la ligne de prodution est récursive ou non
 * @param int   // L'indice de la ligne du production
 * @return int // retourne 1 si la ligne est récursive sinon 0
 */

int Is_Recursive(int i)
{
    int j = 1;
    // parcourir les colones du production de la ligne i
    while (strlen(productionWR[i][j]) > 0)
    {
        // Verifier l'axiome de la régle est égale à la premiére non terminale du régle ou non
        // Sig vérifier la régle de la forme
        // A->Aß|α
        if (productionWR[i][j][0] == productionWR[i][0][0])
            return 1;
        j++;
    }
    return 0;
}
/**
  *  Régle pour élimner la récursivité à gauche : A->Aß|α devient:
                             ___________
                            |           |
                            | A->αN     |
                            | N->ßN|^   |
                            |___________| 
                            donc si on a A->AB|t
                            α = t
                            ß = B
 * @param int // indice de la ligne de production                 
*/
void deleteRecursivite(int i)
{
    // table pour stocker les beta (ß)
    char beta[100][126];
    int ptrBeta = 0;
    // table pour stocker les alpha (α)
    char alpha[100][126];
    int ptrAlpha = 0;
    // le nouveau non terminale à ajouter
    char c = productionWR[i][0][0] - 'A';
    c = c + 13;
    c = c % 26;
    c = c + 'A';
    char ch[2] = "\0";
    ch[0] = c;
    // Parcourir les colones de la régle dans la ligne i du grammaire
    int j = 1;
    while (strlen(productionWR[i][j]) > 0)
    {
        // si la régle est recursive
        if (productionWR[i][j][0] == productionWR[i][0][0])
        {
            for (int k = 1; k < strlen(productionWR[i][j]); k++)
            {
                beta[ptrBeta][k - 1] = productionWR[i][j][k];
            }

            beta[ptrBeta][strlen(productionWR[i][j]) - 1] = (productionWR[i][0][0] + 13);
            ptrBeta += 1;
        }
        else
        {
            // si on n'a pas de récursivté gauche
            // sig la production est de la forme A->ß|a
            for (int k = 0; k < strlen(productionWR[i][j]); k++)
            {
                alpha[ptrAlpha][k] = productionWR[i][j][k];
            }
            if (alpha[ptrAlpha][0] == '#')
            {
                alpha[ptrAlpha][0] = (productionWR[i][0][0] + 13);
            }
            else
                alpha[ptrAlpha][strlen(productionWR[i][j])] = (productionWR[i][0][0] + 13);
            ptrAlpha += 1;
        }
        j++;
    }

    // Si pas de alpha
    // Sig la régle de la forme A->Aß
    if (ptrAlpha != 0)
    {
        strcpy(production[nbLigneProd][0], productionWR[i][0]);
        for (int i = 0; i < ptrAlpha; i++)
        {
            strcpy(production[nbLigneProd][i + 1], alpha[i]);
        }
        nbLigneProd++;
    }
    // Ajouter les nouvelles régles dans la table 'production'
    strcpy(production[nbLigneProd][0], ch);
    for (int i = 0; i < ptrBeta; i++)
    {
        strcpy(production[nbLigneProd][i + 1], beta[i]);
    }
    strcpy(production[nbLigneProd][ptrBeta + 1], "#");
    nbLigneProd++;
}
/**
 * Eliminer la récursivité à gauche dans les régles
 * et stocker les nouvelles régles sans récursivité dans la table ' production'
 */
// void recursivite(){
//     // parcourir la grammaire
//     for(int i=0;i<nbLigneProdWR;i++){
//         // Verifier la ligne admet une récursivité ou non
//         if(Is_Recursive(i)){
//             // Suprimer la récursité par la création de nouvelles régles
//             deleteRecursivite(i);
//         }else{
//             // n'est pas récursive alors copier la ligne dans la nouvelle table de production
//             int j=0;
//             while (strlen(productionWR[i][j])>0)
//             {
//                 strcpy(production[nbLigneProd][j],productionWR[i][j]);
//                 j++;
//             }
//             nbLigneProd++;
//         }

//     }
//     nbColProd=nbColProdWR;
// }

void recursivite()
{
    // parcourir la grammaire
    for (int i = 0; i < nbLigneProdWR; i++)
    {
        if (i == 0)
        {
            // Verifier la ligne admet une récursivité ou non
            if (Is_Recursive(i))
            {
                // Suprimer la récursité par la création de nouvelles régles
                deleteRecursivite(i);
            }
            else
            {
                // n'est pas récursive alors copier la ligne dans la nouvelle table de production
                int j = 0;
                while (strlen(productionWR[i][j]) > 0)
                {
                    strcpy(production[nbLigneProd][j], productionWR[i][j]);
                    j++;
                }
                nbLigneProd++;
            }
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                char tabProd[126][256];
                int ptrtabProd = 0;
                int k = 1;
                while (strlen(productionWR[i][k]) > 0)
                {

                    if (productionWR[i][k][0] == productionWR[j][0][0])
                    {
                        //Remplacer la production
                        //Ex: A->Sa|Ac|B avec S->Ab|a|AA
                        //    A->Aba|aa|AAa|Ac|B
                        char ch[100] = "";
                        int q = 1;
                        while (productionWR[i][k][q] != '\0')
                        {
                            ch[q - 1] = productionWR[i][k][q];
                            q++;
                        }
                        for (int p = 0; p < nbLigneProd; p++)
                        {
                            if (production[p][0][0] == productionWR[j][0][0])
                            {
                                printf("hneee \n");
                                int e = 1;
                                // strcpy(tabProd[ptrtabProd], production[p][0]);
                                printf(" %s ", production[p][0]);
                                while (strlen(production[p][e]) > 0)
                                {
                                    strcpy(tabProd[ptrtabProd], production[p][e]);
                                    strcat(tabProd[ptrtabProd], ch);
                                    ptrtabProd++;
                                    e++;
                                }
                            }
                        }
                        printf("\n Tab Prob : \n");
                        for (int w = 0; w < ptrtabProd; w++)
                        {
                            printf(" %s ", tabProd[w]);
                        }
                        printf("\n");
                    }
                    else
                    {
                        strcpy(tabProd[ptrtabProd], productionWR[i][k]);
                        ptrtabProd++;
                    }

                    k++;
                }
                for (int p = 0; p < ptrtabProd; p++)
                {
                    strcpy(productionWR[i][p + 1], tabProd[p]);
                }
            }
            if (Is_Recursive(i))
            {
                // Suprimer la récursité par la création de nouvelles régles
                deleteRecursivite(i);
            }
            else
            {
                // n'est pas récursive alors copier la ligne dans la nouvelle table de production
                int j = 0;
                while (strlen(productionWR[i][j]) > 0)
                {
                    strcpy(production[nbLigneProd][j], productionWR[i][j]);
                    j++;
                }
                nbLigneProd++;
            }
        }
    }
    nbColProd = nbColProdWR;
}
/************************ Calcule des premiers **********************************/

void verif(int k, int col, int carac)
{
    if (production[k][col][carac] != '\0')
    {
        findfirst(production[k][col][carac]);
        if (test == 1)
        {
            if (production[k][col][carac + 1] != '\0')
            {
                verif(k, col, carac + 1);
            }
            else
            {
                first[firstSize++] = '#';
            }
        }
    }
    else
    {
        first[firstSize++] = '#';
    }
}
/**
 * Calculer les premiers de chaque non terminale
 * et stocker les resultats dans la table 'calc_first'
 */
void CalculFirst()
{

    int jm = 0;

    int i, choice;
    char NT, ch;
    int l;
    // les non terminaux calculer
    char ntDoneFirst[nbLigneProd];
    // pointeur de la table 'ntDoneFirst'
    int ptrFirstT = -1;
    // pointeur de la table 'calc_first'
    int calc_first_Lignes = 0, calc_first_Cols;
    // verifier les premiers du non terminale sont déjà calculer ou non (soit 0 soit 1)
    int checkNtDone;

    // Initialisation du tableau calc_first par '!'
    for (int k = 0; k < nbLigneProd; k++)
    {
        for (int kay = 0; kay < 128; kay++)
        {
            calc_first[k][kay] = '!';
        }
    }

    // Parcourir la grammaire
    for (int k = 0; k < nbLigneProd; k++)
    {
        // Stocker le non terminale dans 'NT'
        NT = production[k][0][0];
        calc_first_Cols = 0;
        // Par défaut les premiers du caractére ne sont pas calculer
        checkNtDone = 0;

        // Vérifier si le First of NT a
        // déjà été calculé
        //Sig NT existe dans ntDoneFirst
        for (int l = 0; l <= ptrFirstT; l++)
            // Le non terminale déjà calculer
            if (NT == ntDoneFirst[l])
                checkNtDone = 1;

        if (checkNtDone == 1)
            continue;
        test = 0;
        testCol = 1;
        // Calculer les permier du non terminale 'NT'
        findfirst(NT);
        // verifier ep
        if (test == 1)
        {
            test = 0;

            verif(k, 1, 1);
        }
        // Trier les non terminaux
        Sort(first, firstSize, jm);
        ptrFirstT += 1;

        // Ajouter NT à la liste calculée
        ntDoneFirst[ptrFirstT] = NT;
        // Ajouter NT à calc_first
        calc_first[calc_first_Lignes][calc_first_Cols++] = NT;
        // Stocker le contenu de 'First' à partir de l'indice 'jm' dans la table calc_first
        for (i = 0 + jm; i < firstSize; i++)
        {
            int lark = 0, chk = 0;
            for (lark = 0; lark < calc_first_Cols; lark++)
            {
                if (first[i] == calc_first[calc_first_Lignes][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                calc_first[calc_first_Lignes][calc_first_Cols++] = first[i];
            }
        }
        jm = firstSize;
        calc_first_Lignes++;
    }
}

/**
 * Calculer les premiers d'un non terminale
 * Stocker la resultat dans la table 'first'
 * @param char //le non terminal
 */
void findfirst(char NT)
{
    int j;
    // Le cas où nous rencontrons un terminal
    if (!(isupper(NT)))
    {

        first[firstSize++] = NT;
    }
    for (j = 0; j < nbLigneProd; j++)
    {
        if (production[j][0][0] == NT)
        {
            for (int i = 1; i < nbColProd; i++)
            {
                if ((production[j][i][0] == '#'))
                {
                    //first[firstSize++] = '#';
                    test = 1;
                    testCol = i;
                }
                else if (!isupper(production[j][i][0]))
                {
                    //Terminale
                    first[firstSize++] = production[j][i][0];
                }
                else
                {
                    // Récursion pour calculer le premier de
                    // Nouveau Non-Terminal que nous rencontrons
                    // au début
                    findfirst(production[j][i][0]);
                }
            }
        }
    }
}

/**
 * Afficher les premiers de chaque non terminale
 */
void printFirst()
{
    printf("\n");
    system("setterm -bold on");
    printf(" ¤ Les premiers : \n");
    system("setterm -bold off");
    int j;
    for (int i = 0; i < nbLigneProd; i++)
    {
        printf("   Premiers de (%c) : ", calc_first[i][0]);
        j = 1;
        while (calc_first[i][j] != '!')
        {
            printf("%c ", calc_first[i][j]);
            j++;
        }
        printf("\n");
    }
    printf("\n \n ");
}

/************************ Calcule des suivants **********************************/
/**
 * Calculer les suivants de chaque non terminale
 * et stocker les resultats dans la table 'calc_follow'
 */
void CalculFollow()
{
    // les non terminaux calculer
    char ntDoneFollow[nbLigneProd];
    int ptrFollowT = -1;
    // verifier les suivants du non terminale sont déjà calculer ou non (soit 0 soit 1)
    int checkNtDone;
    // Socker le non terminale
    char NT;
    int km = 0;

    // Initialisation du tableau calc_follow par '!'
    for (int k = 0; k < nbLigneProd; k++)
    {
        for (int l = 0; l < 100; l++)
        {
            calc_follow[k][l] = '!';
        }
    }

    int calc_follow_Lignes = 0, calc_follow_Cols;
    int land = 0;
    // Parcourir la grammaire
    for (int e = 0; e < nbLigneProd; e++)
    {
        NT = production[e][0][0];
        calc_follow_Cols = 0;
        checkNtDone = 0;
        // Vérifier si le suivi de NT
        // a déjà été calculé
        for (int l = 0; l <= ptrFollowT; l++)
            if (NT == ntDoneFollow[l])
                checkNtDone = 1;

        if (checkNtDone == 1)
            continue;
        land += 1;
       

        // Calculer les suivants du non terminale 'NT'
        findFollow(NT);
        // Trier la table des suivants à partir de l'indice 'km'
        Sort(followT, followSize, km);

        // Ajouter NT à la liste calculée
        ntDoneFollow[ptrFollowT] = NT;
        // Ajouter NT à la table calc_follow
        calc_follow[calc_follow_Lignes][calc_follow_Cols++] = NT;

        // Stocker le contenu de 'followT' à partir de l'indice 'km' dans la table calc_follow
        for (int i = 0 + km; i < followSize; i++)
        {
            int lark = 0, chk = 0;
            for (lark = 0; lark < calc_follow_Cols; lark++)
            {
                if (followT[i] == calc_follow[calc_follow_Lignes][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                calc_follow[calc_follow_Lignes][calc_follow_Cols++] = followT[i];
            }
        }
        km = followSize;
        calc_follow_Lignes++;
    }
}

/**
 * Calculer les suivants d'un non terminale
 * Stocker la resultat dans la table 'followT'
 * @param char //le non terminal
 */
void findFollow(char NT)
{
    int i, j;

    // Ajout de "$" à la suite
    // ensemble du symbole de départ
    if (production[0][0][0] == NT)
    {
        followT[followSize++] = '$';
    }
    // parcourir la grammaire
    for (i = 0; i < nbLigneProd; i++)
    {
        for (j = 1; j < nbColProd; j++)
        {
           
            for (int k = 0; k < strlen(production[i][j]); k++)
            {
                if (production[i][j][k] == NT)
                {
                    if (production[i][j][k + 1] != '\0')
                    {
                        // Calculer le premier du prochain
                        // Non-terminal dans la production
                        followfirst(production[i][j][k + 1], i, j, k + 2);
                    }

                    if (production[i][j][k + 1] == '\0' && NT != production[i][0][0])
                    {
                            // Calculer les suivivant du non terminal.
                            findFollow(production[i][0][0]);
                    }
                }
            }
        }
    }
}
/**
 * Afficher les suivants de chaque non terminale
 */
void printFollow()
{
    system("setterm -bold on");
    printf(" ¤ Les suivants : \n");
    system("setterm -bold off");
    int j;
    for (int i = 0; i < nbLigneProd; i++)
    {
        printf("   Suivants de (%c) : ", calc_follow[i][0]);
        j = 1;
        while (calc_follow[i][j] != '!')
        {
            printf("%c ", calc_follow[i][j]);
            j++;
        }
        printf("\n");
    }
    printf("\n \n ");
}

/**
 * Calculer les premiers du non terminale
 * @param char //le non terminale
 * @param int  // l'indice de ligne
 * @param int  // l'indice de colonne
 * @param int  // l'indice de caractére suivant
 */
void followfirst(char NT, int c1, int c2, int c3)
{
    int k;

    // Le cas où l'on rencontre un terminal
    if (!(isupper(NT)))
        followT[followSize++] = NT;
    else
    {
        int i = 0, j = 1;
        for (i = 0; i < nbLigneProd; i++)
        {
            if (calc_first[i][0] == NT)
                break;
        }
        //Comprenant la première série de
        // Non-Terminal dans le suivi de
        // la requête originale
        while (calc_first[i][j] != '!')
        {
            // S'il n'est pas un epsilone "#"
            if (calc_first[i][j] != '#')
            {
                followT[followSize++] = calc_first[i][j];
            }
            else
            {
                // Dans le cas d'un epsilone
                if (production[c1][c2][c3] == '\0')
                {
                    // Cas où nous atteignons la fin d'une production
                    // Calculer les suivant du non terminale de la partie gauche (Axiome)
                    findFollow(production[c1][0][0]);
                }
                else
                {
                    // Récursion vers le symbole suivant
                    // au cas où nous rencontrerions un un epsilone "#"
                    followfirst(production[c1][c2][c3], c1, c2, c3 + 1);
                }
            }
            j++;
        }
    }
}
/************************ Calcule les premier des régles **********************************/
/**
 * Calculer les premiers de chaque régle
 */
void regle_first()
{
    //Parcourir la grammaire
    for (int i = 0; i < nbLigneProd; i++)
    {
        int j = 1;
        while (strlen(production[i][j]) > 0)

        {
            if (strlen(production[i][j]) != 0)
            {
                ptrRegleFirst += 1;
                strcpy(regleFirst[ptrRegleFirst].regle, production[i][0]);
                int ptrFirstList = 0;
                strcat(regleFirst[ptrRegleFirst].regle, "->");
                strcat(regleFirst[ptrRegleFirst].regle, production[i][j]);
                if (!(isupper(production[i][j][0])))
                {
                    regleFirst[ptrRegleFirst].firstList[ptrFirstList] = production[i][j][0];
                    ptrFirstList++;
                }
                else
                {
                    int e = 0;
                    int ep = 1;
                    while (ep == 1 && production[i][j][e] != '\0')
                    {
                        ep = 0;
                        for (int k = 0; k < nbLigneProd; k++)
                        {
                            if (calc_first[k][0] == production[i][j][e])
                            {
                                int l = 1;
                                while (calc_first[k][l] != '!')
                                {
                                    if (calc_first[k][l] == '#')
                                    {
                                        ep = 1;
                                        e++;
                                    }
                                    else
                                    {
                                        regleFirst[ptrRegleFirst].firstList[ptrFirstList] = calc_first[k][l];
                                        ptrFirstList++;
                                    }
                                    l++;
                                }
                            }
                        }
                    }
                    if (production[i][j][e] == '\0')
                    {
                        regleFirst[ptrRegleFirst].firstList[ptrFirstList] = '#';
                        ptrFirstList++;
                    }
                }
                regleFirst[ptrRegleFirst].firstListLen = ptrFirstList;
            }
            j++;
        }
    }
    ptrRegleFirst++;
    system("setterm -bold on");
    printf(" ¤ Les premiers des régles : \n");
    system("setterm -bold off");
    for (int i = 0; i < ptrRegleFirst; i++)
    {
        printf("   Premiers de (%s) : ", regleFirst[i].regle);
        for (int j = 0; j < regleFirst[i].firstListLen; j++)
        {
            printf("%c ", regleFirst[i].firstList[j]);
        }
        printf("\n");
    }
}
/************************ Table LL(1) **********************************/

/**
 * Savoir un terminale apartient à une table ou non
 * @param char // le caractére à chercher
 * @return int // la position du caractére
 */
int findPosTerminal(char c)
{
    for (int i = 0; i <= ptrTerminal; i++)
    {
        if (terminal[i] == c)
            // la position du caractére
            return i;
    }
    // si le caractére n'existe pas
    return -1;
}
/**
 * Affichage de la table d'analyse syntaxique
 */
void table_LL1_print(char c)
{
    char x = (char)' ';

    for (int k = 0; k < ptrRegleFirst; k++)
    {
        int pos_1 = 1, pos = 0;
        if (regleFirst[k].regle[0] == c)
        {
            for (int l = 0; l < regleFirst[k].firstListLen; l++)
            {
                if (regleFirst[k].firstList[l] != '#')
                {
                    printf("\n");
                    // printf("        ");
                    pos = findPosTerminal(regleFirst[k].firstList[l]);
                    if (pos > -1 && pos < ptrTerminal)
                    {
                        pos += 1;
                        for (int y = 0; y < pos * 10; y++)
                            printf(" ");
                        printf("%s", regleFirst[k].regle);
                        pos_1 = 10 - strlen(regleFirst[k].regle);
                    }
                }
                else
                {
                    pos_1 = 0;
                    int pos_length = 0;
                    printf("\n");
                    for (int j = 0; j < nbLigneProd; j++)
                    {
                        int q = 1;
                        if (calc_follow[j][0] == c)
                        {

                            while (calc_follow[j][q] != '!')
                            {

                                pos = findPosTerminal(calc_follow[j][q]);
                                if (pos != -1)
                                {
                                    pos += 1;
                                    //printf("%-10s", "");

                                    for (int y = 0; y < ((pos - pos_1) * 10) - pos_length; y++)
                                        printf(" ");
                                    printf("%s", regleFirst[k].regle);
                                    pos_1 = pos;
                                    pos_length = strlen(regleFirst[k].regle);
                                }
                                q++;
                            }
                        }
                    }
                }
            }
            //printf("\n");
        }
    }
}
/**
 * Affichage de la table d'analyse syntaxique
 */
void table_LL1()
{
    // Affichage de la table d'analyse syntaxique
    printf("\n");
    system("setterm -bold on");
    printf("\033[1;35m");
    printf("\n\t************************* Table LL(1)  *************************\n");
    printf("\033[0m");
    system("setterm -bold off");
    system("setterm -bold on");
    printf("\033[1;34m");
    printf("\t------------------------------------------------------------------\n");
    printf("\033[0m");
    system("setterm -bold off");
    printf("%-10s", "");
    // Affichage des terminaux
    for (int i = 0; i < ptrTerminal; i++)
    {
        system("setterm -bold on");
        printf("\033[1;35m");
        printf("%c         ", terminal[i]);
        printf("\033[0m");
        system("setterm -bold off");
    }
    printf("\n");
    system("setterm -bold on");
    printf("\033[1;34m");
    printf("--------------------------------------------------------------------------\n");
    printf("\033[0m");
    system("setterm -bold off");
    for (int i = 0; i < ptrNT; i++)
    {
        // Affichage de non terminale
        system("setterm -bold on");
        printf("\033[1;35m");
        printf(" %c", NT[i]);
        printf("\033[0m");
        system("setterm -bold off");
        printf("%-9s", "");
        table_LL1_print(NT[i]);
        printf("\n");
        system("setterm -bold on");
        printf("\033[1;34m");
        printf("--------------------------------------------------------------------------\n");
        printf("\033[0m");
        system("setterm -bold off");
    }
}
/************************************** Check Word ***********************************/
/************************** Stack *********************************/
void init()
{
    pile.top = -1;
    push('$');
    push(production[0][0][0]);
}
int isempty()
{

    if (pile.top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (pile.top == MAXSIZE)
        return 1;
    else
        return 0;
}

char peek()
{
    return pile.stack[pile.top];
}

char pop()
{
    int data;

    if (!isempty())
    {
        data = pile.stack[pile.top];
        pile.top = pile.top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
        exit(-1);
    }
}

void push(int data)
{

    if (!isfull())
    {
        pile.top = pile.top + 1;
        pile.stack[pile.top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}
void printPile(char *chaine)
{
    for (int i = 0; i < pile.top + 1; i++)
    {
        chaine[i] = pile.stack[i];
    }
}

/***************************** Word ********************************/
void inverseWord(char *chaine)
{
    int i, n;
    char lettre;
    char x[100];
    for (int k = 0; k < strlen(inv); k++)
    {
        inv[k] = '\0';
    }
    if (strlen(chaine) == 4)
    {
        x[0] = chaine[3];
    }
    else
    {
        int n = 0;
        for (int j = 3; j < strlen(chaine); j++)
        {
            x[n] = chaine[j];
            n++;
        }

        for (i = 0; i < n / 2; i++)
        {
            lettre = x[i];
            x[i] = x[n - i - 1];
            x[n - i - 1] = lettre;
        }
    }
    strcpy(inv, x);
    //return ch;
}

char *findAction(char axiome, char terminal)
{
    int IndexEp = -1;
    if (axiome == terminal)
    {
        return "Supprimer";
    }
    else
    {
        for (int i = 0; i < ptrRegleFirst; i++)
        {
            if (regleFirst[i].regle[0] == axiome)
            {
                for (int j = 0; j < regleFirst[i].firstListLen; j++)
                {
                    if (regleFirst[i].firstList[j] == '#')
                    {
                        IndexEp = i;
                    }
                    if (regleFirst[i].firstList[j] == terminal)
                    {
                        return regleFirst[i].regle;
                    }
                }
            }
        }
        if (IndexEp != -1)
        {
            for (int j = 0; j < nbLigneProd; j++)
            {
                int q = 1;
                if (calc_follow[j][0] == axiome)
                {
                    while (calc_follow[j][q] != '!')
                    {
                        if (calc_follow[j][q] == terminal)
                        {
                            return regleFirst[IndexEp].regle;
                        }
                        q++;
                    }
                }
            }
        }
        return "Erreur";
    }
}
void verifWord()
{
    init();
    system("setterm -bold on");
    printf("\n \n Tapez un mot : ");
    system("setterm -bold off");
    scanf("%s", &word);
    word[strlen(word)] = '$';
    system("setterm -bold on");
    printf("\033[1;34m");
    printf("---------------------------------------------------------------------\n");
    printf("|Pile                  |Entrée                |Action                |\n");
    printf("---------------------------------------------------------------------\n");
    printf("\033[0m");
    system("setterm -bold off");
    int ptrLectureWord = 0;
    int err = 0;
    while (!isempty() && word[ptrLectureWord] != '\0' && err == 0)
    {
        char pileContent[256] = "";
        printPile(pileContent);
        char action[256] = "";
        strcpy(action, findAction(pop(), word[ptrLectureWord]));
        printf("|%s", pileContent);
        for (int k = 0; k < (22 - strlen(pileContent)); k++)
        {
            printf(" ");
        }
        //Afficher l'entrée
        printf("|");
        for (int l = ptrLectureWord; l < strlen(word); l++)
        {
            printf("%c", word[l]);
        }
        for (int k = 0; k < (22 - strlen(word) + ptrLectureWord); k++)
        {
            printf(" ");
        }
        printf("|%s", action);
        for (int k = 0; k < (22 - strlen(action)); k++)
        {
            printf(" ");
        }
        printf("|\n");
        if (strcmp(action, "Erreur") == 0)
        {
            err = 1;
        }
        else
        {
            if (strcmp(action, "Supprimer") == 0)
            {
                ptrLectureWord++;
            }
            else
            {
                inverseWord(action);
                if (strcmp(inv, "#") != 0)
                {

                    for (int e = 0; e < strlen(inv); e++)
                    {
                        push(inv[e]);
                    }
                }
            }
        }
    }
    if (isempty() && word[ptrLectureWord] == '\0')
    {
        printf("|");
        for (int k = 0; k < 22; k++)
        {
            printf(" ");
        }
        printf("|");
        for (int k = 0; k < 22; k++)
        {
            printf(" ");
        }
        printf("|");
        system("setterm -bold on");
        printf("\033[1;35m");
        printf("Accepter");
        printf("\033[0m");
        system("setterm -bold off");
        for (int k = 0; k < 14; k++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    system("setterm -bold on");
    printf("\033[1;34m");
    printf("----------------------------------------------------------------------\n");
    printf("\033[0m");
    system("setterm -bold off");
}
