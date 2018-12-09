// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      mxd.cpp
/// @brief     Implementation of mxd.hpp.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 13, 2018
/// @copyright (C) 2018 Nabla Zero Labs

// Related mxd header
#include "mxd.hpp"

// C++ Standard Library
#include <sstream>
#include <stdexcept>

// mxd Library
#include "window.hpp"

// OpenGL Libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace nzl {

void initialize() {
  if (auto status = glfwInit(); status == GLFW_FALSE) {
    throw std::runtime_error("Unable to initialize GLFW");
  }

  nzl::Window win(800, 600, "Invisible Window");
  win.hide();
  win.make_current();

  glfwWindowHint(GLFW_VERSION_MAJOR, glGetString(GL_VERSION)[0]);
  glfwWindowHint(GLFW_VERSION_MINOR, glGetString(GL_VERSION)[2]);
};

void terminate() noexcept { glfwTerminate(); }

void requires_current_context() {
  if (glfwGetCurrentContext() == nullptr) {
    std::ostringstream oss;
    oss << "There is no current OpenGL context";
    throw std::runtime_error(oss.str());
  }
}

}  // namespace nzl
