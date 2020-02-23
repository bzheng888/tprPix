/*
 * ======================= BioSoup.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.02.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "Script/gameObjs/bioSoup/BioSoup.h"

//-------------------- CPP --------------------//
#include <cmath>
#include <functional>
#include <string>
#include <vector>

//-------------------- tpr --------------------//
#include "tprGeneral.h"

//-------------------- Engine --------------------//
#include "tprAssert.h"
#include "Density.h"
#include "animSubspeciesId.h"
#include "RenderPool.h"
#include "create_go_oth.h"
#include "dyParams.h"

#include "esrc_shader.h" 
#include "esrc_chunk.h"
#include "esrc_ecoObj.h"
#include "esrc_animFrameSet.h"

//-------------------- Script --------------------//
#include "Script/gameObjs/assemble_go.h"

using namespace std::placeholders;

#include "tprDebug.h" 


namespace gameObjs{//------------- namespace gameObjs ----------------
namespace bioSoup_inn {//------------------ namespace: bioSoup_inn ---------------------//

    double calc_goMeshZOff( size_t mapEntUWeight_ );


}//--------------------- namespace: bioSoup_inn end ------------------------//


struct FloorGo_PvtBinary{

    int tmp {};
    //===== padding =====//
    //...
};


void BioSoup::init(GameObj &goRef_, const DyParam &dyParams_ ){

    //================ go.pvtBinary =================//
    auto *pvtBp = goRef_.init_pvtBinary<FloorGo_PvtBinary>();

    //========== 标准化装配 ==========//
    assemble_regularGo( goRef_, dyParams_ );

    //================ bind callback funcs =================//
    //-- 故意将 首参数this 绑定到 保留类实例 dog_a 身上
    goRef_.RenderUpdate = std::bind( &BioSoup::OnRenderUpdate,  _1 );   
    
    //-------- actionSwitch ---------//
    goRef_.actionSwitch.bind_func( std::bind( &BioSoup::OnActionSwitch,  _1, _2 ) );

    //================ go self vals =================//
}



void BioSoup::OnRenderUpdate( GameObj &goRef_ ){

    //=====================================//
    //  将 确认要渲染的 goMeshs，添加到 renderPool         
    //-------------------------------------//
    goRef_.render_all_goMesh();
}


/* -- 此处用到的 animFrameIdxHdle实例，是每次用到时，临时 生产／改写 的
 * -- 会被 动作状态机 取代...
 */
void BioSoup::OnActionSwitch( GameObj &goRef_, ActionSwitchType type_ ){
    tprAssert(0);
}


namespace bioSoup_inn {//------------------ namespace: bioSoup_inn ---------------------//



double calc_goMeshZOff( size_t mapEntUWeight_ ){

    // 获得一个 小数值 (0.0, 0.1)
    double rd = static_cast<double>(mapEntUWeight_) / 71.17;
    double integer {}; // 不会被使用
    double fract = modf(rd, &integer) / 10.0; // (0.0, 0.1)
    return ( floorGoLayer_2_goMesh_baseZOff(FloorGoLayer::L_4) + fract );
}




}//--------------------- namespace: bioSoup_inn end ------------------------//
}//------------- namespace gameObjs: end ----------------

