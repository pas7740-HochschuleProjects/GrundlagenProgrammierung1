# Instrument debugging session
#
# 1) in some terminal, query for the tty
#
# tty
#   output e.g.
#   /dev/pts/2
#
# 2) start gdb session like this:
#
# gdbtui -x count.gdb -tty /dev/pts/2 -q bin/count 
#

# Set breakpoints
break main
# Configure layout
winheight src 15
# Start the programm
run
# Set variables to display at the deugger's prompt
display i
