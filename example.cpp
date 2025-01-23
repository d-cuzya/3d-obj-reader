#include "obj-reader.h"

int main() {
	ObjReader obj_reader;
	Obj file = obj_reader.create_obj("./objs/suzanne.obj");
}