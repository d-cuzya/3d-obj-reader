#pragma once
#include <vector>
#include <string>
#include <fstream>
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
	std::string path;
	std::vector<std::string> mtllibs; //ZDELAT
	std::vector<vertex> vertices;
};

class ObjReader {
public:
	Obj create_obj(const char* file_path) {
		Obj* obj = new Obj();
		this->obj_list.push_back(obj);
		std::ifstream file;
		obj->path = file_path;
		std::vector<std::string> file_str;
		{
			std::string tmpstr;
			file.open(file_path);
			while (std::getline(file, tmpstr)) {
				file_str.push_back(tmpstr);
			}
			file.close();
		}
		for (size_t i = 0; i < file_str.size(); i++)
		{
			if (file_str[i][0] == '#') {
				continue;
			}
			if (file_str[i][0] == 'v') {
				std::vector<std::string> tmpstr = split_str(file_str[i], ' ');
				// DODELAT
			}

		}
	}
	bool clear_objs() { return false; };
	~ObjReader() {
		for (size_t i = 0; i < obj_list.size(); i++)
		{
			delete obj_list[i];
		}
	}
private:
	std::vector<Obj*> obj_list;
};