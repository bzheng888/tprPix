/*
 * ========================= input.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.01.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *   键盘，鼠标，joystick 等输入设备 管理文件
 * ----------------------------
 */
#ifndef TPR_INPUT_H
#define TPR_INPUT_H
//=== *** glad FIRST, glfw SECEND *** ===
#include<glad/glad.h>  
#include<GLFW/glfw3.h>

//-------------------- CPP --------------------//
#include <functional>

//-------------------- Engine --------------------//
#include "IntVec.h" 
#include "InputINS.h"


namespace input{//------------- namespace input --------------------


using F_InputINS_Handle = std::function< void(const InputINS&) >;


//-- 外部通过这个函数，来绑定需要的 inputINS 处理函数 --
void bind_inputINS_handleFunc( const F_InputINS_Handle &_func );


void init_input();

void processInput( GLFWwindow *windowPtr_ );
//void scroll_callback(GLFWwindow* windowPtr_, double xoffset_, double yoffset_);
IntVec2 get_mouse_pos();


}//----------------- namespace input: end -------------------
#endif 

