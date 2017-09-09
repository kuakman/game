/**
 * Interface GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_SHADERCONTROLLER_H
#define GAME_SHADERCONTROLLER_H

#include <glad/glad.h>
#include <map>
#include "../../headers/Controller.h"

namespace game_controller {

    typedef std::map<std::string, GLuint> map_shader;

    class ShaderController : public Controller {

        static ShaderController *_instance;

        private:
            std::string basePath;
            std::map<std::string, GLuint> shaders;

            void initialize(std::string basePath);
            GLuint compile(std::string file, std::string ext, GLuint id);
            void debug(std::string file, GLuint id, int success);
            void debugProgram(GLuint id, int success);
            const std::string resolvePath(std::string file, std::string ext);
            const char* read(std::string file, std::string ext);

        public:
            ShaderController();
            ShaderController(std::string basePath);

            GLuint load(std::string file, GLenum type);
            unsigned int getProgramWith();

            static ShaderController *instance();
    };

}

#endif //GAME_SHADERCONTROLLER_H
