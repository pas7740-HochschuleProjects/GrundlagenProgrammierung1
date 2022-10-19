# Disassembler auf INTEL-Variante stellen
set disassembly-flavor intel

# Speziell für das Programm arraySum
break main
winheight src 14

# Auto-Display
# Angabe des Scopes main:: notwendig
# Sonst Fehlermeldung wenn nicht in Scope von main()
display main::sum
display main::i

