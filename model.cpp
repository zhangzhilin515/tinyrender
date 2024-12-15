#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "model.h"

Model::Model(const char *filename) : verts_(), faces_() {
    std::ifstream in;
    in.open (filename, std::ifstream::in);
    if (in.fail()) {
        std::cerr << "Fail to load model " << filename << std::endl;
        return;
    }
    std::cerr << "Load model " << filename << " successfully" << std::endl;
    std::string line;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vec3f v;
            for (int i=0;i<3;i++) iss >> v[i];
            verts_.push_back(v);
        }
        else if(!line.compare(0, 4, "vt  ")) {
            iss >> trash >> trash;
            Vec3f t;
            for(int i = 0; i < 3; i++) iss >> t[i];
            textures_.push_back(t);
        } 
        else if (!line.compare(0, 2, "f ")) {
            std::vector<std::vector<int>> f(2);
            int itrash, vidx, vtidx;
            iss >> trash;
            while (iss >> vidx >> trash >> vtidx >> trash >> itrash) {
                vidx--; // in wavefront obj all indices start at 1, not zero
                vtidx--;
                f[0].push_back(vidx);
                f[1].push_back(vtidx);
            }
            faces_.push_back(f);
        }
    }
    std::cerr << "# v# " << verts_.size() << " vt# " << textures_.size() << " f# "  << faces_.size() << std::endl;
}

Model::~Model() {
}

int Model::nverts() {
    return (int)verts_.size();
}

int Model::ntextures_() {
    return (int)textures_.size();
}

int Model::nfaces() {
    return (int)faces_.size();
}

std::vector<std::vector<int>> Model::face(int idx) {
    return faces_[idx];
}

Vec3f Model::vert(int i) {
    return verts_[i];
}

Vec3f Model::texture(int i) {
    return textures_[i];
}