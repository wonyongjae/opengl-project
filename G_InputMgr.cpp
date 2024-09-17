#include "G_InputMgr.h"

bool G_InputMgr::init(GLFWwindow* arg_window)
{
    if (arg_window == nullptr)
        return false;

    /* Cursor pos set to window's center */
    glfwSetCursorPos(arg_window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    /* Callback Functions set */
    glfwSetKeyCallback(arg_window, keyboardCallback);
    glfwSetCursorPosCallback(arg_window, mouseCursorPosCallback);
    glfwSetMouseButtonCallback(arg_window, mouseButtonCallback);

    return true;
}

void G_InputMgr::keyboardCallback(GLFWwindow* arg_window, int arg_key, int arg_scancode, int arg_action, int arg_mods)
{
    switch (arg_key) {
    case GLFW_KEY_ESCAPE:
    case GLFW_KEY_Q:
        glfwDestroyWindow(arg_window);
        glfwTerminate();
        exit(0);
        break;

    case GLFW_KEY_W: std::cout << "W" << std::endl; break;
    case GLFW_KEY_S: std::cout << "S" << std::endl; break;
    case GLFW_KEY_A: std::cout << "A" << std::endl; break;
    case GLFW_KEY_D: std::cout << "D" << std::endl; break;
    default: break;
    }

    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();
    camera->OnKeyboard(arg_key);
}

void G_InputMgr::mouseCursorPosCallback(GLFWwindow* arg_window, double arg_x, double arg_y)
{
    //std::cout << "mouse pos " << arg_x << ", " << arg_y << std::endl;
}

void G_InputMgr::mouseButtonCallback(GLFWwindow* arg_window, int arg_button, int arg_action, int arg_Mode)
{
    double x, y;

    glfwGetCursorPos(arg_window, &x, &y);

    if (arg_button == GLFW_MOUSE_BUTTON_LEFT) {
        m_Mouse.isLeftPressed = (arg_action == GLFW_PRESS);

        if (!m_Mouse.isLeftPressed) {
            std::cout << "mouse left clicked call " << std::endl;
        }
    }

    if (arg_button == GLFW_MOUSE_BUTTON_RIGHT) {
        m_Mouse.isRightPressed = (arg_action == GLFW_PRESS);

        if (!m_Mouse.isLeftPressed) {
            std::cout << "mouse right clicked call " << std::endl;
        }
    }

    m_Mouse.x = (int)x;
    m_Mouse.y = (int)y;

    BasicCamera* camera = G_CameraMgr::getInstance().getCamera();
    camera->OnMouse(x, y);
}
