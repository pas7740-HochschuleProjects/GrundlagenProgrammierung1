Use this generic versions of

.vscode/launch.json
.vscode/tasks.json

for projects with multiple but single C-Files.

You need a Makefile, though!

The tasks configured in tasks.json will run the Makefile
and will start the binary corresponding to the active file in the editor.

Debugging is configured in launch.json and starts the debugger for
the binary corresponding to the active file in the editor.

