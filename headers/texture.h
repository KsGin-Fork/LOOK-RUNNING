//
// Created by ksgin on 18-8-29.
//

#ifndef LOOK_RUNNING_TEXTURE_H
#define LOOK_RUNNING_TEXTURE_H

#include "common.h"

class texture {
public:
    unsigned int id;
    bool initialize(const char *filename , bool alpha) {
        glGenTextures(1 , &id);
        glBindTexture(GL_TEXTURE_2D , id);

        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_R , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);

        auto type = GL_RGB;
        if (alpha) type = GL_RGBA;

        int width , height , nrChannels;
        unsigned char * data = stbi_load(filename , &width , &height , &nrChannels , 0);
        if (!data){
            return false;
        }
        glTexImage2D(GL_TEXTURE_2D , 0 , type , width , height , 0 , type , GL_UNSIGNED_BYTE , data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
        return true;
    }
    void use() {
        glBindTexture(GL_TEXTURE_2D , id);
    }
};

#endif //LOOK_RUNNING_TEXTURE_H
