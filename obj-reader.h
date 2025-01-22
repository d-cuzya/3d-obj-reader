#pragma once
#include <vector>

//https://en.wikipedia.org/wiki/Wavefront_.obj_file

struct vertex {
	float x;
	float y;
	float z;
	float w;
};


struct Obj {
	std::vector<vertex> vertices;
};

class ObjReader {
public:
	Obj create_obj(const char& file_path) {

	}
	bool clear_objs() { return false; };
private:
	std::vector<Obj*> obj_list;
};