
#include "matrix.h"
#include <cassert>
#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include "c_allocator.h"
#include "putting_it_together_ch04.h"

using namespace RayTracer;

void glfw_error_callback(int error, const char *desc);
void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void glfw_window_size_callback(GLFWwindow *window, int width, int height);

static const char* vertex_shader_text =
"#version 330 core\n"
"layout (location = 0) in vec2 vPos;\n"
"layout (location = 1) in vec2 uv;\n"
"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"
"out vec2 tex_coord;\n"
"void main() {\n"
"    gl_Position = projection * view * model * vec4(vPos.x, vPos.y, 0.0, 1.0);\n"
"    tex_coord = uv;\n"
"}\n";

static const char* fragment_shader_text =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 tex_coord;\n"
"uniform sampler2D tex_sampler;\n"
"void main () {\n"
"    FragColor = texture(tex_sampler, tex_coord);\n"
"}\n";

bool toggle_wireframe = false;
bool wireframe = false;
float screen_ratio;

Matrix model_matrix;
GLint model_matrix_location;

Matrix view_matrix;
GLint view_matrix_location;

Matrix projection_matrix;
GLint projection_matrix_location;

void update_viewport(int width, int height)
{
    screen_ratio = (float)width / (float)height;
    glViewport(0, 0, width, height);

    view_matrix = matrix_scale(width, height, 1);
    glUniformMatrix4fv(view_matrix_location, 1, GL_TRUE, view_matrix.flat);

    projection_matrix = matrix_ortho(0, width, height, 0, -1, 1);
    glUniformMatrix4fv(projection_matrix_location, 1, GL_TRUE, projection_matrix.flat);
}

int main(int argc, char** argv)
{
    auto ca = c_allocator_get();
    Canvas c = CH04::CH04_putting_it_together(ca);

    GLFWwindow *window;

    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit()) {
        fprintf(stderr, "glfwInit() failed\n");
        return -1;
    }

    int window_width = c.width;
    int window_height = c.height;
    screen_ratio = (float)window_width / (float)window_height;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(window_width, window_height, "RayTracer", nullptr, nullptr);
    assert(window);

    glfwSetKeyCallback(window, glfw_key_callback);
    glfwSetWindowSizeCallback(window, glfw_window_size_callback);

    glfwMakeContextCurrent(window);

    gladLoadGL(glfwGetProcAddress);

    auto gl_version = glGetString(GL_VERSION);
    auto gl_renderer = glGetString(GL_RENDERER);
    auto gl_shading_language_version = glGetString(GL_SHADING_LANGUAGE_VERSION);

    printf("GL_VERSION: %s\n", gl_version);
    printf("GL_RENDERER: %s\n", gl_renderer);
    printf("GL_SHADING_LANGUAGE_VERSION: %s\n", gl_shading_language_version);

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, nullptr);
    glCompileShader(vertex_shader);
    GLint shader_compiled = 0;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &shader_compiled);
    assert(shader_compiled == GL_TRUE);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &shader_compiled);
    assert(shader_compiled == GL_TRUE);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    GLint program_linked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    assert(program_linked == GL_TRUE);

    float vertices[] = {
        // positions     // uvs
         1.0f,  1.0f,    1.0f, 1.0f, // top right
         1.0f,  0.0f,    1.0f, 0.0f, // bottom right
         0.0f,  0.0f,    0.0f, 0.0f, // bottom left
         0.0f,  1.0f,    0.0f, 1.0f, // top left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2  * sizeof(float)));
    glEnableVertexAttribArray(1);

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, c.width, c.height, 0, GL_RGB, GL_FLOAT, c.buffer);
    glGenerateMipmap(GL_TEXTURE_2D);

    glUseProgram(program);

    model_matrix_location = glGetUniformLocation(program, "model");
    view_matrix_location = glGetUniformLocation(program, "view");
    projection_matrix_location = glGetUniformLocation(program, "projection");

    // model_matrix = matrix_identity().translate(-0.5, -0.5, 0).rotate_z(M_PI / 2).translate(0.5, 0.5,  0);
    model_matrix = matrix_identity();

    glUniformMatrix4fv(model_matrix_location, 1, GL_TRUE, model_matrix.flat);

    glClearColor(0.1, 0.1, 0.1, 1);

    update_viewport(window_width, window_height);

    glfwSwapInterval(1);

    while (true) {
        glfwPollEvents();

        if (glfwWindowShouldClose(window)) {
            break;
        }

        if (toggle_wireframe) {
            toggle_wireframe = false;
            wireframe = !wireframe;

            if (wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_W && action == GLFW_PRESS) {
        toggle_wireframe = true;
    }
}

void glfw_error_callback(int error, const char *desc)
{
    fprintf(stderr, "GLFW Error: %s\n", desc);
}

void glfw_window_size_callback(GLFWwindow *window, int width, int height)
{
    update_viewport(width, height);
}
