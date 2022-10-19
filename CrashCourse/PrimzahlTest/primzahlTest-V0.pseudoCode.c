/* Pruefe of Zahl n eine Primzahl ist */
{
    Zahl n einlesen;

    i = 2;
    teilerGefunden = falsch; /* Flag fuer Abbruch */

    while ( i < n && teilerGefunden == falsch ) {
        if ( i teilt n ) {
            teilerGefunden = wahr;
        } else {
            i = i + 1;
        }
    }

    if (teilerGefunden == falsch) {
        Ausgabe n ist eine Primzahl;
    } else {
        Ausgabe i teilt n, also n keine Primzahl;
    }
}
