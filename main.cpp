#ifdef _DEBUG
#define _DEBUG_WAS_DEFINED 1
#undef _DEBUG
#endif

#include<Python.h>
#include<stdio.h>

// CppModule

static PyObject* CppModule_start(PyObject* self, PyObject* args) { 
	const char* chMsg; 
	char return_chMsg[100];
	if (!PyArg_ParseTuple(args, "s", &chMsg))
		return NULL;
	strcpy(return_chMsg, "PyCppExt_start() executed with message :");
	strcat(return_chMsg, chMsg);
	strcat(return_chMsg, "\0");
	return Py_BuildValue("s", return_chMsg);

};
static PyObject* CppModule_add(PyObject* self, PyObject* args)
{
	int i, j;
	if (!PyArg_ParseTuple(args, "ii", &i, &j))
	{
		return Py_None;
	}
	return PyLong_FromLong(i + j);
}
static PyObject* CppModule_mul(PyObject* self, PyObject* args)
{
	double x, y;
	if (!PyArg_ParseTuple(args, "dd", &x, &y))
	{
		return Py_None;
	}
	return PyFloat_FromDouble(x * y);
}
static PyMethodDef CppModule_Methods[] = {
{ "start", CppModule_start, METH_VARARGS, "probe() of myCppExt module" },
{ "add", CppModule_add, METH_VARARGS, "add() of myCppExt module" },
{ "mul", CppModule_mul, METH_VARARGS, "mul() of myCppExt module" },
{NULL, NULL, 0, NULL}
};

static struct PyModuleDef CppModule_Module = {
PyModuleDef_HEAD_INIT,
"CppModule", // module name
"This is my C Extension Module", // document of module
-1,
CppModule_Methods // methods of module
};
PyMODINIT_FUNC PyInit_CppModule(void)
{
	static PyObject* CppModule_Error;
	PyObject* m;
	m = PyModule_Create(&CppModule_Module);
	if (m == NULL)
		return NULL;
	CppModule_Error = PyErr_NewException("CppModule.error", NULL, NULL);
	Py_INCREF(CppModule_Error);
	PyModule_AddObject(m, "error", CppModule_Error);
	return m;
}
#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG 1
#endif