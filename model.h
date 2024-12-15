#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include "geometry.h"

class Model {
private:
	std::vector<Vec3f> verts_;
	std::vector<Vec3f> textures_;
	std::vector< std::vector<std::vector<int>> > faces_;
public:
	Model(const char *filename);
	~Model();
	int nverts();
	int ntextures_();
	int nfaces();
	Vec3f vert(int i);
	Vec3f texture(int i);
	std::vector<std::vector<int>> face(int idx);
};

#endif //__MODEL_H__
