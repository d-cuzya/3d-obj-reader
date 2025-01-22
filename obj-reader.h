#pragma once
#include <vector>
#include <string>
//https://en.wikipedia.org/wiki/Wavefront_.obj_file

std::vector<std::string> split_str(std::string str, char target) {
	std::vector<std::string> tmp;
	std::string once_str = "";
	//std::cout << str.length() << ") " << str << std::endl;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != target) {
			once_str += str[i];
		}
		else {
			tmp.push_back(once_str);
			once_str = "";
		}
	}
	if (once_str != "") {
		tmp.push_back(once_str);
	}
	return tmp;
}

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