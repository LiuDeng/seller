//
//  UIMacro.h
//  shopbaby
//
//  Created by 王飞 on 14-12-12.
//  Copyright (c) 2014年 王飞. All rights reserved.
//

#ifndef shopbaby_UIMacro_h
#define shopbaby_UIMacro_h

#define OFF_Y (IOS7_OR_LATER?20.0f:0.0f)

#define TAB_HEIGHT 49
#define NAV_HEIGHT 44
#define STATUS_HEIGHT 20

//heightForHeaderInSection
#define SECTION_HEADER_HIGHT  5

#define WIDTH_SEPARATOR_LINE .5
#define WIDTH_BORDER         .5

///设备宽高
#define DEVICE_HEIGHT   ([[UIScreen mainScreen]bounds].size.height)
#define DEVICE_WIDTH    ([[UIScreen mainScreen]bounds].size.width)
#define DEVICE_SCALE    (DEVICE_WIDTH * 1.0f / 320)


#define RGB(Red,Green,Blue)         [UIColor colorWithRed:Red/255.0 green:Green/255.0 blue:Blue/255.0 alpha:1.0]
#define RGBA(Red,Green,Blue,Alpha)  [UIColor colorWithRed:Red/255.0 green:Green/255.0 blue:Blue/255.0 alpha:Alpha]

//确定字体
#if 0
#define FONT(fontsize)              [UIFont fontWithName:@"Helvetica" size:fontsize]
#define FONT_BOLD(fontsize)         [UIFont fontWithName:@"Helvetica-Bold" size:fontsize]
#else
#define FONT(fontsize)              [UIFont systemFontOfSize:fontsize]
#define FONT_BOLD(fontsize)         [UIFont boldSystemFontOfSize:fontsize]
#endif



// 通用颜色

//[背景色] 程序主背景
#define COLOR_BACKGROUND                        RGB(245, 245, 245)              //#f5f5f5


#define COLOR_SHADOW_LAYER                      [UIColor colorWithWhite:0.1f alpha:0.7f]


//[文字颜色]
//#define COLOR_TITLE_NORMAL                      RGB(0, 0, 0)                    //#000000

//[文字颜色] 灰色
//#define COLOR_TITLE_LIGHTGRAY                   RGB(110, 110, 110)                 //#616161

//[文字颜色] 重要
#define COLOR_TITLE_IMPORTANT                   RGB(253, 62, 62)                //#fd3e3e
//[文字颜色] placeholder
#define COLOR_TITLE_PLACEHOLDER                 RGB(100, 103, 109)
//分割线颜色
#define COLOR_LINE                              RGB(0xe4,0xe4,0xea)              //


//[文字颜色] 导航栏（标题栏）标题
#define COLOR_NAVBAR_TITLE                      [UIColor whiteColor]

//[背景色] 弹出菜单和弹出框的背景
#define COLOR_ALERT_BACKGROUND                  [UIColor whiteColor]

//[文字颜色] 弹出菜单和弹出框的标题
#define COLOR_ALERT_TITLE                       [UIColor blackColor]

//弹出菜单和弹出框的背景蒙层
#define COLOR_ALERT_BACKGROUND_LAYER            [UIColor colorWithWhite:.5f alpha:0.5f]

//[背景色] 弹出菜单的按钮
#define COLOR_ALERTSHEET_BTN                    [UIColor whiteColor]

//[背景色] 弹出框的按钮（蓝色）
#define COLOR_ALERT_BTN                         RGB(0, 122, 255)

//我的cell背景色
#define COLOR_MYVIEWCELL_BACKGROUND             [UIColor whiteColor]
//loading和弹框文字颜色
#define COLOR_ALERTCONTENT                      [UIColor whiteColor]

//自定义密码弹窗
#define COLOR_ALERT_BORDER                      [UIColor lightGrayColor]

#define COLOR_CELL_SELECTION                    RGBA(43, 51, 54, 0.1)
#define COLOR_CELL_BACKGROUND                   [UIColor whiteColor]

#define COLOR_LOADING_BACKGROUD                 [UIColor colorWithWhite:1.0f alpha:0.8f]
#define COLOR_TITLE                 [UIColor blackColor]
#define COLOR_TEXT_NORMAL           RGB(0x3f,0x42,0x4e)
#define COLOR_TEXT_LIGHTGRAY        RGB(0x78, 0x78, 0x78)
#define COLOR_TEXT_PLACEHOLDER      RGB(194, 193, 201) 
#define COLOR_TEXT_RED              RGB(0xff,0x3b,0x30)
#define COLOR_BORDER                [UIColor lightGrayColor]
#define COLOR_BUTTON_SELECT         RGB(57, 197, 252)
#define COLOR_BUTTON_TITLE          [UIColor whiteColor]
//[文字颜色] 被禁用按钮
#define COLOR_BUTTON_TEXT_DISABLED  COLOR_TEXT_NORMAL
//按钮背景色
#define COLOR_BUTTON_BACKGROUND     RGB(242, 242,242)


#define COLOR_MAIN_BLUE             RGB(80,180,227)
#define COLOR_MAIN_BLUE_LIGHT       RGBA(80,180,227,0.5)
#define COLOR_LIGHT_BLUE            RGB(115, 205, 240)
#define COLOR_NAV_BACKGROUND        COLOR_MAIN_BLUE
#define COLOR_TEXT_BACKGROUND       RGBA(255,255,255,.5)
// 字体
#define FONT_TEXT_NORMAL            FONT(14)
#define FONT_TEXT_SMALL             FONT(12)
#define FONT_TEXT_SMALL11           FONT(11)
//导航栏(标题栏)标题字体
#define FONT_TEXT_NAVBAR_TITLE      FONT(19)

//导航栏(标题栏)两边按钮字体
#define FONT_TEXT_NAVBAR_BUTTON     FONT(15)


//弹出菜单和弹出框的标题大小
#define FONT_TEXT_ALERT_TITLE       FONT_TEXT_NAVBAR_BUTTON

//弹出菜单和弹出框的按钮字体大小
#define FONT_TEXT_ALERT_BUTTON      FONT_TEXT_NAVBAR_BUTTON



#endif
