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
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * numVertices * 3 , vertices, GL_STATIC_DRAW);
        glVertexAttribPointer( 0 , numVertices , GL_FLOAT , GL_FALSE , 0 , (void*)0);

        glEnableVertexAttribArray(0);
        glBindBuffer(1,vertexBufferObject);

        return true;
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
