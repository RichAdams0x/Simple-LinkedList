#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//salut notre travail consistera a creer une liste chainée ou nous allons stocker des notes entières.
//definissons dabord notre structure de donnée
typedef struct block{
		int note;
		struct block* next_block;
	}block;
	
	//creons maintenant un nouveau type que l'on va assigner aux pointeurs chargés de pointer sur notre structure
	
	typedef block* block_pointer;
	//definissons les prototypes de toutes les procédures dont nous aurions besoin pour creer cette liste chainée

void ajouter_note(block_pointer* fpointer,int note);
void afficher_notes(block_pointer fpointer);
void delete_first(block_pointer* fpointer);
void delete_last(block_pointer* fpointer);
void add_first(block_pointer* fpointer,int note);
void add_middle(block_pointer* fpointer,int note2,int size);
void delete_middle(block_pointer* fpointer,int longueur);
void affiche_menu();
void affiche_menu_ajout();
void affiche_menu_supprime();
void add_by_orde(block_pointer* fpointer,int mark);
void delete_mark(block_pointer* fpointer,int notee);

int main(int argc, char *argv[]) {
	printf("bonjour et bienvenu dans notre structure de données ou vous pourrez stocker vos notes\n");
	printf("----------MENU----------\n");
	//definissons nos variables globales
	int note,choix,choix2,taille=-1;
	block_pointer pointer=NULL;
	//corps de notre programme. cest dans cette boucle while que nous allons ajencer nos procédures. rien de spécial ici
	while(1){
		affiche_menu();
		scanf("%d",&choix);
		while(choix==0||choix>4){
			printf("le numero choisi ne correspond a aucune commande!!\n");
			printf("veuillez Reessayer\n");
			affiche_menu();
			scanf("%d",&choix);
		}
		switch(choix){
			case 1:
				affiche_menu_ajout();
				scanf("%d",&choix2);
				while(choix2==0||choix2>4){
					printf("le numero choisi ne correspond a aucune commande!!\n");
					printf("veuillez Reessayer\n");
					affiche_menu_ajout();
					scanf("%d",&choix2);
				}
				switch(choix2){
					case 1:
						printf("enter la note:");
						scanf("%d",&note);
						add_first(&pointer,note);
						taille+=1;
						break;
					case 2:
						printf("enter la note:");
						scanf("%d",&note);
						if(taille>=0){
							add_middle(&pointer,note,taille);
							taille+=1;
						}
						else{
							printf("votre liste ne comporte pas assez de note pour pouvoir faire l'ajout au millieu");
						}
						break;
					case 3:
						printf("enter la note:");
						scanf("%d",&note);
						ajouter_note(&pointer,note);
						taille+=1;
						break;
					case 4:
						printf("enter la note:");
						scanf("%d",&note);
						add_by_orde(&pointer,note);
						break;
				}
				break;
			case 2:
				affiche_menu_supprime();
				scanf("%d",&choix2);
				while(choix2==0||choix2>4){
					printf("le numero choisi ne correspond a aucune commande!!\n");
					printf("veuillez Reessayer\n");
					affiche_menu_supprime();
					scanf("%d",&choix2);
				}
				switch(choix2){
					case 1:
						delete_first(&pointer);
						taille-=1;
						break;
					case 2:
						if(taille>1){
							delete_middle(&pointer,taille);
							taille-=1;
						}
						else{
							printf("votre liste ne comporte pas assez de note pour pouvoir faire la suppression du millieu");
						}
						break;
					case 3:
						delete_last(&pointer);
						taille-=1;
						break;
					case 4:
						printf("entrer la note:");
						scanf("%d",&note);
						delete_mark(&pointer,note);
						break;
				}
				break;
			case 3:
				afficher_notes(pointer);
				break;
		}
		if(choix==4){
			printf("MERCI D'AVOIR EXPERIMENTER NOTRE STRUCTURE DE DONNEES. A BIENTOT!!");
			break;
		}
			
	}
	return 0;
}

void ajouter_note(block_pointer* fpointer,int note){ 
	block_pointer pointer2;
	if((*fpointer)==NULL){
		(*fpointer)=malloc(sizeof(block));
		(*fpointer)->note=note;
		(*fpointer)->next_block=NULL;
	}
	else{
		pointer2=(*fpointer);
		while(pointer2->next_block!=NULL){
			pointer2=pointer2->next_block;
		}
		pointer2->next_block=malloc(sizeof(block));
		pointer2->next_block->note=note;
		pointer2->next_block->next_block=NULL;
	}
}
void afficher_notes(block_pointer fpointer){
	while(fpointer!=NULL){
		printf("%d-->",fpointer->note);
		fpointer=fpointer->next_block;
	}
	printf("NULL");
}
void delete_first(block_pointer* fpointer){
	block_pointer fpointerSup;
	fpointerSup=(*fpointer);
	fpointerSup=fpointerSup->next_block;
	*fpointer=free;
	*fpointer=fpointerSup;
}

void delete_last(block_pointer* fpointer){
	block_pointer fpointerSup;
	fpointerSup=(*fpointer);
	while(fpointerSup->next_block->next_block!=NULL){
		fpointerSup=fpointerSup->next_block;
	}
	fpointerSup->next_block->next_block=free;
	fpointerSup->next_block=NULL;
}

void add_first(block_pointer* fpointer,int note){
	block_pointer pointerAdd;
	pointerAdd=malloc(sizeof(block));
	pointerAdd->note=note;
	pointerAdd->next_block=(*fpointer);
	(*fpointer)=pointerAdd;
}

void add_middle(block_pointer* fpointer,int note2,int size){
	int index=size;
	block_pointer pointerMiddle,pointerMiddle2;
	pointerMiddle2=(*fpointer);
	while(index!=(size/2)+1){
		pointerMiddle2=pointerMiddle2->next_block;
		index-=1;
	}
	pointerMiddle=malloc(sizeof(block));
	pointerMiddle->note=note2;
	pointerMiddle->next_block=pointerMiddle2->next_block;
	pointerMiddle2->next_block=pointerMiddle;
}
void delete_middle(block_pointer* fpointer,int longueur){
	int index=longueur;
	block_pointer pointer_del=(*fpointer),pointer_del2;
	while(index!=(longueur/2)+1){
		pointer_del=pointer_del->next_block;
		index-=1;
	}
	pointer_del2=pointer_del->next_block;
	pointer_del->next_block=pointer_del->next_block->next_block;
	pointer_del2=free;
}

void affiche_menu(){
	printf("1-AJOUTER UNE NOTE\n");
	printf("2-SUPPRIMER UNE NOTE\n");
	printf("3-AFFICHER LA LISTE\n");
	printf("4-EXIT\n");
	printf("que voulez vous faire:\n");
}

void affiche_menu_ajout(){
	printf("1-Ajouter une note au debut de la liste\n");
	printf("2-Ajouter une note au milieu de la liste\n");
	printf("3-Ajouter une note a la fin de la liste\n");
	printf("4-Ajouter une note dans l'ordre\n");
	printf("que voulez vous faire:\n");
}
void affiche_menu_supprime(){
	printf("1-Supprimer la note au debut de la liste\n");
	printf("2-Supprimer la note au milieu de la liste\n");
	printf("3-Supprimer la note a la fin de la liste\n");
	printf("4-Supprimer une note define\n");
	printf("que voulez vous faire:\n");
}

void add_by_orde(block_pointer* fpointer,int mark){
	block_pointer pointerOrder,pointer_create;
	pointer_create=malloc(sizeof(block));
	pointer_create->note=mark;
	pointerOrder=(*fpointer);
	while(1){
		if(pointerOrder->next_block->note>mark){
			break;
		}
		pointerOrder=pointerOrder->next_block;
	}
	pointer_create->next_block=pointerOrder->next_block;
	pointerOrder->next_block=pointer_create;
}

void delete_mark(block_pointer* fpointer,int notee){
	block_pointer pointerDell;
	block_pointer pointerDell2;
	pointerDell=(*fpointer);
	while(notee!=pointerDell->next_block->note){
		pointerDell=pointerDell->next_block;
		if(pointerDell->next_block=NULL){
			printf("cette note n'est pas dans la liste");
			break;
		}
	}
	pointerDell2=pointerDell->next_block;
	pointerDell->next_block=pointerDell2->next_block;
	pointerDell2=free;
}
