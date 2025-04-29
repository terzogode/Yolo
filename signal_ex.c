#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// signal example: if push Ctrl+d on a.out, it prints gestore, use Ctrl+z to end

/* void	gestore(int segnale)
{
	printf("Ricevuto il segnale %d\n", segnale);
}

int	main(void)
{
	signal(SIGINT, gestore); // Associa SIGINT (Ctrl+C) al nostro gestore
	while (1) {
		printf("Sto lavorando...\n");
		sleep(1);
	}
	return 0;
} */

///////////////////////////////////////////////////////////////////////////////

//signal example: use kill to send a signal to another process or itself

/* void	gestore(int segnale)
{
	printf("Ricevuto segnale %d con kill()\n", segnale);
}

int	main(void)
{
	signal(SIGUSR1, gestore); // Imposta un gestore per SIGUSR1

	printf("Mio PID: %d\n", getpid());
	printf("Invio SIGUSR1 a me stesso...\n");

	kill(getpid(), SIGUSR1); // Invia SIGUSR1 a questo stesso processo

	return 0;
} */

///////////////////////////////////////////////////////////////////////////////

//signal example: use signal to igore something

/* int	main(void)
{
	signal(SIGINT, SIG_IGN); // Ignora SIGINT (Ctrl+C)

	while (1) {
		printf("Non mi fermerai con Ctrl+C!\n");
		sleep(1);
	}

	return 0;
} */


/* La funzione sigaction() ti permette di impostare un gestore di segnali in modo dettagliato, più robusto di signal().
Come funziona?

Hai una struttura chiamata struct sigaction, dove puoi specificare:

	- quale funzione chiamare quando arriva un segnale (sa_handler)

	- quali segnali bloccare temporaneamente mentre il gestore è in esecuzione (sa_mask)

	- altre opzioni (sa_flags)

Struttura:

struct sigaction 
{
	void (*sa_handler)(int);   // Puntatore alla funzione gestore
	sigset_t sa_mask;          // Altri segnali da bloccare temporaneamente
	int sa_flags;              // Opzioni extra (es. restart, ecc.)
};

SIGEMPTYSET
Questa funzione inizializza un insieme di segnali (tipo una lista vuota) in cui puoi poi aggiungere segnali.

sigset_t set;
sigemptyset(&set); // "set" ora è vuoto: non contiene nessun segnale

SIGADDSET
Serve per aggiungere un segnale a un set (insieme di segnali), come se stessi dicendo: "Blocca anche questo segnale mentre esegui il gestore". */

/* struct sigaction 
{
	void (*sa_handler)(int);   // Puntatore alla funzione gestore
	sigset_t sa_mask;          // Altri segnali da bloccare temporaneamente
	int sa_flags;              // Opzioni extra (es. restart, ecc.)
};

void gestore(int segnale) {
    printf("Ricevuto segnale %d\n", segnale);
}

int main() {
	struct sigaction azione;
	

	// Imposta il gestore
	azione.sa_handler = gestore;

	// Inizializza la maschera a vuoto
	sigemptyset(&azione.sa_mask);

	// Aggiunge SIGTERM alla maschera (bloccato durante esecuzione del gestore)
	sigaddset(&azione.sa_mask, SIGTERM);

	azione.sa_flags = 0; // Nessuna opzione extra

	// Collega il gestore al segnale SIGINT
	sigaction(SIGINT, &azione, NULL);

	while (1) {
		printf("In attesa di segnali...\n");
		sleep(2);
	}

	return 0;
} */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Removed incorrect redefinition of struct sigaction

void gestore(int segnale) {
	printf("🟡 Gestore per segnale %d iniziato\n", segnale);
	sleep(10); // Simula lavoro lungo nel gestore
	printf("🟢 Gestore per segnale %d terminato\n", segnale);
}

int main() {
	struct sigaction azione;

	azione.sa_handler = gestore;

	// Inizializza la maschera (nessun segnale bloccato all'inizio)
	sigemptyset(&azione.sa_mask);

	// Aggiungiamo SIGTERM alla maschera → sarà bloccato durante SIGINT
	sigaddset(&azione.sa_mask, SIGTERM);

	azione.sa_flags = 0;

	// Imposta gestore per SIGINT (Ctrl+C)
	sigaction(SIGINT, &azione, NULL);

	// Imposta gestore anche per SIGTERM (per vedere quando arriva)
	signal(SIGTERM, gestore);

	printf("🔵 PID del processo: %d\n", getpid());
	printf("Premi Ctrl+C per inviare SIGINT (entra nel gestore)\n");
	printf("Durante i 10 secondi, apri un altro terminale e digita:\n");
	printf("  kill -SIGTERM %d\n\n", getpid());

	while (1) {
		printf("⏳ In attesa di segnali...\n");
		sleep(2);
	}

	return 0;
}





