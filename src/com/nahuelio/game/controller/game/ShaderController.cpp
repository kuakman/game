/**
 * Class ShaderController
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 **/
#include "headers/ShaderController.h"
#include <boost/filesystem.hpp>
#include <boost/assign/list_inserter.hpp>
#include <boost/foreach.hpp>
#include <iostream>

namespace fs = boost::filesystem;
using namespace game_controller;

ShaderController::ShaderController() {
    this->initialize(fs::current_path().string());
};

ShaderController::ShaderController(std::string basePath) {
    this->initialize(basePath);
};

ShaderController *ShaderController::_instance = 0;

ShaderController *ShaderController::instance() {
    if(!_instance) _instance = new ShaderController();
    return _instance;
};

/** Methods **/

void ShaderController::initialize(std::string basePath) {
    this->basePath = basePath;
};

const std::string ShaderController::resolvePath(std::string file, std::string ext) {
    return (this->basePath + "/shaders/" + file + "." + ext);
}

const char* ShaderController::read(std::string file, std::string ext) {
    std::string output = "";
    fs::load_string_file(this->resolvePath(file, ext), output);
    return output.c_str();
}

GLuint ShaderController::compile(std::string file, std::string ext, GLuint id) {
    int success;
    glCompileShader(id);
    this->debug(file, id, success);
    boost::assign::insert(this->shaders) (this->resolvePath(file, ext), id);
    return id;
}

void ShaderController::debug(std::string file, GLuint id, int success) {
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[1024];
        glGetShaderInfoLog(id, 1024, NULL, infoLog);
        printf("Error Compiling Shader [%s:%d]: %s", file.c_str(), id, infoLog);
    }
}

void ShaderController::debugProgram(GLuint id, int success) {
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[1024];
        glGetProgramInfoLog(id, 1024, NULL, infoLog);
        printf("Error Compiling Program [%d]: %s", id, infoLog);
    }
}

GLuint ShaderController::load(std::string file, GLenum type) {
    unsigned int shader;
    shader = glCreateShader(type);
    const char* out = this->read(file, "glsl");
    glShaderSource(shader, 1, &out, NULL);
    return this->compile(file, "glsl", shader);
}

unsigned int ShaderController::getProgramWith() {
    int success;
    unsigned int program;
    program = glCreateProgram();
    BOOST_FOREACH(map_shader::value_type &shader, shaders) {
        glAttachShader(program, shader.second);
    }
    glLinkProgram(program);
    this->debugProgram(program, success);
    return program;
}
