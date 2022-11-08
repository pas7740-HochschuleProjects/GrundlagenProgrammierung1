// Read level decription from file
// We allow for level descriptions of dimensions
//    (aboard->last_row + 1) x (last_col + 1)
enum ResCodes initializeLevelFromFile(struct board* aboard, const char* filename) {
    int y,x;
    int rownr;
    char buf[100];  // for messages
    FILE* in;       // FILE pointer for reading from file

    // Fill board with empty cells.
    for (y = 0; y <= aboard->last_row; y++) {
        for (x = 0; x <= aboard->last_col; x++) {
            placeItem( @001);
        } 
    }

    // Initialize food_items
    aboard->food_items = 0;

    // Read at most aboard->last_row+1 lines from file
    // Read at most aboard->last_col+1 characters per line from file
    // --> We need a buffer of size (aboard->last_col+1 + 2 )
    // The additional 2 elements are for '\n' and '\0'
    int bufsize = aboard->last_col + 3;
    char* buffer;
    if ((buffer = malloc(sizeof(char) * bufsize)) == NULL) {
        sprintf(buf,"Kein Speicher mehr in initializeLevelFromFile\n");
        showDialog(buf,"Bitte eine Taste druecken");
        return RES_FAILED;
    }

    // Open the file
    if ( (in = fopen(filename,"r")) == NULL) {
        sprintf(buf,"Kann Datei %s nicht oeffnen",filename);
        showDialog(buf,"Bitte eine Taste druecken");
        return RES_FAILED;
    }

    rownr = 0;
    // Read all lines from the text file describing the level
    while (rownr < aboard->last_row+1 && ! feof(in)) {
        int len;
        // Read one line from file
        if (fgets(buffer,bufsize,in) != NULL) {
            // The specifiction of fgets guarantees that there are
            // at least two characters in the buffer, namely '\n' followed by '\0'.
            // Exception: buffer was full before '\n' was read. Then we only
            // have a '\0' in the buffer.
            len = strlen(buffer);
            // Note: function strlen does not count the terminating '\0'.
            if (buffer[len -1] != '\n') {
                // Input line was not yet finished. No '\n' in buffer.
                // Delete the last char before '\0'from the buffer because
                // it exceeds the allowed number of characters.
                buffer[len -1] = '\0';
                // Delete the rest of the line that is already in OS input buffer
                while (fgetc(in) != '\n'){;}
            } else {
                // Input line in buffer ends with '\n'
                // Delete the '\n' from the buffer
                buffer[len -1] = '\0';
            }
        } else {
            // fgets returned NULL
            // The reason may be either End Of File (EOF) or a real read error.
            // We immediately return on real read error
            if (!feof(in)) {
                char buf[100];
                sprintf(buf,"Fehler beim Lesen von Zeile %d aus Datei %s",
                        rownr +1,filename);
                showDialog(buf,"Bitte eine Taste druecken");
                return RES_FAILED;
            } else {
                // We got EOF, skip rest of loop
                // Loop condition will fire
                continue;
            }
        }
        // If we reach this line, our buffer is filled with the current input line.
        // Due to our logic above the variable len is properly set.
        // However, for the sake of clarity we compute the length again
        len = strlen(buffer);

        // Fill the board's row with the symbols specified in the current input line
        for (x = 0; x <= aboard->last_col && x < len; x++) {
            switch (buffer[x]) {
                case SYMBOL_BARRIER:
                    placeItem(aboard,rownr,x,BC_BARRIER,SYMBOL_BARRIER,COLP_BARRIER);
                    break;
                case SYMBOL_FOOD_1:
                    @002
                case SYMBOL_FOOD_2:
                    @002
                case SYMBOL_FOOD_3:
                    @002

                // We ignore all other symbols! 
            }
        }
        // advance to next input line
        rownr++;
    } // END while
    
    // Free the line buffer
    free(buffer);

    // Draw a line in order to separate the message area
    // Note:
    // we cannot use function placeItem() since the message area is outside the board!
    for (x=0; x <= aboard->last_col; x++) {
        @003
    }

    fclose(in);
    return RES_OK;
}
