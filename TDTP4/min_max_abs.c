int main()
{
    int x = -3;
    int y = 5;
    int z;

    /* Un calcul sans signification particulière */
    x = valeur_absolue(x); /* valeur absolue de x */
    z = minimum(x, y);     /* minimum entre x et y */
    z = factorielle(z);    /* z! */
    z = minimum(2, z);     /* minimum entre 2 et z */

    /* Valeur fonction */
    return EXIT_SUCCESS;
}
