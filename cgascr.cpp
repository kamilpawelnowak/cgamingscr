#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
//Code created using Gemini

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
switch (message) {
case WM_CLOSE:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}  

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);  

}

GLfloat angle = 0.0f;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
WNDCLASSEX wc;
wc.cbSize = sizeof(WNDCLASSEX);
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = WndProc;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor = LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
wc.lpszMenuName = NULL;
wc.lpszClassName = "OpenGLWindow";
wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
if (!RegisterClassEx(&wc)) {
    MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

HWND  
 hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,  
 "OpenGLWindow", "OpenGL Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 1280, NULL, NULL, hInstance, NULL);

if (!hWnd) {
    MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

ShowWindow(hWnd, nCmdShow);
UpdateWindow(hWnd);  


HDC hDC;
HGLRC hRC;

hDC = GetDC(hWnd);

PIXELFORMATDESCRIPTOR pfd;
pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
pfd.nVersion = 1;
pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL  
 | PFD_DOUBLEBUFFER;
pfd.iPixelType = PFD_TYPE_RGBA;
pfd.cColorBits = 32;
pfd.cDepthBits = 24;
pfd.cStencilBits = 8;
pfd.iLayerType = PFD_MAIN_PLANE;  


int iPixelFormatIndex = ChoosePixelFormat(hDC, &pfd);
SetPixelFormat(hDC, iPixelFormatIndex, &pfd);

hRC = wglCreateContext(hDC);
wglMakeCurrent(hDC, hRC);

glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glEnable(GL_DEPTH_TEST);

while (true) {
    MSG msg;
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            break;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle, 0.0, 1.0, 0.0);
    //GLUquadricObj *quadric = gluNewQuadric();
    //gluSphere(quadric, 1.0, 20, 20);
    //gluDeleteQuadric(quadric);
    glFlush(); 
    angle += 0.4f;

    // Your OpenGL rendering code here
    //glColor3f(1.0f, 0.0f, 0.0f); // Red
    //glColor3f(0.0f, 0.0f, 1.0f); // Blue
    //glColor3f(0.0f, 1.0f, 0.0f); // Green
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex3f(-0.3f, 0.4f,0.1f);
        glVertex3f(-0.2f, 0.3f,0.1f);
        glVertex3f(-0.2f, -0.3f,0.1f);
        glVertex3f(-0.3f, -0.4f,0.1f);
        glVertex3f(-0.3f, -0.4f,-0.1f);
        glVertex3f(-0.3f, 0.4f,-0.1f);
        glVertex3f(-0.3f, 0.4f,0.1f);
        glVertex3f(-0.3f, -0.4f,0.1f);
        glVertex3f(-0.3f, 0.4f,-0.1f);
        glVertex3f(-0.2f, 0.3f,-0.1f);
        glVertex3f(-0.2f, -0.3f,-0.1f);
        glVertex3f(-0.3f, -0.4f,-0.1f);
        glVertex3f(-0.2f, 0.3f,0.1f);
        glVertex3f(-0.2f, 0.3f,-0.1f);
        glVertex3f(-0.2f, -0.3f,-0.1f);
        glVertex3f(-0.2f, -0.3f,0.1f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-0.3f, 0.4f,0.1f);
        glVertex3f(0.0f, 0.6f,0.05f);
        glVertex3f(0.0f, 0.5f,0.05f);
        glVertex3f(-0.2f, 0.3f,0.1f);
        glVertex3f(-0.2f, 0.3f,-0.1f);
        glVertex3f(0.0f, 0.5f,-0.05f);
        glVertex3f(0.0f, 0.5f,0.05f);
        glVertex3f(-0.2f, 0.3f,0.1f);
        glVertex3f(-0.2f, 0.3f,-0.1f);
        glVertex3f(-0.3f, 0.4f,-0.1f);
        glVertex3f(0.0f, 0.6f,-0.05f);
        glVertex3f(0.0f, 0.5f,-0.05f);
        glVertex3f(-0.2f, 0.3f,-0.1f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-0.3f, 0.4f,-0.1f);
        glVertex3f(-0.3f, 0.4f,0.1f);
        glVertex3f(0.0f, 0.6f,0.05f);
        glVertex3f(0.0f, 0.6f,-0.05f);
        glVertex3f(-0.3f, 0.4f,-0.1f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-0.3f, -0.4f,0.1f);
        glVertex3f(0.0f, -0.6f,0.05f);
        glVertex3f(0.0f, -0.5f,0.05f);
        glVertex3f(-0.2f, -0.3f,0.1f);
        glVertex3f(-0.2f, -0.3f,-0.1f);
        glVertex3f(0.0f, -0.5f,-0.05f);
        glVertex3f(0.0f, -0.5f,0.05f);
        glVertex3f(-0.2f, -0.3f,0.1f);
        glVertex3f(-0.3f, -0.4f,-0.1f);
        glVertex3f(0.0f, -0.6f,-0.05f);
        glVertex3f(0.0f, -0.5f,-0.05f);
        glVertex3f(-0.2f, -0.3f,-0.1f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-0.3f, -0.4f,-0.1f);
        glVertex3f(-0.3f, -0.4f,0.1f);
        glVertex3f(0.0f, -0.6f,0.05f);
        glVertex3f(0.0f, -0.6f,-0.05f);
        glVertex3f(-0.3f, -0.4f,-0.1f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex3f(0.0f, 0.5f,0.05f);
        glVertex3f(0.0f, 0.6f,0.05f);
        glVertex3f(0.3f, 0.4f,0.0f);
        glVertex3f(0.0f, 0.5f,-0.05f);
        glVertex3f(0.0f, 0.6f,-0.05f);
        glVertex3f(0.0f, 0.6f,0.05f);
        glVertex3f(0.3f, 0.4f,0.0f);
        glVertex3f(0.0f, 0.5f,-0.05f);
        glVertex3f(0.0f, 0.5f,0.05f);
        glVertex3f(0.3f, 0.4f,0.0f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex3f(0.0f, -0.5f,0.05f);
        glVertex3f(0.0f, -0.6f,0.05f);
        glVertex3f(0.3f, -0.4f,0.0f);
        glVertex3f(0.0f, -0.5f,-0.05f);
        glVertex3f(0.0f, -0.6f,-0.05f);
        glVertex3f(0.0f, -0.6f,0.05f);
        glVertex3f(0.3f, -0.4f,0.0f);
        glVertex3f(0.0f, -0.5f,-0.05f);
        glVertex3f(0.0f, -0.5f,0.05f);
        glVertex3f(0.3f, -0.4f,0.0f);
    glEnd();

    SwapBuffers(hDC);
}

wglMakeCurrent(NULL, NULL);
wglDeleteContext(hRC);
ReleaseDC(hWnd, hDC);
DestroyWindow(hWnd);
return 0;
}


//Drawing letter C
// glBegin(GL_POLYGON);
//         glColor3f(0.0f, 1.0f, 0.0f); // Green
//         glVertex2f(-0.3f, 0.4f);
//         glVertex2f(-0.2f, 0.3f);
//         glVertex2f(-0.2f, -0.3f);
//         glVertex2f(-0.3f, -0.4f);
//     glEnd();
//     glBegin(GL_POLYGON);
//         glColor3f(0.0f, 0.0f, 1.0f); // Blue
//         glVertex2f(-0.3f, 0.4f);
//         glVertex2f(0.0f, 0.6f);
//         glVertex2f(0.0f, 0.5f);
//         glVertex2f(-0.2f, 0.3f);
//     glEnd();
//     glBegin(GL_POLYGON);
//         glColor3f(0.0f, 0.0f, 1.0f); // Blue
//         glVertex2f(-0.3f, -0.4f);
//         glVertex2f(0.0f, -0.6f);
//         glVertex2f(0.0f, -0.5f);
//         glVertex2f(-0.2f, -0.3f);
//     glEnd();
//     glBegin(GL_POLYGON);
//         glColor3f(1.0f, 0.0f, 0.0f); // Red
//         glVertex2f(0.0f, 0.5f);
//         glVertex2f(0.0f, 0.6f);
//         glVertex2f(0.3f, 0.4f);
//     glEnd();
//     glBegin(GL_POLYGON);
//         glColor3f(1.0f, 0.0f, 0.0f); // Red
//         glVertex2f(0.0f, -0.5f);
//         glVertex2f(0.0f, -0.6f);
//         glVertex2f(0.3f, -0.4f);
//     glEnd();
