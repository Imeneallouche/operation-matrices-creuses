#include <stdio.h>
#include <stdlib.h>
#include <string.h>






//la structure du maillon de la 1ère représentation
typedef struct maillon
{
    int value;
    int line;
    int column;
    struct maillon *next;
}
maillon;





//déclaration du pointeur vers le maillon de la 1ère représentation
typedef struct maillon *pointer;







//la machine abstraite
void alocate(pointer *p);                   //alloueur un maillon
void free_it(pointer p);                    //liberer un maillon

pointer to_next(pointer p);                 //suivant du maillon
int value(pointer p);                       //valeur du maillon
int column_number(pointer p);               //numero de colone du maillon
int line_number(pointer p);                 //numero de ligne du maillon

void aff_adr(pointer *p,pointer q);         //aff_adr() editer le champ next
void aff_value(pointer *p,int value);       //aff_val() editer le champ value
void aff_line(pointer *p , int line);       //aff_ligne() editer le champ ligne
void aff_column(pointer *p , int column);   //aff_colone() editer le champ colone












//les fonctiosn de la 1ere representation





//
void ask_for_matrix(pointer *start, int lines, int columns);





//creer un nouveau maillon et inserer à la fin de la liste en précisant tous les champs
void create_new_node(pointer *start ,int row,int column,int non_zero_element);




//affiche le vrai contenu de la matrice crée sans les valeurs nulles comme suit:
/*
    line    column  value
     .        .       .
     .        .       .
     .        .       .
     .        .       .
*/
void display(pointer *start);







//afficher le contenu de la liste sous forme d'une matrice
//en completant l'affichage des valeurs nulles dans les espaces manquants comme suit:
/*
    .   .   .   .
    .   .   .   .
    .   .   .   .
    .   .   .   .
    .   .   .   .
*/
void PrintList(pointer *start, int lines_number, int columns_number);








//cree la transposee d'une matrice et retourne sa tete dans la variable pointer *new_head
void matrix_transposee(pointer *new_head, pointer *start);




//inserer un maillon mais en ordre selon la 1ere representation
//la position de l'insertion du maillon est déduite du nombre de ligne et colone du maillon
//ce module sera utilisée dans la creation de la transposée pour un coup de temps meilleur
void insert_node_order(pointer *new_head , int line, int column, int value);





//exige des conditions sur le numéro de ligne et de colone de départ et d'arrivée
//selon la matrice de départ
//pour eviter toute faute de segmentation ou d'incohérence
void submatrix_conditions(int* dl,int*dc,int*al,int*ac,int lines , int columns);



//extraire une sous matrice à partir de la matrice principal et retourner sa tete
//dans la variable *new_head
void extraction_submatrix(pointer *new_head, pointer *start , int lines, int columns);



//exige des conditions sur le nombre de ligne et de colone des sous blocs
//selon la matrice de départ
//pour eviter toute faute de segmentation ou d'incohérence
void division_sous_bloc_conditions(int lines, int columns, int *line_number, int *column_number);




void division_sous_bloc(pointer *start, int lines, int columns);



//libère l'espace mememoire alloué pour une liste de la 1ère representation à partir de la tete de la liste
void freeList(pointer *start);


//additioner deux matrices de la meme dimension et retourner la tete de la matrice résultat
//dans la variable pointer *result
void add_matrixes(pointer *first_matrix , pointer *seocnd_matrix , pointer *result);


//multiplier deux matrices et retourner la tete de la nouvelle matrice
//dans la variable result
void multiply_matrixes(pointer *first_matrix, pointer* second_matrix , pointer* result);







//fait le ou logique entre deux matrices de meme dimension et retourne la tete de la nouvelle matrice
//dans la variable pointer* result
void operation_or(pointer *first_matrix ,pointer* second_matrix , pointer *result);


//fait le ou exclusif logique entre deux matrices de meme dimension et retourne la tete de la nouvelle matrice
//dans la variable pointer* result
void operation_oux(pointer *first_matrix ,pointer* second_matrix , pointer *result);


//fait le et logique entre deux matrices de meme dimension et retourne la tete de la nouvelle matrice
//dans la variable pointer* result
void operation_et(pointer *first_matrix ,pointer* second_matrix , pointer *result);


//fait le non logique sur une matrice et retourne la tete de la nouvelle matrice
//dans la variable pointer* result
void operation_non(pointer *start, pointer *result, int lines, int columns);






























int main(void)
{

    //le menu et les options
    printf("    *************************************************\n");
    printf("    *                                               *\n");
    printf("    *   Bienvenu sur notre programme fascinant!     *\n");
    printf("    *                                               *\n");
    printf("    *************************************************\n\n\n");

    printf("veuillez consulter nos diverses fonctions et en choisir une:\n");
    printf("    1-  Lecture d'une matrice creuse entière\n");
    printf("    2-  Affichage d'une matrice creuse entière\n");
    printf("    3-  Extraction d'une sous matrice\n");
    printf("    4-  Division d'une matrice en sous-blocs de taille égale\n");
    printf("    5-  Transposée d'une matrice\n");
    printf("    6-  Addition de deux matrices\n");
    printf("    7-  Multiplication de deux matrices\n");
    printf("    8-  Opérations logiques : NON\n");
    printf("    9-  Opérations logiques : ET\n");
    printf("    10-  Opérations logiques : OU\n");
    printf("    11-  Opérations logiques : OUX\n");




    //le choix des options
    printf("\n\nsaisissez le numéro de votre option: ");
    int option;
    scanf(" %i",&option);
    while (option<1 || option>11)
    {
        printf("pas d'option correspondante à un tel numéro saisissez un autre: ");
        scanf(" %i",&option);
    }

    printf("***************************************     \n");





            printf("\nsuper! maintenant pour créer la matrice on aura besoin de plus d'info sur celle ci: \n\n");
            printf("nombre de lignes : ");
            int lines;
            scanf("%i",&lines);

            printf("nombre de colones ");
            int columns;
            scanf("%i",&columns);

            pointer start=NULL;
            ask_for_matrix(&start,lines,columns);



                switch(option)
                {
                        case 1:



                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *   Lecture et creation de la matrice creuse:   *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        printf("\nla matrice a été crée dynamiquement avec succés etes vous sur de vous contenter de ça sans l'afficher? \n");
                                        printf("si vous voulez l'afficher pour vérifier sa création tapez y sinon n : ");
                                        char answer;
                                        scanf(" %c",&answer);
                                        if (answer =='y')
                                        {
                                            printf("\n");
                                            PrintList(&start,lines, columns);
                                            printf("\n");
                                            display(&start);
                                        }
                                        freeList(&start);
                                        break;



                        case 2:

                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *      affichage entier de la matrice creuse:   *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        PrintList(&start,lines, columns);
                                        freeList(&start);
                                        break;



                        case 3:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *      soustraction d'une sous matrice:         *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        pointer submatrix_head= NULL;
                                        extraction_submatrix(&submatrix_head, &start ,lines, columns);


                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&submatrix_head);

                                        freeList(&start);
                                        freeList(&submatrix_head);
                                        break;



                        case 4:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *      division de la matrice en sous blocs:    *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        division_sous_bloc(&start,lines,columns);
                                        freeList(&start);
                                        break;




                        case 5:

                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *    creation de la transposée de la matrice:   *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        pointer new_head = NULL;
                                        matrix_transposee(&new_head,&start);

                                        printf("\n\n l'affichage entier de la transposée: \n");
                                        PrintList(&new_head , columns, lines);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&new_head);

                                        freeList(&start);
                                        freeList(&new_head);
                                        break;



                        case 6:

                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *          l'addition de deux matrices:         *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        printf("une deuxième matrice de meme taille est indisponsable inserez ses valeurs:\n");
                                        pointer second_matrix=NULL;
                                        pointer result=NULL;
                                        ask_for_matrix(&second_matrix,lines,columns);
                                        printf("\n      ***************************************     \n\n");
                                        add_matrixes(&start,&second_matrix,&result);

                                        printf("\n\n l'affichage entier du résultat de l'addition des deux matrices: \n");
                                        PrintList(&result,lines, columns);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&result);

                                        freeList(&start);
                                        freeList(&second_matrix);
                                        freeList(&result);
                                        break;




                        case 7:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *      la multiplication de deux matrices:      *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        //not finished yet
                                        break;


                        case 8:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *           l'operation logique NON:            *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        result=NULL;
                                        operation_non(&start,&result,lines,columns);

                                        printf("\n\n l'affichage entier du résultat du NON logique de la matrice: \n");
                                        PrintList(&result,lines, columns);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&result);

                                        freeList(&start);
                                        freeList(&result);
                                        break;




                        case 9:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *           l'operation logique ET:             *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        printf("une deuxième matrice de meme taille est indisponsable inserez ses valeurs:\n");
                                        second_matrix=NULL;
                                        result=NULL;
                                        ask_for_matrix(&second_matrix,lines,columns);
                                        printf("\n      ***************************************     \n\n");
                                        operation_et(&start,&second_matrix,&result);

                                        printf("\n\n l'affichage entier du résultat du ET logique des deuxs matrices: \n");
                                        PrintList(&result,lines, columns);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&result);

                                        freeList(&start);
                                        freeList(&second_matrix);
                                        freeList(&result);
                                        break;




                        case 10:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *            l'operation logique OU:            *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        printf("une deuxième matrice de meme taille est indisponsable inserez ces ses valeurs:\n");
                                        second_matrix=NULL;
                                        result=NULL;
                                        ask_for_matrix(&second_matrix,lines,columns);
                                        printf("\n      ***************************************     \n\n");
                                        operation_or(&start,&second_matrix,&result);

                                        printf("\n\n l'affichage entier du résultat du OU logique des deuxs matrices: \n");
                                        PrintList(&result,lines, columns);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&result);

                                        freeList(&start);
                                        freeList(&second_matrix);
                                        freeList(&result);
                                        break;




                        case 11:


                                        printf("    *************************************************\n");
                                        printf("    *                                               *\n");
                                        printf("    *      l'operation logique OU Exclusif:         *\n");
                                        printf("    *                                               *\n");
                                        printf("    *************************************************\n\n\n");
                                        printf("une deuxième matrice de meme taille est indisponsable inserez ces ses valeurs:\n");
                                        second_matrix=NULL;
                                        result=NULL;
                                        ask_for_matrix(&second_matrix,lines,columns);
                                        printf("\n      ***************************************     \n\n");
                                        operation_oux(&start,&second_matrix,&result);

                                        printf("\n\n l'affichage entier du résultat du OU exclusif logique des deuxs matrices: \n");
                                        PrintList(&result,lines, columns);
                                        printf("\n\n le contenu de la liste crée: \n");
                                        display(&result);

                                        freeList(&start);
                                        freeList(&second_matrix);
                                        freeList(&result);
                                        break;
                }

    return 0;
}

























void alocate(pointer *p)
{
     *p = (maillon*)malloc(sizeof(maillon));
     (*p)->next = NULL;

}
void free_it(pointer p)
{
    free(p);
}


pointer to_next(pointer p)
{
     return(p->next);
}
int value(pointer p)
{
    return((p)->value);
}
int column_number(pointer p)
{
    return ((p)->column);
}
int line_number(pointer p)
{
    return ((p)->line);
}


void aff_adr(pointer *p,pointer q)
{
    (*p)->next = q;
}
void aff_value(pointer *p,int value)
{
    (*p)->value = value;
}
void aff_line(pointer *p , int line)
{
    (*p)->line = line;
}
void aff_column(pointer *p , int column)
{
    (*p)->column = column;
}






















//demande des valeurs de la matrice
void ask_for_matrix(pointer *start ,int lines, int columns)
{
    // i <==> nombre de ligne de la matrice
    // j <==> nombre de colones de la matrice
    // number <==> la valeur du maillon à créer
    int i,j,number;

    for (i=0  ;i<lines ;i++)
    {
        for (j=0  ;j<columns ; j++)
        {
            printf("matrix[%i][%i] = ",i,j);
            scanf("%i",&number);

            //si la valeur n'est pas nulle on crée un maillon
            if (number!=0)
            {
                create_new_node(start,i,j,number);
            }

        }
        printf("\n");
    }
}








//créer un maillon pour les valeurs non nulles
void create_new_node(pointer *start, int row,int column,int non_zero_element)
{
    pointer ptr, temp;

    //allouer l'espace pour le maillon à chainer
    alocate(&temp);
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }



    //remplir les champs du maillon par les données
    aff_adr(&temp,NULL);
    aff_value(&temp,non_zero_element);
    aff_line(&temp,row);
    aff_column(&temp, column);


      //si la liste est vide alors le maillon est la tete de la liste
      if(*start==NULL)
        {
            *start=temp;
        }

      //sinon on parcours la liste jusqu'à la fin
      else
        {
                ptr=*start;
                while(to_next(ptr)!=NULL)
                {
                        ptr=to_next(ptr);
                }

                //on insère le maillon à la fin
                aff_adr(&ptr,temp);
        }
}











//afficher la liste sous forme de matrice en affichant les valeurs nulles manquantes
void PrintList(pointer *start,int lines_number, int columns_number)
{
        // i <==> nombre de ligne de la matrice
        // j <==> nombre de colones de la matrice
        int i,j;


        //si la liste est vide on affiche directement que des zéros
        if(*start==NULL)
        {
            for (i=0  ;  i<lines_number ; i++)
            {
                for (j=0  ;j<columns_number ;j++)
                {
                    printf("\t %i",0);
                }
            }
            printf("\n");
        }


        //sinon
        else
        {
                pointer ptr;
                ptr =*start;
                for (i=0  ;  i<lines_number ; i++)
                {
                    for (j=0  ;j<columns_number ;j++)
                    {
                        //si matrix[i][j] existe dans la liste donc on affiche sa valeur
                        if (ptr!=NULL && line_number(ptr)== i && column_number(ptr)==j)
                        {
                            printf("%d\t",value(ptr));
                            ptr=to_next(ptr);
                        }

                        //sinon alors sa valeur est nulle donc on affiche 0
                        else
                        {
                            printf("%d\t",0);
                        }
                    }
                    printf("\n");
                }
        }
}








//creation de la sous matrice
void matrix_transposee(pointer *new_head, pointer *start)
{
    //si la liste est vide alors on retourne directement la variable pointer *new_head comme étant un pointer NIL
    if(*start==NULL)
    {
        exit(0);
    }


    //sinon
    else
    {
        pointer here;
        here =*start;
        // on parcours la liste et on inverse le numéro de ligne et de colone à chaque reprise
        //on les insère dans la place convenable grace à la foncion insert_node_order
        while(here!=NULL)
        {
            insert_node_order(new_head ,line_number(here),column_number(here),value(here));
            here=to_next(here);
        }
    }
}







//inserer le maillon par ordre de ligne et de colone (son emplacement dans la matrice)
void insert_node_order(pointer *new_head , int line, int column, int value)
{
    pointer temp,ptr;

    //alloueur le maillon à inserer
    alocate(&temp);
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }

    //remplir les champ du maillon par les données
    aff_adr(&temp,NULL);
    aff_value(&temp,value);
    aff_line(&temp,column);
    aff_column(&temp,line);


    //si la liste est vide alors le maillon sera dans la tete
    if(*new_head==NULL)
    {
        *new_head=temp;
    }


    //sinon
    else
    {
        ptr=*new_head;
        //insertion au début si l'emplacement du maillon deverait etre avant l'emplacement du maillon qui se retrouve dans la tete
        if ((line_number(ptr)>column) || (line_number(ptr)==column && column_number(ptr)>line))
        {
            aff_adr(&temp,*new_head);
            //le maillon devient la tete
            *new_head=temp;
        }


        //insertion au milieu/fin par rapport à la valeur de ligne et colone du maillon (emplacement dans la liste)
        else
        {
            //on parcours jusq'à y arriver au bon emplacement
            while(to_next(ptr)!=NULL && ((line_number(ptr)<column) || (line_number(ptr)==column && column_number(ptr)<line-1)))
            {
                ptr=to_next(ptr);
            }

            //on insère le maillon dans l'emplacement convenable
            aff_adr(&temp,to_next(ptr));
            aff_adr(&ptr, temp);
        }
    }
}









void extraction_submatrix(pointer *new_head, pointer *start ,int lines , int columns)
{
    //dl <==> la ligne de départ
    //dc <==> la colone de départ
    //al <==> la ligne d'arrivée
    //ac <==> la colone d'arrivée
    int dl,dc,al,ac;

    //éditer les valeurs des lignes et colones de départ et d'arrivée
    submatrix_conditions(&dl,&dc,&al,&ac,lines,columns);

    pointer ptr;
    ptr=*start;

    //parcourir la matrice de départ
    while(ptr!=NULL && (line_number(ptr)<al || (line_number(ptr)== al && column_number(ptr)<=ac)))
    {
        //on extrait que les maillons qui sont entre [dl,al] et [dc,ac]
        if (line_number(ptr)>=dl && column_number(ptr)>=dc && column_number(ptr)<=ac)
            //creer le maillon en mettant à jour les nouvelles valeur des numéros de lignes et colones
            create_new_node(new_head,line_number(ptr)-dl, column_number(ptr)-dc,value(ptr));

        ptr=to_next(ptr);
    }


    printf("la sous-matrice a été crée dynamiquement avec succés etes vous sur de vous contenter de ça sans l'afficher? \n");
    printf("si vous voulez l'afficher pour vérifier sa création tapez y sinon n : ");
    char answer;
    scanf(" %c",&answer);
    if (answer =='y')
    {
        printf("\n");
        PrintList(new_head, al-dl+1, ac-dc+1);
        printf("\n");
    }
}







//éles conditions sur la lignes et colone de départ et d'arrivée
void submatrix_conditions(int* dl,int*dc,int*al,int*ac,int lines , int columns)
{

    //dl <==> la ligne de départ
    //dc <==> la colone de départ
    //al <==> la ligne d'arrivée
    //ac <==> la colone d'arrivée

     printf("extraction d'une sous matrice aura besoin d'un point de départ et d'arrivé...\n");

     printf("ligne de départ: ");
     scanf("%i",dl);
     while(*dl>lines-1)
     {
         printf("dépassement de nombre de lignes de matrice saisie, saisissez une ligne de départ plus petite:");
         scanf("%i",dl);
     }



     printf("colone de départ: ");
     scanf("%i",dc);
     while(*dc>columns-1)
     {
         printf("dépassement de nombre de colones de matrice saisie, saisissez une colone de départ plus petite:");
         scanf("%i",dc);
     }


     printf("ligne d'arrivée: ");
     scanf("%i",al);
     while(*al>lines-1 || *al<*dl)
     {
         if(*al>lines-1)
         {
                printf("dépassement de nombre de lignes de matrice saisie, saisissez une ligne d'arrivée plus petite:");
                scanf("%i",al);
         }
         else
         {
                printf("la ligne de d'arrivée doit etre supérieure ou égale à la ligne de départ try another: ");
                scanf("%i",al);
         }
     }


     printf("colone d'arrivée: ");
     scanf("%i",ac);
     while(*ac>columns-1 || (*ac<*dc))
     {
         if (*ac>columns-1)
         {
            printf("dépassement de nombre de colones de matrice saisie, saisissez une colone d'arrivée plus petite:");
            scanf("%i",ac);
         }
         else
         {
            printf("la colone d'arrivé doit etre supérieure ou égale à la colone de départ, try another: ");
            scanf("%i",ac);
         }
     }
}







//additionner deux matrices de tetes : pointer* first_matrix et pointer* second_matrix
void add_matrixes(pointer *first_matrix , pointer *second_matrix , pointer *result)
{

    pointer ptr1,ptr2;
    ptr1 = *first_matrix;
    ptr2 = *second_matrix;


    //parcourir les deux matrices au meme temps pour un meilleur coup de temps
    while (ptr1 !=NULL && ptr2 !=NULL)
    {
        //si le nombre de ligne et colones des deux maillons sont identiques
        if(line_number(ptr1)==line_number(ptr2) && column_number(ptr1)==column_number(ptr2))
        {
            //on crée le maillon et la valeur de son champ est égale à la somme des valeurs du champ value des deux matrices
           create_new_node(result,line_number(ptr1),column_number(ptr1),value(ptr1)+value(ptr2));

           //on avance dans les deux listes avec un pas (maillon)
           ptr1=to_next(ptr1);
           ptr2=to_next(ptr2);
        }


        //sinon
        else
        {
            //si le maillon de 1ère liste a un emplacement inférieur à celui de la 2ème liste
            if (line_number(ptr1)<line_number(ptr2) || (line_number(ptr1)==line_number(ptr2) && column_number(ptr1)<column_number(ptr2)))
            {
                //on crée le maillon correspendannt au maillon de la 1ème liste
                //la valeur du champs value == valeur du champs value du maillon de la 1ere liste
                create_new_node(result,line_number(ptr1),column_number(ptr1),value(ptr1));
                //on avance que dans la 1ere liste
                ptr1=to_next(ptr1);
            }


            //sinon si le maillon de 2ème liste a un emplacement inférieur à celui de la 1ème liste
            else
            {
                //on crée le maillon correspendannt au maillon de la 2ème liste
                //la valeur du champs value == valeur du champs value du maillon de la 2eme liste
                create_new_node(result,line_number(ptr2),column_number(ptr2),value(ptr2));
                //on avance que dans la 2eme liste
                ptr2=to_next(ptr2);
            }
        }
    }


    //tant qu'on est pas arrivé à la fin de la 1ère liste
    while (ptr1 !=NULL)
    {
            //on crée les maillons correspendants aux maillons restants de la la 1ère liste
            create_new_node(result,line_number(ptr1),column_number(ptr1),value(ptr1));
            ptr1=to_next(ptr1);
    }

    //tant qu'on est pas arrivé à la fin de la 2ème liste
    while (ptr2 !=NULL)
    {
          //on crée les maillons correspendants aux maillons restants de la la 2ème liste
          create_new_node(result,line_number(ptr2),column_number(ptr2),value(ptr2));
          ptr2=to_next(ptr2);
    }
}

















void operation_or(pointer *first_matrix ,pointer* second_matrix , pointer *result)
{
    pointer ptr1, ptr2;
    ptr1 = *first_matrix;
    ptr2 = *second_matrix;


    //on parcours les deux listes au meme temps pour un meilleur coup de temps
    while (ptr1 !=NULL && ptr2 !=NULL)
    {
        //si le nombre de ligne et colones des deux maillons sont identiques
        if(line_number(ptr1)==line_number(ptr2) && column_number(ptr1)==column_number(ptr2))
        {
           //on crée le maillon et la valeur de son champ est égale à 1
           create_new_node(result,line_number(ptr1),column_number(ptr1),1);
           //on avance dans les deux listes avec un pas (maillon)
           ptr1=to_next(ptr1);
           ptr2=to_next(ptr2);
        }


        else
        {
            //sinon si le maillon de 1ère liste a un emplacement inférieur à celui de la 2ème liste
            if (line_number(ptr1)<line_number(ptr2) || (line_number(ptr1)==line_number(ptr2) && column_number(ptr1)<column_number(ptr2)))
            {
                //on crée le maillon correspendannt au maillon de la 1ème liste
                //la valeur du champs value  est égale à 1
                create_new_node(result,line_number(ptr1),column_number(ptr1),1);
                //on avance que dans la 1ere liste
                ptr1=to_next(ptr1);
            }

            //sinon si le maillon de 2ème liste a un emplacement inférieur à celui de la 1ème liste
            else
            {
                //on crée le maillon correspendannt au maillon de la 2ème liste
                //la valeur du champs value est égale à 1
                create_new_node(result,line_number(ptr2),column_number(ptr2),1);
                //on avance que dans la 2eme liste
                ptr2=to_next(ptr2);
            }
        }
    }

    //tant qu'on est pas arrivé à la fin de la 1ère liste
    while (ptr1 !=NULL)
    {
            //on crée les maillons correspendants aux maillons restants de la la 1ère liste
            create_new_node(result,line_number(ptr1),column_number(ptr1),1);
            ptr1=to_next(ptr1);
    }

    //tant qu'on est pas arrivé à la fin de la 2ème liste
    while (ptr2 !=NULL)
    {
        //on crée les maillons correspendants aux maillons restants de la la 2ème liste
        create_new_node(result,line_number(ptr2),column_number(ptr2),1);
        ptr2=to_next(ptr2);
    }
}








void operation_oux(pointer *first_matrix ,pointer* second_matrix , pointer *result)
{
    pointer ptr1 , ptr2;
    ptr1 = *first_matrix;
    ptr2 = *second_matrix;


    //parcourir les deux matrices au meme temps pour un meilleur coup de temps
    while (ptr1 !=NULL && ptr2 !=NULL)
    {
        //si le nombre de ligne et colones des deux maillons sont identiques
        if(line_number(ptr1)==line_number(ptr2) && column_number(ptr1)==column_number(ptr2))
        {
            //on avance dans les deux listes avec un pas (maillon) sans créer le maillon
            ptr1=to_next(ptr1);
            ptr2=to_next(ptr2);
        }

        //sinon
        else
        {
            //si le maillon de 1ère liste a un emplacement inférieur à celui de la 2ème liste
            if (line_number(ptr1)<line_number(ptr2) || (line_number(ptr1)==line_number(ptr2) && column_number(ptr1)<column_number(ptr2)))
            {
                //on crée le maillon correspendannt au maillon de la 1ème liste avec une valeur de 1
                create_new_node(result,line_number(ptr1),column_number(ptr1),1);
                //on avance que dans la 1ere liste
                ptr1=to_next(ptr1);
            }

            //sinon si le maillon de 2ème liste a un emplacement inférieur à celui de la 1ème liste
            else
            {
                //on crée le maillon correspendannt au maillon de la 2ème liste avec une valeur de 1
                create_new_node(result,line_number(ptr2),column_number(ptr2),1);
                //on avance que dans la 2eme liste
                ptr2=to_next(ptr2);
            }
        }
    }



    //tant qu'on est pas arrivé à la fin de la 1ère liste
    while (ptr1 !=NULL)
    {
            //on crée les maillons correspendants aux maillons restants de la la 1ère liste
            create_new_node(result,line_number(ptr1),column_number(ptr1),1);
            ptr1=to_next(ptr1);
    }

    //tant qu'on est pas arrivé à la fin de la 2ème liste
    while (ptr2 !=NULL)
    {
        //on crée les maillons correspendants aux maillons restants de la la 2ème liste
        create_new_node(result,line_number(ptr2),column_number(ptr2),1);
        ptr2=to_next(ptr2);
    }
}







void operation_et(pointer *first_matrix ,pointer* second_matrix , pointer *result)
{
    pointer ptr1 ,ptr2;
    ptr1 = *first_matrix;
    ptr2 = *second_matrix;

    //parcourir les deux matrices au meme temps pour un meilleur coup de temps
    while (ptr1 !=NULL && ptr2 !=NULL)
    {
        //si le nombre de ligne et colones des deux maillons sont identiques
        if(line_number(ptr1)==line_number(ptr2) && column_number(ptr1)==column_number(ptr2))
        {
            //on crée le maillon correspendannt au maillon des deux listes
            create_new_node(result,line_number(ptr1),column_number(ptr1),1);
            //on avance dans les deux listes avec un pas (maillon)
            ptr1=to_next(ptr1);
            ptr2=to_next(ptr2);
        }

        else
        {
            //si le maillon de 1ère liste a un emplacement inférieur à celui de la 2ème liste
            if (line_number(ptr1)<line_number(ptr2) || (line_number(ptr1)==line_number(ptr2) && column_number(ptr1)<column_number(ptr2)))
                //on avance que dans la 1ere liste
                ptr1=to_next(ptr1);

            //sinon si le maillon de 2ème liste a un emplacement inférieur à celui de la 1ème liste
            else
                //on avance que dans la 2eme liste
                ptr2=to_next(ptr2);
        }
    }
}








void operation_non(pointer *start, pointer *result, int lines, int columns)
{
    pointer ptr;
    ptr = *start;
    //i <==> le nombre de lignes de la matrice
    //j <==> le nombre de colones d ela matrice
    int i,j;

    for (i=0  ;i<lines; i++)
    {
        for (j=0  ;j<columns ;j++)
        {
            if (ptr==NULL || line_number(ptr)>i || (line_number(ptr)==i && column_number(ptr)>j))
                create_new_node(result,i,j,1);
            else
                ptr=to_next(ptr);
        }
    }
}









void division_sous_bloc_conditions(int lines, int columns, int *line_size, int *column_size)
{

    //line_size <==> le nombre de ligne demandé dans les sous-blocs
    //column_size <==> le nombre de colones demandé dans les sous-blocs

    printf("combien de lignes vous voulez avoir dans vos sous-blocs: ");
    scanf("%i",line_size);
    while(lines % (*line_size) !=0)
    {
        printf("ça devait etre un multiple de nombre de ligne de la matrice mère try again: ");
        scanf("%i",line_size);
    }


    printf("combien de colones vous voulez avoir dans vos sous-blocs: ");
    scanf("%i",column_size);

    while(columns % (*column_size) !=0)
    {
        printf("ça devait etre un multiple de nombre de colone de la matrice mère try again: ");
        scanf("%i",line_size);
    }
}








void division_sous_bloc(pointer *start, int lines, int columns)
{
    //line_size <==> le nombre de ligne demandé dans les sous-blocs
    //column_size <==> le nombre de colones demandé dans les sous-blocs
    int line_size, column_size;

    //récupérer les valeurs de line_size et column_size
    division_sous_bloc_conditions(lines,columns,&line_size,&column_size);


    //le nombre de sous blocs est égale à:
    int blocs =(lines / line_size) * (columns / column_size);

    //stocker les tete des sous blocs crées dans un tableau
    pointer headers_list[blocs];


    //initialiser les listes des sous blocs à des listes vide NIL
    int i;
    for (i=0  ;i<blocs  ;i++)
    {
        headers_list[i] = NULL;
    }

    pointer ptr;
    ptr = *start;
    //parcourir la liste
    while (ptr!=NULL)
    {
        //i est l'index ou stocker le maillon dans l'index spécifié dans le tableau
        //i est donné par l'equation:
        i=(columns/column_size)*(line_number(ptr)/line_size)+(column_number(ptr)/column_size);
        //creer le maillon avec mise à jour du numérode ligne et colone de chaque maillon
        create_new_node(&headers_list[i] ,(line_number(ptr)%line_size),(column_number(ptr)%column_size),value(ptr));
        ptr = to_next(ptr);
    }





    //afficher les sous blocs crées
    printf("\n\nles sous-blocs ont été crées dynamiquement avec succés etes vous sur de vous contenter de ça sans les afficher? \n");
    printf("si vous voulez les afficher pour vérifier leurs création tapez y sinon n : ");
    char answer;
    scanf(" %c",&answer);
    if (answer =='y')
    {
        for (i=0  ;i<blocs  ;i++)
        {
            printf("\n\n le sous blocs numéro %i: \n",i);
            PrintList(&headers_list[i],line_size,column_size);
        }
    }

}









void multiply_matrixes(pointer* first_matrix, pointer* second_matrix, pointer *result)
{

}








//libérer une liste
void freeList(pointer *start)
{
   pointer tmp;
   //parcourir la liste
   while (*start != NULL)
    {
       //liberer maillon par maillon
       tmp = *start;
       *start = to_next(*start);
       free_it(tmp);
    }
}










//afficher les maillons crées de la liste
void display(pointer *start)
{
        pointer ptr;
        //si la liste est vide on l'indique
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }

        //sinon on parcourt la liste et à chaque fois on indique les champs ligne, colone et valeur crées
        else
        {
                ptr=*start;
                printf("\nLine\tColumn\tValue\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",line_number(ptr));
                        printf("%d\t",column_number(ptr));
                        printf("%d\t",value(ptr) );
                        ptr=to_next(ptr);
                        printf("\n");
                }
        }
}