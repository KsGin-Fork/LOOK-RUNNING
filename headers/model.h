//
// Created by ksgin on 18-8-29.
//

#ifndef LOOK_RUNNING_MODEL_H
#define LOOK_RUNNING_MODEL_H

#include "common.h"

/**
 * model class
 */
class model {
public:

    /**
     * DATA TYPE
     */
    enum dataType {
        VERTEX ,
        UV
    };

    /**
     * VAO
     */
    unsigned int vertexArrayObject;
    /**
     * VBO
     */
    unsigned int vertexBufferObject;

    /**
     * initialize
     * @param vertices vertices
     */
    bool initialize(const float *vertices , const int numVertices) {

        glGenVertexArrays(1 , &vertexArrayObject);
        glGenBuffers(1, &vertexBufferObject);

        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVertices , vertices, GL_STATIC_DRAW);
        glBindBuffer(1,vertexBufferObject);

        return true;
    }

    /**
     * pointer vertex buffer
     */
     void vertexPointer(const unsigned int idx , const int size , const int stride , const int begin) {
        glVertexAttribPointer(idx , size , GL_FLOAT , GL_FALSE , stride * sizeof(float) , (void*)(begin * sizeof(float)));
        glEnableVertexAttribArray(idx);
     }

    /**
     * draw
     */
    void draw(int first , int count) {
        glBindVertexArray(vertexArrayObject);
        glDrawArrays(GL_TRIANGLES , first , count);
    }

    /**
     * destroy
     */
    void destroy() {
        glDeleteVertexArrays(1 , &vertexArrayObject);
        glDeleteBuffers(1 , &vertexBufferObject);
    }
};

#endif //LOOK_RUNNING_MODEL_H
