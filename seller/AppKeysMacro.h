//
//  AppKeysMacro.h
//  new_supply
//
//  Created by HuangHao on 15/7/1.
//  Copyright (c) 2015年 bysunnet. All rights reserved.
//

#ifndef new_supply_AppKeysMacro_h
#define new_supply_AppKeysMacro_h

#if APP_STATUS != AppStatus_Product

// 测试
#   define Umeng_AppKey @"5556a6cce0f55ae4c5004fa5"

#   define AVOSAppID @"nsx87qih0t4u44uttyan77wynvwiwxjly9ntn2uhp14xbbvk"

#   define AVOSAppKey @"futc60n2xl5hr4rer5228y9zwrh0ks5d0qhkjq4w4tttf7ap"

#else

// 正式

#   define Umeng_AppKey @"5556a759e0f55a6a81004498"

#   define AVOSAppID @"iw1qys2i126pfvs6y2mam8k67kmf7anqj4f5rizabon9y73e"

#   define AVOSAppKey @"rfa6ewcvxs5254sfqcjsg38uy2lkkoi5czygsacs52sw3ud6"

#endif


#endif
