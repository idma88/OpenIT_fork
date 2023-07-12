/**
 * @file Entrypoint.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение макроса точки входа в приложение
 */
#pragma once

#ifdef WIN32
#include <windows.h>
#define ENTRYPOINT_MAIN                                                                            \
  int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpCmdLine, int nCmdShow)
#else
#define ENTRYPOINT_MAIN int main(int argc, char* argv[])
#endif