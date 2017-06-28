/**
 * Interface GameController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/

#ifndef GAME_SHADERCONTROLLER_H
#define GAME_SHADERCONTROLLER_H

#include <glad.h>
#include "../../headers/Controller.h"

namespace game_controller {

    class ShaderController : public Controller {

        static ShaderController *_instance;

        private:
            std::string basePath;
            void initialize(std::string basePath);
            void compile(std::string file, GLuint id);
            void debug(std::string file, GLuint id, int success);
            void debugProgram(GLuint id, int success);
            const GLchar* *read(std::string file, std::string ext);

        public:
            ShaderController();
            ShaderController(std::string basePath);

            int load(std::string file, GLenum type);
            int getProgramWith();

            static ShaderController *instance();
    };

}

#endif //GAME_SHADERCONTROLLER_H
