/*
 * Autore: EnryBarto
 * Data: 10/10/2020
 * Versione: 1
 * Sorgente: gioco_undici.c 
 * 
 * Funzione:
 * Gioco degli 11 stecchini.
 * Si parte da 11 stecchini.
 * Ogni giocatore nel suo turno può togliere
 * da 1 a 3 stecchini.
 * Chi rimane con 1 stecchino perde.
 */

#include <stdio.h>

void main() {
	int stecchini = 11; /* Stecchini rimanenti */
	int giocatore = 0; /* Numero scelto dal giocatore */
	int counter = 0; /* Contatore dei giri */
	int pc = 2; /* Numero scelto dal pc */
	int i = 0; /* Contatore per la visualizzazione degli stecchini rimasti*/
	
	printf("\nGIOCO DEGLI 11 STECCHINI\n"); /* Messaggio di inizio */
	printf("||||||||||| - Rimasti: 11\n\n"); /* Mostra a schermo la situazione iniziale */
	
	do {
		counter++; /* Incrementa il contatore di 1 */

		stecchini = stecchini - pc; /* Calcola il numero di stecchini rimasti */
		
		/* TURNO DEL COMPUTER */  
		printf("Turno del computer: -%d\n", pc); /* Scrive gli stecchini che toglie il computer */	
		
		for(i = 0; i != stecchini; i++){ /* Mostra a schermo gli stecchini rimasti */
			printf("|"); 	
		}
		printf(" - Rimasti: %d\n\n", stecchini); /* Scrive il numero di stecchini rimasti */
		
		/* TURNO DEL GIOCATORE */	
		printf("Turno del giocatore, inserire il numero di stecchini da rimuovere (min 1, max 3): -"); /* Chiede al giocatore di inserire un numero */
		scanf("%d", &giocatore); 

		while(giocatore < 1 || giocatore > 3) {
			printf("Numero inserito non valido\nTurno del giocatore, inserire il numero di stecchini da rimuovere (min 1, max 3): -"); /* Chiede al giocatore di inserire un numero */
			scanf("%d", &giocatore); 
		}
		
		stecchini = stecchini - giocatore; /* Calcola il numero di stecchini rimasti */
		
		for(i = 0; i != stecchini; i++){ /* Mostra a schermo gli stecchini rimasti */
			printf("|"); 	
		}
		printf(" - Rimasti: %d\n\n", stecchini); /* Scrive il numero di stecchini rimasti */
		
		/* TURNO DEL COMPUTER */
		if (counter == 1){ /* Controlla se è il primo turno */
			pc = 4 - giocatore;
		} else {
			pc = stecchini - 1;
		}
	} while (counter == 1); /* Controlla se è il primo turno */
	
	stecchini = stecchini - pc; /* Calcola il numero di stecchini rimasti */
	
	/* TURNO DEL PC */
	printf("Turno del computer: -%d\n| - Rimasti: %d\n\n", pc, stecchini); /* Mostra a schermo e scrive il numero degli stecchiini rimasti */ 
	
	printf("Hai perso\n\n"); /* Informa il giocatore della sua sconfitta */
}
