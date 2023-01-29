#include "functions.c"

int main(){
    /*Lecture de la grammaires
    Soit grammaire donner par l'utilisateur 
    soit grammaire donner par défaut */
    readProduction();

    // Afficher la grammaire avant l'élimination de la recursivité
    PrintProductionWR();

    // elimination de la récursivité à gauche
    recursivite();
    // Sauvegarder les non terminaux
    save_NT_Terminal();
    // Afficher la grammaire aprés l'élimination de la recursivité
    PrintProduction();

    // calculer les premiers
    CalculFirst();
     // calculer les suivants
    CalculFollow();

    // Afficher les premiers de chaque non terminale
    printFirst();
    // Afficher les suivants de chaque non terminale
    printFollow();
    // Afficher les premiers de chaque regle
    regle_first();
    //Afficher la table LL1
    table_LL1();

    verifWord();
}
