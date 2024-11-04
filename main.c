#include "pocketpy.h"
#include <assert.h>

void py__add_module_raylib();

int main(){
    py_initialize();

    // add raylib module to python
    py__add_module_raylib();

    char* source = py_callbacks()->importfile("main.py");
    assert(source != NULL);

    bool ok = py_exec(source, "main.py", EXEC_MODE, NULL);
    if(!ok) py_printexc();
    
    py_finalize();
    return 0;
}
