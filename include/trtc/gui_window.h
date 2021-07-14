#pragma once

#include "canvas.h"
#include "matrix.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#pragma warning(disable:4551)
#include <glad/gl.h>
#pragma warning(default:4551)


using namespace RayTracer;

struct GUI_Window
{
    float screen_ratio;
    int width;
    int height;

    Matrix model_matrix;
    Matrix view_matrix;
    Matrix projection_matrix;

    GLint model_matrix_location;
    GLint view_matrix_location;
    GLint projection_matrix_location;
};

void guisystem_init();
void guisystem_deinit();

void guiwindow_show(const Canvas &c);

void glfw_error_callback(int error, const char *desc);
void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void glfw_window_size_callback(GLFWwindow *window, int width, int height);

void update_viewport(GUI_Window *window, int width, int height);

static const char* vertex_shader_text =
"#version 120\n"
"attribute vec2 vPos;\n"
"attribute vec2 uv;\n"
"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"
"varying vec2 tex_coord;\n"
"void main() {\n"
"    gl_Position = projection * view * model * vec4(vPos.x, vPos.y, 0.0, 1.0);\n"
"    tex_coord = uv;\n"
"}\n";

static const char* fragment_shader_text =
"#version 120\n"
// "varying vec4 FragColor;\n"
"varying vec2 tex_coord;\n"
"uniform sampler2D tex_sampler;\n"
"void main () {\n"
"    gl_FragColor = texture2D(tex_sampler, tex_coord);\n"
"}\n";


