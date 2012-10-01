    while(continuer) /* le joueur veut faire un nouvel essai */
    {
	essais = essais + 1;
	/* tirage de x */
	x = rand() % NBMAX + 1; /* entre 1 et NBMAX inclus */
	/* tirage de y */
	y = rand() % NBMAX + 1; /* entre 1 et NBMAX inclus */

	/* question */
	printf("%d + %d = ", x, y);
        scanf("%d",&choix);

        if(x + y == choix) /* trouvé */
        {
	    printf("Bravo c'est bien %d\n", choix);
	    succes = succes + 1;
        }
        else /* pas trouvé */
        {
	    printf("Faux, %d + %d = %d (pas %d)\n", x, y, x + y, choix);        
	}
	printf("Continuer (1) ou arreter (0) ?\n");
	scanf("%d", &choix);
	if (choix == 0)
	{
	    continuer = FALSE;
	}
    }
