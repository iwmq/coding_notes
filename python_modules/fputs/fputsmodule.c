#include <Python.h>


static PyObject * StringTooShortError = NULL;


// Define the wrapper of fputs
static PyObject *method_fputs(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int byte_copied = -1;

    // Parse arguments
    if (!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    // Check if this str is too shor
    if (strlen(str) < 10) {
        PyErr_SetString(
            StringTooShortError,
            "String length must be greater than 10"
        );

        return NULL;
    }

    FILE *fp = fopen(filename, "w");
    byte_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(byte_copied);
}


// Define methods
static PyMethodDef FputsMethods[] = {
    {
        "fputs",
        method_fputs,
        METH_VARARGS,
        "Python interface for the fputs C library function"
    },
    {NULL, NULL, 0, NULL}
};


// Define module objects
static PyModuleDef fputsmodule = {
    PyModuleDef_HEAD_INIT,
    "fputs",
    "Python interface for the fputs C library function",
    -1,
    FputsMethods
};

// Initialization
PyMODINIT_FUNC PyInit_fputs(void) {
    // Create module instance
    PyObject *module = PyModule_Create(&fputsmodule);

    // Create new exception object
    StringTooShortError = PyErr_NewException(
        "fputs.StringTooShortError", NULL, NULL
    );

    // Add the exception object to module
    PyModule_AddObject(module, "StringTooShortError", StringTooShortError);

    // Define a constant
    PyModule_AddIntConstant(module, "FPUTS_FLAGS", 64);

    // Define a marco and add it to moduel
    #define FPUTS_MACRO 256
    PyModule_AddIntMacro(module, FPUTS_MACRO);

    return module;
}