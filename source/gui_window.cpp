#include "gui_window.h"

#pragma warning(disable:4551)
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#pragma warning(default:4551)

#include <cstdio>

void guisystem_init()
{
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit()) {
        fprintf(stderr, "glfwInit() failed\n");
        assert(false);
    }

}

void guisystem_deinit()
{
    glfwTerminate();
}

void guiwindow_show(const Canvas &c)
{
    GLFWwindow *window;

    GUI_Window my_window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    window = glfwCreateWindow(c.width, c.height, "RayTracer", nullptr, nullptr);
    if (!window) return;

    int iwidth, iheight;
    glfwGetWindowSize(window, &iwidth, &iheight);
    my_window.screen_ratio = (float)iwidth / (float)iheight;

    printf("Window size: %d, %d\n", iwidth, iheight);
    printf("Canvas size: %d, %d\n", c.width, c.height);

    my_window.width = iwidth;
    my_window.height = iheight;

    glfwSetWindowUserPointer(window, &my_window);

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

    char buffer[2048];

    if (shader_compiled != GL_TRUE) {

        GLsizei length; 
        glGetShaderInfoLog(vertex_shader, 2048, &length, buffer);
        fprintf(stderr, "Shader compilation failed: \n%.*s\n",
                length, buffer);
        return;
    }

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &shader_compiled);

    if (shader_compiled != GL_TRUE) {

        GLsizei length; 
        glGetShaderInfoLog(fragment_shader, 2048, &length, buffer);
        fprintf(stderr, "Shader compilation failed: \n%.*s\n",
                length, buffer);
        return;
    }

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

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, c.width, c.height, 0, GL_RGB, GL_FLOAT, c.buffer);

    glUseProgram(program);

    my_window.model_matrix_location = glGetUniformLocation(program, "model");
    my_window.view_matrix_location = glGetUniformLocation(program, "view");
    my_window.projection_matrix_location = glGetUniformLocation(program, "projection");

    my_window.model_matrix = matrix_identity();
    glUniformMatrix4fv(my_window.model_matrix_location, 1, GL_TRUE, my_window.model_matrix.flat);

    glClearColor(0.1f, 0.1f, 0.1f, 1.f);

    update_viewport(&my_window, my_window.width, my_window.height);

    glfwSwapInterval(1);

    while (true) {
        glfwPollEvents();

        if (glfwWindowShouldClose(window)) {
            break;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
}

void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void glfw_error_callback(int error, const char *desc)
{
    fprintf(stderr, "GLFW Error: %s\n", desc);
}

void glfw_window_size_callback(GLFWwindow *window, int width, int height)
{
    auto my_window = (GUI_Window *)glfwGetWindowUserPointer(window);
    update_viewport(my_window, width, height);
}

void update_viewport(GUI_Window *window, int width, int height)
{
    window->screen_ratio = (float)width / (float)height;
    glViewport(0, 0, width, height);

    float mxscale = 1.0f;
    float myscale = 1.0f;

    if (width > height) {
        mxscale /= window->screen_ratio;
    } else if (width < height) {
        myscale *= window->screen_ratio;
    }

    window->view_matrix = matrix_scale(width * mxscale, height * myscale, 1);
    glUniformMatrix4fv(window->view_matrix_location, 1, GL_TRUE, window->view_matrix.flat);

    window->projection_matrix = matrix_ortho(0, (float)width, (float)height, 0, -1, 1);
    glUniformMatrix4fv(window->projection_matrix_location, 1, GL_TRUE,
                       window->projection_matrix.flat);
}

